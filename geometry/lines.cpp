struct pt { //complex<double> does not work here, becuase we need to set pt.x and pt.y
	double x, y;
	pt() {};
	pt(double x, double y) : x(x), y(y) {};
};

struct line {
	double a, b, c; //a*x+b*y+c, b=0 <=> vertical line, b=1 <=> otherwise
};

line pointsToLine(pt p1, pt p2) {
	line l;
	if (fabs(p1.x - p2.x) < EPSILON) {
		l.a = 1; l.b = 0.0; l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
	return l;
}

bool areParallel(line l1, line l2) {
	return (fabs(l1.a - l2.a) < EPSILON) && (fabs(l1.b - l2.b) < EPSILON);
}

bool areSame(line l1, line l2) {
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPSILON);
}

bool areIntersect(line l1, line l2, pt &p) {
	if (areParallel(l1, l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPSILON) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return true;
}