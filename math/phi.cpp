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

// Sieb, falls alle Werte benötigt werden. Laufzeit: O(N*log(log(N)))
for (int i = 1; i <= N; i++) phi[i] = i;
for (int i = 2; i <= N; i++) if (phi[i] == i) {
  for (int j = i; j <= N; j += i) {
    phi[j] /= i;
    phi[j] *= i - 1;
}}
