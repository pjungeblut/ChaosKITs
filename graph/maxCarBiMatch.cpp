// Laufzeit: O(n*(|V|+|E|))
vector< vector<int> > adjlist; // Gerichtete Kanten, von links nach rechts.
vector<int> pairs; // Zu jedem Knoten der gematchte Knoten rechts, oder -1.
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

// n = #Knoten links (0..n-1), m = #Knoten rechts
int kuhn(int n, int m) {
	pairs.assign(n + m, -1);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		visited.assign(n + m, false);
		ans += dfs(i);
	}
	return ans; // Größe des Matchings.
}
