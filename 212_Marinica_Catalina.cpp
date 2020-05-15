/*
Marinica Catalina
212
Proiect 3 Tema 4
GNU GCC Compiler


automobil - masina - mini
                   - mica
                   - compacta - hatchback
                              - combi
                              - sedan

          - monovolum
*/

#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<set>
#include<utility>
#include <bits/stdc++.h>
using namespace std;


///---------------------------------------------------

class Automobil
{protected:
    string marca;
    int an_fabricatie;
    float pret;
    static int numar_automobile;
public:
    Automobil (string,int,float);
    Automobil (const Automobil&);
    virtual ~Automobil();
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream&, Automobil&);
    friend ostream& operator<<(ostream&, Automobil&);
    static void NumarObiecte(){ cout<<numar_automobile;}

    virtual string model_masina()
        {return "automobil";}
    int get_an_fabricatie() const {return this->an_fabricatie;}

    Automobil& operator=(const Automobil& automobil){
        if(this==&automobil)
            return *this;
        this->marca=automobil.marca;
        this->an_fabricatie=automobil.an_fabricatie;
        this->pret=automobil.pret;
        return *this;
    }
};

    int Automobil::numar_automobile;

    Automobil::Automobil(string marca="",int an_fabricatie=0,float pret=0){
        numar_automobile++;
        this->marca=marca;
        this->an_fabricatie=an_fabricatie;
        this->pret=pret;
    }

    Automobil::Automobil(const Automobil& automobil){
        this->marca=automobil.marca;
        this->an_fabricatie=automobil.an_fabricatie;
        this->pret=automobil.pret;
    }


    void Automobil::citire(istream &in){
        int an_fabricatie;
        float pret;

        cout<<"Marca: "; in>>this->marca;
        while(true){
            cout<<"An fabricatie: "; in>>an_fabricatie;
            try{
                if(an_fabricatie<1950 || an_fabricatie>2020)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"An invalid pentru fabricarea unui automobil(1950-2020)\n";
            }
        }

        while(true){
            cout<<"Pret: "; in>>pret;
            try{
                if(pret<0)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Pretul unui automobil nu poate sa fie negativ.\n";
            }
        }

        this->an_fabricatie=an_fabricatie;
        this->pret=pret;

    }

    void Automobil::afisare(ostream &out){
        out<<"\n\nMarca: "<<this->marca;
        out<<"\nAn fabricatie: "<<this->an_fabricatie;
        out<<"\nPret: "<<this->pret;
    }


    istream& operator>>(istream& in,Automobil& automobil){
        automobil.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out,Automobil& automobil){
        automobil.afisare(out);
        return out;
    }


    Automobil::~Automobil(){};

///---------------------------------------------------

class Masina:public Automobil
{protected:
    float lungime;
    string tip_masina;
 public:
    Masina(string,int,float,float,string);
    Masina(const Masina&);
    ~Masina();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Masina&);
    friend ostream& operator<<(ostream&, Masina&);
    string model_masina()
        {return "masina";}

    Masina& operator=(const Masina &masina){
        if(this==&masina)
            return *this;
        Automobil::operator=(masina);
        this->lungime=masina.lungime;
        this->tip_masina=masina.tip_masina;
        return *this;
    }

};

    Masina::Masina(string marca="",int an_fabricatie=0,float pret=0,float lungime=0,string tip_masina=""):Automobil(marca,an_fabricatie,pret){
        this->lungime=lungime;
        this->tip_masina=tip_masina;
    }

    Masina::Masina(const Masina& masina):Automobil(masina){
        this->lungime=lungime;
        this->tip_masina=tip_masina;
    }

    void Masina::afisare(ostream &out){
        Automobil::afisare(out);
        out<<"\nLungime: ";
        out<<this->lungime;
        out<<"\nTip masina: ";
        out<<this->tip_masina;
    }

    void Masina::citire(istream& in){
        Automobil::citire(in);
        float lungime;
        while(true){
            try{
                cout<<"Lungime: ";
                in>>lungime;
                if(lungime<0)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Lungimea unui automobil nu poate fi negativa.\n";
            }
        }
        this->lungime=lungime;

        cout<<"Tip masina: ";
        in>>this->tip_masina;
    }

    istream& operator>>(istream& in, Masina& masina){
        masina.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Masina& masina){
        masina.afisare(out);
        return out;
    }

    Masina::~Masina(){};

