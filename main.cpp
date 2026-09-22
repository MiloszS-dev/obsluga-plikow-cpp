#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dane{

private:
    string nazwisko;
    string numer;

public:

    bool odczytaj(ifstream &plik){
        if(plik >> nazwisko >> numer){
            return true;
        }
        else{
            return false;
        }
    }

    void wyswietl(){
        cout<<nazwisko<<"  "<<numer<<endl;
    }

    void zapisz(ofstream &plik){
        plik << nazwisko << "  " << numer<<endl;
    }

};



int main()
{
    dane osoba;

    ifstream plik("dane.txt");
    ofstream wynik("wynik.txt");

    while(osoba.odczytaj(plik)){
        osoba.wyswietl();
        osoba.zapisz(wynik);
    }

    plik.close();
    wynik.close();

    return 0;
}
