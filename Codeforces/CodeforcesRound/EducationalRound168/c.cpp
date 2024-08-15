#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    stack <int> st;
    int ans = 0; 
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '_') {
        if (st.empty() == false) {
          ans += i - st.top();
          st.pop();   
        }
        else {
          st.push(i); 
        }
      }
      else if (s[i] == '(') {
        st.push(i); 
      }
      else {
        ans += i - st.top(); 
        st.pop(); 
      }
    }  
    cout << ans << endl;
  }
  return 0; 
}