///---------------------------------------------------
 class Mini:public Masina
 {
public:
    Mini(string,int,float,float,string);
    Mini(const Mini&);
    ~Mini();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Mini&);
    friend ostream& operator<<(ostream&, Mini&);
    string model_masina()
        {return "mini";}

    Mini& operator=(const Mini &mini){
        if(this==&mini)
            return *this;
        Masina::operator=(mini);
        return *this;
    }
};

    Mini::Mini(string marca="",int an_fabricatie=0,float pret=0,
               float lungime=0,string tip_masina=""):Masina(marca,an_fabricatie,pret,lungime,tip_masina){}
    Mini::Mini(const Mini& mini):Masina(mini){}

    void Mini::afisare(ostream &out){
        Masina::afisare(out);
    }

    void Mini::citire(istream& in){
        Masina::citire(in);
        while(true){
            try{
                if(this->lungime>=4 || this->lungime<0)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Lungimea unei masini mini e <4m si pozitiva.\n";
                cout<<"Lungime: ";
                in>>this->lungime;
            }
        }

          while(true){
            try{
                if(this->tip_masina!="oras")
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Tipul unei masini mini e oras"<<endl;
                cout<<"Tip: ";
                in>>this->tip_masina;
            }
        }
    }

    istream& operator>>(istream& in, Mini& mini){
        mini.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Mini& mini){
        mini.afisare(out);
        return out;
    }

    Mini::~Mini(){};

///---------------------------------------------------

class Mica:public Masina
 {
public:
    Mica(string,int,float,float,string);
    Mica(const Mica&);
    ~Mica();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Mica&);
    friend ostream& operator<<(ostream&, Mica&);
    string model_masina()
        {return "mica";}

    Mica& operator=(const Mica &mica){
        if(this==&mica)
            return *this;
        Masina::operator=(mica);
        return *this;
    }
};

    Mica::Mica(string marca="",int an_fabricatie=0,float pret=0,
               float lungime=0,string tip_masina=""):Masina(marca,an_fabricatie,pret,lungime,tip_masina){}
    Mica::Mica(const Mica& mica):Masina(mica){}

    void Mica::afisare(ostream &out){
        Masina::afisare(out);
    }

    void Mica::citire(istream& in){
        Masina::citire(in);
        while(true){
            try{
                if(this->lungime<3.85 || this->lungime>4.1)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Lungimea unei masini mici e intre 3.85 si 4.1"<<endl;
                cout<<"Lungime: ";
                in>>this->lungime;
            }
        }

          while(true){
            try{
                if(this->tip_masina!="oras")
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Tipul unei masini mici e oras"<<endl;
                cout<<"Tip: ";
                in>>this->tip_masina;
            }
        }
    }

    istream& operator>>(istream& in, Mica& mica){
        mica.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Mica& mica){
        mica.afisare(out);
        return out;
    }

    Mica::~Mica(){};

///---------------------------------------------------
class Compacta:public Masina
 {
public:
    Compacta(string,int,float,float,string);
    Compacta(const Compacta&);
    ~Compacta();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Compacta&);
    friend ostream& operator<<(ostream&, Compacta&);
    string model_masina()
        {return "compacta";}

    Compacta& operator=(const Compacta &compacta){
        if(this==&compacta)
            return *this;
        Masina::operator=(compacta);
        return *this;
    }
};

    Compacta::Compacta(string marca="",int an_fabricatie=0,float pret=0,
               float lungime=0,string tip_masina=""):Masina(marca,an_fabricatie,pret,lungime,tip_masina){}
    Compacta::Compacta(const Compacta& compacta):Masina(compacta){}

    void Compacta::afisare(ostream &out){
        Masina::afisare(out);
    }

    void Compacta::citire(istream& in){
        Masina::citire(in);
        while(true){
            try{
                if(this->lungime<4.2 || this->lungime>4.5)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Lungimea unei masini de acest tip e intre 4.2 si 4.5"<<endl;
                cout<<"Lungime: ";
                in>>this->lungime;
            }
        }

          while(true){
            try{
                if( this->tip_masina!="oras" && this->tip_masina!="drum_lung" && this->tip_masina!="mixta" )
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Tipul unei masini de acest tip e oras/drum_lung/mixta"<<endl;
                cout<<"Tip: ";
                in>>this->tip_masina;
            }
        }
    }

    istream& operator>>(istream& in, Compacta& compacta){
        compacta.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Compacta& compacta){
        compacta.afisare(out);
        return out;
    }

    Compacta::~Compacta(){};

///---------------------------------------------------

