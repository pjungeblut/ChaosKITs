// Laufzeit: init: O(n), query: O(log n), update: O(log n)
// Berechnet das Maximum im Array.
int a[MAX_N], m[4 * MAX_N];

int query(int x, int y, int k = 0, int X = 0, int Y = MAX_N - 1) {
	if (x <= X && Y <= y) return m[k];
	if (y < X || Y < x) return -1000000000; // Ein "neutrales" Element.
	int M = (X + Y) / 2;
	return max(query(x, y, 2 * k + 1, X, M), query(x, y, 2 * k + 2, M + 1, Y));
}

void update(int i, int v, int k = 0, int X = 0, int Y = MAX_N - 1) {
	if (i < X || Y < i) return;
	if (X == Y) {
		m[k] = v;
		a[i] = v;
		return;
	}
	int M = (X + Y) / 2;
	update(i, v, 2 * k + 1, X, M);
	update(i, v, 2 * k + 2, M + 1, Y);
	m[k] = max(m[2 * k + 1], m[2 * k + 2]);
}

// Einmal vor allen anderen Operationen aufrufen.
void init(int k = 0, int X = 0, int Y = MAX_N - 1) {
	if (X == Y) {
		m[k] = a[X];
		return;
	}
	int M = (X + Y) / 2;
	init(2 * k + 1, X, M);
	init(2 * k + 2, M + 1, Y);
	m[k] = max(m[2 * k + 1], m[2 * k + 2]);
}
