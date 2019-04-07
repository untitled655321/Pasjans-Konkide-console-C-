#include <iostream>
#include <iomanip>
#include <vector>

#include <queue>

#include <stack>
#include <ctime>
#include <cstdlib>

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
    Karta()
    {
        ukryta=true;
    }

    Karta(int f,int k){figura = f;kolor = k;ukryta=true;}

    int pokaz_figure(){if(ukryta==false)return figura; else return 0;}

    int pokaz_kolor(){if(ukryta==false)return kolor; else return 0;}

    bool czy_figura_ukryta(){return ukryta;};

    void odslon_karte(){ukryta=false;}

    bool przenies_karte(){if(ukryta==false)return true;}

private:

    bool ukryta;

    int kolor;

    int figura;

};



class Talia{

public:
    Talia(): ilosc_kolorow(4), rodzaje_kart(14), rozmiar_tali(52)
    {generuj_talie();
    tasuj();
    }

    queue<Karta> karty;
    int ilosc_kolorow;
    int rodzaje_kart;
    int rozmiar_tali;

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
    int l, i, n;
    l=56;         //pozniej zmienic na 52(po wywaleniu karty 10)
    Karta K[l];
    bool w[l];
    bool p;
    for (i=0; i<l; i++)
    {
        K[i]=karty.front();
        karty.pop();
    }
    for (i=0; i<l; i++)
    {
        w[i]=false;
    }
    for (i=0; i<l; i++)
    {
        p=false;
        while(p==false)
        {
            n=rand()%56;
            if(w[n]==false)
            {
                karty.push(K[n]);
                p=true;
            }
        }
    }
    }
};

class Plansza{

public:

    Plansza(Talia t): ilosc_pol_1_2_3_4_5_6_7(7), ilosc_stosow(4) {talia = t;}
    //dunkcje do rozk�adania kart dla nowej gry
        void rozdaj_karty_na_pola_1_2_3_4_5_6_7(){

                for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++){

                    for(int j=0;j<i;j++){
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

    //tutaj zaczynaj� sie funkcje rysuj�ce plansze




             void rysuj_pola_1_2_3_4_5_6_7(){
                 int max_size=0;
                 char numery[18] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', 'c', 's', 'd', 'h'};
            for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++)
                 {
                     if(pola_1_2_3_4_5_6_7[i].size()>max_size)
                     {
                        max_size=pola_1_2_3_4_5_6_7[i].size();
                     }
                 }
//                                                                    cout << pola_1_2_3_4_5_6_7[1][0].pokaz_figure() << "     ";
            for(int j=0;j<max_size;j++){
    //                cout<<i<<"||";
                            for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++){
                                if(j<pola_1_2_3_4_5_6_7[i].size()){
                                cout<< setw(5) << pola_1_2_3_4_5_6_7[i][j].pokaz_figure()  << pola_1_2_3_4_5_6_7[i][j].pokaz_kolor()  << " | ";
                                }
                                else
                                {
                                    cout << "       | ";
                                }
                            }
                            cout<<endl;
                        }
                        cout << setw(4) << "1" << setw(9) << "2" << setw(9) << "3" << setw(9) << "4" << setw(9) << "5" << setw(9) << "6" << setw(9) << "7" << endl;
                    };

                    void rysuj_pola_8_9_10_11(){
                    char numery[18] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', 'c', 's', 'd', 'h'};
                    cout << setw(9) << "0" << "                               " << setw(5) << "8" << setw(5) << "9" << setw(5) << "10" << setw(5) << "11" << endl;
                    cout << "----------------------------------------------------------------" << endl;
                    cout << setw(9) << pole0.front().pokaz_figure() << pole0.front().pokaz_kolor()  << "                            ";
                    if(pola_8_9_10_11[0].empty()==false)
                        {cout << setw(7) << numery[pola_8_9_10_11[0].top().pokaz_figure() - 1] << numery[pola_8_9_10_11[0].top().pokaz_kolor() - 1];}
                    else
                        {cout << "       ";}
                    if(pola_8_9_10_11[1].empty()==false)
                        {cout << setw(7) << numery[pola_8_9_10_11[1].top().pokaz_figure() - 1] << numery[pola_8_9_10_11[1].top().pokaz_kolor() - 1];}
                    else
                        {cout << "       ";}
                    if(pola_8_9_10_11[2].empty()==false)
                        {cout << setw(7) << numery[pola_8_9_10_11[2].top().pokaz_figure() - 1] << numery[pola_8_9_10_11[2].top().pokaz_kolor() - 1];}
                    else
                        {cout << "       ";}
                    if(pola_8_9_10_11[3].empty()==false)
                        {cout << setw(7) << numery[pola_8_9_10_11[3].top().pokaz_figure() - 1] << numery[pola_8_9_10_11[3].top().pokaz_kolor() - 1];}
                    else
                        {cout << "       ";}
                    cout << endl;
                    cout << "----------------------------------------------------------------" << endl;};

