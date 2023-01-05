#include <iostream> 
#include <vector>
#include <map>
#include <cstring> 
#include <math.h>
int numTest; 
int n, k, X, D; 
std::vector <int> startLeads[100005], endLeads[100005]; 

void update(std::vector <int> &fw, int index, const int &value) { 
  for (; index <= 100001; index += index & -index) {
    fw[index] += value; 
  }
}

int get(const std::vector <int> &fw, int index) {
  int ret = 0; 
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> k >> X >> D; 
    std::vector <int> fwPeoples, fwMeetings; 
    std::vector <int> cntPeoples; 
    fwPeoples.resize(100005, 0);   
    fwMeetings.resize(100005, 0); 
    cntPeoples.resize(n + 1, 0); 
    for (int i = 0; i <= D; i++) {
      startLeads[i].clear();
      endLeads[i].clear(); 
    }
    int numbMeetings; 
    std::cin >> numbMeetings; 
    for (int i = 1; i <= numbMeetings; i++) {
      int id, L, R;
      std::cin >> id >> L >> R; 
      startLeads[L].push_back(id);
      endLeads[R].push_back(id);
    }
    for (int i = 0; i < X; i++) {
      for (int j = 0; j < (int) startLeads[i].size(); j++) {
        int id = startLeads[i][j]; 
        cntPeoples[id]++; 
      }                           
    }
    for (int i = 1; i <= n; i++) {
      update(fwPeoples, cntPeoples[i] + 1, 1);
      update(fwMeetings, cntPeoples[i] + 1, cntPeoples[i]);  
    }
    int L = 0; 
    int R = X;
    int ans = numbMeetings + 10;  
    while (R <= D) {
      int lo = 0;
      int hi = numbMeetings;
      int len = -1;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int numbPeoples = get(fwPeoples, mid + 1);
        if (numbPeoples >= k) {
          hi = mid - 1; 
        }  
        else {
          len = mid; 
          lo = mid + 1; 
        }
      }
      int numbMeetings = get(fwMeetings, len + 1); 
      int numbPeoples = get(fwPeoples, len + 1); 
      numbMeetings += (k - numbPeoples) * (len + 1); 
      ans = std::min(ans, numbMeetings); 
      L++; 
      for (int i = 0; i < (int) endLeads[L].size(); i++) {
        int id = endLeads[L][i]; 
        update(fwPeoples, cntPeoples[id] + 1, -1);
        update(fwMeetings, cntPeoples[id] + 1, -cntPeoples[id]);
        cntPeoples[id]--; 
        update(fwPeoples, cntPeoples[id] + 1, 1);
        update(fwMeetings, cntPeoples[id] + 1, cntPeoples[id]);
      }
      for (int i = 0; i < (int) startLeads[R].size(); i++) {
        int id = startLeads[R][i]; 
        update(fwPeoples, cntPeoples[id] + 1, -1);
        update(fwMeetings, cntPeoples[id] + 1, -cntPeoples[id]);
        cntPeoples[id]++; 
        update(fwPeoples, cntPeoples[id] + 1, 1);
        update(fwMeetings, cntPeoples[id] + 1, cntPeoples[id]);
      }
      R++; 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}