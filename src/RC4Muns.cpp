#include "RC4.h"
/**
The Sieve of Eratosthenes algorithm is used to generate prime numbers.
at the beginning we write down all numbers between 2 and num .
We mark all proper multiples of 2 (since 2 is the smallest prime number) as
composite. A proper multiple of a number X , is a number greater than X  and
divisible by X. Then we find the next number that hasn't been marked as
composite, in this case it is 3. Which means 3 is prime, and we mark all proper
multiples of 3 as composite. The next unmarked number is 5, which is the next
prime number, and we mark all proper multiples of it. And we continue this
procedure until we processed all numbers in the row.
**/
BBSG ::BBSG(int length, int num)
    : len(length), rng(chrono::steady_clock::now().time_since_epoch().count()) {
  vector<bool> primes(num, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i < num; i++) {
    if (primes[i]) {
      // Push the number to the primeNumbers vector if it is prime and 3 =
      // number mod 4.
      if (i % 4 == 3)
        primeNumbers.push_back(i);
      for (int j = i * i; j < num; j += i) {
        primes[j] = false;
      }
    }
  }
  generateTwoPrimeNumbers();
}
void BBSG ::generateKey(unsigned char *key) {
  int x = ((long long)s * s) % n;
  for (int i = 0; i < len; ++i) {
    key[i] = 0;
    for (int j = 0; j < 8; j++) {
      x = (1LL * x * x) % n;
      key[i] |= (x % 2) << j;
    }
  }
}
void BBSG ::generateTwoPrimeNumbers() {
  /// uniform_int_distribution<int>(0, primeNumbers.size()-1)(rng) used to,
  /// generate a random number from 0 to size of the primes vector.
  p = primeNumbers[uniform_int_distribution<int>(0,
                                                 primeNumbers.size() - 1)(rng)];
  q = primeNumbers[uniform_int_distribution<int>(0,
                                                 primeNumbers.size() - 1)(rng)];
  n = p * q;
  // limit is a count of numbers not divisible by p and q
  int limit;
  if (p == q) {
    limit = n - n / q;
  } else {
    limit = n - (n / p + n / q);
  }
  // Generate a random index to select s
  limit = uniform_int_distribution<int>(0, limit)(rng);
  for (int i = 1, j = 0; i < n; i++) {
    if (i % p != 0 && i % q != 0) {
      if (j == limit) {
        s = i;
        break;
      }
      j++;
    }
  }
}
const unsigned char *RC4 ::generateRandomKey(int len) {
  delete[] K;
  K = new unsigned char[len];
  k_len = len;
  BBSG randomKey(len, 1000);
  randomKey.generateKey(K);
  return K;
}
