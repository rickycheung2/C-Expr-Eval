/**
 *  Integer Stack ADT : public interface
 *    Choose your implementation of a stack
 *
 *  COMP220: Lab 7 Solution
 *  Original Author:  Joseph Fall 
 *  Modified by:  
 *  Date:    Mar. 6, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#include "istack.h"

/*******************
 * PRIVATE TYPE DECLARATION
 ********************/
/*
struct item_s {
	int data;
	struct item_s* next;    
} ;
typedef struct item_s Item;

struct IntStack_s {
	Item* top;
	int len;
} ;
typedef struct IntStack_s IntStack_t;
*/


Item* itemCreate( int value );



/*********************
 *  PUBLIC INTERFACE
 *********************/
 
/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( ){
    IntStack_t stk;
    stk.top = itemCreate(-404);
    stk.len = 0;
    return stk;
}

/*
 * Destructor - empty stack and free all associated memory
 */
void istackDestroy( IntStack_t *stack ){
	Item* cur = stack->top->next;
	while ( cur != NULL ){
	 	cur = cur->next;
	 	free(stack->top);
	 	stack->top = cur;
	 }
	 stack->len = 0;
 }

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  ){
	Item* cur = stack.top->next;
	printf("\n==Top of Stack==\n");
	while (cur != NULL ){
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	printf("==Bottom of Stack==\n");
} 

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty( IntStack_t stack ){
	if ( stack.len == 0 ){
		return true;
	}
	else {
		return false;
	}
}

/*
 * Return true iff the stack is full
 */
bool istackIsFull( IntStack_t stack ){
	return false;
}

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack ){
	assert(!istackIsEmpty(stack));
	return stack.top->next->data;
}

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack ){
	assert(!istackIsEmpty(*stack));
	Item* toDelete = stack->top->next;
	int top = toDelete->data;
	stack->top->next = toDelete->next;
	free(toDelete);
	stack->len -= 1;
	return top;
}

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item){
	Item* newItm = itemCreate(item);
	newItm->next = stack->top->next;
	stack->top->next = newItm;
	stack->len += 1;
	return istackTop(*stack);
}


Item* itemCreate( int value ){
	Item* itm = malloc(sizeof(Item));
	itm->data = value;
	itm->next = NULL;
	return itm;
}