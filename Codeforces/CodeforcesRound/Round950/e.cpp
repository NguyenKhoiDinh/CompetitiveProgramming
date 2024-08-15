#include <bits/stdc++.h>

using namespace std;
int numTest; 
vector <std::vector <int> > rotateMatrix(const vector <vector <int> > &a) {
  int n = (int) a.size();
  int m = (int) a[0].size();
  vector <vector <int> > ret;
  for (int i = m - 1; i >= 0; i--) {
    vector <int> v; 
    for (int j = 0; j < n; j++) {
      v.push_back(a[j][i]);  
    }
    ret.push_back(v); 
  }  
  return ret; 
}
int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m;
    cin >> n >> m; 
    vector <vector <int> > a;
    vector <vector <int> > b;
    a.resize(n);
    b.resize(n); 
    for (int i = 0; i < n; i++) {
      a[i].resize(m);
      b[i].resize(m); 
    }  
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j]; 
        a[i][j]--;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
        b[i][j]--; 
      }
    }
    if (n > m) {
      swap(n, m);
      a = rotateMatrix(a);
      b = rotateMatrix(b);   
    }
    bool ok = true; 
    vector <int> base; 
    for (int i = 0; i < n; i++) {
      if (ok == false) {
        break; 
      }
      vector <int> &ba = a[i];
      vector <int> check(n * m, false); 
      for (int j = 0; j < m; j++) {
        check[ba[j]] = true;   
      }
      vector <int> pos(n * m, 0); 
      for (int j = 0; j < n; j++) {
        int numbCorrect = 0;
        vector <int> &bb = b[j];
        for (int k = 0; k < m; k++) {
          if (check[bb[k]] == true) {
            numbCorrect++; 
          }
        }
        if (numbCorrect == 0) {
          continue; 
        }
        if (numbCorrect < m) {
          ok = false;
          break; 
        }
        for (int k = 0; k < m; k++) {
          pos[bb[k]] = k; 
        }  
        break;
      }
      vector <int> baseValid; 
      for (int j = 0; j < m; j++) {
        baseValid.push_back(pos[ba[j]]);
      }
      if (base.empty() == true) {
        base = baseValid; 
      }
      else if (base != baseValid) {
        ok = false;
        break; 
      }
    }
    cout << (ok == true ? "YES" : "NO") << endl;
  }
  return 0; 
}