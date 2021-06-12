#include <iostream>
#include <string>
#include "project.h"
using namespace std;

int main(void)
{
	system("clear");
	Map<char,string> m;
	m.initilize(); // to initilize the map using avl tree with the encode for each character
	string upspace = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // to center the display
	cout << upspace ;
	cout << "+---------------------+\n";
	cout << "|      MAIN MENU      |" << endl; // main menu
	cout << "+---------------------+\n";
	cout << "|     1. Encode       |" << endl;
	cout << "|     2. Decode       |" << endl ;
	cout << "+---------------------+\n";
	int opt;								// to select the opertion to perform
	cout << endl << "Enter the option : "; // to choose the operation
	cin >> opt;
	cout << endl ;
	string str ;	// the string that is to be encoded
	system("clear");
	cout << upspace;
	if (opt == 1) // to select the encode space
	{
		cout << "Enter the Message To Encode (finish it with a ~) : " << endl << endl ;
		getline(cin,str);  // to get the message
		while (str[str.size()-1] != '~'){ 
			string temp;
			getline(cin,temp);   // to get the message line by line
			str += '\n' + temp;
		}
		str.resize(str.size()-1);
		string encode;   		// to store the encoded message
		srand (time(NULL));		// to produce random character
		/* salting */
		for ( int s = 3 ; s < str.size() ; s += 4){
			char rch = 'A' + rand() % 60; // adding random character to the original message
			str.insert(s,1,rch);
		}
		/*  encoding  */
		for ( int j = 0 ; j < str.size() ; j++){
			encode += m.values(str[j]);		// finding the appropriate encode for the given charcter
		}
		cout << endl << "ENCODED MESSAGE : " << endl;
		cout << "-----------------" << endl;
		for ( int e = 0 ; e < encode.size() ; e++) // displaying the encoded message
		{
			if (e % 60 == 0){
				cout << endl;
			}
			cout << encode[e] ;
		}
		cout << endl << endl ;
	}
	else if (opt == 2)  // to select the decoded version 
	{
		getchar();
		string encode;  // to be the encoded message that is to be decoded
		cout << "Enter the Encoded message to Decode (finish it with a ~) : " << endl << endl;
		getline(cin,encode);
		while (encode[encode.size()-1] != '~'){ // getting the encoded message line by line
			string s ;
			getline(cin,s);
			encode += s;
		}
		encode.resize(encode.size()-1);
		cout << endl << "DECODED MESSAGE : " << endl; 
		cout << "-----------------" << endl;
		string result;						// to store the decoded message
		/*  decoding */
		for ( int i = 0 ; i < encode.size() ; i += 5){
			string decode;
			for(int j = i ; j < i+5 ; j++){ 	// extracting 5 encoded characters to decode
				decode += encode[j];
			}
			result += m.findKey(decode) ; 	// find the orginal charcter for the encoded data
		}
		/* remove the salting */
		for ( int s = 3; s < result.size() ; s += 3){
			result.erase(result.begin() + s); // to remove the random characters addded during encoding
		}
		cout << result << endl << endl; // printing the decoded message
	}
	return 0;
}
