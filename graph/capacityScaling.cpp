// Ford Fulkerson mit Capacity Scaling.
// Laufzeit: O(|E|^2*log(C))
struct MaxFlow { // Muss mit new erstellt werden!
  static const int MAX_N = 500; // #Knoten, kein Einfluss auf die Laufzeit.
  struct edge { int dest, rev; ll capacity, flow; };
  vector<edge> adjlist[MAX_N];
  int visited[MAX_N] = {0}, target, dfsCounter = 0;
  ll capacity;

  bool dfs(int x) {
    if (x == target) return 1;
    if (visited[x] == dfsCounter) return 0;
    visited[x] = dfsCounter;
    for (edge &e : adjlist[x]) {
      if (e.capacity >= capacity && dfs(e.dest)) {
        e.capacity -= capacity; adjlist[e.dest][e.rev].capacity += capacity;
        e.flow += capacity; adjlist[e.dest][e.rev].flow -= capacity;
        return 1;
      }
    }
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
      while (dfsCounter++, dfs(s)) {
        flow += capacity;
      }
      capacity /= 2;
    }
    return flow;
  }
};
