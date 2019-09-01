#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Adresat
{
int id = 0;
string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";
};

int wyszukiwaniePoImieniu(vector<Adresat> adresaci, int iloscOsob)//Osoba osoby[] == vector<Adresat> adresaci
{
    system("cls");
    string imie;
    int i=0;
    int iloscWystepujacegoImienia=0;
    cout << "Podaj imie jakie chcesz wyszukac: ";
    cin >> imie;

    if (iloscOsob>i)
    {
            while (i<iloscOsob)
            {
                if (adresaci[i].imie==imie)
                {
                    cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                    iloscWystepujacegoImienia++;
                }
                i++;
            }
            if(iloscWystepujacegoImienia==0)
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
    else if (iloscOsob==0)
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
    int i=0;
    int iloscWystepujacegoNazwiska=0;
    cout << "Podaj nazwisko jakie chcesz wyszukac: ";
    cin >> nazwisko;

    if(iloscOsob>i)
    {
        while (i<iloscOsob)
        {
            if (adresaci[i].nazwisko==nazwisko)
            {
            cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
            iloscWystepujacegoNazwiska++;
            }
            i++;
        }
        if (iloscWystepujacegoNazwiska==0)
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
    else if (iloscOsob==0)
    {
        cout << "Nie ma takiego nazwiska w ksiazce adresowej, bo jest pusta!" << endl;
        Sleep(3000);
    }
    return 0;
}

int wczytajWszystkieOsobyZPliku(vector<Adresat> adresaci)
{
    int nr_linii=1;
    int iloscOsob=0;
    string linia;
    int ostatni = 0;
    Adresat adresat;//obiekt adresu

    adresaci.clear();//zmiana tutaj

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);
    if (plik.good()==false) //sprawdza czy plik istnieje
    {
        cout<<"Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik, linia)) //funkcja pobiera ca³a linie z pliku plik, zmienna linia zeby tam by³a przechowywana wartosc pobranej linii, ci¹gle nam bedzie pobieraæ linie
    {
        ////////////////////////////////////////////////////////////////////rozdzial lini na slowa
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i=0; i<6; i++)
        {
            switch(i)
            {
                case 0: adresat.id = atoi(el[i].c_str());                   break;
                case 1: adresat.imie = el[i];                               break;
                case 2: adresat.nazwisko = el[i];                           break;
                case 3: adresat.numerTelefonu = el[i];                      break;
                case 4: adresat.email = el[i];                              break;
                case 5: adresat.adres = el[i];                              break;
            }
        }
        if (nr_linii>0)
        {
            iloscOsob++;
        }
        nr_linii++;
        adresaci.push_back(adresat); //to zakomentowane
    }
    plik.close();

    ostatni = adresaci.size();
    if (iloscOsob==0)
    {
        return iloscOsob;
    }
    if (iloscOsob==adresaci[ostatni-1].id)
    {
        return iloscOsob;
    }
    else if (iloscOsob!=adresaci[ostatni-1].id)
    {
        return adresaci[ostatni-1].id;
    }
}

//funkcja wczytywania wektor
vector<Adresat> wczytajWszystkieOsobyZPlikuWektor(vector<Adresat> adresaci)
{
    int nr_linii=1;
    int iloscOsob=0;
    string linia;
    Adresat adresat;//obiekt adresu

    adresaci.clear();//zmiana tutaj

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);
    if (plik.good()==false) //sprawdza czy plik istnieje
    {
        cout<<"Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik, linia)) //funkcja pobiera ca³a linie z pliku plik, zmienna linia zeby tam by³a przechowywana wartosc pobranej linii, ci¹gle nam bedzie pobieraæ linie
    {
        ////////////////////////////////////////////////////////////////////rozdzial lini na slowa
        string s = linia;
        vector <string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '|'))
        {
            el.push_back(item);
        }
        for (int i=0; i<6; i++)
        {
            switch(i)
            {
                case 0: adresat.id = atoi(el[i].c_str());                   break;
                case 1: adresat.imie = el[i];                               break;
                case 2: adresat.nazwisko = el[i];                           break;
                case 3: adresat.numerTelefonu = el[i];                      break;
                case 4: adresat.email = el[i];                              break;
                case 5: adresat.adres = el[i];                              break;
            }
        }
        if (nr_linii>0)
        {
            iloscOsob++;
        }
        nr_linii++;
        adresaci.push_back(adresat);
    }
    plik.close();

    return adresaci;
}

void wyswietlWszystkieOsobyZPliku(vector<Adresat> adresaci, int iloscOsob)
{
    system("cls");
    int nr_linii=1;
    string linia;
    Adresat adresat;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);
    if (plik.good()==false) //sprawdza czy plik istnieje
    {
        cout<<"Plik nie istnieje lub jest jakis blad!";
        exit(0);
    }
    while (getline(plik, linia)) //funkcja pobiera ca³a linie z pliku plik, zmienna linia zeby tam by³a przechowywana wartosc pobranej linii, ci¹gle nam bedzie pobieraæ linie
    {
        cout << linia << endl;
    }
    plik.close();


    if (iloscOsob==0)
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

