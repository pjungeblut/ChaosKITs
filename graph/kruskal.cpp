//Takes a Graph g (EdgeList!!!) with N nodes and computes the MST and Cost of it. Runtime: O(|E|*log(|E|))
//Requires UnionFind-Datastructure!!!
pair<graph,int> buildMST(int N, graph& g) {
  UnionFind uf(N);
  graph mst; int mst_cost = 0; int M = g.size();
  sort(g.begin(),g.end());
  for(int i = 0; i < M; i++) {
    int u = g[i].second.first, v = g[i].second.second;
    if(uf.findSet(u) != uf.findSet(v)) {
      mst.push_back(g[i]); mst_cost += g[i].first;
      uf.unionSets(u,v);
    }
  }
  return make_pair(mst,mst_cost);
}
