#include <iostream> 
#include <map>
#include <string> 
#include <set> 
#include <deque> 
#include <utility> 
int n, k; 
std::deque <std::pair <std::string, std::string> > cache;
std::map <std::string, std::multiset <std::string> > IP; 
std::map <std::string, std::string> lastIP; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    int type;
    std::cin >> type;
    if (type == 1) {
      std::string domain, ip; 
      std::cin >> domain >> ip; 
      lastIP[domain] = ip;  
    }  
    else {
      std::string domain; 
      std::cin >> domain; 
      std::map <std::string, std::string>::iterator it = lastIP.find(domain); 
      if (it != lastIP.end()) {
        if (IP[domain].empty() == false) {
          std::multiset <std::string>::iterator itBegin, itEnd; 
          itBegin = IP[domain].begin(); 
          itEnd = IP[domain].end(); 
          itEnd--; 
          if (*itBegin != *itEnd) {
            std::cout << "Warning: Possible DNS Poisoning detected!";
            return 0; 
          }
          if (it->second != *itBegin) {
            std::cout << "Warning: Possible DNS Poisoning detected!";
            return 0;    
          }
        }
        if ((int) cache.size() == k) {
          std::pair <std::string, std::string> element = cache.front(); 
          cache.pop_front(); 
          std::string other_domain = element.first; 
          std::string ip = element.second; 
          std::multiset <std::string>::iterator it1 = IP[other_domain].find(ip); 
          if (it1 != IP[other_domain].end()) {
            IP[other_domain].erase(it1); 
          }
        } 
        cache.push_back(std::make_pair(domain, it->second));
        IP[domain].insert(it->second);    
      }
    }
  }
  std::cout << "Everything looks ok!"; 
  return 0; 
}