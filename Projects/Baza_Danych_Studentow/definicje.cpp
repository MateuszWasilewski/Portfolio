/**
 * @file definicje.cpp
 * @author Mateusz Wasilewski
 * 
 * @brief Plik zawierający dokładne definicje wszystkich klas oraz funkcji zawierających się na program
 * @version 1.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "funkcje.h"
#include <iostream>
#include <forward_list>
#include <fstream>
#include <iomanip> 
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

/** \brief Klasa definiująca ocenę wraz z datą wstawienia
 * 
 * klasa ocena wraz z funkcjami operującymi na danych
 * \param mark ocena w skali 1-6
 * \param procent ocena w skali procentowej
 * \param data data wstawienia oceny
 * 
 * @code
 *  class ocena{
    private:
        int mark;
        int procent;
        string data;
    public:
        //funkcje
    }
 * @endcode
 * 
 * @see uczen
  */

class ocena{
private:
    int mark;
    int procent;
    string data;

public:
    /**
     * @brief Konstruktor nowej oceny
     * 
     * @param mk wartość nowej oceny w skali 1-6
     * @param pr wartość nowej oceny w skali 0-100
     * @param kiedy data przypisana ocenie
     * 
     * @code
     *  ocena(int mk, int pr, string kiedy){
            mark = mk;
            procent = pr;
            data = kiedy;
            return;
        }
     * @endcode
     */
    ocena(int mk, int pr, string kiedy){
        mark = mk;
        procent = pr;
        data = kiedy;
        return;
    }

    /**
     * @brief Funkcja wypisująca ocenę na podane wyjście
     * 
     * używana do zapisania oceny do pliku
     * 
     * @param read parametr definujący wyjście na które trzeba wypisać ocenę
     * 
     * @code
     *  void read_ocena(fstream &read){
            read << mark << " " << procent << " " << data << "\n";
            return;
        }
     * @endcode
     */
    void read_ocena(fstream &read){
        read << mark << " " << procent << " " << data << "\n";
        return;
    }

    /**
     * @brief Zwraca ocenę w skali 1-6 do liczenia średniej
     * 
     * @return double 
     * 
     * @code
     *  double ocen(){
            return mark;
        }
     * @endcode
     */
    double ocen(){
        return mark;
    }

    /**
     * @brief Zwraca ocenę w skali 0-100 do liczenia średniej
     * 
     * @return int 
     * 
     * @code
     *  int pr(){
            return procent;
        }
     * @endcode
     */
    int pr(){
        return procent;
    }

    /**
     * @brief Wypisuje ocenę na standardowe wyjście
     * 
     * @code
     *  void read_ocena_loud(){
            cout << "ocena: " << mark << " " << procent << "% " << data << "\n";
            return;
        }
     * @endcode
     */
    void read_ocena_loud(){
        cout << "ocena: " << mark << " " << procent << "% " << data << "\n";
        return;
    }
};

/**
 * @brief Klasa ucznia wraz z danymi o nim i jego ocenami
 * 
 * @param id publiczne id ucznia używane do wyszukiwania i porównywania
 * 
 * @param name Imię ucznia
 * @param nazwisko Nazwisko ucznia
 * @param pesel PESEL ucznia
 * @param data Data urodzenia ucznia
 * @param zamieszkanie Miejscowość zamieszkania ucznia
 * @param telefon nr telefonu do ucznia/rodzica
 * @param locen liczba ocen ucznia
 * @param oceny lista zawierająca obiekty ocen
 * \see ocena
 * 
 * @code
 *  class uczen{
    public:
        string id;
    private:
        string name;
        string nazwisko;
        string pesel;
        string data;
        string zamieszkanie;
        string telefon;
        int locen;

        forward_list <ocena> oceny;
    public:
        //funckcje
    }
 * @endcode
 */
class uczen{
public:
    string id;
private:
    string name;
    string nazwisko;
    string pesel;
    string data;
    string zamieszkanie;
    string telefon;
    int locen;

