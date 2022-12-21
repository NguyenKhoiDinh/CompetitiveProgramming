#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
const int inf = 100005; 
std::string pattern;
std::string rev_pattern;
std::vector <int> dp;
std::vector <long long> hash, rev_hash, power27;
int n, numQuery; 
struct element {
  int numSegments; 
  std::vector <int> listSegments; 
};
std::vector <element> listElement; 
std::set <int> listLength;
std::vector <int> listPosition[10005];  

void init() {
  hash.resize(n + 2, 0LL);
  rev_hash.resize(n + 2, 0LL);
  power27.resize(n + 2, 0LL);
  power27[0] = 1LL; 
  for (int i = 1; i <= n; i++) {
    power27[i] = power27[i - 1] * 27LL; 
    hash[i] = hash[i - 1] * 27LL + (pattern[i - 1] - 'a' + 1); 
    rev_hash[i] = rev_hash[i - 1] * 27LL + (rev_pattern[i - 1] - 'a' + 1); 
  }
} 

long long getHash(int l, int r, const std::vector <long long> &hash) {
  int len = r - l + 1;
  long long ret = hash[r];
  ret -= (hash[l - 1] * power27[len]);
  return ret;  
}

bool checkPalindrome(int l, int r) {
  long long currentHash = getHash(l, r, hash); 
  long long reverseHash = getHash(n - r + 1, n - l + 1, rev_hash); 
  return (currentHash == reverseHash); 
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> pattern; 
  rev_pattern = pattern; 
  std::reverse(rev_pattern.begin(), rev_pattern.end()); 
  n = (int) pattern.size(); 
  init(); 
  std::cin >> numQuery;
  for (int query = 0; query < numQuery; query++) {
    int numSegments;
    std::cin >> numSegments;
    std::vector <int> listSegments; 
    listSegments.resize(numSegments);
    for (int i = 0; i < numSegments; i++) {
      std::cin >> listSegments[i];
      listLength.insert(listSegments[i]);  
    }
    listElement.push_back((element) {numSegments, listSegments}); 
  }
  for (std::set <int>::iterator it = listLength.begin(); it != listLength.end(); it++) {
    int len = *it; 
    for (int i = 1; i + len - 1 <= n; i++) {
      if (checkPalindrome(i, i + len - 1) == true) {
        listPosition[len].push_back(i); 
      }
    }
  }
  for (int query = 0; query < numQuery; query++) {
    element currentElement = listElement[query];
    int numSegments = currentElement.numSegments;
    std::vector <int> &listSegments = currentElement.listSegments;
    dp.clear();
    dp.resize(1 << numSegments);
    for (int mask = 0; mask < (1 << numSegments); mask++) {
      dp[mask] = inf; 
    }  
    dp[0] = 0; 
    for (int mask = 0; mask < (1 << numSegments); mask++) {
      if (dp[mask] == inf) {
        continue; 
      }
      for (int i = 0; i < numSegments; i++) {
        if ((mask & (1 << i)) == 0) {
          int len = listSegments[i];
          int lo = 0; 
          int hi = (int) listPosition[len].size() - 1; 
          int pos = -1; 
          while (lo <= hi) {
            int mid = (lo + hi) / 2; 
            if (listPosition[len][mid] > dp[mask]) {
              pos = listPosition[len][mid];
              hi = mid - 1; 
            }
            else {
              lo = mid + 1; 
            }
          }
          if (pos != -1) {
            dp[mask | (1 << i)] = std::min(dp[mask | (1 << i)], pos + len - 1);
          }
        }
      }
    }
    if (dp[(1 << numSegments) - 1] <= n) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}