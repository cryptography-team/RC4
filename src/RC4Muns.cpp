#include "RC4.h"

BBSG :: BBSG(int length,int num):len(length){
    vector<bool>primes(num,true);
    primes[0] = primes[1] = false;
    for(int i =2 ; i<num; i++){
        if(primes[i]){
            if(i%4 == 3)
                primeNumbers.push_back(i);
            for(int j = i*i;j<num;j+=i){
                primes[j] = false;
            }
        }
    }

}
void BBSG :: generateKey(unsigned char* key){
}
void BBSG :: generateTwoPrimeNumbers(){
     unsigned seed = std ::chrono::system_clock::now().time_since_epoch().count();
     uniform_int_distribution<int> distribution(0,primeNumbers.size()-1);
     shuffle (primeNumbers.begin(),primeNumbers.end(),default_random_engine(seed));
     p = primeNumbers[distribution(generator)];
     q = primeNumbers[distribution(generator)];
     n = p * q;
     s = primeNumbers[distribution(generator)];
}
void RC4 :: generateRandomKey(){}




