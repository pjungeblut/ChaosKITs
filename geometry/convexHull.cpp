#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct point {
  double x, y;
  point(){} point(double x, double y) : x(x), y(y) {}
  bool operator <(const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};
 
// 2D cross product.
// Return a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
double cross(const point &O, const point &A, const point &B){
  double d = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
  if (fabs(d) < 1e-9) return 0.0;
  return d;
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Colinear points are not in the convex hull, if you want colinear points in the hull remove "=" in the CCW-Test
// Note: the last point in the returned list is the same as the first one.
vector<point> convexHull(vector<point> P){
  int n = P.size(), k = 0;
  vector<point> H(2*n);
  
  // Sort points lexicographically
  sort(P.begin(), P.end());
  
  // Build lower hull
  for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0.0) k--;
    H[k++] = P[i];
  }
  
  // Build upper hull
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0.0) k--;
    H[k++] = P[i];
  }
  
  H.resize(k);
  return H;
}
