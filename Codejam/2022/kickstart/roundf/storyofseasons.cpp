#include <iostream>
#include <utility>  
#include <math.h> 
#include <algorithm> 
struct seed {
  long long numb, days, cost;
  long long deadline; 
  bool operator < (const seed &other) const {
    return deadline > other.deadline; 
  }
};
int numTest;
int n;
seed a[100005];
long long X, D;  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> D >> n >> X; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].numb >> a[i].days >> a[i].cost; 
      a[i].deadline = D - a[i].days; 
    }
    std::sort(a + 1, a + n + 1); 
    long long lastDays = D;
    long long numbDays = 0LL;
    long long remain = 0LL; 
    long long ans = 0LL; 
    std::priority_queue <std::pair <long long, long long> > pq; 
    for (int i = 1; i <= n; i++) {
      pq.push(std::make_pair(a[i].cost, a[i].numb));
      numbDays += lastDays - a[i].deadline;
      while (!pq.empty()) {
        std::pair <long long, long long> pqTop = pq.top();
        pq.pop();
        long long number = a[i].numb;
        long long cost = a[i].cost;
        if (remain >= number) {
          remain -= number;
          ans += number * cost;
          number = 0; 
        }   
        else {       
          number -= remain; 
          ans += remain * cost;
          remain = 0; 
        }
        long long needDays = number / X;
        long long minDays = std::min(numbDays, needDays); 
        numbDays -= minDays; 
        needDays -= minDays;
        ans += minDays * X * cost;
        number -= minDays * X;

      }   
    }  
  }
  return 0; 
}