    forward_list <ocena> oceny;

public:
    /**
     * @brief Konstruktor nowego ucznia
     * 
     * @param imie imie ucznia
     * @param nazw nazwisko ucznia
     * @param psl pesel ucznia
     * @param urodz data urodzenia ucznia
     * @param zamieszk miejscowość zamieszkania ucznia
     * @param tel nr telefonu ucznia/rodzica
     * @param ocen liczba ocen ucznia
     * 
     * @code
     *  uczen(string imie, string nazw, string psl, string urodz, string zamieszk, string tel, int ocen){
            id = imie + '_' + nazw; //id ucznia nadawane w konstruktorze
            name = imie;
            nazwisko = nazw;
            pesel = psl;
            data = urodz;
            zamieszkanie = zamieszk;
            telefon = tel;
            locen = ocen;

            return;
        }
     * @endcode
     */
    uczen(string imie, string nazw, string psl, string urodz, string zamieszk, string tel, int ocen){
        id = imie + '_' + nazw; //id ucznia nadawane w konstruktorze
        name = imie;
        nazwisko = nazw;
        pesel = psl;
        data = urodz;
        zamieszkanie = zamieszk;
        telefon = tel;
        locen = ocen;

        return;
    }

    /** @brief Wypisanie wszystkich ocen ucznia na standardowe wyjście 
     * 
     * @code
     *  void wypisz_oceny(){
            printf("\n\n");
            for(auto &e:oceny){
                e.read_ocena_loud();
            }
            return;
        }
     * @endcode
    */
    void wypisz_oceny(){
        printf("\n\n");
        for(auto &e:oceny){
            e.read_ocena_loud();
        }
        return;
    }

    /**
     * @brief Funkcja wywołana przez użytkownika aby dodać nową ocenę dla wybranego ucznia
     * 
     * Użytkownik ma 3 opcje po wspisaniu 3 zmiennych: \n 
     *  1 - zatwierdza (dane zostają dodane) \n 
     *  2 - poprawienie (ponowne wywołanie fukcji dodaj_ocene) \n 
     *  3 - anuluj (koniec funkcji) \n 
     * 
     * @param mk ocena w skali 1-6
     * @param pr ocena w skali 0-100
     * @param kiedy data oceny
     * 
     * @see give_number()
     * 
     * @code
     *  void dodaj_ocene(){
            int mk=-1, pr=-1;
            string kiedy, opcja;
            while(mk < 1 || mk > 6){
                printf("Podaj ocene w przedziale 1-6: ");
                mk = give_number();
            }
            while(pr < 0 || pr > 100){
                printf("Podaj wynik procentowy w skali 0-100: ");
                pr = give_number();
            }
            printf("Podaj Date: ");
            cin >> kiedy;

            printf("1) Potwierdzam\n");
            printf("2) Popraw Dane\n");
            printf("3) Anuluj\n");
            cin >> opcja;
            

            printf("\n\n");
            if(opcja == "1") {
                ocena mark(mk,pr,kiedy);
                oceny.push_front(mark);
                locen++;
            }
            else if(opcja == "2"){
                dodaj_ocene();
            }
            else if(opcja == "3"){
                printf("Anulowano\n");
            }
            else{
                printf("Taka opcja nie istnieje\n");
            }
            return;
        }
     * @endcode
     */
    void dodaj_ocene(){
        int mk=-1, pr=-1;
        string kiedy, opcja;
        while(mk < 1 || mk > 6){
            printf("Podaj ocene w przedziale 1-6: ");
            mk = give_number();
        }
        while(pr < 0 || pr > 100){
            printf("Podaj wynik procentowy w skali 0-100: ");
            pr = give_number();
        }
        printf("Podaj Date: ");
        cin >> kiedy;

        printf("1) Potwierdzam\n");
        printf("2) Popraw Dane\n");
        printf("3) Anuluj\n");
        cin >> opcja;
        

        printf("\n\n");
        if(opcja == "1") {
            ocena mark(mk,pr,kiedy);
            oceny.push_front(mark);
            locen++;
        }
        else if(opcja == "2"){
            dodaj_ocene();
        }
        else if(opcja == "3"){
            printf("Anulowano\n");
        }
        else{
            printf("Taka opcja nie istnieje\n");
        }
        return;
    }

