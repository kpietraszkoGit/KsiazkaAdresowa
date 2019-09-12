#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include<stdio.h>


using namespace std;

struct Adresat
{
int id = 0, idUzytkownik = 0;
string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";
};

struct Uzytkownik
{
    int idUzytkownika;
    string nazwa, haslo;
};

/////////////////////////////////Ksiazka Adresowa funkcje

void usunIZmienNazwePliku()
{
    remove("Adresaci.txt");
    rename("Adresaci_tymczasowy.txt", "Adresaci.txt");
}

void tworzeniePliku(string nazwaPliku)
{
    ifstream plik;
    plik.open(nazwaPliku.c_str());
    if (plik)//jest plik
    {
    }
    else if (!plik)//nie ma pliku
    {
        string nazwa_pliku;
        nazwa_pliku = nazwaPliku;
        ofstream plik(nazwa_pliku.c_str());
    }
    plik.close();
}

int wyszukiwaniePoImieniu(vector<Adresat> adresaci, int iloscOsob)
{
    system("cls");
    string imie;
    int i = 0;
    int iloscWystepujacegoImienia = 0;
    cout << "Podaj imie jakie chcesz wyszukac: ";
    cin >> imie;

    if (iloscOsob > i)
    {
            while (i < iloscOsob)
            {
                if (adresaci[i].imie == imie)
                {
                    cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                    iloscWystepujacegoImienia++;
                }
                i++;
            }
            if (iloscWystepujacegoImienia == 0)
            {
                cout << "Nie ma takiego imienia w ksiazce adresowej!" << endl;
                Sleep(3000);
            }
            else
            {
                cout << endl << "Wcisnij jakis klawisz aby przejsc do menu" << endl;
                system("pause");
            }
    }
    else if (iloscOsob == 0)
    {
        cout << "Nie ma takiego imienia w ksiazce adresowej, bo jest pusta!" << endl;
        Sleep(3000);
    }
    return 0;
}

int wyszukiwaniePoNazwisku(vector<Adresat> adresaci, int iloscOsob)
{
    system("cls");
    string nazwisko;
    int i = 0;
    int iloscWystepujacegoNazwiska = 0;
    cout << "Podaj nazwisko jakie chcesz wyszukac: ";
    cin >> nazwisko;

    if (iloscOsob > i)
    {
        while (i < iloscOsob)
        {
            if (adresaci[i].nazwisko == nazwisko)
            {
                cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                iloscWystepujacegoNazwiska++;
            }
            i++;
        }
        if (iloscWystepujacegoNazwiska == 0)
        {
            cout << "Nie ma takiego nazwiska w ksiazce adresowej!" << endl;
            Sleep(3000);
        }
        else
        {
            cout << endl << "Wcisnij jakis klawisz aby przejsc do menu" << endl;
            system("pause");
        }
    }
    else if (iloscOsob == 0)
    {
        cout << "Nie ma takiego nazwiska w ksiazce adresowej, bo jest pusta!" << endl;
        Sleep(3000);
    }
    return 0;
}

int wczytajWszystkieOsobyZPliku(vector<Adresat> adresaci)
{
    int nr_linii = 1;
    int iloscOsob = 0;
    string linia;
    int ostatni = 0;
    Adresat adresat;//obiekt adresu

    adresaci.clear();

    fstream plik;
    plik.open("Adresaci.txt",ios::in);
    if (plik.good() == false) //sprawdza czy plik istnieje
    {
        cout<<"Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik, linia))
    {
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i = 0; i < 7; i++)
        {
            switch(i)
            {
                case 0: adresat.id = atoi(el[i].c_str());                   break;
                case 1: adresat.idUzytkownik = atoi(el[i].c_str());         break;
                case 2: adresat.imie = el[i];                               break;
                case 3: adresat.nazwisko = el[i];                           break;
                case 4: adresat.numerTelefonu = el[i];                      break;
                case 5: adresat.email = el[i];                              break;
                case 6: adresat.adres = el[i];                              break;
            }
        }
        if (nr_linii > 0)
        {
            iloscOsob++;
        }
        nr_linii++;
        adresaci.push_back(adresat);
    }
    plik.close();

    ostatni = adresaci.size();

    if (iloscOsob == 0)
    {
        return iloscOsob;
    }
    else if (iloscOsob == adresaci[ostatni-1].id)
    {
        return iloscOsob;
    }
    else if (iloscOsob != adresaci[ostatni-1].id)
    {
        return adresaci[ostatni-1].id;
    }
}

