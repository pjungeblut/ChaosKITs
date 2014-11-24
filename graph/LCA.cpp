//RMQ muss hinzugefuegt werden!
vector<int> visited(2*MAX_N), first(MAX_N, 2*MAX_N), depth(2*MAX_N);
vector<vector<int>> graph(MAX_N);

void initLCA(int gi, int d, int &c) {
	visited[c] = gi, depth[c] = d, first[gi] = min(c, first[gi]), c++;
	for(int gn : graph[gi]) {
		initLCA(gn, d+1, c);
		visited[c] = gi, depth[c] = d, c++;
	}
}
//[a, b]
int getLCA(int a, int b) {
	return visited[queryRMQ(min(first[a], first[b]), max(first[a], first[b]))];
}
//=> int c = 0; initLCA(0,0,c); initRMQ(); done!
