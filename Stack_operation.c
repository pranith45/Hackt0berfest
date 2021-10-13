/*  Akshay Jyani  */

/*  
	Que : we have available sequence of n element (1,2,3,4.....n)  and we want to produce an another sequenece from available sequence using 3 types of operation push,pop & stackTop

	INPUT FORMAT :
		int n (total number of element in array)
		provide n element
	
	OUTPUT :
		No : if it's not possible to produce given sequence from available sequence
		YES : if it's possible to produce given sequence from available sequence using push & pop operation 
		followed by operations taken place.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next ;
} ;

struct node *stack=NULL , *stack1=NULL ;

void push(struct node ** head , int val){
    struct node * tmp = (struct node *)malloc(sizeof(struct node)) ;
    tmp->data = val ;
    tmp->next = *head ;
    *head=tmp ;
}

int pop(){
    struct node *tmp=stack ;
    stack = stack->next ;
    return tmp->data ;
}

void insert_end(struct node ** head, int val){
    struct node *tmp=*head , *newnode =(struct node *) malloc(sizeof(struct node)) ;
    newnode->data= val ;
    newnode->next = NULL ;
    if (*head==NULL){
        *head=newnode ;
        return ;
    }
    while(tmp->next!=NULL){
        tmp=tmp->next ;
    }
    tmp->next = newnode ;
}

int main(){
    int n,x=0 ;
    scanf("%d",&n) ;
    int *seq=(int *)malloc(sizeof(int)*n)  ;
    for(int i=0 ; i<n ; i++) 
        scanf("%d",&seq[i]) ;

    int i=1 ;
    while(i<=n){
        if (stack==NULL || stack->data!=seq[x]) push(&stack,i) , insert_end(&stack1,i++) ; //push(&stack1,i++) ;
        while(stack!=NULL && stack->data==seq[x]){
            x++ ;
            insert_end(&stack1,-(pop())) ;
        }
    }
    if (stack!=NULL) printf("Not possible. \n") ;
    else {
        printf("Yes. It is possible by the following sequence of operations : \n") ;
        while(stack1->next!=NULL){
            if (stack1->data>0) printf("push(%d) , ",stack1->data) ;
            else printf("pop() , ") ;
            stack1 = stack1->next ;
        }
        printf("pop().") ;
    }
    free(stack) ;
    free(stack1) ;
    return 0 ;
}
