#include <iostream>
using namespace std;

struct Queue
{
	int front, rear, size;
	int capacity;
	int* array;
};

// function to create a queue of given capacity.
// It initializes size of queue as 0
Queue* CreateQueue(int capacity)
{
	Queue* queue = new Queue;
	queue->capacity = capacity;
	queue->front =0;
	queue->size = 0;
	queue->rear = capacity-1; // This is important, see the enqueue
	queue->array = new int[queue->capacity];
	return queue;
}

// Queue is full when size becomes equal to the capacity
//Overflow when size is equal with capacity
int isFull(Queue* queue){
    return (queue->size == queue->capacity); // this return true or false
}

// Queue is empty when size is 0
// Underflow when queue is -1
int isEmpty(Queue* queue){
    return (queue->size == 0); //this return true or false
}

// Function to add an item to the queue.
// It changes rear and size
void Enqueue(Queue* queue, int item_to_add)
{
	if (isFull(queue)==true){
       cout<<"Overflow"<<endl;
       return;
	}

	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = item_to_add;
	queue->size = queue->size + 1;
	cout<<"["<<queue->rear<<"]->";
	printf("%d enqueued to queue\n", item_to_add);
}

// Function to remove an item from queue.
// It changes front and size
int Dequeue(struct Queue* queue)
{
	if (isEmpty(queue)==true){
		cout<<"Underflow"<<endl;
		return INT_MIN;
		}
    cout<<"["<<queue->front<<"]->";
	int item_to_remove = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size = queue->size - 1;
	return item_to_remove;
}

// Function to get front of queue
int Front(Queue* queue)
{
	if (isEmpty(queue)==true)
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int Rear(struct Queue* queue)
{
	if (isEmpty(queue)==true)
		return INT_MIN;
	return queue->array[queue->rear];
}

int main()
{
	Queue* queue = CreateQueue(5);

	Enqueue(queue, 8);
	Enqueue(queue, 10);
	Enqueue(queue, 600);
	Enqueue(queue, 56);
	Enqueue(queue, 1);
	cout<<"First element:"<<Front(queue)<<endl;
	cout<<"Last element:"<<Rear(queue);
	cout<<"\n";
	cout<<Dequeue(queue)<<" Dequeue to the queue"<<endl;
	cout<<Dequeue(queue)<<" Dequeue to the queue"<<endl;
	cout<<Dequeue(queue)<<" Dequeue to the queue"<<endl;
	cout<<Dequeue(queue)<<" Dequeue to the queue"<<endl;
	cout<<Dequeue(queue)<<" Dequeue to the queue";


	return 0;
}
