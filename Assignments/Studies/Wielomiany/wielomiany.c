#include <stdio.h>
#include <stdlib.h>

// Maximal polynomial degree + 1
#define LIMIT 11

// Function reading first non space " " character from standard input and returning it.
// Space is not worth considering because it doesn't have any meaning.
static int Read(void) {
    int znak = getchar();
    while (znak == ' ') 
        znak = getchar();

    return znak;
}

// Function, which prints factor of ax^n, disregarding sign of the factor.
// If power == 0 prints factor even if number == 0.
// If number == 0 prints the factor unless it is 1.
static void PrintFactor(int number, int power, int *printed_before) {
    if (*printed_before == 1) {
        // Printing sign of not highest monomial.
    if (number < 0) 
        printf(" - ");
    else
        printf(" + ");
    }
    else {
        *printed_before = 1;
        if (number < 0) 
            printf("-");
    }
    // Parsing for long long because abs(INT_MIN) > INT_MAX
    long long absolute = number;
    if(absolute < 0)
        absolute = - absolute;

    if (power == 0 || absolute != 1) 
        printf("%lld", absolute);
}
// Printing x to the power of i (x^power).
static void PrintPower(int const power) {
    // If power == 0 then no x and power are needed.
    if (power > 0) {                
        printf("x");

        if (power > 1)
            // Printing "^" and power.
            printf("^%d", power);           
    }
}

// Function setting all values in table a[0..LIMIT-1] to 0.
static void Set0(int a[]) {
    for (int i = 0; i < LIMIT; i++) 
        a[i] = 0;
}

// Function displaying a given polynomial a[] onto the standard output.
// If factor is < 0 (in the highest power) then there is no space between - and factor.
// 1 space between each monomial and sign after the first monomial.
static void Output(int const a[]) {
    // 1 if monomial in the highest power was already printed.
    int printed_before = 0;       

    // Taking into conderation monomials from highest to lowest power.
    for (int i = LIMIT - 1; i >= 0; i--) {
        // If factor != 0 then monomial should be present at the result.      
        if (a[i] != 0) {            
            PrintFactor(a[i], i, &printed_before);
            PrintPower(i);
        }
    }
    // If whole polynomial == 0 then it was not printed before.
    if (printed_before == 0) printf("0");      
    printf("\n");
}

// Function adding polynomial poly to memory.
static void Add(int memory[], int const poly[]) {
    for (int i = 0; i < LIMIT; i++) {
        memory[i] += poly[i]; 
    }
}

// Function multiplying polynomials memory and poly and setting result to memory[].
static void Multiply(int memory[], int const poly[]) {
    // Additional table required for multiplication.
    int result[LIMIT];       
    Set0(result);

    // Multipling memory and poly to result.
    for (int i = 0; i < LIMIT; i++) {
        for (int j = 0; j <= i; j++) {
            result[i] += memory[j] * poly[i - j];
        }
    }
    // Setting results to memory[].
    for (int i = 0; i < LIMIT; i++) {
    	memory[i] = result[i]; 
    }
}

// Function reading numbers from standard input,
// converting it to decimal and leaving next character to *next.
// At the start of the function *next has value of first number to read.
// At the end of the function *next has value of first 
// non space non number character from standard input.
static long long DecimalConversion(int *next) {
    long long number = 0;
    while ('0' <= *next && *next <= '9') {
        // Decimal convertion for each number of factor and putting it together.
        number = number * 10 + (*next - '0'); 
        *next = Read();
    }
    return number;
}

// Function reading x^power from standard input,
// if power > 0 then *next has value x at start.
// At the end of the function *next has value of first 
// non space non number character from standard input.
static int ReadPower(int *next) {
    int power = 0;

    // Lack of x means power == 0.
    if (*next == 'x') {
        *next = Read();
        power = 1;
        // If '^' is present, then power > 1
        if (*next == '^') {
            *next = Read();
            power = (int) DecimalConversion(next);
        }
    }
    return power;
}

// Function reading whole line of standard input and convering it to polynomial poly.
static void Input(int poly[]) {
    Set0(poly);
    long long a_now;
    int power, sign, next;

    next = Read();
    while (next != '\n') {
        a_now = 0;      // Factor of monomial.
        sign = 1;       // Sign of monomial (1 <=> '+') and (-1 <=> '-).
        power = 0;      // Power of monomial.
        
        // Setting right sign and reading next symbol worth considering.
        if (next == '-') {
            sign = -1;
            next = Read();
        }
        else if (next == '+')
            next = Read();
        
        // Reading factor of monomial, and setting it to a_now
        a_now = next == 'x' ? 1 : DecimalConversion(&next);

        // Reading power of monomial.
        power = ReadPower(&next);

        // Setting calculated result to polynomial poly[].
        a_now *= sign;
        poly[power] = (int) a_now;    
    }
}

int main(void) {
    // Table with polynomial in memory.
    int akumulator[LIMIT];      
    Set0(akumulator);

    // Table with polynomial to be written from next line.
    int poly[LIMIT];               
    
    int znak;
    while ((znak = Read()) != '.') {
        // Reading polynomial from standard input.
        Input(poly);               

        // Adequate operation on polynomials.
        // Only opctions are '*' or '+'
        if (znak == '*') 
            Multiply(akumulator, poly);
        else
            Add(akumulator, poly); 

        Output(akumulator);
    }

    return 0;
}
