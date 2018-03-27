#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include"Main.h"
#include"getch.cpp"

using namespace std;
/* C++ file de/encryptor uses very simple algoritm as standard edit and choose from included crypto++ database
   for better cryptography something like AES. Written simple .getch() replacement for linux 
*/

//set password could also be done on the file depending on which function choosen from crypto++
passkey::passkey()
{
    password = 88;
}
//prompt password from user
void passkey::getkey()
{
    cout << "Enter the key: ";
    cin >> key;
}

// check if set password is correct when decrypting 
int passkey::checkkey(int a)
{
    if(a==key)
        return 1;
    else
        return 0;
}

char filenaam[40];


//main loop to prompt user for filename and set or check password
int main()
{
     int a, pw, x, k;
     string c;

         cout << "Enter the correct password: ";
     cin>>pw;
        if(pw!=88)
        {
            cout << "Sorry you entered the wrong password" << endl;
            getch();
            return 0;
        }

     cout << "For ENCRYPTION enter 1\nFor DECRYPTION enter 2\nTo terminate the program enter 3" << endl;
     cin>> a;
     if(a==1)
     {
         file1.getkey();

         cout << "Give your file a name\neg: \"Input_Data\"" << endl;
         cin >> filenaam;

         strcat(filenaam,".txt");

        cout << "Enter data to the file" << endl;

        ofstream InputData(filenaam);

        while(cin >> c)
        {
            InputData << c << " ";
        }

        InputData.close();

        encrypt(file1);

        getch();

        return 0;

     }
     else if(a==2)
     {
         file1.getkey();

         cout << "Enter name of your file\neg: Input_Data.txt" << endl;
         cin >> filenaam;

         strcat(filenaam,".txt");

        decrypt(file1);

        getch();

        return 0;

     }

     else if (a==3)
     {
         return 0;
     }
}

// Does the encrypting edit the chyper used inside the do/while loop
// take encryption functions from /Crypto++
void encrypt(passkey file)
{
    char encfilenaam[50] = "Encrypted_";
    strcat(encfilenaam,filenaam);

    int n;

    srand(file.key);

    ifstream OutputData(filenaam);

    char ch[50] = "";

    ofstream InputData(encfilenaam);

    OutputData.getline(ch,49);
    do
    {
        n= 1 + rand()%9;
        for(int i=0; i<strlen(ch); i++)
        {
            ch[i] = ch[i] + n;
        }
        InputData << ch;
    }
    while(OutputData.getline(ch,49));

    OutputData.close();
    InputData.close();

    cout << "File is successfully encrypted"  << endl;
    cout << "Encrypted data is stored in file with name: " << encfilenaam << endl;
}

// Does the decrypting edit the chyper used inside the do/while loop
// take  functions from /Crypto+++
void decrypt(passkey file)
{
    char decfilenaam[50] = "Decrypted_";
    strcat(decfilenaam,filenaam);

    int m;

    srand(file.key);

    ifstream OutputData(filenaam);

    char ch[50] = "";

    ofstream InputData(decfilenaam);

    OutputData.getline(ch,49);
    do
    {
        m= 1 + rand()%9;
        for(int i=0; i<strlen(ch); i++)
        {
            ch[i] = ch[i] - m;
        }
        InputData << ch;
    }
    while(OutputData.getline(ch,49));

    OutputData.close();
    InputData.close();

    cout << "File successfully decrypted" << endl;
    cout << "Decrypted text is stored in " << decfilenaam << endl;
}


