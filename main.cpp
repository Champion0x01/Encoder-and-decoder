#include<iostream>

using namespace std;

int main(){
	int choice;
	string upspace = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	while(1){
	cout << upspace ;
	cout << "+-------------------------+\n";
	cout << "|     (En/De)Code         |" << endl;
	cout << "+-------------------------+\n";
	cout << "|  1. Random encoding     |" << endl;
	cout << "|  2. Caesar Cipher       |" << endl ;
	cout << "|  3. Compress/Decompress |" << endl;
	cout << "+-------------------------+\n";
	
	cout << "Enter 4 to exit" << endl;
	
	cout << "Enter your choice : ";
	cin >> choice;
	
	switch(choice){
		case 1: system("./project");
				break;
		case 2: cout << upspace;
				system("./cipher");
				break;
		case 3: cout << upspace;
				system("./huffman");
				break;
		case 4: system("clear");
				cout << "Adios!" << endl;
				return 0;
		default: cout << "Please enter a valid option";
	}
	}
	
	return 0;
}