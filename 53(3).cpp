#include"iostream"
#include"stack"
using namespace std;
void Convert(int n, int k)
{
    int p;
    stack<int>s;
    while(n){
        p=n/k;
        s.push(n-p*k);
        n=p;
    }
    while(!s.empty()){
        int r=s.top();
        s.pop();
        cout<<((r<10)? (char)(r+'0'):(char)(r-10+'a'));
    }
    cout<<"Done."<<endl;
}
int main()
{
    int n,k;
    while(1){
        cout<<"请输入十进制数和转换的进制(2~36)"<<endl;
        cin>>n>>k;
        if(k<1||k>36) cout<<"进制"<<k<<"Eorror"<<endl;
        Convert(n,k);
    }
    return 0;
}
