//solving producer-consumer problem using semaphores 
#include<iostream>
using namespace std;
int s=1,e=5,f=0;
//wait
int wait(int s)
{ 
	return(--s);
}
//signal
int signal(int s)
{
	return(++s);
}
		//producer
void producer()
{

	while(1)
        {

		cout<<"produced :\n";

		e=wait(e);
		s=wait(s);
		s=signal(s);
		f=signal(f);

		cout<<"s="<<s<<"\tf="<<f<<"\te="<<e<<"\n";
		break;

	}	

}
			//consumer
void consumer()

{

	while(1)
	{ 
		cout<<"consumed :\n";
		e=wait(f);
		s=wait(s);
		s=signal(s);
		e=signal(e);
		cout<<"s="<<s<<"\tf="<<f<<"\te="<<e<<"\n";
		break;

	}

}

main()

{

	int choice;
		while(1)

		{
			cout<<"1.Producer"<<"\n"<<"2.Consumer"<<"\n"<<"3.exit"<<"\n";
			cin>>choice;
			switch(choice)
			{
				case 1:if(s==1&&(e!=0))
				producer();
				else
				cout<<"buffer is full";
				break;
				case 2:if((s==1)&&(f!=0))
				consumer();
				else
				cout<<"Buffer empty";
				break;
				case 3:exit(0);
				break;

			}

		}

}

