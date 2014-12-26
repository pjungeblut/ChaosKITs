vector< vector<int> > adjlist; //seems to work directed, from left to right
vector<int> pairs; //for every node, stores the matching node on the other side or -1
vector<bool> visited;

bool dfs(int i) {
	if (visited[i]) return false;
	visited[i] = true;
	for (vector<int>::iterator vit = adjlist[i].begin(); vit != adjlist[i].end(); vit++) {
		if (pairs[*vit] < 0 || dfs(pairs[*vit])) {
			pairs[*vit] = i; pairs[i] = *vit; return true;
		}
	}
	return false;
}

int kuhn(int n, int m) { // n = nodes on left side (numbered 0..n-1), m = nodes on the right side
	pairs.assign(n + m, -1);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		visited.assign(n + m, false);
		ans += dfs(i);
	}
	return ans; //size of the MCBM
}
