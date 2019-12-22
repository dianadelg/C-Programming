#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int x;
	int y;
	struct node *next;

}node;

void printing();
int xVal;
int yVal;

int isValid(char board[][8],node*head){
	node*ptr=head;
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		for(xVal=0;xVal<8;xVal++){
			for(yVal=0;yVal<8;yVal++){

					char hold=board[xVal][yVal];
						if(hold=='Q'){
							if(!(ptr->x==xVal&&ptr->y==yVal)){
	if(ptr->x==xVal){
		return 0;
	}
	if(ptr->y==yVal){
		return 0;
	}
	int xv=(ptr->x)-xVal;
	int yv=(ptr->y)-yVal;
	float slope=(float)yv/xv;
	//printf("slope is %f\n",slope);	
	if(slope==1||slope==-1){
		return 0;
	}
}
}
}
}
}
	return 1; //means is valid
	


}


node*search (char board[][8],node*head){
	for(xVal=0;xVal<8;xVal++){
		for(yVal=0;yVal<8;yVal++){
			if(board[xVal][yVal]=='Q'){
				node*add=malloc(sizeof(node));
				add->x=xVal;
				add->y=yVal;
				if(head==NULL){
					add->next=NULL;
					head=add;
				}else{
					add->next=head;
					head=add;
				}
			}
		}
	}

	return head;
}



void printing(char board[][8]){

	for(xVal=0;xVal<8;xVal++){
		for(yVal=0;yVal<8;yVal++){
			printf("%c",board[xVal][yVal]);
		}
		printf("\n");
	}

	return;

}

int queenAdd(char board[][8]){
//so pretty sure this is wrong
	

	int count=0;
	for(xVal=0;xVal<8;xVal++){
		for(yVal=0;yVal<8;yVal++){
			char hold=board[xVal][yVal];
				if(hold=='q'){
					count++;
				}
			}
		}
return count;

	
//we have how many qs there are and where they are, now we need to check if they can be placed
}


	
int main(int argc, char**argv){
	FILE*file;
	int args; //number of arguments

	if(argc==2){
		file=fopen(argv[1],"r");
	}else if(argc==3){
		file=fopen(argv[2],"r");
	}else if(argc==4){
		file=fopen(argv[3],"r");
	}else{
		printf("invalid args\n");
		return 0;
	}

	if(file==NULL){
		printf("empty file");
		return 0;
	}

	char*line=NULL;
	size_t len=0;

	char board[8][8];
	int t,x;
	t=0;
	while((args=getline(&line,&len,file))!=-1){
		
		for(x=0;x<8;x++){
			board[t][x]=line[x];
		
		}
	t++;

	}


	//at this point, we have our original board

	node * head =NULL;
	head=search(board,head);
	int valid;
	valid=isValid(board,head);
	//printf("value of valid is %d\n",valid);
	if(!(valid==1)){
		printf("Invalid\n");
		return 0;
	}

 	//if here, it means we are a valid board and must figure out where to place it
	node*ptr=head;
	int place;
	float slope;
	float xv;
	float yv;
	
//	printing(board);
	
	for(xVal=0;xVal<8;xVal++){
		for(yVal=0;yVal<8;yVal++){
			place=1;
			ptr=head;
			char hold=board[xVal][yVal];
				if(hold=='.'){
					while(ptr!=NULL){
						
						if(xVal==ptr->x||yVal==ptr->y){
							place=0;
						}
						
						xv=(ptr->x)-xVal;
						yv=(ptr->y)-yVal;
						slope=yv/xv;
						//printf("slope is %f\n",slope);
						if(slope==1.0||slope==-1.0){
						//	printf("slope is bad\n");
							place=0;
						}
						ptr=ptr->next;
					}
					if(place==1){
						board[xVal][yVal]='q';
					}else{
						board[xVal][yVal]='.';
					}
				}
				ptr=head;
		}
	}			

printing(board);
if(argc==2){
	return 0;
}

	int numQ=0;
	int value=0;
	if(argc==3){
		//char hold[5];
		value=strcmp(argv[1],"+2");
		
		if(value==0){	
			//means it is a +2 command		

			//send board into function and check to see how many additional queens can be sent in
			//printf("One\n");
			
			numQ=queenAdd(board);
				
/*			
		node*front=NULL;
		node*qPlace=(node*)malloc(sizeof(node));
		
		for(xVal=0;xVal<8;xVal++){
			for(yVal=0;yVal<8;yVal++){
			
				char squish=board[xVal][yVal];
			//	printf("squish at %d,%d is : %c\n",xVal,yVal,squish);
				if(squish=='q'){
					qPlace->x=xVal;
					qPlace->y=yVal;
					
					if(front==NULL){
						qPlace->next=NULL;
						front=qPlace;
						continue;
					}
						qPlace->next=front;
						front=qPlace;
					}
				}
			
			}
	
	
	node*please=front;
		
	while(please!=NULL){
		printf("x : %d     y : %d\n",please->x,please->y);
		please=please->next;
	}
*/


		
				if(numQ==0){
					printf("Zero\n");
				}else if(numQ==1){
					printf("One\n");
				}else{
					printf("Two or more\n");
				}


		}
		
	}


free(head);
return 0;	
	
}
