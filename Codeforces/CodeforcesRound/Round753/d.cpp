#include <bits/stdc++.h> 

using namespace std;
int numTest;
int a[200005]; 
int n; 
string s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    cin >> s;
    vector <int> red, blue; 
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == 'R') {
        red.push_back(a[i]); 
      }
      else {
        blue.push_back(a[i]); 
      }
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int cur = 0;
    bool found = true; 
    for (int i = 0; i < (int) blue.size(); i++) {
      cur++; 
      if (blue[i] < cur) {
        found = false;
        break; 
      }
    }
    for (int i = 0; i < (int) red.size(); i++) {
      cur++; 
      if (red[i] > cur) {
        found = false;
        break; 
      }
    }
    cout << (found == true ? "YES" : "NO") << endl;
  }
  return 0; 
}