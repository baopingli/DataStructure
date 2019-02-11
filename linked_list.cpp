#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int da=0,Node *p=NULL){
			this->data=da;//初始化数据为0
			this->next=p;//这是单向链表
		}

};
class List{
	private:
		Node *head,*tail;//声明头和尾指针
		int position;
	public:
		List()
		{
			head=tail=NULL;
		};
		~List()//析构函数清理内存
		{
			delete head;
			delete tail;
		};
	void print();
	void Insert(int da=0);
	void Delete(int da=0);
	void Search(int da=0);
	int getValueAt(int position);
	void setValueAt(int position,int da);
	void setValueList(int position,int da);


};
int List::getValueAt(int position){
	Node *p=head;
	if(p==NULL)
	{
		cout<<"this list is empty!"<<endl;
		return 0;
	}
	else
	{
		int posi=0;
		while(p!=NULL&&posi!=position)
		{
			posi++;
			p=p->next;
		}
		if(p==NULL)
		{
			cout<<"there is no value of this position in the list"<<endl;
			
		}
		else
		{
			cout<<"in this position ,the value is "<<p->data<<endl;
		}
	}
	return p->data;
}
void List::setValueList(int position,int da)
{
	Node *p=head;
	if(p==NULL)
	{
		cout<<"this list is empty"<<endl;
		return;
	}
	else
	{
		int posi=0;
		while(p!=NULL&&posi!=position)
		{
			posi++;
			p=p->next;
		}
	}
	if(p==NULL)
	{
		cout<<"there is no position in the list"<<endl;
	}
	else
	{
		p->data=da;
		cout<<"the value in the position has been updated"<<endl;
	}

}
void List::Search(int da)
{
	Node *p=head;
	if(p==NULL)
	{
		cout<<"sorry,the list is empty"<<endl;
		return;
	}
	int count=0;
	while(p!=NULL&&p->data!=da)
	{
		p=p->next;
		count++;
	}
	
	cout<<"the value you want to search is at position %d"<<count<<endl;
}
void List::Delete(int da)
{
	Node *p=head,*q=head;
	if(p==NULL)
	{
		cout<<"ths list is empty"<<endl;
		return;
	}
	while(p!=NULL&&p->data!=da)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	cout<<"the deletion operation had been finished"<<endl;

}
void List::Insert(int da)
{
	if(head==NULL)
	{
		head=tail=new Node(da);
		head->next=NULL;
		tail->next=NULL;
	}
	else
	{
		Node *p=new Node(da);
		tail->next=p;
		tail=p;
		tail->next=NULL;
	}
}
void List::print()
{
	Node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"\a";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	List l1;
	l1.Insert(1);
	l1.Insert(2);
	l1.Insert(3);
	l1.print();	
	cout<<"hello world!"<<endl;
	return 0;
}
