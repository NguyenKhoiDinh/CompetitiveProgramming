#include <iostream> 
#include <math.h> 
#include <queue> 
#include <algorithm> 
#include <vector> 
#include <functional>
#include <stdio.h> 
const long long inf = 1000000000000007LL;  
int n;
std::vector <long long> a; 
long long ans; 
long long solve(const std::vector <long long> &a) {
  long long ret = inf; 
  std::vector <long long> b = a;
  std::vector <bool> suffix(n, false); 
  std::vector <bool> prefix(n, false); 
  std::sort(b.begin(), b.end());
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == b[i]) {
      suffix[i] = true; 
    }
    else {
      break; 
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      prefix[i] = true; 
    }
    else {
      break; 
    }
  }
  std::priority_queue <long long, std::vector <long long>, std::greater <long long> > pq;
  int p = 0;
  long long lastCorrect = -1;  
  for (int i = 0; i < n; i++) {
    long long sum = 0LL; 
    pq.push(a[i]);
    while (pq.empty() == false && pq.top() == b[p]) {
      pq.pop(); 
      p++; 
    }
    if (prefix[i] == false) {
      if (pq.empty() == true) {
        if (lastCorrect == -1) {
          sum += (long long) (i + 1) * (i + 1); 
          lastCorrect = (long long) (i + 1) * (i + 1); 
        }
        else {
          sum += lastCorrect;
        }
      }
      else {
        sum += (long long) (i + 1) * (i + 1); 
        lastCorrect = -1; 
      }
    } 
    if (pq.empty() == false || (p < n && suffix[p] == false)) {
      sum += (long long) (n - p) * (n - p);       
    } 
    ret = std::min(ret, sum); 
  } 
  return ret; 
}

int main () {
  scanf("%d", &n); 
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);  
  }
  ans = solve(a); 
  std::reverse(a.begin(), a.end()); 
  long long lim = inf;
  for (int i = 0; i < n; i++) {
    a[i] = lim - a[i]; 
  } 
  ans = std::min(ans, solve(a)); 
  printf("%lld", ans); 
  return 0; 
}