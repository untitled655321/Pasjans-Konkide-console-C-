#include <iostream>

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


int main()
{
    Karta as_karo(As,karo);
    cout<< as_karo.pokaz_figure()<<endl;
    cout<< as_karo.pokaz_kolor()<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
