using namespace std;
#include <iostream>
#include "UserMenu.h"
#include <fstream>
#include <string>
#include "menu.h"
#include <windows.h>
#include <sstream>
#include <time.h>

struct Users{
string login ,parole,email; int telefons;
}users[1000];

void read(string login, string parole){
    ifstream fin ("users.txt");
    for (int i =0;i<1000;i++){
        fin>>users[i].login>>users[i].parole;
    }
}

void registresana(){//lietotaja regitresana un parbaude uz lietotaja sakrisanu
string login, parole, email, dzimums, s;
int telefons, reizes, error;
    do{
        error=0;
        reizes=0;
        cout<<"Ievadiet login (prieks parbaudes uz lietotaju sakrisanu)"<<endl;
        cin>>login;

        ifstream file("login.txt");
        while(getline(file,s)){
            if(login==s){
            reizes++;
            }
        }
        file.close();

        if(reizes>0){
            error=1;
            cout<<"Tads lietotajs jau ir!"<<endl;
        }
    }while(error==1);

    fstream fout1("login.txt",ios::app);
    fout1<<login<<endl;
    fout1.close();
    cout<<"Ievadiet paroli"<<endl;
    cin>>parole;
    cout<<"Ievadiet e pastu "<<endl;
    cin>>email;
    cout<<"Ievadiet telefonu "<<endl;
    cin>>telefons;
    cout<<"Ievadiet savu dzimumu"<<endl;
    cin>>dzimums;

    fstream fout("users.txt",ios::app);
    fout<<login<<" "<<parole<<" "<<email<<" "<<" (+371)"<<telefons<<" "<<dzimums<<endl;
    system("cls");
    cout<<"Jus esat  veiksmigi ieregistrets sistema!"<<endl;
}

