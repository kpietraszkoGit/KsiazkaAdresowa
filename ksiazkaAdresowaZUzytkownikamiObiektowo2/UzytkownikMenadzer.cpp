#include "UzytkownikMenadzer.h"

void UzytkownikMenadzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    Sleep(2000);
    return;
}

Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenadzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenadzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenadzer::logowanieUzytkownika()
{
    string login = "", haslo = "";
    int i = 0;

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    while (i < uzytkownicy.size())
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

bool UzytkownikMenadzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

int UzytkownikMenadzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenadzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}

void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika()
{
    if (idZalogowanegoUzytkownika > 0)
    {
        string noweHaslo = "";
        cout << "Podaj nowe haslo: ";
        noweHaslo = MetodyPomocnicze::wczytajLinie();

        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            if (itr -> pobierzId() == idZalogowanegoUzytkownika)
            {
                itr -> ustawHaslo(noweHaslo);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
    else
    {
        cout << "Aby zmienic haslo, nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

