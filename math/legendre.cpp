int legendre(ll a, ll p) {
  a %= p;
  if (a == 0) return 0;
  if (a == 1 || p == 2) return 1;
  if (a == 2) return (((p * p - 1) / 8) & 1) ? -1 : 1;
  if (isPrime(a)) {
    return legendre(p, a) * ((((p - 1) * (a - 1) / 4) & 1) ? -1 : 1);
  } else {
    map<ll, int> facts;
    factor(a, facts);
    int res = 1;
    for (auto f : facts)
      if (f.second & 1)
        res *= legendre(f.first, p);
    return res;
  }
}
