#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 505; 
struct element {
  int to, fuel, time; 
};

vector <element> adj[MAX_N];
int isGas[MAX_N]; 
int n; 
int m; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> isGas[i]; 
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, fuel, time; 
    cin >> u >> v >> fuel >> time;
    adj[u].push_back((element) {v, fuel, time});
  }
  
  return 0; 
}