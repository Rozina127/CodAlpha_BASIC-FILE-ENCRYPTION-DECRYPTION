#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Encryption function using Caesar cipher
void encrypt_file(const string& infile, const string& outfile, int key)
{
    ifstream fin(infile);
    ofstream fout(outfile);

    if (!fin)
    {
        cout << "Error: Input file cannot be opened." << endl;
        return;
    }

    if (!fout)
    {
        cout << "Error: Output file cannot be created." << endl;
        return;
    }

    char ch;
    while (fin.get(ch))
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                ch = char(int(ch + key - 65) % 26 + 65);
            }
            else
            {
                ch = char(int(ch + key - 97) % 26 + 97);
            }
        }
        fout << ch;
    }

    fin.close();
    fout.close();
}
// Decryption function using Caesar cipher 
void decrypt_file(const string& infile, const string& outfile, int key) 
{
    ifstream fin(infile);
    ofstream fout(outfile);

    if (!fin)
    {
        cout << "Error: Input file cannot be opened." << endl;
        return;
    }

    if (!fout)
    {
        cout << "Error: Output file cannot be created." << endl;
        return;
    }

    char ch;
    while (fin.get(ch)) 
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                ch = char(int(ch - key - 65 + 26) % 26 + 65);
            }
            else {
                ch = char(int(ch - key - 97 + 26) % 26 + 97);
            }
        }
        fout << ch;
    }

    fin.close();
    fout.close();
}

// Main function
int main() {
    string infile, outfile;   // Input and output file 
    int key;
    char choice;

    cout << "Enter input file name: ";
    cin >> infile;

    cout << "Enter output file name: ";
    cin >> outfile;

    cout << "Enter encryption/decryption key: ";
    cin >> key;

    cout << "Enter 'E' for encryption or 'D' for decryption: ";
    cin >> choice;

    if (choice == 'E' || choice == 'e')
    {
        encrypt_file(infile, outfile, key);
        cout << "*** File Encrypted Successfully ***" << endl;
    }
    else if (choice == 'D' || choice == 'd') 
    {
        decrypt_file(infile, outfile, key);
        cout << "*** File Decrypted Successfully ***" << endl; 
    }
    else
    {
        cout << "Invalid choice. Please enter 'E' or 'D' for choice." << endl;
    }

    return 0;
}
