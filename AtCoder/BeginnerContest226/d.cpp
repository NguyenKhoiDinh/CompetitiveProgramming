#include <bits/stdc++.h> 

using namespace std;
set <pair <int, int> > S; 
int n; 
int a[505];
int b[505]; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i]; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }
      int da = a[j] - a[i];
      int db = b[j] - b[i]; 
      int gcd = __gcd(abs(da), abs(db)); 
      da /= gcd;
      db /= gcd; 
      S.insert(make_pair(da, db)); 
    }
  }
  cout << (int) S.size(); 
  return 0; 
}