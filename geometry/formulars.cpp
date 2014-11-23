//komplexe Zahlen als Darstellung fuer Punkte
typedef pt complex<double>;
//Winkel zwischen Punkt und x-Achse in [0, 2 * PI), Winkel zwischen a und b
double angle = arg (a), angle_a_b = arg (a - b);
//Punkt rotiert um Winkel theta
pt a_rotated = a * exp (pt (0, theta));
//Mittelpunkt des Dreiecks abc
pt centroid = (a + b + c) / 3;
//Skalarprodukt
double dot(pt a, pt b) {
	return real(conj(a) * b);
}
//Kreuzprodukt, 0, falls kollinear
double cross(pt a, pt b) {
	return imag(conj(a) * b);
}
//wenn Eckpunkte bekannt
double areaOfTriangle(pt a, pt b, pt c) {
	return abs(cross(b - a, c - a)) / 2.0;
}
//wenn Seitenlaengen bekannt
double areaOfTriangle(double a, double b, double c) {
	double s = (a + b + c) / 2;
	return sqrt(s * (s-a) * (s-b) * (s-c));
}
// Sind die Dreiecke a1, b1, c1, and a2, b2, c2 aehnlich?
// Erste Zeile testet Aehnlichkeit mit gleicher Orientierung,
// zweite Zeile testst Aehnlichkeit mit unterschiedlicher Orientierung
bool similar (pt a1, pt b1, pt c1, pt a2, pt b2, pt c2) {
	return (
		(b2 - a2) * (c1 - a1) == (b1 - a1) * (c2 - a2) ||
		(b2 - a2) * (conj (c1) - conj (a1)) == (conj (b1) - conj (a1)) * (c2 - a2)
	);
}
//Linksknick von a->b nach a->c
double ccw(pt a, pt b, pt c) {
	return cross(b - a, c - a); //<0 => falls Rechtsknick, 0 => kollinear, >0 => Linksknick
}
//Streckenschnitt, Strecken a-b und c-d
bool lineSegmentIntersection(pt a, pt b, pt c, pt d) {
	if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) { //kollinear
		double dist = abs(a - b);
		return (abs(a - c) <= dist && abs(b - c) <= dist) || (abs(a - d) <= dist && abs(b - d) <= dist);
	}
	return ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0;
}
//Entfernung von p zu a-b
double distToLine(pt a, pt b, pt p) {
	return abs(cross(p - a, b - a)) / abs(b - a);
}
//liegt p auf a-b
bool pointOnLine(pt a, pt b, pt p) {
	return abs(distToLine(a, b, p)) < EPSILON;
}
//testet, ob d in der gleichen Ebene liegt wie a, b, und c
bool isCoplanar(pt a, pt b, pt c, pt d) {
	return (b - a) * (c - a) * (d - a) == 0;
}
//berechnet den Flaecheninhalt eines Polygons (nicht selbstschneidend)
double areaOfPolygon(vector<pt> &polygon) { //jeder Eckpunkt nur einmal im Vektor
	double res = 0; int n = polygon.size();
	for (int i = 0; i < (int)polygon.size(); i++)
		res += real(polygon[i]) * imag(polygon[(i + 1) % n]) - real(polygon[(i + 1) % n]) * imag(polygon[i]);
	return 0.5 * abs(res);
}
//testet, ob sich zwei Rechtecke (p1, p2) und (p3, p4) schneiden (jeweils gegenueberliegende Ecken)
bool rectIntersection(pt p1, pt p2, pt p3, pt p4) {
	double minx12 = min(real(p1), real(p2)), maxx12 = max(real(p1), real(p2));
	double minx34 = min(real(p3), real(p4)), maxx34 = max(real(p3), real(p4));
	double miny12 = min(imag(p1), imag(p2)), maxy12 = max(imag(p1), imag(p2));
	double miny34 = min(imag(p3), imag(p4)), maxy34 = max(imag(p3), imag(p4));
	return (maxx12 >= minx34) && (maxx34 >= minx12) && (maxy12 >= miny34) && (maxy34 >= miny12);
}
//testet, ob ein Punkt im Polygon liegt (beliebige Polygone)
bool pointInPolygon(pt p, vector<pt> &polygon) { //jeder Eckpunkt nur einmal im Vektor
	pt rayEnd = p + pt(1, 1000000);
	int counter = 0, n = polygon.size();
	for (int i = 0; i < n; i++) {
		pt start = polygon[i], end = polygon[(i + 1) % n];
		if (lineSegmentIntersection(p, rayEnd, start, end)) counter++;
	}
	return counter & 1;
}
