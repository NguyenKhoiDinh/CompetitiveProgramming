#include <bits/stdc++.h>

using namespace std;
const int inf = 1000000007; 
int n, m, numQueries; 
int a[200005];        
int b[200005]; 
int f[200005]; 
set <int> listPositions[200005]; 
int fail = 0; 
void update(int value, int index, bool isAdd) {
  int curp = *listPositions[value].begin(); 
  if (value > 1) {
    int prev = value - 1; 
    int p = *listPositions[prev].begin(); 
    fail -= p > curp; 
  }
  if (value < n) {
    int nxt = value + 1; 
    int p = *listPositions[nxt].begin(); 
    fail -= curp > p; 
  }
  if (isAdd == false) {
    listPositions[value].erase(listPositions[value].find(index));   
  }
  else {
    listPositions[value].insert(index); 
  }
  curp = *listPositions[value].begin(); 
  if (value > 1) {
    int prev = value - 1; 
    int p = *listPositions[prev].begin(); 
    fail += p > curp; 
  }
  if (value < n) {
    int nxt = value + 1; 
    int p = *listPositions[nxt].begin(); 
    fail += curp > p; 
  }
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    fail = 0; 
    cin >> n >> m >> numQueries; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      f[a[i]] = i;  
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
      b[i] = f[b[i]];  
    }
    for (int i = 1; i <= n; i++) {
      listPositions[i].clear(); 
      listPositions[i].insert(inf); 
    }
    for (int i = 1; i <= m; i++) {
      listPositions[b[i]].insert(i);
    }
    for (int i = 1; i < n; i++) {
      int p1 = *listPositions[i].begin(); 
      int p2 = *listPositions[i + 1].begin();
      fail += p1 > p2;  
    }
    cout << (fail == 0 ? "YA" : "TIDAK") << endl;
    for (int query = 1; query <= numQueries; query++) {
      int s, t; 
      cin >> s >> t;
      t = f[t]; 
      update(b[s], s, false);
      b[s] = t;
      update(b[s], s, true);
      cout << (fail == 0 ? "YA" : "TIDAK") << endl;   
    }  
  }               
  return 0; 
}