#include <bits/stdc++.h> 

using namespace std;

vector <int> a; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int test; 
  cin >> test;
  int x = 0; 
  for (int i = 1; i <= 1000000; i++) {
    if (i % 3 == 0 || (i % 10 == 3)) {
      continue; 
    }
    a.push_back(i);
    if ((int) a.size() == 1000) {
      break; 
    }
  }
  for (int tt = 1; tt <= test; tt++) {
    int k; 
    cin >> k; 
    cout << a[k - 1] << endl;
  }
  return 0; 
}