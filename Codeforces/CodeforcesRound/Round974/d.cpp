#include <iostream> 
#include <math.h> 
int numTest; 
int n, d, k; 
int start[100005], end[100005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> d >> k;
    for (int i = 1; i <= n; i++) {
      start[i] = 0;
      end[i] = 0;
    }             
    for (int i = 1; i <= k; i++) {
      int l, r;
      std::cin >> l >> r;
      start[l]++;
      end[r]++; 
    }
    int l = 1; 
    int r = d;
    int ansMax = -1; 
    int ansMin = k + 10;
    int startMax = -1;
    int startMin = -1;  
    int numbJobs = 0; 
    for (int i = l; i <= r; i++) {
      numbJobs += start[i];  
    }
    ansMax = ansMin = numbJobs;
    startMax = startMin = 1;
    while (r < n) {
      r++; 
      numbJobs += start[r]; 
      numbJobs -= end[l]; 
      l++;
      if (ansMax < numbJobs) {
        ansMax = numbJobs; 
        startMax = l;
      } 
      if (ansMin > numbJobs) {
        ansMin = numbJobs; 
        startMin = l; 
      }
    } 
    std::cout << startMax << ' ' << startMin << std::endl;
  }
  return 0; 
}