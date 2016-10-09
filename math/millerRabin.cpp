// Laufzeit: O(log n). Exakt, nicht propabilistisch.
bool isPrime(ll n) {
	if(n == 2) return true;
	if(n < 2 || n % 2 == 0) return false;
	ll d = n - 1, j = 0;
	while(d % 2 == 0) d >>= 1, j++;
	for(int a = 2; a <= min((ll)37, n - 1); a++) {
		ll v = powMod(a, d, n); // Implementierung von oben.
		if(v == 1 || v == n - 1) continue;
		for(int i = 1;  i <= j; i++) {
			v = multMod(v, v, n); // Implementierung von oben.
			if(v == n - 1 || v <= 1) break;
		}
		if(v != n - 1) return false;
	}
	return true;
}
