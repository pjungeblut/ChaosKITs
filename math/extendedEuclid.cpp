// Accepted in Aufgabe mit Forderung: |X|+|Y| minimal (primaer) und X<=Y (sekundaer).
// Hab aber keinen Beweis dafuer :)
ll x, y, d; // a * x + b * y = d = ggT(a,b)
void extendedEuclid(ll a, ll b) {
	if (!b) {
		x = 1; y = 0; d = a; return;
	}
	extendedEuclid(b, a % b);
	ll x1 = y; ll y1 = x - (a / b) * y;
	x = x1; y = y1;
}
