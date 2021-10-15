#include "functions.hpp"
using namespace std;

/* ---- TO DO ----
- DO MAIN HASH FUNCTION
- DO COMPARISONS
- update random symbol generator


*/

int main(){

    int choice;

    cout << "Choose testing method: " << endl
    << "---------------------------" << endl
    << "1. Input in console. " << endl
    << "2. Input from file. " << endl
    << "3. Comparison " << endl
    << "4. Collision test " << endl
    << "5. Difference test " << endl
    << "---------------------------" << endl;

    choiceCheck(choice, 5);

    if(choice == 1) consoleInput();
    else if(choice == 2) fileInput();
    else if(choice == 3) comparison();
    else if(choice == 4) collisions();
    else if(choice == 5) difference();

}