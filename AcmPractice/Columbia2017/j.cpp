#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 105;
const int MAX_V = 30000000;  
int n, m, q;
int cnt[MAX_V + 5];
vector <int> a; 

int main () {
  cin >> n >> m >> q; 
  for (int i = 1; i <= m; i++) {
    int x; 
    cin >> x;
    x %= MAX_V;
    a.push_back(x); 
  }
  int p = 0; 
  while ((int) a.size() < n) {
    a.push_back((a[p] + a[p + 1]) % MAX_V);
    p++;
  }
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++; 
  }
  a.clear();
  for (int v = 0; v <= MAX_V; v++) {
    while (cnt[v] > 0) {
      a.push_back(v); 
      cnt[v]--; 
    }
  }
  for (int i = 1; i <= q; i++) {
    int position;
    cin >> position; 
    cout << a[position - 1] << endl;
  }
  return 0; 
}