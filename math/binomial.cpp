// Laufzeit: O(k)
ll calc_binom(ll n, ll k) { // Sehr sicher gegen Overflows.
   ll r = 1, d;
   if (k > n) return 0;
   for (d = 1; d <= k; d++) { // Reihenfolge garantiert Teilbarkeit.
      r *= n--;
      r /= d;
   }
   return r;
}
