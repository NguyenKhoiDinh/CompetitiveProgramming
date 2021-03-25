
import java.util.*;

class UnsatisfyingAN {
  static boolean[][] reachable = new boolean[4096][4096];
  static int[][] adj = new int[4096][4096];
  static final int SHIFT = 2048;

  static void dfs(int start, int cur) {
    reachable[start][cur] = true;
    for (int i = 1; i <= adj[cur][0]; i++) {
      if (!reachable[start][adj[cur][i]]) dfs(start, adj[cur][i]);
    }
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int m = s.nextInt();

    for (int i = 0; i < m; i++) {
      int a = s.nextInt();
      int b = s.nextInt();
      adj[SHIFT - a][++adj[SHIFT - a][0]] = SHIFT + b;
      adj[SHIFT - b][++adj[SHIFT - b][0]] = SHIFT + a;
    }

    for (int i = 1; i <= n; i++) {
      dfs(SHIFT + i, SHIFT + i);
      dfs(SHIFT - i, SHIFT - i);
    }

    int best = 3;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (reachable[SHIFT + i][SHIFT - j]) {
          if (i == j) {
            System.out.println(reachable[SHIFT - i][SHIFT + i]);
            best = Math.min(best, reachable[SHIFT - i][SHIFT + i] ? 0 : 1);
          } else {
           best = Math.min(best, reachable[SHIFT + i][SHIFT + j] ? 1 : 2);
          }
        }
      }
    }
    if (best == 3) best = -1;
    System.out.println(best);
  }
}