class Hatchback:public Compacta
 {
public:
    Hatchback(string,int,float,float,string);
    Hatchback(const Hatchback&);
    ~Hatchback();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Hatchback&);
    friend ostream& operator<<(ostream&, Hatchback&);
    string model_masina()
        {return "hatchback";}

    Hatchback& operator=(const Hatchback &hatchback){
        if(this==&hatchback)
            return *this;
        Compacta::operator=(hatchback);
        return *this;
    }
};

    Hatchback::Hatchback(string marca="",int an_fabricatie=0,float pret=0,
               float lungime=0,string tip_masina=""):Compacta(marca,an_fabricatie,pret,lungime,tip_masina){}
    Hatchback::Hatchback(const Hatchback& hatchback):Compacta(hatchback){}

    void Hatchback::afisare(ostream &out){
        Compacta::afisare(out);
    }

    void Hatchback::citire(istream& in){
        Compacta::citire(in);

    }

    istream& operator>>(istream& in, Hatchback& hatchaback){
        hatchaback.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Hatchback& hatchback){
        hatchback.afisare(out);
        return out;
    }

    Hatchback::~Hatchback(){};
///---------------------------------------------------

class Combi:public Compacta
 {
public:
    Combi(string,int,float,float,string);
    Combi(const Combi&);
    ~Combi();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Combi&);
    friend ostream& operator<<(ostream&, Combi&);
    string model_masina()
        {return "combi";}

    Combi& operator=(const Combi &combi){
        if(this==&combi)
            return *this;
        Compacta::operator=(combi);
        return *this;
    }
};

    Combi::Combi(string marca="",int an_fabricatie=0,float pret=0,
               float lungime=0,string tip_masina=""):Compacta(marca,an_fabricatie,pret,lungime,tip_masina){}
    Combi::Combi(const Combi& combi):Compacta(combi){}

    void Combi::afisare(ostream &out){
        Compacta::afisare(out);
    }

    void Combi::citire(istream& in){
        Compacta::citire(in);

    }

    istream& operator>>(istream& in, Combi& combi){
        combi.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Combi& combi){
        combi.afisare(out);
        return out;
    }

    Combi::~Combi(){};

 ///---------------------------------------------------

class Sedan:public Compacta
 {
public:
    Sedan(string,int,float,float,string);
    Sedan(const Sedan&);
    ~Sedan();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Sedan&);
    friend ostream& operator<<(ostream&, Sedan&);
    string model_masina()
        {return "sedan";}

    Sedan& operator=(const Sedan &sedan){
        if(this==&sedan)
            return *this;
        Compacta::operator=(sedan);
        return *this;
    }
};

    Sedan::Sedan(string marca="",int an_fabricatie=0,float pret=0,
               float lungime=0,string tip_masina=""):Compacta(marca,an_fabricatie,pret,lungime,tip_masina){}
    Sedan::Sedan(const Sedan& sedan):Compacta(sedan){}

    void Sedan::afisare(ostream &out){
        Compacta::afisare(out);
    }

    void Sedan::citire(istream& in){
        Compacta::citire(in);

    }

    istream& operator>>(istream& in, Sedan& sedan){
        sedan.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Sedan& sedan){
        sedan.afisare(out);
        return out;
    }

    Sedan::~Sedan(){};
///---------------------------------------------------
class Monovolum:public Automobil
{private:
    int numar_locuri;

 public:
    Monovolum (string,int,float,int);
    Monovolum (const Monovolum&);
    ~Monovolum();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Monovolum&);
    friend ostream& operator<<(ostream&, Monovolum&);
    string model_masina()
        {return "monovolum";}

    Monovolum& operator=(const Monovolum &monovolum){
        if(this==&monovolum)
            return *this;
        Automobil::operator=(monovolum);
        this->numar_locuri=monovolum.numar_locuri;
        return *this;
    }


};
    Monovolum::Monovolum(string marca="",int an_fabricatie=0,float pret=0,int numar_locuri=0):Automobil(marca,an_fabricatie,pret){
        this->numar_locuri=numar_locuri;

    }

    Monovolum::Monovolum(const Monovolum& monovolum):Automobil(monovolum){
        this->numar_locuri=monovolum.numar_locuri;

    }

    void Monovolum::afisare(ostream &out){
        Automobil::afisare(out);
        out<<"\nNumar locuri: ";
        out<<this->numar_locuri;
    }

    void Monovolum::citire(istream& in){
        Automobil::citire(in);
        int numar_locuri;

        while(true){
            try{
                cout<<"Numar locuri: ";
                in>>numar_locuri;
                if(numar_locuri<5 || numar_locuri>7)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Un monovolum poate avea intre 5-7 locuri."<<endl;
            }
        }
        this->numar_locuri=numar_locuri;
    }

    istream& operator>>(istream& in, Monovolum& monovolum){
        monovolum.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Monovolum& monovolum){
        monovolum.afisare(out);
        return out;
    }

    Monovolum::~Monovolum(){};



