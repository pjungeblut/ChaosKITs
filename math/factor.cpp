typedef pair<int,int> ii;
//Factorize a number n in its prime factors
//Call primeSieve-method before with N > sqrt(n)
//Return: Returns a vector of pairs, where the first entry in the pair is
//the prime factor p and the second counts how many times p divides n
vector<ii> factorize(ll n) {
  vector<ii> fact; ll num = n, i = 0, c = 0;
  while(num != 1) {
    if(num % primes[i] == 0) {
      c++; num /= primes[i];
    } else {
      if(c > 0)
	      fact.push_back(make_pair(primes[i],c));
      i++; c = 0;
      if(primes[i]*primes[i] > num) break;
    }
  }
  if(num != 1) fact.push_back(make_pair(num,c+1));
  return fact;
}