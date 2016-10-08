// Laufzeit: O(log(b))
ll multMod(ll a, ll b, ll n) {
	if(a == 0 || b == 0) return 0;
	if(b == 1) return a % n;
	if(b % 2 == 1) return (a + multMod(a, b-1, n)) % n;
	else return multMod((a + a) % n, b / 2, n);
}

// Laufzeit: O(log(b))
ll powMod(ll a, ll b, ll n) {
	if(b == 0) return 1;
	if(b == 1) return a % n;
	if(b % 2 == 1) return multMod(powMod(a, b-1, n), a, n);
	else return powMod(multMod(a, a, n), b / 2, n);
}
