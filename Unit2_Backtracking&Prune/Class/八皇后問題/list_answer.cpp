#include <iostream>
using namespace std;

const int MAXN = 20;

bool column_has_queen[MAXN];
bool LD_RU_Diagonal[MAXN * 2 + 1];
bool LU_RD_Diagonal[MAXN * 2 + 1];

int n;

void update(int y, int x, bool val) {
  column_has_queen[x] = val;
  LD_RU_Diagonal[y + x] = val;
  LU_RD_Diagonal[n - 1 + (y - x)] = val;
}

bool isValidQueenPosition(int y, int x) {
  if (column_has_queen[x])
    return false;
  if (LD_RU_Diagonal[y + x])
    return false;
  if (LU_RD_Diagonal[n - 1 + (y - x)])
    return false;
  return true;
}


int row[MAXN], m;
void print()
{
  cout << "row = [";
  for(int i = 0; i < n; ++i)
  {
    cout << row[i] << ",]"[i == n-1];
  }
  cout << "\n";
}

int ans;
void dfs(int y) {
  if (y == n) {
    print();
    ans++;
    return;
  }
  for (int x = 0; x < n; ++x) {
    if (!isValidQueenPosition(y, x))
      continue;
    update(y, x, true);
    row[m++] = x;
    dfs(y + 1);
    update(y, x, false);
    --m;
  }
}


int main() 
{
  cin >> n;
  dfs(0);
  cout << "Total number of answers : " << ans;
  return 0;
}

