#include "RC4.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  RC4 streamCipher(128);
  string cipher;
  while (true) {
    cout << "Choose one of the following options:\n";
    cout << "\t1- Encrypt a plain text\n";
    cout << "\t2- Decrypt the last cipher text\n";
    cout << "\t3- Set a random key\n";
    cout << "\t4- Set a custom key\n";
    cout << "\t*- Exit the program\n";
    cout << "\nYour option: " << flush;
    int option;
    cin >> option;
    cin.ignore();
    if (option == 1) {
      cout << "Enter your plain text:\n\t" << flush;
      string plain;
      getline(cin, plain);
      cipher = streamCipher.encrypt(plain);
      cout << "The corresponding cipher text is:\n\t" << cipher << endl;
    } else if (option == 2) {
      cout << "The corresponding plain text is:\n\t"
           << streamCipher.decrypt(cipher) << endl;
    } else if (option == 3) {
      cout << "Enter its length: " << flush;
      int len;
      cin >> len;
      cin.ignore();
      cout << "The following key has been generated and set:\n\t"
           << streamCipher.generateRandomKey(len) << endl;
    } else if (option == 4) {
      cout << "Enter your key:\n\t" << flush;
      string key;
      getline(cin, key);
      streamCipher.setKey(key);
      cout << "The key has been set\n";
    } else
      break;
    cout << endl;
#ifdef __unix__
    system("read -p \"Press return key to continue...\"");
    system("clear");
#else
    system("pause");
    system("cls");
#endif
  }
  return 0;
}
