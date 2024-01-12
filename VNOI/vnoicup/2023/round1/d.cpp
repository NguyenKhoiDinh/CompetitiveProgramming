#include <iostream> 
#include <string> 
#include <vector>
#include <utility> 
#include <algorithm>
#include <math.h>
int n, k; 
std::string s1, s2;
int cnt1[26], cnt2[26];  
std::vector <std::pair <int, int> > a; 
int cost[100005]; 
long long sum[100005];
long long prefix[100005], suffix[100005];  

long long S(int l, int r) {
  return sum[r] - sum[l] + cost[l]; 
}

bool compare(std::pair <int, int> &a, std::pair <int, int> &b) {
  return S(a.first, a.second) < S(b.first, b.second); 
}

int main () {
  std::cin >> n >> k;
  std::cin >> s1;
  std::cin >> s2; 
  int start = 0; 
  for (int i = 0; i < n; i++) {
    std::cin >> cost[i];
    if (i == 0) {
      sum[0] = cost[0]; 
    } else {
      sum[i] = sum[i - 1] + cost[i]; 
    }
  }
  for (int i = 0; i < n; i++) {
    cnt1[s1[i] - 'a']++;
    cnt2[s2[i] - 'a']++;
    bool check = false; 
    for (int c = 0; c < 26; c++) {
      if (cnt1[c] != cnt2[c]) {
        check = true;
        break; 
      }
    }  
    if (check == false) {
      if (i > start) {
        a.push_back(std::make_pair(start, i)); 
      }
      start = i + 1; 
      for (int c = 0; c < 26; c++) {
        cnt1[c] = 0;
        cnt2[c] = 0; 
      }
    }
  }
  if ((int) a.size() == 0) {
    std::cout << 0;
    return 0; 
  }
  int curL = a[0].first; 
  int curR = a[0].second; 
  std::vector <std::pair <int, int> > save, rest; 
  save.push_back(std::make_pair(curL, curR)); 
  for (int i = 1; i < (int) a.size(); i++) {
    if (a[i].first == curR + 1) {
      curR = a[i].second; 
      save.back().second = curR; 
    }
    else {
      curL = a[i].first;
      curR = a[i].second; 
      save.push_back(std::make_pair(curL, curR)); 
    }  
  }
  for (int i = 0; i < (int) save.size() - 1; i++) {
    if (save[i].second + 1 <= save[i + 1].first - 1) {
      rest.push_back(std::make_pair(save[i].second + 1, save[i + 1].first - 1)); 
    }
  }
  std::sort(rest.begin(), rest.end(), compare);
  long long ans = 0LL; 
  for (int i = 0; i < (int) save.size(); i++) {
    ans += S(save[i].first, save[i].second); 
  }
  if (k < (int) save.size()) { 
    for (int i = 0; i <= (int) rest.size() - k; i++) {
      ans += S(rest[i].first, rest[i].second); 
    }
  }
  std::cout << ans; 
  return 0;   
}