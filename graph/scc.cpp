// Laufzeit: O(|V|+|E|)
int counter, sccCounter;
vector<bool> visited, inStack;
vector< vector<int> > adjlist;
vector<int> d, low, sccs; // sccs enthält den Index der SCC pro Knoten.
stack<int> s;

void visit(int v) {
	visited[v] = true;
	d[v] = low[v] = counter++;
	s.push(v); inStack[v] = true;

	for (auto u : adjlist[v]) {
		if (!visited[u]) {
			visit(u);
			low[v] = min(low[v], low[u]);
		} else if (inStack[u]) {
			low[v] = min(low[v], low[u]);
	}}

	if (d[v] == low[v]) {
		int u;
		do {
			u = s.top(); s.pop(); inStack[u] = false;
			sccs[u] = sccCounter;
		} while (u != v);
		sccCounter++;
}}

void scc() {
	visited.assign(adjlist.size(), false);
	d.assign(adjlist.size(), -1);
	low.assign(adjlist.size(), -1);
	inStack.assign(adjlist.size(), false);
	sccs.resize(adjlist.size(), -1);

	counter = sccCounter = 0;
	for (int i = 0; i < (int)adjlist.size(); i++) {
		if (!visited[i]) {
			visit(i);
}}}
