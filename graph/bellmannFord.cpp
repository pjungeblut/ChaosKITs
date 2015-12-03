// Laufzeit: O(|V|*|E|)
struct edge {
	int from; int to; int cost;
	edge () {};
	edge (int from, int to, int cost) : from(from), to(to), cost(cost) {};
};

vector<edge> edges; // Kanten einfügen!
vector<int> dist, parent;

void bellmannFord() {
	dist.assign(NUM_VERTICES, INF); dist[0] = 0;
	parent.assign(NUM_VERTICES, -1);
	for (int i = 0; i < NUM_VERTICES - 1; i++) {
		for (int j = 0; j < (int)edges.size(); j++) {
			if (dist[edges[j].from] + edges[j].cost < dist[edges[j].to]) {
				dist[edges[j].to] = dist[edges[j].from] + edges[j].cost;
				parent[edges[j].to] = edges[j].from;
			}
		}
	}

	// "dist" und "parent" sind korrekte kürzeste Pfade.
	// Folgende Zeilen prüfen nur negative Kreise.
	for (int j = 0; j < (int)edges.size(); j++) {
		if (dist[edges[j].from] + edges[j].cost < dist[edges[j].to]) {
			// Negativer Kreis gefunden.
		}
	}
}
