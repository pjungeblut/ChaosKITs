ll phi(ll n) { // Laufzeit: O(sqrt(n))
  // Optimierung: Falls n prim, n - 1 zurückgeben (Miller-Rabin/Sieb).
  ll result = n;
  for(int i = 2; i * i <= n; ++i) {
    if(n % i == 0) {  // Optimierung: Nur über Primzahlen iterieren.
      while(n % i == 0)n /= i;
      result -= result / i;
    }
  }
  if(n > 1) result -= result / n;
  return result;
}
