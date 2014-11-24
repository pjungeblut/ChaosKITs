const ll PRIME_SIZE = 10000000;
vector<int> primes; //call primeSieve(PRIME_SIZE); before

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
		else pos++;
		if(primes[pos]*primes[pos] > n) break;
	}
	if(num != 1) factor.push_back(num);
	return factor;
}
