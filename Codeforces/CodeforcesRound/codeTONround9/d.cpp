#include <bits/stdc++.h>

using namespace std;
int n, m; 
int position[300005]; 
int a[300005]; 
vector <int> listDivisors[300005]; 
void erathones() {
  for (int i = 1; i <= 300000; i++) {
    for (int j = 2 * i; j <= 300000; j += i) {
      listDivisors[j].push_back(i); 
    }
  }
}

int main () {
  erathones();
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> a[i];     
    } 
    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
    bool ok = true; 
    position[1] = 1;
    for (int i = 2; i <= n; i++) {
      int maxPos = -1; 
      for (int j = 0; j < (int) listDivisors[i].size(); j++) {
        int d = listDivisors[i][j]; 
        if (position[d] + 1 <= m) {
          maxPos = max(maxPos, position[d] + 1); 
        }
        else {
          maxPos = -1; 
          break; 
        }
      }
      if (maxPos == -1) {
        cout << -1 << endl;
        ok = false;
        break;
      }
      else {
        position[i] = maxPos; 
      }
    }  
    if (ok == false) {
      continue; 
    }
    for (int i = 1; i <= n; i++) {
      cout << a[position[i]] << ' ';
    }
    cout << endl;
  }
  return 0; 
}