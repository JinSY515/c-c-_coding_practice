#include <iostream>
#define N 1000000007

long long int dp[1001][1001]={0};
int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
 
  int i,j;
  for(i=1; i<=n; i++){
    for(j=1; j<=m; j++){
      if(i==1 && j==1) dp[i][j]=1; //dp[1][1]=1 
      else  //그외
      dp[i][j]=(dp[i-1][j]%N+dp[i][j-1]%N+dp[i-1][j-1]%N)%N;
    }
  }
  printf("%lld",dp[n][m]);
  return 0;
}