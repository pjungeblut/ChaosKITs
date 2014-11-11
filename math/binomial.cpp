ll calc_binom(ll N, ll K) {
   ll r = 1, d;
   if (K > N) return 0;
   for (d = 1; d <= K; d++) {
      r *= N--;
      r /= d;
   }
   return r;
}

