double squaredDist(pt a, pt b) {
	return (a.fst-b.fst) * (a.fst-b.fst) + (a.snd-b.snd) * (a.snd-b.snd);
}

bool compY(pt a, pt b) {
	if (a.snd == b.snd) return a.fst < b.fst;
	return a.snd < b.snd;
}

// points.size() > 1 und alle Punkte müssen verschieden sein!
double shortestDist(vector<pt> &points) {
	set<pt, bool(*)(pt, pt)> status(compY);
	sort(points.begin(), points.end());
	double opt = 1e30, sqrtOpt = 1e15;
	auto left = points.begin(), right = points.begin();
	status.insert(*right); right++;
	
	while (right != points.end()) {
		if (fabs(left->fst - right->fst) >= sqrtOpt) {
			status.erase(*(left++));
		} else {
			auto lower = status.lower_bound(pt(-1e20, right->snd - sqrtOpt));
			auto upper = status.upper_bound(pt(-1e20, right->snd + sqrtOpt));
			while (lower != upper) {
				double cand = squaredDist(*right, *lower);
				if (cand < opt) {
					opt = cand;
					sqrtOpt = sqrt(opt);
				}
				++lower;
			}
			status.insert(*(right++));
	}}
	return sqrtOpt;
}
