#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
const int inf = 10000005;
int dp[MAX_N];

int calculateCost(const string &considerString, const string &word) {
  vector <int> freq;
  freq.resize(26, 0);
  for (int i = 0; i < (int) considerString.size(); i++) {
    freq[considerString[i] - 'a']++;
  }
  for (int i = 0; i < (int) word.size(); i++) {
    freq[word[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (freq[i] != 0) {
      return -1;
    }
  }
  int ans = 0;
  for (int i = 0; i < (int) considerString.size(); i++) {
    ans += considerString[i] != word[i];
  }
  return ans;
}

class SentenceDecomposition {
  public:
  int decompose(string sentence, vector <string> validWords) {
    int n = (int) sentence.size();
    for (int i = 1; i <= n; i++) {
      dp[i] = inf;
    }
    for (int i = 0; i < n; i++) {
      if (dp[i] == inf) {
        continue;
      }
      string considerString = "";
      for (int j = i; j < n; j++) {
        considerString += sentence[j];
        for (int k = 0; k < (int) validWords.size(); k++) {
          int cost = calculateCost(considerString, validWords[k]);
          if (cost != -1) {
            dp[j + 1] = min(dp[j + 1], dp[i] + cost);
          }
        }
      }
    }
    return (dp[n] == inf ? -1 : dp[n]);
  }
};

int main () {
  return 0;
}