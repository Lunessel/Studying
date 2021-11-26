#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "User.h"
#include "Realisation.h"




enum Mode
{
    elogin,
    eregister,
    ehelp,
    ebreak
};
Mode hashit(std::string const &str)
{
    if(str=="login") return elogin;
    if(str=="register") return eregister;
    if(str=="help") return ehelp;
    return ebreak;
}
int main() {
    Realisation person;
    User current_account;

    std::string mode;

    while(true) {
        std::cout << "Do you want login or create an account?(login or register):";
        std::cin >> mode;
        if(mode=="break") break;

        switch (hashit(mode)) {
            case elogin:
                current_account = Realisation::Login();
                break;
            case eregister:
                current_account = person.Register();
                break;
            case ehelp:
                //Help()
                break;
            default:
                std::cout << "command doesn't found";
                break;
        }
        current_account.Print();
        std::cout << "-----------------\n";
        mode="";
    }

    return 0;
}