vector<Adresat> wczytajWszystkieOsobyZPlikuWektor(vector<Adresat> adresaci, int idZalogowaniegoUzytkownika)
{
    int nr_linii = 1;
    int iloscOsob = 0;
    string linia;
    Adresat adresat;//obiekt adresu

    adresaci.clear();

    fstream plik;
    plik.open("Adresaci.txt",ios::in);
    if (plik.good() == false) //sprawdza czy plik istnieje
    {
        cout<<"Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik, linia))
    {
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i = 0; i < 7; i++)
        {
            switch(i)
            {
                case 0: adresat.id = atoi(el[i].c_str());                   break;
                case 1: adresat.idUzytkownik = atoi(el[i].c_str());         break;
                case 2: adresat.imie = el[i];                               break;
                case 3: adresat.nazwisko = el[i];                           break;
                case 4: adresat.numerTelefonu = el[i];                      break;
                case 5: adresat.email = el[i];                              break;
                case 6: adresat.adres = el[i];                              break;
            }
        }
        if (nr_linii > 0)
        {
            iloscOsob++;
        }
        nr_linii++;
        if(adresat.idUzytkownik == idZalogowaniegoUzytkownika)
        {
            adresaci.push_back(adresat);
        }
    }
    plik.close();

    return adresaci;
}

void wyswietlWszystkieOsobyZPliku(vector<Adresat> adresaci, int iloscOsob)
{
    system("cls");
    int nr_linii = 1;
    string linia;
    Adresat adresat;

    for (int i = 0; i < adresaci.size(); i++)
    {
        cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
    }

    if (iloscOsob == 0)
    {
        cout << "Ksiazka adresowa jest pusta!" << endl;
        Sleep(3000);
    }
    else
    {
        cout << endl << "Wcisnij jakis klawisz aby przejsc do menu" << endl;
        system("pause");
    }
}

int dodajNowaOsobe(vector<Adresat> adresaci, int iloscOsob, int idZalogowanegoUzytkownika)
{
    int i = 0;
    int iloscWystepowaniaTegoSamegoKontaktu = 0;
    string imie, nazwisko, numerTelefonu, email, adres;
    Adresat adresat; // element strukury Adresat;

    // Pobieram dane nowej osoby
    system("cls");
    cout << "Dodawanie osoby" << endl;
    cout << "Podaj imie uzytkownika: ";
    cin >> imie;
    cout << "Podaj nazwisko uzytkownika: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu uzytkownika: ";
    cin.sync(); // oprozniam bufor
    getline(cin, numerTelefonu); // wczytuje razem ze spacja
    cout << "Podaj email uzytkownika: ";
    cin >> email;
    cout << "Podaj adres uzytkownika: ";
    cin.sync();
    getline(cin, adres);

    if (iloscWystepowaniaTegoSamegoKontaktu == 0)
    {
        // ustalam id osoby
        int osobaId = iloscOsob + 1;

        // dodaje osobe do wektora
        adresat.id = osobaId;
        adresat.idUzytkownik = idZalogowanegoUzytkownika;
        adresat.imie = imie;
        adresat.nazwisko = nazwisko;
        adresat.numerTelefonu = numerTelefonu;
        adresat.email = email;
        adresat.adres = adres;

        adresaci.push_back(adresat);

        // dodaje osobe do pliku
        fstream plik;
        plik.open("Adresaci.txt", ios::out | ios::app);
        if (plik.good())
        {
            plik << osobaId << "|" << idZalogowanegoUzytkownika << "|" << imie << "|" << nazwisko << "|" << numerTelefonu << "|" << email << "|"  << adres << "|" << endl;

            plik.close();

            cout << "Osoba zostala dodana." << endl;
            Sleep(1000);
            iloscOsob++;
        }
        else
        {
            cout << "Nie mozna otworzyc pliku: Adresaci.txt" << endl;
        }
    }
return iloscOsob;
}

