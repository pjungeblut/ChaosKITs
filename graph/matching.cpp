// Fehlerwahrscheinlichkeit: (n / MOD)^I
const int N=200, MOD=1000000007, I=10;
int n, adj[N][N], a[N][N];

int rank() {
  int r = 0;
  for (int j = 0; j < n; j++) {
    int k = r;
    while (k < n && !a[k][j]) ++k;
    if (k == n) continue;
    swap(a[r], a[k]);
    int inv = powmod(a[r][j], MOD - 2);
    for (int i = j; i < n; i++)
      a[r][i] = 1LL * a[r][i] * inv % MOD;
    for (int u = r + 1; u < n; u++)
      for (int v = j; v < n; v++)
        a[u][v] = (a[u][v] - 1LL * a[r][v] * a[u][j] % MOD + MOD) % MOD;
    ++r;
  }
  return r;
}

int max_matching() {
  int ans = 0;
  for (int _ = 0; _ < I; _++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (adj[i][j]) {
          a[i][j] = rand() % (MOD - 1) + 1;
          a[j][i] = MOD - a[i][j];
    }}}
    ans = max(ans, rank()/2);
  }
  return ans;
}
