struct sat2 {
	vector<vector<int>> adjlist, sccs;
	vector<bool> visited, inStack;
	int n, sccCounter, dfsCounter;
	vector<int> d, low, idx, sol;
	stack<int> s;

	sat2(int vars) : n(vars*2) { adjlist.resize(n);	};

	static int var(int i) { return i << 1; }

	void addImpl(int v1, int v2) {
		adjlist[v1].push_back(v2);
		adjlist[1^v2].push_back(1^v1);
	}
	void addEquiv(int v1, int v2) { addImpl(v1, v2); addImpl(v2, v1); }
	void addOr(int v1, int v2) { addImpl(1^v1, v2); addImpl(1^v2, v1); }
	void addXor(int v1, int v2) { addOr(v1, v2); addOr(1^v1, 1^v2); }
	void addTrue(int v1) { addImpl(1^v1, v1); }
	void addFalse(int v1) { addTrue(1^v1); }
	void addAnd(int v1, int v2) {	addTrue(v1); addTrue(v2); }

	void dfs(int v) {
		visited[v] = true;
		d[v] = low[v] = dfsCounter++;
		s.push(v); inStack[v] = true;

		for (auto w : adjlist[v]) {
			if (!visited[w]) {
				dfs(w);
				low[v] = min(low[v], low[w]);
			} else if (inStack[w]) low[v] = min(low[v], low[w]);
		}

		if (d[v] == low[v]) {
			sccs.push_back(vector<int>());
			int w;
			do {
				w = s.top(); s.pop(); inStack[w] = false;
				idx[w] = sccCounter;
				sccs[sccCounter].push_back(w);
			} while (w != v);
			sccCounter++;
	}}

	bool solvable() {
		visited.assign(n, false);
		inStack.assign(n, false);
		d.assign(n, -1);
		low.assign(n, -1);
		idx.assign(n, -1);
		sccCounter = dfsCounter = 0;
		for (int i = 0; i < n; i++) if (!visited[i]) dfs(i);
		for (int i = 0; i < n; i += 2) if (idx[i] == idx[i + 1]) return false;
		return true;
	}

	void assign() {
		sol.assign(n, -1);
		for (int i = 0; i < sccCounter; i++) {
			if (sol[sccs[i][0]] == -1) {
				for (int v : sccs[i]) {
					sol[v] = 1;
					sol[1^v] = 0;
	}}}}
};
