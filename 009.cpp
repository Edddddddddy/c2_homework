#include <iostream>
using namespace std;
int a[100010];

//一共n天，分成m份，使得最大的一份最小



bool isValid(int mid, int n, int m){
    int fajoSum = 0,cnt = 1;
    for(int i = 0; i < n; ++i){
        if(fajoSum+a[i] > mid) {
            if(a[i] > mid) return false; //需要扩大
            ++cnt;
            if(cnt > m) return false;   //需要扩大
            fajoSum = 0;
        }
        fajoSum += a[i];    //有a[i],cnt就会多一个，因此，初始cnt为1
    }
    if(cnt <= m) return true;
    return false;
}

int fajo(int l, int r,int n,int m){
    int ans;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(isValid(mid,n,m)){   //看看是否有更小的
            ans = mid;
            r = mid-1;
        }else{
            l = mid +1;
        }
    }
    return ans;
}


int main(){
    // freopen("./in/in9.txt","r",stdin);
    int n,m,min = 99999,max = 0;
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(a[i] < min) min = a[i];
        max += a[i]; 
    }    

    cout << fajo(min,max,n,m);

    return 0;
}
