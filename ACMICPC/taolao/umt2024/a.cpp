#include <iostream> 
#include <math.h>
char a[1000005], b[1000005]; 
int cnta[256], cntb[256]; 
int main () {
  int n; 
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnta[a[i]]++; 
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    cntb[b[i]]++; 
  }
  int ans = 0;
  int value = std::min(cntb['R'], cnta['P']); 
  ans += value; 
  cntb['R'] -= value; 
  cnta['P'] -= value; 
  value = std::min(cntb['S'], cnta['R']); 
  ans += value; 
  cntb['S'] -= value; 
  cnta['R'] -= value; 
  value = std::min(cntb['P'], cnta['S']); 
  ans += value; 
  cntb['P'] -= value; 
  cnta['S'] -= value;
  value = std::min(cnta['R'], cntb['R']);
  cnta['R'] -= value;
  cntb['R'] -= value;
  value = std::min(cnta['S'], cntb['S']);
  cnta['S'] -= value;
  cntb['S'] -= value;
  value = std::min(cnta['P'], cntb['P']);
  cnta['P'] -= value;
  cntb['P'] -= value;
  value = std::min(cnta['R'], cntb['P']);
  ans -= value;
  cnta['R'] -= value;
  cntb['P'] -= value;
  value = std::min(cnta['S'], cntb['R']);
  ans -= value;
  cnta['S'] -= value;
  cntb['R'] -= value;
  value = std::min(cnta['P'], cntb['S']);
  ans -= value;
  cnta['P'] -= value;
  cntb['S'] -= value;
  std::cout << std::abs(ans);                                      
  return 0; 
}