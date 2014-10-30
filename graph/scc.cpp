int counter, sccCounter, n; //n == number of vertices
vector<bool> visited, inStack;
vector< vector<int> > adjlist;
vector<int> d, low, sccs;
stack<int> s;

void visit(int v) {
	visited[v] = true;
	d[v] = counter;
	low[v] = counter;
	counter++;
	inStack[v] = true;
	s.push(v);
	
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
			u = s.top();
			s.pop();
			inStack[u] = false;
			sccs[u] = sccCounter;
		} while(u != v);
		sccCounter++;
	}
}

void scc() {
	//read adjlist
	
	visited.clear(); visited.assign(n, false);
	d.clear(); d.resize(n);
	low.clear(); low.resize(n);
	inStack.clear(); inStack.assign(n, false);
	sccs.clear(); sccs.resize(n);
	
	counter = 0;
	sccCounter = 0;
	for (i = 0; i < n; i++) {
		if (!visited[i]) {
			visit(i);
		}
	}
	//sccs has the component for each vertex
}