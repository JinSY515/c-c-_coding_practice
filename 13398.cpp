#include <iostream>
using namespace std;

int dp[100001][2]={0};
int arr[100001];

int max(int a, int b){
  if(a>b) return a;
  else return b;
}
int main(void){
  int n;
  scanf("%d",&n);
  int Max1=0;
  int i;
  for(i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }

  dp[0][0]=dp[0][1]=Max1=arr[0]; //여기에서 초기화하는 과정에서 오류가 여럿 났음.
  for(i=1; i<n; i++){
    dp[i][0]=max(0,dp[i-1][0])+arr[i];
    dp[i][1]=max(dp[i-1][1]+arr[i],dp[i-1][0]);
    //i번째 수를 포함한(제외하지 않은) 값과 i번째 수를 제외한 값 중 최댓값
    Max1=max(Max1,max(dp[i][1],dp[i][0]));
  }

  printf("%d",Max1);

  return 0;
}