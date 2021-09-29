#include "functions.hpp"
using namespace std;

/* ---- TO DO ----
- update random symbol generator
- update hash function


*/

int main(){

    int choice;

    cout << "Choose testing method: " << endl
    << "---------------------------" << endl
    << "1. Input in console. " << endl
    << "2. Input from file. " << endl
    << "3. Comparison " << endl
    << " " << endl
    << "---------------------------" << endl;

    choiceCheck(choice, 3);

    if(choice == 1) consoleInput();
    else if(choice == 2) fileInput();
    else if(choice == 3) comparison();

}