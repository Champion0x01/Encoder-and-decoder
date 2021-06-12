#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main(){
	int choice;
	char *name, *ext, *com;
	
	name = new char[50];
	com = new char[75];
	ext = new char[75];
	
	cout << "File Compressor working on Huffman Encoding" << endl;
	cout << "1. Compress" << endl;
	cout << "2. Extract" << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	
	cout << "Place the file to be compressed or extracted in the same folder as the folder with this executable" << endl;
	cout << "Enter filename : ";
	cin >> name;
	
	strcpy(ext,"./extract ");
	strcpy(com,"./compress ");
	
	strcat(ext,name);
	strcat(com,name);
	
	switch(choice){
		case 1: system(com);
				break;
		case 2: system(ext);
				break;
		default: cout << "Invalid Choice Terminating Program..." << endl;
				exit(0);
	}
	
	return 0;
}