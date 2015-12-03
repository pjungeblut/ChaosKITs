// Laufzeit: O(|V|^2 * |E|^2)
int s, t, f, c; // Quelle, Senke, single flow, single cost
int res[MAX_V][MAX_V];
vector<edge> edges;
vector<int> p, dist;

void augment(int v, int minEdge) {
	if (v == s) { f = minEdge; c = minEdge * dist[t]; return; } // c = minEdge * dist[t] added
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
}}

// Initialisiere res, edges, s und t.
int minCostMaxFlow(int v) { // v = #Knoten
	int mf = 0, mc = 0, i, j;
	while (true) {
		f = 0; c = 0;
		dist.assign(v, INF); dist[s] = 0;
		p.assign(v, -1);
		for (i = 0; i < v - 1; i++) { // Bellmann-Ford.
			for (j = 0; j < (int)edges.size(); j++) {
				if (res[edges[j].from][edges[j].to] > 0 && dist[edges[j].from] + edges[j].cost < dist[edges[j].to]) {
					dist[edges[j].to] = dist[edges[j].from] + edges[j].cost;
					p[edges[j].to] = edges[j].from;
				}
			}
		}
		
		augment(t, INF); // Gefunden Pfad zum Fluss hinzufügen.
		if (f == 0) break;
		mf += f; mc += c;
	}
	return mf; // mf is der maximale Fluss, mc sind die minimalen Kosten.
}