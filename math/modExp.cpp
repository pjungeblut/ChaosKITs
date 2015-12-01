//0<=a,b <=n and n <= MAX(ll)/2
ll mult_mod(ll a, ll b, ll n) {
	if(a == 0 || b == 0) return 0;
	if(b == 1) return a % n;
	
	if(b % 2 == 1) return (a + mult_mod(a, b-1, n)) % n;
	else return mult_mod((a + a) % n, b / 2, n);
}

//0<=a,b<=n and n <= MAX(ll)/2
ll pow_mod(ll a, ll b, ll n) {
	if(b == 0) return 1;
	if(b == 1) return a % n;
	
	if(b % 2 == 1) return mult_mod(pow_mod(a, b-1, n), a, n);
	else return pow_mod(mult_mod(a, a, n), b / 2, n);
}
