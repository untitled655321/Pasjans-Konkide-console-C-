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
    int pokaz_figure(){if(ukryta==false)return figura;}
    int pokaz_kolor(){if(ukryta==false)return kolor;}
    void odslon_karte(){ukryta=false;}
private:
    bool ukryta=true;
    int kolor;
    int figura;
};

class Talia{
public:
    Talia(){generuj_talie();}
    queue<Karta> karty;
    int ilosc_kolorow = 4;
    int rodzaje_kart = 14;
    int rozmiar_tali = 52;
private:

    void generuj_talie(){
        for(int i=1;i<rodzaje_kart+1;i++){
            for(int j=0;j<ilosc_kolorow;j++){
                Karta *karta = new Karta(i,15+j);
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

    //dunkcje do rozk³adania kart dla nowej gry
        void rozdaj_karty_na_pola_1_2_3_4_5_6_7(){
                for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++){
                    for(int j=0;j<i;j++){
                            talia.karty.front().odslon_karte();
                        pola_1_2_3_4_5_6_7[i].push_back(talia.karty.front()) ;
                        talia.karty.pop();
                    }
                }
            }

            void rozdaj_karty_na_pole_0(){
                pole0 = talia.karty;
            };


            void rozdaj_karty_na_pola(){
rozdaj_karty_na_pola_1_2_3_4_5_6_7();
rozdaj_karty_na_pole_0();
    }


    //tutaj zaczynaj¹ sie funkcje rysuj¹ce plansze
             void rysuj_pola_1_2_3_4_5_6_7(){
            for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++){
                            for(int j=0;j<pola_1_2_3_4_5_6_7[i].size();j++){
                                cout<<pola_1_2_3_4_5_6_7[i][j].pokaz_figure()<<" "<<pola_1_2_3_4_5_6_7[i][j].pokaz_kolor()<<" | ";
                            }
                            cout<<endl;
                        }
                    };
                    void rysuj_pola_8_9_10_11(){};
                  void rysuj_pole0(){};

                             void rysuj_plansze(){
                    rysuj_pola_1_2_3_4_5_6_7();
                    rysuj_pola_8_9_10_11();
                    rysuj_pole0();
                };

private:
    Talia talia;
    int ilosc_pol_1_2_3_4_5_6_7 = 7;
    int ilosc_stosow = 4;
    vector<Karta> pola_1_2_3_4_5_6_7 [7];
    stack<Karta> pola_8_9_10_11 [4];
    queue<Karta> pole0;










};





int main()
{

    Talia talia;
    Plansza plansza(talia);
    plansza.rozdaj_karty_na_pola();
    plansza.rysuj_pola_1_2_3_4_5_6_7();
     for(int i=0;i<56;i++){
        cout<< talia.karty.front().pokaz_figure()<< " "<< talia.karty.front().pokaz_kolor();
        cout<<endl;
        talia.karty.pop();
    }


    return 0;
}
