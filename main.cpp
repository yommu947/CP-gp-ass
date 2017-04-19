#include<iostream>
#include<iomanip>
using namespace std;
//1
//globle variables: settings
int seasize = 10, carrier = 1, battleship = 2, submarine = 3, destroyer = 4;
bool displaypc = false, pcstart = false;
char chart[10][10];

char alphabet(int);//turn number into character
int number(char);//turn number into character
void setting();
void sea();
void clear();
void arrange();
void game();

int main() {

	int choice;
	cout << "\nWelcome Captain!";//welcome massage
	cout << "\n\n*** Game Manu ***\n";
	cout << "[1] Start Game\n[2] Setting\n[3] Instruction\n[4] Credits\n[5] Exit\n";
	cout << "*****************";
	cout << endl << "Option (1 - 5):";
	cin >> choice;
	switch (choice) {
	case 1:game(); break;
	case 2:setting(); break;
	case 3:break;
	case 4:break;
	case 5:return 0;
	default: cout << "Please input 1-5";
	}
	main();
}

char alphabet(int num) {//turn number into character
	switch (num) {
	case 1: return 'A';
	case 2: return 'B';
	case 3: return 'C';
	case 4: return 'D';
	case 5: return 'E';
	case 6: return 'F';
	case 7: return 'G';
	case 8: return 'H';
	case 9: return 'I';
	case 10: return 'J';
	default: return '*';
	}
}

int number(char num) {//turn number into character
	switch (num) {
	case 'A': return 1;
	case 'B': return 2;
	case 'C': return 3;
	case 'D': return 4;
	case 'E': return 5;
	case 'F': return 6;
	case 'G': return 7;
	case 'H': return 8;
	case 'I': return 9;
	case 'J': return 10;
	case 'a': return 1;
	case 'b': return 2;
	case 'c': return 3;
	case 'd': return 4;
	case 'e': return 5;
	case 'f': return 6;
	case 'g': return 7;
	case 'h': return 8;
	case 'i': return 9;
	case 'j': return 10;
	default: return 0;
	}
}

void setting() {
	int option;
	cout << "\n\n*** Setting Menu ***\n";
	cout << "[1] Who starts first\n[2] Display PC's ships\n[3] Sea size\n[4] Number of ships\n[5] Returnto game menu\n";
	cout << "********************";
	cout << endl << "Option (1 - 5):";
	cin >> option;
	switch (option) {
	case 1:cout << "Let PC start first?(Input 1 for yes 0 for no)"; cin >> pcstart; break;
	case 2:cout << "Display PC's ships?(Input 1 for yes 0 for no)"; cin >> displaypc; break;
	case 3:cout << "Set sea size(5 to 10)"; cin >> seasize; break;
	case 4:
		cout << "Carrier (" << carrier << ") change to ";
		cin >> carrier;
		cout << "Battleship (" << battleship << ") change to ";
		cin >> battleship;
		cout << "Submarine (" << submarine << ") change to ";
		cin >> submarine;
		cout << "Destroyer (" << destroyer << ") change to ";
		cin >> destroyer; break;
	case 5:main();
	default:break;
	}
	if (option!=5) { setting(); }

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


	for (int row = 1; row <= seasize; row++) {
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
	cout << "+"<<endl;
}

void clear() {
	for (int c = 1; c <= 10; c++) {
		for (int cc = 1; c <= 10; c++) {
			chart[c][cc] = ' ';
		}
	}
};

void arrange() {
	char xchar, ychar;
	int x, y, direction;
	for (int c = 1; c <= carrier; c++) {
		cout << "Input coordinate of carrier "<<c<<"(e.g. C2) :";
		cin >> ychar >>xchar;
		y = number(ychar);
		x = xchar-48;
		cout << "\nInput direction of carrier " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		for (int cc = 0; cc < 5; cc++) {
			if (direction == 1) {
				chart[y][x + cc] = 'o';
			}
			else {
				chart[y + cc][x] = 'o';
			}
		}
		sea();
	}
	for (int c = 1; c <= battleship; c++) {
		cout << "Input coordinate of battleship " << c << "(e.g. C2) :";
		cin >> ychar >> xchar;
		y = number(ychar);
		x = xchar - 48;
		cout << "\nInput direction of battleship " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		for (int cc = 0; cc < 4; cc++) {
			if (direction == 1) {
				chart[y][x + cc] = 'o';
			}
			else {
				chart[y + cc][x] = 'o';
			}
		}
		sea();
	}
	for (int c = 1; c <= submarine; c++) {
		cout << "Input coordinate of submarine " << c << "(e.g. C2) :";
		cin >> ychar >> xchar;
		y = number(ychar);
		x = xchar - 48;
		cout << "\nInput direction of submarine " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		for (int cc = 0; cc < 3; cc++) {
			if (direction == 1) {
				chart[y][x + cc] = 'o';
			}
			else {
				chart[y + cc][x] = 'o';
			}
		}
		sea();
	}
	for (int c = 1; c <= destroyer; c++) {
		cout << "Input coordinate of destroyer " << c << "(e.g. C2) :";
		cin >> ychar >> xchar;
		y = number(ychar);
		x = xchar - 48;
		cout << "\nInput direction of destroyer " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		for (int cc = 0; cc < 2; cc++) {
			if (direction == 1) {
				chart[y][x + cc] = 'o';
			}
			else {
				chart[y + cc][x] = 'o';
			}
		}
		sea();
	}

}

void game() {
	sea();
	arrange();
}
