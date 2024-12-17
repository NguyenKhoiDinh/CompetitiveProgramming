#include <bits/stdc++.h> 

using namespace std;
struct dog {
  int weight, intelligence, cost; 
  bool operator < (const dog &other) {
    return (weight < other.weight || (weight == other.weight && intelligence < other.intelligence)); 
  }
};
int f[10005]; 
dog a[10005]; 
int n; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].weight >> a[i].intelligence >> a[i].cost; 
  }
  sort(a + 1, a + n + 1); 
  f[1] = a[1].cost;
  for (int i = 2; i <= n; i++) {
    f[i] = a[i].cost;
    for (int j = i - 1; j >= 1; j--) {
      if (a[j].intelligence <= a[i].intelligence) {
        f[i] = max(f[i], f[j] + a[i].cost); 
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[i]); 
  }
  cout << ans; 
  return 0; 
}
               
