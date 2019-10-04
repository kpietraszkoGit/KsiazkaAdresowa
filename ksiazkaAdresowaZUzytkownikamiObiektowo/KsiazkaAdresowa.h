#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

class KsiazkaAdresowa
{

    UzytkownikMenadzer uzytkownikMenadzer; //obiekt//12:00
    AdresatMenadzer *adresatMenadzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public://KsiazkaAdresowa();//konstruktor ma taka sama nazwe jak nazwa klasy w której sie znajduje
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenadzer = NULL;// jak sie pracuje na wskaźnikach trzeba przypisać NULL i stworzyć destruktor
    };//konstruktor z lista inicjalizujaca
    ~KsiazkaAdresowa()
    {
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    };

    void rejestracjaUzytkownika();// wywolam odpowiednia metode z UzytkownikMenadzer
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();


    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
};

#endif
