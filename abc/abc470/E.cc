// https://atcoder.jp/contests/abc470/tasks/abc470_e
// -probability
// 关键1：对任意策略 E[分数] = (ΣA_i/N)·E[配对数]，故只需最大化期望配对数
// 关键2：最优策略是"有配就收、没配翻未知牌"，状态仅由 (life, 未知对数, 单翻对数) 决定
// dp[life][c0][c1]：生命 life，c0 个未知对，c1 个单翻对时，之后能拿到的期望配对数

#include <iomanip>
#include <iostream>

using namespace std;
constexpr int maxn = 205;
int n, L;
double dp[maxn][maxn][maxn];

void solve() {
  cin >> n >> L;
  double sum = 0;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    sum += a;
  }

  // 边界：c0 = 0 时所有配对位置已知，一对接一对白拿，不耗命
  for (int life = 1; life <= L; life++)
    for (int c1 = 0; c1 <= n; c1++)
      dp[life][0][c1] = c1;

  // 每步转移都使 s = life + c0 + c1 严格递减，故按 s 升序即可拓扑
  for (int s = 0; s <= L + n; s++)
    for (int life = 1; life <= L; life++)
      for (int c0 = 0; c0 <= n; c0++) {
        int c1 = s - life - c0;
        if (c1 < 0 || c1 > n || c0 + c1 > n)
          continue;
        int tot = 2 * c0 + c1; // 回合开始时面朝下的牌数
        if (tot == 0) {
          dp[life][c0][c1] = 0;
          continue;
        }
        double &f = dp[life][c0][c1];
        // ① 第一张的配对是某张已翻的单牌：概率 c1/tot，第二张直接拿它
        if (c1 > 0)
          f = (double)c1 / tot * (1 + dp[life][c0][c1 - 1]);
        else
          f = 0;
        // ②③④ 第一张来自未知对，配对还面朝下：概率 2c0/tot
        if (c0 > 0) {
          double p = (double)2 * c0 / tot;
          int rest = tot - 1; // 第一张翻完后剩余的面朝下的牌数
          // ② 第二张正好是第一张的配对：概率 1/rest
          f += p / rest * (1 + dp[life][c0 - 1][c1]);
          // ③ 第二张来自另一个未知对：概率 (2c0-2)/rest，生命 -1
          if (c0 >= 2)
            f += p * (double)(2 * c0 - 2) / rest * dp[life - 1][c0 - 2][c1 + 2];
          // ④ 第二张是某张已翻单牌的配对：概率 c1/rest，生命还剩则下回合白拿
          if (c1 > 0)
            f += p * (double)c1 / rest *
                 (life >= 2 ? 1 + dp[life - 1][c0 - 1][c1] : 0);
        }
      }

  double x = dp[L][n][0]; // 初始：N 个未知对，无单翻对
  cout << fixed << setprecision(12) << x * sum / n << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