                  void rysuj_pole0(){
                  };

                             void rysuj_plansze(){
                    rysuj_pola_8_9_10_11();
                    rysuj_pola_1_2_3_4_5_6_7();
                    rysuj_pole0();
                };



                //odswieza plansze po kazdym wydanym poleceniu przez gracza

                void odswiez_plansze(){
                    odslon_na_wierzchu_pol_1_2_3_4_5_6_7();
                    odslon_na_wierzchu_pola0();
                    rysuj_plansze();
                }



                  //odslon karty na wierzchu

                void odslon_na_wierzchu_pol_1_2_3_4_5_6_7(){
                       for(int k=0;k<ilosc_pol_1_2_3_4_5_6_7;k++){
                                int sizee = pola_1_2_3_4_5_6_7[k].size()-1;
                                if(sizee>=0){pola_1_2_3_4_5_6_7[k].back().odslon_karte();}
                        }
                }

                 void odslon_na_wierzchu_pola0(){
                           pole0.front().odslon_karte();

                }


                //zwraca bool czy karta rzeczywiscie znajduje sie na polu z ktorego ma zostac przeniesiona



                int podaj_indeks_vectora(int numer_pola,int figura,int kolor){
                    int indeks = -1;
                    for(int i=0;i<pola_1_2_3_4_5_6_7[numer_pola].size();i++){

                            if((pola_1_2_3_4_5_6_7[numer_pola][i].pokaz_figure()==figura)&&(pola_1_2_3_4_5_6_7[numer_pola][i].pokaz_kolor()==kolor)&&(pola_1_2_3_4_5_6_7[numer_pola][i].czy_figura_ukryta()==false)){
                                indeks = i;
                            }
                    }
                    return indeks;
                }


                bool czy_ruch_dozwolony(int figura_do_przeniesienia,int kolor_do_przeniesiena,int figura_na_ktora_przeniesc,int kolor_na_ktory_przeniesc){
                    if((figura_do_przeniesienia+1==figura_na_ktora_przeniesc)&&(kolor_do_przeniesiena%2!=kolor_na_ktory_przeniesc%2)){
                        return true;
                    }
                    else{
                        return false;
                    }

                }


