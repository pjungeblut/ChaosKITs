// Laufzeit: O(|V|*|E|)
vector<edge> edges; // Kanten einfügen!
vector<int> dist, parent;

void bellmannFord() {
	dist.assign(NUM_VERTICES, INF); dist[0] = 0;
	parent.assign(NUM_VERTICES, -1);
	for (int i = 0; i < NUM_VERTICES - 1; i++) {
		for (auto &e : edges) {
			if (dist[e.from] + e.cost < dist[e.to]) {
				dist[e.to] = dist[e.from] + e.cost;
				parent[e.to] = e.from;
	}}}

	// "dist" und "parent" sind korrekte kürzeste Pfade.
	// Folgende Zeilen prüfen nur negative Kreise.
	for (auto &e : edges) {
		if (dist[e.from] + e.cost < dist[e.to]) {
			// Negativer Kreis gefunden.
}}}
