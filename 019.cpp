#include <iostream>
#include <cstring>
using namespace std;


/**
 * 思路：dfs
 * 
 */
const int MAX = 100;
const int dx[8]={-1,1,-2,2,-2,2,-1,1};
const int dy[8]={-2,-2,-1,-1,1,1,2,2};
int N, p=0,q=0;
// int nx, ny;
bool visited[100][100] = {0};
bool isSuccess;
struct Step{
    char x;
    char y;
}path[100];

void dfs(int x, int y, int n){
    path[n].x = x + '0';
    path[n].y = y + 'A' -1;
    // cout << path[n].y  << endl;
    
    if(n == p*q){
        isSuccess = true;
        return;
    }
    for(int i = 0; i < 8; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && ny > 0 && nx <= p && ny <= q  && !isSuccess && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx,ny,n+1);
            visited[nx][ny] = false;    //关键，如果失败了就不保存
        }
    }
}

int main(){
    // freopen("in/in019.txt","r",stdin);
    cin >> N;
    for(int i = 1 ; i <= N; i++){
        isSuccess = false;
        cin >> p >> q;
        memset(visited, false, sizeof(visited));
        visited[1][1] = true;
        dfs(1,1,1);

        cout << "Scenario #" << i << ":"<< endl;
        if(isSuccess){
            for(int j = 1;j <= p*q;++j){
                cout << path[j].y << path[j].x;
            }
            cout << endl;
        }else{
            cout << "impossible" << endl;
        }
        cout << endl;
    }
    

    return 0;
}
