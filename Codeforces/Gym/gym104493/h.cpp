#include <iostream>
#include <set>
#include <utility>
#include <queue> 
int a[100005]; 
int n, numTest, numQueries; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::set <std::pair <int, long long> > S; 
    std::priority_queue <long long> pq, pq2; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      S.insert(std::make_pair(i, a[i])); 
      pq.push(a[i]); 
    }
    std::cout << pq.top() << std::endl;  
    std::cin >> numQueries; 
    for (int query = 1; query <= numQueries; query++) {
      int section;
      std::cin >> section; 
      std::pair <int, long long> pr = std::make_pair(section, -1); 
      std::set <std::pair <int, long long> >::iterator it = S.upper_bound(pr);
      std::pair <int, long long> found = *it;
      long long fishes = found.second;
      S.erase(it);
      pq2.push(fishes); 
      it = S.upper_bound(found);
      pr = *it;
      pq2.push(pr.second); 
      pr.second += fishes;
      S.erase(it);
      S.insert(pr);
      pq.push(pr.second); 
      while (pq2.empty() == false && pq.top() == pq2.top()) {
        pq.pop();
        pq2.pop(); 
      }    
      std::cout << pq.top() << std::endl;
    }
  }
  return 0; 
}