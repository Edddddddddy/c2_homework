#include <iostream>
#include <cstring>
using namespace std;

char tfloor[21][21];
bool label[21][21];
int W, H;
int sum ;

void dfs(int m, int n){
    if(label[m][n] == 1) return;
    label[m][n] = 1;
    sum++;
    if(m-1>=0  && tfloor[m-1][n] == '.')dfs(m-1,n);
    if(m+1<H  && tfloor[m+1][n] == '.')dfs(m+1,n);
    if(n-1>=0  && tfloor[m][n-1] == '.')dfs(m,n-1);
    if(n+1<W && tfloor[m][n+1] == '.')dfs(m,n+1);
    
}

int main(){
    // freopen("in/in018.txt","r",stdin);
    

    while(scanf("%d %d",&W,&H)){
        char c;
        while((c =getchar()) != -1){
            if(c == '\n') break;
        }
        
        if(W==0 && H==0){
            break;
        }	
        int bw = 0, bh = 0;
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                scanf("%c",&tfloor[i][j]);
                if(tfloor[i][j] == '@'){
                    bh = i;
                    bw = j;
                }
            }
            while(getchar() != '\n'); 
            
        }
        sum = 0;
        memset(label, 0x00, sizeof(label));
        dfs(bh,bw);
        cout << sum << endl;
    }
    

    return 0;
}
