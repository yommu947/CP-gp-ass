#include<iostream>
#include<iomanip>
using namespace std;

//globle variables: settings
int seasize = 10, carrier = 1, battleship = 1, submarine = 1, destroyer = 1;
char displaypc = 'n';
char pcstart = 'p';
int total_size;
char chart[10][10];
char input[5];
bool quit = true;
bool continues = false;

char alphabet(int);//turn number into character
int number(char);//turn number into character
void setting();
void sea();
void clear();
void arrange();
void game();
void credits();
void instructions();
int quitfunction(char input[]);

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
		main();break;
	case 4: credits();
		system("cls");
		main();
		break;
	case 5: return 0;
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

			while ((total_size >= seasize * seasize) || (carrier < 1 || carrier > 5 ) || (battleship < 1 || battleship > 5 ) || (submarine < 1 || submarine > 5 ) || (destroyer < 1 || destroyer > 5 ))
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
	cout << "+"<<endl;
}


void clear() {
	for (int c = 1; c <= 10; c++) {
		for (int cc = 1; c <= 10; c++) {
			chart[c][cc] = ' ';
		}
	}
}

void arrange() {
	char xchar, ychar;
	int x, y;
	char direction[5];
	bool allow;
	for (int c = 1; c <= carrier; c++) {
		do{
		allow = true;
		cout << "Input coordinate of carrier "<<c<<"(e.g. C2) :";
		cin >> input;
		quitfunction(input);
		if(continues == true){
			cout << "Input coordinate of carrier "<<c<<"(e.g. C2) :";
			cin >> input;
		}
		y = number(input[0]);
		x = input[1] - 48;
		cout << "\nInput direction of carrier " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		quitfunction(direction);
		if(quit == true){
			cout << "\nInput direction of carrier " << c << "(1 for horizontal, 2 for vertical):";
			cin >> direction;
		}
		cout << endl;
		
		
		for (int cc = 0; cc < 5; cc++) {
			if (direction[0] == '1') {
				if(chart[y][x + cc] == 'o'){allow = false;}
			}
			else {
				if(chart[y + cc][x] == 'o'){allow = false;}
			}
		}

	if(direction[0] == '1'){
		if(x + 4 > seasize - 1){
			allow = false;
		}
	} else {
		if(y + 4 > seasize - 1){
			allow = false;
		}
	}

	if(y == 10 || x < 0 || x > 9 || input[2] != '\0'|| (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0'){
		allow = false;
	}
	
		} while (allow == false);
		
		system("cls");
		if(allow=true){
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
		cout << "Input coordinate of Battleship " << c << "(e.g. C2) :";
		cin >> input;
		quitfunction(input);
		if(continues == true){
			cout << "Input coordinate of Battleship "<<c<<"(e.g. C2) :";
			cin >> input;
		}
		y = number(input[0]);
		x = input[1] - 48;
		cout << "\nInput direction of Battleship " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		quitfunction(direction);
		if(quit == true){
			cout << "\nInput direction of Battleship " << c << "(1 for horizontal, 2 for vertical):";
			cin >> direction;
		}
		for (int cc = 0; cc < 4; cc++) {
			if (direction[0] == '1') {
				if(chart[y][x + cc] == 'o'){allow=false;}
			}
			else {
				if(chart[y + cc][x] == 'o'){allow=false;}
			}
		}
	if(direction[0] == '1'){
		if(x + 3 > seasize - 1){
			allow = false;
		}
	} else {
		if(y + 3 > seasize - 1){
			allow = false;
		}
	}

	if(y == 10 || x < 0 || x > 9 || input[2] != '\0'|| (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0'){
		allow = false;
	}
	
		} while (allow == false);
		
		system("cls");
		if(allow=true){
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
		do{
		allow = true;
		cout << "Input coordinate of submarine " << c << "(e.g. C2) :";
		cin >> input;
		quitfunction(input);
		if(continues == true){
			cout << "Input coordinate of submarine "<<c<<"(e.g. C2) :";
			cin >> input;
		}
		y = number(input[0]);
		x = input[1] - 48;
		cout << "\nInput direction of submarine " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		quitfunction(direction);
		if(continues == true){
			cout << "\nInput direction of submarine " << c << "(1 for horizontal, 2 for vertical):";
			cin >> direction;
		}
		for (int cc = 0; cc < 3; cc++) {
			if (direction[0] == '1') {
				if(chart[y][x + cc] == 'o'){allow=false;}
			}
			else {
				if(chart[y + cc][x] == 'o'){allow=false;}
			}
		}
	if(direction[0] == '1'){
		if(x + 2 > seasize - 1){
			allow = false;
		}
	} else {
		if(y + 2 > seasize - 1){
			allow = false;
		}
	}

	if(y == 10 || x < 0 || x > 9 || input[2] != '\0'|| (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0'){
		allow = false;
	}
	
		} while (allow == false);
		
		system("cls");
		if(allow=true){
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
		cout << "Input coordinate of destroyer " << c << "(e.g. C2) :";
		cin >> input;
		quitfunction(input);
		if(continues == true){
			cout << "Input coordinate of destroyer "<<c<<"(e.g. C2) :";
			cin >> input;
		}
		y = number(input[0]);
		x = input[1] - 48;
		cout << "\nInput direction of destroyer " << c << "(1 for horizontal, 2 for vertical):";
		cin >> direction;
		quitfunction(direction);
		if(continues == true){
			cout << "\nInput direction of destroyer " << c << "(1 for horizontal, 2 for vertical):";
			cin >> direction;
		}
	for (int cc = 0; cc < 2; cc++) {
			if (direction[0] == '1') {
				if(chart[y][x + cc] == 'o'){
					allow=false;
				}
			}
			else {
				if(chart[y + cc][x] == 'o'){allow=false;}
			}
		}
	if(direction[0] == '1'){
		if(x + 1 > seasize - 1){
			allow = false;
		}
	} else {
		if(y + 1 > seasize - 1){
			allow = false;
		}
	}

	if(y == 10 || x < 0 || x > 9 || input[2] != '\0'|| (direction[0] != '1' && direction[0] != '2') || direction[1] != '\0'){
		allow = false;
	}
	
		} while (allow == false);
		
	
		system("cls");
		if(allow=true){
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

void game() {
	sea();
	arrange();


}


void instructions() {
	// option 3: Instructions 








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

int quitfunction(char input[]){
	char quit2[] = "Quit";
	quit = true;
	continues = false;
	for(int i = 0; i < 4; i++){
		if(input[i] != quit2[i]){
			quit = false;
		}
	}
	if(quit == true){
		cout << "Do you want to quit?(y=yes,n=no): ";
		char ans;
		cin >> ans;
		if(ans == 'y' || ans == 'Y'){
			system("cls");
			return main();
		}
		else{
			continues = true;
		}
	}
}
