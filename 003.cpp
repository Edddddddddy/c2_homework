#include <iostream>
#include <cstring>
using namespace std;




void fullPermutation(string s, int n,int end){
    if(n == end) {
        for(int i = 0; i <= end;i++){
            cout << s[i];
        }
        cout << endl;
        return;
    }
    for(int i = n; i <= end;i++){
        char tmp=s[i];
        for(int j = i;j>n;--j){
            s[j] = s[j-1];
        }
        s[n] = tmp;
        // swap(s[i],s[n]);
        fullPermutation(s,n+1,end);
        // swap(s[i],s[n]);
        tmp=s[n];
        for(int j = n;j < i;j++){
            s[j] = s[j+1];
        }
        s[i] = tmp;
    }
    

}

int main(){
    string s;
    cin >> s;
    int len = s.length();
    fullPermutation(s,0,len-1);

    

    return 0;
}
