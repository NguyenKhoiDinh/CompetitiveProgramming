#include <bits/stdc++.h> 

using namespace std;
set <vector <int> > S; 

int main () {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  vector <int> a(d + 1, 0); 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= d; j++) {
      scanf("%d", &a[j]);  
    }
    S.insert(a); 
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= d; j++) {
      scanf("%d", &a[j]); 
    }
    if (S.find(a) != S.end()) {
      printf("BAD\n"); 
    }
    else {
      printf("GOOD\n");
    }
  }
  return 0; 
}