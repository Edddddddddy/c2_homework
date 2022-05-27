#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


bool a[6][6], visited[6][6];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct node{
    int x,y;
    int xx,yy;
    int step;
}st, path[6][6];

queue<node> q;

void printPath(int i, int j){
    if(path[i][j].xx != 0 || path[i][j].yy != 0){
        printPath(path[i][j].xx, path[i][j].yy);
    }else{
        cout << "(0, 0)" << endl;
    }
    cout << "(" << i << ", " << j << ")" << endl;
}

int main(){
    // freopen("in/in022.txt","r",stdin);
    
    memset(path, 0, sizeof(path));

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cin >> a[i][j];
            path[i][j].step = 99;
        }
    }
    
    memset(visited,0,sizeof(visited));
    // memset(a,0,sizeof(a));
    
    st.x = 0;
    st.y = 0;

    q.push(st);

    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        visited[tmp.x][tmp.y] = 1;
        if(tmp.x == 4 && tmp.y == 4)break;
        
        node tmp2;
        for(int i = 0; i < 4; ++i){
            tmp2.x = tmp.x+dir[i][0];
            tmp2.y = tmp.y+dir[i][1];
            tmp2.step = tmp.step+1;
            
            if(tmp2.x >= 0 && tmp2.x <= 4 && tmp2.y>= 0 && tmp2.y <= 4 && a[tmp2.x][tmp2.y] == 0){
                if(!visited[tmp2.x][tmp2.y]){   //没有访问过
                    visited[tmp2.x][tmp2.y] = 1;
                    path[tmp2.x][tmp2.y].step = tmp2.step;
                    path[tmp2.x][tmp2.y].xx = tmp.x;
                    path[tmp2.x][tmp2.y].yy = tmp.y;
                    q.push(tmp2);
                    continue;
                }

                if(tmp2.step < path[tmp2.x][tmp2.y].step){  //更新路径
                    path[tmp2.x][tmp2.y].step = tmp2.step;
                    path[tmp2.x][tmp2.y].xx = tmp.x;
                    path[tmp2.x][tmp2.y].yy = tmp.y;
                    q.push(tmp2);
                }
            }
        }
    }
    printPath(4,4);

    return 0;
}
