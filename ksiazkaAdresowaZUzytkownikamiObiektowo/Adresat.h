#ifndef ADRESAT_H // zabezpieczenie przed podwójnym includowaniem uzytkownik.h
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
//wszystkie one sa prywatne zahermetyzowane
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat(int id=0, int idUzytkownika=0, string imie="", string nazwisko="", string numerTelefonu="", string email="", string adres="")
    {
        this->id = id;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }
    void ustawId(int noweId);//gettery aby udostepnic innym klasa, tu publiczenie s¹ metody, które zabezpieczamy w pliku .cpp
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzId();//settery
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};

#endif
