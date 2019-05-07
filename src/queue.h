#ifndef QUEUE
#define QUEUE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct t_queue{
  int size, head, tail;
  int *datavec;
} Queue;

Queue *q_init(int);
void q_free(Queue*);
int q_length(Queue*);
bool enqueue(Queue*, int);
int dequeue(Queue*);
void printqueue(Queue*);
void q_error();

Queue *q_init(int size){
  Queue *q = (Queue*)malloc(sizeof(Queue));
  if(q == NULL) q_error();

  q->size = size;
  q->datavec = (int*)malloc(sizeof(int) * (size+1));
  if(q->datavec == NULL) q_error();
  q->head = q->tail = 0;
  return q;
}

void q_free(Queue *q){
  free(q->datavec);
  free(q);
}

int q_length(Queue *q){
  // mod((head-tail) % (size+1))
  return (q->size+1+q->head-q->tail) % (q->size+1);
}

bool enqueue(Queue *q, int data){
  if((q->head+1) % (q->size+1) == q->tail) return false;

  q->datavec[q->head] = data;
  q->head++;
  q->head %= (q->size+1);
  return true;
}

int dequeue(Queue *q){
  int ret;
  if(q->head == q->tail){
    fprintf(stderr, "err: queue is empty.\n");
    exit(1);
  }
  ret = q->datavec[q->tail];
  q->tail++;
  q->tail %= (q->size+1);
  return ret;
}

void printqueue(Queue *q){
  putc('[', stdout);
  if(q->head != q->tail){
    printf("%d", q->datavec[(q->head+q->size) % (q->size+1)]);
    for(int i=(q->head+q->size) % (q->size+1); i!=q->tail; i=(q->size+i) % (q->size+1)){
      printf(", %d", q->datavec[(i+q->size) % (q->size+1)]);
    }
  }
  printf("]\n");
}

void q_error(){
  fprintf(stderr, " %s(%d)", strerror(errno), errno);
  exit(1);
}
#endif
