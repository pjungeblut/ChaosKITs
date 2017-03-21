// Ford Fulkerson mit Capacity Scaling. Laufzeit: O(|E|^2*log(C))
static const int MAX_N = 500; // #Knoten, egal für die Laufzeit.
struct edge { int dest, rev; ll cap, flow; };
vector<edge> adjlist[MAX_N];
int visited[MAX_N], target, dfsCounter;
ll capacity;

bool dfs(int x) {
  if (x == target) return 1;
  if (visited[x] == dfsCounter) return 0;
  visited[x] = dfsCounter;
  for (edge &e : adjlist[x]) {
    if (e.cap >= capacity && dfs(e.dest)) {
      e.cap -= capacity; adjlist[e.dest][e.rev].cap += capacity;
      e.flow += capacity; adjlist[e.dest][e.rev].flow -= capacity;
      return 1;
  }}
  return 0;
}

void addEdge(int u, int v, ll c) {
  adjlist[u].push_back(edge {v, (int)adjlist[v].size(), c, 0});
  adjlist[v].push_back(edge {u, (int)adjlist[u].size() - 1, 0, 0});
}

ll maxFlow(int s, int t) {
  capacity = 1L << 62;
  target = t;
  ll flow = 0L;
  while (capacity) {
    while (dfsCounter++, dfs(s)) flow += capacity;
    capacity /= 2;
  }
  return flow;
}
