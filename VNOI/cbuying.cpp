#include <bits/stdc++.h>

using namespace std;

map <long long, long long> M;

int main () {
  int n; 
  long long B; 
  scanf("%d %lld", &n, &B);
  for (int i = 1; i <= n; i++) {
    long long price; 
    long long numb; 
    scanf("%lld %lld", &price, &numb);
    M[price] += numb;
  }
  long long ans = 0; 
  for (map <long long, long long> :: iterator it = M.begin(); it != M.end(); it++) {
    long long cnt = min(B / it->first, (long long) it->second); 
    ans += cnt; 
    B -= cnt * it->first; 
  }
  printf("%lld", ans);
  return 0; 
}