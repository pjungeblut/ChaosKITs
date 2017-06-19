double f(double x) { return x; }

double simps(double a, double b) {
  return (f(a) + 4.0 * f((a + b) / 2.0) + f(b)) * (b - a) / 6.0;
}

double integrate(double a, double b) {
  double m = (a + b) / 2.0;
  double l = simps(a, m), r = simps(m, b), tot = simps(a, b);
  if (abs(l + r - tot) < EPSILON) return tot;
  return integrate(a, m) + integrate(m, b);
}
