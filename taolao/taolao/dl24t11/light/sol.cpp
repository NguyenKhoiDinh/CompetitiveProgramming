#include <bits/stdc++.h> 

using namespace std;           
int n, m, numQueries;
map <pair <int, int>, int> id;  
vector <bitset <100000> > mybit; 
bitset <100000> total; 

int main () {
  cin >> n >> m >> numQueries; 
  mybit.resize(n); 
  for (int i = 0; i < m; i++) {
    int u, v, c; 
    cin >> u >> v >> c;
    u--;
    v--; 
    if (u > v) {
      swap(u, v); 
    }
    if (c == 1) {
      total.set(i, 1); 
    }
    mybit[u].set(i, 1);
    mybit[v].set(i, 1); 
  } 
  for (int query = 1; query <= numQueries; query++) {
    int u;
    cin >> u;
    u--;
    total ^= mybit[u];
    cout << total.count() << ' ';    
  }
  return 0; 
}