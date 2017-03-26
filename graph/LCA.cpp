vector<int> visited(2*MAX_N), first(MAX_N, 2*MAX_N), depth(2*MAX_N);
vector<vector<int>> graph(MAX_N);

// Funktioniert nur mit von der Wurzel weggerichteten Kanten.
// Falls ungerichtete Kanten, visited-check einführen.
void initLCA(int gi, int d, int &c) { // Laufzeit: O(n)
	visited[c] = gi, depth[c] = d, first[gi] = min(c, first[gi]), c++;
	for(int gn : graph[gi]) {
		initLCA(gn, d+1, c);
		visited[c] = gi, depth[c] = d, c++;
}}

int getLCA(int a, int b) { // Laufzeit: O(1)
	return visited[queryRMQ(
			min(first[a], first[b]), max(first[a], first[b]))];
}

// Benutzung:
int c = 0;
initLCA(0, 0, c);
initRMQ();