///---------------------------------------------------

template <class t> class Vanzare{
 private:
    int numarStoc;
    int numarVandut;
    set<pair<t* ,bool> > stoc;
    set<pair<t* ,bool> > vandut;
 public:
    Vanzare(int numarStoc=0,int numarVandut=0, set<pair<t*,bool> > p=set<pair<t*,bool> >(), set<pair<t*,bool> > q=set<pair<t*,bool> >()){
        typename set<pair<t* ,bool> >::iterator itr;
        this->numarStoc=numarStoc;
        this->numarVandut=numarVandut;
        for ( itr = p.begin(); itr != p.end(); ++itr)
            stoc.insert(make_pair(itr->first,itr->second));
        for ( itr = q.begin(); itr != q.end(); ++itr)
            vandut.insert(make_pair(itr->first,itr->second));
        }


    int get_numarStoc()const{return this->numarStoc;}
    int get_numarVandut()const{return this->numarVandut;}



    Vanzare(const Vanzare &vanzare){
        typename set<pair<t* ,bool> >::iterator itr;
        this->numarStoc=vanzare.numarStoc;
        this->numarVandut=vanzare.numarVandut;

        for ( itr = vanzare.stoc.begin(); itr != vanzare.stoc.end(); ++itr)
            stoc.insert(make_pair(itr->first,itr->second));
        for ( itr = vanzare.vandut.begin(); itr != vanzare.vandut.end(); ++itr)
            vandut.insert(make_pair(itr->first,itr->second));
    }

    Vanzare& operator=(const Vanzare &vanzare){
        if(this==&vanzare)
            return *this;
        typename set<pair<t* ,bool> >::iterator itr;
        this->numarStoc=vanzare.numarStoc;
        this->numarVandut=vanzare.numarVandut;

        for ( itr = vanzare.stoc.begin(); itr != vanzare.stoc.end(); ++itr)
            stoc.insert(make_pair(itr->first,itr->second));
        for ( itr = vanzare.vandut.begin(); itr != vanzare.vandut.end(); ++itr)
            vandut.insert(make_pair(itr->first,itr->second));

        return *this;
    }


    void cumpara_obiect(){
        if(numarStoc==0)
            cout<<"Nu exista niciun automobil de acest tip pe stoc.\n";
        else{
            int i;
            typename set<pair<t* ,bool> >::iterator itr;
            cout<<"Puteti cumpara unul din urmatoarele obiecte: ";
            for (itr = stoc.begin(); itr != stoc.end(); ++itr) {
                cout << *(itr->first)<<endl;
                cout <<"Nou: "<<itr->second<<endl;
                cout<<"--------------------------\n";
            }
           while(true){
              cout<<"Introduceti pozitia obiectului pe care doriti sa il cumparati: ";
              cin>>i;
              try{
                 if(i<=0 || i>numarStoc)
                    throw 1;
                 else
                    break;
                }
              catch(int a){
                 cout<<"Puteti cumpara unul dintre cele "<<numarStoc<<" obiecte din stoc\n";
              }
            }


            itr=stoc.begin();
            while(i-1){
               itr++;
               i--;
            }

            cout<<"Ati cumparat:\n";
            cout<<*(itr->first);
            cout <<"\nNou: "<<itr->second<<endl;

            vandut.insert(make_pair(itr->first,itr->second));
            stoc.erase(itr);

            numarStoc--;
            numarVandut++;
        }
    }


    void citire(istream &in){
        int nrstoc;

        while(true){
            try{
                cout<<"Introduceti numarul de obiecte pe care doriti sa le adaugati in stoc: ";
                in>>nrstoc;
                if(nrstoc<0)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Puteti adauga un numar >=0 de obiecte in stoc.\n";
            }
        }

        this->numarStoc=numarStoc+nrstoc;
        t **p;
        p=new t*[nrstoc];

        cout<<"Introduceti obiectele in stoc: \n";
        for(int i=0;i<nrstoc;i++){
           p[i]=new t;
           in>>*p[i];
           stoc.insert(make_pair(*&p[i],true));
           cout<<"\n";
        }

        delete []p;

    }


    void afisare(ostream &out){
        typename set<pair<t* ,bool> >::iterator itr;
        out<<"\nIn stoc se gasesc "<<numarStoc<<" obiecte:";
        for (itr = stoc.begin(); itr != stoc.end(); ++itr) {
            out << *(itr->first)<<endl;
            out <<"Nou: "<<itr->second<<endl;
            out<<"--------------------------\n";
        }

        out<<"\nS-au vandut "<<numarVandut<<" obiecte:";
        for (itr = vandut.begin(); itr != vandut.end(); ++itr) {
            out <<*(itr->first)<<endl;
            out <<"Nou: "<<itr->second<<endl;
            out <<"--------------------------\n";
        }
    }

    friend istream& operator >>(istream &in, Vanzare <t> &vanzare){
        vanzare.citire(in);
        return in;
    }

    friend ostream& operator <<(ostream &out, Vanzare<t> &vanzare){
        vanzare.afisare(out);
        return out;
    }

   ~Vanzare(){};
};