    /** @brief Wypisanie wszystkich danych ucznia na standardowej wyjscie 
     * 
     * @code
     *  void podaj_dane(){
            printf("\n\n");
            
            printf("Dane: ");
            cout << id << "\n";
            printf("Imie: ");
            cout << name << "\n";
            printf("Nazwisko: ");
            cout << nazwisko << "\n";
            printf("PESEL: ");
            cout << pesel << "\n";
            printf("Data urodzenia: ");
            cout << data << "\n";
            printf("Miasto zamieszkania: ");
            cout << zamieszkanie << "\n";
            printf("Telefon do rodzica: ");
            cout << telefon << "\n\n";
            return;
        }
     * @endcode
    */
    void podaj_dane(){
        printf("\n\n");
        
        printf("Dane: ");
        cout << id << "\n";
        printf("Imie: ");
        cout << name << "\n";
        printf("Nazwisko: ");
        cout << nazwisko << "\n";
        printf("PESEL: ");
        cout << pesel << "\n";
        printf("Data urodzenia: ");
        cout << data << "\n";
        printf("Miasto zamieszkania: ");
        cout << zamieszkanie << "\n";
        printf("Telefon do rodzica: ");
        cout << telefon << "\n\n";
        return;
    }

    /**
     * @brief Wczytanie ocen ucznia z pliku w folderze "Uczniowie"
     * 
     * @code
     *  void wczytaj_oceny(){
            oceny.clear();

            fstream read;
            string input;
            read.open("Uczniowie/" + id + "_oceny.txt", ios::in);

            int mark;
            int pro;
            string dta;
            for(int i=0; i<locen; ++i){
                read >> mark >> pro >> dta;
                ocena nowa(mark,pro,dta);
                oceny.push_front(nowa);
            }
            
            read.close();
            return;
        }
     * @endcode
     */
    void wczytaj_oceny(){
        oceny.clear();

        fstream read;
        string input;
        read.open("Uczniowie/" + id + "_oceny.txt", ios::in);

        int mark;
        int pro;
        string dta;
        for(int i=0; i<locen; ++i){
            read >> mark >> pro >> dta;
            ocena nowa(mark,pro,dta);
            oceny.push_front(nowa);
        }
        
        read.close();
        return;
    }

    /**
     * @brief Wypisanie danych ucznia na podane wyjście
     * 
     * używana do zapisania danych ucznia do pliku jako zapis stanu programu \n 
     * Jeśli plik nie istnieje zostanie stworzony. Poprzednie dane w pliku zostaną podmienione.
     * @param read parametr wyjścia
     * 
     * @code
     *  void save_data(fstream &read){
            read << name << "\n";
            read << nazwisko << "\n";
            read << pesel << "\n";
            read << data << "\n";
            read << zamieszkanie << "\n";
            read << telefon << "\n";
            read << locen << "\n";

            fstream ocen;
            ocen.open("Uczniowie/" + id + "_oceny.txt", ios::out);
            for(auto &e:oceny){
                e.read_ocena(ocen);
            }

            ocen.close();
        }
        @endcode
     */
    void save_data(fstream &read){
        read << name << "\n";
        read << nazwisko << "\n";
        read << pesel << "\n";
        read << data << "\n";
        read << zamieszkanie << "\n";
        read << telefon << "\n";
        read << locen << "\n";

        fstream ocen;
        ocen.open("Uczniowie/" + id + "_oceny.txt", ios::out);
        for(auto &e:oceny){
            e.read_ocena(ocen);
        }

        ocen.close();
    }

    /**
     * @brief Funkcja liczy i wypisuje średnią ocen (1-6)na standardowe wyjście
     * 
     * wynik podaje z dokładnościa do 2 cyfr po przecinku 
     * 
     * @code
     *  void podaj_avg(){
            double l = 0;
            double m = locen;
            for(auto &e:oceny){
                l += e.ocen();
            }

            printf("\n\n");
            if(m == 0){
                printf("Brak ocen\n");
                return;
            }
            else{
                cout << fixed << setprecision(2) << l/m << "\n";
            }
            return;
        }
        @endcode

        @see ocena::ocen()
        @see uczen
     */
    void podaj_avg(){
        double l = 0;
        double m = locen;
        for(auto &e:oceny){
            l += e.ocen();
        }

        printf("\n\n");
        if(m == 0){
            printf("Brak ocen\n");
            return;
        }
        else{
            cout << fixed << setprecision(2) << l/m << "\n";
        }
        return;
    }

