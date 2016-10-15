// Ist g Primitivwurzel modulo p. Teste zufällige g, um eine zu finden.
bool is_primitive(ll g, ll p) {
  map<ll, int> facs;
  factor(p - 1, facs);
  for (auto &f : facs)
    if (1 == powMod(g, (p - 1) / f.first, p)) return false;
  return true;
}

// Alternativ: Generator zum Finden. -1 falls keine existiert.
ll generator (ll p) { // Laufzeit: O(ans*log(phi(n))*log(n))
	map<ll, int> facs;
	factor(n, facs);
  ll phi = phi(p),  n = phi;

  for (ll res = 2; res <= p; res++) {
    bool ok = true;
    for (auto &f : facs)
    	ok &= powMod(res, phi / f.first, p) != 1;
    if (ok)  return res;
  }
  return -1;
}
