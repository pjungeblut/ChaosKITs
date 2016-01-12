#define N 10000001
vector<ll> primes;
//Finds all prime numbers between 0..N
//Use this method for N < 10000000 to avoid memory access errors
void primeSieve() {
  bitset<N> isPrime; isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for(ll i = 2; i < N+1; i+=2) {
      if(isPrime[i]) {
	      for(ll j = i*i; j >= 0 && j < N+1; j+=i) isPrime[j] = 0;
	      primes.push_back(i);
      }
      if(i == 2) i--;
  }
}