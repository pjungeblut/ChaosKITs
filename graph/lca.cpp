struct LCA {
  vector<int> depth, visited, first;
  int idx;
  SparseTable st;

  void init(vector<vector<int>> &g, int root) { // Laufzeit: O(|V|)
    depth.assign(2 * g.size(), 0);
    visited.assign(2 * g.size(), -1);
    first.assign(g.size(), 2 * g.size());
    idx = 0;
    visit(g, root, 0);
    st.init(&depth);
  }

  void visit(vector<vector<int>> &g, int v, int d) {
    visited[idx] = v, depth[idx] = d, first[v] = min(idx, first[v]), idx++;

    for (int w : g[v]) {
      if (first[w] == 2 * (int)g.size()) {
        visit(g, w, d + 1);
        visited[idx] = v, depth[idx] = d, idx++;
  }}}

  int getLCA(int a, int b) { // Laufzeit: O(1)
    if (first[a] > first[b]) swap(a, b);
    return visited[st.queryIdempotent(first[a], first[b])];
  }
};
