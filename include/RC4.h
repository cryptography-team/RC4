#ifndef RC4_H_INCLUDED
#define RC4_H_INCLUDED
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;
class BBSG
{
private :
    int len , n;
    vector<int> primeNumbers;
    default_random_engine generator;
    unsigned char p, q, s;
public :
    BBSG(int length ,int num);
    void generateTwoPrimeNumbers();
    void generateKey(unsigned char* key);
};
class RC4
{
private:
    unsigned char *K;
    int k_len;
public:
    RC4(int len);
    void setKey(unsigned char *key);
    void generateRandomKey();
    string encrypt(const string& plain);
    string decrypt(const string& cipher);
    ~RC4();
};

#endif // RC4_H_INCLUDED
