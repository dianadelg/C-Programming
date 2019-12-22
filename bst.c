#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bstSize=0;
int args=0;
char instruct;
int number;
typedef struct node{
	int data;
	struct node * left;
	struct node * right;

}node;

int search(node*root,int num){
//where it returns 0 if not found and 1 if found
	node*ptr=root;

	if(bstSize==0||ptr==NULL){
		return 0;
	}

	while(ptr!=NULL){
		if(num==ptr->data){
			return 1;}
	
		else if(num > ptr->data){
			ptr=ptr->right;}

		else {
			ptr=ptr->left;
		}
	}
//broke out of loop and not found
return 0;		

}

node* delete(node*root, int num){

	node*ptr=root;
	node*prev=NULL;

	while(ptr!=NULL){
		if(ptr->data==num){
			//means we found, need to break
			break;
		}
	
		prev=ptr;
		if(num<ptr->data){
			ptr=ptr->left;
		}else{
			ptr=ptr->right;
		}
	}
	//stepping out of this while loop means we have node at ptr and prev node is at ptr
	
	node*replace=NULL;
	if(ptr->left!=NULL&&ptr->right!=NULL){
		replace=ptr->left;
		prev=ptr;
		//must get inorder predecessor
		
		while(replace->right!=NULL){
			prev=replace;
			replace=replace->right;
		}
	
		//once it breaks, mean we need to copy data
		ptr->data=replace->data;
	}

	if(prev==NULL){
		//means it never moved along and we're at the node
		//delelte root
		if(ptr->left!=NULL){
			root=ptr->left;
		}else{
			root=ptr->right;
		}	
		bstSize--;
		return root;
	}
	//else we are deleting either a leaf or somethng with only one child
	
	node*t=(ptr->right!=NULL)?ptr->right : ptr->left;

	if(ptr==prev->left){
		prev->left=t;
	}else{
		prev->right=t;
	}

	bstSize--;
	return root;




}

node* insert(node*root,int num){
	node*temp=(node*)malloc(sizeof(node));

	if(temp==NULL){
		return root;
	}

	temp->data=num;
	temp->left=NULL;
	temp->right=NULL;

	if(bstSize==0){
		bstSize++;
		return temp;
	}

	node*ptr=root;
	node*prev=NULL;
	
	while(ptr!=NULL){
		if(num<ptr->data){
			prev=ptr;
			ptr=ptr->left;
		}else{
			prev=ptr;
			ptr=ptr->right;
		}
	}
	//if we break out of loop, means we hit a null (empty place to put node)
	
	if(num < prev->data){
		//place to left
		prev->left=temp;
		bstSize++;
	}else{
		prev->right=temp;
		bstSize++;
	}


	return root;
}

void print(node*root){
	//simple inorder trav
	if(bstSize==0){
		printf("\n");
		return;
	}
	if(root==NULL){
		return;
	}
	
	printf("(");
	print(root->left);
	//printf("(");	
	printf("%d",root->data);
	print(root->right);
	printf(")");
	return;


}

int main(int argc, char **argv){
//	printf("am i working\n");
	
	args=scanf(" %c %d", &instruct, &number);
	

	node*root=NULL;

	while(args==2 || args==1){
	
		if(args==2&&instruct=='i'){
			int result;
			result=search(root,number);
			
			if(result==0){
				root=insert(root,number);
				printf("inserted\n");
			}else{
				printf("duplicate\n");
			}

		}else if(args==2&&instruct=='s'){
			int result;
			result=search(root,number);
			
			if(result==0){
				printf("absent\n");
			}else{
				printf("present\n");
			}
		}else if(args==2&&instruct=='d'){
			
			int value;
			value=search(root,number);
			
			if(value==0){
				printf("absent\n");
			}else{
				root=delete(root,number);
				printf("deleted\n");
			}
			
		}else if(args==1&&instruct=='p'){
			if(bstSize==0){
				printf("\n");
				//printf("\n");
			}else{
				print(root);
				printf("\n");
			}

		}else{
			//means invalid
			return 0;
		}
		args=scanf(" %c %d",&instruct,&number);
	//might have to change back to ==2
	}
	
	//need to figure out how to do the inputs and outputs if user enters
	//only one character like p
		
	free(root);
	return 0;
}
	
