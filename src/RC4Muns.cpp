#include "RC4.h"

BBSG :: BBSG(int length,int num):len(length),rng(chrono::steady_clock::now().time_since_epoch().count())
{
    vector<bool>primes(num,true);
    primes[0] = primes[1] = false;
    for(int i =2 ; i<num; i++)
    {
        if(primes[i])
        {
            if(i%4 == 3)
                primeNumbers.push_back(i);
            for(int j = i*i; j<num; j+=i)
            {
                primes[j] = false;
            }
        }
    }

}
void BBSG :: generateKey(unsigned char* key)
{
    int x = (long long)s*s % n;
    for(int i = 0 ; i<len; ++i)
    {
        key[i] = 0;
        for(int j = 0 ; j<8; j++)
        {
            x = x*x % n;
            key[i] |= (x % 2) << j;
        }
    }
}
void BBSG :: generateTwoPrimeNumbers()
{

    p = primeNumbers[uniform_int_distribution<int>(0, primeNumbers.size()-1)(rng)];
    q = primeNumbers[uniform_int_distribution<int>(0, primeNumbers.size()-1)(rng)];
    n = p * q;
    int limit;
    if(p == q)
    {
        limit = n - n/q;
    }
    else
    {
        limit = n - n/p + n/q;
    }
    limit = uniform_int_distribution<int>(0, limit)(rng);
    for(int i=1, j=0; i<n; i++)
    {
        if(i%p != 0 && i%q != 0)
        {
            if(j == limit)
            {
                s = i;
                break;
            }
            j++;
        }
    }
}
void RC4 :: generateRandomKey(int len)
{
    delete K;
    K = new unsigned char[len];
    BBSG randomKey(len,1000);
    randomKey.generateKey(K);
}




