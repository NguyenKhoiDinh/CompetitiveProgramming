#include <bits/stdc++.h>

using namespace std;
int deg[100005]; 
int n; 
string s; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      deg[i] = 0; 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      deg[u]++;
      deg[v]++; 
    }
    int totalMark = 0; 
    cin >> s; 
    for (int i = 0; i < n; i++) {
      totalMark += s[i] == '?'; 
    }
    int numb0 = 0, numb1 = 0, numbM = 0;
    for (int i = 2; i <= n; i++) {
      if (deg[i] == 1) {
        if (s[i - 1] == '0') {
          numb0++; 
        }
        else if (s[i - 1] == '1') {
          numb1++; 
        }
        else {
          numbM++; 
        }
      }
    }
    int ans = 0; 
    if (s[0] == '?') {
      ans = max(numb0, numb1); 
      ans += numbM / 2;
      if ((totalMark - 1 - numbM) % 2 == 1) {
        int other = (numbM + 1) / 2;
        other += min(numb0, numb1);
        ans = max(ans, other);  
      }   
    }
    else {
      if (s[0] == '0') {
        ans += numb1; 
      }
      else {
        ans += numb0; 
      }
      ans += (numbM + 1) / 2;
    }
    cout << ans << endl; 
  }
  return 0;                           
}