                void przemiesc_karte(int pole_z,int figura_do_przeniesienia,int kolor_do_przeniesiena,int pole_do){


                if(pole_z==0){
                        if((pole_do>=1)&&(pole_do<=7)){
                                pole_do = pole_do-1;
                                  if(pola_1_2_3_4_5_6_7[pole_do].empty()==true){
                            pola_1_2_3_4_5_6_7[pole_do].push_back(pole0.front());
                            pole0.pop();
                                }
                            else if(czy_ruch_dozwolony(pole0.front().pokaz_figure(),pole0.front().pokaz_kolor(),pola_1_2_3_4_5_6_7[pole_do].back().pokaz_figure(),pola_1_2_3_4_5_6_7[pole_do].back().pokaz_kolor())){
                            pola_1_2_3_4_5_6_7[pole_do].push_back(pole0.front());
                            pole0.pop();
                                }
                        }
                        else if((pole_do>=8)&&(pole_do<=11)){

                        }
                }
                else if((pole_z>=1)&&(pole_z<=7)){
                        //-1 poniewaz tablica vectorow rozpoczyna sie od "0"

                        if((pole_do>=1)&&(pole_do<=7)){
                        pole_z = pole_z-1;
                        pole_do = pole_do-1;
                       int indeks = podaj_indeks_vectora(pole_z,figura_do_przeniesienia,kolor_do_przeniesiena);

                if(pola_1_2_3_4_5_6_7[pole_do].empty()==true){

                      pola_1_2_3_4_5_6_7[pole_do].insert( pola_1_2_3_4_5_6_7[pole_do].end(), pola_1_2_3_4_5_6_7[pole_z].begin()+indeks, pola_1_2_3_4_5_6_7[pole_z].end() );

                      pola_1_2_3_4_5_6_7[pole_z].erase(pola_1_2_3_4_5_6_7[pole_z].begin()+indeks,pola_1_2_3_4_5_6_7[pole_z].end());

                }
                else if((czy_ruch_dozwolony(figura_do_przeniesienia,kolor_do_przeniesiena,pola_1_2_3_4_5_6_7[pole_do].back().pokaz_figure(),pola_1_2_3_4_5_6_7[pole_do].back().pokaz_kolor()))&&(indeks!=-1)){

                    pola_1_2_3_4_5_6_7[pole_do].insert( pola_1_2_3_4_5_6_7[pole_do].end(), pola_1_2_3_4_5_6_7[pole_z].begin()+indeks, pola_1_2_3_4_5_6_7[pole_z].end() );

                      pola_1_2_3_4_5_6_7[pole_z].erase(pola_1_2_3_4_5_6_7[pole_z].begin()+indeks,pola_1_2_3_4_5_6_7[pole_z].end());

                   }

                   else{
                    cout<<"Blad ruchu"<<endl;
                    if(czy_ruch_dozwolony(figura_do_przeniesienia,kolor_do_przeniesiena,pola_1_2_3_4_5_6_7[pole_do].back().pokaz_figure(),pola_1_2_3_4_5_6_7[pole_do].back().pokaz_kolor())==false){
                    cout<<"Nie mozna przeniesc karty o wyzszej wartosci na karte o wartosci nizszej, lub o nieodpowiednich kolorach";
                    cout<<endl;
                    }
                    if(indeks==-1){
                        cout<<"Karta ktora chcesz przeniesc nie istnieje na podanym polu nie istnieje";
                        cout<<endl;
                    }
                   }
                        }
                        else{
                                pole_z = pole_z-1;
                                pole_do = pole_do-8;
                        pola_8_9_10_11[pole_do].push( pola_1_2_3_4_5_6_7[pole_z].front());
                                pola_1_2_3_4_5_6_7[pole_z].pop_back();

                        }
                }

                else if((pole_z>=8)&&(pole_z<=11)){

                }
                }







private:

    Talia talia;
    int ilosc_pol_1_2_3_4_5_6_7;
    int ilosc_stosow;
    vector<Karta> pola_1_2_3_4_5_6_7 [7];
    stack<Karta> pola_8_9_10_11 [4];
    queue<Karta> pole0;
};

int main()

{
    srand( time( NULL ) );
    Talia talia;
    Plansza plansza(talia);
    plansza.rozdaj_karty_na_pola();


    plansza.odswiez_plansze();


    while(true){

    int pole_z;

    int figura_do_przeniesienia;
    int kolor_do_przeniesienia;


    int pole_do;

    cout<<"Podaj pole z ktorego przeniesc: ";
    cin>>pole_z;
    cout<<"Podaj figure ktora przeniesc: ";
    cin>>figura_do_przeniesienia;
    cout<<"Podaj kolor ktory przeniesc: ";
    cin>>kolor_do_przeniesienia;
    cout<<"Podaj pole na ktore przeniesc: ";
    cin>>pole_do;

    plansza.przemiesc_karte(pole_z,figura_do_przeniesienia,kolor_do_przeniesienia,pole_do);

    plansza.odswiez_plansze();

    }


 for(int i=0;i<56;i++){

        cout<< talia.karty.front().pokaz_figure()<< " "<< talia.karty.front().pokaz_kolor();

        cout<<endl;

        talia.karty.pop();

    }

    return 0;

}
