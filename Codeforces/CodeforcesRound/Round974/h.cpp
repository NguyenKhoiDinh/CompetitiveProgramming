#include <iostream> 
#include <math.h> 
#include <algorithm> 
#include <vector>
const int BLOCK = 450; 
int numTest; 
struct question {
  int l, r, id;
  bool operator < (const question &other) {
    if (l / BLOCK != other.l / BLOCK) {
      return l < other.l; 
    }  
    return r < other.r; 
  } 
};
bool ans[200005]; 
int n, numQueries;
int a[200005];
int cnt[1000005];
std::vector <question> listQuery;   

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQueries; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      cnt[a[i]] = 0; 
    }
    listQuery.clear(); 
    for (int query = 1; query <= numQueries; query++) {
      int l, r;
      std::cin >> l >> r; 
      listQuery.push_back((question) {l, r, query}); 
    }
    std::sort(listQuery.begin(), listQuery.end());
    int numbOdd = 0;
    int L = listQuery[0].l;
    int R = listQuery[0].r;
    int id = listQuery[0].id;
    for (int i = L; i <= R; i++) {
      cnt[a[i]] ^= 1;
      if (cnt[a[i]] == 1) {
        numbOdd++; 
      } 
      else {
        numbOdd--; 
      }
    }
    ans[id] = numbOdd == 0;
    for (int i = 1; i < (int) listQuery.size(); i++) {
      int l = listQuery[i].l;
      int r = listQuery[i].r; 
      int id = listQuery[i].id;
      while (L < l) {
        cnt[a[L]] ^= 1;
        if (cnt[a[L]] == 1) {
          numbOdd++; 
        } 
        else {
          numbOdd--; 
        }
        L++; 
      } 
      while (L > l) {
        L--; 
        cnt[a[L]] ^= 1;
        if (cnt[a[L]] == 1) {
          numbOdd++; 
        } 
        else {
          numbOdd--; 
        }
      }
      while (R > r) {
        cnt[a[R]] ^= 1;
        if (cnt[a[R]] == 1) {
          numbOdd++; 
        } 
        else {
          numbOdd--; 
        }
        R--; 
      }
      while (R < r) {
        R++; 
        cnt[a[R]] ^= 1;
        if (cnt[a[R]] == 1) {
          numbOdd++; 
        } 
        else {
          numbOdd--; 
        } 
      }
      ans[id] = numbOdd == 0; 
    }  
    for (int i = 1; i <= numQueries; i++) {
      std::cout << (ans[i] == true ? "YES" : "NO") << std::endl;
    }
  }
  return 0; 
}