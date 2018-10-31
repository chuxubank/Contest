#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int real;
	int imaginary;
	Node *next;
	Node() {}
	Node(int r, int i)
		: real(r), imaginary(i) {}
};

class List
{
  private:
	Node *head, *tail;

  protected:
	void init();

  public:
	List() { init(); }
	void insert(int real, int imaginary);
	void print_sum();
};

void List::init()
{
	head = new Node();
	tail = head;
	tail->next = NULL;
}

void List::insert(int real, int imaginary)
{
	Node *p = new Node(real, imaginary);
	tail->next = p;
	tail = p;
	tail->next = NULL;
}

void List::print_sum()
{
	int real_sum = 0, imag_sum = 0;
	Node *p = head->next;
	while (p)
	{
		real_sum += p->real;
		imag_sum += p->imaginary;
		p = p->next;
	}
	cout << real_sum << "+" << imag_sum << "i" << endl;
}

int main()
{
	List list;
	int real, imaginary;
	for (int i = 0; i < 10; i++)
	{
		cin >> real >> imaginary;
		list.insert(real, imaginary);
	}
	list.print_sum();
	return 0;
}