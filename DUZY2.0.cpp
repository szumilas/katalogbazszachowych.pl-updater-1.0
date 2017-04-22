#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

string _ECO;
int _DEBIUT;


char s[9][9];
bool ruch;
int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8;
bool bicieCZARNE[9];
bool bicieBIALE[9];
bool roszK=1;
bool roszQ=1;
bool roszk=1;
bool roszq=1;

void wypisz();
void poczatek();
void pozycja(string fen);
void ruchpgn(string a);
string fen();

struct z
{
    int id;
    string nazw,im;
    
};

struct kod
{
    int p;
    string nr;
    string ruchy;
    string nazwa;
    string fen;
};

struct city{
    string name;
    double sz;
    double dl;
    int woj;
};

vector<kod>t;
vector<city>miasta;

void zwroc_eco(string a)
{
    if(a.size()<20)
    {_ECO=-1;_DEBIUT=-1;}
    else
    {
    string b;
    for(int q=0;q<a.size();q++)
    {
        if(a[q]=='{')
        {
            for(;a[q]!='}';q++)
            {}
            q++;
        }
        b.push_back(a[q]);
    }
    a=b;
    for(int q=0;q<a.size();q++)
    if(a[q]==13)a[q]=' ';
    poczatek();
    
    int priorytet=-1;
    int numer=-1;
        for(int w=0;w<a.size()-20&&w<250;w++)
        {
            string r;
            for(;(!(a[w]>='0'&&a[w]<='9'||a[w]>='a'&&a[w]<='z'||a[w]>='A'&&a[w]<='Z'||a[w]=='-'||a[w]=='.'))&&w<a.size()-20;w++)
            {
            }   
            if(a[w]>'0'&&a[w]<'9')
            {
                while(a[w]!='.')
                w++;
                w++;
                while(!(a[w]>='0'&&a[w]<='9'||a[w]>='a'&&a[w]<='z'||a[w]>='A'&&a[w]<='Z'||a[w]=='-'||a[w]=='.'))
                w++;
            }
            while((a[w]>='0'&&a[w]<='9'||a[w]>='a'&&a[w]<='z'||a[w]>='A'&&a[w]<='Z'||a[w]=='-'||a[w]=='.')&&w<a.size()-20)
            {
                r.push_back(a[w]);
                w++;
            }
            
            if(r[0]>='0'&&r[0]<='9'||r.size()<=1||w>=a.size()-20)
            {}
            else
            {
            if(!(r[0]=='a'||r[0]=='b'||r[0]=='c'||r[0]=='d'||r[0]=='e'||r[0]=='f'||r[0]=='g'||r[0]=='h'||r[0]=='K'||r[0]=='Q'||r[0]=='B'||r[0]=='R'||r[0]=='N'))
            break;
            //cout<<r<<endl;
            bool _NIE=0;
            for(int q=0;q<r.size();q++)
            if(r[q]=='-')
            {_NIE=1;break;}
            if(_NIE==1)
            break;
            ruchpgn(r);
            string tenfen=fen();
            //cout<<tenfen;getchar();
            for(int e=0;e<t.size();e++)
            {
                //cout<<t[e].fen<<"?"<<endl;
                if(t[e].fen==tenfen&&t[e].p>priorytet)
                {
                //cout<<"TAKKKK!"<<e<<endl;
                priorytet=t[e].p;
                numer=e;
                break;}
            }
            }
                
        }
    if(numer>=0)
    {_ECO=t[numer].nr;
    _DEBIUT=numer;}
    else
    {_ECO=-1;_DEBIUT=-1;}
    }
}


