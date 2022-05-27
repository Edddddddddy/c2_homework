#include <iostream>
#include <algorithm>
using namespace std;
int N;

long fun(int f0[], int f1[],int s0, int s1){
    long tmp = 0;
    sort(f0, f0 + s0);//注意这里一定不能把s0写成s0-1，s0表示要排序s0个数
	sort(f1, f1 + s1);
    int i = s0-1, j = s1-1;
    while(i>=0 && j>=0){    //从f0和f1最后一个开始
        if(f0[i] <= f1[j]){     //
            --j;
            ++i;
        }else{  // ...f0[i].. .....f1[j].. 存在.....个逆序数
			tmp += j; 
			tmp++;
		}
        --i;
    }
    return tmp;
}

long nixu(int x[], int q){
    if(q == 1) return 0;
    if (q == 2 && x[0] > x[1]) return 1;
    if(q >= 3){
        int * p1 = new int[q/2 + 1];
        int * p2 = new int[q/2 + 1];
        for(int i = 0; i < q/2; i++) p1[i] = x[i];  //p1放前一半
        int d = 0; 
        for(int i = q/2; i < q;i++){    //p2放后一半，带上中间那个数字
            p2[d] = x[i];
            d++;
        }
        //前一半+后一半+？
        return nixu(p1,q/2) + nixu(p2, q-q/2) + fun(p1,p2,q/2,q-q/2); 
        delete []p1;
        delete []p2;
    }
}

int main(){
    freopen("in/in011.txt","r",stdin);

    cin >> N;
    int *a = new int[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    long sum = nixu(a,N);
    cout << sum;
    delete [] a;

    return 0;
}
