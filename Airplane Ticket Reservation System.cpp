#include <iostream>
#include <string.h>
#include "dstack.h"
#include "dqueue.h"
dynamicstack s1;
dynamicqueue q1;
using namespace std;
// node for regestration
struct reg
{
	int id;
	int age;
	string name;
	string address;
	int topay;
	reg *next;
	reg *prev;
};
// class for registration using linked list
class registerme
{
	reg *head, *tail;

public:
	registerme()
	{
		head = tail = NULL;
	}
	//////////////////////
	bool isempty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	///////////////////////
	void regme(int id, string name, int age, string address)
	{
		reg *temp = new reg;
		temp->id = id;
		temp->age = age;
		temp->name = name;
		temp->address = address;
		temp->topay = 0;
		temp->next = NULL;
		temp->prev = NULL;
		if (isempty())
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		system("cls");
		cout << "  ================ UOG Airlines PK =================  \t\t\t\n\n";
		cout << "  ----------Registeration Successfull --------- \t\t\t\n\n";
		cout << "\nYour id = " << id;
		cout << "\nYour name = " << name;
		cout << "\nYour age = " << age;
		cout << "\nYour Adress = " << address << endl;
		cout << "\n";
		system("pause");
	}
	/////////////////
	void displayreg()
	{
		if (isempty())
		{
			cout << "The list is empty.\n";
			system("pause");
			return;
		}
		reg *current = head;
		cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
		cout << "  ---------- List of Registered Persons --------- \t\t\t\n\n";
		while (current != NULL)
		{
			cout << "\nID: " << current->id << "\n";
			cout << "Name: " << current->name << "\n";
			cout << "Age: " << current->age << "\n";
			cout << "Address: " << current->address << "\n\n";
			current = current->next;
		}
		system("pause");
	}
	/////////////////////////////
	void deletereg(int id)
	{
		if (isempty())
		{
			cout << "The list is empty. Nothing to delete.\n";
			system("pause");
			return;
		}
		reg *cur = head;
		reg *prev = NULL;
		while (cur != NULL && cur->id != id)
		{
			prev = cur;
			cur = cur->next;
		}

		if (cur == NULL)
		{
			cout << "User with ID " << id << " not found.\n";
			system("pause");
			return;
		}
		if (head->id == id)
		{
			reg *temp = head;
			cout << head->name << " your ID " << id << " registration has been removed.\n";
			head = head->next;
			if (head != NULL)
			{
				head->prev = NULL;
			}
			delete temp;
		}
		else if (tail->id == id)
		{
			reg *temp = tail;
			cout << tail->name << " your ID " << id << " registration has been removed.\n";
			tail = tail->prev;
			if (tail != NULL)
			{
				tail->next = NULL;
			}
			delete temp;
		}
		else
		{
			cout << cur->name << " your ID " << id << " registration has been removed.\n";
			prev->next = cur->next;
			delete cur;
		}

		system("pause");
	}
	bool checkid(int id)
	{
		reg *current = head;
		while (current != NULL && current->id != id)
		{
			current = current->next;
		}
		if (current == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	string getname(int id)
	{
		reg *current = head;
		while (current != NULL && current->id != id)
		{
			current = current->next;
		}
		return current->name;
	}
	string getaddress(int id)
	{
		reg *current = head;
		while (current != NULL && current->id != id)
		{
			current = current->next;
		}
		return current->address;
	}
};

// to display tickets
struct ticket
{
	int serial;
	string date;
	string company;
	string destination;
	int quantity;
	int price;
	ticket *next, *prev;
};

class ticketavailable
{
	ticket *head, *tail;

public:
	ticketavailable()
	{
		addticket(1, "15/01/24", "PIA", "     Dubai ", 10, 98000);
		addticket(2, "16/01/24", "AirSial", " Qatar ", 5, 135000);
		addticket(3, "17/01/24", "Emirates", "Italy ", 3, 240000);
		addticket(4, "18/01/24", "PIA", "     Saudia", 20, 85000);
		addticket(5, "19/01/24", "Emirates", "Canada", 5, 355000);
	}
	bool empty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void addticket(int se, string dat, string com, string dest, int qt, int pri)
	{
		ticket *temp = new ticket;
		temp->serial = se;
		temp->date = dat;
		temp->company = com;
		temp->destination = dest;
		temp->quantity = qt;
		temp->price = pri;
		temp->next = NULL;
		temp->prev = NULL;
		if (empty())
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}
	void availabletickets()
	{
		if (empty())
		{
			cout << "The list is empty.\n";
			system("pause");
			return;
		}
		ticket *current = head;
		cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
		cout << "  ---------- List of Available Tickets --------- \t\t\t\n\n";
		cout << "No."
			 << " "
			 << " Date"
			 << " "
			 << "    Company"
			 << " "
			 << " Destination"
			 << "  "
			 << "Price"
			 << "    "
			 << "Available" << endl;
		while (current != NULL)
		{
			cout << " " << current->serial << " " << current->date << "    " << current->company << "   " << current->destination << "    " << current->price << "       " << current->quantity << endl;
			current = current->next;
		}
	}
	string getcompany(int t)
	{

		ticket *current = head;
		while (current != NULL && current->serial != t)
		{
			current = current->next;
		}
		return current->company;
	}
	string getdestination(int t)
	{

		ticket *current = head;
		while (current != NULL && current->serial != t)
		{
			current = current->next;
		}
		return current->destination;
	}
	string getdate(int t)
	{

		ticket *current = head;
		while (current != NULL && current->serial != t)
		{
			current = current->next;
		}
		return current->date;
	}
	int getprice(int t)
	{

		ticket *current = head;
		while (current != NULL && current->serial != t)
		{
			current = current->next;
		}
		return current->price;
	}
	void getquantity(int t)
	{
		{

			ticket *current = head;
			while (current != NULL && current->serial != t)
			{
				current = current->next;
			}
			current->quantity--;
		}
	}
};

ticketavailable obj2;

struct booked
{
	int uid;
	string uname;
	string uaddress;
	string company;
	string destination;
	int ticketnum;
	string date;
	booked *next, *prev;
};
class bookcancel : public registerme//multiple inherutance
{
	booked *head, *tail;

public:
	bookcancel()
	{
		head = tail = NULL;
	}
	bool ezempty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void bookthis(int num, int id)
	{
		int received, back, more;
		cout << "Your Total Charges are = " << obj2.getprice(num) << endl;
		cout << "Enter cash = ";
		cin >> received;
		while (received < obj2.getprice(num))
		{
			cout << "Enter more Cash = ";
			cin >> more;
			received = received + more;
		}
		back = received - obj2.getprice(num);
		cout << "Here is Your cash = " << back<<endl;
		booked *temp = new booked;
		temp->uid = id;
		temp->uname = getname(id);
		temp->uaddress = getaddress(id);
		temp->destination = obj2.getdestination(num);
		temp->company = obj2.getcompany(num);
		temp->date = obj2.getdate(num);
		temp->next = NULL;
		if (ezempty())
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		system("pause");
		system("cls");
		cout<<"\n\n---------------Booking Done----------------";
		cout << "\n\n-----------------Receipt-----------------";
		cout << "\nID: " << id << "\n";
		cout << "Name: " << getname(id) << "\n";
		cout << "Address: " << getaddress(id) << "\n";
		cout << "Destination " << obj2.getdestination(num) << "\n";
		cout << "Date " << obj2.getdate(num) << "\n\n";
		obj2.getquantity(num);

		system("pause");
	}

	void deletebooking(int id)
	{
		if (isempty())
		{
			cout << "You havent booked yet.\n";
			system("pause");
			return;
		}
		booked *cur = head;
		booked *prev = NULL;
		while (cur != NULL && cur->uid != id)
		{
			prev = cur;
			cur = cur->next;
		}

		if (cur == NULL)
		{
			cout << "You havent booked yet.\n";
			system("pause");
			return;
		}
		if (head->uid == id)
		{
			booked *temp = head;
			cout << head->uname << " your ticket to " << cur->destination << " has been removed.\n";
			s1.push(id, head->destination, head->date, head->uname);
			head = head->next;
			if (head != NULL)
			{
				head->prev = NULL;
			}
			delete temp;
		}
		else if (tail->uid == id)
		{
			booked *temp = tail;
			cout << tail->uname << " your ticket to " << cur->destination << " has been removed.\n";

			s1.push(id, tail->destination, tail->date, tail->uname);

			tail = tail->prev;
			if (tail != NULL)
			{
				tail->next = NULL;
			}
			delete temp;
		}
		else
		{
			cout << cur->uname << " your ticket to " << cur->destination << " has been removed.\n";
			s1.push(id, cur->destination, cur->date, cur->uname);
			prev->next = cur->next;
			delete cur;
		}

		system("pause");
	}
	bool checkidbooking(int id)
	{
		booked *current = head;
		while (current != NULL && current->uid != id)
		{
			current = current->next;
		}
		if (current == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void showcanceled()
	{
		while (!s1.isempty())
		{
			s1.pop();
		}
	}
	void getflight(int id)
	{
			booked *current = head;
		while (current != NULL && current->uid != id)
		{
			current = current->next;
		}
		cout<<" Name: "<<current->uname<<endl;
		cout<<" Destination "<<current->destination<<" with "<<current->company<<endl;
		cout<<" Date = "<<current->date<<"\n"<<endl;
		cout << "Thanks for choosing us have a safe journey\n";
//		system("pause");
		
		q1.enqueue(id,current->destination,current->date,current->uname);
			deletebooking(id);
//			system("cls");
			system("pause");

	}
	void gethistory()
	{
		if(q1.isempty())
		{
			cout<<"No history available !\n";
			system("pause");
			return;
		}
		while(!q1.isempty())
		{
		q1.dequeue();
		}
		system("pause");
	}
};

int id = 0;
//f=global variable

int main()
{
	bookcancel obj;
	int n;
menu:
	system("cls");
	cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
	cout << "  ------------------- WELCOME -------------------  \t\t\t\n\n";
	cout << " 1.Registeration Center                                  \t\t\t\n";
	cout << " 2.Ticket Center                                        \t\t\t\n";
	cout << " 3.Take Flight                                           \t\t\t\n";
	cout << " 4.Exit                                                \t\t\t\n\n";
	cout << "Enter Your Choice( recommended: register yourself) = ";
	cin >> n;
	while (n < 0 || n > 4)
	{
		cout << "Please enter a valid choice!\n";
		cout << "Enter your choice = ";
		cin >> n;
	}
	// switch case for all scenarios
	switch (n)
	{
	case 1:
	{
	// registration label
	reg:
		system("cls");
		int c;
		cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
		cout << "  -----------  Registeration Centre -------------  \t\t\t\n\n";
		cout << "1.Register Yourself\n2.Delete Your Registration\n3.Show all Regitrstions\n4.Goto Main menu\n";
		cout << "\nEnter Your Choice = ";
		cin >> c;
		if (c == 1)
		{
			system("cls");
			cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
			cout << "  -----------  Registeration Yourself -------------  \t\t\t\n\n";
			int age;
			string name, address;
			id++;
			cout << "Enter Your Name = ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter your age = ";
			cin >> age;
			cout << "Enter Your Adress = ";
			cin.ignore();
			getline(cin, address);
			obj.regme(id, name, age, address);
			goto menu;
		}
		if (c == 2)
		{
			system("cls");
			cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
			cout << "  -----------  Delete Registration  -------------  \t\t\t\n\n";
			int delid;
			cout << "Enter the ID of the user you want to delete = ";
			cin >> delid;
			obj.deletereg(delid);
			goto reg;
		}
		if (c == 3)
		{
			system("cls");
			obj.displayreg();
			goto reg;
		}
		if (c == 4)
		{
			goto menu;
		}
		break;
	}
	case 2:
	{
	tick:
		system("cls");
		int c2;
		cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
		cout << "  --------------  Ticket  Centre ----------------  \t\t\t\n\n";
		cout << "1.Show Available Tickets\n2.Book A Ticket\n3.Cancel A Ticket\n4.Canceled Tickets\n5.GoTo Main Menu\n";
		cout << "\nEnter your choice = ";
		cin >> c2;
		if (c2 == 1)
		{
			system("cls");
			obj2.availabletickets();
			system("pause");
			goto tick;
		}
		else if (c2 == 2)
		{
			int nu;
			system("cls");
			cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
			cout << "  --------------  Ticket  Booking ---------------  \t\t\t\n\n";
			cout << "Enter registration ID = ";
			cin >> nu;
			if (obj.checkid(nu) == true)
			{
				if (obj.checkidbooking(nu) == false)
				{
					obj2.availabletickets();
					int num;
					cout << "Enter Ticket No = ";
					cin >> num;
					obj.bookthis(num, nu);
					goto menu;
				}
				else
				{
					cout << "Already booked!\n";
				}
			}
			else
			{
				cout << "Please register first !\n";
				system("pause");
				goto reg;
			}
			system("pause");
			goto tick;
		}
		else if (c2 == 3)
		{
			system("cls");
			cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
			cout << "  --------------  Ticket  Booking ---------------  \t\t\t\n\n";
			int ee;
			cout << "Enter Your Id = ";
			cin >> ee;
			if (obj.checkidbooking(ee) == true)
			{
				obj.deletebooking(ee);
				system("pause");
				goto menu;
			}
			else
			{
				cout << "Not boooked any ticket yet ";
				system("pause");
			}
			goto tick;
		}
		else if (c2 == 4)
		{
			system("cls");
			cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
			cout << "  --------------  Canceled Tickets ---------------  \t\t\t\n\n";
			if (s1.isempty())
			{
				cout << "No record\n";
			}
			else
			{
				obj.showcanceled();
			}
			system("pause");
			goto tick;
		}
		else if (c2 == 5)
		{
			goto menu;
		}
		break;
	}
	case 3:
	{
		take:
		system("cls");
		int c5;
		cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
		cout << "  --------------  Take Flight ---------------  \t\t\t\n\n";
		cout<<"1.Take Off\n2.Deparure History\n3.GoTo MainMenu\n\n";
		cout<<"Enter Your Choice = ";
		cin>>c5;
		if(c5==1)
		{
			system("cls");
		cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
		cout << "  --------------  Flights  Departue ----------------  \t\t\t\n\n";
				int eee;
		cout << "Enter Your Id = ";
		cin >> eee;
		if (obj.checkid(eee) == true && obj.checkidbooking(eee) == true)
		{
			obj.getflight(eee);
		}
		else
		{
			cout << "Book Your Ticket First !\n\n";
			system("pause");
						goto tick;

		}
		goto menu;
		}
		if(c5==2)
		{
			system("cls");
				cout << "  ================ UOG Airlines =================  \t\t\t\n\n";
		cout << "  --------------  Flight history ---------------  \t\t\t\n\n";
			obj.gethistory();
			goto menu;
		}
		if(c5==3)
		{
			goto menu;
		}
		break;
	}
	case 4:
	{
		cout << "Thanks for using program !";
		break;
	}
	}
	return 0;
}
