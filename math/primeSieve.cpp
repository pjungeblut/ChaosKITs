#include <iostream>
#include <vector>

vector<int> primeSieve(int n) {
	vector<int> primes;
	vector<bool> isPrime(n,true);
	for(int i = 2; i < n; i+=2) {
		if(i*i <= n) {
			if(isPrime[i]) {
				primes.push_back(i);
				for(int j = 2; i*j < n; j++) {
					isPrime[i*j] = false;
				}
			}
		}
		else {
			if(isPrime[i])
				primes.push_back(i);
		}
		if(i == 2)
			i--;
	}
	return primes;
} 
