#include <bits/stdc++.h>

using namespace std;
int numTest; 
int a, b, n, m; 
struct point {
  int x, y, id; 
};
point p[400005];  
bool compareToX(point &a, point &b) {
  return a.x < b.x; 
}
bool compareToY(point &a, point &b) {
  return a.y < b.y; 
}
bool compareToId(point &a, point &b) {
  return a.id < b.id; 
}
set <int> Sx[400005], Sy[400005]; 
map <int, int> idX, idY;
int realx[400005], realy[400005];  

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> a >> b >> n >> m; 
    for (int i = 1; i <= n; i++) {
      Sx[i].clear();
      Sy[i].clear(); 
    }
    for (int i = 1; i <= n; i++) {
      cin >> p[i].x >> p[i].y;
      p[i].id = i;  
    }
    sort(p + 1, p + n + 1, compareToX);
    idX.clear();
    for (int i = 1; i <= n; i++) {
      if (idX.find(p[i].x) == idX.end()) {
        int sz = (int) idX.size(); 
        idX[p[i].x] = sz + 1; 
      }
    }
    for (int i = 1; i <= n; i++) {
      int x = idX[p[i].x];
      realx[x] = p[i].x;  
      Sx[x].insert(p[i].id); 
    }
    sort(p + 1, p + n + 1, compareToY);
    idY.clear();
    for (int i = 1; i <= n; i++) {
      if (idY.find(p[i].y) == idY.end()) {
        int sz = (int) idY.size(); 
        idY[p[i].y] = sz + 1; 
      }
    }
    for (int i = 1; i <= n; i++) {
      int y = idY[p[i].y];
      realy[y] = p[i].y;  
      Sy[y].insert(p[i].id); 
    }
    sort(p + 1, p + n + 1, compareToId); 
    int loX = 0, loY = 0, hiX = a + 1, hiY = b + 1;
    int lX = 1, rX = (int) idX.size(), lY = 1, rY = (int) idY.size();
    int alice = 0;
    int bob = 0; 
    bool isSwap = false; 
    for (int query = 1; query <= m; query++) {
      char type;
      int k; 
      cin >> type >> k; 
      if (type == 'D') {
        hiX -= k; 
        while (realx[rX] >= hiX) {
          (isSwap == false ? alice += (int) Sx[rX].size() : bob += (int) Sx[rX].size()); 
          for (set <int>::iterator it = Sx[rX].begin(); it != Sx[rX].end(); it++) {
            int id = *it;   
            int y = idY[p[id].y];
            if (Sy[y].find(id) != Sy[y].end()) {
              Sy[y].erase(Sy[y].find(id)); 
            }  
          }
          Sx[rX].clear(); 
          rX--; 
        }
      }
      else if (type == 'U') {
        loX += k; 
        while (realx[lX] <= loX) {
          (isSwap == false ? alice += (int) Sx[lX].size() : bob += (int) Sx[lX].size());
          for (set <int>::iterator it = Sx[lX].begin(); it != Sx[lX].end(); it++) {
            int id = *it; 
            int y = idY[p[id].y];
            if (Sy[y].find(id) != Sy[y].end()) {
              Sy[y].erase(Sy[y].find(id)); 
            } 
          }
          Sx[lX].clear(); 
          lX++; 
        }
      }
      else if (type == 'L') {
        loY += k; 
        while (realy[lY] <= loY) {
          (isSwap == false ? alice += (int) Sy[lY].size() : bob += (int) Sy[lY].size());
          for (set <int>::iterator it = Sy[lY].begin(); it != Sy[lY].end(); it++) {
            int id = *it; 
            int x = idX[p[id].x]; 
            if (Sx[x].find(id) != Sx[x].end()) {
              Sx[x].erase(Sx[x].find(id)); 
            }
          }
          Sy[lY].clear(); 
          lY++; 
        }
      }
      else {
        hiY -= k; 
        while (realy[rY] >= hiY) {
          (isSwap == false ? alice += (int) Sy[rY].size() : bob += (int) Sy[rY].size());
          for (set <int>::iterator it = Sy[rY].begin(); it != Sy[rY].end(); it++) {
            int id = *it; 
            int x = idX[p[id].x]; 
            if (Sx[x].find(id) != Sx[x].end()) {
              Sx[x].erase(Sx[x].find(id)); 
            }
          }
          Sy[rY].clear();
          rY--; 
        }
      }
      isSwap = !isSwap; 
    }    
    cout << alice << ' ' << bob << endl; 
  }
  return 0; 
}