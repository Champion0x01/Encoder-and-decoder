// C++ program to demonstrate the working of public inheritance

#include <iostream>
#include <string>
//#include "cipher.h"
using namespace std;

class text{

   protected:
    string message;
    int key;

   public:
    // function to access private member
    void getStringAndKey() {
        cout << "Enter the string: ";
        cin >> message;
        cout << "Enter the key: ";
        cin >> key;
    }

    void textReset()
    {
         message.erase();
    }
};

class cipher : public text{
   public:
    // function to access protected member from Base
    void encode(){
        string encodedString = message;
        //cout << message << endl;
        for (int i = 0; i < message.length(); ++i)
            encodedString[i] = encodedString[i] + (key % 26);
        cout << "Encoded piece of text is " << encodedString << endl;
        //return encodedString;
    }
};

class decipher: public text{
  public:
    // function to access protected member from Base
    void decode(){
        string decodedString = message;
        //cout << message << endl;
        for (int i = 0; i < message.length(); ++i)
            decodedString[i] = message[i] - (key % 26); 
        cout << "Decoded piece of text is " << decodedString << endl;
        //return decodedString;
    }  
};

int main() {
    cout << "***************CAESAR CIPHER***************\n";
    int choice = 3;
    cout <<"1. Encode a piece of text\n2. Decode a piece of text\n";
    while (choice)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cipher str;
            str.getStringAndKey();
            str.encode();
            str.textReset();
        }
        else if (choice == 2)
        {
            decipher str;
            str.getStringAndKey();
            str.decode();
            //cout << "Decoded piece of text is " << str.decode() << endl;
            str.textReset();
        }
        cout << "Press 0 if you wish to exit or 1 to continue\n";
        cin >> choice;
    }
    return 0;
}