struct SuffixArray { // MAX_LG = ceil(log2(MAX_N))
	static const int MAX_N = 100010, MAX_LG = 17;
	pair<pair<int, int>, int> L[MAX_N];
	int P[MAX_LG + 1][MAX_N], n, step, count;
	int suffixArray[MAX_N], lcpArray[MAX_N]; 

	SuffixArray(const string &s) : n(s.size()) { // Laufzeit: O(n*log^2(n))
		for (int i = 0; i < n; i++) P[0][i] = s[i];
		suffixArray[0] = 0; // Falls n == 1.
		for (step = 1, count = 1; count < n; step++, count <<= 1) {
			for (int i = 0; i < n; i++) L[i] =
					{{P[step-1][i], i+count < n ? P[step-1][i+count] : -1}, i};
			sort(L, L + n);
			for (int i = 0; i < n; i++) P[step][L[i].second] = i > 0 &&
					L[i].first == L[i-1].first ? P[step][L[i-1].second] : i;
		}
		for (int i = 0; i < n; i++) suffixArray[i] = L[i].second;
		for (int i = 1; i < n; i++)
			lcpArray[i] = lcp(suffixArray[i - 1], suffixArray[i]);
	}

	// x und y sind Indizes im String, nicht im Suffixarray.
	int lcp(int x, int y) { // Laufzeit: O(log(n))
		int k, ret = 0;
		if (x == y) return n - x;
		for (k = step - 1; k >= 0 && x < n && y < n; k--)
			if (P[k][x] == P[k][y])
				x += 1 << k, y += 1 << k, ret += 1 << k;
		return ret;
	}
};
