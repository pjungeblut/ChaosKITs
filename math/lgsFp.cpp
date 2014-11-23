void normalLine(ll n, ll line, ll p) { //normalisiert Zeile line
	ll factor = multInv(mat[line][line], p); //Implementierung von oben
	for (ll i = 0; i <= n; i++) {
		mat[line][i] *= factor;
		mat[line][i] %= p;
	}
}

void takeAll(ll n, ll line, ll p) { //zieht Vielfaches von line von allen anderen Zeilen ab
	for (ll i = 0; i < n; i++) {
		if (i == line) continue;
		ll diff = mat[i][line]; //abziehen
		for (ll j = 0; j <= n; j++) {
			mat[i][j] -= (diff * mat[line][j]) % p;
			while (mat[i][j] < 0) {
				mat[i][j] += p;
			}
		}
	}
}

void gauss(ll n, ll p) { //n x n+1-Matrix, Koerper F_p
	for (ll line = 0; line < n; line++) {
		normalLine(n, line, p);
		takeAll(n, line, p);
	}
}