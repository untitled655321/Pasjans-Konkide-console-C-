#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;

class Karta{
public:
    Karta(int f,int w, string o){wartosc = w;figura = f;ozn = o;}
    int pokaz_figure(){return figura;}
    int pokaz_wartosc(){return wartosc;}
    void pokaz_ozn(string *u){*u=ozn;}
    void ustaw_figure(int f){figura = f;}
    void ustaw_wartosc(int w){wartosc = w;}
    void ustaw_ozn(string o){ozn = o;}
private:
    string ozn;
    int wartosc;
    int figura;
};

void tasuj(vector<Karta> vect, char num[], char gr[])
{
    int i, j, a, b, s;
    bool p;
    char x, y;
    Karta k(0, 0, "");
    string t, u;
    for (i=0; i<54; i++)
    {
        p=true;
        while(p==true){
        a=rand()%13;
        b=rand()%4;
        t.push_back(num[a]);
        t.push_back(gr[b]);
        k.ustaw_ozn(t);
        k.ustaw_figure(b);
        k.ustaw_wartosc (a);
        s=vect.size();
        p=false;
        for(j=0; j<s; j++)
        {
            vect[j].pokaz_ozn(&u);
            if(u==t)
            {
                p=true;
            }
        }
        if(p==false)
        {
            vect.push_back(k);
        }
    }
    }
}
void zapisz(vector<Karta> vect, vector<Karta> list, int c)
{
    int a, i, p;
    Karta k(0, 0, "");
    string s;
    a=(rand()%8)+2;
    for(i=0; i<a; i++)
    {
        cout << "xxxxxxxx" << endl;
        p = vect[i+c].pokaz_figure();
        cout << "xxxxxxxx" << endl;
        k.ustaw_figure(p);
        vect[i+c].pokaz_ozn(&s);
        k.ustaw_ozn(s);
        p=vect[i+c].pokaz_wartosc();
        k.ustaw_wartosc(p);
        list.push_back(k);
    }
    c=c+a;
}

void rozdziel(vector<Karta> vect, queue<Karta> kolejka, vector<Karta> two, vector<Karta> three, vector<Karta> four, vector<Karta> five, vector<Karta> six, vector<Karta> seven)
{
    Karta kr(0, 0, "");
    string s;
    int c=0;
    int p;
    zapisz(vect, two, c);
    zapisz(vect, three, c);
    zapisz(vect, four, c);
    zapisz(vect, five, c);
    zapisz(vect, six, c);
    zapisz(vect, seven, c);
    for(int i=c; i<54; i++)
    {
        p=vect[i].pokaz_figure();
        kr.ustaw_figure(p);
        vect[i].pokaz_ozn(&s);
        kr.ustaw_ozn(s);
        p=vect[i].pokaz_wartosc();
        kr.ustaw_wartosc(p);
        kolejka.push(kr);
    }
}

void wypisz(queue<Karta> kolejka, vector<Karta> one, vector<Karta> two, vector<Karta> three, vector<Karta> four, vector<Karta> five, vector<Karta> six, vector<Karta> seven)
{
    string s;
    int i;
    int w[7];
    cout << setw(12) << "0" << "                               " << setw(5) << "8" << setw(5) << "9" << setw(5) << "10" << setw(5) << "11" << endl;
    cout << "----------------------------------------------------------------" << endl;
    kolejka.front().pokaz_ozn(&s);
    cout << setw(4) << s << endl;
    cout << "----------------------------------------------------------------" << endl;
    w[0]=one.size();
    w[1]=two.size();
    w[2]=three.size();
    w[3]=four.size();
    w[4]=five.size();
    w[5]=six.size();
    w[6]=seven.size();
    int max;
    max=0;
    for(i=0; i<7; i++)
    {
        if(w[i]>max){max=w[i];}
    }
    for(i=0; i<(max+1); i++)
    {
        cout << "|";
        if(i<w[0])
        {
            one[i].pokaz_ozn(&s);
            cout << setw(8) << s;
        }
        else
        {
            cout << "        ";
        }
        cout << "|";
        if(i<w[1])
        {
            two[i].pokaz_ozn(&s);
            cout << setw(8) << s;
        }
        else
        {
            cout << "        ";
        }
        cout << "|";
        if(i<w[2])
        {
            three[i].pokaz_ozn(&s);
            cout << setw(8) << s;
        }
        else
        {
            cout << "        ";
        }
        cout << "|";
        if(i<w[3])
        {
            four[i].pokaz_ozn(&s);
            cout << setw(8) << s;
        }
        else
        {
            cout << "        ";
        }
        cout << "|";
        if(i<w[4])
        {
            five[i].pokaz_ozn(&s);
            cout << setw(8) << s;
        }
        else
        {
            cout << "        ";
        }
        cout << "|";
        if(i<w[5])
        {
            six[i].pokaz_ozn(&s);
            cout << setw(8) << s;
        }
        else
        {
            cout << "        ";
        }
        cout << "|";
        if(i<w[6])
        {
            seven[i].pokaz_ozn(&s);
            cout << setw(8) << s;
        }
        else
        {
            cout << "        ";
        }
        cout << "|";
    }
    for(i=0; i<7; i++)
    {
        cout << setw(9) << (i+1);
    }
}


int main()
{
    srand( time( NULL ) );

    queue <Karta> kolejka0;
    stack <Karta> stos811;
    //vector <stack <stos811> > wektor;                  //wektor 4 stosów
    vector <Karta> one;
    vector <Karta> two;
    vector <Karta> three;
    vector <Karta> four;
    vector <Karta> five;
    vector <Karta> six;
    vector <Karta> seven;
    char numery[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    char group[4] = {'h', 's', 'd', 'c'};
    vector <Karta> tasowanie;

    tasuj(tasowanie, numery, group);
    rozdziel(tasowanie, kolejka0, two, three, four, five, six, seven);
    //wypisz(kolejka0, one, two, three, four, five, six, seven);  //w parametrach jeszcze wektor 4 soosów

    string test;
    test.push_back(numery[2]);
    test.push_back(numery[7]);

    cout << test << endl;


    cout << "Hello world!" << endl;
    return 0;
}
