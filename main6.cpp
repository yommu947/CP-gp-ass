#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

//globle variables: settings
int seasize = 10, carrier = 1, battleship = 1, submarine = 1, destroyer = 1;
char displaypc = 'y';
char pcstart = 'p';
int total_size;
char chart[10][10];
char AIchart[10][10];
char input[5];
bool quit, continues, askagain;
int turn;
int playercarrier = carrier, playerbattleship = battleship, playersubmarine = submarine, playerdestroyer = destroyer;
int playership = playercarrier + playerbattleship + playersubmarine + playerdestroyer;
int AIcarrier = carrier, AIbattleship = battleship, AIsubmarine = submarine, AIdestroyer = destroyer;
int AIship = AIcarrier + AIbattleship + AIsubmarine + AIdestroyer;
bool Random = true;
int east = 0, south = 0, west = 0, north = 0;
int AIx, AIy;
int carrierdir[6][3];
int battleshipdir[6][3];
int submarinedir[6][3];
int destroyerdir[6][3];
int AIcarrierdir[6][3];
int AIbattleshipdir[6][3];
int AIsubmarinedir[6][3];
int AIdestroyerdir[6][3];
int x;

char alphabet(int);//turn number into character
int number(char);//turn number into character
void setting();
void sea();
void clear();
void arrange();
void game();
void credits();
void instructions();
void quitfunction(char input[]);
void AIsea();
void AIarrange();
void Battlestage();
void playerturn();
void AIturn();
void checkdistroyed();

int main() {

    int choice;
    cout << "\nWelcome Captain!";//welcome massage
    cout << "\n\n*** Game Manu ***\n";
    cout << "[1] Start Game\n[2] Setting\n[3] Instruction\n[4] Credits\n[5] Exit\n";
    cout << "*****************";
    cout << endl << "Option (1 - 5):";
    cin >> choice;
    switch (choice) {
        case 1:
            system("cls");
            game();
            system("cls");
            main();
            break;
        case 2: setting();
            system("cls");
            main();
            break;
        case 3: instructions();
            system("cls");
            main(); break;
        case 4: credits();
            system("cls");
            main();
            break;
        case 5: break;
        default: system("cls");
            cout << "Please input 1-5";
            main();
    }

}

char alphabet(int num) {//turn number into character
    switch (num) {
        case 0: return 'A';
        case 1: return 'B';
        case 2: return 'C';
        case 3: return 'D';
        case 4: return 'E';
        case 5: return 'F';
        case 6: return 'G';
        case 7: return 'H';
        case 8: return 'I';
        case 9: return 'J';
        default: return '*';
    }
}