    /**
     * @brief Funkcja liczy i wypisuje średnia ocen (0-100) na standardowe wyjście 
     * 
     * wynik podaje z dokładnośćią do całkowitych punktów procentowych
     * 
     * @code
     *  void podaj_avg_pr(){
            int l = 0;
            int m = locen;
            printf("\n\n");
            for(auto &e:oceny){
                l += e.pr();
            }
            if(m == 0){
                printf("Brak ocen\n");
                return;
            }
            else{
                l += m/2;               //poprawna średnia na int
                cout << l/m << "\n";
            }
            return;
        }
        @endcode

        @see ocena::pr()
        @see uczen
     */
    void podaj_avg_pr(){
        int l = 0;
        int m = locen;
        printf("\n\n");
        for(auto &e:oceny){
            l += e.pr();
        }
        if(m == 0){
            printf("Brak ocen\n");
            return;
        }
        else{
            l += m/2;               //poprawna średnia na int
            cout << l/m << "\n";
        }
        return;
    }
};

/**
 * @brief Publiczny obiekt zawierający listę obiektów uczniów
 * 
 * @code
 * forward_list <uczen> uczniowie;
 * @endcode
 * 
 * @see uczen
 * @see dodaj_ucznia()
 * @see usun_ucznia()
 * 
 */
forward_list <uczen> uczniowie;
/**
 * @brief Zmienna publiczna sugerująca zamknięcie programu przy 1 zapytaniu
 * 
 * @code
 * bool end_program = 0;
 * @endcode
 * 
 * @see main()
 */
bool end_program = 0;

/**
 * @brief Funkcja rekurencyjnie wczytująca dowolnego stringa, aż podanie zostana poprawna liczba w systemie dziesietnym 
 * @param input wejscie użytkownika
 * @return int 
 * 
 * @code
 *  int give_number(){
        string input;
        cin >> input;

        int liczba = 0;
        int znak = 1;
        for(int i=0; i<input.size(); ++i){
            liczba *= 10;                                                       //przesuwa poprzednio dodane cyfry o 1 w lewo w sys 10
            if(input[i] >= '0' && input[i] <= '9') liczba += input[i] - '0';    //dodaje ostatnia cyfre do wyniku
            else if(input[i] == '-') znak *= -1;                                //sprawdza minusy poprzedzające i występujące w liczbie aby określić finalny znak
            else{                                                               //w wypadku wystąpienia nieznanego znaku zwraca blad i oczekuje na poprawne wejscie
                printf("Podaj liczbe: \n");
                return give_number();
            }
        }
        return liczba * znak;
    }
 * @endcode
 */
int give_number(){
    string input;
    cin >> input;

    int liczba = 0;
    int znak = 1;
    for(int i=0; i<input.size(); ++i){
        liczba *= 10;                                                           //przesuwa poprzednio dodane cyfry o 1 w lewo w sys 10
        if(input[i] >= '0' && input[i] <= '9') liczba += input[i] - '0';        //dodaje ostatnia cyfre do wyniku
        else if(input[i] == '-') znak *= -1;                                    //sprawdza minusy poprzedzające i występujące w liczbie aby określić finalny znak
        else{                                                                   //w wypadku wystąpienia nieznanego znaku zwraca blad i oczekuje na poprawne wejscie
            printf("Podaj liczbe: \n");
            return give_number();
        }
    }
    return liczba * znak;
}

/**
 * @brief Funkcja wczytująca listę uczniów wraz z ich danymi do listy
 * 
 * dane wczytywane są z folderu /Uczniowie
 * @see uczniowie
 * 
 * @code
 *  void wczytaj_uczniow(){
        fstream read;
        read.open("Uczniowie/lista.txt", ios::in);

        string input;
        while(getline(read,input)){
            fstream ucze;
            string imie, nazw, psl, urodz, zamieszk,tel;
            int oceny;

            ucze.open("Uczniowie/" + input + "_dane.txt", ios::in);
            ucze >> imie;
            ucze >> nazw;
            ucze >> psl;
            ucze >> urodz;
            ucze >> zamieszk;
            ucze >> tel;
            ucze >> oceny;
            ucze.close();

            uczen nowy(imie,nazw,psl,urodz,zamieszk,tel, oceny);
            nowy.wczytaj_oceny();

            uczniowie.push_front(nowy);
        }

        printf("\n\n");
        printf("Wczytano uczniow \n");
        read.close();
        return;
    }
 * @endcode
 */
