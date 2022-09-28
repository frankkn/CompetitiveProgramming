#include <iostream>
#include <cstring> // for memset
#include <string>

using namespace std;

int grid[9][9];
//bool row[9][10], col[9][10];
//bool subgrids[3][3][10];
int row[9];
int col[9];
int subgrids[3][3];


void input() {
  for (int r = 0; r < 9; ++r) {
    string buffer;
    cin >> buffer;
    for (int c = 0; c < 9; ++c) {
      if (isdigit(buffer[c]))
        grid[r][c] = 1 << (buffer[c] - '0');
      else
        grid[r][c] = 0;
    }
  }
}

void print() {
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c)
      cout << __lg(grid[r][c]);
    cout << '\n';
  }
}

//判斷位於grid[r][c]的num有沒有用過
bool illegal(int r, int c, int num) {
  return (row[r] | col[c] | subgrids[r / 3][c / 3]) & num;
}

//把位於grid[r][c]的num更新為用過或沒用過 
void update(int r, int c, int num) {
  row[r] ^= num;
  col[c] ^= num;
  subgrids[r / 3][c / 3] ^= num;
}

bool check() {
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      if (grid[r][c] == 0) continue;
      if (illegal(r, c, grid[r][c]))
        return false;
      update(r, c, grid[r][c]);
    }
  }
  return true;
}

bool dfs(int idx) {
  if (idx == 81) return true;

  int r = idx / 9, c = idx % 9;
  if (grid[r][c]) return dfs(idx + 1);

  for (int num = (1 << 1); num <= (1 << 9); num <<= 1) {
    if(illegal(r, c, num)) continue;
    grid[r][c] = num;
    update(r, c, num);
    if (dfs(idx + 1)) return true;
    update(r, c, num);
  }
  grid[r][c] = 0;
  return false;
}

int main() {
  input();
  if (dfs(0))
    print();
  else
    cout << "No answer\n";
  return 0;
}

