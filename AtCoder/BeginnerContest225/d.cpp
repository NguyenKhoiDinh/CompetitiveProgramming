#include <bits/stdc++.h> 

using namespace std;
struct car {
  int head, tail; 
};
car a[100005]; 
int n, numQuery; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> numQuery; 
  for (int i = 1; i <= n; i++) {
    a[i].head = -1;
    a[i].tail = -1; 
  }
  for (int i = 1; i <= numQuery; i++) {
    int type;
    cin >> type;
    if (type == 3) {
      int u;
      cin >> u; 
      while (a[u].head != -1) {
        u = a[u].head; 
      }
      while (a[u].tail != -1) {
        cout << u << ' '; 
        u = a[u].tail; 
      }
      cout << endl; 
    }
    else if (type == 1) {
      int u, v; 
      cin >> u >> v; 
      a[u].tail = v;
      a[v].head = u;
    }
    else {
      int u, v;
      cin >> u >> v; 
      a[u].tail = -1;
      a[v].head = -1; 
    }
  }
  return 0; 
}