int number(char num) {//turn number into character
    switch (num) {
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
        case 'D': return 3;
        case 'E': return 4;
        case 'F': return 5;
        case 'G': return 6;
        case 'H': return 7;
        case 'I': return 8;
        case 'J': return 9;
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        case 'i': return 8;
        case 'j': return 9;
        default: return 10;
    }
}
void setting() {
    int option;
    system("cls");
    cout << "\n*** Setting Menu ***\n";
    cout << "[1] Who starts first\n[2] Display PC's ships\n[3] Sea size\n[4] Number of ships\n[5] Return to game menu\n";
    cout << "********************";
    cout << endl << "Option (1 - 5):";
    cin >> option;
    switch (option) {
        case 1:	system("cls");
            cout << "[1] Who starts first" << endl;
            cout << "Who starts first? ";
            if (pcstart == 'p') cout << "( Player First NOW)" << endl;
            else cout << "( Computer First NOW )" << endl;

            cout << "p: player, c: computer" << endl;
            cout << "Please type here: ";
            cin >> pcstart;
            cout << endl;

            if (pcstart == 'p') cout << "Player First" << endl;
            else if (pcstart == 'c') cout << "Computer First" << endl;
            else {

                do {
                    cout << "Please enter p or c only" << endl;
                    cout << "Please type here: ";
                    cin >> pcstart;
                    cout << endl;
                } while (pcstart != 'p' && pcstart != 'c');

                if (pcstart == 'p') cout << "Player First" << endl;
                else if (pcstart == 'c') cout << "Computer First" << endl;

            }

            cout << "State Updated" << endl;
            system("pause");
            system("cls");
            setting();
            break;
        case 2: system("cls");
            cout << "[2] Display PC's ships" << endl;
            cout << "Display PC's ships? ";
            if (displaypc == 'y') cout << "(Display PC's ships NOW)" << endl;
            else cout << "( Not display PC's ships NOW )" << endl;

            cout << "Display = y or Not display = n" << endl;
            cout << "Please type here: ";
            cin >> displaypc;
            cout << endl;

            if (displaypc == 'y') cout << "Display PC's ships" << endl;

            else if (displaypc == 'n') cout << "Not display PC's ships" << endl;

            else {
                do {
                    cout << "Please enter y or n only" << endl;
                    cout << "Please type here: ";
                    cin >> displaypc;
                    cout << endl;
                } while (displaypc != 'y' && displaypc != 'n');

                if (displaypc == 'y') cout << "Display PC's ships" << endl;
                else if (displaypc == 'n') cout << "Not display PC's ships" << endl;

            }

            cout << "state updated" << endl;
            system("pause");
            system("cls");
            setting();
            break;
        case 3: system("cls");
            cout << "[3] Sea size" << endl;
            cout << "Set sea size (5 to 10) " << "(NOW is " << seasize << " x " << seasize << ")" << endl;
            cout << "Please type here: ";
            cin >> seasize;

            total_size = carrier * 5 + battleship * 4 + submarine * 3 + destroyer * 2;

            while (seasize * seasize <= total_size) {
                cout << endl;
                cout << "Sea size should be from 5 to 10 (each side) and large than total size of ships" << endl;
                cout << "The total size of ships is " << total_size << endl;
                cout << "Please type here: ";
                cin >> seasize;
            }

            while (seasize != 5 && seasize != 6 && seasize != 7 && seasize != 8 && seasize != 9 && seasize != 10)
            {
                cout << endl;
                cout << "Sea size should be from 5 to 10 (each side) and large than total size of ships" << endl;
                cout << "The total size of ships is " << total_size << endl;
                cout << "Please type here: ";
                cin >> seasize;

            }

            cout << endl;
            cout << "Sea size change to " << seasize << " x " << seasize << endl;
            cout << "state updated" << endl;
            system("pause");
            setting();
            break;

        case 4:
            system("cls");
            cout << "[4] Number of ships" << endl;

            cout << left << setw(22) << "Type of ship" << "Number" << endl;
            cout << setw(11) << "carrier" << "(size 5):" << right << setw(5) << carrier << endl;
            cout << left << setw(11) << "Battleship" << "(size 4):" << right << setw(5) << battleship << endl;
            cout << left << setw(11) << "Submarine" << "(size 3):" << right << setw(5) << submarine << endl;
            cout << left << setw(11) << "Destroyer" << "(size 2):" << right << setw(5) << destroyer << endl;
            cout << endl;

            cout << "Change the number of ships" << endl;
            cout << "Carrier" << " change to ";
            cin >> carrier;
            cout << "Battleship" << " change to ";
            cin >> battleship;
            cout << "Submarine" << " change to ";
            cin >> submarine;
            cout << "Destroyer" << " change to ";
            cin >> destroyer;

            total_size = carrier * 5 + battleship * 4 + submarine * 3 + destroyer * 2;

            while ((total_size >= seasize * seasize) || (carrier < 1 || carrier > 5) || (battleship < 1 || battleship > 5) || (submarine < 1 || submarine > 5) || (destroyer < 1 || destroyer > 5))
            {
                system("cls");
                cout << endl;
                cout << "SHIPS SIZE do not exceed the SEA SIZE" << endl;
                cout << "Please try again " << "( Sea Size = " << seasize << " x " << seasize << " )" << endl;
                cout << endl;

                cout << "Change the number of ships" << endl;

                cout << "Carrier" << " change to ";
                cin >> carrier;
                cout << "Battleship" << " change to ";
                cin >> battleship;
                cout << "Submarine" << " change to ";
                cin >> submarine;
                cout << "Destroyer" << " change to ";
                cin >> destroyer;

                total_size = carrier * 5 + battleship * 4 + submarine * 3 + destroyer * 2;
            }

            cout << endl;
            cout << "state updated" << endl;
            system("pause");
            system("cls");
            setting();
            break;



        case 5: system("pause");
            system("cls");
            break;
        default:system("cls");
            setting();
            break;
    }


}

