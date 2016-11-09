// Laufzeit: O(n * log log n)
#define N 100000000 // Bis 10^8 in unter 64MB Speicher.
bitset<N / 2> isNotPrime;

inline bool check(int x) { // Diese Methode zum Lookup verwenden.
  if (x < 2) return false;
  else if (x == 2) return true;
  else if (!(x & 1)) return false;
  else return !isNotPrime[x / 2];
}

inline int primeSieve() { // Rückgabe: Anzahl der Primzahlen < N.
  int counter = 1; // Die 2, die sonst vergessen würde.
  for (int i = 3; i < N; i += 2) {
    if (!isNotPrime[i / 2]) {
      for (int j = 3 * i; j < N; j+= 2 * i) isNotPrime[j / 2] = 1;
      counter++;
  }}
  return counter;
}
