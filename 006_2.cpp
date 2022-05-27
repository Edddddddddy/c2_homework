#include <iostream>

using namespace std;
int IntDivide(int n, int m)
{
        if((n<1)||(m<1))
                return 0;
        if((n==1)||(m==1))
                return 1;
        if(n<m)
                return IntDivide(n,n);
        if(n==m)
                return IntDivide(n,n-1)+1;
        return IntDivide(n-m,m)+IntDivide(n,m-1);
}
 
int main()
{

    int n ;
    int k = 50;
    while(k--){
        cin >> n;
        cout << IntDivide(n,n) << endl;
    }


    return 0;
}