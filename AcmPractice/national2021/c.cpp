#include<bits/stdc++.h>
using namespace std;
 
struct Point {
    int x, y;
    Point (int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }
 
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
 
    long long modul(void) const {
        return 1LL * x * x + 1LL * y * y;
    }
 
    long long operator % (const Point &p) const {
        return 1LL * x * p.y - 1LL * p.x * y;
    }
};
 
bool inALine(const Point &a, const Point &b, const Point &c) {
    return (b - a) % (c - a) == 0;
}
 
struct Triangle {
    long long x, y, z;
 
    Triangle(long long _x = 0, long long _y = 0, long long _z = 0) {
        x = _x; y = _y; z = _z;
        if (x > y) swap(x, y);
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);
    }
 
    int coeff(void) const {
        if (x == y && y == z) return 6;
        if (x == y || y == z) return 2;
        return 1;
    }
 
    bool operator < (const Triangle &t) const {
        if (x != t.x) return x < t.x;
        if (y != t.y) return y < t.y;
        if (z != t.z) return z < t.z;
        return false;
    }
};
 
int n;
Point points[105];
map <Triangle, int> cnt, cntOne[105], cntTwo[105][105];
 
void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    points[i] = Point(x, y); 
  }  
}
 
int getCount(const map <Triangle, int> &mp, const Triangle &t) {
  __typeof(mp.begin()) it = mp.find(t);
  return (it == mp.end() ? 0 : it->second);
}
 
void solve() {
  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      for (int k = j + 1; k <= n; k++) {
        if (inALine(points[i], points[j], points[k]) == false) {
          long long ab = (points[i] - points[j]).modul();
          long long bc = (points[j] - points[k]).modul();
          long long ca = (points[k] - points[i]).modul();
          Triangle abc(ab, bc, ca); 
          int delta = abc.coeff(); 
          cnt[abc] += delta;
          cntOne[i][abc] += delta;
          cntOne[j][abc] += delta;
          cntOne[k][abc] += delta;
          cntTwo[i][j][abc] += delta;
          cntTwo[i][k][abc] += delta;
          cntTwo[j][k][abc] += delta;
        }
      }
    }
  } 
  long long res = 0;
  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      for (int k = j + 1; k <= n; k++) {
        if (!inALine(points[i], points[j], points[k])) {
          long long ab = (points[i] - points[j]).modul();
          long long bc = (points[j] - points[k]).modul();
          long long ca = (points[k] - points[i]).modul();
          Triangle abc(ab, bc, ca);
          res += getCount(cnt, abc);
          res -= getCount(cntOne[i], abc) + getCount(cntOne[j], abc) + getCount(cntOne[k], abc);
          res += getCount(cntTwo[i][j], abc) + getCount(cntTwo[i][k], abc) + getCount(cntTwo[j][k], abc);
          res -= abc.coeff();
        }
      }
    }
  }      
  cout << res;
}
 
int main () {
  init();
  solve();
  return 0;
}