void wczytaj_uczniow(){
    fstream read;
    read.open("Uczniowie/lista.txt", ios::in);

    string input;
    while(getline(read,input)){
        fstream ucze;
        string imie, nazw, psl, urodz, zamieszk,tel;
        int oceny;

        ucze.open("Uczniowie/" + input + "_dane.txt", ios::in);
        ucze >> imie;
        ucze >> nazw;
        ucze >> psl;
        ucze >> urodz;
        ucze >> zamieszk;
        ucze >> tel;
        ucze >> oceny;
        ucze.close();

        uczen nowy(imie,nazw,psl,urodz,zamieszk,tel, oceny);
        nowy.wczytaj_oceny();

        uczniowie.push_front(nowy);
    }

    printf("\n\n");
    printf("Wczytano uczniow \n");
    read.close();
    return;
}

/**
 * @brief Fukcja zapisuje dane do plików
 * 
 * oznacza nadpisanie wszystkich danych, które były tam poprzednio
 * 
 * @code
 *  void zapisz_dane(){
    mkdir("Uczniowie");           //tworzy nowy folder Uczniowie, jeśli taki nie istnieje
    fstream lista;
    lista.open("Uczniowie/lista.txt", ios::out);
    for(auto &e:uczniowie){
        fstream ucze;
        lista << e.id << "\n";

        ucze.open("Uczniowie/" + e.id +"_dane.txt", ios::out);
        e.save_data(ucze);
        ucze.close();
    }
    lista.close();
    printf("\n\n");
    printf("Zapisano dane\n\n");
    return;
}
 * @endcode
 */
void zapisz_dane(){
    mkdir("Uczniowie");
    fstream lista;
    lista.open("Uczniowie/lista.txt", ios::out);
    for(auto &e:uczniowie){
        fstream ucze;
        lista << e.id << "\n";

        ucze.open("Uczniowie/" + e.id +"_dane.txt", ios::out);
        e.save_data(ucze);
        ucze.close();
    }
    lista.close();
    printf("\n\n");
    printf("Zapisano dane\n\n");
    return;
}

/**
 * @brief Usuwa podanego ucznia z listy
 * 
 * uczen zostaje usuniety z listy, po zapisaniu stany programu dane jego ocen mimo wszystko zostaną w plikach programu
 * 
 * @param ucze kopia obiektu ucznia do usuniecia
 * 
 * @code
 *  void usun_ucznia(uczen ucze){
        forward_list <uczen> fd = uczniowie;
        uczniowie.clear();
        for(auto &e:fd){
            if(ucze.id != e.id) uczniowie.push_front(e);
        }
        printf("\n\nUsunieto ucznia ");
        cout << ucze.id << "\n";
    }
 * @endcode
 * @see uczen
 * @see uczniowie
 */
void usun_ucznia(uczen ucze){
    
    forward_list <uczen> fd = uczniowie;
    uczniowie.clear();
    for(auto &e:fd){
        if(ucze.id != e.id) uczniowie.push_front(e);
    }
    printf("\n\nUsunieto ucznia ");
    cout << ucze.id << "\n";
}

/**
 * @brief Funkcja oczekująca na wybór użytkownika i powołująca wybrane działanie
 * 
 * @param ucze wzkaźnik na ucznia na którym ma zostać wykonane wybrane działanie
 * 
 * opcje do wyboru przez użytkownika: \n 
 *  dodaj ocene \n
 *  wypisz wszystkie oceny ucznia \n 
 *  podaj srednia 1-6 \n 
 *  podaj srednia 0-100 \n 
 *  podaj dane ucznia \n 
 *  usun ucznia \n 
 *  anuluj i wyjdz \n 
 * 
 * @see uczen
 * @see usun_ucznia()
 * 
 * @code
 *  void do_uczen(uczen &ucze){
        printf("\nWybrano "); cout << ucze.id << "\n";
        printf("1) Dodaj ocene \n");
        printf("2) Wypisz wszystkie oceny \n");
        printf("3) Podaj srednia ocen \n");
        printf("4) Podaj srednia procentowa \n");
        printf("5) Podaj dane ucznia\n");
        printf("6) Usun ucznia\n");
        printf("7) Anuluj \n");

        string opcja;
        cin >> opcja;
        if(opcja == "1"){
            ucze.dodaj_ocene();
        }
        else if(opcja == "2"){
            ucze.wypisz_oceny();
        }
        else if(opcja == "3"){
            ucze.podaj_avg();
        }
        else if(opcja == "4"){
            ucze.podaj_avg_pr();
        }
        else if(opcja == "5"){
            ucze.podaj_dane();
        }
        else if(opcja == "6"){
            usun_ucznia(ucze);
        }
        else if(opcja == "7"){
            printf("\n\n");
            printf("Anulowano\n");
        }
        else{
            printf("\n\n");
            printf("Taka opcja nie istnieje\n");
        }
        return;
    }
 * @endcode
 */
