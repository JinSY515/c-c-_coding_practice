#include <iostream>
#define N 1000000000
long long dp[201][201];
int main(void){
  int n,k;
  scanf("%d %d",&n,&k);
  for(int i=0; i<=n; i++){
    dp[1][i]=1;
    //정수1개로 i만드는 경우의 수는 1
  }
  for(int i=2; i<=k; i++){
      //정수 i개로 j만드는 경우의 수 분해//
      //정수 i-1개로 0,1,..j 만드는 경우의 수의 합//
    for(int j=0; j<=n; j++){

      for(int l=0; l<=j; l++){
        dp[i][j]+=dp[i-1][l];
      }
      //0에서 j까지(그 전까지) 더해주기//
      dp[i][j]%=N;
    }
  }

  printf("%lld",dp[k][n]);
  return 0;
}