// Laufzeit: O(|V|^3)
int costs[N_LEFT][N_RIGHT];

int match(int l, int r) {
  vector<int> xy(l, -1), yx(r, -1), lx(l), ly(r, 0), augmenting(r);
  vector<bool> s(l);
  vector<ii> slack(r, ii(0,0));

  for (int x = 0; x < l; x++) lx[x] = *max_element(costs[x], costs[x] + r);
  for (int root = 0; root < l; root++) {
    fill(augmenting.begin(), augmenting.end(), -1);
    fill(s.begin(), s.end(), false);
    s[root] = true;
    for (int y = 0; y < r; y++) {
      slack[y] = ii(lx[root] + ly[y] - costs[root][y], root);
    }
    int y = -1;
    for (;;) {
      int delta = INT_MAX, x = -1;
      for (int yy = 0; yy < r; yy++) {
        if (augmenting[yy] == -1) {
          if (slack[yy].first < delta) {
            delta = slack[yy].first;
            x = slack[yy].second;
            y = yy;
      }}}
      if (delta > 0) {
        for (int x = 0; x < l; x++) if (s[x]) lx[x] -= delta;
        for (int y = 0; y < r; y++) {
          if (augmenting[y] > -1) ly[y] += delta;
          else slack[y].first -= delta;
      }}
      augmenting[y] = x;
      x = yx[y];
      if (x == -1) break;
      s[x] = true;
      for (int y = 0; y < r; y++) {
        if (augmenting[y] == -1) {
          ii alt = ii(lx[x] + ly[y] - costs[x][y], x);
          if (slack[y].first > alt.first) {
            slack[y] = alt;
    }}}}
    while (y != -1) {
      // Jede Iteration vergrößert Matching um 1 (können 0-Kanten sein!).
      int x = augmenting[y];
      int prec = xy[x];
      yx[y] = x;
      xy[x] = y;
      y = prec;
  }}
  return accumulate(lx.begin(), lx.end(), 0) +
         accumulate(ly.begin(), ly.end(), 0); // Wert des Matchings.
}
