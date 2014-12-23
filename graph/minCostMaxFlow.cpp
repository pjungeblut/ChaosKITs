int s, t, f, c; //source, target, single flow, single cost
int res[MAX_V][MAX_V]; //residual graph
vector<edge> edges; //edge list
vector<int> p, dist; //parent pointer, dist field

void augment(int v, int minEdge) {
	if (v == s) { f = minEdge; c = minEdge * dist[t]; return; } //c = minEdge * dist[t] added
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
}}

//first inititalize res, edges, s and t
int minCostMaxFlow(int v) { //v is number of vertices
	int mf = 0, mc = 0, i, j;
	while (true) {
		f = 0; c = 0;
		dist.assign(v, INF); dist[s] = 0;
		p.assign(v, -1);
		for (i = 0; i < v - 1; i++) { //Bellmann-Ford
			for (j = 0; j < (int)edges.size(); j++) {
				if (res[edges[j].from][edges[j].to] > 0 && dist[edges[j].from] + edges[j].cost < dist[edges[j].to]) {
					dist[edges[j].to] = dist[edges[j].from] + edges[j].cost;
					p[edges[j].to] = edges[j].from;
				}
			}
		}
		
		augment(t, INF); //add found path to max flow, method as in EdmondsKarp
		if (f == 0) break;
		mf += f; mc += c;
	}
	return mf; //returns max flow, for in cost, use mc
}