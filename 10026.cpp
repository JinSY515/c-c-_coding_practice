#include <iostream>
#include <string.h>
using namespace std;
char map[101][101];
int visited[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n;
bool inRange(int ny, int nx){
    return (0<=ny && ny<n && 0<=nx && nx<n);
}
//범위 내인지 bool 함수로 //

void dfs(int x, int y, int isdisease){
    //isdisease는 적록색맹이면 1, 아니면 0으로 표기//
    visited[x][y]=1;
    int i,nx,ny;
    for(i=0; i<4; i++){
        nx=x+dx[i];
        ny=y+dy[i];

        if(inRange(ny,nx) && !visited[nx][ny]){
            if(isdisease==0 && map[x][y]==map[nx][ny]){
                dfs(nx,ny,0);
            }
            else if(isdisease==1){
                if(map[x][y]=='R' || map[x][y]=='G'){
                    if(map[nx][ny]=='R'||map[nx][ny]=='G')
                        dfs(nx,ny,1);
                }
                else if(map[x][y]=='B'&& map[nx][ny]=='B'){
                    dfs(nx,ny,1);
                }
            }
        }
    }
}
int main(void){
    scanf("%d",&n);
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf(" %c",&map[i][j]);
            //여기서 주의할 것, 입력할 때 띄어쓰기 없으면 제대로 입력되지 않음//
        }
    }
    int disease=0;
    int not_disease=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(!visited[i][j]){
                not_disease++;
                dfs(i,j,0);
            }
        }
    }
    //여기는 적록색맹이 아닌 사람의 시각에서//
    memset(visited,0,sizeof(visited));
    //방문기록 초기화//

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(!visited[i][j]){
                disease++;
                dfs(i,j,1);
            }
        }
    }
    //적록색밍인 사람의 시각에서//
    printf("%d %d",not_disease,disease);

    return 0;
}