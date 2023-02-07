#include <iostream>
#include <string>
using namespace std;

int grid[9][9];

void input() {
  for (int r = 0; r < 9; ++r) {
    string buffer;
    cin >> buffer;
    for (int c = 0; c < 9; ++c) {
      grid[r][c] = buffer[c] - '0';
    }
  }
}

bool row[9][10], col[9][10];
bool subgrids[3][3][10];

//判斷位於grid[r][c]的num有沒有用過
bool illegal(int r, int c, int num) {
  return row[r][num] || col[c][num] || subgrids[r / 3][c / 3][num];
}

//把位於grid[r][c]的num更新為用過或沒用過 
void update(int r, int c, int num, bool val) {
  row[r][num] = val;
  col[c][num] = val;
  subgrids[r / 3][c / 3][num] = val;
}

bool check() {
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      if (grid[r][c] == 0) continue; // 伏筆
      if (illegal(r, c, grid[r][c]))
        return false;
      update(r, c, grid[r][c], true);
    }
  }
  return true;
}

int main() {
  input();
  cout << (check() ? "Yes\n" : "No\n");
  return 0;
}
