// Great Cirlce Distance mit Längen- und Breitengrad.
double gcDist(
    double pLat, double pLon, double qLat, double qLon, double radius) {
  pLat *= PI / 180; pLon *= PI / 180; qLat *= PI / 180; qLon *= PI / 180;
  return radius * acos(cos(pLat) * cos(pLon) * cos(qLat) * cos(qLon) +
                       cos(pLat) * sin(pLon) * cos(qLat) * sin(qLon) +
                       sin(pLat) * sin(qLat));
}

// Great Cirlce Distance mit kartesischen Koordinaten.
double gcDist(point p, point q) {
  return acos(p.x * q.x + p.y * q.y + p.z * q.z);
}

// 3D Punkt in kartesischen Koordinaten.
struct point{
  double x, y, z;
  point() {}
  point(double x, double y, double z) : x(x), y(y), z(z) {}
  point(double lat, double lon) {
    lat *= PI / 180.0; lon *= PI / 180.0;
    x = cos(lat) * sin(lon); y = cos(lat) * cos(lon); z = sin(lat);
  }
};
