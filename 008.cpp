#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
/*
    分派问题
    分析：
        初始已知：每个n个数字，分成相等的f个数的最大值
        方法：二分查找
*/

int n,f;
const double EPS = 1e-12;


bool isValid(double * v,double vol,int n,int f){
    int count = 0;
    for(int i = 0; i < n;i++){
        count += (int)(v[i]/vol);
        
    }
    return (count >=f);
}

int main(){
    
    // freopen("in.txt", "r", stdin);
    int n,f;    //1~10000
    cin >> n >> f;
    f = f+1;
    int r[n];    //1~10000
    double v[n];

    //初始化两个数组r和v
    for(int i = 0; i < n; i++){
        scanf("%d", &r[i]);
    }
    sort(r,r+n);

    for(int i = 0; i < n; i++){
        v[i] = 3.1415926535898*r[i]*r[i];
        
    }

    
    // 初始化下面要用的值
    double left =0 , right = 1,mid,ans,max = v[n-1];
    

    while((right-left) > EPS){
        mid = left + (right-left)/2;
        if(isValid(v,mid*max,n,f)) {
            ans = mid;
            left = mid;
        }else{
            right =mid- EPS;
        }
    }
    
        
    printf("%.3lf", ans*max);
    return 0;
}
