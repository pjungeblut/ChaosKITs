#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ll;

vector<int> primeSieve(ll n) {
	vector<int> primes;
	vector<bool> isPrime(n,true);
	for(ll i = 2; i < n; i+=2) {
		if(isPrime[i]) {
			primes.push_back(i);
			if(i*i <= n) {
				for(ll j = i; i*j < n; j+=2) isPrime[i*j] = false;
			}
		}
		if(i == 2)
			i--;
	}
	return primes;
} 
