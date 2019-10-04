#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenadzer.logowanieUzytkownika();
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());//wstrzykiwanie zaleznosci miedzy klasami,przesy³anie danych
    }
}

void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        adresatMenadzer->dodajAdresata(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        adresatMenadzer->wyswietlWszystkichAdresatow(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby wyswietlic wszystkich adresatow nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenadzer.wylogowanieUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikMenadzer.czyUzytkownikJestZalogowany();
}