void sea() {
    cout << "   ";
    for (int c = 0; c < seasize; c++) {
        cout << right << setw(2) << c;
    }
    cout << endl << "  +-";
    for (int c = 0; c < seasize; c++) {
        cout << "--";
    }
    cout << "+";


    for (int row = 0; row < seasize; row++) {
        cout << endl << alphabet(row) << " | ";
        for (int col = 0; col < seasize; col++) {
            cout << chart[row][col] << " ";
        }
        cout << "|";

    }
    cout << endl << "  +-";
    for (int c = 0; c < seasize; c++) {
        cout << "--";
    }
    cout << "+" << endl;
}

void AIsea() {
    cout << "   ";
    for (int c = 0; c < seasize; c++) {
        cout << right << setw(2) << c;
    }
    cout << endl << "  +-";
    for (int c = 0; c < seasize; c++) {
        cout << "--";
    }
    cout << "+";


    for (int row = 0; row < seasize; row++) {
        cout << endl << alphabet(row) << " | ";
        for (int col = 0; col < seasize; col++) {
            if (displaypc == 'n' && AIchart[row][col] == 'o') {
                cout << "  ";
            }
            else { cout << AIchart[row][col] << " "; }
        }
        cout << "|";

    }
    cout << endl << "  +-";
    for (int c = 0; c < seasize; c++) {
        cout << "--";
    }
    cout << "+" << endl;
}

void clear() {
    for (int c = 0; c < 10; c++) {
        for (int cc = 0; cc < 10; cc++) {
            chart[c][cc] = ' ';
            AIchart[c][cc] = ' ';
        }
    }
}

