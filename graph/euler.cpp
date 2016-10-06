// Laufzeit: O(|V|+|E|)
vector< vector<int> > adjlist, otherIdx;
vector<int> cycle, validIdx;

// Vertauscht Kanten mit Indizes a und b von Knoten n.
void swapEdges(int n, int a, int b) {
	int neighA = adjlist[n][a], neighB = adjlist[n][b];
	int idxNeighA = otherIdx[n][a], idxNeighB = otherIdx[n][b];
	swap(adjlist[n][a], adjlist[n][b]);
	swap(otherIdx[n][a], otherIdx[n][b]);
	otherIdx[neighA][idxNeighA] = b;
	otherIdx[neighB][idxNeighB] = a;
}

// Entfernt Kante i von Knoten n (und die zugehörige Rückwärtskante).
void removeEdge(int n, int i) {
	int other = adjlist[n][i];
	if (other == n) { //Schlingen.
		validIdx[n]++;
		return;
	}
	int otherIndex = otherIdx[n][i];
	validIdx[n]++;
	if (otherIndex != validIdx[other]) {
		swapEdges(other, otherIndex, validIdx[other]);
	}
	validIdx[other]++;
}

// Findet Eulerzyklus an Knoten n startend.
// Teste vorher, dass Graph zusammenhängend ist! Isolierten Knoten?
// Teste vorher, ob Eulerzyklus überhaupt existiert!
void euler(int n) {
	while (validIdx[n] < (int)adjlist[n].size()) {
		int nn = adjlist[n][validIdx[n]];
		removeEdge(n, validIdx[n]);
		euler(nn);
	}
	cycle.push_back(n); // Zyklus in cycle in umgekehrter Reihenfolge.
}
