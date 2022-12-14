#include <bits/stdc++.h> 

using namespace std;

struct athletic {
  int r[5];
  int id;  
};

athletic a[50005]; 

bool compare(athletic &a, athletic &b) {
  int numbWin = 0;
  for (int i = 0; i < 5; i++) {
    if (a.r[i] < b.r[i]) {
      numbWin++;
    }
  }
  return (numbWin >= 3);
}              
int n, numTest;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i].r[j];
      }
      a[i].id = i; 
    }
    sort(a + 1, a + n + 1, compare);
    bool ok = true; 
    for (int i = 2; i <= n; i++) {
      if (compare(a[1], a[i]) == false) {
        ok = false;
        break; 
      } 
    }
    if (ok == true) {
      cout << a[1].id << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
  return 0; 
}