void arrange() {
    char xchar, ychar;
    char direction[5];
    int x, y;
    bool allow;
    for (int c = 1; c <= carrier; c++) {
        do {
            allow = true;
            do {
                cout << endl;
                cout << "Input coordinate of carrier " << c << "(e.g. C2) :";
                cin >> input;
                quitfunction(input);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            y = number(input[0]);
            x = input[1] - 48;
            do {
                cout << "\nInput direction of carrier " << c << "(1 for horizontal, 2 for vertical):";
                cin >> direction;
                quitfunction(direction);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            cout << endl;


            for (int cc = 0; cc < 5; cc++) {
                if (direction[0] == '1') {
                    if (chart[y][x + cc] == 'o') { allow = false; }
                }
                else {
                    if (chart[y + cc][x] == 'o') { allow = false; }
                }
            }

            if (direction[0] == '1') {
                if (x + 4 > seasize - 1) {
                    allow = false;
                }
            }
            else {
                if (y + 4 > seasize - 1) {
                    allow = false;
                }
            }

            if (y == 10 || x < 0 || x > 9 || input[2] != '\0' || (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0') {
                allow = false;
            }

        } while (allow == false);


        carrierdir[c][0] = direction[0] - 48;
        carrierdir[c][1] = y;
        carrierdir[c][2] = x;
        system("cls");
        if (allow == true) {
            for (int cc = 0; cc < 5; cc++) {
                if (direction[0] == '1') {
                    chart[y][x + cc] = 'o';
                }
                else {
                    chart[y + cc][x] = 'o';
                }
            }
        }
        sea();
    }

    for (int c = 1; c <= battleship; c++) {
        do {
            allow = true;
            do {
                cout << endl;
                cout << "Input coordinate of Battleship " << c << "(e.g. C2) :";
                cin >> input;
                quitfunction(input);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            y = number(input[0]);
            x = input[1] - 48;
            do {
                cout << "\nInput direction of Battleship " << c << "(1 for horizontal, 2 for vertical):";
                cin >> direction;
                quitfunction(direction);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            cout << endl;

            for (int cc = 0; cc < 4; cc++) {
                if (direction[0] == '1') {
                    if (chart[y][x + cc] == 'o') { allow = false; }
                }
                else {
                    if (chart[y + cc][x] == 'o') { allow = false; }
                }
            }
            if (direction[0] == '1') {
                if (x + 3 > seasize - 1) {
                    allow = false;
                }
            }
            else {
                if (y + 3 > seasize - 1) {
                    allow = false;
                }
            }

            if (y == 10 || x < 0 || x > 9 || input[2] != '\0' || (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0') {
                allow = false;
            }

        } while (allow == false);

        battleshipdir[c][0] = direction[0] - 48;
        battleshipdir[c][1] = y;
        battleshipdir[c][2] = x;
        system("cls");
        if (allow == true) {
            for (int cc = 0; cc < 4; cc++) {
                if (direction[0] == '1') {
                    chart[y][x + cc] = 'o';
                }
                else {
                    chart[y + cc][x] = 'o';
                }
            }
        }
        sea();
    }



    for (int c = 1; c <= submarine; c++) {
        do {
            allow = true;
            do {
                cout << endl;
                cout << "Input coordinate of submarine " << c << "(e.g. C2) :";
                cin >> input;
                quitfunction(input);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            y = number(input[0]);
            x = input[1] - 48;
            do {
                cout << "\nInput direction of submarine " << c << "(1 for horizontal, 2 for vertical):";
                cin >> direction;
                quitfunction(direction);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            cout << endl;

            for (int cc = 0; cc < 3; cc++) {
                if (direction[0] == '1') {
                    if (chart[y][x + cc] == 'o') { allow = false; }
                }
                else {
                    if (chart[y + cc][x] == 'o') { allow = false; }
                }
            }
            if (direction[0] == '1') {
                if (x + 2 > seasize - 1) {
                    allow = false;
                }
            }
            else {
                if (y + 2 > seasize - 1) {
                    allow = false;
                }
            }

            if (y == 10 || x < 0 || x > 9 || input[2] != '\0' || (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0') {
                allow = false;
            }

        } while (allow == false);

        submarinedir[c][0] = direction[0] - 48;
        submarinedir[c][1] = y;
        submarinedir[c][2] = x;
        system("cls");
        if (allow == true) {
            for (int cc = 0; cc < 3; cc++) {
                if (direction[0] == '1') {
                    chart[y][x + cc] = 'o';
                }
                else {
                    chart[y + cc][x] = 'o';
                }
            }
        }
        sea();
    }




    for (int c = 1; c <= destroyer; c++) {
        do {
            allow = true;
            do {
                cout << endl;
                cout << "Input coordinate of destroyer " << c << "(e.g. C2) :";
                cin >> input;
                quitfunction(input);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            y = number(input[0]);
            x = input[1] - 48;
            do {
                cout << "\nInput direction of destroyer " << c << "(1 for horizontal, 2 for vertical):";
                cin >> direction;
                quitfunction(direction);
                if (continues == false) {
                    system("cls");
                    clear();
                    main();
                    return;
                }
            } while (askagain == true);
            cout << endl;

            for (int cc = 0; cc < 2; cc++) {
                if (direction[0] == '1') {
                    if (chart[y][x + cc] == 'o') {
                        allow = false;
                    }
                }
                else {
                    if (chart[y + cc][x] == 'o') { allow = false; }
                }
            }
            if (direction[0] == '1') {
                if (x + 1 > seasize - 1) {
                    allow = false;
                }
            }
            else {
                if (y + 1 > seasize - 1) {
                    allow = false;
                }
            }

            if (y == 10 || x < 0 || x > 9 || input[2] != '\0' || (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0') {
                allow = false;
            }

        } while (allow == false);

        destroyerdir[c][0] = direction[0] - 48;
        destroyerdir[c][1] = y;
        destroyerdir[c][2] = x;
        system("cls");
        if (allow == true) {
            for (int cc = 0; cc < 2; cc++) {
                if (direction[0] == '1') {
                    chart[y][x + cc] = 'o';
                }
                else {
                    chart[y + cc][x] = 'o';
                }
            }
        }
        sea();
    }

}

void AIarrange() {
    srand(time(0));
    int AIshipdirection, pt1, pt2, errorcheck;
    for (int i = 1; i <= carrier; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 6;
                for (int i = pt2; i <= pt2 + 4; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    AIchart[pt1][pt2 + 2] = 'o';
                    AIchart[pt1][pt2 + 3] = 'o';
                    AIchart[pt1][pt2 + 4] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                    AIcarrierdir[i][0] = AIshipdirection;
                    AIcarrierdir[i][1] = pt1;
                    AIcarrierdir[i][2] = pt2;
                }
            }
            else {//vertical
                pt1 = rand() % 6;
                pt2 = rand() % seasize;
                for (int i = pt1; i <= pt1 + 4; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                    AIchart[pt1 + 2][pt2] = 'o';
                    AIchart[pt1 + 3][pt2] = 'o';
                    AIchart[pt1 + 4][pt2] = 'o';
                    AIcarrierdir[i][0] = AIshipdirection;
                    AIcarrierdir[i][1] = pt1;
                    AIcarrierdir[i][2] = pt2;
                }
            }
        } while (errorcheck == 0);
    }
    for (int i = 1; i <= battleship; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 7;
                for (int i = pt2; i <= pt2 + 3; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    AIchart[pt1][pt2 + 2] = 'o';
                    AIchart[pt1][pt2 + 3] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                    AIbattleshipdir[i][0] = AIshipdirection;
                    AIbattleshipdir[i][1] = pt1;
                    AIbattleshipdir[i][2] = pt2;
                }
            }
            else {//vertical
                pt1 = rand() % 7;
                pt2 = rand() % seasize;
                for (int i = pt1; i <= pt1 + 3; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                    AIchart[pt1 + 2][pt2] = 'o';
                    AIchart[pt1 + 3][pt2] = 'o';
                    AIbattleshipdir[i][0] = AIshipdirection;
                    AIbattleshipdir[i][1] = pt1;
                    AIbattleshipdir[i][2] = pt2;
                }
            }
        } while (errorcheck == 0);
    }
    for (int i = 1; i <= submarine; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 8;
                for (int i = pt2; i <= pt2 + 2; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    AIchart[pt1][pt2 + 2] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                    AIsubmarinedir[i][0] = AIshipdirection;
                    AIsubmarinedir[i][1] = pt1;
                    AIsubmarinedir[i][2] = pt2;
                }
            }
            else {//vertical
                pt1 = rand() % 8;
                pt2 = rand() % seasize;
                for (int i = pt1; i <= pt1 + 2; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                    AIchart[pt1 + 2][pt2] = 'o';
                    AIsubmarinedir[i][0] = AIshipdirection;
                    AIsubmarinedir[i][1] = pt1;
                    AIsubmarinedir[i][2] = pt2;
                }
            }
        } while (errorcheck == 0);
    }
    for (int i = 1; i <= destroyer; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 9;
                for (int i = pt2; i <= pt2 + 1; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                    AIdestroyerdir[i][0] = AIshipdirection;
                    AIdestroyerdir[i][1] = pt1;
                    AIdestroyerdir[i][2] = pt2;
                }
            }
            else {//vertical
                for (int i = pt1; i <= pt1 + 1; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    }
                    else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    pt1 = rand() % 9;
                    pt2 = rand() % seasize;
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                    AIdestroyerdir[i][0] = AIshipdirection;
                    AIdestroyerdir[i][1] = pt1;
                    AIdestroyerdir[i][2] = pt2;
                }
            }
        } while (errorcheck == 0);
    }
}

void game() {
    sea();
    arrange();
    AIarrange();
    Battlestage();



}


void instructions() {
    // option 3: Instructions
    cout << "You are the player who playing the battleship game." << endl;
    cout << "You need to attack all the opponent's ships by using four types of ships-carrier, battleship,submarine and destroyer." << endl;
    cout << "Each ship can be placed either horizontally or vertically on the sea, and occupies the required number of slots according to its size." << endl;
    cout << "Whenever a ship is placed on the sea, the occupied slots are marked with a capital letter ‘O’." << endl;
    cout << "Then you should arrange the next ship until all the ships are placed on the sea." << endl;
    cout << "If you attack on an emptyslot, the slot is marked by an asterisk ‘*’." << endl;
    cout << "If you attack on the ship body, the slot is marked by a capital letter ‘H’." << endl;
    cout << "You lose if your ships'body is hit by PC." << endl;
    cout << "You win the battleship game if you hit all opponent ships' body." << endl;







    system("pause");

}

void credits() {
    // option 4: Credits

    cout << endl;
    cout << "Student Full Name		Student ID		Class" << endl;
    cout << "Choi Yiu Tung			16152710A		202C" << endl;
    cout << "Lee Chung Chak			16070266A		202A" << endl;
    cout << "Hung Kam Chung			16016760A		202B" << endl;
    cout << "Li Man Fung			16091471A		202B" << endl;
    cout << "Leung Kwan Ho			16071890A		202B" << endl;
    cout << "Leung Man Hin			16137324A		202C" << endl;
    cout << endl;

    system("pause");

}

void quitfunction(char input[]) {
    char quit2[] = "Quit";
    quit = true;
    continues = false;
    askagain = false;
    for (int i = 0; i < 4; i++) {
        if (input[i] != quit2[i]) {
            quit = false;
            continues = true;
        }
    }
    if (quit == true) {
        quit = false;
        continues = true;
        askagain = true;
        cout << endl;
        cout << "Do you want to quit?(y=yes,n=no): ";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            continues = false;
            quit = true;
        }
    }
    cout << endl;
}

void Battlestage() {
    if (pcstart == 'p') {
        turn = 0;
    }
    else {
        turn = 1;
    }
    while (playership != 0 && AIship != 0) {
        system("cls");
        cout << "Playership numbers : " << setw(6) << left << playership << "AIship numbers : " << AIship << endl << endl;
        cout << AIbattleshipdir[1][0] << AIbattleshipdir[1][1] << AIbattleshipdir[1][2] << endl;
        cout << AIbattleshipdir[2][0] << AIbattleshipdir[2][1] << AIbattleshipdir[2][2] << endl;
        cout << AIcarrier << endl;
        cout << AIbattleship << endl;
        cout << AIsubmarine << endl;
        cout << AIdestroyer << endl;
        cout << "Player sea" << endl << endl;
        sea();
        cout << endl;
        cout << "AI sea" << endl << endl;
        AIsea();
        cout << endl;
        if (turn % 2 == 0) {
            playerturn();
        }
        else {
            AIturn();
        }
    }

    system("cls");
    cout << "Playership numbers : " << setw(6) << left << playership << "AIship numbers : " << AIship << endl << endl;
    cout << "Player sea" << endl << endl;
    sea();
    cout << endl;
    if (displaypc == 'y') {
        cout << "AI sea" << endl << endl;
        AIsea();
        cout << endl;
    }
    if (playership == 0) {
        cout << "Player's ships are all destroyed. AI Win!" << endl << endl;
        system("pause");
        clear();
        system("cls");
        main();
    }
    else {
        cout << "AI's ships are all destroyed. Player Win!" << endl << endl;
        system("pause");
        system("cls");
        clear();
        main();
    }
}

void playerturn() {
    int x, y;
    bool allow;
    do {
        allow = true;
        do {
            cout << "Which location you want to attack?(eg. c2): ";
            cin >> input;
            cout << endl;
            quitfunction(input);
            if (continues == false) {
                system("cls");
                clear();
                main();
                return;
            }
        } while (askagain == true);
        y = number(input[0]);
        x = input[1] - 48;
        if (AIchart[y][x] == '*' && AIchart[y][x] == 'H') {
            allow = false;
        }
        if (y == 10 || x < 0 || x > 9 || input[2] != '\0') {
            allow = false;
        }

    } while (allow == false);

    if (AIchart[y][x] != 'o') {
        AIchart[y][x] = '*';
        x = x + 1;
    }
    else if (AIchart[y][x] == 'o') {
        AIchart[y][x] = 'H';
    }
    turn++;
    checkdistroyed();
}

void AIturn() {
    char directionactive = '0';
    char direction = 0;
    if (Random == true && directionactive == '0') {
        bool allow = true;
        srand(time(0));
        do {
            AIx = rand() % 10;
            AIy = rand() % 10;

            if (chart[AIy][AIx] == '*' || chart[AIy][AIx] == 'H') {
                allow = false;
            }

        } while (allow == false);

        if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H') {
            chart[AIy][AIx] = '*';
        }
        else if (chart[AIy][AIx] == 'o') {
            chart[AIy][AIx] = 'H';
            Random = false;
        }
    }
    else if (Random == false && directionactive == '1') {

        switch (direction) {
            case 0: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H') {
                    chart[AIy][AIx + 1] = '*';
                    direction = 1;if(AIx==seasize)
                    directionactive = '0';
                }
                else if (chart[AIy][AIx + 1] == 'o') {
                    chart[AIy][AIx + 1] = 'H';
                }
                break;
            case 1: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H' ) {
                    chart[AIy - 1][AIx] = '*';
                    direction = 0;if(AIy==0)
                    directionactive = '0';
                }
                else if (chart[AIy - 1][AIx] == 'o') {
                    chart[AIy -1][AIx] = 'H';
                }
                break;
            case 2: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H' ) {
                    chart[AIy][AIx - 1] = '*';
                    direction = 3;if(AIx==0)
                    directionactive = '0';
                }
                else if (chart[AIy][AIx - 1] == 'o') {
                    chart[AIy][AIx - 1] = 'H';
                }
                break;
            case 3: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H' ) {
                    chart[AIy+1][AIx] = '*';
                    direction = 2;if(AIy==seasize)
                    directionactive = '0';
                }
                else if (chart[AIy+1][AIx] == 'o') {
                    chart[AIy+1][AIx] = 'H';
                }
                break;
        }
    }
    else if (Random == false && directionactive == '0') {
        int a;
        srand(time(0));
        a = rand() % 4;
        switch (a) {
            case 0: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H' ) {
                    chart[AIy][AIx + 1] = '*';
                    east = east + 1;
                }
                else if (chart[AIy][AIx + 1] == 'o') {
                    chart[AIy][AIx + 1] = 'H';
                    east = east + 2;
                    direction = 0;
                    directionactive = '1';
                }
                break;

            case 1: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H' ) {
                    chart[AIy - 1][AIx] = '*';
                    south = south + 1;
                }
                else if (chart[AIy - 1][AIx] == 'o') {
                    chart[AIy - 1][AIx] = 'H';
                    south = south + 2;
                    direction = 1;
                    directionactive = '1';
                }
                break;

            case 2: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H') {
                    chart[AIy][AIx - 1] = '*';
                    west = west + 1;
                }
                else if (chart[AIy][AIx - 1] == 'o') {
                    chart[AIy][AIx - 1] = 'H';
                    west = west + 2;
                    direction = 2;
                    directionactive = '1';
                }
                break;

            case 3: if (chart[AIy][AIx] != '*' && chart[AIy][AIx] != 'o' && chart[AIy][AIx] != 'H') {
                    chart[AIy + 1][AIx] = '*';
                    north = north + 1;
                }
                else if (chart[AIy + 1][AIx] == 'o') {
                    chart[AIy + 1][AIx] = 'H';
                    north = north + 2;
                    direction = 3;
                    directionactive = '1';
                }
                break;
        }

    }
    turn++;
    checkdistroyed();
}



