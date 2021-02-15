#include <iostream>
int N, T;
int max(int a, int b){
  if(a>b) return a;
  else return b;
}
int main(void){
  
  scanf("%d %d",&N,&T);
  int dp[N+1][T+1];
  int K[N];
  int S[N];
  for(int i=0; i<N; i++){
    scanf("%d %d",&K[i],&S[i]);
  }
  for(int i=0; i<N+1; i++){
    for(int j=0; j<T+1; j++){
      if(i==0|| j==0) dp[i][j]=0; //행 혹은 열의 인덱스가 0이라면 0으로 초기화시켜줌
      else if(K[i-1]<=j){
        dp[i][j]=max(S[i-1]+dp[i-1][j-K[i-1]],dp[i-1][j]); 
      }
      else dp[i][j]=dp[i-1][j]; //그렇지 않다면 위 행의 값 그대로 받기
    }
  }
  printf("%d",dp[N][T]);
  return 0;
}