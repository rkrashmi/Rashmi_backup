#include "header.h"

void fwd_display (struct master *mhead, int pos)
{
	int count = 1;
	struct master *mtemp = mhead;
	struct node *head = NULL;
	struct node *temp = NULL;

	while (count < pos) {
		count++;
		mtemp = mtemp -> mnext;
	}
	head = mtemp -> addr;
	temp = head;

	do {
		printf ("%d\t", temp -> info);
		temp = temp -> next;
	}while (temp != head);
	printf ("\n");
}
