#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
string P, I; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> P >> I; 
    int p = 0; 
    int q = 0; 
    while (true) {
      while (q < (int) I.size()) {
        if (I[q] == P[p]) {
          q++;
          p++;
          break; 
        }
        else {
          q++; 
        }
      }
      if (p == (int) P.size() || q == (int) I.size()) {
        break; 
      }
    }
    if (p == (int) P.size()) {
      cout << (int) I.size() - (int) P.size() << endl; 
    }
    else {
      cout << "IMPOSSIBLE" << endl; 
    }
  }
  return 0; 
}