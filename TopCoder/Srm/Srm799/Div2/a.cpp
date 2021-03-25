#include <bits/stdc++.h>

using namespace std;

class CoolPairsEasy {
  public:
  int count(vector <string> firstname, vector <string> lastname) {
    int n = (int) firstname.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          if (lastname[i] == firstname[j]) {
            res++;
          }
        }
      }
    }
    return res;
  }
};

int main () {
  return 0;
}