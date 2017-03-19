// Baut Suffixbaum online auf. Laufzeit: O(n)
// Einmal initSuffixTree() aufrufen und dann extend für jeden Buchstaben.
// '\0'-Zeichen (oder ähnliches) an den Text anhängen!
string s;
int root, lastIdx, needsSuffix, pos, remainder, curVert, curEdge, curLen;
struct Vert {
  int start, end, suffix; // Kante [start,end)
  map<char, int> next;
  int len() { return min(end, pos + 1) - start; }
};
vector<Vert> tree;

int newVert(int start, int end) {
  Vert v;
  v.start = start;
  v.end = end;
  v.suffix = 0;
  tree.push_back(v);
  return ++lastIdx;
}

void addSuffixLink(int vert) {
  if (needsSuffix) tree[needsSuffix].suffix = vert;
  needsSuffix = vert;
}

bool fullImplicitEdge(int vert) {
  if (curLen >= tree[vert].len()) {
    curEdge += tree[vert].len();
    curLen -= tree[vert].len();
    curVert = vert;
    return true;
  }
  return false;
}

void initSuffixTree() {
  needsSuffix = remainder = curEdge = curLen = 0;
  lastIdx = pos = -1;
  root = curVert = newVert(-1, -1);
}

void extend() {
  pos++;
  needsSuffix = 0;
  remainder++;
  while (remainder) {
    if (curLen == 0) curEdge = pos;
    if (!tree[curVert].next.count(s[curEdge])) {
      int leaf = newVert(pos, s.size());
      tree[curVert].next[s[curEdge]] = leaf;
      tree[curVert].next[s[curEdge]] = leaf;
      addSuffixLink(curVert);
    } else {
      int nxt = tree[curVert].next[s[curEdge]];
      if (fullImplicitEdge(nxt)) continue;
      if (s[tree[nxt].start + curLen] == s[pos]) {
        curLen++;
        addSuffixLink(curVert);
        break;
      }
      int split = newVert(tree[nxt].start, tree[nxt].start + curLen);
      tree[curVert].next[s[curEdge]] = split;
      int leaf = newVert(pos, s.size());
      tree[split].next[s[pos]] = leaf;
      tree[nxt].start += curLen;
      tree[split].next[s[tree[nxt].start]] = nxt;
      addSuffixLink(split);
    }
    remainder--;
    if (curVert == root && curLen) {
      curLen--;
      curEdge = pos - remainder + 1;
    } else {
      curVert = tree[curVert].suffix ? tree[curVert].suffix : root;
    }
  }
}
