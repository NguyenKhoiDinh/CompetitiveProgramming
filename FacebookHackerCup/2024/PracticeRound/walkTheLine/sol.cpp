#include <iostream> 
#include <math.h> 
#include <algorithm> 
int numTest;
long long K;  
int n; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> K; 
    long long mini = 1000000007; 
    for (int i = 1; i <= n; i++) {
      long long S;
      std::cin >> S;
      mini = std::min(mini, S);  
    }
    long long ans; 
    if (n == 1) {
      ans = mini;  
    }
    else {
      ans = mini * 2 * (n - 2) + mini; 
    }
    std::cout << (ans <= K ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}