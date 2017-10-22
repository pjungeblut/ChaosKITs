// Laufzeit: O(n + m + z), n = #Text, m = Summe #Pattern, z = #Matches
// Findet mehrere Patterns gleichzeitig in einem String.
// 1) Wurzel erstellen: aho.push_back(vertex());
// 2) Mit addString(0, pattern, idx); Patterns hinzufügen.
// 3) finishAutomaton(0) aufrufen.
// 4) Mit state = go(state, c) in nächsten Zustand wechseln.
//    DANACH: Wenn patterns-Vektor nicht leer ist: Hier enden alle
//    enthaltenen Patterns.
// ACHTUNG: Die Zahlenwerte der auftretenden Buchstaben müssen
// zusammenhängend sein und bei 0 beginnen!
struct vertex {
  int next[ALPHABET_SIZE], failure;
  int character; 
  vector<int> patterns; // Indizes der Patterns, die hier enden.
  vertex() { for (int i = 0; i < ALPHABET_SIZE; i++) next[i] = -1; }
};
vector<vertex> aho;

void addString(int v, vector<int> &pattern, int patternIdx) {
  for (int i = 0; i < (int)pattern.size(); i++) {
    if (aho[v].next[pattern[i]] == -1) {
      aho[v].next[pattern[i]] = aho.size();
      aho.push_back(vertex());
      aho.back().character = pattern[i];
    }
    v = aho[v].next[pattern[i]];
  }
  aho[v].patterns.push_back(patternIdx);
}

void finishAutomaton(int v) {
  for (int i = 0; i < ALPHABET_SIZE; i++)
    if (aho[v].next[i] == -1) aho[v].next[i] = v;

  queue<int> q;
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (aho[v].next[i] != v) {
      aho[aho[v].next[i]].failure = v;
      q.push(aho[v].next[i]);
  }}
  while (!q.empty()) {
    int r = q.front(); q.pop();
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      if (aho[r].next[i] != -1) {
        q.push(aho[r].next[i]);
        int f = aho[r].failure;
        while (aho[f].next[i] == -1) f = aho[f].failure;
        aho[aho[r].next[i]].failure = aho[f].next[i];
        for (int j = 0; j < (int)aho[aho[f].next[i]].patterns.size(); j++) {
          aho[aho[r].next[i]].patterns.push_back(
              aho[aho[f].next[i]].patterns[j]);
}}}}}

int go(int v, int c) {
  if (aho[v].next[c] != -1) return aho[v].next[c];
  else return go(aho[v].failure, c);
}
