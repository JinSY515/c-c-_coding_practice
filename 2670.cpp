#include <iostream>
using namespace std;
double dp[10001];

int max(int a, int b){
  if(a>b) return a;
  else return b;
}
int main(void){
  int n;
  double Max=0;
  scanf("%d",&n);
  int i;
  scanf("%lf",&dp[0]);
  for(i=1; i<n; i++){
    scanf("%lf",&dp[i]);
    if(dp[i]<=dp[i-1]*dp[i]){
      dp[i]=dp[i-1]*dp[i];
    }
    Max=max(dp[i],Max);
    //그냥 max함수로 if절 안에 집어넣어 버리면 다시 처음부터 최댓값을 구해야 함.
    //따라서 바로 max함수를 쓰지 않고 입력과 동시에 처리를 하면서 최댓값도 동시에 구해줌.
  }
  printf("%.3lf",Max);
  return 0;
}