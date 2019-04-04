#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

enum{
kier = 18,
karo = 17,
wino = 16,
trefl = 15,
As = 14,
Krol = 13,
Dama = 12,
Wallet = 11,
dziesiec = 10,
dziewiec = 9,
osiem = 8,
siedem = 7,
szesc = 6,
piec = 5,
cztery = 4,
trzy =3,
dwa = 2,
jeden = 1
};

class Karta{
public:
    Karta(int f,int k){figura = f;kolor = k;}
    int pokaz_figure(){return figura;}
    int pokaz_kolor(){return kolor;}
private:
    int kolor;
    int figura;
};

class Talia{
public:
    Talia(){generuj_talie();}
    queue<Karta> karty;
    int ilosc_kolorow = 4;
    int rodzaje_kart = 12;
    int rozmiar_tali = 52;
private:

    void generuj_talie(){
        for(int i=0;i<rodzaje_kart;i++){
            for(int j=0;j<ilosc_kolorow;j++){
                Karta *karta = new Karta(i,j);
                karty.push(*karta);
                delete karta;
            }
        }
    }

    void tasuj(){

    }
};

class Plansza{
public:
    Plansza(Talia t){talia = t;}
    vector< vector<Karta> > pola1;
    vector< stack<Karta> > pola2;
private:
    Talia talia;
    int ilosc_pol = 7;
    int ilosc_stosow = 4;
    void rysuj_plansze(){
    rysuj_pola1();
    rysuj_pola2();
    };
    void rysuj_pola1();
    void rysuj_pola2();

};





int main()
{
    Karta as_karo(As,karo);
    Talia talia;
    Plansza plansza(talia);
     for(int i=0;i<52;i++){
        cout<< talia.karty.front().pokaz_figure()<<endl;
        talia.karty.pop();
    }
    cout<< as_karo.pokaz_figure()<<endl;
    cout<< as_karo.pokaz_kolor()<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
