#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
int id;
char name[100];
int quantity;
}
library;

 int arr(library *r1){
int r3=0;
FILE *r4;
r4=fopen("fp.txt","r");
 for(int i=0;fscanf(r4,"%d %d %[^\n]" ,&r1[i].id,&r1[i].quantity,r1[i].name)!=EOF;i++)
 {r3++;}
 fclose(r4);
 return r3;
 }

 void insert_book(FILE *insert)
 {library b;
insert=fopen("fp.txt","a");
printf("ID:");
scanf("%d",&b.id);
printf("Quantity:");
scanf("%d",&b.quantity);
printf("Name:");
getchar();
gets(b.name);
fprintf(insert,"%d %d %s" , b.id,b.quantity,b.name);
fclose(insert);
 }

void delete_book(library *b){
FILE *deletee;
FILE *temp ;
int id,y;
printf("write ID of abook");
scanf("%d",&id);
y=arr(b);
deletee=fopen("fp.txt","+a");
temp=fopen("temp.txt","w");
for(int i=0;i<y;i++){
    if(b[i].id==id){
        continue; }
    else
        fprintf(temp,"%d %d %s \n" ,b[i].id,b[i].quantity,b[i].name);}
fclose(deletee);
fclose(temp);
remove("fp.txt");
rename("temp.txt","fp.txt");
}
void search_abook(int i,int id,library *b){

    int size;
    FILE *searchh;
    searchh=fopen("fp.txt","r");
    size=arr(b);
if(i<=size&&b[i].id==id){
printf("%d %d %s \n" ,b[i].id,b[i].quantity,b[i].name);}
else if(b[i].id!=id){
            search_abook(i+1,id,b);}
else{
printf("the book doesn't exist \n");
}
fclose(searchh);
}
int search_by_binary(library *b){
arr(b);
int size=arr(b);
int temp1,temp2;
char str[30];
char name[30];

for(int k=1;k<size;k++){
    for(int i=0;i<size-k;i++)
        {
            if(strcmp(b[i].name,b[i+1].name)>0)
            {
                temp1=b[i].id;
                b[i].id=b[i+1].id;
                b[i+1].id=temp1;

                temp2=b[i].quantity;
                b[i].quantity=b[i+1].quantity;
                b[i+1].quantity=temp2;

                strcpy(str,b[i].name);
                strcpy(b[i].name,b[i+1].name);
                strcpy(b[i+1].name,str);
            }
        }
        }
    int mid,low=0,high=size-1;
    printf("write a name of book : ");
        getchar();
    gets(name);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(name,b[mid].name)==0){
            printf("%d %d %s \n" ,b[mid].id,b[mid].quantity,b[mid].name);
            return 1;
        }
        else if(strcmp(name,b[mid].name)==-1){
        high=mid-1;
        }
        else {
            low=mid+1;}
    }
    printf("Not found \n");


}
void display_sorted_by_name(library *b){
arr(b);
int size=arr(b);
int temp1,temp2;
char str[30];
char name[30];

for(int k=1;k<size;k++){
    for(int i=0;i<size-k;i++)
        {
            if(strcmp(b[i].name,b[i+1].name)>0)
            {
                temp1=b[i].id;
                b[i].id=b[i+1].id;
                b[i+1].id=temp1;

                temp2=b[i].quantity;
                b[i].quantity=b[i+1].quantity;
                b[i+1].quantity=temp2;

                strcpy(str,b[i].name);
                strcpy(b[i].name,b[i+1].name);
                strcpy(b[i+1].name,str);
            }
        }}
        for(int i=0;i<size;i++){
            printf("%d %d %s \n" ,b[i].id,b[i].quantity,b[i].name);}

}
void display_unsorted(library *b){
int size=arr(b);
for(int i=0;i<size;i++){
    printf("%d %d %s \n" ,b[i].id,b[i].quantity,b[i].name);}

}
int main()
{ char c;
do{
library book[10];
FILE *r4;
printf("insert_book :1 \ndelete_book :2 \nsearch_abook :3\nsearch_by_binary :4\ndisplay_all_books_sorted_by_name :5\ndisplay_all_books_unsorted :6 \nwrite your choose: ");
int x;
int id;
scanf("%d",&x);

 switch(x){
 case 1:
     r4=fopen("fp.txt","r");
     insert_book(r4);
     fclose(r4);
     break;
case 2:
    delete_book(book);
    break;
case 3 :
    arr(book);
    printf("write ID of book");
    scanf("%d",&id);
    search_abook(0,id,book);
    break;
case 4 :
    arr(book);
    search_by_binary(book);
    break;
case 5:
     arr(book);
     display_sorted_by_name(book);
     break;
case 6:
    arr(book);
    display_unsorted(book);
    break;
default:
    printf("\n choose the right number \n");}
printf("if you want perform any additional operation click (Y) or (y) : ");
scanf("%s",&c);

}
while(c=='y' || c=='Y');

    return 0;
}
