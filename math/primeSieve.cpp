// Sieb des Eratosthenes. Laufzeit: O(n * log log n)
#define N 100000001 // Bis 10^8 in unter 64MB Speicher.
bitset<N / 2> isPrime;

inline bool check(int x) { // Diese Methode zum Lookup verwenden.
  if (x < 2) return false;
  else if (x == 2) return true;
  else if (!(x & 1)) return false;
  else return !isPrime[x / 2];
}

inline int primeSieve(int n) { // Gibt die Anzahl der Primzahlen <= n zurück.
  int counter = 1;
  for (int i = 3; i <= min(N, n); i += 2) {
    if (!isPrime[i / 2]) {
      for (int j = 3 * i; j <= min(N, n); j+= 2 * i) isPrime[j / 2] = 1;
      counter++;
    }
  }
  return counter;
}
