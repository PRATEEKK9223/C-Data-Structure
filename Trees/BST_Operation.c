#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *rchild,*lchild;
};

typedef struct node TreeNode;

TreeNode* creatNode(int data)
{
    TreeNode *newnode;
    newnode=(TreeNode*)malloc(sizeof(TreeNode));
    newnode->data=data;
    newnode->lchild=newnode->rchild=0;
    return newnode;
}

TreeNode* insert(TreeNode *root,int data)
{
    TreeNode *newnode=creatNode(data);
    if(root==0)
        root=newnode;
    else if(data < root->data)
        root->lchild=insert(root->lchild,data);
    else
        root->rchild=insert(root->rchild,data);

    return root;
}

void Inorder(TreeNode *root)
{
    if(root==0)
        return;
    else{
        Inorder(root->lchild);
        printf("%d-",root->data);
        Inorder(root->rchild);
    }
}

void Preorder(TreeNode* root)
{
    if(root==0)
        return ;
    else{
        printf("%d-",root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}
void Postorder(TreeNode *root)
{
    if(root==0)
        return ;
    else{
        Postorder(root->lchild);
        Postorder(root->rchild);
        printf("%d-",root->data);
    }
}

int search(TreeNode *root,int key)
{
    if(root==0)
        return 0;
    else if(root->data==key)
        return 1;
    else if(key < root->data )
        search(root->lchild,key);
    else if(key > root->data)
        search(root->rchild,key);
}

int min(TreeNode *root)
{
    if(root==0)
        return 0;
    else{
        while(root->lchild!=0)
        {
            root=root->lchild;
        }
        return root->data;
    }
}
int max(TreeNode *root)
{
    if(root==0)
        return 0;
    else{
        while (root->rchild)
        {
            root=root->rchild;
        }
        return root->data;
        
    }
}



void main()
{
    TreeNode *root=NULL;
    int choice,data,ans;
    for(;;)
    {
        printf("\nenter your choice\n");
        printf("1-INSERT\n2-Inorder\n3-preorder\n4-postorder\n5-search\n6-minimum\n7-maximum\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the data\n");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            case 2:
                Inorder(root);
                break;
            case 3:
                Preorder(root);
                break;
            case 4:
                Postorder(root);
                break;
            case 5:
                printf("enter the key to search\n");
                scanf("%d",&data);
                ans=search(root,data);
                if(ans==1)
                    printf("is found\n");
                else    
                    printf("not found\n");
                break;
            case 6:
                printf("the minimum value is %d",min(root));
                break;
            case 7:
                printf("the maximum value is %d",max(root));

            case 8:
                exit(0);
            default :
                printf("invalid choice\n");
        }
    }
}