void do_uczen(uczen &ucze){
    printf("\nWybrano "); cout << ucze.id << "\n";
    printf("1) Dodaj ocene \n");
    printf("2) Wypisz wszystkie oceny \n");
    printf("3) Podaj srednia ocen \n");
    printf("4) Podaj srednia procentowa \n");
    printf("5) Podaj dane ucznia\n");
    printf("6) Usun ucznia\n");
    printf("7) Anuluj \n");

    string opcja;
    cin >> opcja;
    if(opcja == "1"){
        ucze.dodaj_ocene();
    }
    else if(opcja == "2"){
        ucze.wypisz_oceny();
    }
    else if(opcja == "3"){
        ucze.podaj_avg();
    }
    else if(opcja == "4"){
        ucze.podaj_avg_pr();
    }
    else if(opcja == "5"){
        ucze.podaj_dane();
    }
    else if(opcja == "6"){
        usun_ucznia(ucze);
    }
    else if(opcja == "7"){
        printf("\n\n");
        printf("Anulowano\n");
    }
    else{
        printf("\n\n");
        printf("Taka opcja nie istnieje\n");
    }
    return;
}

/**
 * @brief Wybór ucznia przez użytkownika spośród podanych opcji (z listy)
 * 
 * @see uczen
 * 
 * @code
 *  void wybierz_ucznia(){
        if(!uczniowie.empty()){
            printf("Wybierz ucznia \n");
            for(auto &e:uczniowie){
                cout << e.id << "\n";
            }
            string id;
            cin >> id;
            for(auto &e: uczniowie){
                if(e.id == id){
                    do_uczen(e);
                    return;
                }
                
            }
            printf("Taki uczen nie istnieje \n");
        }
        else{
            printf("Brak Uczniów \n");
        }
        
        //wybierz_ucznia();
        return;
    }
 * @endcode
 */
void wybierz_ucznia(){
    if(!uczniowie.empty()){
        printf("Wybierz ucznia \n");
        for(auto &e:uczniowie){
            cout << e.id << "\n";
        }
        string id;
        cin >> id;
        for(auto &e: uczniowie){
            if(e.id == id){
                do_uczen(e);
                return;
            }
            
        }
        printf("Taki uczen nie istnieje \n");
    }
    else{
        printf("Brak Uczniów \n");
    }
    
    //wybierz_ucznia();
    return;
}

/**
 * @brief Dodanie ucznia wraz z jego wszystkimi danymi do listy
 * 
 * użytkownik może zatwierdzić dane \n 
 * podać na nowo \n 
 * lub anulować i wyjść
 * 
 * @see uczen
 * 
 * @code
 *  void dodaj_ucznia(){
        string id,imie, nazw, psl, urodz, zamieszk,tel;
        printf("Podaj imie: ");
        cin >> imie;
        printf("Podaj Nazwisko: ");
        cin >> nazw;
        printf("Podaj PESEL: ");
        cin >> psl;
        printf("Podaj date urodzenia: ");
        cin >> urodz;
        printf("Podaj miasto zamieszkania: ");
        cin >> zamieszk;
        printf("Podaj telefon do rodzica: ");
        cin >> tel;

        printf("1) Potwierdzam \n");
        printf("2) Popraw Dane \n");
        printf("3) Anuluj\n");
        string opcja;
        cin >> opcja;

        printf("\n\n");
        if(opcja == "1"){
            uczen nowy(imie, nazw, psl, urodz, zamieszk, tel, 0);
            uczniowie.push_front(nowy);
        }
        else if(opcja == "2"){
            dodaj_ucznia();
        }
        else if(opcja == "3"){
            printf("Anulowano\n");
        }
        else{
            printf("Taka opcja nie istnieje\n");
        }
        return;
    }
 * @endcode
 */
