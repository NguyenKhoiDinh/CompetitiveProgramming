#include <iostream> 
#include <vector> 
#include <math.h>
#include <stdio.h>
int t[300005];
long long a[300005];
long long tmp[300005];  
int n, k; 
std::vector <int> listPos[300005]; 
struct itnode {
  long long maxLeft, maxRight, sum, maxSum;   
};
itnode it[4 * 300005]; 
long long ans = -1; 

itnode mergeNode(const itnode &nodeLeft, const itnode &nodeRight) {
  itnode ret; 
  ret.sum = nodeLeft.sum + nodeRight.sum; 
  ret.maxLeft = std::max(nodeLeft.maxLeft, nodeLeft.sum + nodeRight.maxLeft);
  ret.maxRight = std::max(nodeRight.maxRight, nodeRight.sum + nodeLeft.maxRight);
  ret.maxSum = std::max(nodeLeft.maxRight + nodeRight.maxLeft, std::max(nodeLeft.maxSum, nodeRight.maxSum)); 
  return ret; 
}

void update(int index, int L, int R, int position, const long long &value) {
  if (position < L || position > R) {
    return; 
  }
  if (L == R) {
    it[index] = (itnode) {value, value, value, value};
    return;  
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value); 
  update(2 * index + 1, mid + 1, R, position, value); 
  it[index] = mergeNode(it[2 * index], it[2 * index + 1]);
}

int main () {
  scanf("%d %d", &n, &k); 
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    listPos[t[i]].push_back(i); 
  }   
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    update(1, 1, n, i, a[i]);
  }
  for (int type = 1; type <= k; type++) {
    std::vector <int> &pos = listPos[type];
    for (int i = 0; i < (int) pos.size(); i++) {
      update(1, 1, n, pos[i], -a[pos[i]]); 
      tmp[pos[i]] = -1LL * (k - 1) * a[pos[i]];
      update(1, 1, n, pos[i], tmp[pos[i]]);  
    }  
    ans = std::max(ans, it[1].maxSum); 
    for (int i = 0; i < (int) pos.size(); i++) {
      update(1, 1, n, pos[i], -tmp[pos[i]]);
      update(1, 1, n, pos[i], a[pos[i]]);  
    }
  } 
  printf("%lld", ans); 
  return 0; 
}