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
    vector< vector<Karta> > pola_1_2_3_4_5_6_7;
    vector< stack<Karta> > pola_8_9_10_11;
    queue<Karta> pole0;
private:
    Talia talia;
    int ilosc_pol_1_2_3_4_5_6_7 = 7;
    int ilosc_stosow = 4;

        void rysuj_plansze(){
            rysuj_pola_1_2_3_4_5_6_7();
            rysuj_pola_8_9_10_11();
            rysuj_pole0();
        };
    void rysuj_pola_1_2_3_4_5_6_7();
    void rysuj_pola_8_9_10_11();
    void rysuj_pole0();
    void rozdaj_karty_na_pola(){

    }
    void rozdaj_karty_na_pola_1_2_3_4_5_6_7(){
    for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++){

    }
    }

};





int main()
{

    Talia talia;
    Plansza plansza(talia);
     for(int i=0;i<52;i++){
        cout<< talia.karty.front().pokaz_figure()<<endl;
        talia.karty.pop();
    }


    return 0;
}
