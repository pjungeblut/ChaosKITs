bool isPrime(ll n) { // Miller Rabin Primzahltest. O(log n)
	if(n == 2) return true;
	if(n < 2 || n % 2 == 0) return false;
	ll d = n - 1, j = 0;
	while(d % 2 == 0) d >>= 1, j++;
	for(int a = 2; a <= min((ll)37, n - 1); a++) {
		ll v = powMod(a, d, n); // Implementierung von oben.
		if(v == 1 || v == n - 1) continue;
		for(int i = 1;  i <= j; i++) {
			v = (v * v) % n;
			if(v == n - 1 || v <= 1) break;
		}
		if(v != n - 1) return false;
	}
	return true;
}

ll rho(ll n) { // Findet Faktor < n, nicht unbedingt prim.
  if (~n & 1) return 2;
  ll c = rand() % n, x = rand() % n, y = x, d = 1;
  while (d == 1) {
    x = ((x * x) % n + c) % n;
    y = ((y * y) % n + c) % n;
    y = ((y * y) % n + c) % n;
    d = gcd(abs(x - y), n); // Implementierung von oben.
  }
  return d == n ? rho(n) : d;
}

void factor(ll n, map<ll, int> &facts) {
  if (n == 1) return;
  if (isPrime(n)) {
    facts[n]++;
    return;
  }
  ll f = rho(n);
  factor(n / f, facts);
  factor(f, facts);
}
