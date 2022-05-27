#include <iostream>
#include <cstring>
using namespace std;

// int n,hb,f[30],d[30],t[29];     // n < 25 h < 200
//N:湖数量30 hb:时间20 fi:最初五分钟钓鱼数 di:每五分钟减少的钓鱼数量 ti:每五分钟路途时间


int main(){
    // freopen("in/in024.txt","r",stdin);
    int n,hb;
    cin >> n;
    while(n != 0){
        cin >> hb;
        
        int tmp = -1;
        int res[30];    //保存这组数据结果
        int f[30],d[30],t[29];
        memset(res,0,sizeof(res));
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        memset(t,0,sizeof(t));
        for(int i = 0; i < n; ++i) cin >> f[i];    //最初5
        for(int i = 0; i < n; ++i) cin >> d[i];    //减少量
        for(int i = 0; i < n-1; ++i){
            cin >> t[i];  //路途时间
            // cout << t[i] << endl;
        } 

        int ft[n];

        for(int k = 0; k < n; ++k){ //最后可能停留的鱼塘可能有n种
            int result[n];  //保存这次结果
            for(int i = 0; i < n; ++i){
                result[i] = 0;  //结果
            }
            int h = hb*12;
            int test = 0;

            for(int i = 0; i < k; ++i) h-= t[i];    //减去走过的路程
            for(int i = 0; i < n; ++i) ft[i] = f[i];    // 复制一份初始的钓鱼数量

            int emp = 0;

            while(h > 0 && emp <= k){ //没时间了或者全空了，则退出循环
                
                int a = 0;
                for(int i = 0; i <= k; ++i){
                    if(ft[a] < ft[i]) a = i;    //找到初始数量最多的鱼塘 a
                }
                
                test += ft[a];  //尝试这种可能性
                result[a]++;    //a钓鱼一次，a时间增加
                ft[a]-= d[a];    //下次钓鱼量减少
                if(ft[a] <= 0) {
                    ft[a] = 0;   //不能更少了则为0
                }
                for(int i = emp; i <= k; ++i){  //统计空鱼塘数，只要有非空鱼塘，就继续
                    if(ft[i] == 0) {
                        
                        ++emp;  
                    }
                    else break;
                }
                h--;
            }
            if(test > tmp){ //如果能钓更多，则更新结果
                for(int i = 0; i < n; ++i){ //保存结果
                    res[i] = result[i];
                }
                if(h > 0){  //如果全空了，还有时间，就放在第一个湖上
                    res[0]+=h;
                }
                tmp = test;
            }
        }

        for(int i = 0; i < n; i++){
            cout << res[i]*5 ;
            if(i != n-1) cout << ", ";
        }
        cout << endl;
        cout<<"Number of fish expected: "<<tmp<<endl;
        cout << endl;
        cin >> n;
    }

    return 0;
}
