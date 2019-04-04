#include <iostream>
#include <vector>

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
    Karta(int f,int k){kolor = k;figura = f;}
    int pokaz_figure(){return figura;}
    int pokaz_kolor(){return kolor;}
private:
    int kolor;
    int figura;
};

class Talia{
public:
    Talia(){generuj_talie();}
    vector<Karta> karty;
    int ilosc_kart = 52;
private:
    void tasuj(){}
    void generuj_talie(){
    for(int i=0;i<ilosc_kart;i++){
        Karta *karta = new Karta(i,i);
        karty.push_back(*karta);
        delete karta;
    }
    }
};


int main()
{
    Karta as_karo(As,karo);
    Talia talia;
    cout<< as_karo.pokaz_figure()<<endl;
    cout<< as_karo.pokaz_kolor()<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
