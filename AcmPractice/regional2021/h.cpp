#include <bits/stdc++.h> 

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
    }
    for (int turn = 0; ; turn = 1 - turn) {
      if (n < 2) {
        cout << (turn == 1 ? "Hoang" : "Vuong") << endl; 
        break; 
      }
      n -= 2; 
    }
  }
  return 0; 
}