void checkdistroyed() {
    int shippart;
    for (int i = 1; i <= playercarrier; i++) {
        shippart = 0;
        if (carrierdir[i][0] == 1) {
            for (int a = 0; a <= 4; a++) {
                if (chart[carrierdir[i][1]][carrierdir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (carrierdir[i][0] == 2) {
            for (int a = 0; a <= 4; a++) {
                if (chart[carrierdir[i][1] + a][carrierdir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 5) {
            playercarrier = playercarrier - 1;
        }
    }

    for (int i = 1; i <= playerbattleship; i++) {
        shippart = 0;
        if (battleshipdir[i][0] == 1) {
            for (int a = 0; a <= 3; a++) {
                if (chart[battleshipdir[i][1]][battleshipdir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (battleshipdir[i][0] == 2) {
            for (int a = 0; a <= 3; a++) {
                if (chart[battleshipdir[i][1] + a][battleshipdir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 4) {
            playerbattleship = playerbattleship - 1;
        }
    }

    for (int i = 1; i <= playersubmarine; i++) {
        shippart = 0;
        if (submarinedir[i][0] == 1) {
            for (int a = 0; a <= 2; a++) {
                if (chart[submarinedir[i][1]][submarinedir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (submarinedir[i][0] == 2) {
            for (int a = 0; a <= 2; a++) {
                if (chart[submarinedir[i][1] + a][submarinedir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 3) {
            playersubmarine = playersubmarine - 1;
        }
    }

    for (int i = 1; i <= playerdestroyer; i++) {
        shippart = 0;
        if (destroyerdir[i][0] == 1) {
            for (int a = 0; a <= 1; a++) {
                if (chart[destroyerdir[i][1]][destroyerdir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (destroyerdir[i][0] == 2) {
            for (int a = 0; a <= 1; a++) {
                if (chart[destroyerdir[i][1] + a][destroyerdir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 2) {
            playerdestroyer = playerdestroyer - 1;
        }
    }

    playership = playercarrier + playerbattleship + playersubmarine + playerdestroyer;

    for (int i = 1; i <= AIcarrier; i++) {
        shippart = 0;
        if (AIcarrierdir[i][0] == 1) {
            for (int a = 0; a <= 4; a++) {
                if (AIchart[AIcarrierdir[i][1]][AIcarrierdir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (AIcarrierdir[i][0] == 2) {
            for (int a = 0; a <= 4; a++) {
                if (AIchart[AIcarrierdir[i][1] + a][AIcarrierdir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 5) {
            AIcarrier = AIcarrier - 1;
        }
    }

    for (int i = 1; i <= AIbattleship; i++) {
        shippart = 0;
        if (AIbattleshipdir[i][0] == 1) {
            for (int a = 0; a <= 3; a++) {
                if (AIchart[AIbattleshipdir[i][1]][AIbattleshipdir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (AIbattleshipdir[i][0] == 2) {
            for (int a = 0; a <= 3; a++) {
                if (AIchart[AIbattleshipdir[i][1] + a][AIbattleshipdir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 4) {
            AIbattleship = AIbattleship - 1;
        }
    }

    for (int i = 1; i <= AIsubmarine; i++) {
        shippart = 0;
        if (AIsubmarinedir[i][0] == 1) {
            for (int a = 0; a <= 2; a++) {
                if (AIchart[AIsubmarinedir[i][1]][AIsubmarinedir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (AIsubmarinedir[i][0] == 2) {
            for (int a = 0; a <= 2; a++) {
                if (AIchart[AIsubmarinedir[i][1] + a][AIsubmarinedir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 3) {
            AIsubmarine = AIsubmarine - 1;
        }
    }

    for (int i = 1; i <= AIdestroyer; i++) {
        shippart = 0;
        if (AIdestroyerdir[i][0] == 1) {
            for (int a = 0; a <= 1; a++) {
                if (AIchart[AIdestroyerdir[i][1]][AIdestroyerdir[i][2] + a] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        else if (AIdestroyerdir[i][0] == 2) {
            for (int a = 0; a <= 1; a++) {
                if (AIchart[AIdestroyerdir[i][1] + a][AIdestroyerdir[i][2]] == 'H') {
                    shippart = shippart + 1;
                }
            }
        }
        if (shippart == 2) {
            AIdestroyer = AIdestroyer - 1;
        }
    }

    AIship = AIcarrier + AIbattleship + AIsubmarine + AIdestroyer;

}
