#include <bits/stdc++.h>

using namespace std;
int numTest; 
string s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    vector <bool> check(26, false); 
    int n; 
    cin >> n; 
    cin >> s; 
    string st = ""; 
    for (int i = 0; i < n; i++) {
      if (check[s[i] - 'a'] == false) {
        st += s[i]; 
        check[s[i] - 'a'] = true; 
      }
    }
    sort(st.begin(), st.end());
    for (int i = 0; i < n; i++) {
      int sz = (int) st.size(); 
      for (int j = 0; j < sz; j++) {
        if (s[i] == st[j]) {
          s[i] = st[sz - 1 - j]; 
          break;
        }
      }
    }
    cout << s << endl;
  }
  return 0; 
}