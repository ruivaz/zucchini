#include <stdio.h>
#include "btree.h"
#include <stdlib.h>

/*
 * Return true if value exists in binary search tree
 *
 * */


node_t* newNode(int value){
        node_t *node = malloc(sizeof(node_t));
        node->value=value;
        node->left=NULL;
        node->right=NULL;

        return node;
}


int  searchValue(node_t *root, int value){
	
	//Return false if target is not found
	if(root==NULL)
		return -1;
	else{ 
		if (value == root->value){
			return 0;
		}
		else{
			if(value<root->value)
				return(searchValue(root->left, value));	
			else
				return(searchValue(root->right, value));
		}
		
	}			
}

node_t* insertNode(node_t *root, int value){

	if(root==NULL){
		return newNode(value);
	} 
		
	else{
		if(value>root->value)
			root->right= insertNode(root->right, value);
		else
			root->left= insertNode(root->left, value);
		return(root);
	}
}

node_t* build1231(){

node_t *node1 = newNode(1);
node_t *root = newNode(2);
node_t *node3 = newNode(3);

root->left=node1;
root->right=node3;

return root;

}

node_t* build1232(){
node_t *root = newNode(2);
root->left = newNode(1);
root->right= newNode(3);

return root;	
}

node_t* build1234(){
node_t *root=NULL;
root=insertNode(root,4);
root=insertNode(root,2);
root=insertNode(root,1);
root=insertNode(root,3);
root=insertNode(root,6);
//root=insertNode(root,16);
////root=insertNode(root,20);
////root=insertNode(root,21);
////root=insertNode(root,17);
////root=insertNode(root,18);
////root=insertNode(root,19);
////root=insertNode(root,4);
////root=insertNode(root,3);
////root=insertNode(root,2);
////root=insertNode(root,1);
//
//
//
return root;
//}
//
}
node_t* build1233(){
node_t *root=NULL;
root=insertNode(root,4);
root=insertNode(root,2);
root=insertNode(root,1);
root=insertNode(root,3);
root=insertNode(root,5);
//root=insertNode(root,16);
//root=insertNode(root,20);
//root=insertNode(root,21);
//root=insertNode(root,17);
//root=insertNode(root,18);
//root=insertNode(root,19);
//root=insertNode(root,4);
//root=insertNode(root,3);
//root=insertNode(root,2);
//root=insertNode(root,1);



return root;
}

int size(node_t *root){
	if(root==NULL)
		return 0;
	else
		return 1+size(root->left)+size(root->right);
}


int max(int a, int b){
	return a>b ? a:b;
}

int maxDepth(node_t *root){
	if(root==NULL)
		return 0;
	else
		return max((1+maxDepth(root->right)), (1+maxDepth(root->left)));		
		
}

int minValue(node_t *root){
	if(root->left==NULL)
		return root->value;
	else{
		while(root->left!=NULL){
			root=root->left;	
		}
		return root->value;
	}
}


int minValue1(node_t *root){
	if(root->left==NULL)
		return root->value;
	else
		return minValue1(root->left);
}

void printTree1(node_t *root){
	if(root==NULL)
		return;
	
	printTree1(root->left);
	printf("%d ", root->value);
	printTree1(root->right);
	
}

void printTree2(node_t *root){
	if(root==NULL)
		return;
	else{
	printTree2(root->left);
	printTree2(root->right);
	printf("%d ",root->value);
	}
}


void printTree3(node_t *root){
        if(root==NULL)
                return;
        else{
        printf("%d ",root->value);
	printTree3(root->left);
        printTree3(root->right);
        }
}

int hasSumPath(node_t *root, int sum){
	int a=1;
	if(root==NULL)
		return -1;
	else {
		if((root->left==NULL) && (root->right==NULL) && (sum-root->value==0)){
			return 0;
		}
		else{
			a=a*hasSumPath(root->left, sum-root->value);
			a=a*hasSumPath(root->right, sum-root->value);	
		
		}
	}	
	return a;
}

int hasSumPath1(node_t *root, int sum){
	if(root==NULL)
		return(sum==0);
	else{  
		int subSum=sum-root->value;
		return(hasSumPath1(root->left, subSum)||hasSumPath1(root->right, subSum));
		
	}
}


int hasPathSum2(node_t *root, int sum) { 
  // return true if we run out of tree and sum==0 
     if (root == NULL) { 
         return(sum == 0); 
     } 
     else { 
           // otherwise check both subtrees 
           int subSum = sum - root->value; 
           return(hasPathSum2(root->left, subSum) || 
           hasPathSum2(root->right, subSum)); 
     } 
       
} 

void printPathsRecur(node_t *node, int path[], int pathLen){
        if(node->left==NULL && node->right==NULL){
               int i;
	       path[pathLen]=node->value;
	       pathLen+=1;	
               printf("Path: ");
               for(i=0;i<pathLen;i++){
                       printf("%d ",path[i]);
	       }
	       return;
        }
	else{
		path[pathLen]=node->value;
		pathLen+=1;
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

void printPaths(node_t *root) {
	int pathLen=0;
	int path[500];

	if(root==NULL)
		return;
	else
		printPathsRecur(root, path, pathLen);
}

                                   
void mirror(node_t *root){
	node_t *helper=NULL;
	if(root->left==NULL && root->right==NULL)
		return;
	
	helper=root->right;
	root->right=root->left;
	root->left=helper;
	mirror(root->right);
	mirror(root->left);
	
}


void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
}

void printPathsRecur1(node_t* node, int path[], int pathLen) { 
  if (node==NULL) return;

  path[pathLen] = node->value; 
  pathLen++; 
  if (node->left==NULL && node->right==NULL) { 
    printArray(path, pathLen); 
  } 
  else { 
    printPathsRecur1(node->left, path, pathLen); 
    printPathsRecur1(node->right, path, pathLen); 
  } 
} 

void printPaths1(node_t* node) {
  int path[1000];
  printPathsRecur1(node, path, 0);
}





void doubleTree(node_t *root)
{
	if(root==NULL)
		return;
	
	doubleTree(root->left);
	doubleTree(root->right);
	//printf("A: %d \n", root->value );
	node_t *helper = NULL;
	helper = root->left;
		//printf("Left Value: %d\n", helper->value);
	root->left = newNode(root->value);
		//printf("New Left Value: %d\n", root->left->value);
        root->left->left = helper;
		//printf("New Left Left Value: %d\n", root->left->left->value);
}

int sameTree(node_t *root, node_t *second ){
	if(root==NULL && second==NULL)
		return(1);

        else if(root!=NULL && second!=NULL){
		printf("Second Value %d\n", second->value);
		printf("Root value %d\n", root->value);
		return(root->value==second->value &&
		       sameTree(root->left, second->left) &&
		       sameTree(root->right, second->right));
	}
	else 
		return(0);
}

int main(){
	node_t *root=NULL;
	node_t *second=NULL;
	root=build1233();
	second=build1234();
	printf("Valueof Root: %d \n",root->value);
	printf("Size of Tree: %d \n", size(root));
	printf("Max Depth of Tree: %d \n", maxDepth(root));
	printf("Minimum Value: %d \n", minValue1(root));
	printTree1(root);
	printf("\n");
	printTree2(root);
        printf("\n");
        printTree3(root);
	printf("\n%d\n", hasPathSum2(root,9));
	printPaths(root);
	printf("\n");
	//doubleTree(root);
	printf("\n");
        printPaths1(root);
	printf("Same Tree: %d\n",sameTree(root, second));
	free(root);

return 0;
}
