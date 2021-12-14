/**
 * @file main.cpp
 * @author Mateusz Wasilewski
 * @brief Funkcja main programu
 * @version 1.1
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021
 */

#include "definicje.cpp"

/**
 * @brief wewnętrzna petla dzialania programu
 * 
 * @code 
 *  int main(){
 *      while(!end_program){
            ask_what_to_do();
        }
        printf("Koncze dzialanie programu\n");
        return 0;
 *  }
 * @endcode
 * @see ask_what_to_do()
 */
int main(){

    while(!end_program){
        ask_what_to_do();
    }
    printf("Koncze dzialanie programu\n");
    return 0;
}