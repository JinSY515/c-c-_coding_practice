#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp{
  bool operator()(int a, int b){
    return a>b;
  }
};

vector<pair<int,int>> v;
priority_queue<int,vector<int>,cmp> q; //우선순위 큐

int main(void){
  int n;
  scanf("%d",&n);
  int i;
  int s,t;
  for(i=0; i<n; i++){
    scanf("%d %d",&s,&t);
    v.push_back({s,t}); //벡터 페어
  }
  sort(v.begin(),v.end()); //시작 시간 기준으로 정렬

  q.push(v[0].second); 
  for(i=1; i<n; i++){
    if(q.top()<=v[i].first){  //큐의 탑에 있는 값이 다음 시작 시간보다 작으면
      q.pop();  //그 이전 값을 pop
      q.push(v[i].second); //새로운 값 푸시
    }
    else{
      q.push(v[i].second); //다음 시작 시간보다 크면, 팝하지 않음
    }
  }
  printf("%lu",q.size());  //큐에 남아있는 개수 
  return 0;
}