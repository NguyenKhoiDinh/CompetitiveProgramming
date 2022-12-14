#include <bits/stdc++.h> 

using namespace std;
int numTest;
int father[200005];
int ans[200005]; 
long long dist[200005]; 
int n; 
int p[200005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> father[i];
      if (i == father[i]) {
        father[i] = 0; 
      }
      dist[i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      cin >> p[i]; 
    }
    set <int> S; 
    S.insert(0);
    dist[0] = 0;  
    long long maxSum = -1;
    bool found = true;   
    for (int i = 1; i <= n; i++) {
      int vertex = p[i];
      if (S.find(father[vertex]) == S.end()) {
        cout << -1 << endl; 
        found = false;
        break; 
      }
      S.insert(vertex);
      ans[vertex] = maxSum + 1 - dist[father[vertex]];
      dist[vertex] = maxSum + 1;
      maxSum++;    
    }
    if (found == true) {
      for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' '; 
      }
      cout << endl; 
    }            
  }
  return 0; 
}