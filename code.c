#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* link;
} *start;

void create_list(int);
struct node* reverse(struct node*, struct node*);
void display(int);

int main()
{
	start = NULL;
	int nodes;
	printf("Enter the number of nodes : ");
	scanf("%d", &nodes);
	int data;
	printf("Enter the data : ");
	for (size_t i = 0; i < nodes; i++)
	{
		scanf("%d", &data);
		create_list(data);
	}

	struct node* q;
	q = start;
	int index = 0;
	do
	{
		struct node* beg, * end;
		if (q->info < q->link->info)
		{
			beg = q;
			while (q->info < q->link->info)
			{
				q = q->link;
				if (q->link == NULL)
				{
					struct node* tmp = (struct node*)malloc(sizeof(struct node));
					tmp->info = q->info - 1;
					tmp->link = NULL;
					q->link = tmp;
					index++;
				}
			}
			end = q;
			q = reverse(beg, q);
			q = q->link;
		}
		else if (q->info > q->link->info)
		{
			beg = q;
			while (q->info > q->link->info)
			{
				q = q->link;
				if (q->link == NULL)
				{
					struct node* tmp = (struct node*)malloc(sizeof(struct node));
					tmp->info = q->info + 1;
					tmp->link = NULL;
					q->link = tmp;
					index++;
				}
			}
			end = q;
			q = reverse(beg, q);
			q = q->link;
		}
		else
			q = q->link;
		if (index > 0)
			break;
	} while (q->link != NULL);
	display(nodes);
}

void create_list(int data)
{
	struct node* tmp, * q;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = NULL;
	if (start == NULL)
		start = tmp;
	else
	{
		q = start;
		while (q->link != NULL)
			q = q->link;
		q->link = tmp;
	}
}

struct node* reverse(struct node* beg, struct node* end)
{
	struct node* head;
	if (start == beg)
	{
		head = beg;
		while (beg->info != end->info)
		{
			struct node* index = head->link->link;
			head->link->link = beg;
			start = head->link;
			beg = head->link;
			head->link = index;
		}
		end = head;
	}
	else
	{
		struct node* q = start;
		while (q->link != beg)
			q = q->link;
		head = q->link;
		while (beg->info != end->info)
		{
			struct node* index = head->link->link;
			head->link->link = beg;
			beg = head->link;
			head->link = index;
			q->link = beg;
		}
		end = head;
	}
	return end;
}

void display(int nodes)
{
	struct node* q;
	if (start == NULL)
		printf("Empty!");
	else
	{
		q = start;
		for (size_t i = 0; i < nodes; i++)
		{
			printf("%d -> ", q->info);
			q = q->link;
		}
	}
}
