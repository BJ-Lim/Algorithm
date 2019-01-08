#define QUEUE_SIZE 100
#define TYPE int

TYPE queue[QUEUE_SIZE];
int front = 0;	//add to this
int back = 0;	//pop to this

void enqueue(TYPE value){
	if ((front + 1) % QUEUE_SIZE != back){
		queue[front++] = value;
		front %= QUEUE_SIZE;
	} else {
		printf("queue is overflow!\n");
	}
}

TYPE dequeue(){
	back %= QUEUE_SIZE;
	if( front == back ){
		printf("queue is empty!");
		return -1;	//this value will be changed when TYPE is changed.
	} else {
		return queue[back++];
	}
}
