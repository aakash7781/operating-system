// program for first fit
#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cout<<"enter number of blocks"<<endl;
	cin>>n;
	cout<<"enter number of processes"<<endl;
	cin>>m;
	int allocation[m];
	int block[n];
	int process[m];
	for(int i=0;i<n;i++)   
	{
		block[i]=0;
	}
		for(int i=0;i<m;i++)      
	{
		process[i]=0;
	}
	
	cout<<"enter size of blocks"<<endl;  
	for(int i=0;i<n;i++)
	{
		cout<<"enter size of block"<<i+1<<"     "; cin>>block[i];
	}
	cout<<"enter size of process"<<endl;  
	for(int i=0;i<n;i++)
	{
		cout<<"enter size of process"<<i+1<<"     "; cin>>process[i];
	}
	for(int i=0;i<m;i++) 
	{
		cout<<"check "<<i<<endl;		
		for(int j=0;j<n;j++) 				
		{cout<<"check "<<j<<endl;       
		
			if(process[i]<=block[j])
				{
					allocation[i]=j;
					cout<<"process allocated "<<j+1<<endl;
					block[j]=block[j]-process[i];cout<<"block size left"<<block[j]<<endl;
					break;
				}
		}
	}
	cout<<"blocks allocated"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<allocation[i]+1<<endl;
	}
	cout<<"process allocated                    block allocated"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<i+1<<"                                          "<<allocation[i]+1<<endl;
	}
}
