#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#define ld long double
using namespace std;

class perfum{
public:
    string name;
    bool saved = 0;
    vector <string> head, heart, base;


    perfum(string nazw){
        name = nazw;
        fstream input;
        input.open("Perfumy/" + name + ".txt", ios::in);
        string sklad, cel; 


        while(input >> sklad){
            if(sklad == "head"){
                cel = "head";
            }
            else if(sklad == "heart"){
                cel = "heart";
            }
            else if(sklad == "base"){
                cel = "base";
            }
            else{
                if(cel == "head") head.push_back(sklad);
                if(cel == "heart") heart.push_back(sklad);
                if(cel == "base") base.push_back(sklad);

            }
        }
        input.close();
    }

    ~perfum(){
        if(saved){
            fstream input;
            input.open("Perfumy/" + name + ".txt", ios::out);
            
            input << "head\n";
            for(auto e:head){
                input << e << "\n";
            }
            input << "heart\n";
            for(auto e:heart){
                input << e << "\n";
            }
            input << "base\n";
            for(auto e:base){
                input << e << "\n";
            }

            input.close();
        }
    }
};

vector <perfum> perfumy;

bool koniec = 0;


void wczytaj_perfumy(){
    fstream input;
    mkdir("Perfumy", 0777);
    input.open("Perfumy/lista.txt", ios::in);
    string name;
    while(input >> name){
        perfum nowy(name);
        perfumy.push_back(nowy);
    }

    input.close();
}

perfum create(){
    string name, input;
    int lp;
    cout << "Podaj nazwe: \n";
    cin >> name;
    perfum nowy(name);

    cout << "Podaj liczbe skladnikow (glowa)\n";
    cin >> lp;
    for(int i=1; i<= lp; ++i){
        cout << "Podaj skladnik " << i << "  ";
        cin >> input;
        nowy.head.push_back(input);
    }

    cout << "Podaj liczbe skladnikow (serce)\n";
    cin >> lp;
    for(int i=1; i<= lp; ++i){
        cout << "Podaj skladnik " << i << "  ";
        cin >> input;
        nowy.head.push_back(input);
    }

    cout << "Podaj liczbe skladnikow (baza)\n";
    cin >> lp;
    for(int i=1; i<= lp; ++i){
        cout << "Podaj skladnik " << i << "  ";
        cin >> input;
        nowy.base.push_back(input);
    }
    return nowy;
}

void zakoncz(){
    fstream line;
    line.open("Perfumy/lista.txt", ios::out);
    for(auto &e:perfumy){
        line << e.name << "\n";
    }
    line.close();
}

void check(perfum nowy){
    cout << "\n";
    for(auto &e:perfumy){
        cout << "Check z " << e.name << "\n";
        ld licz,m;
        licz = 0;
        m = e.head.size();
        cout << "Pokrywa sie w glowie \n ";
        for(auto f:nowy.head){
            for(auto g:e.head){
                if(f == g){
                    cout << f << "\n";
                    licz++;
                }
            }
        }
        if(licz == 0) cout << "Nic\n";
        else{
            cout << "Zgodnosc w ";
            cout << fixed << setprecision(2) << licz/m << "\n";
        }


        licz = 0;
        m = e.heart.size();
        cout << "Pokrywa sie w sercu \n ";
        for(auto f:nowy.heart){
            for(auto g:e.heart){
                if(f == g){
                    cout << f << "\n";
                    licz++;
                }
            }
        }
        if(licz == 0) cout << "Nic\n";
        else{
            cout << "Zgodnosc w ";
            cout << fixed << setprecision(2) << licz/m << "\n";
        }
        

        licz = 0;
        m = e.base.size();
        cout << "Pokrywa sie w podstawie \n ";
        for(auto f:nowy.base){
            for(auto g:e.base){
                if(f == g){
                    cout << f << "\n";
                    licz++;
                }
            }
        }
        if(licz == 0) cout << "Nic\n";
        else{
            cout << "Zgodnosc w ";
            cout << fixed << setprecision(2) << licz/m << "\n";
        }
        
    }
}

void next_action(){
    cout << "\n Wybierz co chcesz zrobic\n";
    cout << "1 Dodaj Perfum\n";
    cout << "2 Sprawdz Perfum\n";
    cout << "3 Zakoncz\n";

    string opcja;
    cin >> opcja;
    if(opcja == "1"){
        perfum nowy = create();
        nowy.saved = 1;
        perfumy.emplace_back(nowy);
    }
    else if(opcja == "2"){
        //perfum nowy = create();
        check(create());
    }
    else if(opcja == "3"){
        koniec = 1;
    }
    else {
        cout << "Nie ma takiej opcji \n";
    }
}

int main(){

    wczytaj_perfumy();
    while(!koniec){
        next_action();
    }

    zakoncz();
}

