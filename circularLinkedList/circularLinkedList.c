struct node{
	char data;
	struct node * pre;
	struct node * next;
};

typedef struct node Node;

void insertNode(Node **head, char data){
	Node *i = *head;
	Node *t = (Node*)malloc(sizeof(Node));
	
	t->data = data;
	t->pre = t;		
	t->next = t;

	if( *head == NULL){
		*head = t;
		return;
	}

	do{
		if( i->data > t->data ){
			t->next = i;
			t->pre = i->pre;
			i->pre->next = t;
			i->pre = t;

			if( i->data > i->next->data )
				*head = i->next;
			return;
		}

		i = i->next;
	} while( i != *head);

	t->pre = i->pre;
	t->next = i;
	i->pre->next = t;
	i->pre = t;
}

void deleteNode(Node **head, char data){
	Node *i = *head;

	if( *head == NULL)
		return;

	do{
		if( i->data == data){
			if(i->next == i)
				*head = NULL;
			i->pre->next = i->next;
			i->next->pre = i->pre;

			if(*head == i)
				*head = i->next;
			

			free(i);

			return;
		}
		i = i->next;
	} while( i != *head);
}

void printNode(Node **head){
	Node *i = *head;

	if( *head == NULL)
		return;

	do{
		printf("%c\n", i->data);
		i = i->next;
	} while(i != *head);
}

void freeNode(Node **head){
	Node *i = *head;
	Node *t;

	if( *head == NULL)
		return;

	while( i != *head ){
		t = i;
		i = i->next;
		free(t);
	}
}
