#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	struct node* next;
}node;

int llsize=0;
int args=0;
char instruct='i';
int number=0;


int isFound(node * head, int num){
	//where 0 means not found and 1 means found
	node*ptr=head;
	int i;
	if(llsize==0){
		return 0;
	}
	for(i=0;i<llsize;i++){
		if(ptr->data==num){
			return 1;
		}else{
			ptr=ptr->next;
		}
	}
	return 0;
}

node* insertFirst(node*head, int num){
	//where we insert the first element 
	node*temp=malloc(sizeof(node));
	if(temp==NULL){
		return head;
	}
	temp->data=num;
	temp->next=NULL;

	head=temp;
	llsize++;
	return head;
}

node * insert(node*head, int num){
	node*temp=malloc(sizeof(node));
	if(temp==NULL){
		return head;
	}

	temp->data=num;
	temp->next=NULL;

	node*ptr=head;
	node*lag=NULL;

	do{
		if(ptr->data > num){
			if(ptr->data==head->data){
			//means it's at head
			temp->next=head;
			head=temp;
			llsize++;
			return head;
			}
			temp->next=ptr;
			lag->next=temp;
			llsize++;
			return head;
		}else{
			
			if(ptr->next==NULL){
				ptr->next=temp;
				llsize++;
				return head;
			}
			lag=ptr;
			ptr=ptr->next;
		}
			
	}while(ptr!=NULL);

return head;
}

int cCount(int hold){
	//int count=0; //this is the final length
	int check; //this is the each number spaces
	check=0;

	long long h=(long)(long)hold;
	while(h!=0){
		h/=10;
		check++;
	}
	return check;

}

void print(node*head){
	//ccount will be the total size of the malloced string
	if(llsize==0){
		printf("0 :\n");
		return;			
	}

	//else ccount function
	int count=0; //this is the final count of spaces needed for char array
	node*ptr=head;
	int hold;
	while(ptr!=NULL){
		hold=ptr->data;
		count+=cCount(hold);
		ptr=ptr->next;
	}

	//once here, count will have all of the spaces needed for numebers
	count+=llsize+2;
	//now mult by 2
	
	count=count*2;
	char*str=(char*)malloc(count*sizeof(char));
	if(str==NULL){
		return;
	}
	
	str[0]='\0';

	//now put in string
	//first the number
	char arr[12];
	sprintf(arr,"%d",llsize);
	strcat(str,arr); //this puts in the number
	
	char space[2];
	space[0]=' ';
	space[1]='\0';
	
	char colon[2];
	colon[0]=':';
	colon[1]='\0';
	
	//strcat colon and space
	strcat(str,space);
	strcat(str,colon);
	

	//now add the data element by element
	ptr=head;
	while(ptr!=NULL){
		strcat(str,space);
		int holding=ptr->data; //gets number
		char n[12];
		sprintf(n,"%d", holding);
		strcat(str,n);
		ptr=ptr->next;
	}
	//one we reach this, means string is concatenated correctly and should run
	
	printf("%s\n",str);
	free(str);
	return;
		
}

node* delete(node*head, int num){
	//where num is the number to be deleted
	//no need to create nodes so yeehaw
	
	node*ptr=head;
	node*lag=NULL;
	
	//printf("Head is %d \n",head->data);

	while(ptr!=NULL){
		if(ptr->data==num){
			if(llsize==1){
			//means it's in list and since only element, delete
				head=NULL;
				llsize--;
				return head;	
			}
			
			if(ptr==head){
				//means removing the first item		
				head=ptr->next;
			//	printf("Head is now %d \n", head->data);
				llsize--;
				return head;
			}
			
			if(ptr->next==NULL){
				//last item
				lag->next=NULL;
				llsize--;
				return head;
			}
			
			//middle item or something
			lag->next=ptr->next;
			llsize--;
			return head;
	
		}else{
			lag=ptr;
			ptr=ptr->next;

		}
	}
return head;	
	
}

int main(int argc, char**argv){

	node*head=NULL;
	args=scanf(" %c %d", &instruct, &number);
	int true=0; //to be used if it exists or not
	
	if(args!=2 || (instruct!='d' && instruct!='i')){
		return 0; //bad input, terminate
	}
	
	while(args==2){
		if(instruct=='i'){
			//inserting a number
			if(llsize==0){
				head=insertFirst(head,number);
				print(head);
			}else{
				true=isFound(head,number);
				if(true==0){
					head=insert(head,number);
				}
				print(head);
			
			}
		}else if(instruct=='d'){ // if issues, delete the if condition part
			/*if(llsize==0){
				//cannot delete from nothing
				print(head);
			}
		*/
			true=isFound(head,number);
			if(true==1){
		//		printf("In list and must be deleted \n");
				//means it's in there and we must delete
				head=delete(head,number);
				print(head);
			}else{
			//means not found
			print(head);
			}
		}

		//else{
			//terminate
		//	return 0;
	//	}

		args=scanf(" %c %d",&instruct,&number);
	}
free(head);
return 0;

}
