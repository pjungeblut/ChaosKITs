// Laufzeit: O(log (n) + log(p))
ll multInv(ll n, ll p) { // Berechnet das multiplikative Inverse von n in F_p.
	extendedEuclid(n, p); // Implementierung von oben.
	x += ((x / p) + 1) * p;
	return x % p;
}