void userMenu(){
char  nomaspunkts[21],marka[21],klase[21],laiks[21],  s[1024], vards[21], uzvards[21];
int izvele, izvele2, izvele3, izvele4=0;
string login; string parole,  tell,line;
    system("cls");
    cout<<"Ievadiet login "<<endl;//paroles un logina ievadisana prieks ieesanas UserMenu
    cin>>login;
    cout<<"Ievadiet paroli"<<endl;
    cin>>parole;
    read(login, parole);
    system("cls");
    bool flag=true;
    for(int i=0;i<1000;i++){
        if (login==users[i].login && parole==users[i].parole){
            system("cls");
            cout<<"Jus iegajat ka "<<login<<" Lietotajs, Jums ir piejejamas sadas funkcijas:"<<endl;
        do{
            sakums: ;
            printMenuUserizvele();//UserMenu darbibu  izvelne
            cin>>izvele;
            switch(izvele){
                case 1: {
                    do{
                        cout<<"Ievadiet nomas punktu"<<endl;//meklesana pec nomas punkta meklesanas rezultatu izvade rezervacijas izveide(tabula)
                        cin>>nomaspunkts;

                        ifstream file("auto.txt");
                        while(file.getline(s,1024)){
                            if(strstr(s, nomaspunkts))
                                cout << s << endl;
                        }
                        file.close();

                        izvele4==0;
                        piekrisanaUserMenu();
                        cin>>izvele3;
                        if(izvele3!=1)
                            goto sakums;
                        else
                            rezervacija();
                        cout<<"Nav kludu? Ja ir tad atkartojiet datu ievadisanu(ja-1,ne-0)"<<endl;
                        cin>>izvele4;
                    }while(izvele4==1);
                    cout<<"Tabula ir izveidota!"<<endl;
                    break;
                }

                case 2:{
                    do{
                        cout<<"Ievadi auto marku"<<endl;//meklesana pec auto markas meklesanas rezultatu izvade rezervacijas izveide(tabula)
                        cin>>marka;
                        ifstream file("auto.txt");

                        while(file.getline(s,1024)){
                            if(strstr(s, marka))
                                cout << s << endl;
                        }
                        file.close();

                        izvele4==0;
                        piekrisanaUserMenu();
                        cin>>izvele3;
                        if(izvele3!=1)
                            goto sakums;
                        else
                            rezervacija();
                        cout<<"Nav kludu? Ja ir tad atkartojiet datu ievadisanu(ja-1,ne-0)"<<endl;
                        cin>>izvele4;
                    }while(izvele4==1);
                    cout<<"Tabula ir izveidota!"<<endl;
                    break;
                }

                case 3:{
                    do{
                        cout<<"Ievadi auto klasi"<<endl;//meklesana pec auto klases meklesanas rezultatu izvade rezervacijas izveide(tabula)
                        cin>>klase;

                        ifstream file ("auto.txt");
                        while (file.getline(s,1024)){
                            if(strstr(s,klase))
                                cout<<s<<endl;
                        }
                        file.close();

                        izvele4==0;
                        piekrisanaUserMenu();
                        cin>>izvele3;
                        if(izvele3!=1)
                            goto sakums;
                        else
                            izvele4==0;

                        rezervacija();
                        cout<<"Nav kludu? Ja ir tad atkartojiet datu ievadisanu(ja-1,ne-0)"<<endl;
                        cin>>izvele4;
                    }while(izvele4==1);
                        cout<<"Tabula ir izveidota!"<<endl;
                        break;
                }

                case 4:{
                    do{
                        cout<<"Ievadi auto brivo laiku(ir  vai nav ) "<<endl;//meklesana pec briva laika meklesanas rezultatu izvade rezervacijas izveide(tabula)
                        cin>>laiks;

                        ifstream file ("auto.txt");
                        while (file.getline(s,1024)){
                            if(strstr(s,laiks))
                                cout<<s<<endl;
                        }
                        file.close();

                        izvele4==0;
                        piekrisanaUserMenu();
                        cin>>izvele3;
                        if(izvele3!=1)
                            goto sakums;
                        else
                            rezervacija();
                        cout<<"Nav kludu? Ja ir tad atkartojiet datu ievadisanu(ja-1,ne-0)"<<endl;
                        cin>>izvele4;
                    }while(izvele4==1);
                    cout<<"Tabula ir izveidota!"<<endl;
                    break;
                }

                case 5:{
                    system("cls");//iziesana no AdminMenu
                break;
                }

                case 6:{//rezervacijas meklesana
                    cout<<"Ievadiet savu vardu un uzvardu"<<endl;
                    cin>>vards>>uzvards;
                    cout<<"Jusu rezervacija(-as):"<<endl;

                    ifstream file("rezervacija.txt");
                        while(file.getline(s,1024)){
                            if(strstr(s,vards))
                                if(strstr(s,uzvards))
                                    cout << s << endl;
                        }
                        file.close();
                    break;
                }

                case 7:{//informacias par tavu profilu izvade
                    cout<<"Ludzu Ievadiet savu telefonu(drosibas jautajums)"<<endl;
                    cin>>tell;
                    cout<<"Informacija par savu profilu:"<<endl;

                    ifstream file("users.txt");
                    while(getline(file,line)){
                        if(line.find("(+371)"+tell)!=string::npos)
                            cout << line << endl;
                    }
                    file.close();
                    break;
                }
        }
        cout<<"Gribat kaut ko vel izdarit?(ja-1,ne-0)"<<endl;
        cin>>izvele2;
        system("cls");
        }while(izvele2==1);

        flag=false;
        system("cls");
        }
    }
    if (flag==true){
            system("cls");
        cout<<"Nepareizs login vai parole "<<endl;

    }

}

