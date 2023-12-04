#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string imie, nazwisko, film;
    int rokurodzenia;
    cout<<"Prosze podaj swoje dane:"<<endl;
    cout<<"podaj imie"<<endl;
    cin>>imie;
    cout<<"podaj nazwisko"<<endl;
    cin>>nazwisko;
    cout<<"podaj swoj rok urodzenia"<<endl;
    cin>>rokurodzenia;
    cout<<"podaj film na jaki chcesz isc"<<endl;
    cin>>film;

    int wiek = 2023 - rokurodzenia;
    ofstream plik("odp.txt");
    if (plik.is_open()){
        if (film == "Scooby-doo" && wiek > 7){
            plik << "mozesz isc";
        }
        else if (film == "Titanic" && wiek > 13){
            plik << "mozesz isc";
        }
        else if (film == "Potop" && wiek > 16){
            plik << "mozesz isc";
        }
        else {
            plik << "nie mozesz isc"; }
    }

    plik.close();
    return 0;
}