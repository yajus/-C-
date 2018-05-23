#include<iostream>
using namespace std;
class set
{
public:
    int n=0;
    int data[10000]={0};
public:
    set(int num)
    {
        data[1]=num;
        n++;
    }
    
    set()
    {}
    
    set (int* c)
    {
        int size=0;
        int count=1;
        while(c[count]!=0)
        {
            size++;
            count++;
        }
        int i;
        for(int j=1;j<=size;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(data[i]==c[j])
                    break;
            }
            if(--i==n)
            {
                data[i+1]=c[j];
                n++;
            }
        }
    }
    //method
public:
    set& operator+(const set w)
    {
        for(int j=1;j<=w.n;j++)
        {
            int i;
            for(i=1;i<=n;i++)
            {
                if(data[i]==w.data[j])
                    break;
                //cout<<'i'<<i<<endl;
            }
            if(--i==n)
            {
                //cout<<'i'<<i<<endl;
                data[i+1]=w.data[j];
                n++;
            }
        }
        return *this;
    }
    set& operator-(const set w)
    {
        for(int j=1;j<=w.n;j++)
        {
            int i;
            for(i=1;i<=n;i++)
            {
                if(data[i]==w.data[j])
                    break;
            }
            if(--i!=n)
            {
                ++i;
                for(i;i<=n-1;i++)
                    data[i]=data[i+1];
                data[n]=0;
                n--;
            }
        }
        return *this;
    }
    friend set& operator^(const set y,const set w);
    
    void show()
    {
        cout<<"集合元素为："<<endl;
        for(int i=1;i<=n;i++)
            cout<<data[i]<<' ';
        cout<<endl;
    }
};
set& operator^(const set y,const set w)
{
    set re;
    for(int i=1;i<=w.n;i++)
    {
        for(int j=1;j<=y.n;j++)
        {
            if(w.data[i]==y.data[j])
            {
                re+w.data[i];
            }
        }
    }
    return re;
}
int main()
{
    set *data[100];
    int num=0;
    int choice=1;
    while(choice!=0)\
    {
        cout<<"请选择操作：0.退出;1.输入新集合;2.集合合并;3.集合相交;4.集合相减;5.查看集合元素:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
                break;
            case 1:
            {
                num++;
                cout<<"请输入元素个数:"<<endl;
                int n;
                cin>>n;
                int exchange[1000]={0};
                cout<<"请输入元素:"<<endl;
                for(int i=1;i<=n;i++)
                    cin>>exchange[i];
                data[num]=new set(exchange);
                data[num]->show();
                break;
            }
            case 2:
            {
                cout<<"请选择两个集合：";
                int an,bn;
                cin>>an>>bn;
                *data[an]=*data[an]+*data[bn];
                cout<<an<<"+"<<bn<<"->"<<an<<endl;
                (*data[an]).show();
                break;
            }
            case 3:
            {
                cout<<"请选择两个集合：";
                int an,bn;
                cin>>an>>bn;
                *data[an]=*data[an]^*data[bn];
                cout<<an<<"^"<<bn<<"->"<<an<<endl;
                (*data[an]).show();
                break;
            }
            case 4:
            {
                cout<<"请选择两个集合：";
                int an,bn;
                cin>>an>>bn;
                *data[an]=*data[an]-*data[bn];
                cout<<an<<"-"<<bn<<"->"<<an<<endl;
                (*data[an]).show();
                break;
            }
            case 5:
            {
                cout<<"请选择一个集合：";
                int an;
                cin>>an;
                (*data[an]).show();
            }
        }
    }
}







