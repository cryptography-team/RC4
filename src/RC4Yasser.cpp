#include "RC4.h"
#include <cstring>

using std::strcpy;
using std::strlen;
using std::swap;

RC4::RC4(int len) { generateRandomKey(len); }

string RC4::encrypt(const string &plain) {
  int S[SIZE], T[SIZE];
  for (int i = 0; i < SIZE; i++) {
    S[i] = i;
    T[i] = K[i % k_len];
  }

  int j = 0;
  for (int i = 0; i < SIZE; i++) {
    j = (j + S[i] + T[i]) % SIZE;
    swap(S[i], S[j]);
  }

  string cipher;
  int i = j = 0;
  for (char M : plain) {
    i = (i + 1) % SIZE;
    j = (j + S[i]) % SIZE;
    swap(S[i], S[j]);
    int t = (S[i] + S[j]) % SIZE;
    cipher += M ^ S[t];
  }

  return cipher;
}

string RC4::decrypt(const string &cipher) { decrypt(cipher); }

void RC4::setKey(unsigned char *key) {
  int newSize = strlen(key);
  if (k_len != newSize) {
    k_len = newSize;
    delete[] K;
    key = new unsigned char[k_len];
  }
  strcpy(K, key);
}

RC4::~RC4() { delete[] K; };
