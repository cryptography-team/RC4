#ifndef RC4_H_INCLUDED
#define RC4_H_INCLUDED
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
class BBSG {
private:
  int len, n, s;
  vector<int> primeNumbers;
  unsigned char p, q;
  mt19937 rng;

public:
  BBSG(int length, int num);
  void generateTwoPrimeNumbers();
  void generateKey(unsigned char *key);
};
class RC4 {
private:
  enum { SIZE = 256 };
  unsigned char *K;
  int k_len;

public:
  RC4(int len);
  void setKey(const string &key);
  const unsigned char *generateRandomKey(int len);
  string encrypt(const string &plain);
  string decrypt(const string &cipher);
  ~RC4();
};

#endif // RC4_H_INCLUDED
