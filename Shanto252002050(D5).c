#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
int room;
int treasure;
struct Node *next;
};



struct Node* createRoom(int room, int treasure){
struct Node *newNode;
newNode =(struct Node*)malloc(sizeof(struct Node));
newNode->room =room;
newNode->treasure =treasure;
newNode->next =NULL;
return newNode;
}
int main(){
struct Node *head =NULL;
struct Node *temp =NULL;

int i;
int choice;
int score = 0;
head = createRoom(1, rand() %2);
    temp = head;
for(i =2; i <=5; i++){
    
temp->next = createRoom(i, rand() %2);
temp = temp->next;
}
temp = head;
 printf("\n\n\t\t TREASURE HUNT GAME \n\n");
   printf("\t   Find the treasure in 5 rooms! \n");
 while(temp != NULL){
     
    printf("\nYou are in Room %d\n", temp->room);
printf("1. Search Room\n");
printf("2. Go to Next Room\n");
printf("Enter choice: ");
scanf("%d", &choice);

     if(choice ==1){
       
if(temp->treasure== 1){
 printf("\n*** TREASURE FOUND! ***\n");
 score+= 10;
 temp->treasure = 0;}
else{
 printf("\nNo treasure here!\n");}
}else if(choice ==2)
{
 if(temp->next !=NULL){
 temp =temp->next;
 printf("You moved to the next room.\n");
}else{
 printf("\nNo more rooms!\n");
 break;}
}else{
 printf("\nInvalid choice!\n");}
}
 printf("\t\tGAME OVER\n");
 printf("Your Score = %d\n", score);

if(score>= 30)
printf("Excellent\n");
else if(score >=10)
printf("OHO Not so bad\n");
else
printf("GOOD BOY\n");
return 0;
}
