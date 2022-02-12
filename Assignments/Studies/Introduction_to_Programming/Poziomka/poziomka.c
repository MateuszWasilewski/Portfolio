#include <stdio.h>
#include <limits.h>

// Definitions
#ifndef POLA
#define POLA 5
#endif

#ifndef WIERSZE
#define WIERSZE 26
#endif

#ifndef KOLUMNY
#define KOLUMNY 26
#endif

#ifndef WYBOR
#define WYBOR 1000
#endif

// Determine what TAKEN and FREE spaces should be symbolized with
#define FREE '.'
#define TAKEN '#'

// Global variable indicating which spaces are free to play
// and which are already blocked.
char board[WIERSZE][KOLUMNY];

// Global variable which includes information about moves resulting in best score
// Sometimes it contains garbage information 
// but all values with indexes smaller than variable possibilities are good.
int options[WIERSZE * KOLUMNY];

// Function Setting all values in rectangle on table board to (value).
// Left Top has coordinates (x1,y1).
// Right Bottom has coordinates (x2,y2).
static void Set(int start_row, int end_row, int start_column, int end_column, char value) {
    for(int row = start_row; row <= end_row; row++) {
        for(int column = start_column; column <= end_column; column++) {
            board[row][column] = value;
        }
    }
}

// Setting all values in table board to (value).
static void SetBoard(char value) {
    Set(0, WIERSZE-1, 0, KOLUMNY-1, value);
}

// Calculates score for span [starts..ends] assuming 
// that all spaces in this range are unoccupied.
static int ScoreForSpan(int starts, int ends) {
    return (ends - starts + 1) / POLA;
}

// Function calculating score for left or right player.
// It works by iterating first vertically from players perspective
static int Score(int left) {
    int score = 0;
    int outer = WIERSZE, inner = KOLUMNY;
    if (left) {
        outer = KOLUMNY;
        inner = WIERSZE;
    }

    for (int vertical = 0; vertical < outer; vertical++) {
        // Start of clear space for moves.
        int start = 0;

        for (int horizontal = 0; horizontal < inner; horizontal++) {
            // Makes sure to ask right slot in table board.
            int value = !left ? board[vertical][horizontal] : board[horizontal][vertical];

            // End of clear spaces.
            if (value != FREE) {
                score += ScoreForSpan(start, horizontal - 1);
                start = horizontal + 1;
            }
        }
        // We need to and potencial score at the end of the board.
        score += ScoreForSpan(start, inner - 1);
    }
    return score;
}

// Function which converts a single encoded integer to
// either rows (mala == 1)
// or columns (mala == 0)
static int ConvertOption(int i, int mala) {
    return mala == 0 ? options[i] % (1 << 8) : options[i] >> 8;
}

// Prints program's move (i) onto standard output
// row first, then column.
static void PrintMove(int i) {
    printf("%c%c\n", ConvertOption(i, 1) + 'a', ConvertOption(i, 0) + 'A');
}

// Function calculates score for move placing line [x .. x + POLA - 1]
// In Row (y).
// And sets table options[0..N] to include only opctions with best scores.
static void ConsiderOption(int x, int y, int *wynik, int *N) {
    // Temporarely placing line.
    Set(y, y, x, x + POLA - 1, TAKEN);

    // Calculating Score for whole board.
    int score = Score(0) - Score(1);

    // Removing previously placed line.
    Set(y, y, x, x + POLA - 1, FREE);

    // If score is better than ones so far then we can forget former ones.
    if (score > *wynik) {
        *wynik = score;
        *N = 0;
    }

    // If score is as good as the best, then it should be included.
    if (score == *wynik){
        // Encoding move as a single integer.
        y <<= 8;
        options[*N] = x + y;
        (*N)++;
    }
}

// Function placing line on board permanently.
// Results in printing move onto standard output.
static void MakeMove(int i) {
    PrintMove(i);
    int x = ConvertOption(i, 1);
    int X = ConvertOption(i, 0);

    Set(x, x, X, X + POLA - 1, TAKEN);
}

// Function which goes through each possible move
// and if it is possible then
// induces function ConsiderOption() to consider it.
static void GoThroughOptions(int *possibilities) {
    // number_of_taken - determines number of hashes in line z 
    // from position [z - POLA + 1] to [z] .
    int number_of_taken = 0;

    // Determines highest possible score encoutered so far,
    int wynik = INT_MIN;

    for (int i = 0; i < WIERSZE; i++) {
        number_of_taken = 0;
        for (int z = 0; z < KOLUMNY; z++) {
            // Makes sure to have right amount of taken space counted.
            number_of_taken += board[i][z] != FREE ? 1 : 0;
            if (z >= POLA)
                number_of_taken -= board[i][z - POLA] != FREE ? 1 : 0;
            
            // Means that there are no occupied spaces in regared place
            // and it is far enough from board edge.
            if (z >= POLA - 1 && number_of_taken == 0)
                ConsiderOption(z - POLA + 1, i, &wynik, possibilities);
        }
    }
}

// Function deciding which move to persue based on number of possibilities
// and define WYBOR.
// If there isn't a possible move then it gives up and returns 1.
static int DecideMove(int *possibilities) {
    if (*possibilities > 0){
        MakeMove(WYBOR % *possibilities);
        return 1;
    }
    else{
        printf(".\n");
        return 0;
    }
}

// Function acting upon player first character of input.
// It player placed a move then it draws it on the board.
static int PlayerMove() {
    // First character of player's move.
    int znak1 = getchar();
    // Row of opponents move
    int znak2;

    if (znak1 == EOF || znak1 == '.')
        return 0;

    // means that opponents gave first move to program.
    if (znak1 != '-') {
        znak2 = getchar();
        // Converting row and column of opponent's move to include 
        // the same information but in interval [0..25].
        znak1 -= 'A';
        znak2 -= 'a';

        // Draws opponents move on board, assuming it was correct.
        Set(znak2, znak2 + POLA - 1, znak1, znak1, TAKEN);
    }

    // Reading "\n" character from standard input
    znak1 = getchar();
    return 1;
}

// Function which symulates all possible program moves, 
// finds all with maximal score, choses one and performs it.
static int ProgramMove(void) {
    // Variable determining how many moves are possible and have best score
    // in global table options.
    int possibilities = 0;
    GoThroughOptions(&possibilities);

    // Decides on move, and returns if we should still play.
    return DecideMove(&possibilities);
}

// Function performing whole game turn,
// read opponents move, place it, find best move, chose and perform it.
// Returns 0 if program of player gave up.
// Returns 1 otherwise.
static int Play(void) {
    return PlayerMove() && ProgramMove();
}

int main(void) {
    // Sets whole board as free spaces to play
    SetBoard(FREE);

    // If while fails then player aborted game, gave up or program gave up.
    while (Play());

    return 0;
}