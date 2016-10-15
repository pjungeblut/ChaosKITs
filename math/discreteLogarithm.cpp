// Bestimmt Lösung x für a^x=b mod m.
ll solve (ll a, ll b, ll m) { // Laufzeit: O(sqrt(m)*log(m))
  ll n = (ll)sqrt((double)m) + 1;
  map<ll,ll> vals;
  for (int i = n; i >= 1; i--) vals[powMod(a, i * n, m)] = i;
  for (int i = 0; i <= n; i++) {
    ll cur = (powMod(a, i, m) * b) % m;
    if (vals.count(cur)) {
      ll ans = vals[cur] * n - i;
      if (ans < m) return ans;
  }}
  return -1;
}
