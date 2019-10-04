#ifndef ADRESATMENADZER_H // zabezpieczenie przed podwójnym includowaniem AdresatMenadzer.h
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
//#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenadzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;//zeby zadna metoda nie zmienila tej danej
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
   // int idZalogowanegoUzytkownika;
    //int idOstatniegoAdresata;
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);


public://15:50//19:40
    AdresatMenadzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) //konstruktor: odbieram nazwaPlikuZAdresatami i wysłam do plikuZAdresatami, natepnie odbieram idZalogowanegoUzytkownika którego przypisuje do stalej ID_ZALOGOWANEGO_UZYTKOWNIKA;
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    ///////////////////////////////////////////
    //void wypiszWszystkichAdresatow();
    //void wczytajAdresatowZalogowanegoUzytkownikaZPliku();//niezainplmentowane
};

#endif
