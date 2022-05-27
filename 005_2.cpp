//递归，看的别人的代码，能看就看，不懂就算了
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[100001]= {0};
int my_cnt=0;
bool expression_bool();
bool term_bool();
bool factor_bool();
 
bool expression_bool() //求一个表达式的值
{
    bool result=term_bool();//求第一项的值
    bool more=true;
    while(more)
    {
        char op=s[my_cnt];//看一个字符,不取走
        if(op=='&'||op=='|')
        {
            my_cnt++;//从数组中取走一个字符
            bool value=term_bool();
            if(op=='&') result=result&value;
            else result=result|value;
        }
        else
        {
            more=false;
        }
    }
    return result;
}
 
bool term_bool() //因为!的运算优先级更高,所以把!xxx也当成一个项
{
    bool result;
    char op=s[my_cnt];
    if(op=='!')
    {
        my_cnt++;
        result=!factor_bool();
    }
    else
    {
        result=factor_bool();
    }
 
    return result;
}
 
bool factor_bool() //求一个因子的值
{
    bool result;
    char c=s[my_cnt];
    if(c=='(') //如果该因子是由括号括起来的表达式组成的话
    {
        my_cnt++;
        result=expression_bool();
        my_cnt++;
    }
    else if(c=='V')
    {
        result=true;
        my_cnt++;
    }
    else if(c=='F')
    {
        result=false;
        my_cnt++;
    }
    else if(c=='!')  //出现了!,说明读取到了一个因子
    {
        result=term_bool();
    }
 
    return result;
}
 
int main()
{
    int k=0;
    while(cin.getline(s,100000))
    {
        char t[100001]= {0};
        int len=strlen(s);
        for(int i=0,k=0; i<len; ++i)
        {
            if(s[i]!=' ')
            {
                t[k++]=s[i];
            }
        }
 
        len=strlen(t);
        for(int i=0; i<len; ++i)
        {
            s[i]=t[i];
        }
        s[len]='\0';
        //到这里输入中的空格已经被去除干净了
        cout<<"Expression "<<++k<<": "<<(expression_bool()?"V":"F")<<endl;
        //初始化工作
        my_cnt=0;
        memset(s,0,100000);
    }
    return 0;
}
