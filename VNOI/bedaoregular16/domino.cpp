#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> 
int n; 
int a[100005];
int b[100005]; 
std::vector <int> domino[6]; 
int dp[6][2005]; 
std::vector <int> v[6];
std::pair <int, int> trace[6][2005];  
int ans[6]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    int maxi = std::max(a[i], b[i]);
    int mini = std::min(a[i], b[i]); 
    if (maxi - mini > 0) {
      domino[maxi - mini].push_back(i);  
    }
  }
  for (int numb = 1; numb <= 5; numb++) {
    int total = (int) domino[numb].size();
    if (total == 0) {
      continue; 
    }
    for (int x = 0; x <= total; x++) {
      if ((total - x) % 2 == 0 && numb * x <= 100) {
        v[numb].push_back(-numb * x);
        v[numb].push_back(numb * x);     
      }
    }  
  }
  dp[0][1000] = 1; 
  for (int i = 0; i < 5; i++) {
    for (int diff = 0; diff <= 2000; diff++) {
      if (dp[i][diff] == 0) {
        continue; 
      }
      if (v[i + 1].empty() == true) {
        dp[i + 1][diff] = 1; 
        trace[i + 1][diff] = std::make_pair(i, diff);
      }
      for (int j = 0; j < (int) v[i + 1].size(); j++) {
        dp[i + 1][diff + v[i + 1][j]] = 1;
        trace[i + 1][diff + v[i + 1][j]] = std::make_pair(i, diff);   
      }
    }
  }
  int ansDiff = -1;
  int minDiff = 2023;  
  for (int diff = 0; diff <= 2000; diff++) {
    if (dp[5][diff] == 0) {
      continue; 
    }
    if (minDiff > std::abs(diff - 1000)) {
      minDiff = std::abs(diff - 1000);
      ansDiff = diff;    
    } 
  }
  std::cout << minDiff << std::endl;
  int p = 5; 
  while (p > 0) {
    if (v[p].empty()) {
      ans[p] = 1000000007;
    }
    else {
      ans[p] = ansDiff - trace[p][ansDiff].second;
    } 
    ansDiff = trace[p][ansDiff].second; 
    p--; 
  }                               
  std::vector <int> ret; 
  for (int i = 1; i <= 5; i++) {
    if (ans[i] == 1000000007) {
      continue; 
    }    
    int pos = 0;
    int neg = 0; 
    if (ans[i] < 0) {
      neg = ans[i] / (-i); 
    }
    else {
      pos = ans[i] / i; 
    }
    int total = (int) domino[i].size();
    total -= neg + pos;
    neg += total / 2;
    pos += total / 2;
    for (int j = 0; j < (int) domino[i].size(); j++) {
      int id = domino[i][j];
      if (a[id] > b[id]) {
        if (pos > 0) {
          pos--; 
        }
        else {
          ret.push_back(id);
          neg--; 
        }
      }
      else {
        if (neg > 0) {
          neg--; 
        }
        else {
          ret.push_back(id);
          pos--; 
        }
      } 
    } 
  }
  std::cout << (int) ret.size() << ' ';
  for (int i = 0; i < (int) ret.size(); i++) {
    std::cout << ret[i] << ' ';
  }
  return 0;
}