int main()
{
    //wczytanie zawodnikow
    vector<z>tidow;
    tidow.clear();
    
    fstream zaw;
    zaw.open("z-akt.txt");
    
    
    string a;
    
    while(getline(zaw,a))
    {
    string nazw;
    nazw.clear();
    string im;
    im.clear();
    int qq=0;
    int id=0;
    for(;a[qq]!='(';qq++)
    {}
    qq++;
    for(;a[qq]!=',';qq++)
    {id+=a[qq]-48;id*=10;}
    id/=10;
    //cout<<id;
    qq+=3;
    for(;a[qq+1]!=',';qq++)
    {nazw.push_back(a[qq]);}
    //cout<<nazw;
    qq+=4;
    for(;a[qq+1]!=',';qq++)
    {im.push_back(a[qq]);}
    //cout<<im;
    
    z nowy;
    nowy.im=im;
    nowy.id=id;
    nowy.nazw=nazw;
    
    tidow.push_back(nowy);
    a.clear();
    }
    
    zaw.close();
    
    //otwieranie plikow, implementacja zmiennych
    fstream _p,_t,_tout,_pout,kody,_miasta,aktualizacja;//_lout;
    _p.open("p2.0.txt");
    _t.open("t2.0.txt");
    _miasta.open("miasta.txt");
    aktualizacja.open("aktualizacja.txt",ios::out);
    kody.open("eco.txt");
    //- _lout.open("l.txt",ios::out|ios::app);
    
    
    fstream p10000;p10000.open("1010000",ios::out|ios::app);
    fstream p20000;p20000.open("1020000",ios::out|ios::app);
    fstream p30000;p30000.open("1030000",ios::out|ios::app);
    fstream p40000;p40000.open("1040000",ios::out|ios::app);
    fstream p50000;p50000.open("1050000",ios::out|ios::app);
    fstream p60000;p60000.open("1060000",ios::out|ios::app);
    fstream p70000;p70000.open("1070000",ios::out|ios::app);
    fstream p80000;p80000.open("1080000",ios::out|ios::app);
    fstream p90000;p90000.open("1090000",ios::out|ios::app);
    fstream p100000;p100000.open("1100000",ios::out|ios::app);
    
    fstream p110000;p110000.open("1110000",ios::out|ios::app);
    fstream p120000;p120000.open("1120000",ios::out|ios::app);
    fstream p130000;p130000.open("1130000",ios::out|ios::app);
    fstream p140000;p140000.open("1140000",ios::out|ios::app);
    fstream p150000;p150000.open("1150000",ios::out|ios::app);
    fstream p160000;p160000.open("1160000",ios::out|ios::app);
    fstream p170000;p170000.open("1170000",ios::out|ios::app);
    fstream p180000;p180000.open("1180000",ios::out|ios::app);
    fstream p190000;p190000.open("1190000",ios::out|ios::app);
    fstream p200000;p200000.open("1200000",ios::out|ios::app);
    
    fstream p210000;p210000.open("1210000",ios::out|ios::app);
    fstream p220000;p220000.open("1220000",ios::out|ios::app);
    fstream p230000;p230000.open("1230000",ios::out|ios::app);
    fstream p240000;p240000.open("1240000",ios::out|ios::app);
    fstream p250000;p250000.open("1250000",ios::out|ios::app);
    fstream p260000;p260000.open("1260000",ios::out|ios::app);
    fstream p270000;p270000.open("1270000",ios::out|ios::app);
    fstream p280000;p280000.open("1280000",ios::out|ios::app);
    fstream p290000;p290000.open("1290000",ios::out|ios::app);
    fstream p300000;p300000.open("1300000",ios::out|ios::app);
    
    
    
    a.clear();
    
    int id;
    
    //wczytywanie do tablicy kodow debiutowych
    while(!kody.eof())
    {
        kod nowy;
        getline(kody,nowy.nr);
        getline(kody,nowy.ruchy);
        getline(kody,nowy.nazwa);
        t.push_back(nowy);
    }
    for(int q=0;q<t.size();q++)
    {
        int ile=0;
        for(int w=0;w<t[q].ruchy.size();w++)
        if(t[q].ruchy[w]==' ')
        ile++;
        t[q].p=ile;
    }
    for(int q=0;q<t.size();q++)
    {
        poczatek();
        for(int w=0;w<t[q].ruchy.size();w++)
        {
            string r;
            for(;t[q].ruchy[w]==' '&&w<t[q].ruchy.size();w++)
            {
            }   
            if(t[q].ruchy[w]>'0'&&t[q].ruchy[w]<'9')
            {
                while(t[q].ruchy[w]!='.')
                w++;
                w++;
            }
            while(t[q].ruchy[w]!=' '&&w<t[q].ruchy.size())
            {
                r.push_back(t[q].ruchy[w]);
                w++;
            }
            ruchpgn(r);
        }
        t[q].fen=fen();
    }
    
    //wczyanie miast
    while(getline(_miasta,a))
    {
    int c=0;
    string _name,_sz,_dl,_woj;
    for(int q=0;q<a.size();q++)
    {
        if(a[q]=='|')
        {
            c=q+1;
            break;
        }
        _name.push_back(a[q]);
    }
    for(int q=c;q<a.size();q++)
    {
        if(a[q]=='|')
        {
            c=q+1;
            break;
        }
        _sz.push_back(a[q]);
    }
    for(int q=c;q<a.size();q++)
    {
        if(a[q]=='|')
        {
            c=q+1;
            break;
        }
        _dl.push_back(a[q]);
    }
    for(int q=c;q<a.size();q++)
    {
        if(a[q]=='|')
        {
            c=q+1;
            break;
        }
        _woj.push_back(a[q]);
    }
    
    double _nrdl,_nrsz;
    _nrsz=(_sz[0]-48)*10+(_sz[1]-48)+double(_sz[3]-48)/10+double(_sz[4]-48)/100+double(_sz[5]-48)/1000;
    _nrdl=(_dl[0]-48)*10+(_dl[1]-48)+double(_dl[3]-48)/10+double(_dl[4]-48)/100+double(_dl[5]-48)/1000;
    int _idwoj;
    if(_woj.size()==1)
    _idwoj=_woj[0]-48;
    else
    _idwoj=(_woj[0]-48)*10+_woj[1]-48;
    
    /* - 
    for(;;)
    {
        if(_woj[0]=='x'){_idwoj=0;break;}   //BRAK
        if(_woj[0]=='D'){_idwoj=1;break;}   //dolnoslaskie
        if(_woj[0]=='K'){_idwoj=2;break;}   //kujawsko-pomorskie
        if(_woj[0]=='L'&&_woj[1]=='u'&&_woj[2]=='b'&&_woj[3]=='e'){_idwoj=3;break;}   //lubelskie
        if(_woj[0]=='L'&&_woj[1]=='u'&&_woj[2]=='b'&&_woj[3]=='u'){_idwoj=4;break;}   //lubuskie
        if(_woj[0]=='L'&&_woj[1]=='o'){_idwoj=5;break;}   //lodzie
        if(_woj[0]=='M'&&_woj[1]=='a'&&_woj[2]=='l'){_idwoj=6;break;}   //malopolskie
        if(_woj[0]=='M'&&_woj[1]=='a'&&_woj[2]=='z'){_idwoj=7;break;}   //mazowieckie
        if(_woj[0]=='O'){_idwoj=8;break;}   //opolskie
        if(_woj[0]=='P'&&_woj[1]=='o'&&_woj[2]=='d'&&_woj[3]=='k'){_idwoj=9;break;}   //podkarpackie
        if(_woj[0]=='P'&&_woj[1]=='o'&&_woj[2]=='d'&&_woj[3]=='l'){_idwoj=10;break;}   //podlaskie
        if(_woj[0]=='P'&&_woj[1]=='o'&&_woj[2]=='m'&&_woj[3]=='o'){_idwoj=11;break;}   //pomorskie
        if(_woj[0]=='S'&&_woj[1]=='l'){_idwoj=12;break;}   //slaskie
        if(_woj[0]=='S'&&_woj[1]=='w'){_idwoj=13;break;}   //swietokrzyskie
        if(_woj[0]=='W'&&_woj[1]=='a'){_idwoj=14;break;}   //warminsko-mazurskie
        if(_woj[0]=='W'&&_woj[1]=='i'){_idwoj=15;break;}   //wielkopolskie
        if(_woj[0]=='Z'){_idwoj=16;break;}   //zachodniopomorskie
        break;
    }
    */
    city nowe;
    nowe.name=_name;
    nowe.dl=_nrdl;
    nowe.sz=_nrsz;
    nowe.woj=_idwoj;
    
    miasta.push_back(nowe);
    }
    
    /*for(int q=0;q<miasta.size();q++)
    cout<<q<<" "<<miasta[q].name<<" "<<miasta[q].dl<<endl;*/
    
    /*string partia="1. e4 c5 2. Nf3 Nc6 3. d4 cxd4 4.Nxd4 e5 5.Nb5 d6 6.N1c3 Nf6 7.Bg5 a6 8.Na3";
    zwroc_eco(partia);
    cout<<_ECO<<" "<<_DEBIUT<<endl;*/
    
    string linia,_ol;
    while(getline(_p,linia))
    {_ol=linia;}
    int idpartii=(_ol[26]-48)*1000000+(_ol[27]-48)*100000+(_ol[28]-48)*10000+(_ol[29]-48)*1000+(_ol[30]-48)*100+(_ol[31]-48)*10+(_ol[32]-48);
    //idpartii++;
    cout<<idpartii<<endl;
    _p.close();
    
    while(getline(_t,linia))
    {_ol=linia;}
    int idturnieju=(_ol[26]-48)*100000+(_ol[27]-48)*10000+(_ol[28]-48)*1000+(_ol[29]-48)*100+(_ol[30]-48)*10+(_ol[31]-48);
    idturnieju++;
    cout<<idturnieju<<endl;
    _t.close();
    
    _pout.open("p2.0.txt",ios::out|ios::app);
    _tout.open("t2.0.txt",ios::out|ios::app);
    while(cin)
    {
        string z,x,c,v,b;
        cout<<"sciezka pliku:"<<endl;
        getline(cin,z);
        
        fstream plik2;
        char nazwa[z.size()];
        for(int q=0;q<z.size();q++)
        nazwa[q]=z[q];
        nazwa[z.size()]=0;nazwa[z.size()+1]=0;
        
        plik2.open(nazwa);
        
        if(plik2)
        {
            int games=0;
            int size=0;
            
            int id=idturnieju;
            char base[8];
            base[0]=id/100000+48;
            base[1]=(id/10000)%10+48;
            base[2]=(id/1000)%10+48;
            base[3]=(id/100)%10+48;
            base[4]=(id/10)%10+48;
            base[5]=(id/1)%10+48;
            base[6]=0;
            base[7]=0;
            fstream baza;
            cout<<id<<endl;
            cout<<base<<endl;
            baza.open(base,ios::out);
            string a;
            string bialy,czarny;
            int wynik=5;
            string calapartia;
            string bn,bi;
            string cn,ci;
            while(getline(plik2,a))
            {
                if(a[0]=='['&&a[1]=='W'&&a[2]=='h'&&a[3]=='i'&&a[4]=='t'&&a[5]=='e'&&a[6]==' ')
                {games++;/*zwroc_eco(calapartia);*/
                
                if(games>1)
                {
                idpartii++;    
                zwroc_eco(calapartia);
                
                //tutaj mieszam!!
                
                int idb=0,idc=0;
                
                for(int q=0;q<tidow.size();q++)
                {
                    if(bn==tidow[q].nazw&&bi==tidow[q].im)
                    {idb=tidow[q].id;break;}
                }
                
                
                for(int q=0;q<tidow.size();q++)
                {
                    if(cn==tidow[q].nazw&&ci==tidow[q].im)
                    {idc=tidow[q].id;break;}
                }
                
                
                
                
                
                
                
                //=======
                
                
                
                
                
                _pout<<"INSERT INTO `p2.0` VALUES("<<idpartii<<", "<<idturnieju<<", "<<idb<<", "<<idc<<", '"<<bn<<"', '"<<bi<<"', '"<<cn<<"', '"<<ci<<"', "<<wynik<<", '"<<_ECO<<"', '"<<_DEBIUT<<"');"<<endl;
                aktualizacja<<"INSERT INTO `p2.0` VALUES("<<idpartii<<", "<<idturnieju<<", "<<idb<<", "<<idc<<", '"<<bn<<"', '"<<bi<<"', '"<<cn<<"', '"<<ci<<"', "<<wynik<<", '"<<_ECO<<"', '"<<_DEBIUT<<"');"<<endl;
                
                
                //INSERT INTO `b` VALUES(1160001, '  1.c4 Nf6 2.Nc3 e6 3.g3 d5 4.Bg2 Be7 5.d4 O-O 6.Nf3 dxc4 7.Ne5 c5 8.d5 exd5 9.Nxd5 Nxd5 10.Qxd5 Qxd5 11.Bxd5 c3 12.bxc3 Bf6 13.f4 Nd7 14.Nxd7 Bxc3+  15.Kf2 Bxd7 16.Rb1 Rab8 17.Rxb7 Rxb7 18.Bxb7 Be6 19.Be3 Rb8 20.Rd1 Bb4 21. Bc6 Bxa2 22.Ra1 Be6 23.Rxa7 c4 24.Rb7 Rxb7 25.Bxb7 f5 26.Bc1 Bc5+ 27.Be3  Bb4 28.Bc1 Kf7 29.e4 fxe4 30.Bxe4 g6 31.Kf3 h5 32.Bc6 Ke7 33.Ke4 Bc5 34. Bd5 Bf5+ 35.Ke5 Bg1 36.Ba3+ Kd7 37.h3 c3 38.Be4 Bxe4 39.Kxe4 Ke6 40.g4  hxg4 41.hxg4 c2 42.Bb2 Bf2 43.f5+ gxf5+ 44.gxf5+ Kf7 45.Kd3 Bh4 1/2-1/2 ');
                
                aktualizacja<<"INSERT INTO `b` VALUES("<<idpartii<<", '"<<calapartia<<"');"<<endl;
                
                for(;;)
                {
                    if(idpartii<=1010000){p10000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1020000){p20000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1030000){p30000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1040000){p40000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1050000){p50000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1060000){p60000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1070000){p70000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1080000){p80000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1090000){p90000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1100000){p100000<<idpartii<<" "<<calapartia<<endl;break;}
                    
                    if(idpartii<=1110000){p110000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1120000){p120000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1130000){p130000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1140000){p140000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1150000){p150000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1160000){p160000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1170000){p170000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1180000){p180000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1190000){p190000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1200000){p200000<<idpartii<<" "<<calapartia<<endl;break;}
                    
                    if(idpartii<=1210000){p210000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1220000){p220000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1230000){p230000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1240000){p240000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1250000){p250000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1260000){p260000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1270000){p270000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1280000){p280000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1290000){p290000<<idpartii<<" "<<calapartia<<endl;break;}
                    if(idpartii<=1300000){p300000<<idpartii<<" "<<calapartia<<endl;break;}
                    break;
                }
                }
                calapartia.clear();
                }
                size+=a.size()+1;
                
                if(a[0]=='[')
                {
                    for(;;)
                    {
                        if(a[1]=='W'&&a[2]=='h'&&a[3]=='i'&&a[4]=='t'&&a[5]=='e'&&a[6]==' ')
                        {
                            bialy.clear();
                            int zm=7;
                            for(;a[zm]!='"';zm++){}
                            zm++;
                            for(;a[zm]!='"';zm++)
                            {
                                bialy.push_back(a[zm]);
                            }
                            //cout<<bialy<<endl;getchar();
                            break;
                        }
                        if(a[1]=='B'&&a[2]=='l'&&a[3]=='a'&&a[4]=='c'&&a[5]=='k'&&a[6]==' ')
                        {
                            czarny.clear();
                            int zm=7;
                            for(;a[zm]!='"';zm++){}
                            zm++;
                            for(;a[zm]!='"';zm++)
                            {
                                czarny.push_back(a[zm]);
                            }
                            //cout<<czarny<<endl;getchar();
                            break;
                        }
                        if(a[1]=='R'&&a[2]=='e'&&a[3]=='s'&&a[4]=='u'&&a[5]=='l'&&a[6]=='t'&&a[7]==' ')
                        {
                            int zm=7;
                            for(;a[zm]!='"';zm++){}
                            zm++;
                            for(;;)
                            {
                                if(a[zm]=='1'&&a[zm+1]=='-'){wynik=1;break;}
                                if(a[zm]=='1'){wynik=2;break;}
                                if(a[zm]=='0'){wynik=0;break;}
                                wynik=3;
                                break;
                            }
                            //cout<<wynik<<endl;getchar();
                            break;
                        }
                        break;
                    }
                }
                else
                {
                    calapartia+=" "+a;
                    //fstream partia;
                    if(bialy.size()!=0&&czarny.size()!=0)
                    {
                      
                    
                    //cout<<bialy<<" - "<<czarny<<" ["<<wynik<<"]"<<endl;
                    
                    bn.clear();
                    bi.clear();
                    
                    int zm=0;
                    if(bialy[1]==' '||bialy[2]==' '||bialy[3]==' ')
                    {
                        if((bialy[0]=='I'&&bialy[1]=='I')||(bialy[1]=='+'||bialy[2]=='+')||bialy[1]==' '||(bialy[0]=='W'&&bialy[1]=='G'&&bialy[2]=='M')||
                        (bialy[0]=='W'&&bialy[1]=='I'&&bialy[2]=='M')||(bialy[0]=='W'&&bialy[1]=='F'&&bialy[2]=='M')||(bialy[0]=='G'&&bialy[1]=='M'&&bialy[2]==' ')||
                        (bialy[0]=='I'&&bialy[1]=='M'&&bialy[2]==' ')||(bialy[0]=='F'&&bialy[1]=='M'&&bialy[2]==' ')||(bialy[0]=='W'&&bialy[1]=='C'&&bialy[2]=='M')||
                        (bialy[0]=='C'&&bialy[1]=='M'&&bialy[2]==' '))
                        {
                            for(;bialy[zm]!=' '&&zm<bialy.size();zm++){}
                            zm++;
                        }
                    }
                    bn.push_back(bialy[zm]);
                    zm++;
                    bool duza=0;
                    for(;bialy[zm]!=' '&&zm<bialy.size();zm++)
                    {
                        if(bialy[zm]>='A'&&bialy[zm]<='Z')
                        bialy[zm]+=32;
                        if(duza==1&&bialy[zm]>='a'&&bialy[zm]<='z')
                        bialy[zm]-=32;
                        for(;;)
                        {
                            if(bialy[zm]=='¹'){bialy[zm]='a';break;}
                            if(bialy[zm]=='æ'){bialy[zm]='c';break;}
                            if(bialy[zm]=='ê'){bialy[zm]='e';break;}
                            if(bialy[zm]=='³'){bialy[zm]='l';break;}
                            if(bialy[zm]=='ñ'){bialy[zm]='n';break;}
                            if(bialy[zm]=='ó'){bialy[zm]='o';break;}
                            if(bialy[zm]=='œ'){bialy[zm]='s';break;}
                            if(bialy[zm]=='Ÿ'){bialy[zm]='z';break;}
                            if(bialy[zm]=='¿'){bialy[zm]='z';break;}
                            
                            if(bialy[zm]=='¥'){bialy[zm]='A';break;}
                            if(bialy[zm]=='Æ'){bialy[zm]='C';break;}
                            if(bialy[zm]=='Ê'){bialy[zm]='E';break;}
                            if(bialy[zm]=='£'){bialy[zm]='L';break;}
                            if(bialy[zm]=='Ñ'){bialy[zm]='N';break;}
                            if(bialy[zm]=='Ó'){bialy[zm]='O';break;}
                            if(bialy[zm]=='Œ'){bialy[zm]='S';break;}
                            if(bialy[zm]==''){bialy[zm]='Z';break;}
                            if(bialy[zm]=='¯'){bialy[zm]='Z';break;}
                            break;
                        }
                        if(bialy[zm]=='-')
                        duza=1;
                        else
                        duza=0;
                        if(bialy[zm]!=',')
                        bn.push_back(bialy[zm]);
                    }
                    zm++;
                    
                    for(;((bialy[zm]>='a'&&bialy[zm]<='z')||(bialy[zm]>='A'&&bialy[zm]<='Z')||bialy[zm]=='-')&&zm<bialy.size();zm++)
                    {
                        bi.push_back(bialy[zm]);
                    }
                    //========czarny
                    
                    cn.clear();
                    ci.clear();
                    
                    zm=0;
                    if(czarny[1]==' '||czarny[2]==' '||czarny[3]==' ')
                    {
                        if((czarny[0]=='I'&&czarny[1]=='I')||(czarny[1]=='+'||czarny[2]=='+')||czarny[1]==' '||(czarny[0]=='W'&&czarny[1]=='G'&&czarny[2]=='M')||
                        (czarny[0]=='W'&&czarny[1]=='I'&&czarny[2]=='M')||(czarny[0]=='W'&&czarny[1]=='F'&&czarny[2]=='M')||(czarny[0]=='G'&&czarny[1]=='M'&&czarny[2]==' ')||
                        (czarny[0]=='I'&&czarny[1]=='M'&&czarny[2]==' ')||(czarny[0]=='F'&&czarny[1]=='M'&&czarny[2]==' ')||(czarny[0]=='W'&&czarny[1]=='C'&&czarny[2]=='M')||
                        (czarny[0]=='C'&&czarny[1]=='M'&&czarny[2]==' '))
                        {
                            for(;czarny[zm]!=' '&&zm<czarny.size();zm++){}
                            zm++;
                        }
                    }
                    cn.push_back(czarny[zm]);
                    zm++;
                    duza=0;
                    for(;czarny[zm]!=' '&&zm<czarny.size();zm++)
                    {
                        if(czarny[zm]>='A'&&czarny[zm]<='Z')
                        czarny[zm]+=32;
                        if(duza==1&&czarny[zm]>='a'&&czarny[zm]<='z')
                        czarny[zm]-=32;
                        for(;;)
                        {
                            if(czarny[zm]=='¹'){czarny[zm]='a';break;}
                            if(czarny[zm]=='æ'){czarny[zm]='c';break;}
                            if(czarny[zm]=='ê'){czarny[zm]='e';break;}
                            if(czarny[zm]=='³'){czarny[zm]='l';break;}
                            if(czarny[zm]=='ñ'){czarny[zm]='n';break;}
                            if(czarny[zm]=='ó'){czarny[zm]='o';break;}
                            if(czarny[zm]=='œ'){czarny[zm]='s';break;}
                            if(czarny[zm]=='Ÿ'){czarny[zm]='z';break;}
                            if(czarny[zm]=='¿'){czarny[zm]='z';break;}
                            
                            if(czarny[zm]=='¥'){czarny[zm]='A';break;}
                            if(czarny[zm]=='Æ'){czarny[zm]='C';break;}
                            if(czarny[zm]=='Ê'){czarny[zm]='E';break;}
                            if(czarny[zm]=='£'){czarny[zm]='L';break;}
                            if(czarny[zm]=='Ñ'){czarny[zm]='N';break;}
                            if(czarny[zm]=='Ó'){czarny[zm]='O';break;}
                            if(czarny[zm]=='Œ'){czarny[zm]='S';break;}
                            if(czarny[zm]==''){czarny[zm]='Z';break;}
                            if(czarny[zm]=='¯'){czarny[zm]='Z';break;}
                            break;
                        }
        
                        if(czarny[zm]=='-')
                        duza=1;
                        else
                        duza=0;
                        if(czarny[zm]!=',')
                        cn.push_back(czarny[zm]);
                    }
                    zm++;
                    
                    for(;((czarny[zm]>='a'&&czarny[zm]<='z')||(czarny[zm]>='A'&&czarny[zm]<='Z')||czarny[zm]=='-')&&zm<czarny.size();zm++)
                    {
                        ci.push_back(czarny[zm]);
                    }
        
                    
                    
                    
                    //INSERT INTO `p` VALUES(100001, 20070826, 20070830, 'Janow Lubelski', 'Janow Lubelski', 10084, 187, 106);
                    //plik<<"INSERT INTO `p` VALUES("<<idpartii<<", "<<idturnieju<<", '"<<bn<<"', '"<<bi<<"', '"<<cn<<"', '"<<ci<<"', "<<wynik<<");"<<endl;
                    //cout<<bn<<", "<<bi<<" - "<<cn<<", "<<ci<<" ["<<wynik<<"]"<<endl;
                    
                    
                    
                    
                    }
                    //cout<<endl<<calapartia<<endl;
                    
                    
                    
                    
                    
                    /*
                    while(getline(we,a))
                    {
                        if(a[0]=='[')
                        break;
                        if(bialy.size()!=0&&czarny.size()!=0)
                        {
                            for(;;)
                            {
                            if(idpartii<=1010000){p10000<<a<<" ";break;}
                            if(idpartii<=1020000){p20000<<a<<" ";break;}
                            if(idpartii<=1030000){p30000<<a<<" ";break;}
                            if(idpartii<=1040000){p40000<<a<<" ";break;}
                            if(idpartii<=1050000){p50000<<a<<" ";break;}
                            if(idpartii<=1060000){p60000<<a<<" ";break;}
                            if(idpartii<=1070000){p70000<<a<<" ";break;}
                            if(idpartii<=1080000){p80000<<a<<" ";break;}
                            if(idpartii<=1090000){p90000<<a<<" ";break;}
                            if(idpartii<=1100000){p100000<<a<<" ";break;}
                            break;
                            }
                        }
                    }*/
                    /*
                    for(;;)
                    {
                    if(idpartii<=1010000){p10000<<endl;break;}
                    if(idpartii<=1020000){p20000<<endl;break;}
                    if(idpartii<=1030000){p30000<<endl;break;}
                    if(idpartii<=1040000){p40000<<endl;break;}
                    if(idpartii<=1050000){p50000<<endl;break;}
                    if(idpartii<=1060000){p60000<<endl;break;}
                    if(idpartii<=1070000){p70000<<endl;break;}
                    if(idpartii<=1080000){p80000<<endl;break;}
                    if(idpartii<=1090000){p90000<<endl;break;}
                    if(idpartii<=1100000){p100000<<endl;break;}
                    break;
                    }*/
                    //plik<<"');"<<endl;
                    //getchar();
                    
                    if(bialy.size()!=0&&czarny.size()!=0)
                    {/*idpartii++;*/}
        
                    /*bialy.clear();
                    czarny.clear();*/
                    
                    //partia.close();
                    
                    
                    
                    
                    
                    
                }
                baza<<a<<endl;
                
                //cout<<a<<endl;
            }
            idpartii++;    
            zwroc_eco(calapartia);
            //tutaj mieszam!!
                
                int idb=0,idc=0;
                
                for(int q=0;q<tidow.size();q++)
                {
                    if(bn==tidow[q].nazw&&bi==tidow[q].im)
                    {idb=tidow[q].id;break;}
                }
                
                
                for(int q=0;q<tidow.size();q++)
                {
                    if(cn==tidow[q].nazw&&ci==tidow[q].im)
                    {idc=tidow[q].id;break;}
                }
                
                
                
                
                
                
                
                //=======
                
                
                
                
                
                _pout<<"INSERT INTO `p2.0` VALUES("<<idpartii<<", "<<idturnieju<<", "<<idb<<", "<<idc<<", '"<<bn<<"', '"<<bi<<"', '"<<cn<<"', '"<<ci<<"', "<<wynik<<", '"<<_ECO<<"', '"<<_DEBIUT<<"');"<<endl;
                aktualizacja<<"INSERT INTO `p2.0` VALUES("<<idpartii<<", "<<idturnieju<<", "<<idb<<", "<<idc<<", '"<<bn<<"', '"<<bi<<"', '"<<cn<<"', '"<<ci<<"', "<<wynik<<", '"<<_ECO<<"', '"<<_DEBIUT<<"');"<<endl;
                
                
                //INSERT INTO `b` VALUES(1160001, '  1.c4 Nf6 2.Nc3 e6 3.g3 d5 4.Bg2 Be7 5.d4 O-O 6.Nf3 dxc4 7.Ne5 c5 8.d5 exd5 9.Nxd5 Nxd5 10.Qxd5 Qxd5 11.Bxd5 c3 12.bxc3 Bf6 13.f4 Nd7 14.Nxd7 Bxc3+  15.Kf2 Bxd7 16.Rb1 Rab8 17.Rxb7 Rxb7 18.Bxb7 Be6 19.Be3 Rb8 20.Rd1 Bb4 21. Bc6 Bxa2 22.Ra1 Be6 23.Rxa7 c4 24.Rb7 Rxb7 25.Bxb7 f5 26.Bc1 Bc5+ 27.Be3  Bb4 28.Bc1 Kf7 29.e4 fxe4 30.Bxe4 g6 31.Kf3 h5 32.Bc6 Ke7 33.Ke4 Bc5 34. Bd5 Bf5+ 35.Ke5 Bg1 36.Ba3+ Kd7 37.h3 c3 38.Be4 Bxe4 39.Kxe4 Ke6 40.g4  hxg4 41.hxg4 c2 42.Bb2 Bf2 43.f5+ gxf5+ 44.gxf5+ Kf7 45.Kd3 Bh4 1/2-1/2 ');
                
                aktualizacja<<"INSERT INTO `b` VALUES("<<idpartii<<", '"<<calapartia<<"');"<<endl;
                for(;;)
            {
                if(idpartii<=1010000){p10000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1020000){p20000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1030000){p30000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1040000){p40000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1050000){p50000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1060000){p60000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1070000){p70000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1080000){p80000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1090000){p90000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1100000){p100000<<idpartii<<" "<<calapartia<<endl;break;}
                
                if(idpartii<=1110000){p110000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1120000){p120000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1130000){p130000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1140000){p140000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1150000){p150000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1160000){p160000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1170000){p170000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1180000){p180000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1190000){p190000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1200000){p200000<<idpartii<<" "<<calapartia<<endl;break;}
                
                if(idpartii<=1210000){p210000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1220000){p220000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1230000){p230000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1240000){p240000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1250000){p250000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1260000){p260000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1270000){p270000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1280000){p280000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1290000){p290000<<idpartii<<" "<<calapartia<<endl;break;}
                if(idpartii<=1300000){p300000<<idpartii<<" "<<calapartia<<endl;break;}
                break;
            }
            calapartia.clear();
                
                
                
                
                
                
                
                
                
                
                
                
            
            size/=1000;
            baza.close();
            cout<<endl<<games<<" "<<size<<endl;
        
            
            cout<<"nazwa turnieju:"<<endl;
            getline(cin,x);
            cout<<"poczatek:"<<endl;
            getline(cin,c);
            cout<<"koniec:"<<endl;
            getline(cin,v);
            cout<<"miasto:"<<endl;
            getline(cin,b);
            string link;
            cout<<"serwis turniejowy:"<<endl;
            getline(cin,link);
            string typ;
            cout<<"typ:"<<endl;
            getline(cin,typ);
            
            if(link[0]=='0')
            link.clear();
            
            
            
            //==========================
            bool tak=0;
    
            for(int q=0;q<miasta.size();q++)
            {
                bool nie=0;
                for(int w=0;w<b.size();w++)
                {
                    if(miasta[q].name[w]==b[w])
                    {}
                    else
                    {
                        nie=1;
                        break;
                    }
                }
                if(nie==0&&miasta[q].name.size()==b.size())
                {
                    tak=1;
                    //INSERT INTO `t` VALUES(100002, 20070829, 20070902, 'Obra lato open 2008', 'Obra', 10085, 45, 33);
                    _tout<<"INSERT INTO `t2.0` VALUES("<<id<<", "<<c<<", "<<v<<", '"<<x<<"', '"<<link<<"', "<<q+1<<", "<<games<<", "<<size<<", "<<typ<<");"<<endl;
                    aktualizacja<<"INSERT INTO `t2.0` VALUES("<<id<<", "<<c<<", "<<v<<", '"<<x<<"', '"<<link<<"', "<<q+1<<", "<<games<<", "<<size<<", "<<typ<<");"<<endl;
    
                    //ile++;
                    break;
                } 
                
            }
            
            if(tak==0)cout<<b<<endl;
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            //_tout<<"INSERT INTO `turnieje` VALUES("<<id<<", "<<c<<", "<<v<<", '"<<x<<"', '"<<b<<"', 0, "<<games<<", "<<size<<");"<<endl;
            cout<<endl<<"============================================="<<endl;
            idturnieju++;
        }
        else
        {
            cout<<"zla sciezka";
            break;
        }
    }
    
    
    
    
    
    
    t.clear();
    
    _p.close();
    _tout.close();
    _miasta.close();
    _pout.close();
    kody.close();
    aktualizacja.close();
    //_lout.close();
    
    
    p10000.close();
    p20000.close();
    p30000.close();
    p40000.close();
    p50000.close();
    p60000.close();
    p70000.close();
    p80000.close();
    p90000.close();
    p100000.close();
    
    p110000.close();
    p120000.close();
    p130000.close();
    p140000.close();
    p150000.close();
    p160000.close();
    p170000.close();
    p180000.close();
    p190000.close();
    p200000.close();
    
    p210000.close();
    p220000.close();
    p230000.close();
    p240000.close();
    p250000.close();
    p260000.close();
    p270000.close();
    p280000.close();
    p290000.close();
    p300000.close();



    cin.ignore();
    getchar();
    return 0;
}
void poczatek()
{
    pozycja("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w");
    for(int q=1;q<=8;q++)
    {
        bicieBIALE[q]=0;
        bicieCZARNE[q]=0; 
    }
    roszK=1;
    roszQ=1;
    roszk=1;
    roszq=1;
        
}
string fen()
{
    string fen;
    fen.clear();
    for(int q=8;q>=1;q--)
    {
    for(int w=1;w<=8;w++)
    {
        if(s[w][q]!=0)
        fen.push_back(s[w][q]);
        else
        {
            int licznik=0;
            for(int ww=w;ww<=8&&s[ww][q]==0;ww++)
            {
                licznik++;
                w++;
            }
            fen.push_back(licznik+48);
            w--;
        }
    }
    if(q!=1)
    fen.push_back('/');
    }
    fen.push_back(' ');
    if(ruch==1)
    fen.push_back('b');
    else
    fen.push_back('w');
    
    fen.push_back(' ');
    if(roszK==0&&roszQ==0&&roszk==0&&roszq==0)
    fen.push_back('-');
    else
    {
        if(roszK==1)fen.push_back('K');
        if(roszQ==1)fen.push_back('Q');
        if(roszk==1)fen.push_back('k');
        if(roszq==1)fen.push_back('q');
    }
    fen.push_back(' ');
    if(ruch==1)
    {
        for(int q=1;q<=8;q++)
        {
            if(bicieBIALE[q]==1)
            {
                char z;
                if(q==1) z='a'; else if(q==2) z='b'; else if(q==3) z='c'; else if(q==4) z='d'; else if(q==5) z='e'; else if(q==6) z='f'; else if(q==7) z='g'; else if(q==8) z='h';
                fen.push_back(z);fen.push_back('3');
                break;
            }
            if(q==8)
            {
                fen.push_back('-');
            }
        }
    }
    else
    {
        for(int q=1;q<=8;q++)
        {
            if(bicieCZARNE[q]==1)
            {
                char z;
                if(q==1) z='a'; else if(q==2) z='b'; else if(q==3) z='c'; else if(q==4) z='d'; else if(q==5) z='e'; else if(q==6) z='f'; else if(q==7) z='g'; else if(q==8) z='h';
                fen.push_back(z);fen.push_back('6');
                break;
            }
            if(q==8)
            {
                fen.push_back('-');
            }
        }
    }
    fen.push_back(' ');fen.push_back('0');fen.push_back(' ');fen.push_back('1');
    return fen;
}
void pozycja (string fen)
{
    for(int q=1;q<=8;q++)
    for(int w=1;w<=8;w++)
    s[q][w]=0;
    int kol=1;
    int wiersz=8;
    int q=0;
    for(;fen[q]!=' '&&q<fen.size();q++)
    {
        if(fen[q]=='/')
        {
            kol=1;
            wiersz--;
        }
        if(fen[q]>='A'&&fen[q]<='Z'||fen[q]>='a'&&fen[q]<='z')
        {
            s[kol][wiersz]=fen[q];
            kol++;
        }
        if(fen[q]>='1'&&fen[q]<='8')
        {
            kol+=fen[q]-48;
        }
    }
    if(fen[q+1]=='b')
    ruch=1;
    else
    ruch=0;
       
    
    
    
}
void ruchpgn(string a)
{
    string b;
    bool bicie=0;
    b.clear();
    
    for(int q=0;q<a.size();q++)
    if(a[q]>='a'&&a[q]<='h'||a[q]>='A'&&a[q]<='Z'||a[q]>='1'&&a[q]<='8'||a[q]=='-')
    b.push_back(a[q]);
    else if(a[q]=='x')
    bicie=1;
    
    a.clear();
    a=b;
    //===============================================
    //pion
    //===============================================
    //pojedynczy ruch
    if(a[0]>='a'&&a[0]<='h'&&a[1]>='1'&&a[1]<='8')
    {
        if(ruch==0)
        {
            
            s[a[0]-'a'+1][a[1]-48]='P';
            if(s[a[0]-'a'+1][a[1]-48-1]=='P')
            s[a[0]-'a'+1][a[1]-48-1]=0;
            else if(s[a[0]-'a'+1][a[1]-48-2]=='P')
            {
                s[a[0]-'a'+1][a[1]-48-2]=0;
                bicieBIALE[a[0]-'a'+1]=1;
            }
        }
        else
        {
            s[a[0]-'a'+1][a[1]-48]='p';
            if(s[a[0]-'a'+1][a[1]-48+1]=='p')
            s[a[0]-'a'+1][a[1]-48+1]=0;
            else if(s[a[0]-'a'+1][a[1]-48+2]=='p')
            {
                s[a[0]-'a'+1][a[1]-48+2]=0;
                bicieCZARNE[a[0]-'a'+1]=1;
            }
        }
    }
    //bicie
    if(a[0]>='a'&&a[0]<='h'&&bicie==1)
    {
        if(ruch==0)
        {
            s[a[1]-'a'+1][a[2]-48]='P';
            s[a[0]-'a'+1][a[2]-48-1]=0;
            if(a[2]-48==6&&bicieCZARNE[a[1]-'a'+1]==1)
            {
                s[a[1]-'a'+1][a[2]-48-1]=0;
                bicieCZARNE[a[1]-'a'+1]=0;
            }
        }
        else
        {
            s[a[1]-'a'+1][a[2]-48]='p';
            s[a[0]-'a'+1][a[2]-48+1]=0;
            if(a[2]-48==3&&bicieBIALE[a[1]-'a'+1]==1)
            {
                s[a[1]-'a'+1][a[2]-48+1]=0;
                bicieBIALE[a[1]-'a'+1]=0;
            }
        }
    }
    //dorabianie
    if(a[a.size()-1]>='A'&&a[a.size()-1]<='Z'&&a[a.size()-1]!='O')
    {
        char dorobienie=a[a.size()-1];
        if(ruch==1)
        dorobienie+=32;
        s[a[a.size()-3]-'a'+1][a[a.size()-2]-48]=dorobienie;
    }
    //===============================================
    //wieza
    //===============================================
    //zwykly ruch Ra2
    if(a[0]=='R'&&a[1]>='a'&&a[1]<='h'&&a[2]>='1'&&a[2]<='8')
    {
        if(ruch==0)
        {
            s[a[1]-'a'+1][a[2]-48]='R';
            bool mam=0;
            for(;;)
            {
                for(int q=a[1]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='R')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1;q--)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='R')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48+1;q<=8;q++)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='R')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48-1;q>=1;q--)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='R')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                break;
            }
        }
        else
        {
            s[a[1]-'a'+1][a[2]-48]='r';
            bool mam=0;
            for(;;)
            {
                for(int q=a[1]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='r')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1;q--)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='r')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48+1;q<=8;q++)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='r')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48-1;q>=1;q--)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='r')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                break;
            }
        }
    }
    //zwykly ruch dwie moga Rab2
    if(a[0]=='R'&&a[1]>='a'&&a[1]<='h'&&a[2]>='a'&&a[2]<='h'&&a[3]>='1'&&a[3]<='8')
    {
        if(ruch==0)
        {
            s[a[2]-'a'+1][a[3]-48]='R';
            s[a[1]-'a'+1][a[3]-48]=0;
        }
        else
        {
            s[a[2]-'a'+1][a[3]-48]='r';
            s[a[1]-'a'+1][a[3]-48]=0;
        }
    }
    //zwykly ruch dwie moga R4b2
    if(a[0]=='R'&&a[1]>='1'&&a[1]<='8'&&a[2]>='a'&&a[2]<='h'&&a[3]>='1'&&a[3]<='8')
    {
        if(ruch==0)
        {
            s[a[2]-'a'+1][a[3]-48]='R';
            s[a[2]-'a'+1][a[1]-48]=0;
        }
        else
        {
            s[a[2]-'a'+1][a[3]-48]='r';
            s[a[2]-'a'+1][a[1]-48]=0;
        }
    }
    //===============================================
    //skoczek
    //===============================================
    //zwykly ruch Nb2
    if(a[0]=='N'&&a[1]>='a'&&a[1]<='h'&&a[2]>='1'&&a[2]<='8'&&a.size()==3)
    {
        if(ruch==0)
        {
            s[a[1]-'a'+1][a[2]-48]='N';
            for(;;)
            {
                if(a[1]-'a'+1+1>=1&&a[1]-'a'+1+1<=8&&a[2]-48+2>=1&&a[2]-48+2<=8&&s[a[1]-'a'+1+1][a[2]-48+2]=='N'){s[a[1]-'a'+1+1][a[2]-48+2]=0;break;}
                if(a[1]-'a'+1+2>=1&&a[1]-'a'+1+2<=8&&a[2]-48+1>=1&&a[2]-48+1<=8&&s[a[1]-'a'+1+2][a[2]-48+1]=='N'){s[a[1]-'a'+1+2][a[2]-48+1]=0;break;}
                if(a[1]-'a'+1+2>=1&&a[1]-'a'+1+2<=8&&a[2]-48-1>=1&&a[2]-48-1<=8&&s[a[1]-'a'+1+2][a[2]-48-1]=='N'){s[a[1]-'a'+1+2][a[2]-48-1]=0;break;}
                if(a[1]-'a'+1+1>=1&&a[1]-'a'+1+1<=8&&a[2]-48-2>=1&&a[2]-48-2<=8&&s[a[1]-'a'+1+1][a[2]-48-2]=='N'){s[a[1]-'a'+1+1][a[2]-48-2]=0;break;}
                if(a[1]-'a'+1-1>=1&&a[1]-'a'+1-1<=8&&a[2]-48-2>=1&&a[2]-48-2<=8&&s[a[1]-'a'+1-1][a[2]-48-2]=='N'){s[a[1]-'a'+1-1][a[2]-48-2]=0;break;}
                if(a[1]-'a'+1-2>=1&&a[1]-'a'+1-2<=8&&a[2]-48-1>=1&&a[2]-48-1<=8&&s[a[1]-'a'+1-2][a[2]-48-1]=='N'){s[a[1]-'a'+1-2][a[2]-48-1]=0;break;}
                if(a[1]-'a'+1-2>=1&&a[1]-'a'+1-2<=8&&a[2]-48+1>=1&&a[2]-48+1<=8&&s[a[1]-'a'+1-2][a[2]-48+1]=='N'){s[a[1]-'a'+1-2][a[2]-48+1]=0;break;}
                if(a[1]-'a'+1-1>=1&&a[1]-'a'+1-1<=8&&a[2]-48+2>=1&&a[2]-48+2<=8&&s[a[1]-'a'+1-1][a[2]-48+2]=='N'){s[a[1]-'a'+1-1][a[2]-48+2]=0;break;}
                break;
            }
        }
        else
        {
            s[a[1]-'a'+1][a[2]-48]='n';
            for(;;)
            {
                if(a[1]-'a'+1+1>=1&&a[1]-'a'+1+1<=8&&a[2]-48+2>=1&&a[2]-48+2<=8&&s[a[1]-'a'+1+1][a[2]-48+2]=='n'){s[a[1]-'a'+1+1][a[2]-48+2]=0;break;}
                if(a[1]-'a'+1+2>=1&&a[1]-'a'+1+2<=8&&a[2]-48+1>=1&&a[2]-48+1<=8&&s[a[1]-'a'+1+2][a[2]-48+1]=='n'){s[a[1]-'a'+1+2][a[2]-48+1]=0;break;}
                if(a[1]-'a'+1+2>=1&&a[1]-'a'+1+2<=8&&a[2]-48-1>=1&&a[2]-48-1<=8&&s[a[1]-'a'+1+2][a[2]-48-1]=='n'){s[a[1]-'a'+1+2][a[2]-48-1]=0;break;}
                if(a[1]-'a'+1+1>=1&&a[1]-'a'+1+1<=8&&a[2]-48-2>=1&&a[2]-48-2<=8&&s[a[1]-'a'+1+1][a[2]-48-2]=='n'){s[a[1]-'a'+1+1][a[2]-48-2]=0;break;}
                if(a[1]-'a'+1-1>=1&&a[1]-'a'+1-1<=8&&a[2]-48-2>=1&&a[2]-48-2<=8&&s[a[1]-'a'+1-1][a[2]-48-2]=='n'){s[a[1]-'a'+1-1][a[2]-48-2]=0;break;}
                if(a[1]-'a'+1-2>=1&&a[1]-'a'+1-2<=8&&a[2]-48-1>=1&&a[2]-48-1<=8&&s[a[1]-'a'+1-2][a[2]-48-1]=='n'){s[a[1]-'a'+1-2][a[2]-48-1]=0;break;}
                if(a[1]-'a'+1-2>=1&&a[1]-'a'+1-2<=8&&a[2]-48+1>=1&&a[2]-48+1<=8&&s[a[1]-'a'+1-2][a[2]-48+1]=='n'){s[a[1]-'a'+1-2][a[2]-48+1]=0;break;}
                if(a[1]-'a'+1-1>=1&&a[1]-'a'+1-1<=8&&a[2]-48+2>=1&&a[2]-48+2<=8&&s[a[1]-'a'+1-1][a[2]-48+2]=='n'){s[a[1]-'a'+1-1][a[2]-48+2]=0;break;}
                break;
            }
        }
    }
    //ruch ale dwa moga Nbd4
    if(a[0]=='N'&&a[1]>='a'&&a[1]<='h'&&a[2]>='a'&&a[2]<='h'&&a[3]>='1'&&a[3]<='8')
    {
        if(ruch==0)
        {
            s[a[2]-'a'+1][a[3]-48]='N';
            for(;;)
            {
                if(a[2]-'a'+1+1==a[1]-'a'+1&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1+1][a[3]-48+2]=='N'){s[a[2]-'a'+1+1][a[3]-48+2]=0;break;}
                if(a[2]-'a'+1+2==a[1]-'a'+1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1+2][a[3]-48+1]=='N'){s[a[2]-'a'+1+2][a[3]-48+1]=0;break;}
                if(a[2]-'a'+1+2==a[1]-'a'+1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1+2][a[3]-48-1]=='N'){s[a[2]-'a'+1+2][a[3]-48-1]=0;break;}
                if(a[2]-'a'+1+1==a[1]-'a'+1&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1+1][a[3]-48-2]=='N'){s[a[2]-'a'+1+1][a[3]-48-2]=0;break;}
                if(a[2]-'a'+1-1==a[1]-'a'+1&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1-1][a[3]-48-2]=='N'){s[a[2]-'a'+1-1][a[3]-48-2]=0;break;}
                if(a[2]-'a'+1-2==a[1]-'a'+1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1-2][a[3]-48-1]=='N'){s[a[2]-'a'+1-2][a[3]-48-1]=0;break;}
                if(a[2]-'a'+1-2==a[1]-'a'+1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1-2][a[3]-48+1]=='N'){s[a[2]-'a'+1-2][a[3]-48+1]=0;break;}
                if(a[2]-'a'+1-1==a[1]-'a'+1&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1-1][a[3]-48+2]=='N'){s[a[2]-'a'+1-1][a[3]-48+2]=0;break;}
                break;
            }
        }
        else
        {
            s[a[2]-'a'+1][a[3]-48]='n';
            for(;;)
            {
                if(a[2]-'a'+1+1==a[1]-'a'+1&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1+1][a[3]-48+2]=='n'){s[a[2]-'a'+1+1][a[3]-48+2]=0;break;}
                if(a[2]-'a'+1+2==a[1]-'a'+1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1+2][a[3]-48+1]=='n'){s[a[2]-'a'+1+2][a[3]-48+1]=0;break;}
                if(a[2]-'a'+1+2==a[1]-'a'+1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1+2][a[3]-48-1]=='n'){s[a[2]-'a'+1+2][a[3]-48-1]=0;break;}
                if(a[2]-'a'+1+1==a[1]-'a'+1&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1+1][a[3]-48-2]=='n'){s[a[2]-'a'+1+1][a[3]-48-2]=0;break;}
                if(a[2]-'a'+1-1==a[1]-'a'+1&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1-1][a[3]-48-2]=='n'){s[a[2]-'a'+1-1][a[3]-48-2]=0;break;}
                if(a[2]-'a'+1-2==a[1]-'a'+1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1-2][a[3]-48-1]=='n'){s[a[2]-'a'+1-2][a[3]-48-1]=0;break;}
                if(a[2]-'a'+1-2==a[1]-'a'+1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1-2][a[3]-48+1]=='n'){s[a[2]-'a'+1-2][a[3]-48+1]=0;break;}
                if(a[2]-'a'+1-1==a[1]-'a'+1&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1-1][a[3]-48+2]=='n'){s[a[2]-'a'+1-1][a[3]-48+2]=0;break;}
                break;
            }
        }
    }
    //ruch ale dwa moga N4e3
    if(a[0]=='N'&&a[1]>='1'&&a[1]<='8'&&a[2]>='a'&&a[2]<='h'&&a[3]>='1'&&a[3]<='8')
    {
        if(ruch==0)
        {
            s[a[2]-'a'+1][a[3]-48]='N';
            for(;;)
            {
                if(a[1]-48==a[3]-48+2&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1+1][a[3]-48+2]=='N'){s[a[2]-'a'+1+1][a[3]-48+2]=0;break;}
                if(a[1]-48==a[3]-48+1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1+2][a[3]-48+1]=='N'){s[a[2]-'a'+1+2][a[3]-48+1]=0;break;}
                if(a[1]-48==a[3]-48-1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1+2][a[3]-48-1]=='N'){s[a[2]-'a'+1+2][a[3]-48-1]=0;break;}
                if(a[1]-48==a[3]-48-2&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1+1][a[3]-48-2]=='N'){s[a[2]-'a'+1+1][a[3]-48-2]=0;break;}
                if(a[1]-48==a[3]-48-2&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1-1][a[3]-48-2]=='N'){s[a[2]-'a'+1-1][a[3]-48-2]=0;break;}
                if(a[1]-48==a[3]-48-1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1-2][a[3]-48-1]=='N'){s[a[2]-'a'+1-2][a[3]-48-1]=0;break;}
                if(a[1]-48==a[3]-48+1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1-2][a[3]-48+1]=='N'){s[a[2]-'a'+1-2][a[3]-48+1]=0;break;}
                if(a[1]-48==a[3]-48+2&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1-1][a[3]-48+2]=='N'){s[a[2]-'a'+1-1][a[3]-48+2]=0;break;}
                break;
            }
        }
        else
        {
            s[a[2]-'a'+1][a[3]-48]='n';
            for(;;)
            {
                if(a[1]-48==a[3]-48+2&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1+1][a[3]-48+2]=='n'){s[a[2]-'a'+1+1][a[3]-48+2]=0;break;}
                if(a[1]-48==a[3]-48+1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1+2][a[3]-48+1]=='n'){s[a[2]-'a'+1+2][a[3]-48+1]=0;break;}
                if(a[1]-48==a[3]-48-1&&a[2]-'a'+1+2>=1&&a[2]-'a'+1+2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1+2][a[3]-48-1]=='n'){s[a[2]-'a'+1+2][a[3]-48-1]=0;break;}
                if(a[1]-48==a[3]-48-2&&a[2]-'a'+1+1>=1&&a[2]-'a'+1+1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1+1][a[3]-48-2]=='n'){s[a[2]-'a'+1+1][a[3]-48-2]=0;break;}
                if(a[1]-48==a[3]-48-2&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48-2>=1&&a[3]-48-2<=8&&s[a[2]-'a'+1-1][a[3]-48-2]=='n'){s[a[2]-'a'+1-1][a[3]-48-2]=0;break;}
                if(a[1]-48==a[3]-48-1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48-1>=1&&a[3]-48-1<=8&&s[a[2]-'a'+1-2][a[3]-48-1]=='n'){s[a[2]-'a'+1-2][a[3]-48-1]=0;break;}
                if(a[1]-48==a[3]-48+1&&a[2]-'a'+1-2>=1&&a[2]-'a'+1-2<=8&&a[3]-48+1>=1&&a[3]-48+1<=8&&s[a[2]-'a'+1-2][a[3]-48+1]=='n'){s[a[2]-'a'+1-2][a[3]-48+1]=0;break;}
                if(a[1]-48==a[3]-48+2&&a[2]-'a'+1-1>=1&&a[2]-'a'+1-1<=8&&a[3]-48+2>=1&&a[3]-48+2<=8&&s[a[2]-'a'+1-1][a[3]-48+2]=='n'){s[a[2]-'a'+1-1][a[3]-48+2]=0;break;}
                break;
            }
        }
    }
    //ruch ale duzo moze Nc2e3
    if(a[0]=='N'&&a[1]>='a'&&a[1]<='h'&&a[2]>='1'&&a[2]<='8'&&a[3]>='a'&&a[3]<='h'&&a[4]>='1'&&a[4]<='8')
    {
        if(ruch==0)
        {
            s[a[3]-'a'+1][a[4]-48]='N';
            s[a[1]-'a'+1][a[2]-48]=0;
        }
        else
        {
            s[a[3]-'a'+1][a[4]-48]='n';
            s[a[1]-'a'+1][a[2]-48]=0;
        }
    }
    //===============================================
    //krol
    //===============================================
    if(a[0]=='K')
    {
        if(ruch==0)
        {
            for(int q=1;q<=8;q++)for(int w=1;w<=8;w++)if(s[q][w]=='K'){s[q][w]=0;break;}
            s[a[1]-'a'+1][a[2]-48]='K';
        }
        else
        {
            for(int q=1;q<=8;q++)for(int w=1;w<=8;w++)if(s[q][w]=='k'){s[q][w]=0;break;}
            s[a[1]-'a'+1][a[2]-48]='k';
        }
    }
    //===============================================
    //goniec - na skroty
    //===============================================
    if(a[0]=='B')
    {
        if(ruch==0)
        {
            for(int q=1;q<=8;q++)for(int w=1;w<=8;w++)if(s[q][w]=='B' && (q+w)%2==(a[1]-'a'+1+a[2]-48)%2){s[q][w]=0;break;}
            s[a[1]-'a'+1][a[2]-48]='B';
        }
        else
        {
            for(int q=1;q<=8;q++)for(int w=1;w<=8;w++)if(s[q][w]=='b' && (q+w)%2==(a[1]-'a'+1+a[2]-48)%2){s[q][w]=0;break;}
            s[a[1]-'a'+1][a[2]-48]='b';
        }
    }
    //===============================================
    //hetman
    //===============================================
    //zwykly ruch Qe3
    if(a[0]=='Q' && a[1]>='a' && a[1]<='h' && a[2]>='1' && a[2]<='8' && a.size()==3)
    {
        if(ruch==0)
        {
            s[a[1]-'a'+1][a[2]-48]='Q';
            bool mam=0;
            for(;;)
            {
                for(int q=a[1]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='Q')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1;q--)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='Q')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48+1;q<=8;q++)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='Q')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48-1;q>=1;q--)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='Q')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a'+2;q<=8 && a[2]-48+q-(a[1]-'a'+1)<=8;q++)
                {
                    if(s[q][a[2]-48+q-(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48+q-(a[1]-'a'+1)]=='Q')
                        {
                            s[q][a[2]-48+q-(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1 && a[2]-48+q-(a[1]-'a'+1)>=1;q--)
                {
                    if(s[q][a[2]-48+q-(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48+q-(a[1]-'a'+1)]=='Q')
                        {
                            s[q][a[2]-48+q-(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a'+2;q<=8 && a[2]-48-q+(a[1]-'a'+1)>=1;q++)
                {
                    if(s[q][a[2]-48-q+(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48-q+(a[1]-'a'+1)]=='Q')
                        {
                            s[q][a[2]-48-q+(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1 && a[2]-48-q+(a[1]-'a'+1)<=8;q--)
                {
                    if(s[q][a[2]-48-q+(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48-q+(a[1]-'a'+1)]=='Q')
                        {
                            s[q][a[2]-48-q+(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            s[a[1]-'a'+1][a[2]-48]='q';
            bool mam=0;
            for(;;)
            {
                for(int q=a[1]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='q')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1;q--)
                {
                    if(s[q][a[2]-48]!=0)
                    {
                    if(s[q][a[2]-48]=='q')
                    {
                        s[q][a[2]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48+1;q<=8;q++)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='q')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-48-1;q>=1;q--)
                {
                    if(s[a[1]-'a'+1][q]!=0)
                    {
                    if(s[a[1]-'a'+1][q]=='q')
                    {
                        s[a[1]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a'+2;q<=8 && a[2]-48+q-(a[1]-'a'+1)<=8;q++)
                {
                    if(s[q][a[2]-48+q-(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48+q-(a[1]-'a'+1)]=='q')
                        {
                            s[q][a[2]-48+q-(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1 && a[2]-48+q-(a[1]-'a'+1)>=1;q--)
                {
                    if(s[q][a[2]-48+q-(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48+q-(a[1]-'a'+1)]=='q')
                        {
                            s[q][a[2]-48+q-(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a'+2;q<=8 && a[2]-48-q+(a[1]-'a'+1)>=1;q++)
                {
                    if(s[q][a[2]-48-q+(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48-q+(a[1]-'a'+1)]=='q')
                        {
                            s[q][a[2]-48-q+(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[1]-'a';q>=1 && a[2]-48-q+(a[1]-'a'+1)<=8;q--)
                {
                    if(s[q][a[2]-48-q+(a[1]-'a'+1)]!=0)
                    {
                        if(s[q][a[2]-48-q+(a[1]-'a'+1)]=='q')
                        {
                            s[q][a[2]-48-q+(a[1]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                break;
            }
        }
    }
    //ruch ale dwa moga Qed3
    if(a[0]=='Q' && a[1]>='a' && a[1]<='h' && a[2]>='a' && a[2]<='h' && a[3]>='1' && a[3]<='8' )
    {
        if(ruch==0)
        {
            s[a[2]-'a'+1][a[3]-48]='Q';
            bool mam=0;
            for(;;)
            {
                for(int q=a[2]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='Q' && q==a[1]-'a'+1)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1;q--)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='Q' && q==a[1]-'a'+1)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48+1;q<=8;q++)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='Q' && a[2]-'a'+1==a[1]-'a'+1)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48-1;q>=1;q--)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='Q' && a[2]-'a'+1==a[1]-'a'+1)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48+q-(a[2]-'a'+1)<=8;q++)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='Q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48+q-(a[2]-'a'+1)>=1;q--)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='Q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48-q+(a[2]-'a'+1)>=1;q++)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='Q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48-q+(a[2]-'a'+1)<=8;q--)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='Q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            s[a[2]-'a'+1][a[3]-48]='q';
            bool mam=0;
            for(;;)
            {
                for(int q=a[2]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='q' && q==a[1]-'a'+1)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1;q--)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='q' && q==a[1]-'a'+1)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48+1;q<=8;q++)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='q' && a[2]-'a'+1==a[1]-'a'+1)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48-1;q>=1;q--)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='q' && a[2]-'a'+1==a[1]-'a'+1)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48+q-(a[2]-'a'+1)<=8;q++)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48+q-(a[2]-'a'+1)>=1;q--)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48-q+(a[2]-'a'+1)>=1;q++)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48-q+(a[2]-'a'+1)<=8;q--)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='q' && q==a[1]-'a'+1)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                break;
            }
        }
    }
    //ruch ale dwa moga Q4d3
    if(a[0]=='Q' && a[1]>='1' && a[1]<='8' && a[2]>='a' && a[2]<='h' && a[3]>='1' && a[3]<='8' )
    {
        if(ruch==0)
        {
            s[a[2]-'a'+1][a[3]-48]='Q';
            bool mam=0;
            for(;;)
            {
                for(int q=a[2]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='Q' && a[3]-48==a[1]-48)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1;q--)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='Q' && a[3]-48==a[1]-48)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48+1;q<=8;q++)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='Q' && q==a[1]-48)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48-1;q>=1;q--)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='Q' && q==a[1]-48)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48+q-(a[2]-'a'+1)<=8;q++)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='Q' && a[3]-48+q-(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48+q-(a[2]-'a'+1)>=1;q--)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='Q' && a[3]-48+q-(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48-q+(a[2]-'a'+1)>=1;q++)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='Q' && a[3]-48-q+(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48-q+(a[2]-'a'+1)<=8;q--)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='Q' && a[3]-48-q+(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            s[a[2]-'a'+1][a[3]-48]='q';
            bool mam=0;
            for(;;)
            {
                for(int q=a[2]-'a'+2;q<=8;q++)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='q' && a[3]-48==a[1]-48)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1;q--)
                {
                    if(s[q][a[3]-48]!=0)
                    {
                    if(s[q][a[3]-48]=='q' && a[3]-48==a[1]-48)
                    {
                        s[q][a[3]-48]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48+1;q<=8;q++)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='q' && q==a[1]-48)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[3]-48-1;q>=1;q--)
                {
                    if(s[a[2]-'a'+1][q]!=0)
                    {
                    if(s[a[2]-'a'+1][q]=='q' && q==a[1]-48)
                    {
                        s[a[2]-'a'+1][q]=0;
                        mam=1;
                        break;
                    }
                    else
                    break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48+q-(a[2]-'a'+1)<=8;q++)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='q' && a[3]-48+q-(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48+q-(a[2]-'a'+1)>=1;q--)
                {
                    if(s[q][a[3]-48+q-(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48+q-(a[2]-'a'+1)]=='q' && a[3]-48+q-(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48+q-(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a'+2;q<=8 && a[3]-48-q+(a[2]-'a'+1)>=1;q++)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='q' && a[3]-48-q+(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                if(mam==1)
                break;
                for(int q=a[2]-'a';q>=1 && a[3]-48-q+(a[2]-'a'+1)<=8;q--)
                {
                    if(s[q][a[3]-48-q+(a[2]-'a'+1)]!=0)
                    {
                        if(s[q][a[3]-48-q+(a[2]-'a'+1)]=='q' && a[3]-48-q+(a[2]-'a'+1)==a[1]-48)
                        {
                            s[q][a[3]-48-q+(a[2]-'a'+1)]=0;
                            mam=1;
                            break;
                        }
                        else
                        break;
                    }
                }
                break;
            }
        }
    }
    //ruch ale duzo moze Qc2e3
    if(a[0]=='Q'&&a[1]>='a'&&a[1]<='h'&&a[2]>='1'&&a[2]<='8'&&a[3]>='a'&&a[3]<='h'&&a[4]>='1'&&a[4]<='8')
    {
        if(ruch==0)
        {
            s[a[3]-'a'+1][a[4]-48]='Q';
            s[a[1]-'a'+1][a[2]-48]=0;
        }
        else
        {
            s[a[3]-'a'+1][a[4]-48]='q';
            s[a[1]-'a'+1][a[2]-48]=0;
        }
    }
    //ROSZADA KROTKA
    if(a[0]=='O' && a[1]=='-' && a[2]=='O' && a.size()==3)
    {
        if(ruch==0)
        {
            s[e][1]=0;
            s[h][1]=0;
            s[g][1]='K';
            s[f][1]='R';
        }
        else
        {
            s[e][8]=0;
            s[h][8]=0;
            s[g][8]='k';
            s[f][8]='r';
        }
    }
    //ROSZADA DLUGA
    if(a[0]=='O' && a[1]=='-' && a[2]=='O' && a[3]=='-' && a[4]=='O')
    {
        if(ruch==0)
        {
            s[e][1]=0;
            s[1][1]=0;
            s[c][1]='K';
            s[d][1]='R';
        }
        else
        {
            s[e][8]=0;
            s[1][8]=0;
            s[c][8]='k';
            s[d][8]='r';
        }
    }
    if(s[1][1]!='R')
    roszQ=0;
    if(s[h][1]!='R')
    roszK=0;
    if(s[1][8]!='r')
    roszq=0;
    if(s[h][8]!='r')
    roszk=0;
    
    if(s[e][1]!='K')
    {roszQ=0;roszK=0;}
    if(s[e][8]!='k')
    {roszq=0;roszk=0;}
    
    if(ruch==0)
    {
        ruch=1;
        for(int q=1;q<=8;q++)
        bicieCZARNE[q]=0;
    }
    else
    {
        ruch=0;
        for(int q=1;q<=8;q++)
        bicieBIALE[q]=0;
    }
}
