#include <bits/stdc++.h> 

using namespace std;
const long long mod = 1000000007LL;
const int inf = 10000005;  
long long f[55][55][55][55]; 
struct point {
  int x, y; 
  bool operator < (const point &other) {
    return y < other.y;
  }
  bool operator == (const point &other) {
    return (x == other.x && y == other.y); 
  }
};
struct vecto {
  int x, y; 
  vecto(int _x, int _y) {
    x = _x;
    y = _y;
  }
  double dot(const vecto &other) {
    return x * other.x + y * other.y; 
  }
  double cross(const vecto &other) {
    return x * other.y - y * other.x; 
  }
  double length() {
    return std::sqrt(x * x + y * y); 
  }
};
 
vecto operator + (const vecto &A, const vecto &B) {
  return (vecto) {A.x + B.x, A.y + B.y};  
}
vecto operator - (const vecto &A, const vecto &B) {
  return (vecto) {B.x - A.x, B.y - A.y};
}
bool isOnSegment(const point &A, const point &B, const point &C) { // check point C is on a segment AB
  vecto AB(B.x - A.x, B.y - A.y);
  vecto AC(C.x - A.x, C.y - A.y);  
  if (AB.cross(AC) == 0) {
    vecto CA(A.x - C.x, A.y - C.y);
    vecto CB(B.x - C.x, B.y - C.y);
    if (CA.dot(CB) < 0) {
      return true; 
    } 
  }
  return false; 
}  
 
int ccw(const point &A, const point &B, const point &C) { // check counter clockwise
  vecto AB(B.x - A.x, B.y - A.y);
  vecto AC(C.x - A.x, C.y - A.y); 
  if (AB.cross(AC) < 0) {
    return 1; 
  }
  else if (AB.cross(AC) > 0) {
    return -1; 
  }
  return 0; 
}
point pc[55]; 
int n; 
point p[55]; 
int maxHeight[55][55]; 
bool isValid(point &A, point &B, point &C, point &D) {
  if (A == C || A == D || B == C || B == D) {
    return false; 
  }
  if (isOnSegment(A, B, C) == true || isOnSegment(A, B, D) == true || isOnSegment(C, D, A) == true || isOnSegment(C, D, B) == true) {
    return false;  
  }
  if ((ccw(A, B, C) * ccw(A, B, D) < 0) && (ccw(C, D, A) * ccw(C, D, B) < 0)) {
    return false; 
  }  
  return true; 
}

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> pc[i].y; 
    pc[i].x = 0;  
  }
  pc[0].y = 0;
  pc[n + 1].y = 100005; 
  sort(pc, pc + n + 2); 
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y; 
  }
  p[0].x = inf; 
  p[0].y = 0;
  p[n + 1].x = inf;
  p[n + 1].y = 100005;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = i; j <= n + 1; j++) {
      int maxH = -1; 
      maxHeight[i][j] = -1; 
      for (int k = i; k <= j; k++) {
        if (maxH < p[k].y) {
          maxH = p[k].y; 
          maxHeight[i][j] = k; 
        }
      }
    }
  }  
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      if (i == 0 && j != 0) {
        continue; 
      }
      if (i == n + 1 && j != n + 1) {
        continue; 
      }
      f[i][i][j][j] = 1; 
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j1 = 0; j1 <= n + 1; j1++) {
      for (int j2 = 0; j2 <= n + 1; j2++) {
        if (i == 0 && j1 != 0) {
          continue; 
        }
        if (i + 1 == n + 1 && j2 != n + 1) {
          continue; 
        }
        if (isValid(pc[i], p[j1], pc[i + 1], p[j2]) == true) {                                      
          f[i][i + 1][j1][j2] = 1;
        }
      }
    }
  }
  for (int l = n - 1; l >= 0; l--) {
    for (int r = l + 2; r <= n + 1; r++) {
      for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
          if (i == j) {
            continue; 
          }
          if (l == 0 && i != 0) {
            continue; 
          }
          if (r == n + 1 && j != n + 1) {
            continue;
          }
          if (isValid(pc[l], p[i], pc[r], p[j]) == false) {
            continue; 
          }
          for (int m = l + 1; m <= r - 1; m++) {
            int maxHeight = -1; 
            int h = -1; 
            for (int k = 0; k <= n + 1; k++) {
              if (p[k].x <= p[i].x && p[k].x <= p[j].x && maxHeight < p[k].x && isValid(pc[m], p[k], pc[l], p[i]) == true && isValid(pc[m], p[k], pc[r], p[j]) == true) {
                maxHeight = p[k].x;
                h = k; 
              }  
            }
            if (h != -1) {
              (f[l][r][i][j] += (f[l][m][i][h] * f[m][r][h][j]) % mod) %= mod; 
            }
          }
        }
      }
    } 
  }                                                 
  cout << f[0][n + 1][0][n + 1]; 
  return 0; 
}