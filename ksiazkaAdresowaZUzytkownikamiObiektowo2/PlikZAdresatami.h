#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami: public PlikTekstowy
{
    string NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI;
    int idOstatniegoAdresata;
    int idUsuwanegoAdresata;

    bool czyPlikJestPusty2(fstream &plikTekstowy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI = "AdresaciTymczasowi.txt";
        idOstatniegoAdresata = 0;
        idUsuwanegoAdresata = 0;
    };

    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    int usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();
    void edytujAdresataWPliku(Adresat adresat);
};

#endif
