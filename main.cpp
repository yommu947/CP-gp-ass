#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;



//menu
int main() {
    int option;
    cout << "Welcome to the WAR! Captain!" << endl;
    cout << "*** Game Menu ***" << endl;
    cout << "[1] Start Game" << endl;
    cout << "[2] Settings" << endl;
    cout << "[3] Instruction" << endl;
    cout << "[4] Credits" << endl;
    cout << "[5] Exit" << endl;
    cout << "*****************" << endl;
    cout << "Option (1 - 5): ";
    cin >> option;
    
    switch (option){
        case 1: startgame(); break;
        case 2: setting(); break;
        case 3: instruction(); break;
        case 4: credits(); break;
        case 5: cout << "Bye!"; break;
    }
}

void startgame(){

}
void setting(){
    
}
void instruction(){
    
}
void credits(){
    
}
