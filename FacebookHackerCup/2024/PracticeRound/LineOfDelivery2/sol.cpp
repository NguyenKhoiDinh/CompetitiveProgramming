#include <iostream>
#include <vector>  
#include <math.h> 
int n, G, numTest; 
int e[300005];
long long it[4 * 300005];
long long position[300005];  
void update(int index, int L, int R, int position, int value) {
  if (L > position || R < position) {
    return; 
  }
  if (L == R) {
    it[index] += value; 
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value);
  update(2 * index + 1, mid + 1, R, position, value); 
  it[index] = it[2 * index] + it[2 * index + 1]; 
}
long long get(int index, int L, int R, int l, int r) {
  if (L > r || l > R) {
    return 0LL; 
  }
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  long long left = get(2 * index, L, mid, l, r); 
  long long right = get(2 * index + 1, mid + 1, R, l, r); 
  return left + right; 
}
int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cout << std::endl; 
    std::cin >> n >> G; 
    for (int i = 1; i <= n; i++) {
      std::cin >> e[i]; 
    }
    for (int i = 0; i <= 4 * n; i++) {
      it[i] = 0; 
    }
    std::vector <long long> lenEmpty;
    lenEmpty.push_back(1000000000000007LL);
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        lenEmpty[0] -= e[i];
        lenEmpty.push_back(e[i] - 1);
        update(1, 1, n, 1, e[i] - 1);   
      }
      else {
        int lo = 1; 
        int hi = i - 1;
        int minPos = -1;
        while (lo <= hi) {
          int mid = (lo + hi) / 2; 
          if (get(1, 1, n, mid, i - 1) < e[i]) {
            minPos = mid; 
            hi = mid - 1; 
          }
          else {
            lo = mid + 1; 
          }
        }
        if (minPos == -1) {
          update(1, 1, n, i - 1, -e[i]); 
          lenEmpty.back() -= e[i];
          lenEmpty.push_back(e[i] - 1);
          update(1, 1, n, i, e[i] - 1);    
        } 
        else {
          long long add = e[i] - get(1, 1, n, minPos, i - 1);
          std::cout << minPos << "     " << get(1, 1, n, minPos, i - 1) << "          " << add << "       " << e[i] << std::endl;
          update(1, 1, n, i, lenEmpty.back() - 1);  
          lenEmpty.push_back(lenEmpty.back() - 1);
          lenEmpty[minPos - 1] -= add;
          if (minPos > 1) {
            update(1, 1, n, minPos - 1, -add); 
          }                           
          update(1, 1, n, minPos, add - lenEmpty[minPos]);
          lenEmpty[minPos] = add;                  
        }
      }
      for (int j = 1; j < (int) lenEmpty.size(); j++) {
        std::cout << lenEmpty[j] << "    "; 
      }
      std::cout << std::endl;
    }
    position[n] = lenEmpty.back() + 1;
    lenEmpty.pop_back();
    for (int i = n - 1; i >= 1; i--) {
      position[i] = position[i + 1] + lenEmpty.back() + 1; 
      lenEmpty.pop_back(); 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << position[i] << "      "; 
    }
    std::cout << std::endl;
    long long mini = 1000000000000007LL; 
    int ans;  
    for (int i = 1; i <= n; i++) {
      if (mini > std::abs(G - position[i])) {
        mini = std::abs(G - position[i]); 
        ans = i; 
      }
    }
    std::cout << ans << ' ' << mini << std::endl;
    std::cerr << "TEST CASE #" << testCase << " DONE!!!" << std::endl;
  } 
  return 0; 
}