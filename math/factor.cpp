#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ll;

const ll PRIME_SIZE = 10000000;
vector<int> primes;

//Call before calculating anything
void primeSieve() {
	vector<int> isPrime(PRIME_SIZE,true);
	for(ll i = 2; i < PRIME_SIZE; i+=2) {
		if(isPrime[i]) {
			primes.push_back(i);
			if(i*i <= PRIME_SIZE) {
				for(ll j = i; i*j < PRIME_SIZE; j+=2) isPrime[i*j] = false;
			}
		}
		if(i == 2)
			i--;
	}
} 

//Factorize the number n
vector<int> factorize(ll n) {
	vector<int> factor;
	ll num = n;
	int pos = 0;
	while(num != 1)  {
		if(num % primes[pos] == 0) {
			num /= primes[pos];
			factor.push_back(primes[pos]);
		}
		else
			pos++;
		if(primes[pos]*primes[pos] > n)
			break;
	}
	if(num != 1)
		factor.push_back(num);
	return factor;
	
}
