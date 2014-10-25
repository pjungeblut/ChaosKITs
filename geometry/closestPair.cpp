double squaredDist(point a, point b) {
	return (a.first-b.first) * (a.first-b.first) + (a.second-b.second) * (a.second-b.second);
}

bool compY(point a, point b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

double shortestDist(vector<point> &points) {
	//check that points.size() > 1 and that ALL POINTS ARE DIFFERENT
	set<point, bool(*)(point, point)> status(compY);
	sort(points.begin(), points.end());
	double opt = 1e30, sqrtOpt = 1e15;
	auto left = points.begin(), right = points.begin();
	status.insert(*right); right++;
	
	while (right != points.end()) {
		if (fabs(left->first - right->first) >= sqrtOpt) {
			status.erase(*(left++));
		} else {
			auto lower = status.lower_bound(point(-1e20, right->second - sqrtOpt));
			auto upper = status.upper_bound(point(-1e20, right->second + sqrtOpt));
			while (lower != upper) {
				double cand = squaredDist(*right, *lower);
				if (cand < opt) {
					opt = cand;
					sqrtOpt = sqrt(opt);
				}
				++lower;
			}
			status.insert(*(right++));
		}
	}
	return sqrtOpt;
}
