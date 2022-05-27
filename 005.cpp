#include <iostream>
using namespace std;

bool factor_value();    //因子
bool expression_value();    //表达式
bool term_value();

void rmSpace(){
    char c = cin.peek();
    while(c == ' '){
        cin.get();
        c = cin.peek();
    }
}

bool factor_value(){
    bool result;
    rmSpace();
    char c = cin.peek();
    if(c == '('){   //是一个括号括起来的表达式
        cin.get();
        rmSpace();
        result = expression_value();
        rmSpace();
        cin.get();
    }
    else if(c == '!'){
        cin.get();
        
        rmSpace();
        result = !factor_value();
        // rmSpace();
    }else {
        cin.get();
        if(c == 'V') result = true;
        else result = false;
        // rmSpace();
    }
    return result;
}

bool term_value(){
    bool result = factor_value();
    while(1){
        rmSpace();
        char op = cin.peek();
        if(op == '&' || op == '|'){
            cin.get();
            bool value = factor_value();
            if(op == '&') {
                result &= value;
            }
            else {
                result |= value;
            }
        }else break;
    }
    return result;
}

bool expression_value(){
    
    bool result = term_value();
    return result;
}


// 表达式-> 项
//     
int main(){
    bool result = 0;
    int count=0;

    while(count < 20){
        
            result= expression_value();
        if(cin.peek() == '\n') cin.get(); 
        if(result)
            cout << "Expression " << ++count << ": V" << endl;
        else 
            cout << "Expression " << ++count << ": F" << endl;
    }

    

    return 0;
}
