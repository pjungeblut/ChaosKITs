// Laufzeit: O(n log(n)).
typedef complex<double> cplx; // Eigene Implementierung ist noch deutlich schneller.
vector<cplx> fft(const vector<cplx> &a, bool inverse = 0) { // a.size() muss eine Zweierpotenz sein!
	int logn = 1, n = a.size();
	vector<cplx> A(n);
	while ((1 << logn) < n) logn++;
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (int k = 0; k < logn; k++) j = (j << 1) | ((i >> k) & 1);
		A[j] = a[i];
	}
	for (int s = 2; s <= n; s <<= 1) {
		double angle = 2 * PI / s * (inverse ? -1 : 1);
		cplx ws(cos(angle), sin(angle));
		for (int j = 0; j < n; j+= s) {
			cplx w = 1;
			for (int k = 0; k < s / 2; k++) {
				cplx u = A[j + k], t = A[j + s / 2 + k];
				A[j + k] = u + w * t;
				A[j + s / 2 + k] = u - w * t;
				if (inverse) A[j + k] /= 2,	A[j + s / 2 + k] /= 2;
				w *= ws;
			}
		}
	}
	return A;
}

// Polynome: a[0] = a_0, a[1] = a_1, ... und b[0] = b_0, b[1] = b_1, ...
// Integer-Koeffizienten: Runde beim Auslesen der Koeffizienten: (int)round(a[i].real()) 
vector<cplx> a = {0,0,0,0,1,2,3,4}, b = {0,0,0,0,2,3,0,1};
a = fft(a); b = fft(b);
for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];
a = fft(a,1); // a = a * b
