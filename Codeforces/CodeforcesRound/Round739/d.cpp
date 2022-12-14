#include <bits/stdc++.h> 

using namespace std;

vector <string> a; 

string convert(long long N) {
  string res = "";
  while (N > 0) {
    int r = N % 10;
    N /= 10;
    res += (char) (r + '0');  
  }
  reverse(res.begin(), res.end());
  return res;
}   

int main () {
  for (long long i = 0; i <= 62; i++) {
    a.push_back(convert(1LL << i)); 
  }
  int test;
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    string s;
    cin >> s;
    int ans = 1000000007;
    for (int i = 0; i < (int) a.size(); i++) {
      string st = a[i];
      ans = min(ans, (int) s.size() + (int) st.size());
      for (int j = 0; j < (int) st.size(); j++) {
        int p = 0;
        int numb = 0;
        for (int k = 0; k <= j; k++) {
          while (p < (int) s.size() && s[p] != st[k]) {
            p++; 
          }
          if (p < (int) s.size()) {
            numb++;
            p++; 
          }                                  
        }    
        if (numb == j + 1) {
          ans = min(ans, (int) s.size() + (int) st.size() - 2 * (j + 1));   
        }
      }
    }
    cout << ans << endl;
  }
  return 0; 
}
             
