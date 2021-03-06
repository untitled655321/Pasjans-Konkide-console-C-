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

void tasuj(vector<Karta>& vect, char num[], char gr[])
{
    int i, j, a, b, s;
    bool p;
    char x, y;
    Karta k(0, 0, "");
    string t, u, w;

    for (i=0; i<54; i++)
    {
        t.clear();
        p=true;
        while(p==true){
        a=rand()%12;
        b=rand()%4;
        cout << a << "     " << b << "     " << endl;
        t.push_back(num[a]);
        t.push_back(gr[b]);
        w="";
        w.push_back(*t.rbegin());
        t.pop_back();
        w.push_back(*t.rbegin());
        t.pop_back();
        k.ustaw_ozn(w);
        k.ustaw_figure(b);
        k.ustaw_wartosc (a);
        s=vect.size();
        p=false;
        for(j=0; j<s; j++)
        {
            vect[j].pokaz_ozn(&u);
            if(u==w)
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
    for (i=0; i<54; i++)
    {
        vect[i].pokaz_ozn(&u);
        cout << u << endl;
    }
    //cout << vect.size() << endl;
}

void zapisz(vector<Karta> vect, vector<Karta>& list, int &c)
{
    int a, i, p;
    Karta k(0, 0, "");
    string s;
    a=(rand()%8)+2;
    for(i=0; i<a; i++)
    {
        p = vect[i+c].pokaz_figure();
        k.ustaw_figure(p);
        vect[i+c].pokaz_ozn(&s);
        k.ustaw_ozn(s);
        p=vect[i+c].pokaz_wartosc();
        k.ustaw_wartosc(p);
        list.push_back(k);
    }
    c=c+a;
}

void rozdziel(vector<Karta> vect, queue<Karta>& kolejka, vector<Karta>& two, vector<Karta>& three, vector<Karta>& four, vector<Karta>& five, vector<Karta>& six, vector<Karta>& seven)
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
    cout << setw(9) << "0" << "                               " << setw(5) << "8" << setw(5) << "9" << setw(5) << "10" << setw(5) << "11" << endl;
    cout << "----------------------------------------------------------------" << endl;
    kolejka.front().pokaz_ozn(&s);
    cout << setw(9) << s << endl;
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
    cout << "|";
        for(i=0; i<7; i++)
    {
        cout << setw(5) << (i+1) << "   |";
    }
    cout << endl;
    for(i=0; i<(max+1); i++)
    {
        cout << "|";
        if(i<w[0])
        {
            cout << " ";
            one[i].pokaz_ozn(&s);
            cout << setw(5) <<  s;
            cout << "  ";
            cout << "|";
        }
        else
        {
            cout << "        |";
        }
        if(i<w[1])
        {
            cout << " ";
            two[i].pokaz_ozn(&s);
            cout << setw(5) << s;
            cout << "  ";
            cout << "|";
        }
        else
        {
            cout << "        |";
        }
        if(i<w[2])
        {
            cout << " ";
            three[i].pokaz_ozn(&s);
            cout << setw(5) << s;
            cout << "  ";
            cout << "|";
        }
        else
        {
            cout << "        |";
        }
        if(i<w[3])
        {
            cout << " ";
            four[i].pokaz_ozn(&s);
            cout << setw(5) << s;
            cout << "  ";
            cout << "|";
        }
        else
        {
            cout << "        |";
        }
        if(i<w[4])
        {
            cout << " ";
            five[i].pokaz_ozn(&s);
            cout << setw(5) << s;
            cout << "  ";
            cout << "|";
        }
        else
        {
            cout << "        |";
        }
        if(i<w[5])
        {
            cout << " ";
            six[i].pokaz_ozn(&s);
            cout << setw(5) << s;
            cout << "  ";
            cout << "|";
        }
        else
        {
            cout << "        |";
        }
        if(i<w[6])
        {
            cout << " ";
            seven[i].pokaz_ozn(&s);
            cout << setw(5) << s;
            cout << "  ";
            cout << "|";
        }
        else
        {
            cout << "        |";
        }
        cout << endl;
    }
}


int main()
{
    srand( time( NULL ) );

    queue <Karta> kolejka0;
    stack <Karta> stos811;
    //vector <stack <stos811> > wektor;                  //wektor 4 stos�w
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
    cout << tasowanie.size() << endl;
    rozdziel(tasowanie, kolejka0, two, three, four, five, six, seven);
    cout << one.size() << endl;
    wypisz(kolejka0, one, two, three, four, five, six, seven);  //w parametrach jeszcze wektor 4 soos�w

    //string test;
    //test.push_back(numery[2]);
    //test.push_back(numery[7]);

    //cout << test << endl;


    cout << endl;
    return 0;
}
