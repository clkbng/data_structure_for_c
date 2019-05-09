#ifndef STACK
#define STACK
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct t_stack{
	int size, top;
	int *datavec;
} Stack;

Stack *initStack(int);
void freeStack(Stack*);
int stackLength(Stack*);
bool push(Stack*, int);
int pop(Stack*);
void printStack(Stack*);
void errorStack();

Stack *initStack(int size){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL) errorStack();

	s->size = size;
	s->datavec = (int*)malloc(sizeof(int) * size);
	if(s->datavec == NULL) errorStack();
	s->top = 0;
	return s;
}

void freeStack(Stack *s){
	free(s->datavec);
	free(s);
}

int stackLength(Stack *s){
	return s->top;
}

bool push(Stack *s, int data){
	if(s->size == s->top) return false;

	s->datavec[s->top++] = data;
	return true;
}

int pop(Stack *s){
	if(!(s->top)){
		fprintf(stderr, "err: stack is empty.\n");
		exit(1);
	}
	// s->top--;
	return s->datavec[--s->top];
}

void printStack(Stack *s){
	putc('[', stdout);
	if(s->top){
		printf("%d", s->datavec[s->top-1]);
		for(int i= s->top - 2; i >= 0; i--){
			printf(", %d", s->datavec[i]);
		}
	}
	printf("]\n");
}

void errorStack(){
	fprintf(stderr, " %s(%d)", strerror(errno), errno);
	exit(1);
}
#endif
