#include <iostream> 
#include <deque> 
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>  
int n, k, x, type; 
int a[200005];
int b[200005];
int nxt[200005];  
int f[200005][30]; 
int pos[200005]; 
int ans[200005];
int v[200005];  
int fw[200005]; 
std::unordered_map <int, std::deque <int> > mydeque; 
void update(int index, int value) {
  for (; index <= 200000; index += index & -index) {
    fw[index] += value; 
  }
}
int get(int index) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int main () {
  scanf("%d %d %d %d", &n, &k, &x, &type);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[i] = i;  
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &b[i]);
  }
  int p1 = 1; 
  int p2 = n - k + 1;
  int p = 1;  
  for (int i = 1; i <= n; i++) {
    if (i == b[p]) {
      nxt[i] = p2;
      p2++;
      p++;   
    }
    else {
      nxt[i] = p1; 
      p1++; 
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i][0] = nxt[i]; 
  }
  for (int j = 1; j <= 29; j++) {
    for (int i = 1; i <= n; i++) {
      int p = f[i][j - 1]; 
      f[i][j] = f[p][j - 1]; 
    }
  }
  for (int j = 29; j >= 0; j--) {
    if ((x & (1 << j)) > 0) {
      for (int i = 1; i <= n; i++) {
        pos[i] = f[pos[i]][j]; 
      }
      x -= (1 << j);   
    } 
  }
  for (int i = 1; i <= n; i++) {
    ans[pos[i]] = a[i];
  }
  if (type == 1) {
    for (int i = 1; i <= n; i++) {
      printf("%d ", ans[i]); 
    }
  }
  else {
    for (int i = 1; i <= n; i++) {
      mydeque[ans[i]].push_back(i); 
    }
    std::vector <int> p(n + 1); 
    for (int i = 1; i <= n; i++) {
      p[mydeque[a[i]].front()] = i;
      mydeque[a[i]].pop_front(); 
    }
    long long ret = 0LL; 
    for (int i = n; i >= 1; i--) {
      ret += get(p[i] - 1);
      update(p[i], 1);    
    }
    printf("%lld", ret % 24102009LL);
  }
  return 0; 
}