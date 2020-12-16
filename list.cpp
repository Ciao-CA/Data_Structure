#include<iostream>
using namespace std;

class List
{
private:
    int data;
    List *next;
public:
    List *Create(int len)
    {
        int val;
        List *head,*tail,*pre;
        head=new List;
        head->next=NULL;pre=head;
        head->data=len;
        cout<<"输入各权值"<<endl;
        while(len)
        {
            attach(pre,tail);
            pre=pre->next;
            cin>>val;
            pre->data=val;
            --len;
        }
        return head;
    }
    void attach(List *pre,List *tail)
    {
        tail=new List;
        pre->next=tail;
        tail->next=NULL;
    }

    void print(List *l)
    {
        int len=l->data;
        while(--len)
        {
            l=l->next;
            cout<<l->data<<" ";
        }
        cout<<l->next->data<<endl;
    }

    void Insertk(int val,int k,List *l)
    {
        if(k<1||k>l->data)
        {
            cout<<"wrong parameter"<<endl;
            return;
        }
        int len=l->data;
        ++l->data;
        while(--k)
        {
            l=l->next;
        }
        List *pre=new List;
        pre->next=l->next;
        l->next=pre;
        pre->data=val;
    }

    void deletek(int k,List *l)
    {
        if(k<1||k>l->data)
        {
            cout<<"wrong parameter"<<endl;
            return;
        }
        int len=l->data;
        --l->data;
        while(--k)
        {
            l=l->next;
        }
        List *pre=l->next;
        l->next=pre->next;
        pre->next=NULL;
    }

    bool isempty(List *l)
    {
        return l->data==0;
    }

    int getlength(List *l)
    {
        return l->data;
    }

    List *reverse(List *l)
    {
        List *p,*q;
        List *h=l->next;
        p=h->next;
        q=p->next;
        h->next=NULL;
        while(p!=NULL)
        {
            p->next=h;
            h=p;
            p=q;
            if(q!=NULL)
                q=q->next;
        }
        l->next=h;
        return l;
    }

    List *lappend(List *l1,List *l2)
    {
        if(l1==NULL)return NULL;
        if(l2==NULL)return NULL;
        List *l;
        l=new List;
        List *pre1,*pre2,*tail,*tag,*head;
        List *p1,*p2;
        head=new List;
        head->data=l1->data+l2->data;
        tag=head;
        tail=new List;
        head->next=tail;tail->next=NULL;
        pre1=l1->next;pre2=l2->next;
        while(pre1&&pre2)
        {
            if(pre1->data<=pre2->data)
            {
                tail->data=pre1->data;
                List *n=new List;
                tail->next=n;
                tail=tail->next;
                pre1=pre1->next;
            }
            else
            {
                tail->data=pre2->data;
                List *n=new List;
                tail->next=n;
                tail=tail->next;
                pre2=pre2->next;
            }
        }
        if(pre1)
        {
            while(pre1)
            {
                tail->data=pre1->data;
                List *n=new List;
                tail->next=n;
                tail=tail->next;
                pre1=pre1->next;
            }
        }
        else
        {
            while(pre2)
            {
                tail->data=pre2->data;
                List *n=new List;
                tail->next=n;
                tail=tail->next;
                pre2=pre2->next;
            }
        }
        tail=NULL;
        return tag;
    }

    void mysort(List *l)
    {
        List *head,*tail;
        head=l->next;tail=head;
        for(head;head!=NULL;head=head->next)
        {
            for(tail=head;tail!=NULL;tail=tail->next)
            {
                if(head->data>tail->data)
                {
                    int s=head->data;
                    head->data=tail->data;
                    tail->data=s;
                }
            }
        }
    }

};

int main()
{
    List root;
    int len=5;
    List *r=root.Create(len);
    root.mysort(r);
    root.print(r);
    return 0;
}