///---------------------------------------------------


template <> class Vanzare <Monovolum>
{
    int numarStoc;
    int numarVandut;
    set<pair<Monovolum* ,bool> > stoc;
    set<pair<Monovolum* ,bool> > vandut;

 public:
    Vanzare(int numarStoc=0,int numarVandut=0, set<pair<Monovolum*,bool> > p=set<pair<Monovolum*,bool> >(), set<pair<Monovolum*,bool> > q=set<pair<Monovolum*,bool> >()){
        typename set<pair<Monovolum* ,bool> >::iterator itr;
        this->numarStoc=numarStoc;
        this->numarVandut=numarVandut;

        for ( itr = p.begin(); itr != p.end(); ++itr)
            stoc.insert(make_pair(itr->first,itr->second));
        for ( itr = q.begin(); itr != q.end(); ++itr)
            vandut.insert(make_pair(itr->first,itr->second));
    }

    int get_numarStoc()const{return this->numarStoc;}
    int get_numarVandut()const{return this->numarVandut;}

    void cumpara_obiect(){
        if(numarStoc==0)
            cout<<"Nu exista niciun monovolum pe stoc.\n";
        else{
            int i;
            string luna;
            typename set<pair<Monovolum* ,bool> >::iterator itr;

            while(true){
                try{
                    cout<<"Introduceti luna in care doriti sa cumparati monovolumul: ";
                    cin>>luna;
                    if(luna!="ianuarie" && luna!="februarie" && luna!="martie" && luna!="aprilie" && luna!="mai" &&
                       luna!="iunie" && luna!="iulie" && luna!="august" && luna!="septembrie" && luna!="octombrie" &&
                       luna!="noiembrie" && luna!="decembrie" )
                        throw 1;
                    else
                        break;
                }
                catch(int a){
                    cout<<"Nu ati introdus o luna valida.\n";
                }
            }

            cout<<"\nPuteti cumpara unul din urmatoarele monovolume: ";

            for (itr = stoc.begin(); itr != stoc.end(); ++itr) {
                cout << *(itr->first)<<endl;
                cout <<"Nou: "<<itr->second<<endl;
                if(!itr->second && (luna=="iunie" || luna=="iulie" || luna=="august")){
                    cout<<"Discount SH: "<<2020-itr->first->get_an_fabricatie()<<"%"<<endl;
                    cout<<"Discount promotional:10%";
                }
                cout<<"\n--------------------------\n";
            }
            while(true){
              cout<<"Introduceti pozitia monovolumului pe care doriti sa il cumparati: ";
              cin>>i;
              try{
                 if(i<=0 || i>numarStoc)
                    throw 1;
                 else
                    break;
                }
              catch(int a){
                 cout<<"Puteti cumpara unul dintre cele "<<numarStoc<<" monovolume din stoc\n";
              }
            }


            itr=stoc.begin();
            while(i-1){
               itr++;
               i--;
            }

            cout<<"Ati cumparat monovolumul:\n";
            cout<<*(itr->first);
            cout <<"\nNou: "<<itr->second<<endl;

            vandut.insert(make_pair(itr->first,itr->second));
            stoc.erase(itr);


            numarStoc--;
            numarVandut++;
        }
    }


    void citire(istream &in){
        int nou;
        int nrstoc;

        while(true){
            try{
                cout<<"Introduceti numarul de monovolume pe care doriti sa le adaugati in stoc: ";
                in>>nrstoc;
                if(nrstoc<0)
                    throw 1;
                break;
            }
            catch(int i){
                cout<<"Puteti adauga un numar >=0 de monovolume in stoc.\n";
            }
        }

        this->numarStoc=this->numarStoc+nrstoc;

        Monovolum **p;
        p=new Monovolum*[nrstoc];

        cout<<"Introduceti monovolumele in stoc: \n";
        for(int i=0;i<nrstoc;i++){
            p[i]=new Monovolum;
            in>>*p[i];
            while(true){
                try{
                    cout<<"Nou(0/1): ";
                    in>>nou;
                    if(nou!=0 && nou!=1)
                        throw 1;
                    break;
                }
                catch(int a){
                }
            }
            if(nou==0)
                stoc.insert(make_pair(*&p[i],false));
            else
                stoc.insert(make_pair(*&p[i],true));
            cout<<"\n";
        }

        delete []p;

    }


    void afisare(ostream &out){
        typename set<pair<Monovolum* ,bool> >::iterator itr;
        out<<"\nIn stoc se gasesc "<<numarStoc<<" obiecte:";
        for (itr = stoc.begin(); itr != stoc.end(); ++itr) {
            out << *(itr->first)<<endl;
            out <<"Nou: "<<itr->second<<endl;
            if(!itr->second)
                out<<"Discount SH: "<<2020-itr->first->get_an_fabricatie()<<endl;
            out<<"--------------------------\n";
        }

        out<<"\nS-au vandut "<<numarVandut<<" obiecte:";
        for (itr = vandut.begin(); itr != vandut.end(); ++itr) {
            out <<*(itr->first)<<endl;
            out <<"Nou: "<<itr->second<<endl;
            if(!itr->second)
                out<<"Discount SH: "<<2020-itr->first->get_an_fabricatie()<<endl;
            out <<"--------------------------\n";
        }
    }

    friend istream& operator >>(istream &in, Vanzare <Monovolum> &vanzare){
        vanzare.citire(in);
        return in;
    }

    friend ostream& operator <<(ostream &out, Vanzare<Monovolum> &vanzare){
        vanzare.afisare(out);
        return out;
    }

   ~Vanzare(){};

};

