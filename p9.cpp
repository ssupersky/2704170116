#include<iostream>
#include<sstream>
#include"string"
using namespace std;
int getInt(string &a)
{
    for(unsigned int i=0;i<a.length();i++){
        char s=a[i];
        if(!(s>='0'&&s<='9'||0==i&&('+'==s||'-'==s)))
            throw a+"is not an int number.";
    }
    int n=atoi(a.c_str());
    stringstream p;
    p<<n;
    if(a!=p.str())throw a+"out of range.";
    return n;

}
void main()
{
    string a,b;
    cout<<"please input 2 int numbers:"<<endl;
    try{
        cin>>a>>b;
        int n=getInt(a);
        int m=getInt(b);
        int k=n+m;
        if(k>0&&n<0&&m<0||k<0&&n>0&&m>0)throw"over flow.";
        cout<<n<<"+"<<m<<"="<<k<<endl;
    }
    catch(char * s)
    {
        cout<<"input error:"<<s<<endl;
    }
    catch(string s)
    {
        cout<<"input error:"<<s<<endl;
    }
}
