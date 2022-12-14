#include <bits/stdc++.h> 

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b;
    cin >> a >> b;
    set <int> S;
    int half = (a + b + 1) / 2;
    for (int i = 0; i <= min(a, b); i++) {
      S.insert(abs(half - a) + 2 * i);
      S.insert(abs(half - b) + 2 * i);
    }                       
    cout << (int) S.size() << endl;
    for (set <int> :: iterator it = S.begin(); it != S.end(); it++) {
      cout << *it << ' ';
    }
    cout << endl; 
  }
  return 0; 
}