void rezervacija(){
string marka, modelis,vards_uzvards,  klase, nomaspunkts,  teksts, teksts2;
int y, m, d, error=0, y1, m1, d1, datums1, datums2, id, id_line, h1, h2,  gads,  izvele5;
double cena,stundaslikme;
cout<<"Rezervacijas taisisana: ievadiet visus jums vajadzigus datus prieks rezervesanas"<<endl;//rezervacijas taisisana(informacijas ievadisana)
    fflush(stdin);
    cout<<"Ievadi auto marku:"<<endl;
    getline(cin,marka);

    fflush(stdin);
    cout<<"Ievadi auto modeli:"<<endl;
    getline(cin,modelis);

    cout<<"Ievadi Auto gadu  "<<endl;
    cin>>gads;

    fflush(stdin);
    cout<<"Ievadi Auto klasi :"<<endl;
    getline(cin,klase);

    fflush(stdin);
    cout<<"Ievadi auto nomas stundas likmi"<<endl;
    cin>>stundaslikme;

    fflush(stdin);
    cout<<"Ievadi nomasPunktu"<<endl;
    getline(cin,nomaspunkts);

    fflush(stdin);
    cout<<"Ievadi savu vardu un uzvardu"<<endl;
    getline(cin,vards_uzvards);

    id_line=0;
    ifstream file("rezervacija.txt");
    while(getline(file,teksts)){
        id_line++;
    }
    file.close();
    id= id_line;

    do{
        do{
            sakums11:  ;
                time_t rawtime;//tagadeja datuma izvade uz ekrana
                struct tm *timeinfo;
                time ( &rawtime );
                timeinfo = localtime ( &rawtime );
                printf ( "Current local time and date: %s", asctime (timeinfo) );
                error=0;
                cout<<"Ievadiet sakum datumu:gadu,menesi un dienu(forma:y:m:d)"<<endl;
                cin>>y>>m>>d;
                if(y<=0){//pirma datuma parbaude uz pareizibu
                    cout<<"Jus nepareizi ievadijat gadu skaitu "<<endl;
                    error=1;
                    goto beigas;
                }else{
                    if(m>=1 && m<=12){
                    }else{
                        cout<<"Jus nepareizi ievadijat menesu skaitu"<<endl;
                        error=1;
                        goto beigas;
                    }
                }
                if(m!=2){
                        goto sakums;
                }else
                    if(y%4==0 && d<=29){
                        goto beigas;
                    }else
                        if(d<=28 && m==2){
                            goto beigas;
                        }else{
                            cout<<"Jus nepareizi ievadijat dienas skaitu"<<endl;
                            error=1;
                            goto beigas;
                        }

                sakums: ;
                if(m>=1 && m>=7){
                    goto sakums1;
                }else
                    if(m%2==0 && d<=30){
                        goto beigas;
                    }else
                        if(m%2!=0 && d<=31){
                            goto beigas;
                        }else{
                            cout<<"Jus nepareizi ievadijat dienas skaitu"<<endl;
                            error=1;
                            goto beigas;
                        }

                sakums1: ;
                if(m%2==0 && d<=31){
                    goto beigas;
                }else
                    if(m%2!=0 && d<=30){
                        goto beigas;
                    }else{
                        cout<<"Jus nepareizi ievadijat dienas skaitu"<<endl;
                        error=1;
                    }
                beigas: ;
        }while(error==1);
        cout<<"Datuma parbaude:"<<endl;

        if(y<2018){//prima datuma parbaude uz tagadejo datumu
            cout<<"Datums ir par mazu!(salidzinot ar tagadejo datumu!"<<endl;
            error=1;
            goto beigas3;
        }else
            if(y==2018)
                if(m<=1){
                    cout<<"Datums ir par mazu!(salidzinot ar tagadejo datumu!"<<endl;
                    error=1;
                    goto beigas3;
                }else
                    if(m!=2){
                    }else
                        if(d<=27){
                            cout<<"Datums ir par mazu!(salidzinot ar tagadejo datumu!"<<endl;
                            error=1;
                            goto beigas3;
                        }
        beigas3: ;
    }while(error==1);
    cout<<"Viss ir ok!"<<endl;
        do{
            error=0;
            do{
                error=0;
                cout<<"Lidz kadam datumam jus gribat rezervet auto(y:m:d)?"<<endl;
                cout<<"Lielakais nemsanas termins: ne vairak  par gadu(skaitas no nemsanas briza"<<endl;
                cin>>y1>>m1>>d1;

                if(y1<=0){//otra datuma parbaude uz pareizibu
                    cout<<"Jus nepareizi ievadijat gadu skaitu "<<endl;
                    error=1;
                    goto beigas1;
                }
                    if(m1>=1 && m1<=12){
                    }else{
                        cout<<"Jus nepareizi ievadijat menesu skaitu"<<endl;
                        error=1;
                        goto beigas1;
                    }
                    if(m1!=2){
                        goto sakums2;
                    }else
                        if(y1%4==0 && d1<=29){
                            goto beigas1;
                        }else
                            if(d1<=28 && m1==2){
                                goto beigas1;
                            }else{
                                cout<<"Jus nepareizi ievadijat dienas skaitu"<<endl;
                                error=1;
                                goto beigas1;
                            }

            sakums2: ;
                if(m1>=1 && m1>=7){
                    goto sakums3;
                }else
                    if(m1%2==0 && d1<=30){
                        goto beigas1;
                    }else
                        if(m1%2!=0 && d1<=31){
                            goto beigas1;
                        }else{
                            cout<<"Jus nepareizi ievadijat dienas skaitu"<<endl;
                            error=1;
                            goto beigas1;
                        }
            sakums3: ;

            if(m1%2==0 && d1<=31){
                goto beigas1;
            }else
                if(m1%2!=0 && d1<=30){
                    goto beigas1;
                }else{
                    cout<<"Jus nepareizi ievadijat dienas skaitu"<<endl;
                    error=1;
                }
            beigas1: ;
            }while(error==1);

            error=0;
            cout<<"Notiek datumu parbaude..."<<endl;
            if(y1-y<0){//divu datumu parbaude uz to vai otrais datums ir mazaks
                cout<<"Otrais datums ir mazaks!"<<endl;
                goto sakums11 ;
            }else
                if(m1<m){
                    cout<<"Otrais datums ir mazaks!"<<endl;
                    goto sakums11 ;
                }else
                    if(d1<d){
                        cout<<"Otrais datums ir mazaks!"<<endl;
                        goto sakums11 ;
                    }else
                        if(y==y1 && m==m1 && d==d1){//parbaude uz terminu(vai vins nav lielkas neka 1 gads)
                            goto beigas2;
                        }else
                            if(y1-y>1){
                                cout<<"Ne vairak ka uz gadu!"<<endl;
                                error=1;
                                goto beigas2;
                                }if(y1-y==0){}
                                else
                                    if(m1>m){
                                        cout<<"Ne vairak ka uz gadu!"<<endl;
                                        error=1;
                                        goto beigas2;
                                    }else
                                        if(d1>d){
                                            cout<<"Ne vairak ka uz gadu!"<<endl;
                                            error=1;}
                                            goto beigas2;
                                            beigas2: ;
        }while(error==1);
        cout<<"Viss ir ok!"<<endl;

        int  jdn, jdn1,  r;//datumu dienu skaitu kopiga atrasana un pec tam datumu starpibas atrasan atrasana
            int a=(14-m)/12;
            int yy=y+4800-a;
            int mm=m+12*a-3;

            jdn=d+(153*mm+2)/5+365*yy+yy/4-yy/100+yy/400-32045;

            int a1=(14-m1)/12;
            int yy1=y1+4800-a1;
            int mm1=m1+12*a1-3;
            jdn1=d1+(153*mm1+2)/5+365*yy1+yy1/4-yy1/100+yy1/400-32045;
            r=(jdn1-jdn);

            do{
                error=0;
                cout<<"Papildus:Ievadiet stundu skaitu uz cikiem jus gribat sanemt masinu un cikos atdot"<<endl;
                cin>>h1>>h2;
                if(h1<25 && h2<25 && h1>0 && h2>0){//stundas ievade un parbaude
                    if(r!=0){
                        goto beigas5;
                    }else
                        if(h1>=h2){
                            cout<<"Error!"<<endl;
                                error=1;}
                }else{
                    cout<<"Error!"<<endl;
                }
                beigas5: ;
            }while(error==1);

            if(r==0){
                cena=(h2-h1)*stundaslikme;
            }else{
                int data1=24-h1;
                    cena=((r-1)*24+h2+data1)*stundaslikme;
            }

            fstream fout("datums1.txt",ios::out);
            fout<<y<<":"<<m<<":"<<d<<endl;
            fout.close();

            fstream fout1("datums2.txt",ios::out);
            fout1<<y1<<":"<<m1<<":"<<d1<<endl;
            fout1.close();


            string gads1,datums11, datums22,cena1,  id1, h11, h22;//visu ievaditu datu(tikai int) konvertesana uz string prieks tabulas

            ostringstream temp;
            temp<<gads; gads1=temp.str();
            temp.str(" "); temp.clear();

            temp<<datums1; datums11=temp.str();
            temp.str(" "); temp.clear();

            temp<<datums2; datums22=temp.str();
            temp.str(" "); temp.clear();


            temp<<cena; cena1=temp.str();
            temp.str(" "); temp.clear();

            temp<<h1; h11=temp.str();
            temp.str(" "); temp.clear();

            temp<<h2; h22=temp.str();
            temp.str(" "); temp.clear();

            ifstream in ("datums1.txt");
            getline(in, datums11);
            in.close();

            ifstream in1 ("datums2.txt");
            getline(in1, datums22);
            in1.close();

            fstream fout2("rezervacija.txt",ios::app);//ierakstisana ieks rezervacijas
            fout2<<id+1<<".auto"<<"||"<<marka<<"||"<<modelis<<"||"<<gads<<"||"<<klase<<"||"<<stundaslikme<<"ˆ/h"<<"||"<<nomaspunkts<<"||"<<"||"<<cena<<"eiro"<<"||"<<vards_uzvards<<"||"<<"sakum datums(stundas): "<<datums11 <<" "<< h11<<"h"<<"||"<<"beigas datums(stundas): "<<datums22 <<" "<<h22<<"h"<<endl;
            fout2.close();
            id++;

            temp<<id;
            id1=temp.str();
            temp.str(" "); temp.clear();
            drukatRezervaciju(vards_uzvards,  marka, modelis,  nomaspunkts, datums11,  datums22,  gads1, id1, cena1, h11, h22);
}

