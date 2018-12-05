#include"iostream"

#include"queue"
using namespace std;
void Josephus(int n,int k)
{
    queue<int>s;
    int i=1;
    while(i<=n) s.push(i++);
    i=0;
    while(!s.empty()){
        int p=s.front();
        s.pop();
        i++;
        if(i==k){
            cout<<p<<" ";
            i=0;
        }
        else
            s.push(p);
        }
        cout<<endl;
}
int main()
{
    int n,k;
    cout<<"please input n,k:"<<endl;
    cin>>n>>k;
    Josephus(n,k);
    return 0;
}
