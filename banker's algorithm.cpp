//program for implementing banker's algorithm
#include <iostream>
#define MAX 20
using namespace std;
 
class bankers
{
    private:
        int allo[MAX][MAX],max[MAX][MAX],need[MAX][MAX],avail[MAX];
        int p,r,k,result[MAX],pnum,work[MAX],finish[MAX];
 
    public:
        bankers();
        void input();
        void method();
        int search(int);
        void display();
};
 
bankers::bankers()
{
    k=0;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            allo[i][j]=0;
            max[i][j]=0;
            need[i][j]=0;
        }
        avail[i]=0;
        result[i]=0;
        finish[i]=0;
    }
}
 
void bankers::input()
{
    int i,j;
    cout << "Enter the number of processes:";
    cin >>p;
    cout << "Enter the number of resources:";
    cin >>r;
    cout << "Enter the allocated resources: " << endl;
    for(i=0;i<p;i++)
    {
        cout<<"Process\n"<<i;
        for(j=0;j<r;j++)
        {
            cout<<"Resource\n"<<j<<":";
            cin>>allo[i][j];
        }
    }
    cout<<"Enter the maximum resources: "<<endl;
    for(i=0;i<p;i++)
    {
        cout<<"Process\n"<<i;
        for(j=0;j<r;j++)
        {
            cout<<"Resouce\n"<<j<<":";
            cin>>max[i][j];
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    cout << "Enter the currently available resources: ";
    for(j=0;j<r;j++)
    {
        cout<<"Resource "<<j<<":";
        cin>>avail[j];
        work[j]=-1;
    }
    for(i=0;i<p;i++)
        finish[i]=0;
}
 
void bankers::method()
{
    int i=0,j,flag;
    while(1)
    {
        if(finish[i]==0)
        {
            pnum =search(i);
            if(pnum!=-1)
            {
                result[k++]=i;
                finish[i]=1;
                for(j=0;j<r;j++)
                {
                    avail[j]=avail[j]+allo[i][j];
                }
            }
        }
        i++;
        if(i==p)
        {
            flag=0;
            for(j=0;j<r;j++)
                if(avail[j]!=work[j])
 
            flag=1;
            for(j=0;j<r;j++)
                work[j]=avail[j];
 
            if(flag==0)
                break;
            else
                i=0;
        }
    }
}
 
int bankers::search(int i)
{
    int j;
    for(j=0;j<r;j++)
        if(need[i][j]>avail[j])
            return -1;
    return 0;
}
 
void bankers::display()
{
    int i,j;
    cout<<endl<<"OUTPUT:\n";
    cout<<endl<<"PROCESS\t     ALLOTED\t     MAXIMUM\t     NEED";
    for(i=0;i<p;i++)
    {
        cout<<"\nP"<<i+1<<"\t     ";
        for(j=0;j<r;j++)
        {
            cout<<allo[i][j]<<"  ";
        }
        cout<<"\t     ";
        for (j=0;j<r;j++)
        {
            cout<<max[i][j]<<"  ";
        }
        cout<<"\t     ";
        for(j=0;j<r;j++ )
        {
            cout<<need[i][j]<<"  ";
        }
    }
    cout<<"\nThe sequence of the safe processes are: \n";
    for(i=0;i<k;i++)
    {
        int temp = result[i]+1 ;
        cout<<"P"<<temp<<" ";
    }
    cout<<"\nThe sequence of unsafe processes are: \n";
    int flg=0;
    for (i=0;i<p;i++)
    {
        if(finish[i]==0)
        {
        flg=1;
        }
        cout<<"P"<<i<<" ";
    }
    cout<<endl<<"RESULT:\n";
    if(flg==1)
        cout<<endl<<"not in safe state";
    else
        cout<<endl<<"safe state";
}
 
int main()
{
    bankers B;
    B.input ( );
    B.method ( );
    B.display ( );
}
