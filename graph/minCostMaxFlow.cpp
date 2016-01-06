typedef long long ll;
static const ll flowlimit = 1LL << 60; // Should be bigger than the max flow.
struct MinCostFlow { // Should be initialized with new.
	static const int maxn = 400; // Should be bigger than the #vertices.
	static const int maxm = 5000; //#edges.
	struct edge { int node; int next; ll flow; ll value; } edges[maxm << 1];
	int graph[maxn], queue[maxn], pre[maxn], con[maxn], n, m, source, target, top;
	bool inqueue[maxn];
	ll maxflow, mincost, dis[maxn];

	MinCostFlow() { memset(graph, -1, sizeof(graph)); top = 0; }

	inline int inverse(int x) {	return 1 + ((x >> 1) << 2) - x; }

	// Directed edge from u to v, capacity c, weight w.
	inline int addedge(int u, int v, int c, int w) {
		edges[top].value = w; edges[top].flow = c; edges[top].node = v;
		edges[top].next = graph[u];	graph[u] = top++;
		edges[top].value = -w; edges[top].flow = 0; edges[top].node = u;
		edges[top].next = graph[v];	graph[v] = top++;
		return top - 2;
	}

	bool SPFA() {
		int point, node, now, head = 0, tail = 1;
		memset(pre, -1, sizeof(pre));
		memset(inqueue, 0, sizeof(inqueue));
		memset(dis, 0x7F, sizeof(dis));
		dis[source] = 0; queue[0] = source;
		pre[source] = source; inqueue[source] = true;

		while (head != tail) {
			now = queue[head++];
			point = graph[now];
			inqueue[now] = false;
			head %= maxn;

			while (point != -1) {
				node = edges[point].node;
				if (edges[point].flow > 0 && dis[node] > dis[now] + edges[point].value) {
					dis[node] = dis[now] + edges[point].value;
					pre[node] = now; con[node] = point;
					if (!inqueue[node]) {
						inqueue[node] = true; queue[tail++] = node;
						tail %= maxn;
					}
				}
				point = edges[point].next;
			}
		}
		return pre[target] != -1;
	}

	void extend() {
		ll w = flowlimit;
		for (int u = target; pre[u] != u; u = pre[u]) {
			w = min(w, edges[con[u]].flow);
		}
		maxflow += w;
		mincost += dis[target] * w;
		for (int u = target; pre[u] != u; u = pre[u]) {
			edges[con[u]].flow -= w;
			edges[inverse(con[u])].flow += w;
		}
	}

	void mincostflow() {
		maxflow = 0;
		mincost = 0;
		while (SPFA()) {
			extend();
		}
	}
};
