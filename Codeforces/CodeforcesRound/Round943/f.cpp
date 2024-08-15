#include <iostream>
#include <map>
#include <vector> 
 
using namespace std;
int numTest; 
int n, numQueries;
int sum[200005];                       
 
int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQueries;
    sum[0] = 0; 
    for (int i = 1; i <= n; i++) {
      int x; 
      std::cin >> x;
      sum[i] = sum[i - 1] ^ x; 
    }
    std::map <int, std::vector <int> > position;
    for (int i = 0; i <= n; i++) {
      position[sum[i]].push_back(i); 
    } 
    for (int query = 1; query <= numQueries; query++) {
      int l, r;
      std::cin >> l >> r;
      if (sum[r] == sum[l - 1]) {
        std::cout << "YES" << endl;
        continue; 
      } 
      std::vector <int> &vR = position[sum[r]]; 
      int lo = 0; 
      int hi = (int) vR.size() - 1;
      int minLeft = -1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (vR[mid] + 1 >= r) {
          hi = mid - 1; 
        }
        else if (vR[mid] + 1 > l) {
          minLeft = vR[mid] + 1; 
          hi = mid - 1; 
        }
        else {
          lo = mid + 1; 
        }
      }                                 
      std::vector <int> &vL = position[sum[l - 1]]; 
      lo = 0;
      hi = (int) vL.size() - 1; 
      int maxRight = -1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (vL[mid] <= l) {
          lo = mid + 1;                            
        }
        else if (vL[mid] < r) {
          maxRight = vL[mid]; 
          lo = mid + 1; 
        }
        else {
          hi = mid - 1; 
        }
      }                  
      if (minLeft != -1 && maxRight != -1 && maxRight >= minLeft) {
        std::cout << "YES" << std::endl; 
      }
      else {
        std::cout << "NO" << std::endl;
      }
    }
    std::cout << std::endl;
  }
  return 0; 
}