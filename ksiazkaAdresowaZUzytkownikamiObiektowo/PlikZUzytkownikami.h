#ifndef PLIKIZUZYTKOWNIKAMI_H
#define PLIKIZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
////////////////////////////////////
//#include "UzytkownikMenadzer.h"


using namespace std;

class PlikZUzytkownikami
{
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;//stala globalna
    //fstream plikTekstowy;

    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami): NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {};//konstruktor z lista inicjalizujaca {}-cia³o konstruktora
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

    //void zapiszWszystkichUzytkownikowDoPliku(Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};

#endif
