#include <bits/stdc++.h> 

using namespace std;
int n; 
int code[1005]; 

int main () {
  cin >> n; 
  for (int i = 1; i <= n; i++) {
    code[i] = i ^ (i >> 1);                   
  }
  int grayAnswer = 0; 
  for (int bit = 0; bit < 10; bit++) {
    vector <int> query; 
    for (int i = 1; i <= n; i++) {
      if ((code[i] & (1 << bit)) > 0) {
        query.push_back(i);   
      }
    }
    cout << (int) query.size() << ' ';
    for (int i = 0; i < (int) query.size(); i++) {
      cout << query[i] << ' '; 
    }
    cout << endl; 
  }
  fflush(stdout);
  for (int bit = 0; bit < 10; bit++) {
    string ans; 
    cin >> ans; 
    if (ans == "POSITIVE") {
      grayAnswer |= (1 << bit); 
    }
  } 
  if (grayAnswer == 0) {
    cout << -1 << endl; 
  }
  else {
    for (int i = 1; i <= n; i++) {
      if (code[i] == grayAnswer) {
        cout << i << endl; 
        break; 
      }
    }
  }
  fflush(stdout);
  return 0; 
}