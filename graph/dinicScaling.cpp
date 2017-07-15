// Laufzeit: O(|V|^2*|E|)
// Knoten müssen von 0 nummeriert sein.
const int INF = 0x3FFFFFFF, MAXN = 500;
struct edge { int a, b; ll f, c; };
int n, m, pt[MAXN], d[MAXN], s, t;
vector<edge> e;
vector<int> g[MAXN];
ll flow = 0, lim;
queue<int> q;

void addEdge(int a, int b, ll c) {
  g[a].push_back(e.size());
  e.push_back(edge {a, b, 0, c});
  g[b].push_back(e.size());
  e.push_back(edge {b, a, 0, 0});
}

bool bfs() {
  for (int i = 0; i < n; i++) d[i] = INF;
  d[s] = 0; 
  q.push(s);
  while (!q.empty() && d[t] == INF) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < (int)g[cur].size(); i++) {
      int id = g[cur][i], to = e[id].b;
      if (d[to] == INF && e[id].c - e[id].f >= lim) {
        d[to] = d[cur] + 1;
        q.push(to);
      }
    }
  }
  while (!q.empty()) q.pop();
  return d[t] != INF;
}

bool dfs(int v, ll flow) {
  if (flow == 0) return false;
  if (v == t) return true;
  for (; pt[v] < (int)g[v].size(); pt[v]++) {
    int id = g[v][pt[v]], to = e[id].b;
    if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
      int pushed = dfs(to, flow); 
      if (pushed) {
        e[id].f += flow;
        e[id ^ 1].f -= flow;
        return true;
      }       
    }
  }
  return false;
}

// Nicht vergessen, s und t zu setzen!
void dinic() {
  for (lim = (1LL << 62); lim >= 1;) {
    if (!bfs()) { lim /= 2; continue; }
    for (int i = 0; i < n; i++) pt[i] = 0;
    int pushed;
    while ((pushed = dfs(s, lim))) flow += lim;
  }
}
