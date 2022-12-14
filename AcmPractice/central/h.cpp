#include <bits/stdc++.h> 

using namespace std;
struct Point {
  double x, y; 
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  Point operator + (const Point &other) {
    Point ret(x, y);
    ret.x += other.x;
    ret.y += other.y;
    return ret;
  }
  Point operator - (const Point &other) {
    Point ret(x, y);
    ret.x -= other.x;
    ret.y -= other.y;
    return ret;
  }
};
const double EPS = 0.000000001; 
const double PI = acos(-1);

struct Circle { 
  double x, y, r;
  double area() { 
    return r * r * PI; 
  } 
  double segment_area(double theta) const {
    return 0.5 * r * r * (theta - sin(theta));
  }
};

struct Line {
  double a, b, c; 
  Line(Point A, Point B) {
    a = B.y - A.y;
    b = A.x - B.x; 
    c = a * A.x + b * A.y; 
  }
};

// Find common tangents to 2 circles
// Tested:
// - http://codeforces.com/gym/100803/ - H
// Helper method
vector<Point> intersection(Line l, Circle cir) {
    double r = cir.r, a = l.a, b = l.b, c = l.c + l.a*cir.x + l.b*cir.y;
    vector<Point> res;

    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    if (abs(c*c - r*r*(a*a+b*b)) < EPS) {
        res.push_back(Point(x0, y0) + Point(cir.x, cir.y));
        res.push_back(Point(x0, y0) + Point(cir.x, cir.y));

        return res;
    }
    else {
        double d = r*r - c*c/(a*a+b*b);
        double mult = sqrt (d / (a*a+b*b));
        double ax,ay,bx,by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;

        res.push_back(Point(ax, ay) + Point(cir.x, cir.y));
        res.push_back(Point(bx, by) + Point(cir.x, cir.y));
        return res;
    }
}

double distance(const Point &A, const Point &B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); 
}

double distancePointToLine(const Point &C, const Line &L) {
  double ret = abs(L.a * C.x + L.b * C.y + L.c); 
  ret /= sqrt(L.a * L.a + L.b * L.b); 
  return ret; 
}

double squareTriangle(const Point &A, const Point &B, const Point &C) {
  double AB = distance(A, B);
  double AC = distance(A, C);
  double BC = distance(B, C);
  double p = (AB + AC + BC) * 0.5; 
  double ret = p;
  ret *= (p - AB); 
  ret *= (p - AC);
  ret *= (p - BC);
  return sqrt(ret); 
}

Point A(0, 0), B(0, 0), C(0, 0);
double radius, percent; 

int main () {
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> radius >> percent; 
  Circle cir;
  cir.x = C.x;
  cir.y = C.y;
  cir.r = radius;
  Line l(A, B);                                                                   
  double distanceFromPointToLine = 2.0 * squareTriangle(A, B, C) / distance(A, B); 
  if (distanceFromPointToLine >= radius) {
    cout << "NO";
    return 0; 
  }          
  vector <Point> listPoints = intersection(l, cir);
  if ((int) listPoints.size() == 2) {
    cout << "YES";
    return 0;
  }
  for (int i = 0; i < (int) listPoints.size(); i++) {
    swap(listPoints[i].x, listPoints[i].y);
  }
  Point vtCA = Point(A.x - C.x, A.y - C.y);
  Point vtCB = Point(B.x - C.x, B.y - C.y);
  double angle = abs(vtCA.x * vtCB.x + vtCA.y * vtCB.y); 
  angle /= distance(C, A); 
  angle /= distance(C, B);
  angle = acos(angle); 
  double partSquare = cir.segment_area(angle);
  percent *= 0.01; 
  partSquare /= cir.area();  
  if (partSquare >= percent - 0.05 && partSquare <= percent + 0.05) {
    cout << "YES"; 
  } 
  else {
    cout << "NO";
  }
  return 0; 
}                                         