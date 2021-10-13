/* 
  Input: 
    provide only BST root pointer
    
    you can get Inorder sequence of BST using Recursive and Non Recursive approach
    
    
typedef struct bst{
    int data ;
    struct bst *left ;
    struct bst *right ;
}Bst ;  
    
*/

void inorder_nonr(Bst * ptr){
    Bst * curr = ptr ;
    struct NODE * stack = NULL ;
    while(curr!=NULL || !isempty(stack)){
        while (curr!=NULL){
            stack=push(stack,curr) ;
            curr = curr->left ;
        }
        curr=stack->tnd ;
        printf("%d ",curr->data) ;
        stack = pop(stack) ;
        curr = curr->right ;
    }
    printf("\n") ;
}

void inorder_recursive(struct bst* root1){
    if (root1==NULL) return ;
    inorder(root1->left) ;
    printf("%d ", root1->data) ;
    inorder(root1->right) ;
}
