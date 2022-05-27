#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[210][210]; //地图
bool visited[210][210][15]={0};  //是否走过
int M,N,T;  //地图大小，查克拉量
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct Node{
    int r,c;
    int t;
    int steps;
}start,endNode;

void bfs(){
    queue<Node> q;

    q.push(start);

    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        
        //找到
        if(tmp.r == endNode.r && tmp.c == endNode.c){
            printf("%d\n",tmp.steps);
            return;
        }

        //没找到，遍历所有移动方向
        for(int i = 0; i < 4; ++i){
            Node tmp2;
            tmp2.r = tmp.r + dir[i][0];
            tmp2.c = tmp.c + dir[i][1];
            //没有越界
            if(tmp2.r >= 0 && tmp2.r < M && tmp2.c >= 0 && tmp2.c < N ){
                //该状态下没有访问过，且查克拉够，且是敌人
                if(!visited[tmp2.r][tmp2.c][tmp.t-1] && tmp.t > 0 && map[tmp2.r][tmp2.c] == '#' ){
                    tmp2.t = tmp.t-1;
                    tmp2.steps = tmp.steps + 1;
                    q.push(tmp2);
                    visited[tmp2.r][tmp2.c][tmp2.t] = 1;
                }
                //未访问过，且不是敌人
                else if(!visited[tmp2.r][tmp2.c][tmp.t] && map[tmp2.r][tmp2.c] != '#'){
                    tmp2.t = tmp.t;
                    tmp2.steps = tmp.steps +1;
                    q.push(tmp2);
                    visited[tmp2.r][tmp2.c][tmp2.t] = 1;
                }
                //其余情况：访问过则跳过，查克拉不够则跳过
            }
        }

    }
    cout << -1 << endl;
}

int main(){
    // freopen("in/in021.txt","r",stdin);
    
    while(cin >> M >> N >> T){
        // cout << M << N << T;
        for(int i = 0 ; i < M ; i ++)
        {
            for(int j = 0 ; j < N ; j ++)
            {
                cin>>map[i][j];
                if(map[i][j] == '@')
                {
                    start.r = i;
                    start.c = j;
                }

                if(map[i][j] == '+')
                {
                    endNode.r = i;
                    endNode.c = j;
                }
                // cout << map[i][j];
            }
            // cout << endl;
        }
        start.t = T;
        start.steps = 0;
        memset(visited,0,sizeof(visited));
        visited[start.r][start.c][T] = 1;
        
        getchar();
        
        bfs();
        cout << endl;
    }
    
    return 0;
}
