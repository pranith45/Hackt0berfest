/* 
  Input: 
    provide only BST root pointer
    
    you can get Postorder sequence of BST using Recursive and Non Recursive approach
    
    
typedef struct bst{
    int data ;
    struct bst *left ;
    struct bst *right ;
}Bst ;  
    
*/

void postorder_nonr(Bst *ptr){
    if (ptr==NULL){ printf("\n") ; return ; }
    Bst *curr=ptr ;
    struct NODE* stack=(struct NODE * )malloc(sizeof(struct NODE)) , *stack1=NULL ;
    stack->tnd=curr ;
    stack->next=NULL ;
    while(!isempty(stack)){
        stack1=push(stack1,stack->tnd) ;
        stack=pop(stack) ;
        if (stack1->tnd->left) { stack=push(stack,stack1->tnd->left) ;} //printf("%c 2 ",stack1->tnd->left->data) ;}
        if (stack1->tnd->right) { stack=push(stack,stack1->tnd->right) ; } //printf("%c 1 ",stack1->tnd->right->data) ;}
    }
    while(stack1!=NULL){
        printf("%d ",stack1->tnd->data) ;
        stack1=stack1->next ;
    }
    printf("\n") ;
}

void postorder_recursive(struct bst* root1){
    if (root1==NULL) return ;
    postorder(root1->left) ;
    postorder(root1->right) ;
    printf("%d ",root1->data) ;
}
