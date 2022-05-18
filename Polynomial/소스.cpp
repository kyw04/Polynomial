#include <iostream>
using namespace std;

typedef struct _node
{
	int degree;
	double coef;
	struct _node *next;
} node;

node *make_node(int degree, double coef);
void insert_node(node *head, int degree, double coef);

int main()
{
	node *head = make_node(NULL, NULL);
	
	insert_node(head, 1, 2);
	insert_node(head, 1, 5);
	insert_node(head, 2, 1);
	insert_node(head, 1, 4);
	insert_node(head, 3, 2);
	insert_node(head, 4, -2);
	insert_node(head, 5, 2);
	insert_node(head, 6, 1);

	node* move = head;
	while (move->next)
	{
		if (move->next->coef > 0 && move != head)
			cout << "+";
		cout << move->next->coef << "X^" << move->next->degree;
		move = move->next;
	}

	return 0;
}

node *make_node(int degree, double coef)
{
	node *newNode = new node;
	newNode->degree = degree;
	newNode->coef = coef;
	newNode->next = NULL;
	return newNode;
}

void insert_node(node *head, int degree, double coef)
{
	node *move, *newNode;
	if (coef == 0) return;
	newNode = make_node(degree, coef);
	move = head;
	while (true)
	{
		if (!move->next)
		{
			move->next = newNode;
			break;
		}
		else if (move->next->degree == degree)
		{
			move->next->coef += coef;
			delete(newNode);
			break;
		}
		else if (move->degree > degree)
		{
			newNode->next = move->next;
			move->next = newNode;
			break;
		}
		else
			move = move->next;
	}
}