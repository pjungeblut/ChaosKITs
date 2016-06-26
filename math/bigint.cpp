// Bislang keine Division. Multiplikation nach Schulmethode.
#define PLUS  0
#define MINUS 1
#define BASE  1000000000

struct bigint {
  int sign;
  vector<ll> digits;

  // Initialisiert mit 0.
  bigint(void) {
    sign = PLUS;
  }

  // Initialisiert mit kleinem Wert.
  bigint(ll value) {
    if (value == 0) sign = PLUS;
    else {
      sign = value >= 0 ? PLUS : MINUS;
      value = abs(value);
      while (value) {
        digits.push_back(value % BASE);
        value /= BASE;
      }
    } 
  }

  // Initialisiert mit C-String. Kann nicht mit Vorzeichen umgehen.
  bigint(char *str, int length) {
    int base = 1;
    ll digit = 0;
    for (int i = length - 1; i >= 0; i--) {
      digit += base * (str[i] - '0');
      if (base * 10 == BASE) {
        digits.push_back(digit);
        digit = 0;
        base = 1;
      } else base *= 10;
    }
    if (digit != 0) digits.push_back(digit);
    sign = PLUS;
  }

  // Löscht führende Nullen und macht -0 zu 0.
  void trim() {
    while (digits.size() > 0 && digits[digits.size() - 1] == 0) digits.pop_back();
    if (digits.size() == 0 && sign == MINUS) sign = PLUS;
  }

  // Gibt die Zahl aus.
  void print() {
    if (digits.size() == 0) {
      printf("0");
      return;
    }
    if (sign == MINUS) printf("-");
    printf("%lld", digits[digits.size() - 1]);
    for (int i = digits.size() - 2; i >= 0; i--) {
      printf("%09lld", digits[i]);
    }
  }
};

// Kleiner-oder-gleich-Vergleich.
bool operator<=(bigint &a, bigint &b) {
  if (a.digits.size() == b.digits.size()) {
    int idx = a.digits.size() - 1;
    while (idx >= 0) {
      if (a.digits[idx] < b.digits[idx]) return true;
      else if (a.digits[idx] > b.digits[idx]) return false;
      idx--;
    }
    return true;
  }
  return a.digits.size() < b.digits.size();
}

// Kleiner-Vergeleich.
bool operator<(bigint &a, bigint &b) {
  if (a.digits.size() == b.digits.size()) {
    int idx = a.digits.size() - 1;
    while (idx >= 0) {
      if (a.digits[idx] < b.digits[idx]) return true;
      else if (a.digits[idx] > b.digits[idx]) return false;
      idx--;
    }
    return false;
  }
  return a.digits.size() < b.digits.size();
}

void sub(bigint *a, bigint *b, bigint *c);

// a+b=c. a, b, c dürfen gleich sein.
void add(bigint *a, bigint *b, bigint *c) {
  if (a->sign == b->sign) c->sign = a->sign;
  else {
    if (a->sign == MINUS) {
      a->sign ^= 1;
      sub(b, a, c);
      a->sign ^= 1;
    } else {
      b->sign ^= 1;
      sub(a, b, c);
      b->sign ^= 1;
    }
    return;
  }

  c->digits.resize(max(a->digits.size(), b->digits.size()));
  ll carry = 0;
  int i = 0;
  for (; i < (int)min(a->digits.size(), b->digits.size()); i++) {
    ll sum = carry + a->digits[i] + b->digits[i];
    c->digits[i] = sum % BASE;
    carry = sum / BASE;
  }
  if (i < (int)a->digits.size()) {
    for (; i< (int)a->digits.size(); i++) {
      ll sum = carry + a->digits[i];
      c->digits[i] = sum % BASE;
      carry = sum / BASE;
    }
  } else {
    for (; i< (int)b->digits.size(); i++) {
      ll sum = carry + b->digits[i];
      c->digits[i] = sum % BASE;
      carry = sum / BASE;
    }
  }
  if (carry) {
    c->digits.push_back(carry);
  }
}

