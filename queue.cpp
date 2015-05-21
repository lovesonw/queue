#include <iostream>
using namespace std;
struct Node
{
    int Data;
    Node *next;
};
class List
{
    Node *head;
    public:
        List()
        {
            head=NULL;
        }
        void insertlist(int aData,int bData);
        void deletelist(int aData);
        void outputlist();
        Node *gethead()
        {
            return head;
        }
};
void List::outputlist()
{
    Node *now=head;
    while(now!=NULL)
    {
        cout<<now->Data<<" ";
        now=now->next;
    }
    cout<<endl;
}
void List::insertlist(int aData,int bData)
{
    Node *p,*q,*s;
    s=(Node*)new(Node);
    s->Data=bData;
    p=head;
    if (head==NULL) //空表
    {
        head=s;
        s->next=NULL;
    }
    else
        if (p->Data==aData) //第一个数据
        {
            s->next=p;
            head=s;
        }
    else
    {
        while (p->Data!=aData&&p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        if (p->Data==aData)
        {
            q->next=s;
            s->next=p;
        }
        else
        {
            p->next=s;
            s->next=NULL;
        }
    }
}
void List::deletelist(int aData)
{
    Node *p,*q;
    p=head;
    if (p==NULL)
        return;
    if (p->Data==aData)
    {
        head=p->next;
        delete p;
    }
    else
    {
        while(p->Data!=aData&&p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        if (p->Data==aData)
        {
            q->next=p->next;
            delete p;
        }
    }
}
int main()
{
    List A,B;
    int Data[10]={156,15,2,36,889,15,654,12,489,652};//可从文件读入
    A.insertlist(0,Data[0]);
    for (int i=1;i<10;i++)
        A.insertlist(0,Data[i]);
    A.outputlist();
    A.deletelist(Data[4]);
    A.outputlist();
    B.insertlist(0,Data[0]);
    for (int i=1;i<10;i++)
        B.insertlist(B.gethead()->Data,Data[i]);
    B.outputlist();
    B.deletelist(16);
    B.outputlist();
    return 0;
}
