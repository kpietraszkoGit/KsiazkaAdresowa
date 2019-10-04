#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;
//10:52 - zapisac to i przetestowaæ
/*int main()
{//tutaj jest ok
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    //ksiazkaAdresowa.dodajAdresata();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();

}*/
int main()
{
    vector <Uzytkownik> uzytkownicy;
    vector <Adresat> adresaci;
    //int idZalogowanegoUzytkownika;
    //int idOstatniegoAdresata = 0;
    //int idUsunietegoAdresata = 0;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");//obiekt klasy KsiazkaAdresowa
    char wybor;

    while (true)
    {
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
               // wyszukajAdresatowPoImieniu(adresaci);
               // break;
            case '3':
               // wyszukajAdresatowPoNazwisku(adresaci);
               // break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                //break;
            case '6':
                //edytujAdresata(adresaci);
                //break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                //idZalogowanegoUzytkownika = 0;
                adresaci.clear();
                break;
            }
        }
        else
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
/*#include "AdresatMenadzer.h"
int main()
{
  AdresatMenadzer adresatMenadzer("Adresatek.txt", 2);
  adresatMenadzer.wyswietlWszystkichAdresatow();
  adresatMenadzer.dodajAdresata();
  adresatMenadzer.wyswietlWszystkichAdresatow();
}*/

