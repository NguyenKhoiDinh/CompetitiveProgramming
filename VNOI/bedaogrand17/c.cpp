#include <bits/stdc++.h>
using namespace std;
const int lim = 1000000007;  
struct point {
  int x, y; 
};
int n, ans;
vector <point> a;                
vector <point> getConor(const vector <point> &a) {
  int maxx = -lim;
  int minx = lim;
  int maxy = -lim;
  int miny = lim; 
  for (int i = 0; i < (int) a.size(); i++) {
    maxx = max(maxx, a[i].x);
    minx = min(minx, a[i].x); 
    maxy = max(maxy, a[i].y); 
    miny = min(miny, a[i].y); 
  }
  vector <point> ret; 
  ret.push_back((point) {minx, miny});
  ret.push_back((point) {minx, maxy});
  ret.push_back((point) {maxx, maxy});
  ret.push_back((point) {maxx, miny}); 
  return ret;  
}
bool check(const vector <point> &a, int d, int numb) {
  if ((int) a.size() <= numb) {
    return true; 
  }
  vector <point> conor = getConor(a);
  if (numb == 1) {
    if (conor[2].x - conor[0].x <= d && conor[2].y - conor[0].y <= d) {
      return true; 
    }   
    else {
      return false; 
    }
  }
  for (int j = 0; j < 4; j++) {
    int lx = conor[j].x; 
    int ly = conor[j].y;
    int rx = lx + d;
    int ry = ly + d;
    if (j == 1) {
      ry = ly - d;
      swap(ly, ry);  
    }
    else if (j == 2) {
      rx = lx - d;
      swap(lx, rx); 
      ry = ly - d;                 
      swap(ly, ry); 
    }  
    else if (j == 3) {
      rx = lx - d; 
      swap(lx, rx); 
    }
    vector <point> new_points;
    for (int i = 0; i < (int) a.size(); i++) {
      if (lx <= a[i].x && a[i].x <= rx && ly <= a[i].y && a[i].y <= ry) {
        continue; 
      }  
      new_points.push_back(a[i]); 
    }
    if (check(new_points, d, numb - 1) == true) {
      return true; 
    }
  }
  return false; 
}

int main () {
  ios_base::sync_with_stdio(false); 
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y; 
  }
  int lo = 1;
  int hi = 2000000000;            
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    if (check(a, mid, 3) == true) {
      ans = mid; 
      hi = mid - 1; 
    }
    else {
      lo = mid + 1;
    }
  }
  cout << (long long) ans * ans; 
  return 0;                                                          
}                                                  