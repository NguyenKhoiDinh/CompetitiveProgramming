#include <bits/stdc++.h>

using namespace std;
int numTest; 
string s; 
int n; 

int main () {
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    cin >> s; 
    int l = 0; 
    int r = (n + 1) / 2; 
    r--; 
    int sum = 0;
    for (int i = l; i <= r; i++) {
      sum += s[i] - '0';
    }
    int ans = sum; 
    while (r < n) {
      sum -= s[l] - '0';
      l++;
      r++;
      sum += s[r] - '0'; 
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
  return 0; 
}