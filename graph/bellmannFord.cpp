//n = number of vertices, edges is vector of edges
dist.assign(n, INF); dist[0] = 0;
parent.assign(n, -1);
for (i = 0; i < n - 1; i++) {
	for (j = 0; j < (int)edges.size(); j++) {
		if (dist[edges[j].from] + edges[j].cost < dist[edges[j].to]) {
			dist[edges[j].to] = dist[edges[j].from] + edges[j].cost;
			parent[edges[j].to] = edges[j].from;
		}
	}
}
//now dist and parent are correct shortest paths
//next lines check for negative cycles
for (j = 0; j < (int)edges.size(); j++) {
	if (dist[edges[j].from] + edges[j].cost < dist[edges[j].to]) {
		//NEGATIVE CYCLE found
	}
}
