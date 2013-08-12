#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"



int main()
{
    Stack s = NULL;
    int i;
    int tmp;
    int toptmp;

    //makeEmpty(s);
    s = initStack();
    for(i = 0; i < 50; i++){
        push(i, s);
        toptmp = top(s);
        printf("%d    ", toptmp);
    }
    printf("\n");
    /* test makeEmpty(s)*/
    /*makeEmpty(s);
    if(isEmpty(s)){
        printf("makeEmpty works!\n");
    }
    else{
        printf("makeEmpty doesnot work!\n");
    }
    */

    /*test pop(s)*/
    /**/
    for(i = 0; i < 50; i++){
        tmp = pop(s);
        printf("%d    ", tmp);
    }


    /*test disposeStack*/
    /*s = NULL;
    disposeStack(s);
    */

    disposeStack(s);

    return 0;
}

