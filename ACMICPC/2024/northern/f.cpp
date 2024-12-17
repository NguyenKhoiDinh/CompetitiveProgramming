#include <bits/stdc++.h> 

using namespace std;
struct point {
  long double x = 0.0, y = 0.0;
  bool operator < (const point &other) {
    return (x < other.x || (x == other.x && y >= other.y)); 
  } 
};
struct line {
  long double a, b, c; 
};
point p[100005]; 
int n, m, numTest;
line l[100005]; 
int ccw(point A, point B, point C) {
  point AB = (point) {B.x - A.x, B.y - A.y};
  point AC = (point) {C.x - A.x, C.y - A.y};
  if (AB.x * AC.y - AC.x * AB.y < 0) {
    return -1; 
  }                                            
  else if (AB.x * AC.y - AC.x * AB.y > 0) {
    return 1; 
  }
  return 0; 
}

int main () {                      
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    assert(1 <= n && n <= 100000);
    for (int i = 1; i <= n; i++) {
      cin >> p[i].x >> p[i].y; 
    }
    sort(p + 1, p + n + 1);
    point A = p[1], B = p[1], C = p[1], D = p[1], E = p[1], F = p[1], G = p[1], H = p[1]; 
    long double maxX = p[1].x, minX = p[1].x, maxY = p[1].y, minY = p[1].y; 
    for (int i = 2; i <= n; i++) {
      if (maxX < p[i].x) {
        maxX = p[i].x; 
        A = p[i]; 
      }
      else if (maxX == p[i].x) {
        E = p[i]; 
      }
      if (minX > p[i].x) {
        minX = p[i].x;
        B = p[i]; 
      }
      else if (minX == p[i].x) {
        F = p[i]; 
      }
      if (maxY < p[i].y) {
        maxY = p[i].y;
        C = p[i]; 
      }
      else if (maxY == p[i].y) {
        G = p[i]; 
      }
      if (minY > p[i].y) {
        minY = p[i].y;
        D = p[i]; 
      }
      else if (minY == p[i].y) {
        H = p[i]; 
      }
    }
    int ans = 0; 
    cin >> m; 
    for (int i = 1; i <= m; i++) {
      int va, vb, vc;
      cin >> va >> vb >> vc;
      l[i].a = va;
      l[i].b = vb;
      l[i].c = vc;
      point X, Y; 
      X.x = (vb == 0 ? -l[i].c : 0.0); 
      X.y = (vb == 0 ? 0.0 : (-l[i].c - l[i].a * X.x) / l[i].b); 
      Y.x = (vb == 0 ? -l[i].c : 100.0);
      Y.y = (vb == 0 ? 100.0 : (-l[i].c - l[i].a * Y.x) / l[i].b);
      const long double eps = 1e-12; 
      assert(fabs(l[i].a * X.x + l[i].b * X.y + l[i].c - eps) >= 0.0);
      assert(fabs(l[i].a * Y.x + l[i].b * Y.y + l[i].c - eps) >= 0.0); 
      bool ok = false;
      if (ccw(X, Y, A) < 0 && ccw(X, Y, B) < 0 && ccw(X, Y, C) < 0 && ccw(X, Y, D) < 0 && ccw(X, Y, E) < 0 && ccw(X, Y, F) < 0 && ccw(X, Y, G) < 0 && ccw(X, Y, H) < 0) {
        ok = true; 
      }
      if (ccw(X, Y, A) > 0 && ccw(X, Y, B) > 0 && ccw(X, Y, C) > 0 && ccw(X, Y, D) > 0 && ccw(X, Y, E) > 0 && ccw(X, Y, F) > 0 && ccw(X, Y, G) > 0 && ccw(X, Y, H) > 0) {
        ok = true;
      }  
      if (ok == true) {
        ans++;
      }
    }
    cout << ans << endl;
  }                                        
  return 0; 
}