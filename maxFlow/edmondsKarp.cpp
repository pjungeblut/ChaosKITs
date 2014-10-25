int s, t, f; //source, target, single flow
int res[100][100]; //adj-matrix
vector< vector<int> > adjList;
int p[100]; //bfs spanning tree

void augment(int v, int minEdge) {
	if (v == s) { f = minEdge; return; }
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
}}

int main() {
	//inititalize res, adjList, s, t
	int mf = 0;
	while (true) {
		f = 0;
		bitset<100> vis; vis[s] = true;
		queue<int> q; q.push(s);
		memset(p, -1, sizeof(p));
		while (!q.empty()) { //BFS
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int j = 0; j < (int)adjList[u].size(); j++) {
				int v = adjList[u][j];
				if (res[u][v] > 0 && !vis[v]) {
					vis[v] = true; q.push(v); p[v] = u;
		}}}
		
		augment(t, INF); //add found path to max flow
		if (f == 0) break;
		mf += f;
}}
//max flow in mf}