vector<int> uf;

init(int N) {
  uf.assign(N,-1); //-1 indicates that every subset has size 1
}

int findSet(int i) {
  if(uf[i] < 0) return i; //If uf[i] < 0 we have reach a root
  uf[i] = findSet(uf[i]); //Path-Compression
  return uf[i];
}
  
void linkSets(int i, int j) {
  //Take |uf[i]|, where i must be a root, to get the size 
  //of the subset
  if(abs(uf[i]) < abs(uf[j])) { //Union-by-size.
    uf[j] += uf[i]; uf[i] = j; 
  } else {
    uf[i] += uf[j]; uf[j] = i; 
  }
}
  
void unionSets(int i, int j) {
  if(findSet(i) != findSet(j)) linkSets(findSet(i),findSet(j));
} 
  
  
