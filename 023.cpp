#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct cup{
    int x,y;
    int step;
    int flag;
    cup *pre;
};

int A,B,C;
queue<cup> q;
stack<int> s;
int vis[110][110] = {0};    //是否走过
int ans = 0;

void bfs(){
    // int i;
    cup c;  //保存当前状态
    cup t[310]; //存放每一次目前瓶子里的水量的状态

    //初始化
    c.x = 0, c.y = 0;
    c.flag = -1;
    c.pre = NULL;
    c.step = 0;

    q.push(c);  //c 进入队列
    vis[0][0] = 1;
    int count = -1;
    
    while(!q.empty()){
        count++;
        t[count] = q.front();       //存储已经走过的
        q.pop();
        for(int i = 0; i < 6; ++i){
            //走一步
            switch(i){
                case 0:
                    c.x =  A;
                    c.y = t[count].y;
                    c.flag = 0;
                    break;
                case 1:
                    c.y =  B;
                    c.x = t[count].x;
                    c.flag = 1;
                    break;
                case 2: //drop(A)
                    c.x = 0;
                    c.y = t[count].y;
                    c.flag = 2;
                    break;
                case 3: //drop(B)
                    c.y = 0;
                    c.x = t[count].x;
                    c.flag = 3;
                    break;
                case 4: //pour(x,y)
                    if(t[count].x > B - t[count].y){    //可以倒满B
                        c.x = t[count].x - (B-t[count].y);
                        c.y = B;
                    }else{
                        c.x = 0;
                        c.y = t[count].y+t[count].x;
                    }
                    c.flag = 4;
                    break;
                case 5:
                    if(t[count].y > A - t[count].x){    //可以倒满B
                        c.y = t[count].y - (A-t[count].x);
                        c.x = A;
                    }else{
                        c.y = 0;
                        c.x = t[count].x+t[count].y;
                    }
                    c.flag = 5;
                    break;
            }
            
            //已经走过
            if(vis[c.x][c.y]) continue; 

            //没走过
            vis[c.x][c.y] = 1;
            c.step = t[count].step + 1;
            c.pre = &t[count];  //保存前驱

            //找到结果，因为是广度优先，因此最早找到一定是最短的
            if(c.x == C || c.y == C){
                ans = c.step;
                while(c.pre){
                    //栈先进后出，因此可以沿着pre打印出路径
                    s.push(c.flag);
                    c = *c.pre;
                }
                return;
            }
            q.push(c);
        }
    }
}

void print(){
    while(!s.empty()){
        int i = s.top()+1;
        s.pop();
        switch(i){
            case 1: cout<<"FILL(1)"<<endl;break;
			case 2: cout<<"FILL(2)"<<endl;break;
			case 3: cout<<"DROP(1)"<<endl;break;
			case 4: cout<<"DROP(2)"<<endl;break;
			case 5: cout<<"POUR(1,2)"<<endl;break;
			case 6: cout<<"POUR(2,1)"<<endl;break;
        }
    }
}

int main(){
    freopen("in/in023.txt","r",stdin);
    cin >> A >> B >> C;
    bfs();
    if(ans == 0) cout<<"impossible"<<endl;
    else {
        cout << ans << endl;
        print();
    }
    return 0;
}
