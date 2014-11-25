int josephus(int n, int k) { //returns the number of the last survivor (0 based)
	if (n == 1) return 0;
	return (josephus(n - 1, k) + k) % n;
}