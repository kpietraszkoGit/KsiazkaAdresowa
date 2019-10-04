#ifndef UZYTKOWNIK_H // zabezpieczenie przed podw�jnym includowaniem uzytkownik.h
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;//wszystkie one s� prywatne zahermetyzowane
    string login;
    string haslo;

public:
    void ustawId(int noweId);//gettery aby udostepnic innym klasa, tu publiczenie s� metody, kt�re zabezpieczamy w pliku .cpp
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);

    int pobierzId();//settery
    string pobierzLogin();
    string pobierzHaslo();
};

#endif
