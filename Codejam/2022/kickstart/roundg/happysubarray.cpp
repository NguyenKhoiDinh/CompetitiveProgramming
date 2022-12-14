#include <iostream> 
#include <stack> 
const int inf = -400000007; 
int numTest; 
int a[400005]; 
int sum[400005];
long long sum_sum[400005]; 
int nextPos[400005]; 
int n; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      sum[i] = sum[i - 1] + a[i]; 
      sum_sum[i] = sum_sum[i - 1] + sum[i]; 
    }
    sum[n + 1] = inf; 
    std::stack <int> st;
    st.push(n + 1);
    for (int i = n; i >= 0; i--) {
      while (!st.empty()) {
        int index = st.top(); 
        if (sum[index] >= sum[i]) {
          st.pop(); 
        }
        else {
          break; 
        }            
      }
      int index = st.top();
      nextPos[i] = index; 
      st.push(i); 
    } 
    long long ans = 0LL;
    for (int i = 0; i <= n - 1; i++) {
      int j = nextPos[i];
      ans += sum_sum[j - 1] - sum_sum[i] - 1LL * (j - i - 1) * sum[i]; 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}