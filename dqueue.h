#include<iostream>
using namespace std;
struct gnode{
		int id;
	string name;
	string destination;
	string date;
	gnode *next;
};
class dynamicqueue{
	gnode *head,*tail;
	public:
		dynamicqueue()
		{
			head=tail=NULL;
		}
		int count()
	{
		if(isempty())
		{
			cout<<"no nodes exist";
		}
		else
		{
			int count=1;
		gnode *cur;
		cur=head;
		while(cur->next!=NULL)
		{
			count++;
			cur=cur->next;
		}
		return count;	
		}
	}
		bool isempty()
		{
			if(head==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	
		void enqueue(int id,string des,string dat,string na)
			{
			gnode *temp=new gnode;
			temp->id=id;
		temp->name=na;
		temp->destination=des;
		temp->date=dat;
		temp->next=NULL;
		if(isempty())
		{
			head=tail=temp;
		}
		else
		{
			tail->next=temp;
			temp=tail;
		}
		cout<<"Flight Took Off !\n";
	}
	void dequeue()
	{
			if(isempty())
		{
			cout<<"NO Flights Departure History\n";
		}
		else{
				gnode *temp=head;
			head=head->next;
			cout<<temp->name<<" to "<<temp->destination<<" on "<<temp->date<<endl;
			delete temp;
		}
	}
	
};