// a-b=c. c darf a oder b sein. a und b müssen verschieden sein.
void sub(bigint *a, bigint *b, bigint *c) {
  if (a->sign == MINUS || b->sign == MINUS) {
    b->sign ^= 1;
    add(a, b, c);
    b->sign ^= 1;
    return;
  }

  if (a < b) {
    sub(b, a, c);
    c->sign = MINUS;
    c->trim();
    return;
  }

  c->digits.resize(a->digits.size());
  ll borrow = 0;
  int i = 0;
  for (; i < (int)b->digits.size(); i++) {
    ll diff = a->digits[i] - borrow - b->digits[i];
    if (a->digits[i] > 0) borrow = 0;
    if (diff < 0) {
      diff += BASE;
      borrow = 1;
    }
    c->digits[i] = diff % BASE;
  }
  for (; i < (int)a->digits.size(); i++) {
    ll diff = a->digits[i] - borrow;
    if (a->digits[i] > 0) borrow = 0;
    if (diff < 0) {
      diff += BASE;
      borrow = 1;
    }
    c->digits[i] = diff % BASE;
  }
  c->trim();
}

// Ziffernmultiplikation a*b=c. b und c dürfen gleich sein. a muss kleiner BASE sein.
void digitMul(ll a, bigint *b, bigint *c) {
  if (a == 0) {
    c->digits.clear();
    c->sign = PLUS;
    return;
  }
  c->digits.resize(b->digits.size());
  ll carry = 0;
  for (int i = 0; i < (int)b->digits.size(); i++) {
    ll prod = carry + b->digits[i] * a;
    c->digits[i] = prod % BASE;
    carry = prod / BASE;
  }
  if (carry) c->digits.push_back(carry);
  c->sign = (a > 0) ? b->sign : 1 ^ b->sign;
  c->trim();
}

// Zifferndivision b/a=c. b und c dürfen gleich sein. a muss kleiner BASE sein.
void digitDiv(ll a, bigint *b, bigint *c) {
  c->digits.resize(b->digits.size());
  ll carry = 0;
  for (int i = (int)b->digits.size() - 1; i>= 0; i--) {
    ll quot = (carry * BASE + b->digits[i]) / a;
    carry = carry * BASE + b->digits[i] - quot * a;
    c->digits[i] = quot;
  }
  c->sign = b->sign ^ (a < 0);
  c->trim();
} 

// a*b=c. c darf weder a noch b sein. a und b dürfen gleich sein.
void mult(bigint *a, bigint *b, bigint *c) {
  bigint row = *a;
  bigint tmp;
  c->digits.clear();
  for (int i = 0; i < (int)b->digits.size(); i++) {
    digitMul(b->digits[i], &row, &tmp);
    add(&tmp, c, c);
    row.digits.insert(row.digits.begin(), 0);
  }
  c->sign = a->sign != b->sign;
  c->trim();
}

// Berechnet eine kleine Zehnerpotenz.
inline ll pow10(int n) {
  ll res = 1;
  for (int i = 0; i < n; i++) res *= 10;
  return res;
}

// Berechnet eine große Zehnerpotenz.
void power10(ll e, bigint *out) {
  out->digits.assign(e / 9 + 1, 0);
  if (e % 9) out->digits[out->digits.size() - 1] = pow10(e % 9);
  else out->digits[out->digits.size() - 1] = 1;
}

// Nimmt eine Zahl module einer Zehnerpotenz 10^e.
void mod10(int e, bigint *a) {
  int idx = e / 9;
  if ((int)a->digits.size() < idx + 1) return;
  if (e % 9) {
    a->digits.resize(idx + 1);
    a->digits[idx] %= pow10(e % 9);
  } else {
    a->digits.resize(idx);
  }
  a->trim();
}
