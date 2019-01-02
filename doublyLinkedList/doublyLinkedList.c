struct node{
	char data;
	struct node * pre;
	struct node * next;
};

typedef struct node Node;

/*
   Because of NULL and head, we will device cases.
   case1) insert to empty list
   case2) insert to front of the list( It makes head to move )
   case3) insert to mid of the list
   case4) insert to end of the list
 */
void insertNode(Node **head, char data){
	Node *i = *head;
	Node *t = (Node*)malloc(sizeof(Node));

	t->data = data;			//set a new Node
	t->pre = NULL;		
	t->next = NULL;

	if( *head == NULL){		//case1
		*head = t;
		return;
	}

	if( i->data > t->data ){ //case2 : need to move head
		t->next = i;
		i->pre = t;
		*head = t;
		return;
	}

	while( i->next != NULL){	//case3
		i = i->next;
		if( i->data > t->data){
			t->next = i;
			t->pre = i->pre;
			i->pre->next = t;
			i->pre = t;
			return;
		}
	}

	t->pre = i;					//case4
	i->next = t;
}

void deleteNode(Node **head, char data){
	Node *i = *head;

	if ( *head == NULL )
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
	} while( i != *head );
}

void printNode(Node **head){
	Node *i = *head;

	if( *head == NULL)
		return;

	do{
		printf("%c\n", i->data);
		i = i->next;
	} while(i != NULL);
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
