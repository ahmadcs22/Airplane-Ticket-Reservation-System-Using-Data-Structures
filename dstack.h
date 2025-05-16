#include<iostream>
using namespace std;
struct node{
	int id;
	string name;
	string destination;
	string date;
	node *next;
};
class dynamicstack{
	node *head,*tail;
	public:
	dynamicstack()
	{
		head=tail=NULL;
	}
		bool isempty()
	{
		if(head==NULL)
		{
			return true;
		}
		else{
			return false;
		}
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
		node *cur;
		cur=head;
		while(cur->next!=NULL)
		{
			count++;
			cur=cur->next;
		}
		return count;	
		}
	}
	void push(int id,string des,string dat,string na){
		node *temp=new node;
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
			temp->next=head;
			head=temp;
		}
		cout<<"Successfully\n\n";
	}
		void pop()
	{	
		if(isempty())
		{
			cout<<"No cancellation history \n";
		}
		else{
			node *temp=head;
			head=head->next;
			cout<<temp->name<<" to "<<temp->destination<<" on "<<temp->date<<endl;
			delete temp;
		}
	}
	void display()
	{
		node *cur=head;
		while(cur!=NULL)
		{
			cout<<cur->id;
		}
	}
};


