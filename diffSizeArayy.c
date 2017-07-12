#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct d_node_tag
{
    int data;
    struct d_node_tag* next;
}d_node;

typedef struct at_node_tag
{
    int index;
    d_node* dext;
    struct at_node_tag* next;
}at_node;

at_node* InitialiseAT();
void PrintAT(at_node* attop);

at_node* InitialiseAT()
{
    int d;
    int startat=1;

    int atcount=0;
    char c;
    FILE* fptr;
    fptr=fopen("data.txt","r");
    at_node* atptr=NULL, *attop=NULL;
    d_node* dptr;
    int whilecnt=0; //temprorary for checking


    while(!feof(fptr))
    {
        d_node* dnptr=(d_node*)malloc(sizeof(d_node));

        fscanf(fptr,"%d",&d);
        c=fgetc(fptr);
        dnptr->data=d;
        dnptr->next=NULL;
        if(c=='\n' || startat==1)
        {
            //printf("next line\n");
            at_node *atnptr=(at_node*)malloc(sizeof(at_node));
            atnptr->index=atcount;
            atnptr->next=NULL;
            if(startat==1)
            {
                attop=atnptr;
                atptr=atnptr;
                startat=0;
            }
            else
            {
                //dptr->next=dnptr;       ///lets see
                atptr->next=atnptr;
                atptr=atnptr;
            }
            atptr->dext=dnptr;
            atcount++;
        }
        else
        {
            dptr->next=dnptr;
            //c=fgetc(fptr);
            //c=fgetc(fptr);


        }
        dptr=dnptr;

/*
        printf("%d           -",whilecnt);
        c=fgetc(fptr);
        fscanf(fptr,"%d",&d);
        printf("\n%c :",c);
        printf(" %d",d);
        whilecnt++;

*/
    }
    fclose(fptr);
    return attop;
}

void PrintAT(at_node* attop)
{
    at_node* atptr;
    d_node* dptr;
    if(attop==NULL)
    {
        printf("\nAccess Table is NULL\n");
    }
    else
    {
        atptr=attop;
        while(atptr!=NULL)
        {
            printf("%d : ",atptr->index);
            dptr=atptr->dext;
            while(dptr!=NULL)
            {
                printf("%d,",dptr->data);
                dptr=dptr->next;
            }
            printf("NULL\n");
            atptr=atptr->next;
        }
    }
}

void main()
{
    at_node* attop=InitialiseAT();
    PrintAT(attop);
    //rename("data.txt","hello.txt");
}
