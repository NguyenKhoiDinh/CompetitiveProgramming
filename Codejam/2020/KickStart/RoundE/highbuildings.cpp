#include <bits/stdc++.h>

using namespace std;
int numTest;
const int MAX_N = 105; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    if (A + B - C > N || (N >= 2 && A + B - C == 1)) {
      cout << "IMPOSSIBLE" << endl; 
      continue; 
    }
    if (N == 1) {
      cout << "1" << endl; 
      continue; 
    }
    if (N == 2) {
      if (C == 2) {
        cout << "1 1" << endl; 
      }
      else if (A == 2) {
        cout << "1 2" << endl; 
      }
      else if (B == 2) {
        cout << "2 1" << endl; 
      }
      continue; 
    }
    vector <int> res; 
    for (int i = 0; i < A - C; i++) {
      res.push_back(2);
    }
    for (int i = 0; i < C; i++) {
      res.push_back(3); 
    }
    for (int i = 0; i < B - C; i++) {
      res.push_back(2); 
    }
    int more = N - (A + B - C); 
    res.insert(res.begin() + 1, more, 1); 
    for (int i = 0; i < N; i++) {
      cout << res[i] << ' '; 
    }
    cout << endl; 
  }
  return 0;
}