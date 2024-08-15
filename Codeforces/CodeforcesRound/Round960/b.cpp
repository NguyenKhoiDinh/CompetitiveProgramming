#include <bits/stdc++.h>

using namespace std;
int numTest; 
int a[100005]; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, x, y;
    std::cin >> n >> x >> y;
    bool flag = true; 
    for (int i = y - 1; i >= 1; i--) {
      a[i] = (flag == true ? -1 : 1); 
      flag = !flag; 
    }
    flag = true;
    for (int i = x + 1; i <= n; i++) {
      a[i] = (flag == true ? -1 : 1); 
      flag = !flag; 
    }
    for (int i = y; i <= x; i++) {
      a[i] = 1; 
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0; 
}