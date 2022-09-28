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

//把位於grid[r][c]的num更新為用過或沒用過 
void update(int r, int c, int num) {
  row[r] ^= num;
  col[c] ^= num;
  subgrids[r / 3][c / 3] ^= num;
}

int lowbit(int x) { return (x & -x); }

const int MASK = (1 << 10) - 2;
bool dfs(int idx) {
  if (idx == 81) return true;

  int r = idx / 9, c = idx % 9;
  if (grid[r][c]) return dfs(idx + 1);

  // S: 可用的數字集合，若第k bit是1 代表數字k可以用, k = 0~9 
  int S = MASK & ~(row[r] | col[c] | subgrids[r / 3][c / 3]);

  //枚舉有1的部分，且只用0-9bit中是1的bit的次數，例如S = 0b1100011000，就只會跑4次
  for (int num = 0; S; S ^= num) {
    num = lowbit(S);
    
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