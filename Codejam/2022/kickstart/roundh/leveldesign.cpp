#include <iostream> 
#include <math.h>
#include <deque>
#include <math.h>
#include <vector>    
#include <utility>
#include <algorithm> 
const int inf = 10000007; 
int numTest; 
struct item {
  int len; 
  int value; 
};
int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::vector <int> p; 
    int n; 
    std::cin >> n;
    p.resize(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> p[i];
      p[i]--; 
    }
    std::vector <std::pair <int, int> > listCycles; 
    std::vector <bool> checkPosition;
    std::vector <int> countLengthCycle;
    countLengthCycle.resize(n + 1, 0); 
    checkPosition.resize(n, false);
    int maxLengthCycle = -1;  
    for (int i = 0; i < n; i++) {
      if (checkPosition[i] == false) {
        int position = i; 
        int lengthCycle = 0; 
        do {
          checkPosition[position] = true; 
          lengthCycle++;
          position = p[position];   
        }
        while (checkPosition[position] == false);                
        maxLengthCycle = std::max(maxLengthCycle, lengthCycle);  
        countLengthCycle[lengthCycle]++;
      }                                
    }
    for (int i = 1; i <= n; i++) {
      if (countLengthCycle[i] > 0) {
        listCycles.push_back(std::make_pair(i, countLengthCycle[i])); 
      }
    }
    std::vector <item> listItems; 
    for (int i = 0; i < (int) listCycles.size(); i++) {
      std::pair <int, int> element = listCycles[i];
      int number = element.second; 
      int lengthCycle = element.first; 
      int p = 1; 
      while (number >= p) {
        listItems.push_back((item) {lengthCycle * p, p});
        number -= p;
        p *= 2;   
      }
      if (number > 0) {
        listItems.push_back((item) {lengthCycle * number, number});
      }
    }
    int numbItems = (int) listItems.size();
    std::vector <std::vector <int> > dp; 
    dp.resize(numbItems + 1); 
    for (int i = 0; i <= numbItems; i++) {
      dp[i].resize(n + 1, inf); 
    }
    dp[0][0] = 0; 
    for (int i = 0; i < numbItems; i++) {
      for (int j = 0; j <= n; j++) {
        if (dp[i][j] == inf) {
          continue; 
        }
        dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
        if (j + listItems[i].len <= n) {
          dp[i + 1][j + listItems[i].len] = std::min(dp[i + 1][j + listItems[i].len], dp[i][j] + listItems[i].value); 
        } 
      }
    }
    std::vector <int> ans;
    ans.resize(n); 
    int minValue = inf + 5; 
    for (int j = n; j >= 1; j--) {
      ans[j - 1] = std::min(dp[numbItems][j], minValue + 1) - 1;
      minValue = std::min(minValue, dp[numbItems][j]);  
    }
    for (int j = 0; j < n; j++) {
      std::cout << ans[j] << ' '; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}