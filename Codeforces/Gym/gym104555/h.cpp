#include <stdio.h>
#include <math.h>
#include <set> 
#include <vector>
#include <algorithm>
#include <utility>
long long f[1000005]; 
long long l[1000005], r[1000005], cost[1000005];
int n;
long long S;  
struct element {
  int p;
  bool operator < (const element &other) const {
    if (f[p] - l[p] * S == f[other.p] - l[other.p] * S) {
      return p < other.p;
    }
    return (f[p] - l[p] * S > f[other.p] - l[other.p] * S); 
  }  
};
long long ans = 0LL;
std::vector <std::pair <long long, int> > events;
std::set <element> opt;   

int main () {
  scanf("%d %lld", &n, &S); 
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld %lld", &l[i], &r[i], &cost[i]); 
    events.push_back(std::make_pair(l[i], -i)); 
    events.push_back(std::make_pair(r[i], i)); 
  }
  std::sort(events.begin(), events.end());
  for (int i = 0; i < (int) events.size(); i++) {
    std::pair <long long, int> e = events[i]; 
    int id = e.second; 
    long long pos = e.first; 
    if (id > 0) {  // this is end 
      ans = std::max(ans, f[id] + (long long) (pos - l[id] + 1) * S); 
      opt.erase((element) {id}); 
    }
    else { // this is open
      long long best = 0LL; 
      if (opt.empty() == false) {
        std::set <element>::iterator it = opt.begin(); 
        element x = *it; 
        best = f[x.p] + (long long) (pos - l[x.p]) * S; 
      }                                                            
      f[-id] = std::max(best, ans) - cost[-id];
      opt.insert((element) {-id}); 
    }
  } 
  printf("%lld", ans); 
  return 0; 
}