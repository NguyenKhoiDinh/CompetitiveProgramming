#include <iostream> 
#include <math.h> 
#include <vector> 
#include <algorithm>
#include <deque> 
#include <utility> 
int numTest; 
int milk[2000005];
std::vector <int> days;  

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m, k;
    std::cin >> n >> m >> k; 
    days.clear(); 
    for (int i = 1; i <= n; i++) {
      int d, a; 
      std::cin >> d >> a; 
      milk[d] = a; 
      days.push_back(d); 
      days.push_back(d + k); 
    }
    std::sort(days.begin(), days.end());
    days.push_back(1000000000);        
    long long totalMilk = 0LL; 
    std::deque <std::pair <int, int> > dq;
    long long ans = 0LL; 
    for (int i = 0; i < (int) days.size() - 1; i++) {
      while (dq.empty() == false && dq.front().first + k <= days[i]) {
        totalMilk -= dq.front().second; 
        dq.pop_front(); 
      }
      if (milk[days[i]] > 0) {                                           
        totalMilk += milk[days[i]]; 
        dq.push_back(std::make_pair(days[i], milk[days[i]]));
        milk[days[i]] = 0;      
      }
      int numbAvailable = days[i + 1] - days[i];
      while (dq.empty() == false && numbAvailable > 0 && totalMilk >= m) {
        int need = dq.back().second / m;                                                      
        if (need > numbAvailable) {                                 
          dq.back().second -= numbAvailable * m;
          totalMilk -= numbAvailable * m; 
          ans += numbAvailable; 
          numbAvailable = 0; 
        }    
        else {
          totalMilk -= need * m; 
          dq.back().second -= need * m;
          numbAvailable -= need;
          if (dq.back().second == 0) {
            dq.pop_back(); 
          }    
          ans += need; 
          if (dq.empty() == false && numbAvailable > 0 && totalMilk >= m) {
            numbAvailable--; 
            ans++; 
            int pint = m;
            while (dq.empty() == false) {     
              if (dq.back().second < pint) {
                pint -= dq.back().second;
                totalMilk -= dq.back().second; 
                dq.back().second = 0;  
              }
              else {
                totalMilk -= pint; 
                dq.back().second -= pint; 
                pint = 0;
              }                   
              if (dq.back().second == 0) {
                dq.pop_back(); 
              }
              if (pint == 0) {                   
                break;
              }
            }     
          } 
        }
      }
      if (totalMilk < m && numbAvailable > 0 && dq.empty() == false) {
        while (dq.empty() == false) {
          if (dq.back().second < totalMilk) {
            totalMilk -= dq.back().second;
            dq.back().second = 0;  
          }  
          else {
            dq.back().second -= totalMilk; 
            totalMilk = 0; 
          }
          if (dq.back().second == 0) {
            dq.pop_back(); 
          }
          if (totalMilk == 0) {
            break; 
          }
        }
      }  
    }
    std::cout << ans << std::endl;        
  }
  return 0; 
}