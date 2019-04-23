#include <iostream>
#include "menu.h"
#include "AdminMenu.h"
#include "UserMenu.h"
using namespace std;

int main(){
int izvele;
int atkartot;
do{
    printMenu();
    selectMenu(&izvele);
    switch (izvele){//izvelamies vienu no menu galvenam darbibam
        case 1:login_admin();
        break;

        case 2:userMenu();
        break;

        case 3:cout<<"Ata!!"<<endl;
        break;

        case 4:registresana();
        break;

    default:
        cout<<"Kluda"<<endl;
    }
}while(izvele!=3);

}
