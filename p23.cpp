#include "iostream"
using namespace std;
class Node{
public:
    Node(int i):data(i),next(0){}
    int data;
    Node * next;
};
Node * createList(int * a,int n){
    Node * first,*p;
    for(int i=0;i<n;i++){
        if(i==0)p=first=new Node(a[i]);
        else{
                Node * q=new Node(a[i]);
                p->next=q;
                p=p->next;
    }
    }
    p->next=first;
    return first;
}
int msin()
{
    int a[]={1,1,1,2,3,4,2,2,2,1};
    Node * first=createList(a,sizeof(a)/sizeof(int));
    int MaxLen=0;
    int MaxColor=0;
    int MaxStart=0;
    int CurrentLen=0;
    int CurrentColor=0;
    int CurrentStart=0;
    int pos;
    CurrentColor=first->data;
    CurrentLen=1;
    CurrentStart=1;
    Node * p=first->next;
    pos=2;
    while(p!=first&&p->data==first->data)
    {
        CurrentLen++;
        p=p->next;
        pos++;
    }
    int FirstColorLen=CurrentLen;
    while(p!=first){
        int k=p->data;
        if(k==CurrentColor) CurrentLen++;
        else{
            if(CurrentLen>MaxLen){
                MaxStart=CurrentLen;
                MaxColor=CurrentColor;
                MaxStart=CurrentStart;
            }
            CurrentLen=1;
            CurrentColor=k;
            CurrentStart=pos;
        }
        p=p->next;
        pos++;
    }
    if(CurrentStart!=1&&p->data==CurrentColor){
        CurrentLen+=FirstColorLen;
    }
    if(CurrentLen>MaxLen){
        MaxLen=CurrentLen;
        MaxColor=CurrentColor;
        MaxStart=CurrentStart;
    }
    cout<<"Color:"<<MaxColor<<"Len:"<<MaxLen<<"Start"<<MaxStart<<endl;
    return 0;
}
