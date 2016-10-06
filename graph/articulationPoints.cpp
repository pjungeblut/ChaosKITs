// Laufzeit: O(|V|+|E|)
vector< vector<int> > adjlist;
vector<bool> isArt;
vector<int> d, low;
int counter, root; // root >= 2 <=> Wurzel Artikulationspunkt
vector<ii> bridges; // Nur fuer Brücken.

void dfs(int v, int parent) { // Mit parent=-1 aufrufen.
	d[v] = low[v] = counter++;
	if (parent == 0) root++;
	
	for (auto w : adjlist[v]) {
		if (!d[w]) {
			dfs(w, v);
			if (low[w] >= d[v]) isArt[v] = true;
			if (low[w] > d[v]) bridges.push_back(ii(v, w));
			low[v] = min(low[v], low[w]);
		} else if (w != parent) {
			low[v] = min(low[v], d[w]);
}}}

void findArticulationPoints() {
	couter = 1; // Nicht auf 0 setzen!
	low.resize(adjlist.size());
	d.assign(adjlist.size(), 0);
	isArtPoint.assign(adjlist.size(), false);
	bridges.clear(); //nur fuer Bruecken
	for (int v = 0; v < (int)adjlist.size(); v++) if (!d[v]) visit(v, -1);
}
