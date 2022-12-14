#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
int m, n; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> m >> n; 
    cout << 3 * n << endl; 
    for (int i = 1; i <= n; i++) {
      int x, y; 
      cin >> x >> y; 
      if (x == 0 && y == 0) {
        cout << "2 0 0 0 1 1 1" << endl;
        cout << "2 1 0 0 0 0 1" << endl;
        cout << "2 1 1 1 0 0 0" << endl; 
      }
      else if (x == 0) {
        cout << 2 << ' ' << x << ' ' << y << ' ' << x << ' ' << y - 1 << ' ' << x + 1 << ' ' << y - 1 << endl;
        cout << 2 << ' ' << x + 1 << ' ' << y << ' ' << x << ' ' << y << ' ' << x << ' ' << y - 1 << endl; 
        cout << 2 << ' ' << x + 1 << ' ' << y - 1 << ' ' << x + 1 << ' ' << y << ' ' << x << ' ' << y << endl; 
      }
      else if (y == 0) {
        cout << 2 << ' ' << x << ' ' << y << ' ' << x << ' ' << y + 1 << ' ' << x - 1 << ' ' << y + 1 << endl; 
        cout << 2 << ' ' << x - 1 << ' ' << y << ' ' << x << ' ' << y << ' ' << x << ' ' << y + 1 << endl; 
        cout << 2 << ' ' << x - 1 << ' ' << y + 1 << ' ' << x - 1 << ' ' << y << ' ' << x << ' ' << y << endl; 
      }
      else {
        cout << 2 << ' ' << x << ' ' << y << ' ' << x << ' ' << y - 1 << ' ' << x - 1 << ' ' << y - 1 << endl;
        cout << 2 << ' ' << x - 1 << ' ' << y << ' ' << x << ' ' << y << ' ' << x << ' ' << y - 1 << endl;
        cout << 2 << ' ' << x - 1 << ' ' << y - 1 << ' ' << x - 1 << ' ' << y << ' ' << x << ' ' << y << endl; 
      }
    }
  }
  return 0; 
}