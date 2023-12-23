#include <bits/stdc++.h>
int numTest; 
vector <int> ans; 
bool haveColor[100005]; 
int a[100005]; 
int n; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    ans.clear(); 
    memset(haveColor, false, sizeof(haveColor)); 
    int lastNumber = -1; 
    bool valid = true; 
    for (int i = 1; i <= n; i++) {
      if (lastNumber == -1) {
        lastNumber = a[i]; 
      }
      else if (lastNumber == a[i]) {
        continue; 
      }
      else if (haveColor[a[i]] == true) {
        valid = false;
        break;   
      }
      haveColor[a[i]] = true;
      ans.push_back(a[i]);  
      lastNumber = a[i];
    }
    if (valid == false) {
      cout << "IMPOSSIBLE" << endl;   
    }
    else {
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << ' ';
      }
      cout << endl;
    }
  }
  return 0; 
}