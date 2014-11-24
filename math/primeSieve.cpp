vector<int> primes;
void primeSieve(ll n) { //berechnet die Primzahlen kleiner n
	vector<int> isPrime(n,true);
	for(ll i = 2; i < n; i+=2) {
		if(isPrime[i]) {
			primes.push_back(i);
			if(i*i <= n) {
				for(ll j = i; i*j < n; j+=2) isPrime[i*j] = false;
			}
		}
		if(i == 2) i--;
	}
} 
