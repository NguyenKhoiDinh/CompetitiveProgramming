#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 500005; 
int n; 
struct element {
  long long a, b, c;
};
long long maxi[MAX_N];
element save[MAX_N];
long long sum[MAX_N];

int main () {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld %lld", &save[i].a, &save[i].b, &save[i].c);
    maxi[i] = max(save[i].a, max(save[i].b, save[i].c));
    sum[i] = save[i].a + save[i].b + save[i].c - maxi[i];
  }
  sort(sum + 1, sum + n + 1);
  for (int i = 1; i <= n; i++) {
    int lo = 1; 
    int hi = n;
    long long value = save[i].a + save[i].b + save[i].c - 2;
    int pos = upper_bound(sum + 1, sum + n + 1, value) - sum;
    pos--;
    if (maxi[i] >= 2) {
      pos--;
    }
    printf("%d ", pos);
  }
  return 0; 
}