ll extendedEuclid(ll a, ll b, ll &x, ll &y) { // a*x + b*y = ggt(a, b).
	if (a == 0) { x = 0; y = 1; return b; }
	ll x1, y1, d = extendedEuclid(b % a, a, x1, y1);
	x = y1 - (b / a) * x1; y = x1;
	return d;
}
