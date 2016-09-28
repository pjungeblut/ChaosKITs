// Laufzeit: O(n*(|V|+|E|))
vector< vector<int> > adjlist; // Gerichtete Kanten, von links nach rechts.
vector<int> pairs; // Zu jedem Knoten der gematchte Knoten rechts, oder -1.
vector<bool> visited;

bool dfs(int v) {
	if (visited[v]) return false;
	visited[v] = true;
	for (auto w : adjlist[v]) if (pairs[w] < 0 || dfs(pairs[w])) {
		pairs[w] = v; pairs[v] = w; return true;
	}
	return false;
}

// n = #Knoten links (0..n-1), m = #Knoten rechts
int kuhn(int n, int m) {
	pairs.assign(n + m, -1);
	int ans = 0;
	// Greedy Matching. Optionale Beschleunigung.
	for (int i = 0; i < n; i++) for (auto w : adjlist[i]) if (pairs[w] == -1) {
		pairs[i] = w; pairs[w] = i; ans++; break;
	}
	for (int i = 0; i < n; i++) if (pairs[i] == -1) {
		visited.assign(n + m, false);
		ans += dfs(i);
	}
	return ans; // Größe des Matchings.
}
