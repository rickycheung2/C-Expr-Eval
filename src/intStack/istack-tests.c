/*
 *  Integer Stack ADT: Basic Test Driver
 *
 *  Author:  Joseph Fall
 *  Date:    Mar. 6, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "istack.h"

//----- TEST DRIVER -----
int main( )
{
   int v;

   IntStack_t istack = istackCreate();
   assert(istackIsEmpty(istack));
   istackPush(&istack, 1);
   istackPush(&istack, 2);
   istackPush(&istack, 3);

   printf("\nStack:  ");
   istackPrint(istack);

   assert(!istackIsEmpty(istack));
   
   printf("Pop: %d\n", istackPop(&istack));
   
   istackPush(&istack, 99);
   istackPush(&istack, 98);
   istackPush(&istack, 97);

   printf("\nStack:  ");
   istackPrint(istack);

   assert(istackTop(istack) == 97);
   v = istackPop(&istack);
   assert(v == 97);
   printf("Pop: %d\n", v);

   assert(istackTop(istack) == 98);
   v = istackPop(&istack);
   assert(v == 98);
   printf("Pop: %d\n", v);

   printf("\nStack:  ");
   istackPrint(istack);

   istackDestroy(&istack);
}
