ll q = 31; // Größer als Alphabetgröße. q=31,53,311
struct Hasher {
  string s;
  ll mod;
  vector<ll> power, pref;
  Hasher(const string& s, ll mod) : s(s), mod(mod) {
    power.push_back(1);
    for (int i = 1; i < (int)s.size(); i++)
      power.push_back(power.back() * q % mod);
    pref.push_back(0);
    for (int i = 0; i < (int)s.size(); i++)
      pref.push_back((pref.back() * q % mod + s[i]) % mod);
  }

  // Berechnet hash(s[l..r]). l,r inklusive.
  ll hash(int l, int r) {
    return (pref[r+1] - power[r-l+1] * pref[l] % mod + mod) % mod;
  }
};
