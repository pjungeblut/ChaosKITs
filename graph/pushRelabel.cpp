// Laufzeit: O(|V|^3)
struct PushRelabel {
	ll capacities[MAX_V][MAX_V], flow[MAX_V][MAX_V], excess[MAX_V];
	int height[MAX_V], list[MAX_V - 2], seen[MAX_V], n;

	PushRelabel(int n) {
		this->n = n;
		memset(capacities, 0L, sizeof(capacities)); memset(flow, 0L, sizeof(flow));
		memset(excess, 0L, sizeof(excess)); memset(height, 0, sizeof(height));
		memset(list, 0, sizeof(list)); 	memset(seen, 0, sizeof(seen));
	}

	inline void addEdge(int u, int v, ll c) { capacities[u][v] += c; }

	void push(int u, int v) {
		ll send = min(excess[u], capacities[u][v] - flow[u][v]);
		flow[u][v] += send; flow[v][u] -= send;
		excess[u] -= send; excess[v] += send;
	}

	void relabel(int u) {
		int minHeight = INT_MAX / 2;
		for (int v = 0; v < n; v++) {
			if (capacities[u][v] - flow[u][v] > 0) {
				minHeight = min(minHeight, height[v]);
				height[u] = minHeight + 1;
	}}}

	void discharge(int u) {
		while (excess[u] > 0) {
			if (seen[u] < n) {
				int v = seen[u];
				if (capacities[u][v] - flow[u][v] > 0 && height[u] > height[v]) push(u, v);
				else seen[u]++;
			} else {
				relabel(u);
				seen[u] = 0;
	}}}

	void moveToFront(int u) {
		int temp = list[u];
		for (int i = u; i > 0; i--) 
			list[i] = list[i - 1];
		list[0] = temp;
	}

	ll maxFlow(int source, int target) {
		for (int i = 0, p = 0; i < n; i++) if (i != source && i != target) list[p++] = i;

		height[source] = n;
		excess[source] = LLONG_MAX / 2;
		for (int i = 0; i < n; i++) push(source, i);

		int p = 0;
		while (p < n - 2) {
			int u = list[p], oldHeight = height[u];
			discharge(u);
			if (height[u] > oldHeight) {
				moveToFront(p);
				p = 0;
			} else p++;
		}

		ll maxflow = 0L;
		for (int i = 0; i < n; i++) maxflow += flow[source][i];
		return maxflow;
	}
};
