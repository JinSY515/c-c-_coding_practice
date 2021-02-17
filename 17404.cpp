#include <iostream>
#include <cstring>
int dp[1001][3];
int rgb[1001][3];
int n;

int min(int a, int b){
  if(a<b) return a;
  else return b;
}

int house(int color){
  int result;
  memset(dp,1000001,sizeof(dp));
  dp[0][color]=rgb[0][color]; //처음 집이 각각 빨강, 초록, 파랑일 때로 고정.
  for(int i=1; i<n; i++){
    dp[i][0]=min(dp[i-1][1],dp[i-1][2])+rgb[i][0];
    dp[i][1]=min(dp[i-1][0],dp[i-1][2])+rgb[i][1];
    dp[i][2]=min(dp[i-1][0],dp[i-1][1])+rgb[i][2];
  }
  for(int j=0; j<3; j++){
    if(color!=j){
      result=min(result,dp[n-1][j]);  //처음 집의 색깔과 다르다면
    }
  }
  return result;  //그 중 작은 값을 리턴
}
int main(void){
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
      scanf("%d",&rgb[i][j]);
    }
  }
  int ans=1000000001;  //불가능한 수로 초기화시켜놓음
  for(int i=0; i<3; i++){
    ans=min(ans,house(i)); 
  }
  printf("%d",ans);

  return 0;
}