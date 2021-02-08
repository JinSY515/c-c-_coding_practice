#include <iostream>
int n,m;
int map[501][501];
int visited[501][501]={0};
bool inRange(int nx, int ny){
  return (0<=nx && nx<n && 0<=ny && ny<m);
}

int maxcnt=0;
int drawing=0;

int max(int a, int b){
  if(a>b) return a;
  else return b;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void dfs(int x, int y){
  visited[x][y]=1;
  
  for(int i=0;i<4; i++){
    int nx=x+dx[i];
    int ny=y+dy[i];

    if(!visited[nx][ny] && inRange(nx,ny) && map[nx][ny]==1){
      
      dfs(nx,ny);
      drawing++;
    }

    maxcnt=max(maxcnt,drawing);
  }
}

int main(void){

  scanf("%d %d",&n,&m);
  int i,j;
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      scanf("%d",&map[i][j]);
    }
  }
  int cnt=0;
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      if(!visited[i][j] && map[i][j]==1){
        cnt++;
        drawing=1;
        dfs(i,j);
      }
    }
  }

  printf("%d\n%d",cnt,maxcnt);
  return 0;
}