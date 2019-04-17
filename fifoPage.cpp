//program for first in firstout page replacement
#include<iostream>
using namespace std;
int fr[3];
main()
{
void display();
int i,j,x;
cout<<"enter no of pages\n";
cin>>x;
int page[x];
cout<<"enter page sequence\n";
for(int i=0;i<x;i++)
cin>>page[i];
int flag1=0,flag2=0,pf=0,frsize=3,top=0;
for(i=0;i<3;i++)
{
fr[i]=-1;
}
for(j=0;j<12;j++)
{
flag1=0;
flag2=0;
for(i=0;i<12;i++)
{
if(fr[i]==page[j])
{
flag1=1;
flag2=1;
break;
}
}
if(flag1==0)
{
for(i=0;i<frsize;i++)
{
if(fr[i]==-1)
{
fr[i]=page[j];
flag2=1;
break;
}
}
}
if(flag2==0)
{
fr[top]=page[j];
top++;
pf++;
if(top>=frsize)
top=0;
}
display();
}
cout<<"Number of page faults  : "<<pf;

}
void display()
{
int i;
cout<<"\n";
for(i=0;i<3;i++)
cout<<fr[i]<<"\t";
}
