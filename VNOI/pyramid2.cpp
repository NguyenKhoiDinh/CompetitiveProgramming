/*
<>><>><
*/

#include <iostream>
#include <string> 

using namespace std;

int n;
string s; 

int main () {
  cin >> n;
  cin >> s; 
  long long ans = 0; 
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '>') {
      cnt++; 
    }
    else {
      ans = cnt;
    }
  }
  cout << ans;
  return 0; 
}

>><<

1: ><><
2: <><>
3: <<>>