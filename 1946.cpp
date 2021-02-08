#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
  int t;
  int n;
  int i;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    pair<int,int> grade[n];
    for(i=0; i<n; i++){
      scanf("%d %d",&grade[i].first,&grade[i].second);
    }
    sort(grade,grade + n);
    
    int a=grade[0].first;
    int b=grade[0].second;
    int cnt=1;

    for(i=1; i<n; i++){
      if(grade[i].first >a && grade[i].second<b){
        cnt++;
        a=grade[i].first;
        b=grade[i].second;
      }
    }
    printf("%d\n",cnt);

  }
  return 0;
}

/*
  A 3 2
  B 1 4
  C 4 1
  D 2 3
  E 5 5
  를 서류 점수를 기준으로 정렬하면

  B 1 4
  D 2 3
  A 3 2
  C 4 1
  E 5 5
  이다. 

  a=1 (grade[0].fisrt), b=4 (grade[0].second)
  
  서류 점수를 기준으로 정렬했기 때문에 면접 점수를 기준으로 비교하면 된다.

  D의 서류점수는 B의 서류점수보다 낮지만 면접점수가 높다, 따라서 cnt++를 해준다.
  이제 B의 점수를 기준으로 삼는다.

  위의 과정을 반복한다.
*/