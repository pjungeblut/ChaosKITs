// Laufzeit: O(|V|+|E|)
vector<vector<int>> adjlist;
vector<bool> isArt;
vector<int> d, low;
int counter, root, rootCount; // rootCount >= 2 <=> root Artikulationspunkt
vector<ii> bridges; // Nur fuer Brücken.

void dfs(int v, int parent = -1) {
	d[v] = low[v] = ++counter;
	if (parent == root) ++rootCount;
	
	for (auto w : adjlist[v]) {
		if (!d[w]) {
			dfs(w, v);
			if (low[w] >= d[v] && v != root) isArt[v] = true;
			if (low[w] > d[v]) bridges.push_back(ii(v, w));
			low[v] = min(low[v], low[w]);
		} else if (w != parent) {
			low[v] = min(low[v], d[w]);
}}}

void findArticulationPoints() {
	counter = 0;
	low.resize(adjlist.size());
	d.assign(adjlist.size(), 0);
	isArtPoint.assign(adjlist.size(), false);
	bridges.clear(); //nur fuer Bruecken
	for (int v = 0; v < (int)adjlist.size(); v++) {
		if (!d[v]) {
			root = v; rootCount = 0;
			dfs(v);
			if (rootCount > 1) isArt[v] = true;
}}}