void dodaj_ucznia(){
    string id,imie, nazw, psl, urodz, zamieszk,tel;
    printf("Podaj imie: ");
    cin >> imie;
    printf("Podaj Nazwisko: ");
    cin >> nazw;
    printf("Podaj PESEL: ");
    cin >> psl;
    printf("Podaj date urodzenia: ");
    cin >> urodz;
    printf("Podaj miasto zamieszkania: ");
    cin >> zamieszk;
    printf("Podaj telefon do rodzica: ");
    cin >> tel;

    printf("1) Potwierdzam \n");
    printf("2) Popraw Dane \n");
    printf("3) Anuluj\n");
    string opcja;
    cin >> opcja;

    printf("\n\n");
    if(opcja == "1"){
        uczen nowy(imie, nazw, psl, urodz, zamieszk, tel, 0);
        uczniowie.push_front(nowy);
    }
    else if(opcja == "2"){
        dodaj_ucznia();
    }
    else if(opcja == "3"){
        printf("Anulowano\n");
    }
    else{
        printf("Taka opcja nie istnieje\n");
    }
    return;
}

/**
 * @brief wykonanie operacji wybranej przez użytkownika do wykonania w głownej części programu
 * 
 * opcje zostały podane w funkcji ask_what_to_do()
 * 
 * @param opcja wybrana opcja
 * 
 * @code
 *  void do_it(int opcja){
        switch (opcja) {
        case 1:
            wczytaj_uczniow();
            break;
        case 2:
            zapisz_dane();
            break;
        
        case 3:
            wybierz_ucznia();
            break;

        case 4:
            dodaj_ucznia();
            break;

        case 5:
            end_program = 1;
            break;
        
        default:
            printf("Taka opcja nie istnieje podaj poprawna opcje \n");
            do_it(give_number());
            break;
        }
        return;
    }
 * @endcode
 * 
 * @see wczytaj_uczniow()
 * @see zapisz_dane()
 * @see wybierz_ucznia()
 * @see dodaj_ucznia()
 * @see end_program
 * @see ask_what_to_do()
 * 
 * 
 */
void do_it(int opcja){
    switch (opcja) {
    case 1:
        wczytaj_uczniow();
        break;
    case 2:
        zapisz_dane();
        break;
    
    case 3:
        wybierz_ucznia();
        break;

    case 4:
        dodaj_ucznia();
        break;

    case 5:
        end_program = 1;
        break;
    
    default:
        printf("Taka opcja nie istnieje podaj poprawna opcje \n");
        do_it(give_number());
        break;
    }
    return;
}

/**
 * @brief Zapytanie użytkownika o działanie do wykonania w programie
 * 
 * Powołanie działania w funkcji do_it()
 * 
 * @code
 *  void ask_what_to_do(){
        printf("\n");
        printf("Co chcialbys zrobic? Oto twoje mozliwosci: \n");
        printf("1) Wczytaj dane \n");
        printf("2) Zapisz dane (oznacza utrate poprzednich) \n");
        printf("3) Wybierz ucznia \n");
        printf("4) Dodaj ucznia \n");
        printf("5) Zakoncz dzialanie programu (niezapisane dane zostana utracone) \n");

        printf("wybierz liczbe odpowiadajaca opcje\n");

        do_it(give_number());

        return;
    }
 * @endcode
 * 
 * @see do_it()
 * @see main()
 * @see give_number()
 * 
 */

void ask_what_to_do(){
    printf("\n");
    printf("Co chcialbys zrobic? Oto twoje mozliwosci: \n");
    printf("1) Wczytaj dane \n");
    printf("2) Zapisz dane (oznacza utrate poprzednich) \n");
    printf("3) Wybierz ucznia \n");
    printf("4) Dodaj ucznia \n");
    printf("5) Zakoncz dzialanie programu (niezapisane dane zostana utracone) \n");

    printf("wybierz liczbe odpowiadajaca opcje\n");

    do_it(give_number());

    return;
}

