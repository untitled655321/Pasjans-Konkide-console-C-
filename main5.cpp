#include <iostream>

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

    Karta(int f,int k){figura = f;kolor = k;}

    int pokaz_figure(){if(ukryta==false)return figura;}

    int pokaz_kolor(){if(ukryta==false)return kolor;}

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
    //dunkcje do rozk³adania kart dla nowej gry
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

    //tutaj zaczynajš sie funkcje rysujšce plansze


             void rysuj_pola_1_2_3_4_5_6_7(){
            for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++){
                    cout<<i<<"||";
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


//             void rysuj_pola_1_2_3_4_5_6_7(){
  //               int max_size=0;
    //        for(int i=0;i<ilosc_pol_1_2_3_4_5_6_7;i++)
      //           {
        //             if(pola_1_2_3_4_5_6_7[i].size()>max_size)
          //           {
            //            max_size=pola_1_2_3_4_5_6_7[i].size();
              //       }
                // }
//                                                                    cout << pola_1_2_3_4_5_6_7[1][0].pokaz_figure() << "     ";
  //          for(int i=0;i<max_size;i++){
    //                cout<<i<<"||";
      //                      for(int j=0;j<ilosc_pol_1_2_3_4_5_6_7;j++){
        //                        cout << endl << i << "  " << j << endl;
          //                      cout<<pola_1_2_3_4_5_6_7[j][i].pokaz_figure()<<" "<<pola_1_2_3_4_5_6_7[j][i].pokaz_kolor()<<" | ";
            //                }
              //              cout<<endl;
                //        }
                  //  };

 //                   void rysuj_pola_8_9_10_11(){};
//
  //                void rysuj_pole0(){};
//
  //                           void rysuj_plansze(){
//
  //                  rysuj_pola_1_2_3_4_5_6_7();
    //                rysuj_pola_8_9_10_11();
      //              rysuj_pole0();
        //        };



                //odswieza plansze po kazdym wydanym poleceniu przez gracza

                void odswiez_plansze(){
                    odslon_na_wierzchu_pol_1_2_3_4_5_6_7();
                    rysuj_plansze();
                }



                  //odslon karty na wierzchu

                void odslon_na_wierzchu_pol_1_2_3_4_5_6_7(){
                       for(int k=0;k<ilosc_pol_1_2_3_4_5_6_7;k++){
                                int sizee = pola_1_2_3_4_5_6_7[k].size()-1;
                                if(sizee>=0){pola_1_2_3_4_5_6_7[k].back().odslon_karte();}
                        }
                }



                //zwraca bool czy karta rzeczywiscie znajduje sie na polu z ktorego ma zostac przeniesiona

                bool wyszukaj_karte(int figura,int kolor,int numer_pola){
                    bool znajduje_sie = false;

                if(numer_pola==0){
                    return znajduje_sie ;
                }

                else if((numer_pola>=1)&&(numer_pola<=7)){
                    return znajduje_sie;
                }

                else if((numer_pola>=8)&&(numer_pola<=11)){
                return znajduje_sie ;
                }
                }

                void sprawdz_poprawnosc_ruchu(){



                }

                void przemiesc_karte(int pole_z,int figura,int kolor,int pole_do){

                   // wyszukaj_karte(figura,kolor);

                   if(true){

                    //pola_1_2_3_4_5_6_7[pole_do].insert(pola_1_2_3_4_5_6_7[pole_do].back(),pola_1_2_3_4_5_6_7[pole_z][2],pola_1_2_3_4_5_6_7[pole_z][3]);

                    pola_1_2_3_4_5_6_7[pole_do].insert( pola_1_2_3_4_5_6_7[pole_do].end(), pola_1_2_3_4_5_6_7[pole_z].begin(), pola_1_2_3_4_5_6_7[pole_z].end() );

                      pola_1_2_3_4_5_6_7[pole_z].erase(pola_1_2_3_4_5_6_7[pole_z].begin(),pola_1_2_3_4_5_6_7[pole_z].end());

                   }

                   else{
                    cout<<"Podana karta nie istnieje na podanym Polu"<<endl;
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

    int pole_do;

    cin>>pole_z;

    cin>>pole_do;

    plansza.przemiesc_karte(pole_z,0,0,pole_do);

    plansza.odswiez_plansze();

    }

     for(int i=0;i<56;i++){

        cout<< talia.karty.front().pokaz_figure()<< " "<< talia.karty.front().pokaz_kolor();

        cout<<endl;

        talia.karty.pop();

    }


    return 0;

}
