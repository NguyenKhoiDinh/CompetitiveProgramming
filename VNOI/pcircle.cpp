#include <bits/stdc++.h>

using namespace std;
int n; 
vector <vector <int> > res; 
vector <int> per; 

bool isPrime(int p) {
  if (p == 2) {
    return true; 
  }
  for (int i = 2; i <= (int) sqrt(p); i++) {
    if (p % i == 0) {
      return false; 
    }
  }
  return true; 
}

int main () {
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    per.push_back(i);
  }
  do {
    if (per[0] != 1) {
      break;
    } 
    bool flag = true; 
    for (int i = 0; i < 2 * n; i++) {
      if (isPrime(per[i] + per[(i + 1) % (2 * n)]) == false) {
        flag = false; 
        break; 
      }
    }
    if (flag == true) {
      res.push_back(per);
    }
  }
  while (next_permutation(per.begin(), per.end()));
  cout << (int) res.size() << endl; 
  for (int i = 0; i < (int) res.size(); i++) {
    for (int j = 0; j < 2 * n; j++) {
      cout << res[i][j] << ' ';
    }
    cout << endl;
  }
  return 0; 
}