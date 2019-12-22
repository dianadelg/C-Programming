#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
	int data;
	struct node*next;
	
}node;


int k=0; //where k is the dimensions of M (k*k matrix)
int rows=0;
int columns=0;
int exponent=0;

node* append(node*head, int var){

	node*temp=(node*)malloc(sizeof(node));
	if(temp==NULL){
		return head;
	}

	
	temp->data=var;
	temp->next=NULL;

	node*ptr=head;
	
	if(head==NULL){
		//means first element
		head=temp;
		return head;
	}
	
	while(ptr!=NULL){
		if(ptr->next==NULL){
			//means last item
			ptr->next=temp;
			return head;
		}
		ptr=ptr->next;
	}
	
	return head;
}

void printyboi(int ** array){
	//printf("are we printing boi\n");

	int i, j; //where k are dimensions

	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			printf("%d",array[i][j]);
			if(!(j==k-1)){
				printf(" ");
			}
		}
		printf("\n");
	}

	return;
}

void multiply(int ** original, int ** temp, int ** hold){

	int y,v,q;
	
	for(y=0;y<k;y++){
		for(q=0;q<k;q++){
			hold[y][q]=0;
				for(v=0;v<k;v++){
					hold[y][q]=hold[y][q]+original[y][v]*temp[v][q];
}
}
}

return;
	

}

node* slice(char*line){
	//line is 1 4 6 

	char seps[]=" \n";
	char*token;
	int var;
	node*ret=NULL; //ll to be returned

	token=strtok(line,seps);
	while(token!=NULL){
		sscanf(token,"%d",&var);
		token=strtok(NULL,seps);
		ret=append(ret,var);
	}

	return ret;


}

int main(int argc, char**argv){
	int args=0;
	FILE*file=fopen(argv[1],"r"); 
	if(file==NULL){
		return 0;
	}

	char*line=NULL; 
	size_t len=0;
	
	int lineCount=1;
	while((args=getline(&line, &len, file))!=-1){
	
		if(lineCount==1){
			k=atoi(line);
			rows=k;
			columns=k;
		}

		if(lineCount==k+2){
			exponent=atoi(line);
		}
				
	lineCount++;
	}
	
	fclose(file);

	args=0;
	FILE*reopen=fopen(argv[1],"r");
	if(reopen==NULL){
		return 0;
	}
	
	char*line1=NULL;
	size_t len1=0;
	int lineCount1=1;
	
	node *head =NULL;
	
	//matrix
	int ** matrix=malloc(k*sizeof(int*));
	if(matrix==NULL){
		return 0;
	}
	
	int hey;
	for(hey=0;hey<k;hey++){
		matrix[hey]=(int*)malloc(k*sizeof(int));
		if(matrix[hey]==NULL){
			return 0;
		}
	}
//matrix initialized
	int d=0;

	while((args=getline(&line1,&len1,reopen))!=-1){

		if(lineCount1>1&&lineCount1<k+2){
			
			head=slice(line1);
						
			int q=0;

			node*dat=head;
				while(dat!=NULL){
					
					matrix[d][q]=dat->data;
					dat=dat->next;
					q++;
				}
				
			
		d++;					
		}
		
		head=NULL;
		lineCount1++;

	}
	

	
	//matrix is nice and initialized woohoo
	//now do the multiplication in it
	
	int out, in;
	if(exponent==0){
		for(out=0;out<k;out++){
			for(in=0;in<k;in++){
				if(in==out){
					matrix[out][in]=1;
				}else{
					matrix[out][in]=0;
				}
			}
		}
		printyboi(matrix);
		return 0;
	}

	if(exponent==1){
		printyboi(matrix);
		return 0;
	}
	
	//if we reach here, exponent is >=2

	int ** temp=malloc(sizeof(int*)*k);
	int ** hold=malloc(sizeof(int*)*k);
	if(temp==NULL || hold==NULL){
		return 0;
	}

	for(out=0;out<k;out++){
		temp[out]=malloc(sizeof(int)*k);
		hold[out]=malloc(sizeof(int)*k);
		
		if(temp[out]==NULL||hold[out]==NULL){
			return 0;
		}
	}

	int i,j,x;
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			temp[i][j]=0;
			for(x=0;x<k;x++){
				temp[i][j]=temp[i][j]+matrix[i][x]*matrix[x][j];
			}
		}
	}
	
	if(exponent==2){
		printyboi(temp);
		return 0;
	}

	int count=2;
	do{
	
		multiply(matrix,temp,hold);
		count++;
		if(count==exponent){
			printyboi(hold);
			return 0;
		}
		multiply(matrix,hold,temp);
		count++;
		if(count==exponent){
			printyboi(temp);
			return 0;
		}
	
	}while(count!=exponent);	
	



	
	fclose(reopen);		
	free(line);
	free(matrix);
	free(temp);
	free(hold);
	
	return 0;

}
