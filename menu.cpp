using namespace std;
#include <iostream>
#include "menu.h"

void printMenu(){
   cout<<"Menu:"<<endl;
   cout<<"1)Admin"<<endl;
   cout<<"2)User"<<endl;
   cout<<"3)Iziet no programmas"<<endl;
   cout<<"4)Lietotaja registresana"<<endl;
}

void selectMenu(int* izvele){//Izvelamies vienu no menu darbibam
   cout<<"Izveleties vienu no menu darbibam "<<endl;
   cin>>*izvele;
}

void printMenuAdmindarbiba(){//Izvelamies vienu no menu darbibam
    cout<<"1)Pievienot auto marku,auto modeli,auto gadu,auto klasi, stundas likmi,AutoNomas punktu un piejamibu"<<endl;
    cout<<"2)Izeja"<<endl;
    cout<<"3)Aiziet uz labosanu"<<endl;
    cout<<"4)Statistika(Masinu pieejamibas ievadisana un rezultatu paradisana)"<<endl;
}


void printMenuAdminlabosana(){//Izvelamies vienu no menu darbibam
    cout<<"1)Rediget vardus "<<endl;
    cout<<"2)Dzest viss kas ir faila"<<endl;
    cout<<"3)Dzest rindu"<<endl;
    cout<<"4)Iziet no labosanas"<<endl;
}

void printMenuUserizvele(){//Izvelamies vienu no menu darbibam
    cout<<"1)Meklet auto pec nomas punkta(rezervacijas taisisana un drukasana)"<<endl;
    cout<<"2)Meklet auto pec markas(rezervacijas taisisana un drukasana)"<<endl;
    cout<<"3)Meklet auto pec klases(rezervacijas taisisana un drukasana)"<<endl;
    cout<<"4)Meklet auto pec briva laika(rezervacijas taisisana un drukasana)"<<endl;
    cout<<"5)Iziet no userMenu"<<endl;
    cout<<"6)Meklet rezervaciju"<<endl;
    cout<<"7)Paskatitities informaciju par savu profilu"<<endl;
}

void piekrisanaUserMenu(){//Izvelamies vienu no menu darbibam
    cout<<"Vai jus gribat turpinat talak(ja) vai meklet talak(ne)(1-ja, 0-ne)"<<endl;
}


