
#include"string"
#include"stack"
bool checkExpression(const char * a)
{
    int i=0;
    stack<char>s;
    while(a[i]){
        if(a[i]=='(') s.push(a[i]);
        else if(a[i]==')'&&! s.empty()) s.pop();
        else if(a[i]==')')return 1;
        i++;
    }
    if(!s.empty())return 1;
    else return 0;
}
int main(){
    string s="a+((b*c)/()(d+f)-(sdf)*d))-5";
    while(1){
        cout<<"Please input expression(Ctr1+C break):"<<endl;
        cin>>s;
        int ret=checkExpression(s.c_str());
        if(ret)cout<<"Expression Error."<<endl;
        else cout<<"Expression Ok."<<endl;
    }
return 0;
}
