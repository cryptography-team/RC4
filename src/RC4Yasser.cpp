#include "RC4.h"
#include <cstring>

RC4::RC4(int len) : k_len(1), K(new char[1]) {
  K[0] = '\0';
  generateRandomKey(len);
}
#include <iostream>
string RC4::encrypt(const string &plain) {
  unsigned int S[SIZE], T[SIZE];
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
    unsigned char ci = M ^ S[t];
    cipher.push_back(ci);
  }

  return cipher;
}

string RC4::decrypt(const string &cipher) { return encrypt(cipher); }

void RC4::setKey(const string &key) {
  int newSize = key.size();
  if (k_len != newSize) {
    k_len = newSize;
    delete[] K;
    K = new char[k_len + 1];
  }
  strcpy(K, key.c_str());
}

RC4::~RC4() { delete[] K; };
