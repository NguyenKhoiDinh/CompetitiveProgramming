#include <bits/stdc++.h> 

using namespace std;
int a[505][505]; 
int swapPos[505][505];
int n, m;

bool comp(const vector <int> &a, const vector <int> &b) {
  for (int i = 0; i < m; i++) {
    if (a[i] != b[i]) {
      return a[i] > b[i];
    }
  }
  return false; 
}

int main () {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j]; 
    }
    for (int j = 1; j <= m; j++) {
      swapPos[i][m - a[i][j] + 1] = j;
    }
  }
  vector <int> maxVector; 
  for (int i = 1; i <= n * m; i++) {
    maxVector.push_back(-1); 
  }
  for (int i = 1; i <= n; i++) {
    vector <vector <int> > save; 
    for (int j = 1; j <= n; j++) {
      vector <int> v; 
      for (int k = 1; k <= m; k++) {
        v.push_back(a[j][swapPos[i][k]]);   
      }
      save.push_back(v); 
    }
    sort(save.begin(), save.end(), comp); 
    vector <int> b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        b.push_back(save[i][j]); 
      }
    }
    if (maxVector < b) {
      maxVector = b; 
    }
  }                     
  int query;
  cin >> query;
  for (int i = 1; i <= query; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << maxVector[x * m + y] << endl; 
  }
  return 0;
}