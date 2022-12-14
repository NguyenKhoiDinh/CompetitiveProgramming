#include <bits/stdc++.h> 

using namespace std;
int p;
long long n; 
bool mark[10000007];

int main () {                        
  cin >> p >> n;
  int cnt = 1;
  int cur = 0;
  mark[0] = true; 
  for (long long i = 1; i <= n; i++) {
    cur += i;
    cur %= p; 
    if (mark[cur] == false) {
      mark[cur] = true;
      cnt++;
    }
    if (cnt == p || i > 3 * p) {
      break;
    }
  }
  cout << cnt;
  return 0; 
}