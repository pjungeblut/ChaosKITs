#define ALPHABET_SIZE		26
struct SuffixAutomaton {
	struct State {
		int length; int link; int next[ALPHABET_SIZE];
		State() { memset(next, 0, sizeof(next)); }
	};
	static const int MAX_N = 100000; // Maximale Länge des Strings.
	State states[2 * MAX_N];
	int size, last;

	SuffixAutomaton(string &s) { // Laufzeit: O(|s|)
		size = 1; last = 0;
		states[0].length = 0;
		states[0].link = -1;
		for (auto c : s) extend(c);
	}

	void extend(char c) { // Werte von c müssen bei 0 beginnen.
		c -= 'a';
		int current = size++;
		states[current].length = states[last].length + 1;
		int pos = last;
		while (pos != -1 && !states[pos].next[(int)c]) {
			states[pos].next[(int)c] = current;
			pos = states[pos].link;
		}
		if (pos == -1) states[current].link = 0;
		else {
			int q = states[pos].next[(int)c];
			if (states[pos].length + 1 == states[q].length) {
				states[current].link = q;
			} else {
				int clone = size++;
				states[clone].length = states[pos].length + 1;
				states[clone].link = states[q].link;
				memcpy(states[clone].next, states[q].next,
						sizeof(states[q].next));
				while (pos != -1 && states[pos].next[(int)c] == q) {
					states[pos].next[(int)c] = clone;
					pos = states[pos].link;
				}
				states[q].link = states[current].link = clone;
		}}
		last = current;
	}

	// Paar mit Startposition und Länge des LCS. Index in Parameter s.
	ii longestCommonSubstring(string &s) { // Laufzeit: O(|s|)
		int v = 0, l = 0, best = 0, bestpos = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			int c = s[i] - 'a';
			while (v && !states[v].next[c]) {
				v = states[v].link;
				l = states[v].length;
			}
			if (states[v].next[c]) { v = states[v].next[c]; l++; }
			if (l > best) { best = l; bestpos = i; }
		}
		return ii(bestpos - best + 1, best);
	}
};

