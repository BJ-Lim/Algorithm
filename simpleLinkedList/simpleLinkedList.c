/*
 	Insert is automatically sorted to ascending power.
 */
typedef struct Node {
	char data;
	struct Node *next;
}Node;

void insertNode(Node **head, char data){
	Node *i = *head;
	Node *temp = malloc(sizeof(Node));

	temp->data = data;
	temp->next = NULL;

	if(i == NULL){
		*head = temp;
		return;
	}

	if( i->data > temp->data ){
		temp->next = i;
		*head = temp;
		return;
	}

	while( i->next != NULL){
		if(temp->data < i->next->data){	
			temp->next = i->next;
			i->next = temp;
			return;
		}
		i = i->next;
	}
	i->next = temp;
}

void deleteNode(Node **head, char data){
	Node * i = *head;
	Node * t;

	if(i == NULL)
		return;

	if(i->data == data){
		*head = i->next;
		return;
	}

	while(i->next){
		if( i->next->data == data ){
			t = i->next;
			i->next = i->next->next;
			free(t);
			return;
		}
		i = i->next;
	}

	if(i->data == data){
		t = i;
		i = NULL;
		free(t);
	}
}

void printNode(Node **head){
	Node *i = *head;

	while(i){
		printf("%c\n", i->data);
		i = i->next;
	}
}

void freeNode(Node **head){
	Node *i = *head;
	Node *c;

	while(i){
		c = i;
		i = i->next;
		free(c);
	}
}
