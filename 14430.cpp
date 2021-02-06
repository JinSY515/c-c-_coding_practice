#include <iostream>

int dp[301][301];
int map[301][301];
int max(int a, int b){
  if(a>b) return a;
  else return b;
}

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  int i,j;

  for(i=1; i<=n; i++){
    for(j=1; j<=m;j++){
      scanf("%d",&map[i][j]);
    }
  }
  dp[1][1]=map[1][1];

  for(i=1; i<=n; i++){
    for(j=1; j<=m; j++){
      if(i!=1){
        dp[i][j]=max(dp[i][j],dp[i-1][j]+map[i][j]); //첫째 행이 아닐 때
      }
      if(j!=1){
        dp[i][j]=max(dp[i][j],dp[i][j-1]+map[i][j]); //첫째 열이 아닐 때
      }
    }
  }
  printf("%d",dp[n][m]);
  return 0;
}