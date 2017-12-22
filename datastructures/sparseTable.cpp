struct SparseTable {
  int st[MAX_N][MAX_LOG + 1], log[MAX_N + 1]; // Achtung: 2^MAX_LOG > MAX_N
  vector<int> *a;

  // Funktion muss idempotent sein! Hier Minimum.
  bool better(int lidx, int ridx) { return a->at(lidx) <= a->at(ridx); }

  void init(vector<int> *vec) {
    a = vec;
    for (int i = 0; i < (int)a->size(); i++) st[i][0] = i;
    for (int j = 1; j <= MAX_LOG; j++) {
      for (int i = 0; i + (1 << j) <= (int)a->size(); i++) {
        st[i][j] = better(st[i][j - 1], st[i + (1 << (j - 1))][j - 1])
            ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
    }}

    log[1] = 0;
    for (int i = 2; i <= MAX_N; i++) log[i] = log[i/2] + 1;
  }
  
  // Gibt Index des Ergebnisses in [l,r]. Laufzeit: O(1)
  int queryIdempotent(int l, int r) {
    int j = log[r - l + 1];
    return better(st[l][j], st[r - (1 << j) + 1][j])
        ? st[l][j] : st[r - (1 << j) + 1][j];
  }
};
