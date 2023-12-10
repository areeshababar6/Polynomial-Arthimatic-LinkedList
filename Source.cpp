#include<iostream>
using namespace std;


/*		Polynomial Arthimatic:
	The word Polynomial comes from poly which means many and nomial which means terms.
	Each term has a co-efficient and exponent. 

	It's represented by singly linked list
	
	| 5 | 3 | 200 |---->| -3 | 2 | 300 |---->| 2 | 1 | 400 |---->| 1 | 0 | NULL |
	  || 
      \/
	  head

	  5x^3 - 3x^2 + 2x + 1

*/

struct node
{
	float coeff;
	int expo;
	node *link;
};

node *insert(node *head, float co, int ex)
{
	node *temp;
	node *pnew = (node *)malloc(sizeof(node));
	pnew->coeff = co;
	pnew->expo = ex;
	pnew->link = NULL;
	
	if (head == NULL || ex > head->expo)
	{
		pnew->link = head;
		head = pnew;
	}
	else
	{
		temp = head;
		while (temp->link != NULL && temp->link->expo >= ex)
		{
			temp = temp->link;
		}
		pnew->link = temp->link;
		temp->link = pnew;
	}
	return head;
}

node *create_node(node *head)
{
	int n, i;
	float coeff;
	int expo;

	cout << "Enter the number of trem : " ;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Enter the Co-efficient for the term " << i + 1 << " : ";
		cin >> coeff;

		cout << "Enter the Exponent for term " << i + 1 << " : ";
		cin >> expo;

		head = insert(head , coeff, expo);
	}
	return head;
}

void print(node *head)
{
	if (head == NULL)
	{
		cout << "NO POLYNOMIAL !";
	}
	else
	{
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->coeff <<".0x^" << temp->expo;
			temp = temp->link;

			if (temp != NULL)
				cout << " + ";
			else
				cout << endl;
		}
	}
}

int main()
{
	node *head = NULL;
	cout << "Enter the Polynomial !" << endl;
	head = create_node(head);
	print(head);

	return 0;
}
