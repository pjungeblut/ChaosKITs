// Laufzeit: O(log(b))
ll powMod(ll a, ll b, ll n) {
  if(b == 0) return 1;
  if(b == 1) return a % n;
  if(b & 1) return (powMod(a, b - 1, n) * a) % n;
  else return powMod((a * a) % n, b / 2, n);
}
