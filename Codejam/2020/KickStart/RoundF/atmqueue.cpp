#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005; 
int numTest;
pair <int, int> a[MAX_N]; 
int n, X; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> X;
    for (int i = 1; i <= n; i++) {
      int money;
      cin >> money;
      a[i].first = (money + X - 1) / X; 
      a[i].second = i; 
    }
    sort(a + 1, a + n + 1); 
    for (int i = 1; i <= n; i++) {
      cout << a[i].second << ' '; 
    }
    cout << endl; 
  }
  return 0;
}