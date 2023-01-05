#include <iostream> 
#include <set>
#include <utility>
#include <map> 
#include <vector> 
#include <math.h>
int numTest; 
struct seed {
  long long numb, days, cost; 
};
int n;
long long D, X; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> D >> n >> X; 
    std::vector <seed> listSeeds; 
    listSeeds.resize(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> listSeeds[i].numb >> listSeeds[i].days >> listSeeds[i].cost; 
    }
    std::map <long long, std::vector <int> > deadlines; 
    deadlines[0] = std::vector <int>();
    for (int i = 0; i < n; i++) {
      if (D - listSeeds[i].days <= 0) {
        continue; 
      }
      deadlines[D - listSeeds[i].days].push_back(i); 
    }
    std::set <std::pair <long long, int> > have; 
    long long lastDay = D + 1; 
    long long ans = 0LL; 
    for (std::map <long long, std::vector <int> >::reverse_iterator it = deadlines.rbegin(); it != deadlines.rend(); it++) { 
      long long cntSeeds = (lastDay - it->first) * X;
      while (have.empty() == false && cntSeeds > 0) {
        int id = have.begin()->second;
        have.erase(have.begin());
        long long used = std::min(listSeeds[id].numb, cntSeeds); 
        listSeeds[id].numb -= used; 
        cntSeeds -= used; 
        ans += used * listSeeds[id].cost; 
        if (listSeeds[id].numb > 0) {
          have.insert(std::make_pair(-listSeeds[id].cost, id)); 
        }
      }
      std::vector <int> &v = it->second; 
      for (int i = 0; i < (int) v.size(); i++) {
        int id = v[i]; 
        have.insert(std::make_pair(-listSeeds[id].cost, id)); 
      }
      lastDay = it->first; 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}