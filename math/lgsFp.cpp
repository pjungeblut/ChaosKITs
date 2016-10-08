// Laufzeit: O(n^3)
void swapLines(int n, int l1, int l2) {
	for (int i = 0; i <= n; i++) swap(mat[l1][i], mat[l2][i]);
}

void normalLine(int n, int line, ll p) {
	ll factor = multInv(mat[line][line], p); // Implementierung von oben.
	for (int i = 0; i <= n; i++) {
		mat[line][i] *= factor;
		mat[line][i] %= p;
}}

void takeAll(int n, int line, ll p) {
	for (int i = 0; i < n; i++) {
		if (i == line) continue;
		ll diff = mat[i][line];
		for (int j = 0; j <= n; j++) {
			mat[i][j] -= (diff * mat[line][j]) % p;
			mat[i][j] %= p;
			if (mat[i][j] < 0) mat[i][j] += p;
}}}

void gauss(int n, ll p) { // nx(n+1)-Matrix, Körper F_p.
	for (int line = 0; line < n; line++) {
		int swappee = line;
		while (mat[swappee][line] == 0) swappee++;
		swapLines(n, line, swappee);
		normalLine(n, line, p);
		takeAll(n, line, p);
}}
