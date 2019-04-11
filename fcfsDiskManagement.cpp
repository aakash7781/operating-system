// first come first serve Disk Management
#include<iostream>
using namespace std;
main()
{
	int x,res=0;
	cout<<"enter cylinder numbers\n";
	cin>>x;
	int a[x+1];
	for(int i=1;i<=x;i++)
	{
		cout<<"enter cylinder numberings for cylinder ("<<(i)<<"): ";
		cin>>a[i];
	}
	cout<<"enter current cylinder number\n";
    int var=0;
	cin>>a[var];
	cout<<"total disk = ";
    int i=1;
    while(i<=x)
	{
		if(a[var]>a[i])
			res=res+a[var]-a[i];
		else
			res=res+a[i]-a[var];
		var++;
		i++;
	}
	cout<<res;
	
}
