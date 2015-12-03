// Laufzeit: O(|V|+|E|)
int counter, sccCounter;
vector<bool> visited, inStack;
vector< vector<int> > adjlist;
vector<int> d, low, sccs;
stack<int> s;

void visit(int v) {
	visited[v] = true;
	d[v] = counter; low[v] = counter; counter++;
	inStack[v] = true; s.push(v);
	
	for (int i = 0; i < (int)adjlist[v].size(); i++) {
		int u = adjlist[v][i];
		if (!visited[u]) {
			visit(u);
			low[v] = min(low[v], low[u]);
		} else if (inStack[u]) {
			low[v] = min(low[v], low[u]);
		}
	}
	
	if (d[v] == low[v]) {
		int u;
		do {
			u = s.top(); s.pop(); inStack[u] = false;
			sccs[u] = sccCounter;
		} while(u != v);
		sccCounter++;
	}
}

void scc() {
	// Initialisiere adjlist!
	visited.clear(); visited.assign(NUM_VERTICES, false);
	d.clear(); d.resize(NUM_VERTICES);
	low.clear(); low.resize(NUM_VERTICES);
	inStack.clear(); inStack.assign(NUM_VERTICES, false);
	sccs.clear(); sccs.resize(NUM_VERTICES);
	
	counter = 0;
	sccCounter = 0;
	for (i = 0; i < NUM_VERTICES; i++) {
		if (!visited[i]) {
			visit(i);
		}
	}
	// sccCounter ist Anzahl der starkem Zusammenhangskomponenten.
	// sccs enthält den Index der SCC für jeden Knoten.
}