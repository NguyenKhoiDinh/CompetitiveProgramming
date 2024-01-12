#include <iostream>
#include <math.h> 
#include <vector> 
#include <utility>
int numTest; 
std::vector <std::pair <int, int> > listPrime; 
std::vector <int> ans;
std::vector <int> save; 
int minGroup, maxSum, N;

void backTrack(int total, int value, int mul, std::vector <int> &ans, std::vector <int> &save) {
  if (mul == N) {
    if (maxSum < total || (maxSum == total && minGroup > (int) save.size())) {
      maxSum = total;
      minGroup = (int) save.size();                            
      ans = save;
      return; 
    }
  }
  for (int i = 0; i < (int) listPrime.size(); i++) {
    if (listPrime[i].second > 0) {
      if (total + value * listPrime[i].first <= 41) {
        listPrime[i].second--;
        backTrack(total, value * listPrime[i].first, mul * listPrime[i].first, ans, save);
        save.push_back(value * listPrime[i].first); 
        backTrack(total + value * listPrime[i].first, 1, mul * listPrime[i].first, ans, save);
        save.pop_back();  
        listPrime[i].second++; 
      }  
    }
  }
} 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::vector <int> ans; 
    int P;
    std::cin >> P;
    N = P; 
    listPrime.clear(); 
    ans.clear();
    minGroup = 1000; 
    maxSum = 0;
    for (int i = 2; i <= 40000; i++) {
      int cnt = 0;
      bool ok = false;  
      while (P % i == 0) {
        ok = true;
        P /= i;
        cnt++;    
      }
      if (ok == true) {
        listPrime.push_back(std::make_pair(i, cnt)); 
      }
    }
    if (P > 1) {
      listPrime.push_back(std::make_pair(P, 1)); 
    }
    backTrack(0, 1, 1, ans, save);                        
    if (minGroup == 1000) {
      std::cout << -1 << std::endl;
    }
    else {
      int sum = 0;
      for (int i = 0; i < (int) ans.size(); i++) {
        sum += ans[i];
      }
      while (sum < 41) {
        ans.push_back(1); 
        sum++;
      }
      std::cout << (int) ans.size() << ' ';
      for (int i = 0; i < (int) ans.size(); i++) {
        std::cout << ans[i] << ' ';
      }
      std::cout << std::endl; 
    }
    std::cerr << "Case #" << testCase << ": DONE" << std::endl;
  } 
  return 0; 
}