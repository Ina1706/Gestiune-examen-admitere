#include <iostream>
#include<string>

using namespace std;

class Student
{
protected:
    string nume;
    int valid;
    int nr_opt;
    int optiuni[5]; //mate 0 info 1 cti 2 id 3
    float taxa;
    char mod_plata;
    string info_plata;
    static int info;
    static int cti;
    static int mate;
    static int id;
    int scutit_taxa;
    float online;
    string motiv;
    int legitimatii[4];
public:
    friend istream&operator>>(istream&i, Student&s);
    void calcul_taxa();
    friend ostream&operator<<(ostream&o, Student s);
    static void get_nr()
    {
      cout<<"mate: "<<Student::mate<<endl;
      cout<<"info: "<<Student::info<<endl;
      cout<<"cti: "<<Student::cti<<endl;
      cout<<"info id: "<<Student::id<<endl;
    }
    int scutire()
    {
        if(taxa==0)
        return 1;
        return 0;
    }
        int tb()
    {
        if(mod_plata=='t')
        return 1;
        return 0;
    }
    int cas()
    {
        if(mod_plata=='c')
        return 1;
        return 0;
    }
    int inval()
    {
        if(valid==0)
            return 1;
        return 0;
    }
    int suma()
    {
        return taxa;
    }

};

int Student::info=0;
int Student::cti=0;
int Student::mate=0;
int Student::id=0;

istream&operator>>(istream&i, Student&s)
{
    cout<<"nume: ";
    cin>>s.nume;
    cout<<"numar domenii:";
    cin>>s.nr_opt;
    char x;
    for(int i=0;i<s.nr_opt;i++)
    {   int ct=0;
        while(ct==0)
    {try{
    cout<<"optiuni: mate-m, info-i, cti-c, id-d ";
    cin>>x;
        if(x!='m' && x!='i' && x!='c' && x!='d')
            throw x;
        if(x=='m')
        {
            s.optiuni[0]=1;
           Student::mate++;
        }
        if(x=='i')
        {
            s.optiuni[1]=1;
            Student::info++;
        }
        if(x=='c')
        {
            s.optiuni[2]=1;
            Student::cti++;
        }
        if(x=='d')
        {
            s.optiuni[3]=1;
            Student::id++;
        }
        ct=1;
    }catch(char){cout<<"caracterul introdus nu este valid, reincercati!"<<endl;}
    }
    }

    cout<<"orfan/copil cadru didactic/olimpic? 0-nu, 1-da"<<endl;
    cin>>s.scutit_taxa;
    cout<<"mod inscriere: 1-online, 0-offline;";
    cin>>s.online;
    int ct=0;
    while(ct==0)
    {try{
    cout<<"modalitate plata taxa? o-online, t-transfer bancar, c-casierie ";
    cin>>s.mod_plata;
    if(s.mod_plata=='c' && s.online==1) throw 1;
    ct=1;}
    catch(int) {cout<<"imposibil; plata se face numai online sau prin transfer bancar; reincercati "<<endl;}}
    if(s.mod_plata=='o')
    {
        cout<<"adresa web a serviciului utilizat:";
        cin>>s.info_plata;
    }
    if(s.mod_plata=='t')
    {
        cout<<"contul facultatii:";
        cin>>s.info_plata;
    }
    if(s.online==1)
    {
        cout<<"dosar valid? 1-da, 0-nu";
        cin>>s.valid;
        if(s.valid==0)
        {
            cout<<"de ce? motivul va fi atasat in mail"<<endl;
            cin>>s.motiv;
        }
    }
    if(s.valid==1)
    {
        if(s.optiuni[0]==1)
            s.legitimatii[0]=Student::mate;
        if(s.optiuni[1]==1)
            s.legitimatii[1]=Student::info;
        if(s.optiuni[2]==1)
            s.legitimatii[2]=Student::cti;
        if(s.optiuni[3]==1)
            s.legitimatii[3]=Student::mate;
    }
    s.calcul_taxa();
    return i;
}

void Student::calcul_taxa()
{

    if(nr_opt==1)
        taxa=200;
    if(nr_opt==2)
        taxa=300;
    if(nr_opt==3)
        taxa=400;
    if(nr_opt==4)
        taxa=500;
    if(scutit_taxa==1)
    {if(nr_opt==1) taxa=0;
        else taxa=taxa-100;
    }
    if(online==1)
    {
      taxa=(taxa/4)*3;
    }
}

ostream&operator<<(ostream&o, Student s)
{
    cout<<"nume "<<s.nume<<endl;
    cout<<"scutit taxa ";
    if(s.scutit_taxa==0)
        cout<<"nu";
    else cout<<"da";
        cout<<endl;
    cout<<"nr optiuni:"<<s.nr_opt;
    cout<<"optiuni: ";
    if(s.optiuni[0]==1) cout<<"mate, ";
    if(s.optiuni[1]==1) cout<<"info, ";
    if(s.optiuni[2]==1) cout<<"cti, ";
    if(s.optiuni[3]==1) cout<<"info id, ";
    cout<<endl;
    cout<<"mod plata taxa: ";
    if(s.mod_plata=='o') cout<<"online"<<endl;
    if(s.mod_plata=='t') cout<<"transfer"<<endl;
    if(s.mod_plata=='c') cout<<"casierie"<<endl;
    cout<<"mod inscriere: ";
    if(s.online==1) cout<<"online"<<endl;
    else cout<<"offline"<<endl;
    cout<<"taxa: "<<s.taxa<<endl;
    cout<<"legitimatii: ";
    if(s.optiuni[0]==1)
            cout<<" mate "<<s.legitimatii[0];
        if(s.optiuni[1]==1)
            cout<<" info "<<s.legitimatii[1];
        if(s.optiuni[2]==1)
            cout<<" cti "<<s.legitimatii[2];
        if(s.optiuni[3]==1)
            cout<<" id "<<s.legitimatii[3];
    cout<<endl<<endl;
    return o;
}

int main()
{
    int nr;
    Student stud[100];
    int nr_stud=0;
    while(nr!=0)
    {
        cout<<"1-citire student, 2-afisare lista studenti, 0-stop"<<endl;
        cin>>nr;
        switch (nr)
            {
                case 1: {cin>>stud[nr_stud]; nr_stud++; break;}
                case 2: {for (int i=0;i<nr_stud; i++) cout<<stud[i]; break;}
            }
    }
    cout<<"inscrieri pt fiecare domeniu: ";
    Student::get_nr();
    cout<<"candidati care au beeficiat de scutire de taxa: ";
    int nr_scutiti=0;
    int nr_tb=0;
    int nr_c=0;
    int inv=0;
    int suma_tot=0;
    for(int i=0;i<nr_stud;i++)
        {nr_scutiti=nr_scutiti+stud[i].scutire();
        nr_tb=nr_tb+stud[i].tb();
        nr_c=nr_c+stud[i].cas();
        inv=inv+stud[i].inval();
        suma_tot=suma_tot+stud[i].suma();
        }
    cout<<nr_scutiti<<endl;
    cout<<"nr candidati care au platit prin transd bancar: "<<nr_tb<<endl;
    cout<<"nr candidati care au platit la casierie: "<<nr_c<<endl;
    cout<<"nr dosare inv: "<<inv<<endl;
    cout<<"suma totala incasata: "<<suma_tot<<endl;
    return 0;

}
