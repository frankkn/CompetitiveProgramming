#include <iostream>
#include <string>
#include <vector>
using namespace std;

//上下右左 0123
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int grid[7][7];
int ans;
bool vis[7][7];
string s;

void dfs(int y, int x, int move)
{
  if(move == 48)
  {
    if(y==6 && x==0) ans++;
    return;
  }
  if(y==6 && x==0) return;
  if(vis[y][x])	return;

  vector<bool> cur_vis(4, true);
  //當前位置看四個方向:上0下1右2左3的vis情況
  for(int k = 0; k < 4; ++k)
  {
    if(y+dy[k] >= 0 && y+dy[k] < 7 && x+dx[k] >= 0 && x+dx[k] < 7)
    {
      cur_vis[k] = vis[y+dy[k]][x+dx[k]];
    }
  }
  if(!cur_vis[2] && !cur_vis[3] && cur_vis[0] && cur_vis[1])  return;
  if(!cur_vis[0] && !cur_vis[1] && cur_vis[2] && cur_vis[3])  return;

  if(y-1 >= 0 && x+1 < 7 && vis[y-1][x+1] && !cur_vis[0] && !cur_vis[2])  return;
  if(y+1 < 7 && x+1 < 7 && vis[y+1][x+1] && !cur_vis[1] && !cur_vis[2])  return;
  if(y-1 >= 0 && x-1 >= 0 && vis[y-1][x-1] && !cur_vis[0] && !cur_vis[3]) return;
  if(y+1 < 7 && x-1 >= 0 && vis[y+1][x-1]&& !cur_vis[1] && !cur_vis[3]) return;

  vis[y][x] = true;

  if(s[move] == '?')
  {
    for(int k = 0; k < 4; ++k)
    {
      int newy = y+dy[k];
      int newx = x+dx[k];
      if(newy >= 0 && newy < 7 && newx >= 0 && newx < 7)
      {
      	dfs(newy, newx, move+1);
      }
    }
  }
  else if(s[move] == 'U' && y-1 >= 0)
  {
    dfs(y-1, x, move+1);
  }
  else if(s[move] == 'D' && y+1 < 7)
  {
      dfs(y+1, x, move+1);
  }
  else if(s[move] == 'R' && x+1 < 7)
  {
      dfs(y, x+1, move+1);
  }
  else if(s[move] == 'L' && x-1 >= 0)
  {
    dfs(y, x-1, move+1);
  }
  vis[y][x] = false;
}

int main()
{
  cin >> s;
  dfs(0,0,0);
  cout << ans;
  return 0;
}