int dodajNowaOsobe(vector<Adresat> adresaci, int iloscOsob)
{
    int i=0;
    int iloscWystepowaniaTegoSamegoKontaktu=0;
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

    if(iloscWystepowaniaTegoSamegoKontaktu==0)
    {
        // ustalam id osoby
        int osobaId = iloscOsob + 1;

        // dodaje osobe do wektora
        adresat.id = osobaId;
        adresat.imie = imie;
        adresat.nazwisko = nazwisko;
        adresat.numerTelefonu = numerTelefonu;
        adresat.email = email;
        adresat.adres = adres;

        adresaci.push_back(adresat);

        // dodaje osobe do pliku
        fstream plik;
        plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);
        if (plik.good())
        {

            plik << osobaId << "|" << imie << "|" << nazwisko << "|" << numerTelefonu << "|" << email << "|"  << adres << "|" << endl;

            plik.close();

            cout << "Osoba zostala dodana." << endl;
            Sleep(1000);
            iloscOsob++;
        }
        else
        {
            cout << "Nie mozna otworzyc pliku: KsiazkaAdresowa.txt" << endl;
        }
    }
return iloscOsob;
}

void menuDoEdycji(vector<Adresat> adresaci, int iloscOsob, int id)
{
    system("cls");
    char wybor;
    int i=0;
    Adresat adresat;
    //Adresat adresat;
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
    if (wybor =='1')
    {
        string imieZmiany;
        cout << "Podaj imie do zmiany: ";
        cin >> imieZmiany;
        while (i<iloscOsob)
        {
            if (adresaci[i].id==id)
            {
                adresaci[i].imie = imieZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
        cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }
        //system("pause");

            fstream plik;
            plik.open("KsiazkaAdresowa.txt", ios::out | ios::trunc);
            if (plik.good())
            {

                for (int i = 0; i < adresaci.size(); i++)
                {
                plik << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                }
                plik.close();

                cout << "Nastapila zmiana imienia." << endl;
                Sleep(1000);
                iloscOsob++;
            }

        Sleep(3000);
    }
    else if (wybor =='2')
    {
        string nazwiskoZmiany;
        cout << "Podaj nazwisko do zmiany: ";
        cin >> nazwiskoZmiany;
        while (i<iloscOsob)
        {
            if (adresaci[i].id==id)
            {
                adresaci[i].nazwisko = nazwiskoZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
        cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }

            fstream plik;
            plik.open("KsiazkaAdresowa.txt", ios::out | ios::trunc);
            if (plik.good())
            {
                for (int i = 0; i < adresaci.size(); i++)
                {
                plik << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                }
                plik.close();

                cout << "Nastapila zmiana nazwiska." << endl;
                Sleep(1000);
                iloscOsob++;
            }

        Sleep(3000);

    }
    else if (wybor =='3')
    {
        string numerTelefonuZmiany;
        cout << "Podaj numer telefonu do zmiany: ";
        cin >> numerTelefonuZmiany;
        while (i<iloscOsob)
        {
            if (adresaci[i].id==id)
            {
                adresaci[i].numerTelefonu = numerTelefonuZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
        cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }

            fstream plik;
            plik.open("KsiazkaAdresowa.txt", ios::out | ios::trunc);
            if (plik.good())
            {
                for (int i = 0; i < adresaci.size(); i++)
                {
                plik << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                }
                plik.close();

                cout << "Nastapila zmiana numeru telefonu." << endl;
                Sleep(1000);
                iloscOsob++;
            }

        Sleep(3000);

    }
    else if (wybor =='4')
    {
        string emailZmiany;
        cout << "Podaj email do zmiany: ";
        cin >> emailZmiany;
        while (i<iloscOsob)
        {
            if (adresaci[i].id==id)
            {
                adresaci[i].email = emailZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
        cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }

            fstream plik;
            plik.open("KsiazkaAdresowa.txt", ios::out | ios::trunc);
            if (plik.good())
            {
                for (int i = 0; i < adresaci.size(); i++)
                {
                plik << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                }
                plik.close();

                cout << "Nastapila zmiana email-a." << endl;
                Sleep(1000);
                iloscOsob++;
            }

        Sleep(3000);

    }
    else if (wybor =='5')
    {
        string adresZmiany;
        cout << "Podaj adres do zmiany: ";
        cin >> adresZmiany;
        while (i<iloscOsob)
        {
            if (adresaci[i].id==id)
            {
                adresaci[i].adres = adresZmiany;
            }
        i++;
        }
        for (int i = 0; i < adresaci.size(); i++)
        {
        cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }

            fstream plik;
            plik.open("KsiazkaAdresowa.txt", ios::out | ios::trunc);
            if (plik.good())
            {
                for (int i = 0; i < adresaci.size(); i++)
                {
                plik << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                }
                plik.close();

                cout << "Nastapila zmiana adresu." << endl;
                Sleep(1000);
                iloscOsob++;
            }

        Sleep(3000);

    }
    else if (wybor =='6')
    {

    }

}
void edytowanieOsoby(vector<Adresat> adresaci, int iloscOsob)
{
    system("cls");
    char wybor;
    int id;
    int i=0;
    int iloscWystepujacegoID=0;
    cout << "Podaj ID adresata, ktorego chcesz edytowac?" << endl;
    cout << "Twoj wybor: ";
    cin >> id;
    if (iloscOsob>i)
    {
        while (i<iloscOsob)
        {
            if (adresaci[i].id==id)
            {
            cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
            iloscWystepujacegoID++;
            }
            i++;
        }
        if (iloscWystepujacegoID==0)
        {
            cout << "Nie ma takiego ID w ksiazce adresowej!" << endl;
            Sleep(3000);
        }
        else
        {
        cout << endl << "Wcisnij jakis klawisz aby przejsc do menu edycyjnego" << endl;
        system("pause");
        menuDoEdycji(adresaci, iloscOsob, id);
        }
    }
    else if (iloscOsob==0)
    {
        cout << "Nie ma takiego ID w ksiazce adresowej, bo jest pusta!" << endl;
        Sleep(3000);
    }
}

vector<Adresat> usunOsobeZPliku(vector<Adresat> adresaci, int iloscOsob2)
{
    system("cls");
    char wybor;
    char wyborTak;
    int id;
    int i=0;
    int iloscWystepujacegoID=0;
    iloscOsob2 = adresaci.size();
    cout << "Podaj ID adresata, ktorego chcesz usunac?" << endl;
    cout << "Twoj wybor: ";
    cin >> id;

    if (iloscOsob2>i)
    {
        while (i<iloscOsob2)
        {
            if (adresaci[i].id==id)
            {
            cout << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
            iloscWystepujacegoID++;

                cout << "Jesli chcesz usunac tego adresata nacisnij 't': ";
                cin >> wyborTak;
                if (wyborTak =='t')
                {
                    adresaci.erase( adresaci.begin() + i );
                    cout << "Kontakt zostal usuniety" << endl;

                    /////////////zapisac to do pliku
                        fstream plik;
                        plik.open("KsiazkaAdresowa.txt", ios::out | ios::trunc);
                        if (plik.good())
                        {
                            for (int i = 0; i < adresaci.size(); i++)
                            {
                            plik << adresaci[i].id << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].numerTelefonu << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
                            }
                            plik.close();

                            Sleep(1000);
                        }
                    adresaci.clear();
                }
                else
                {
                    cout << "Wcisnales inny klawisz, adresat nie zostanie usuniety" << endl;
                    Sleep(3000);
                }
            }
            i++;
        }
        if (iloscWystepujacegoID==0)
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
    else if(iloscOsob2==0)
    {
        cout << "Nie ma takiego ID w ksiazce adresowej, bo jest pusta!" << endl;
        Sleep(3000);
    }
    return adresaci;
}


int main()
{
    vector<Adresat> adresaci;
    vector<Adresat> adresaci2;
    int iloscOsob = 0;
    char wyborWMenu;
    ////////////////////////////Tworzenie pliku
    ifstream plik;
    plik.open("KsiazkaAdresowa.txt");
    if (plik)//jest plik
    {
        cout << "Plik istnieje";
    }
    else if(!plik)//nie ma pliku
    {
        string nazwa_pliku;
        nazwa_pliku = "KsiazkaAdresowa.txt";
        ofstream plik(nazwa_pliku.c_str());
    }
    /////////////////////////////////////////
    while (true)
    {
        system("cls");
        cout << "1. Dodaj adresata" << endl;
        cout << "2. Wyszukaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" << endl;
        cout << "4. Wyswietl wszystkich adresatow" << endl;
        cout << "5. Usun adresata" << endl;
        cout << "6. Edytuj adresata" << endl;
        cout << "9. Zakoncz program" << endl;
        cout  << "*******************" << endl;
        cout  << "Twoj wybor: ";
        cin >> wyborWMenu;

        if (wyborWMenu == '1')
        {
            iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);//osoby==adresaci
            adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci);
            iloscOsob = dodajNowaOsobe(adresaci, iloscOsob);
        }
        else if (wyborWMenu == '2')
        {
            iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
            adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci);
            wyszukiwaniePoImieniu(adresaci, iloscOsob);
        }
        else if (wyborWMenu == '3')
        {
            iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
            adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci);
            wyszukiwaniePoNazwisku(adresaci, iloscOsob);
        }
        else if (wyborWMenu == '4')
        {
            iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
            wyswietlWszystkieOsobyZPliku(adresaci, iloscOsob);
        }
        else if (wyborWMenu == '5')
        {
            iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
            adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci);
            adresaci2 = usunOsobeZPliku(adresaci, iloscOsob);

        }
        else if (wyborWMenu == '6')
        {
            iloscOsob = wczytajWszystkieOsobyZPliku(adresaci);
            adresaci = wczytajWszystkieOsobyZPlikuWektor(adresaci);
            edytowanieOsoby(adresaci, iloscOsob);
        }
        else if (wyborWMenu == '9')
        {
            exit(0);
        }
    }
    return 0;
}
