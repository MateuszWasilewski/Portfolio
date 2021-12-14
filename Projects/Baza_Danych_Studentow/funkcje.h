/**
 * @file funkcje.h
 * @author Mateusz Wasilewski
 * 
 * @brief Plik zawierający headery wszystkich funkcji i klas programu
 * 
 * Header file ułatwia odwołania się z funkcji do innych funkcji bez zważania na ich kolejność w kodzie
 * @version 1.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream> /// standardowe wyjście
#include <forward_list> /// struktura listy na oceny i uczniów
#include <fstream> /// wyjście/wejście do pliku (zapis danych)
#include <iomanip> /// ucinanie miejsc po przecinku do średniej

class ocena;

class uczen;

int give_number();

void wczytaj_uczniow();

void zapisz_dane();

void do_uczen(uczen &ucze);

void wybierz_ucznia();

void dodaj_ucznia();

void do_it(int opcja);

void ask_what_to_do();

void usun_ucznia(uczen ucze);