vector<Adresat> menuDoEdycji(vector<Adresat> adresaci, int iloscOsob, int id)
{
    system("cls");
    char wybor;
    int i = 0;
    Adresat adresat;

    cout << "Co chcesz edytowac?" << endl;
    cout << "*******************" << endl;
    cout << "1-imie" << endl;
    cout << "2-nazwisko" << endl;
    cout << "3-numer telefonu" << endl;
    cout << "4-email" << endl;
    cout << "5-adres" << endl;
    cout << "6-powrot do menu" << endl;
    cout  << "*******************" << endl;
    cout  << "Twoj wybor: ";
    cin >> wybor;
    if (wybor == '1')
    {
        string imieZmiany;
        cout << "Podaj imie do zmiany: ";
        cin >> imieZmiany;
        while (i < iloscOsob)
        {
            if (adresaci[i].id == id)
            {
                adresaci[i].imie = imieZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
            cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }
        Sleep(3000);
    }
    else if (wybor == '2')
    {
        string nazwiskoZmiany;
        cout << "Podaj nazwisko do zmiany: ";
        cin >> nazwiskoZmiany;
        while (i < iloscOsob)
        {
            if (adresaci[i].id == id)
            {
                adresaci[i].nazwisko = nazwiskoZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
            cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }
        Sleep(3000);

    }
    else if (wybor == '3')
    {
        string numerTelefonuZmiany;
        cout << "Podaj numer telefonu do zmiany: ";
        cin >> numerTelefonuZmiany;
        while (i < iloscOsob)
        {
            if (adresaci[i].id == id)
            {
                adresaci[i].numerTelefonu = numerTelefonuZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
            cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }
        Sleep(3000);

    }
    else if (wybor == '4')
    {
        string emailZmiany;
        cout << "Podaj email do zmiany: ";
        cin >> emailZmiany;
        while (i < iloscOsob)
        {
            if (adresaci[i].id == id)
            {
                adresaci[i].email = emailZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
            cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }
        Sleep(3000);

    }
    else if (wybor == '5')
    {
        string adresZmiany;
        cout << "Podaj adres do zmiany: ";
        cin >> adresZmiany;
        while (i < iloscOsob)
        {
            if (adresaci[i].id == id)
            {
                adresaci[i].adres = adresZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
            cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }
        Sleep(3000);

    }
    else if (wybor == '6')
    {
    }
    return adresaci;
}


void zapisanieAktualnychAdresatowDoPliku(vector<Adresat> adresaciEdycja, int id)
{
    vector<Adresat> adresaci;
    string linia;
    Adresat adresat;
    string nazwaPlikuTymczasowego = "Adresaci_tymczasowy.txt";

    tworzeniePliku(nazwaPlikuTymczasowego);

    fstream plik;
    plik.open("Adresaci.txt",ios::in);
    if (plik.good() == false) //sprawdza czy plik istnieje
    {
        cout<<"Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik, linia))
    {
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i = 0; i < 7; i++)
        {
            switch(i)
            {
                case 0: adresat.id = atoi(el[i].c_str());                   break;
                case 1: adresat.idUzytkownik = atoi(el[i].c_str());         break;
                case 2: adresat.imie = el[i];                               break;
                case 3: adresat.nazwisko = el[i];                           break;
                case 4: adresat.numerTelefonu = el[i];                      break;
                case 5: adresat.email = el[i];                              break;
                case 6: adresat.adres = el[i];                              break;
            }
        }
        adresaci.push_back(adresat);
    }
    plik.close();



    for (int i = 0; i < adresaci.size(); i++)
    {
        fstream plik3;
        plik3.open("Adresaci_tymczasowy.txt", ios::out | ios::app);
        if (plik3.good())
        {
            if (adresaci[i].id == id)
            {
                for (int i = 0; i < adresaciEdycja.size(); i++)
                {
                    if(adresaciEdycja[i].id == id)
                    {
                        plik3 << adresaciEdycja[i].id << "|" << adresaciEdycja[i].idUzytkownik << "|" << adresaciEdycja[i].imie << "|" << adresaciEdycja[i].nazwisko << "|" << adresaciEdycja[i].numerTelefonu << "|" << adresaciEdycja[i].email << "|" << adresaciEdycja[i].adres << "|" << endl;
                    }
                }
            }
            else
            {
                plik3 << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
            }
        }
        plik3.close();
    }
    usunIZmienNazwePliku();
}

vector<Adresat> edytowanieOsoby(vector<Adresat> adresaci, int iloscOsob)
{
    system("cls");
    char wybor;
    int id;
    int i=0;
    int iloscWystepujacegoID=0;
    cout << "Podaj ID adresata, ktorego chcesz edytowac?" << endl;
    cout << "Twoj wybor: ";
    cin >> id;
    if (iloscOsob > i)
    {
        while (i < iloscOsob)
        {
            if (adresaci[i].id == id)
            {
                cout << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                iloscWystepujacegoID++;
            }
            i++;
        }
        if (iloscWystepujacegoID == 0)
        {
            cout << "Nie ma takiego ID w ksiazce adresowej!" << endl;
            Sleep(3000);
        }
        else
        {
            cout << endl << "Wcisnij jakis klawisz aby przejsc do menu edycyjnego" << endl;
            system("pause");
            adresaci = menuDoEdycji(adresaci, iloscOsob, id);
            zapisanieAktualnychAdresatowDoPliku(adresaci, id);
        }
    }
    else if (iloscOsob == 0)
    {
        cout << "Nie ma takiego ID w ksiazce adresowej, bo jest pusta!" << endl;
        Sleep(3000);
    }
    return adresaci;
}

vector<Adresat> usunOsobeZPliku(vector<Adresat> adresaciUsuniecie, int iloscOsob2)
{
    system("cls");
    char wybor;
    char wyborTak;
    int id;
    int i = 0;
    int iloscWystepujacegoID = 0;
    string nazwaPlikuTymczasowego = "Adresaci_tymczasowy.txt";
    vector<Adresat> adresaci;
    string linia;
    Adresat adresat;
    iloscOsob2 = adresaciUsuniecie.size();

    cout << "Podaj ID adresata, ktorego chcesz usunac?" << endl;
    cout << "Twoj wybor: ";
    cin >> id;

    fstream plik;
    plik.open("Adresaci.txt",ios::in);
    if (plik.good() == false) //sprawdza czy plik istnieje
    {
        cout<<"Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik, linia))
    {
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i = 0; i < 7; i++)
        {
            switch(i)
            {
                case 0: adresat.id = atoi(el[i].c_str());                   break;
                case 1: adresat.idUzytkownik = atoi(el[i].c_str());         break;
                case 2: adresat.imie = el[i];                               break;
                case 3: adresat.nazwisko = el[i];                           break;
                case 4: adresat.numerTelefonu = el[i];                      break;
                case 5: adresat.email = el[i];                              break;
                case 6: adresat.adres = el[i];                              break;
            }
        }
        adresaci.push_back(adresat);
    }
    plik.close();

    if (iloscOsob2 > i)
    {
        while (i < iloscOsob2)
        {
            if (adresaciUsuniecie[i].id == id)
            {
            cout << adresaciUsuniecie[i].id << "|" << adresaciUsuniecie[i].idUzytkownik << "|" << adresaciUsuniecie[i].imie << "|" << adresaciUsuniecie[i].nazwisko << "|" << adresaciUsuniecie[i].numerTelefonu << "|" << adresaciUsuniecie[i].email << "|" << adresaciUsuniecie[i].adres << "|" << endl;
            iloscWystepujacegoID++;

                cout << "Jesli chcesz usunac tego adresata nacisnij 't': ";
                cin >> wyborTak;
                if (wyborTak == 't')
                {
                    adresaciUsuniecie.erase( adresaciUsuniecie.begin() + i );
                    cout << "Kontakt zostal usuniety" << endl;

                    tworzeniePliku(nazwaPlikuTymczasowego);

                    /////////////zapisac to do pliku
                    fstream plik;
                    plik.open("Adresaci_tymczasowy.txt", ios::out | ios::trunc);
                    if (plik.good())
                    {
                        for (int i = 0; i < adresaci.size(); i++)
                        {
                                if (adresaci[i].id != id)
                                {
                                    plik << adresaci[i].id << "|" << adresaci[i].idUzytkownik << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                                }
                        }
                    }
                    plik.close();
                    Sleep(1000);
                    usunIZmienNazwePliku();
                }
                else
                {
                    cout << "Wcisnales inny klawisz, adresat nie zostanie usuniety" << endl;
                    Sleep(3000);
                }
            }
            i++;
        }
        if (iloscWystepujacegoID == 0)
        {
            cout << "Nie ma takiego ID w ksiazce adresowej!" << endl;
            Sleep(3000);
        }
        else
        {
            cout << endl << "Wcisnij jakis klawisz aby przejsc do menu" << endl;
            system("pause");
        }
    }
    else if(iloscOsob2 == 0)
    {
        cout << "Nie ma takiego ID w ksiazce adresowej, bo jest pusta!" << endl;
        Sleep(3000);
    }
    return adresaci;
}

int rejestracja(vector<Uzytkownik> uzytkownicy, int usersCount)
{
    string nazwa, haslo;
    int i = 0;
    Uzytkownik uzytkownik;//obiekt
    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;

    while(i < usersCount)
    {
        if(uzytkownicy[i].nazwa == nazwa)
        {
            cout << "Taki uzytkownik juz istnieje. Napisz inna nazwe uzytkownika: ";
            cin >> nazwa;
            i=0;
        }
        else
        {
            i++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> haslo;

    int usersId = usersCount + 1;

    uzytkownik.nazwa = nazwa;
    uzytkownik.haslo = haslo;
    uzytkownik.idUzytkownika = usersId;

    uzytkownicy.push_back(uzytkownik);

    // dodaje osobe do pliku
    fstream plik2;
    plik2.open("Uzytkownicy.txt", ios::out | ios::app);
    if (plik2.good())
    {

        plik2 << usersId << "|" << nazwa<< "|" << haslo << "|" << endl;
        plik2.close();

        cout << "Konto zalozone!" << endl;
        Sleep(1000);
    }
    else
    {
        cout << "Nie mozna otworzyc pliku: Uzytkownicy.txt" << endl;
    }

    return usersId;
}

int logowanie(vector<Uzytkownik> uzytkownicy, int iloscUzytkownikow)
{
    string nazwa, haslo;
    int i = 0;

    cout << "Podaj login: ";
    cin >> nazwa;

    while (i < iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa == nazwa)
        {
            for (int proby = 0; proby < 3; proby++)
            {
                cout << "Podaj haslo. Pozostalo prob " << 3-proby << ": ";
                cin >> haslo;
                if (uzytkownicy[i].haslo == haslo)
                {
                    cout << "Zalogowales sie." << endl;
                    Sleep(1000);
                    return uzytkownicy[i].idUzytkownika;
                }
            }
            cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba!" << endl;
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma takie uzytkownika z takim loginem." << endl;
    Sleep(1500);
    return 0;
}

void zmianaHasla(vector<Uzytkownik> uzytkownicy, int iloscUzytkownikow, int idZalogowaniegoUzytkownika)
{
    string haslo;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;

    for (int i=0; i<iloscUzytkownikow; i++)
    {
        if (uzytkownicy[i].idUzytkownika == idZalogowaniegoUzytkownika)//jesli sie zgadza
        {
            uzytkownicy[i].haslo = haslo;

            fstream plik2;
            plik2.open("Uzytkownicy.txt", ios::out | ios::trunc);
            if (plik2.good())
            {

                for (int i = 0; i < uzytkownicy.size(); i++)
                {
                    plik2 << uzytkownicy[i].idUzytkownika << "|" << uzytkownicy[i].nazwa << "|" << uzytkownicy[i].haslo << "|" << endl;
                }
                plik2.close();

                Sleep(1000);
                cout << "Haslo zostalo zmienione!" << endl;
                Sleep(1500);
            }
        }
    }
}

int wczytajWszystkieOsobyZPlikuUzytkownicy(vector<Uzytkownik> uzytkownicy)
{
    int nr_linii = 1;
    int iloscUzytkownikow = 0;
    string linia;
    int ostatni = 0;
    Uzytkownik uzytkownik;//obiekt adresu

    uzytkownicy.clear();//zmiana tutaj

    fstream plik2;
    plik2.open("Uzytkownicy.txt",ios::in);
    if (plik2.good()==false) //sprawdza czy plik istnieje
    {
        cout << "Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik2, linia))
    {
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i = 0; i < 3; i++)
        {
            switch(i)
            {
                case 0: uzytkownik.idUzytkownika = atoi(el[i].c_str());         break;
                case 1: uzytkownik.nazwa = el[i];                               break;
                case 2: uzytkownik.haslo = el[i];                               break;
            }
        }
        if (nr_linii > 0)
        {
            iloscUzytkownikow++;
        }
        nr_linii++;
        uzytkownicy.push_back(uzytkownik);
    }
    plik2.close();

    ostatni = uzytkownicy.size();

    if (iloscUzytkownikow == 0)
    {
        return iloscUzytkownikow;
    }
    if (iloscUzytkownikow == uzytkownicy[ostatni-1].idUzytkownika)
    {
        return iloscUzytkownikow;
    }
    else if (iloscUzytkownikow != uzytkownicy[ostatni-1].idUzytkownika)
    {
        return uzytkownicy[ostatni-1].idUzytkownika;
    }
}

vector<Uzytkownik> wczytajWszystkieOsobyZPlikuUzytkownicyWektor(vector<Uzytkownik> uzytkownicy)
{
    int nr_linii = 1;
    int iloscUzytkownikow = 0;
    string linia;
    int ostatni = 0;
    Uzytkownik uzytkownik;//obiekt adresu

    uzytkownicy.clear();//zmiana tutaj

    fstream plik2;
    plik2.open("Uzytkownicy.txt",ios::in);
    if (plik2.good() == false) //sprawdza czy plik istnieje
    {
        cout << "Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik2, linia))
    {
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i = 0; i < 3; i++)
        {
            switch(i)
            {
                case 0: uzytkownik.idUzytkownika = atoi(el[i].c_str());         break;
                case 1: uzytkownik.nazwa = el[i];                               break;
                case 2: uzytkownik.haslo = el[i];                               break;
            }
        }
        if (nr_linii > 0)
        {
            iloscUzytkownikow++;
        }
        nr_linii++;
        uzytkownicy.push_back(uzytkownik);
    }
    plik2.close();

    return uzytkownicy;
}

int main()
{
    vector<Uzytkownik> uzytkownicy;
    vector<Adresat> adresaci;
    vector<Adresat> adresaci2;
    vector<Adresat> adresaci3;
    vector<Adresat> adresaci4;
    int iloscOsob = 0;
    int idZalogowaniegoUzytkownika = 0;
    int iloscUzytkownikow = 0;
    char wybor;
    string nazwaPlikuGlownego = "Adresaci.txt";
    string nazwaPlikuUzytkownikow = "Uzytkownicy.txt";

    tworzeniePliku(nazwaPlikuGlownego);
    tworzeniePliku(nazwaPlikuUzytkownikow);

    while (1)
    {
        if (idZalogowaniegoUzytkownika == 0)
        {
            system("cls");
            cout << "1.Rejestracja" << endl;
            cout << "2.Logowanie" << endl;
            cout << "9.Zakoncz program" << endl;
            cin >> wybor;

            if (wybor == '1')
            {
                iloscUzytkownikow = wczytajWszystkieOsobyZPlikuUzytkownicy(uzytkownicy);
                uzytkownicy = wczytajWszystkieOsobyZPlikuUzytkownicyWektor(uzytkownicy);
                iloscUzytkownikow = rejestracja(uzytkownicy, iloscUzytkownikow);
            }
            else if (wybor == '2')
            {
                iloscUzytkownikow = wczytajWszystkieOsobyZPlikuUzytkownicy(uzytkownicy);
                uzytkownicy = wczytajWszystkieOsobyZPlikuUzytkownicyWektor(uzytkownicy);
                idZalogowaniegoUzytkownika = logowanie(uzytkownicy, iloscUzytkownikow);
            }
            else if (wybor == '9')
            {
            exit(0);
            }
        }
        else
        {
            system("cls");
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkich adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout  << "*******************" << endl;
            cout  << "Twoj wybor: ";
            cin >> wybor;

            if (wybor == '1')
            {
                iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
                adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci, idZalogowaniegoUzytkownika);
                iloscOsob = dodajNowaOsobe(adresaci, iloscOsob, idZalogowaniegoUzytkownika);
            }
            else if (wybor == '2')
            {
                iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
                adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci, idZalogowaniegoUzytkownika);
                wyszukiwaniePoImieniu(adresaci, iloscOsob);
            }
            else if (wybor == '3')
            {
                iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
                adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci, idZalogowaniegoUzytkownika);
                wyszukiwaniePoNazwisku(adresaci, iloscOsob);
            }
            else if (wybor == '4')
            {
                iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
                adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci, idZalogowaniegoUzytkownika);
                wyswietlWszystkieOsobyZPliku(adresaci, iloscOsob);
            }
            else if (wybor == '5')
            {
                iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
                adresaci2 = wczytajWszystkieOsobyZPlikuWektor(adresaci, idZalogowaniegoUzytkownika);
                adresaci3 = usunOsobeZPliku(adresaci2, iloscOsob);
            }
            else if (wybor == '6')
            {
                iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
                adresaci2 = wczytajWszystkieOsobyZPlikuWektor(adresaci, idZalogowaniegoUzytkownika);
                adresaci3 = edytowanieOsoby(adresaci2, iloscOsob);
            }
            else if (wybor == '7')
            {
                zmianaHasla(uzytkownicy, iloscUzytkownikow, idZalogowaniegoUzytkownika);
            }
            else if (wybor == '8')
            {
                idZalogowaniegoUzytkownika = 0;
            }
            else if (wybor == '9')
            {
                exit(0);
            }
        }
    }
    return 0;
}
