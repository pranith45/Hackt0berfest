/* 
  Input: 
    provide only BST root pointer
    
   you can get Preorder sequence of BST using Recursive and Non Recursive approach
    
    
typedef struct bst{
    int data ;
    struct bst *left ;
    struct bst *right ;
}Bst ;  
    
*/

void preorder_nonr(Bst* ptr){
    Bst* curr=ptr ;
    struct NODE * stack=(struct NODE * )malloc(sizeof(struct NODE)) ;
    stack->tnd = ptr ;
    stack->next = NULL ;
    while(!isempty(stack) && curr!=NULL){
        printf("%d ",curr->data) ;
        stack=pop(stack) ;
        if (curr->right) stack=push(stack,curr->right) ;
        if (curr->left) stack=push(stack,curr->left) ;
        if (!isempty(stack)) curr = stack->tnd ;
    }
    printf("\n") ;
}

void preorder_recursive(struct bst* root1){
    if (root1==NULL) return ;
    printf("%d ",root1->data) ;
    preorder(root1->left) ;
    preorder(root1->right) ;
}
