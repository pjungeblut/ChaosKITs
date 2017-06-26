// Laufzeit: O(log (b))
ll powMod(ll a, ll b, ll n) {
  if (b == 0) return 1;
  ll res = 1;
  while (b > 1) {
    if (b & 1) res = (a * res) % n;
    a = (a * a) % n;
    b /= 2;
  }
  return (a * res) % n;
}