///---------------------------------------------------


void tip(Automobil *&p, int &i, set<pair<Automobil* ,bool> > &l) {
        string s;
        while(true){
            cout<<"\nIntroduceti tipul automobilului "<<i+1<<": ";
            cin>>s;
            try{
                if(s=="automobil"){
                    p=new Automobil;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                if(s=="masina"){
                    p=new Masina;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                    }

                if(s=="mini"){
                    p=new Mini;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                if(s=="mica"){
                    p=new Mica;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                if(s=="compacta"){
                    p=new Compacta;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                if(s=="hatchback"){
                    p=new Hatchback;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                if(s=="combi"){
                    p=new Combi;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                if(s=="sedan"){
                    p=new Sedan;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                if(s=="monovolum"){
                    p=new Monovolum;
                    cin>>*p;
                    l.insert(make_pair(*&p,true));
                    i++;
                    break;
                }

                throw 1;
            }

            catch (bad_alloc var)
            {
                cout << "Allocation Failure\n";
                exit(EXIT_FAILURE);
            }
            catch(int j)
            {
                cout<<"Nu ati introdus un tip valid. Incercati automobil/masina/mini/mica/compacta/hatchback/combi/sedan/monovolum.\n ";
            }
        }
    }


void meniu(){
    cout <<endl<<"\n====== PARC AUTO =======" << endl
         << endl<<"-------- MENIU ---------" << endl
         << "1.  Citeste informatii despre automobilele care se pot comanda" << endl
         << "2.  Afiseaza automobilele care se pot comanda"<<endl
         << "3.  Vanazare - template ( Automobil )"<<endl
         << "4.  Vanazare - template ( Masina )"<<endl
         << "5.  Vanazare - template ( Mini )"<<endl
         << "6.  Vanazare - template ( Mica )"<<endl
         << "7.  Vanazare - template ( Compacta )"<<endl
         << "8.  Vanazare - template ( Hatchback )"<<endl
         << "9.  Vanazare - template ( Combi)"<<endl
         << "10. Vanazare - template ( Sedan )"<<endl
         << "11. Vanazare - template-Specializare ( Monovolum )"<<endl
         << "12. Afiseaza situatia unei vanzari"<<endl
         << "13. Cumpara un automobil"<<endl
         << "14. Afiseaza o statistica a Parcului Auto" << endl
         << "15. Sterge continutul consolei" << endl
         << "16. Exit\n\n" << endl
         << "Insereaza actiune: ";
}

///---------------------------------------------------
///---------------------------------------------------
///---------------------------------------------------



int main()
{

    set<pair<Automobil* ,bool> > ParcAuto;
    set<pair<Automobil* ,bool> >::iterator itr;
    int n=0,choice;

    Automobil **v;
    Vanzare <Automobil> automobil;
    Vanzare <Masina> masina;
    Vanzare <Mini> mini;
    Vanzare <Mica> mica;
    Vanzare <Compacta> compacta;
    Vanzare <Hatchback> hatchback;
    Vanzare <Combi> combi;
    Vanzare <Sedan> sedan;
    Vanzare <Monovolum> monovolum;



    do{
          meniu();
          cin>>choice;
          switch(choice){
            case 1:
                cout<<"Numar de masini: ";
                cin>>n;
                v=new Automobil*[n];
                for(int i=0;i<n;)
                    tip(v[i],i,ParcAuto);
                cout<<"\n=============================\n";
                break;

            case 2:
                for (itr = ParcAuto.begin(); itr != ParcAuto.end(); ++itr) {
                    cout <<"\nTip automobil: "<<itr->first->model_masina();
                    cout << *(itr->first)<<endl;
                    cout <<"Nou: "<<itr->second<<endl;
                    cout<<"\n=============================\n";
                }
                break;

            case 3:
                    cin>>automobil;
                    cout<<automobil;
                    cout<<"\n=============================\n";
                    break;

            case 4:
                    cin>>masina;
                    cout<<masina;
                    cout<<"\n=============================\n";
                    break;

            case 5:
                    cin>>mini;
                    cout<<mini;
                    cout<<"\n=============================\n";
                    break;

            case 6:
                    cin>>mica;
                    cout<<mica;
                    cout<<"\n=============================\n";
                    break;

            case 7:
                    cin>>compacta;
                    cout<<compacta;
                    cout<<"\n=============================\n";
                    break;

            case 8:
                    cin>>hatchback;
                    cout<<hatchback;
                    cout<<"\n=============================\n";
                    break;

            case 9:
                    cin>>combi;
                    cout<<combi;
                    cout<<"\n=============================\n";
                    break;

            case 10:
                    cin>>sedan;
                    cout<<sedan;
                    cout<<"\n=============================\n";
                    break;

            case 11:
                    cin>>monovolum;
                    cout<<monovolum;
                    cout<<"\n=============================\n";
                    break;

            case 12:{
                 string s;

                 while(true)
                 {
                     try{
                         cout<<"Doriti sa vedeti vanzarea pentru: ";
                         cin>>s;
                         if(s=="automobil"){
                            cout<<automobil;
                            break;
                         }
                          if(s=="masina"){
                            cout<<masina;
                            break;
                         }
                          if(s=="mini"){
                            cout<<mini;
                            break;
                         }
                          if(s=="mica"){
                            cout<<mica;
                            break;
                         }
                          if(s=="compacta"){
                            cout<<compacta;
                            break;
                         }
                          if(s=="hatchback"){
                            cout<<hatchback;
                            break;
                         }
                          if(s=="combi"){
                            cout<<combi;
                            break;
                         }
                          if(s=="sedan"){
                            cout<<sedan;
                            break;
                         }
                          if(s=="monovolum"){
                            cout<<monovolum;
                            break;
                         }

                         throw 1;
                     }
                    catch(int i){
                        cout<<"Puteti alege din urmatoarele tipuri: automobil/masina/mini/mica/compacta/hatchback/combi/sedan/monovolum.\n";
                    }
                 }
                break;
                }

            case 13:{
                 string s;

                 while(true)
                 {
                     try{
                         cout<<"Tipul automobilului dorit: ";
                         cin>>s;
                         if(s=="automobil"){
                            automobil.cumpara_obiect();
                            break;
                         }
                          if(s=="masina"){
                            masina.cumpara_obiect();
                            break;
                         }
                          if(s=="mini"){
                            mini.cumpara_obiect();
                            break;
                         }
                          if(s=="mica"){
                            mica.cumpara_obiect();
                            break;
                         }
                          if(s=="compacta"){
                            compacta.cumpara_obiect();
                            break;
                         }
                          if(s=="hatchback"){
                            hatchback.cumpara_obiect();
                            break;
                         }
                          if(s=="combi"){
                            combi.cumpara_obiect();
                            break;
                         }
                          if(s=="sedan"){
                            sedan.cumpara_obiect();
                            break;
                         }
                          if(s=="monovolum"){
                            monovolum.cumpara_obiect();
                            break;
                         }

                         throw 1;
                     }
                    catch(int i){
                        cout<<"Puteti alege din urmatoarele tipuri: automobil/masina/mini/mica/compacta/hatchback/combi/sedan/monovolum.\n";
                    }
                 }
                break;
                }
            case 14:
                {int nrAutomobile,nrMasini,nrMini,nrMici,nrCompacte,nrHatchbacks,nrCombi,nrSedans,nrMonovolume,S;
                 nrAutomobile=nrMasini=nrMini=nrMici=nrCompacte=nrHatchbacks=nrCombi=nrSedans=nrMonovolume=0;
                 for(int i=0;i<n;i++){
                    Automobil *p1=dynamic_cast<Automobil*>(v[i]);
                    Masina *p2=dynamic_cast<Masina*>(v[i]);
                    Mini *p3=dynamic_cast<Mini*>(v[i]);
                    Mica *p4=dynamic_cast<Mica*>(v[i]);
                    Compacta *p5=dynamic_cast<Compacta*>(v[i]);
                    Hatchback *p6=dynamic_cast<Hatchback*>(v[i]);
                    Combi *p7=dynamic_cast<Combi*>(v[i]);
                    Sedan *p8=dynamic_cast<Sedan*>(v[i]);
                    Monovolum *p9=dynamic_cast<Monovolum*>(v[i]);

                    if(p1) nrAutomobile++;
                    if(p2) nrMasini++;
                    if(p3) nrMini++;
                    if(p4) nrMici++;
                    if(p5) nrCompacte++;
                    if(p6) nrHatchbacks++;
                    if(p7) nrCombi++;
                    if(p8) nrSedans++;
                    if(p9) nrMonovolume++;
                }

                cout<<"\nNumar automobile disponibile pentru comanda: "<<n;
                cout<<"\nDintre care: Automobile: "<<nrAutomobile;
                cout<<"\n             Masini: "<<nrMasini;
                cout<<"\n             Mini: "<<nrMini;
                cout<<"\n             Mici: "<<nrMici;
                cout<<"\n             Compacte: "<<nrCompacte;
                cout<<"\n             Hatchback: "<<nrHatchbacks;
                cout<<"\n             Combi: "<<nrCombi;
                cout<<"\n             Sedan: "<<nrSedans;
                cout<<"\n             Monovolume: "<<nrMonovolume;



                S=automobil.get_numarStoc()+masina.get_numarStoc()+mini.get_numarStoc()+mica.get_numarStoc()+compacta.get_numarStoc()
                    +hatchback.get_numarStoc()+combi.get_numarStoc()+sedan.get_numarStoc()+monovolum.get_numarStoc();
                cout<<"\n\nNumar automobile pe stoc: "<<S;
                S=automobil.get_numarVandut()+masina.get_numarVandut()+mini.get_numarVandut()+mica.get_numarVandut()+compacta.get_numarVandut()
                    +hatchback.get_numarVandut()+combi.get_numarVandut()+sedan.get_numarVandut()+monovolum.get_numarVandut();
                cout<<"\nNumar automobile vandute: "<<S<<endl;

                cout<<"\nDintre care: Automobile- Stoc: "<<automobil.get_numarStoc();
                cout<<"\n                       - Vandute: "<<automobil.get_numarVandut();
                cout<<"\nDintre care: Masini    - Stoc: "<<masina.get_numarStoc();
                cout<<"\n                       - Vandute: "<<masina.get_numarVandut();
                cout<<"\nDintre care: Mini      - Stoc: "<<mini.get_numarStoc();
                cout<<"\n                       - Vandute: "<<mini.get_numarVandut();
                cout<<"\nDintre care: Mica      - Stoc: "<<mica.get_numarStoc();
                cout<<"\n                       - Vandute: "<<mica.get_numarVandut();
                cout<<"\nDintre care: Compacte  - Stoc: "<<compacta.get_numarStoc();
                cout<<"\n                       - Vandute: "<<compacta.get_numarVandut();
                cout<<"\nDintre care: Hatchback - Stoc: "<<hatchback.get_numarStoc();
                cout<<"\n                       - Vandute: "<<hatchback.get_numarVandut();
                cout<<"\nDintre care: Combi     - Stoc: "<<combi.get_numarStoc();
                cout<<"\n                       - Vandute: "<<combi.get_numarVandut();
                cout<<"\nDintre care: Sedan     - Stoc: "<<sedan.get_numarStoc();
                cout<<"\n                       - Vandute: "<<sedan.get_numarVandut();
                cout<<"\nDintre care: Monovolume- Stoc: "<<monovolum.get_numarStoc();
                cout<<"\n                       - Vandute: "<<monovolum.get_numarVandut();
                cout<<endl;


                break;
                }
            case 15:
                system("cls");
                break;
            case 16:
                break;
            default:
                cout<<"Actiune invalida"<<endl;
                    break;
               }
  }while(choice!=16);

return 0;
}

