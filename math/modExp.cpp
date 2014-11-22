ll modPow(ll b, ll e, ll p) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll half = modPow(b, e / 2, p), res = (half * half) % p;
	if (e & 1) res *= b; res %= p;
	return res;
}