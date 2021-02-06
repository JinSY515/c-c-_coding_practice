#include <iostream>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int map[501][501];
int dp[501][501];
int n,m;
bool inRange(int nx, int ny){
  return (0<=nx && nx<m && 0<=ny && ny<n);
}
int dfs(int x, int y){
  if(x==0 && y==0) return 1; //(m-1,n-1)점에서 출발, (0,0)에 도착하면 리턴 1

  if(dp[x][y]==-1){  //방문 안했으면 
    dp[x][y]=0;

    for(int i=0; i<4; i++){
      int nx=x+dx[i];
      int ny=y+dy[i];

      if(inRange(nx,ny) && map[x][y]<map[nx][ny]){ //범위 내이고, 다음에 확인할 게 현재 확인한 것 보다 클 때
      //사실상 오르막길로 풀음
        dp[x][y]+=dfs(nx,ny);
      }
    }
  }
  return dp[x][y]; //결론 리턴
}
int main(void){
 
  scanf("%d %d",&m, &n);
  int i,j;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      scanf("%d",&map[i][j]);
      dp[i][j]=-1;
    }
  }

  printf("%d",dfs(m-1,n-1)); //(m-1,n-1)점에서 시작
  return 0;

}