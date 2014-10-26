vector< vector<int> > adjlist; //adjazenzliste
vector<int> sccs; //speichert die gefundenen SCCs
vector<bool> visited; //welcher Knoten ist schon besucht worden (in der DFS)
vector<bool> inStack; //ist Knoten gerade im Stack
vector<int> d; //discovery time
vector<int> low; //wie weit hoch geht's im Tiefensuchbaum
int counter; //Zaehler fuer discovery time
stack<int> st; //der Stack
int sccCounter; //Zaehler fuer SCCs

//Tiefensuche, die starke Zusammenhangskomponenten findet
void visit(int v) {
	visited[v] = true;
	d[v] = counter;
	low[v] = counter;
	counter++;
	st.push(v);
	inStack[v] = true;
	
	for (int i = 0; i < (int)adjlist[v].size(); i++) {
		int w = adjlist[v][i];
		
		if (!visited[w]) {
			visit(w);
			low[v] = min(low[v], low[w]);
		} else if (inStack[w]) {
			low[v] = min(low[v], low[w]);
		}
	}
	
	if (low[v] == d[v]) {
		int next;
		do {
			next = st.top();
			st.pop();
			sccs[next] = sccCounter;
			inStack[next] = false;
		} while (next != v);
		
		sccCounter++;
	}
}

void solve() {
	//adjlist initialisieren
	//(a || b) wird zu (!a => b) und (!b => a)
	
	visited.clear(); visited.assign(adjlist.size(), false);
	inStack.clear(); inStack.assign(adjlist.size(), false);
	d.clear(); d.assign(adjlist.size(), false);
	low.clear(); low.assign(adjlist.size(), false);
	sccs.clear(); sccs.resize(adjlist.size());
	
	counter = 0;
	sccCounter = 0;
	for (i = 0; i < (int)adjlist.size(); i++) {
		if (!visited[i]) {
			visit(i);
			sccCounter++;
		}
	}
	// genau dann loesbar, wenn keine Variable in gleicher SCC wie Negation ist
}