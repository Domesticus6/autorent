using namespace std;
#include <iostream>
#include <fstream>
#include<string>
#include <windows.h>
#include "menu.h"
#include "AdminMenu.h"


void failsAdmin(){
string teksts;
    cout<<"Faila informacija:"<<endl;
    cout<<"--------------------------------------"<<endl;

    ifstream file("auto.txt");//faila informacijas izvadisana uz ekrana,skatoties adminam statistiku
    while(getline(file,teksts)){
        cout<<teksts<<endl;
    }
    file.close();

    cout<<"-------------------------------------"<<endl;
}

void AdminStatistika(){
char text[21],s[1024];
int id_line=0;
    cout<<"Tagad ievadiet kuros autonomas punktos ir pieejamas masinas(ir vai nav)"<<endl;//vajadziga parametra ievade prieks meklesanai statistikai
    cin>>text;
    cout<<"Statistika:"<<endl;
    cout<<"-------------------------------------"<<endl;

    ifstream file("auto.txt");//statistikas izvade
    while(file.getline(s,1024)){
        if(strstr(s, text))
            cout << s << endl;
    }
    file.close();

    cout<<"-------------------------------------"<<endl;
}

void login_admin(){
int parole, izvele2,izvele3, izvele1, gads, id, atkartojums, id_line;
double stundaslikme;
string marka, modelis, klase, nomaspunkts, s, laiks;
    cout<<"Ievadiet paroli "<<endl;
    cin>>parole;
    if(parole==2233){//ieeja ieks AdmminMenu
        system("cls");
        cout<<"Jus veiksmigi iegajat"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"Jus iegajat ka Administrators, Jums ir piejejamas sadas funkcijas:"<<endl;
        do{
            printMenuAdmindarbiba();//darbibas izvele ieks AdminMenu
            cin>>izvele2;
            switch(izvele2){
            case 1:{
                do{

                    id_line=0;
                    ifstream file("auto.txt");
                    while(getline(file,s)){
                        id_line++;
                    }
                    file.close();
                    id= id_line;
                                     //informacijas par katru auto ievadisana un ierakstisana faila
                        fflush(stdin);
                        cout<<"Ievadi auto marku:"<<endl;
                        getline(cin,marka);

                        fflush(stdin);
                        cout<<"Ievadi auto modeli:"<<endl;
                        getline(cin,modelis);

                        cout<<"Ievadi Auto gadu:"<<endl;
                        cin>>gads;

                        fflush(stdin);
                        cout<<"Ievadi Auto klasi:"<<endl;
                        getline(cin,klase);

                        fflush(stdin);
                        cout<<"Ievadi auto stundas likmi:"<<endl;
                        cin>>stundaslikme;

                        fflush(stdin);
                        cout<<"Ievadi nomasPunktu:"<<endl;
                        getline(cin,nomaspunkts);

                        fflush(stdin);
                        cout<<"Ievadi vai si masina ir briva(ir pieejama vai nav pieejama):"<<endl;
                        getline(cin,laiks);

                        fstream fout("auto.txt",ios::app);
                        fout<<id+1<<"."<<marka<<"||"<<modelis<<"||"<<gads<<"||"<<klase<<"||"<<stundaslikme<<"eiro/h"<<"||"<<nomaspunkts<<"||"<<laiks<<endl;
                        fout.close();

                        id++;//rindu vajag turpinat
                        cout<<"Vai ju gribat ievadit informaciju nakamai masinai?(1-ja,0-ne)"<<endl;
                        cin>>atkartojums;
                }while(atkartojums);
                break;
            }
            case 2:{//izeja no AdminMenu
                system("cls");
                cout<<"Izeja:"<<endl;

            break;}

            case 3:{
                cout<<"Ko gribi izlabot?"<<endl;
                system("cls");
                do{
                    printMenuAdminlabosana();//vienas no labosanas veidiem izvele
                    cin>>izvele3;
                    switch(izvele3){
                        case 1:{
                            ifstream file("auto.txt");//viena varda redigesana un aistasana ar jauno lietotaja ievadito vardu
                            cout<<"Ievadi rindu   :"<<endl;
                            int number_line_editing;//rindas ievadisana
                            cin>>number_line_editing;
                            int i_number_line_now=0;
                            ofstream output("auto_copy.txt");

                            while(getline(file,s )){
                                i_number_line_now++;
                                if(i_number_line_now==number_line_editing){
                                    string word_old; // vecs vards
                                    string word_new; // jauns vards
                                    cout<<"Ievadi veco vardu un jauno"<<endl;
                                    cin >> word_old >> word_new;
                                    size_t ind = s.find(word_old);
                                        if (ind!=string::npos){//jauna un veca varda aizvietosana
                                            s.replace(ind,word_old.size(),word_new);
                                        }
                                }
                                    output<<s<<endl;
                            }
                                    file.close();
                                    output.close();
                                    ifstream gg("auto_copy.txt");//parrakstisana no auto_copy faila uz auto failu
                                    ofstream filee("auto.txt");

                                    while (getline(gg,s)){
                                        filee<<s<<endl;
                                    }
                                    filee.close();
                                    break;
                        }

                        case 2:{
                            ofstream output("auto_copy.txt");//Visa faila  visu datu pilniga dzesana
                            fstream file("auto_copy.txt", ios::out);
                            file.close();
                            output.close();
                            ifstream gg("auto_copy.txt");
                            ofstream filee("auto.txt");

                            while (getline(gg,s)){
                                filee<<s<<endl;
                            }
                            filee.close();
                            break;
                        }

                        case 3:{
                            ifstream file("auto.txt");
                            cout<<"Ievadi rindu:"<<endl;//izvelamies rindu faila
                            int number_line_editing;
                            cin>>number_line_editing;
                            int   i_number_line_now=0;
                            ofstream output("auto_copy.txt");

                            while(getline(file,s )){//notiek noteiktas ievaditas rindas meklesana faila un visu rindu pareiza parvietosana faila(lai nebutu brivo rindu faila pec rindas(-du) dzesanu
                                i_number_line_now++;
                                if(i_number_line_now!=number_line_editing){
                                    output<<s<<endl;
                                }
                            }

                            file.close();
                            output.close();
                            ifstream gg("auto_copy.txt");//parrakstisana no auto_copy faila uz auto failu
                            ofstream filee("auto.txt");

                            while (getline(gg,s)){
                                filee<<s<<endl;
                            }
                            filee.close();
                            break;
                        }

                        case 4:
                            system("cls");//iziesana no labosanas

                        }

                }while(izvele3>0&&izvele3<4);
            break;
            }

            case 4:{
                cout<<"Vai jus gribat paskatities faila informaciju(ja-1, ne-0)"<<endl;//skatamies informaciju faila par auto(vai ne skatamies)
                cin>>izvele1;
                if(izvele1==1){
                    failsAdmin();
                }

                AdminStatistika();//statistikas izvade
                break;
            }
            }

            cout<<"Gribat kaut ko vel izdarit?(ja-1,ne-0)"<<endl;//darbibas atkartosana AdminMenu
            cin>>izvele2;
            system("cls");
        }while(izvele2==1);
    }else{
        system("cls");
        cout<<"Error"<<endl;
    }
}
