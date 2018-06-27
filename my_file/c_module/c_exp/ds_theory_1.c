#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int info;
	struct node * link;
	}NODE;

NODE* insert_node(int ,NODE*,NODE*,NODE*);
NODE* create_node(NODE*);

int main(void)
{
	char * buf = NULL;
	NODE * head = NULL;
	NODE* cur = NULL;
	NODE* next = NULL;
	NODE* temp = NULL;
	int n;
	int i;

	buf = (char *)malloc(sizeof(char)*10);
	head = (NODE*) malloc(sizeof(NODE)*255);
	cur = (NODE*) malloc(sizeof(NODE)*255);
	next = (NODE*) malloc(sizeof(NODE)*255);
	temp = (NODE*) malloc(sizeof(NODE)*255);

	printf("Enter the nor of elements\n");
	fgets(buf , 255,stdin);
	n= atoi(buf);

	printf("PID = %d\n",getpid());
	getchar();

		while(n-- > 0){
		if (cur == NULL){
			cur = create_node(cur);
			head = cur;
		}
	
	/*	else if(cur != NULL){
			next = create_node(temp);
			next = temp;
			cur->link = next;
		}*/
	}

	printf("Insert a new node\n");
	temp = insert_node(n,cur,next,head);

	printf("newly inserted node is  at %p with value %d\n",temp->link,temp->info);
	cur = head;
	printf("Elements in sorted array are\n");
	for( i = 0; i < n+1; i++){
		printf("%d\t",cur->info);
		cur = cur->link;
		}
	return 0;
}



NODE* insert_node(int n, NODE* cur, NODE* next, NODE* head)
{
	NODE * new = NULL;
	int i =0;

	new = (NODE*)malloc(sizeof(NODE)*255);

	new = create_node(new);
	
	while(i < n){
		if(new->info < cur->info){
			new->link = cur;
			head = new;
		}
		else if((new->info > cur->info) && (new->info < next->info)){
            cur->link = new;
            new->link = next;
        }
		else if((new->info > next->info)&&(next->link == NULL)){
            next->link = new;
            new->link= NULL;
        }

		cur = cur->link;
		next = next->link;
	}	
	return new;
}

NODE * create_node(NODE* new)
{
	char * buf = NULL;
	int ele;
	
	printf("Enter the node element\n");
	fgets(buf , 255,stdin);
	ele = atoi(buf);

	new->info = ele;
	new->link = NULL;

	return new;
}