void drukatRezervaciju(string vards_uzvards, string marka, string modelis, string nomaspunkts, string datums11, string datums22, string gads1, string id1,string cena1, string h11, string h22){
    ofstream htmlfails;
	htmlfails.open("failss.html");
                                       //rezervacijas izdrukasana html dokumenta formata
	htmlfails << "<!DOCTYPE html>" << endl;
	htmlfails << "<html>" << endl;
	htmlfails << "<head>" << endl;
	htmlfails << "<style>" << endl;
	htmlfails << "table, th, td {" << endl;
	htmlfails << "    border: 1px solid black;" << endl;
	htmlfails << "    border-collapse: collapse;" << endl;
	htmlfails << "}" << endl;
	htmlfails << "</style>" << endl;
	htmlfails << "</head>" << endl;
	htmlfails << "<body>" << endl;
	htmlfails << "<table style=\"width:500px\">" << endl;
	htmlfails << "  <tr>" << endl;
	htmlfails << "    <th></th>" << endl;
	htmlfails << "    <th></th> " << endl;
	htmlfails << "  </tr>" << endl;
	htmlfails << "  <tr>" << endl;
	htmlfails << "    <td>" << vards_uzvards << "</td>" << endl;
	htmlfails << "    <td>" <<"Rez. Nr. "<< id1 << "</td>" << endl;
	htmlfails << "  </tr>" << endl;
	htmlfails << "  <tr>" << endl;
	htmlfails << "    <td>Nomas punkts</td>" << endl;
	htmlfails << "    <td>" << nomaspunkts << "</td>" << endl;
	htmlfails << "  </tr>" << endl;
	htmlfails << "  <tr>" << endl;
	htmlfails << "    <td>Marka</td>" << endl;
	htmlfails << "    <td>" << marka << "</td>" << endl;
	htmlfails << "  </tr>" << endl;
	htmlfails << "  <tr>" << endl;
	htmlfails << "	<td>Modelis</td>" << endl;
	htmlfails << "	<td>" << modelis << "</td>" << endl;
	htmlfails << "  </tr>" << endl;
	htmlfails << "  <tr>" << endl;
	htmlfails << "	<td>Gads</td>" << endl;
	htmlfails << "	<td>" << gads1<< "</td>" << endl;
	htmlfails << "  </tr>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "	<td>Sakums</td>" << endl;
	htmlfails << "	<td>" << datums11<<" "<<h11<<" h" "</td>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "	<td>Beigas</td>" << endl;
	htmlfails << "	<td>" << datums22<<" "<<h22<<" h" "</td>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "	<td>Cena</td>" << endl;
	htmlfails << "	<td>" << cena1<<" eiro" "</td>" << endl;
	htmlfails << "  </tr>" << endl;
	htmlfails << "</table>" << endl;
	htmlfails << "</body>" << endl;
	htmlfails << "</html>" << endl;

	htmlfails.close();
}






