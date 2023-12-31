#include<iostream.h>

#define MAX 5

class circularQueue
{
    private: int cq[MAX];
             int front;
             int rear;
    public:  circularQueue();
             void enqueue(int order_id);
             int dequeue();
             void display();
};

circularQueue::circularQueue()
{
    front= rear = -1;
    for(int i=0;i<MAX;i++)
        cq[i]=0;
}

void circularQueue::enqueue(int order_id)
{
   if( (front == rear+1) || (front==0 && rear== MAX-1) )
   {
       cout<<"\n Queue is Overflow!!";
       return;
   }
   if(front == -1)
      front=0;

   if(rear == MAX-1 && front !=0)
      rear=0;
   else
      rear=rear+1;

   cq[rear]=order_id;
}

void circularQueue::display()
{
    if(front == -1)
    {
        cout<<"\n queue is underflow!!";
        return;
    }

    if(front<=rear)
    {
        for(int i=front; i<=rear; i++)
            cout<<"\t "<<cq[i];
    }
    else
    {
        for(int i=front ; i<MAX; i++)
            cout<<"\t "<<cq[i];
	for(i=0; i<=rear; i++)
            cout<<"\t "<<cq[i];
    }
}


int circularQueue::dequeue()
{
    if( front == -1)
    {
        cout<<"\n Queue is Empty !!No order to serve";
        return -1;
    }

    int x=cq[front];
    if(front == rear )       //if front and rear pointing to same element; if only one element
         front= rear=-1;

    else if( front ==MAX-1)  /*set front pointer to 0*/
         front = 0;
    else
        front= front +1;     /*Increment front pointer*/
    return x;
}

int main()
{

   circularQueue q;
   int id;
   int ch;
   do
	{
		cout<<"\n\t\t\t1 : Place pizza order ";
		cout<<"\n\t\t\t2 : Serve Order ";
		cout<<"\n\t\t\t3 : Display";
		cout<<"\n\t\t\t4 : Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : cout<<"\nEnter pizza order ID : ";
					 cin>>id;
					 q.enqueue(id);
					 break;

			case 2 : cout<<"\n Order served (ID) : "<<q.dequeue();
			         break;

            case 3 : cout<<"\n Pizza Order Queue : ";
                     q.display();
                     break;

            case 4:  cout<<"\n End of Program !!";
                     break;

            default: cout<<"\n Invalid Choice !!";
		}
	}while(ch!=4);

 return (0);
}


















