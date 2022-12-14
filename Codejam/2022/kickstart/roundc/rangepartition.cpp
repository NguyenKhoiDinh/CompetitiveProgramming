#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
long long X, Y; 
long long N; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> N >> X >> Y;
    long long total = N * (N + 1) / 2; 
    if ((total * X) % (X + Y) != 0) {
      cout << "IMPOSSIBLE"; 
    }
    else {
      cout << "POSSIBLE" << endl; 
      long long half = (total * X) / (X + Y); 
      vector <int> ans; 
      for (int i = N; i >= 1; i--) {
        if (half >= i) {
          ans.push_back(i); 
          half -= i; 
        }
      }
      cout << (int) ans.size() << endl; 
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << ' '; 
      }
      cout << endl; 
    }
  }          
  return 0; 
}