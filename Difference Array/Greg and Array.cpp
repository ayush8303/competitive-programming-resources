#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main()
{
  int n, m, k;
  cin >> n >> m >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<vector<int>> queries(m, vector<int>(3));
  for (int i = 0; i < m; i++)
  {
    int l, r, val;
    cin >> l >> r >> val;
    l--, r--;
    queries[i] = {l, r, val};
  }
  int queriesPref[m + 1] = {0};
  for (int i = 0; i < k; i++)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    queriesPref[l]++;
    queriesPref[r + 1]--;
  }
  for (int i = 1; i < m; i++)
  {
    queriesPref[i] += queriesPref[i - 1];
  }
  int prefArr[n + 1] = {0};
  for (int i = 0; i < m; i++)
  {
    int l = queries[i][0], r = queries[i][1];
    int val = queries[i][2];
    int cnt = val * queriesPref[i];
    prefArr[l] += cnt;
    prefArr[r + 1] -= cnt;
  }
  for (int i = 1; i < n; i++)
  {
    prefArr[i] += prefArr[i - 1];
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] + prefArr[i] << ' ';
  }

  return 0;
}