#include <bits/stdc++.h>

using namespace std; 
const int MAX_N = 300005; 
const int inf = 1000000007; 

struct element {
  int x, type;
  bool operator < (const element &other) const {
    return (x < other.x);
  } 
};
vector <element> a; 
int n, type1, type2; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> type1 >> type2; 
  for (int i = 1; i <= n; i++) {
    element e;
    cin >> e.x >> e.type; 
    a.push_back(e);
  }
  sort(a.begin(), a.end()); 
  int cntFirst = 0, cntSecond = 0; 
  int l = 0;
  int ans = inf;  
  for (int i = 0; i < n; i++) {
    if (a[i].type == 1) {
      cntFirst++; 
    }
    else {
      cntSecond++;
    }
    while (cntFirst >= type1 && cntSecond >= type2) {
      ans = min(ans, a[i].x - a[l].x); 
      if (a[l].type == 1) { 
        cntFirst--; 
      }
      else {
        cntSecond--; 
      }
      l++;
    }
  }
  cout << (ans == inf ? -1 : ans);
  return 0; 
}