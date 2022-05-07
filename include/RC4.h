#ifndef RC4_H_INCLUDED
#define RC4_H_INCLUDED
#include <iostream>
using namespace std;
class BBSG
{
private:
    int len , n;
    unsigned char p, q, s;
public :
    BBSG(int length = 128);
    void generateTwoPrimeNumbers();
    void generateKey(unsigned char* key);
};
class RC4
{
private:
    unsigned char S[256] , T[256], *K , *keyStream;
    int k_len;
public:
    RC4();
    void setKey(unsigned char *key);
    void generateRandomKey();
    void generateKeyStream();
    void damageKeyStream();
    string encrypt(const string& plain);
    string decrypt(const string& cipher);
};

#endif // RC4_H_INCLUDED
