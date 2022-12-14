#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 19;
string s;
struct node {
  int child[2];
  int winner;
  int numbWinner = 0;
  bool isEnd = true;
};

node Tree[(1 << MAX_N) + 5];
int f[(1 << MAX_N) + 5], father[(1 << MAX_N) + 5];
int n, k, q;

void buildTree(int currentNode) {
  if (Tree[currentNode].isEnd == true) {
    f[currentNode] = Tree[currentNode].numbWinner;
    return;
  }
  int left = Tree[currentNode].child[0];
  int right = Tree[currentNode].child[1];
  buildTree(left);
  buildTree(right); 
  if (Tree[currentNode].winner == 0) {
    f[currentNode] = f[left];
  }
  else if (Tree[currentNode].winner == 1) {
    f[currentNode] = f[right]; 
  }
  else {
    f[currentNode] = f[left] + f[right];
  }
}

void update(int currentNode) {
  if (Tree[currentNode].isEnd == true) {
    if (Tree[currentNode].winner == 2) {
      Tree[currentNode].numbWinner = 2;
    }
    else {
      Tree[currentNode].numbWinner = 1;
    }
    f[currentNode] = Tree[currentNode].numbWinner;
  }
  else {
    int left = Tree[currentNode].child[0];
    int right = Tree[currentNode].child[1];
    if (Tree[currentNode].winner == 2) {
      Tree[currentNode].numbWinner = f[left] + f[right];
    }
    else if (Tree[currentNode].winner == 0) {
      Tree[currentNode].numbWinner = f[left];
    }
    else {
      Tree[currentNode].numbWinner = f[right];
    }
    f[currentNode] = Tree[currentNode].numbWinner;
  }
  if (currentNode == n) {
    return;
  }
  int parent = father[currentNode];
  update(parent);
}

int main () {
  cin >> k;
  cin >> s;
  n = (int) s.size();
  s = "-" + s;
  int currentNode = n;
  int p = n;
  while (currentNode > (1 << (k - 1))) {
    Tree[currentNode].child[1] = p - 1;
    Tree[currentNode].child[0] = p - 2;
    father[p - 1] = currentNode;
    father[p - 2] = currentNode;
    Tree[currentNode].isEnd = false;
    p -= 2;
    currentNode--;
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      Tree[i].winner = 0;
    } 
    else if (s[i] == '1') {
      Tree[i].winner = 1;
    }
    else {
      Tree[i].winner = 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (Tree[i].isEnd == true) {
      if (Tree[i].winner == 0 || Tree[i].winner == 1) {
        Tree[i].numbWinner = 1;
      }
      else {
        Tree[i].numbWinner = 2;
      }
      f[i] = Tree[i].numbWinner;
    }
  }
  buildTree(n);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int pos;
    char c;
    cin >> pos >> c;
    s[pos] = c;
    if (c == '0') {
      Tree[pos].winner = 0;
    }
    if (c == '1') {
      Tree[pos].winner = 1;
    }
    if (c == '?') {
      Tree[pos].winner = 2;
    }
    update(pos);
    cout << f[n] << endl;
  }
  return 0;
}

/*
?110???
*/