#include<stdio.h>
#include<stdlib.h>
#define max 10
int insq(int cqueue[max], int *front, int *rear, int *data)
{
      if((*rear + 1) % max == *front)
            return(-1);
      else
      {
            *rear = (*rear + 1) % max;
            cqueue[*rear] = *data;
            return(1);
      }
}
int delq(int cqueue[max], int *front, int *rear, int *data)
{
      if(*front == *rear)
            return(-1);
      else
      {
            *front = (*front + 1) % max;
            *data = cqueue[*front];
            return(1);
      }
}
int main()
{

      int cqueue[max], data;
      int front, rear, reply,ch;
      front = rear = 0; //... Initialize Circular Queue
      printf("-------------------------------------\n");
      printf("\tMenu");
      printf("\n------------------------------------");
      printf("\n 1. Insert number in a Circular Queue");
      printf("\n 2 .Delete number from Circular Queue");
      printf("\n 3. Exit \n");
      printf("------------------------------------\n");
      while(1)
      {
            printf("Choose operation : ");
            scanf("%d", &ch);
            switch(ch)
            {
                  case 1 : // insert
                        printf("\nEnter number: ");
                        scanf("%d", &data);
                        reply = insq(cqueue, &front, &rear, &data);
                        if(reply == -1)
                              printf("\nCircular Queue is Full \n");
                        else
                              printf("%d is inserted in a Circular Queue\n\n", data);
                        break;
                  case 2 : // delete
                        reply = delq(cqueue, &front, &rear,&data);
                        if(reply == -1)
                              printf("\n Circular Queue is Empty \n");
                        else
                              printf("\n %d is deleted from Circular Queue \n", data);
                        printf("\n");
                        break;
                  case 3 : exit(0);
                  default: printf("Invalid operation \n");
    }
}
}