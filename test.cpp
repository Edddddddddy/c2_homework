#include <iostream>
#include <math.h>
using namespace std;

void mydel(int * a){
    a[1]-=1;
    cout << a[1] << " ";
}
string add(string s1, string s2){
    
    string res = "";
    bool flag = false;
    int m,n;
    for(int i = s1.length()-1,j = s2.length()-1;i>-1||j>-1;--i,--j){
        if(i>-1){
            m = s1[i] - '0';
        }else{
            m = 0;
        }
        if(j>-1){
            n = s2[j] - '0';
        }else{
            n = 0;
        }

        if(flag == true){
            if(m+n+1 >=10){
                flag = true;
            }
                res = (char)(((m+n+1)%10)+'0')+res;
        }else{
            if(m+n >= 10){
                flag = true;
            }
            res = (char)(((m+n)%10)+'0')+res;
        }
    }
    return res;
}

int main(){
    // char s[100];
    // while(cin.getline(s,100)){
        
    //     int len = 0;
    //     while(s[len]){
    //         len ++;
    //     }
    //     // cout << len;
    //     // cin.putback('\n');
    //     for(int i = len-1;i >=0;i--){
    //         cin.putback(s[i]);
    //         cout << s[i];
    //     }
    //     char c;
    //     while(cin.peek()!='\n'){
    //         c = cin.get();
    //         cout << c;
    //     }

    // }
    // int b = 3;
    // double a = 1.1 * b;
    // cout << acos(-1);
    // char c = 'a' + 1;
    // cout << add("123", "111") << endl;

    cout <<  char(1+'@');
    
    return 0;
}
