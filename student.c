
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp,*tmp;
    struct data{
    char id[20];
    char name[20];
    char add[20];
    char parname[20];
    char Batch[20];
    char phone_no[20];
}stud1;
struct student{

    struct data stud;
    struct student *next;
}*head,*temp,*curr;

void main()
{
    int i,j,choice;
    printf("JIIT-128\n\n\n");
    printf("Menu\n\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Modify Student Record\n");
    printf("4. Generate Marksheet\n");
    printf("5. Delete Student Record\n");
    printf("6. Change password\n");
    printf("7. Exit\n\n");
    printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                mod_student();
                break;
            case 4:
                break;
            case 5:
                delete_student();
                break;
            case 6:
                break;
            case 7:
                exit(0);
                break;
            default:
                break;
        }
}
void add_student()
{
    int i;
    struct student *n_node;
    n_node=(struct student*)malloc(sizeof(struct student));
    printf("Enrollement No.: ");
    for(i=0;i<=19;i++)
    {
        n_node->stud.id[i]='\0';
        n_node->stud.name[i]='\0';
        n_node->stud.add[i]='\0';
        n_node->stud.Batch[i]='\0';
        n_node->stud.phone_no[i]='\0';
    }
    scanf("%s",n_node->stud.id);
        //here you can confirms the ID
    printf("Name: ");scanf("%s",n_node->stud.name);
    printf("Address: ");scanf("%s",n_node->stud.add);
    printf("Parent's name: ");scanf("%s",n_node->stud.parname);
    printf("Batch: ");scanf("%s",n_node->stud.Batch);
    printf("Phone Number: ");scanf("%s",n_node->stud.phone_no);
    printf("The record is sucessfully added");
    n_node->next=NULL;
    if(head==NULL)
    {
        head=n_node;
        curr=n_node;
    }
    else
    {
        curr->next=n_node;
        curr=n_node;
    }
    fp=fopen("data.txt","ab+");
    fwrite(&curr->stud, sizeof(curr->stud), 1, fp);
    fclose(fp);
}
void search_student(){
    int i;
    char s_id[20];
    for(i=0;i<=19;i++)
    {
        s_id[i]='\0';
        stud1.id[i]='\0';
    }
    int isFound = 0;
    printf("Enter ID to Search: ");
    scanf("%s",s_id);
    fp = fopen("data.txt","rb");
    i=0;
    while(fread(&stud1, sizeof(stud1), 1, fp) == 1){

       // i++;
        if(strcmp(s_id,stud1.id) == 0){
            isFound = 1;
            break;

        }

    }
   //  printf("%d",i);
    if(isFound == 1){
        printf("The record is Found");
        printf("ID: %s",stud1.id);
        printf("Name: %s",stud1.name);
        printf("Address: %s",stud1.add);
        printf("Parent's Name: %s",stud1.parname);
        printf("Batch: %s",stud1.Batch);
        printf("Phone No: %s",stud1.phone_no);
    }else{
        printf("Sorry, No record found in the database");
    }
    fclose(fp);
    printf("%d",i);
    return;
}
void delete_student()
{
    int i;
    char s_id[20];
    for(i=0;i<=19;i++)
    {
        s_id[i]='\0';
        stud1.id[i]='\0';
    }
    int isFound = 0;
    printf("Enter enrollment no. to delete: ");
    scanf("%s",s_id);
    fp = fopen("data.txt","rb");
    temp = fopen("temp.txt", "wb");
    i=0;
    while(fread(&stud1, sizeof(stud1), 1, fp) == 1){

        i++;
        if(strcmp(s_id,stud1.id) != 0){
            fwrite(&stud1, sizeof(stud1), 1, temp);


        }

    }
    fclose(fp);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt","data.txt");
    printf("record deleted\n");
    return;
}
void mod_student(){
    char s_id[19];
    int isFound = 0;
    printf("Enter enrollment no. to Modify: ");
    scanf("%s",s_id);
    fp = fopen("data.txt","rb+");
    while(fread(&stud1, sizeof(stud1),1,fp) == 1){
        if(strcmp(s_id, stud1.id) == 0){

            printf("ID: ");scanf("%s",stud1.id);
            printf("Name: ");scanf("%s",stud1.name);
            printf("Address: ");scanf("%s",stud1.add);
            printf("Parent's name: ");scanf("%s",stud1.parname);
            printf("Batch: ");scanf("%s",stud1.Batch);
            printf("Phone Number: ");scanf("%s",stud1.phone_no);
            fseek(fp,-sizeof(stud1), SEEK_CUR);
            fwrite(&stud1,sizeof(stud1), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        printf("No Record Found");
    }
    else
        printf("Record modified\n");
    fclose(fp);
    return;
}


