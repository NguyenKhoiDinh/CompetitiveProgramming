#include <bits/stdc++.h>

using namespace std;
int numTest; 

string ask(int value) {
  cout << value << endl; 
  fflush(stdout); 
  string res;
  cin >> res; 
  return res;
}

int main () {
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    //cout << "Case #" << testCase << ": ";
    int L, R;
    cin >> L >> R; 
    int n;
    cin >> n;
    L++;
    while (L <= R) {
      int mid = (L + R) >> 1;
      string answer = ask(mid);
      if (answer == "CORRECT") {
        break;
      }
      else if (answer == "TOO_BIG") {
        R = mid - 1; 
      }
      else {
        L = mid + 1; 
      }
    }
  }
  return 0; 
}