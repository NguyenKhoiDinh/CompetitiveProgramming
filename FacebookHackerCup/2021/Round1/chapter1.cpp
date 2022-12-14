#include <bits/stdc++.h> 

using namespace std;

int numTest;
string s;

int calc(int side) {
  int ret = 0;
  for (int i = 1; i < (int) s.size(); i++) {
    if (s[i] == 'O' && side == 0) {
      side = 1;
      ret++;
    }  
    else if (s[i] == 'X' && side == 1) {
      side = 0;
      ret++; 
    }
  }
  return ret;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    int n;
    cin >> n;
    cin >> s;
    int ans = 1000000006; 
    if (s[0] == 'F' || s[0] == 'X') {
      ans = min(ans, calc(0));
    }
    if (s[0] == 'F' || s[0] == 'O') {
      ans = min(ans, calc(1));
    }
    cout << ans << endl;
  }
  return 0; 
}