#include <iostream> 
#include <string> 
#include <set>
int numTest;   
long long prefix[300005], suffix[300005]; 
int n, m; 
long long power[300005]; 
long long sum[300005]; 
std::string s; 
int cnt[300005]; 

int main () {
  power[0] = 1LL; 
  sum[0] = 0LL; 
  for (int i = 1; i <= 300000; i++) {
    power[i] = power[i - 1] * 41LL; 
    sum[i] = sum[i - 1] + power[i]; 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    std::cin >> s; 
    prefix[0] = 0LL;
    cnt[0] = 0;  
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1]; 
      cnt[i] = cnt[i - 1];
      if (s[i - 1] == '1') {
        prefix[i] += power[i];
        cnt[i]++;  
      }
    }
    suffix[n + 1] = 0LL;
    for (int i = n; i >= 1; i--) {
      suffix[i] = suffix[i + 1]; 
      if (s[i - 1] == '1') {
        suffix[i] += power[i]; 
      }
    }
    std::set <long long> S; 
    for (int i = 1; i <= m; i++) {
      int l, r;
      std::cin >> l >> r;
      int numb = cnt[r] - cnt[l - 1]; 
      int last = r; 
      int first = last - numb + 1; 
      long long totalHash = 0LL; 
      totalHash += prefix[l - 1]; 
      totalHash += suffix[r + 1]; 
      totalHash += sum[last] - sum[first - 1]; 
      S.insert(totalHash); 
    }
    std::cout << (int) S.size() << std::endl;
  }
  return 0; 
}