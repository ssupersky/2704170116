#include"iostream"
using namespace std;
class MyStack{
public:
    MyStack(int n):N(n),k(-1){a=new int[k];}
    ~MyStack(){if(a) delete[] a;}
    bool full(){return k==N-1? true:false;}
    bool empty(){return k==-1? true:false;}
    void push(int i){if(k>N-1) throw ":Overflow";a[++k]=i;}
    int pop(){if(k<0) throw "Underflow";return a[k--];}
    bool checkIn(int i){
    for(int j=0;j<=k;j++){
        if(a[j]==i) return true;
    }
    return false;
    }
    int getNext(int i){
        if(full()) return -1;
        int j=i;
        do{
            j++;
            if(j>N-1)j=0;
            if(! checkIn(j))return j;
        }while(j!=i);
        return -1;
    }
    int getGreater(int i){
    int j=i;
    do{
        j++;
        if(j>N-1)return -1;

    }while(checkIn(j));
    return j;}
    int *a;
    int k;
    int N;
};
void printArray(int *a,MyStack &s)
{
    for(int i=0;i<s.N;i++)
        cout<<a[s.a[i]]<<" ";
    cout<<endl;
}
void permutation(int *a,int n)
{
    MyStack s(n);
    int k=0;
    do
    {
        s.push(k);
        k=n-1;
        while((k=s.getNext(k))!=-1)s.push(k);
        printArray(a,s);
        while(! s.empty()){
            k=s.getGreater(s.pop());
            if(k!=-1)break;
        }

    }while(! s.empty()||k!=-1);
}
int main(int argc,char * argv[])
{
    int a[]={1,12,3,4,0};
    permutation(a,sizeof(a)/sizeof(int));
    return 0;
}
