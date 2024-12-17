#include <bits/stdc++.h>

using namespace std;
int x[100005];
int n, numQueries; 
map <long long, long long> f; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQueries; 
    for (int i = 1; i <= n; i++) {
      cin >> x[i]; 
    }
    f.clear(); 
    for (int i = 1; i < n; i++) {
      f[(long long) i * (n - i)] += x[i + 1] - x[i] - 1; 
    }
    for (int i = 1; i <= n; i++) {
      f[(long long) i * (n - i + 1) - 1]++; 
    }
    for (int query = 1; query <= numQueries; query++) {
      long long k;
      cin >> k; 
      cout << f[k] << ' '; 
    }
    cout << endl;
  }
  return 0; 
}