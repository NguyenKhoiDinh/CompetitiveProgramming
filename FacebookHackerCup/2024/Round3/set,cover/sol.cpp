#include <bits/stdc++.h> 

using namespace std; 
vector <string> a; 
int n, k;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n >> k; 
    a.clear(); 
    a.resize(n); 
    for (int i = 0; i < n; i++) {
      cin >> a[i]; 
    }
    int minRow1 = n + 2, maxRow1 = -1, minCol1 = n + 2, maxCol1 = -1; 
    int minRowQ = n + 2, maxRowQ = -1, minColQ = n + 2, maxColQ = -1; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '1') {
          minRow1 = min(minRow1, i); 
          maxRow1 = max(maxRow1, i);
          minCol1 = min(minCol1, j);
          maxCol1 = max(maxCol1, j); 
        }
        else if (a[i][j] == '?') {
          minRowQ = min(minRowQ, i);
          maxRowQ = max(maxRowQ, i);
          minColQ = min(minColQ, j);
          maxColQ = max(maxColQ, j);                                        
        }
      }
    }
    vector <pair <int, int> > save;
    if (minRowQ != n + 2) {
      int j1 = -1, j2 = -1; 
      for (int j = 0; j < n; j++) {
        if (a[minRowQ][j] == '?') {
          if (j1 == -1) {
            j1 = j; 
          }
          j2 = j; 
        }
      }
      save.push_back(make_pair(minRowQ, j1));
      save.push_back(make_pair(minRowQ, j2));
      j1 = -1, j2 = -1; 
      for (int j = 0; j < n; j++) {
        if (a[maxRowQ][j] == '?') {
          if (j1 == -1) {
            j1 = j; 
          }
          j2 = j; 
        }
      }
      save.push_back(make_pair(maxRowQ, j1));
      save.push_back(make_pair(maxRowQ, j2));
      int i1 = -1, i2 = -1;
      for (int i = 0; i < n; i++) {
        if (a[i][minColQ] == '?') {
          if (i1 == -1) {
            i1 = i; 
          }
          i2 = i; 
        }
      }
      save.push_back(make_pair(i1, minColQ));
      save.push_back(make_pair(i2, minColQ));
      i1 = -1, i2 = -1;
      for (int i = 0; i < n; i++) {
        if (a[i][maxColQ] == '?') {
          if (i1 == -1) {
            i1 = i;
          }
          i2 = i; 
        }
      } 
      save.push_back(make_pair(i1, maxColQ)); 
      save.push_back(make_pair(i2, maxColQ)); 
    }
    int sz = (int) save.size();
    int ans = 0;
    for (int mask = 0; mask < (1 << sz); mask++) {
      if ((int) __builtin_popcount(mask) > k) {
        continue; 
      }
      int tmpMinRow = minRow1, tmpMaxRow = maxRow1, tmpMinCol = minCol1, tmpMaxCol = maxCol1;
      for (int i = 0; i < sz; i++) {
        if ((mask & (1 << i)) > 0) {
          tmpMinRow = min(tmpMinRow, save[i].first);
          tmpMaxRow = max(tmpMaxRow, save[i].first); 
          tmpMinCol = min(tmpMinCol, save[i].second); 
          tmpMaxCol = max(tmpMaxCol, save[i].second); 
        }
      }
      if (tmpMaxRow == -1) {
        continue; 
      }
      ans = max(ans, (tmpMaxRow - tmpMinRow + 1) * (tmpMaxCol - tmpMinCol + 1));
    } 
    cout << ans << endl; 
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}