int josephus(int n, int k) { // Der letzte Überlebende, 0-basiert.
	if (n == 1) return 0;
	return (josephus(n - 1, k) + k) % n;
}