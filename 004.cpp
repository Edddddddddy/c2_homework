#include <iostream>
#include <math.h>
using namespace std;

void transformInt(int n){
    if(n == 0) {
        cout << "0";
        return;
    }
    if(n == 1) {
        cout << "2";
        return;
    }
    int count = 0;
    for(int i = 30; i >=0; i--){
        // if(pow(2,(31-i)) > n) continue;
        if(((n>>i)&1) == 1) {
            count++;
            if(count>1) cout << "+";
            if(i == 1) {
                cout << "2";
                continue;
            }
            cout << "2(";
            transformInt(i);
            cout << ")";
        }
    }
    
}

int main(){
    int n;
    cin >> n;
    transformInt(n);
    

    return 0;
}
