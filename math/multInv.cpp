ll multInv(ll n, ll p) { //berechnet das multiplikative Inverse von n in F_p
	extendedEuclid(n, p); //implementierung von oben
	x += ((x / p) + 1) * p;
	return x % p;
}