// Laufzeit: O(n + m + z), n = Suchstringlänge, m = Summe der Patternlängen, z = #Matches
// Findet mehrere Patterns gleichzeitig in einem String.
// 1) Wurzel erstellen: vertex *automaton = new vertex();
// 2) Mit addString(automaton, s, idx); Patterns hinzufügen.
// 3) finishAutomaton aufrufen.
// 4) Mit automaton = go(automaton, c) in nächsten Zustand wechseln. Wenn patterns-Vektor nicht leer ist:
//    Hier enden alle anthaltenen Patterns.
struct vertex {
  vertex *next[ALPHABET_SIZE], *failure;
  char character; 
  vector<int> patterns; // Indizes der Patterns, die hier enden.
  vertex() { for (int i = 0; i < ALPHABET_SIZE; i++) next[i] = NULL; }
};

void addString(vertex *v, string &pattern, int patternIdx) {
  for (int i = 0; i < (int)pattern.length(); i++) {
    if (!v->next[(int)pattern[i]]) {
      vertex *w = new vertex();
      w->character = pattern[i];
      v->next[(int)pattern[i]] = w;
    }
    v = v->next[(int)pattern[i]];
  }
  v->patterns.push_back(patternIdx);
}

void finishAutomaton(vertex *v) {
  for (int i = 0; i < ALPHABET_SIZE; i++)
    if (!v->next[i]) v->next[i] = v;

  queue<vertex*> q;
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (v->next[i] != v) {
      v->next[i]->failure = v;
      q.push(v->next[i]);
  }}
  while (!q.empty()) {
    vertex *r = q.front(); q.pop();
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      if (r->next[i]) {
        q.push(r->next[i]);
        vertex *f = r->failure;
        while (!f->next[i]) f = f->failure;
        r->next[i]->failure = f->next[i];
        for (int j = 0; j < (int)f->next[i]->patterns.size(); j++) {
          r->next[i]->patterns.push_back(f->next[i]->patterns[j]);
}}}}}

vertex* go(vertex *v, char c) {
  if (v->next[(int)c]) return v->next[(int)c];
  else return go(v->failure, c);
}
