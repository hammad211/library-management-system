/*
            DSA LAB PROJECT


            MUHAMMAD SAMULLAH
            FA20-BSE-007
            Section B

            Project Name: Student Library Management System
*/





#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct book{
    char Book_Name[30];
    char Author_Name[30];
    int Book_id;
    int copies;

    struct book *link;
};

struct student{
    char Student_name[30];
    char Student_email[30];
    char Book_Name[30];
    char Author_Name[30];
    int Book_id;

    struct student *link;
};


struct book *book_head=NULL;
struct student *student_head=NULL;

struct book *initializeLibrary(struct book *book_head);
void issueBook(int id);
void AddBook();
struct book *booksReading(struct book *head);


struct student *studentReading(struct student *head);
void studentPrinting(struct student *head);

void printing(struct book *head);

void returnBook(int id,char name[30]);

void searchBook(char arr[30]);

void updateRecord();

void greetings();

void menu();

void deleteBook();

int main()
    {

                greetings();

                int choice;
                struct student *p;

                char arr[30];

                menu();
                printf("\n\t\t\t\t|  Enter choice : ");
                scanf("%d",&choice);


                    while(choice!=-1)
                    {
                        if(choice==1)
                        {
                            printf("\n\n\t\tInitializing Student Library system \n\n");
                            book_head=initializeLibrary(book_head);
                        }
                        else if(choice==2)
                        {
                             printf("\n");
                             book_head=booksReading(book_head);
                             printing(book_head);

                        }
                        else if(choice==3)
                        {
                             printf("\n");
                             AddBook();
                        }
                        else if(choice==4)
                        {
                             printf("\n");
                             int id=0;
                             printf("\n\n\t\t\t\tEnter Id of book : ");
                             scanf("%d",&id);
                             issueBook(id);
                        }
                        else if(choice==5)
                        {
                             printf("\n");
                             student_head=studentReading(student_head);
                             studentPrinting(student_head);
                        }
                        else if(choice==6)
                        {
                             printf("\n");
                             int id=0;
                             char name[30];
                             printf("\n\t\t\t\tEnter Name of Student  : ");
                             fflush(stdin);
                             gets(name);

                             printf("\n\t\t\t\tEnter Id of book       : ");
                             scanf("%d",&id);
                             returnBook(id,name);
                        }
                        else if(choice==7)
                        {
                             printf("\n\n\n\n\t\t\t\t SEARCHING A BOOK\n ");
                            printf("\n\t\t\t Enter book name : ");
                            fflush(stdin);
                            gets(arr);
                            searchBook(arr);
                        }
                        else if(choice==8)
                        {
                            updateRecord();
                            printf("\n\n");
                        }
                        else if(choice==9)
                        {
                            deleteBook();
                        }
                        else
                             printf("\n\tEnter valid input !!\n");

                       menu();
                       printf("\n\t\t\t\t|  Enter choice : ");
                       scanf("%d",&choice);
                       system("cls");
                    }


         return 0;

    }

void menu()
    {
                printf("\n\n\n\t\t\t\t_______________________________________________\n\n");
                printf("\t\t\t\t|\t\t MAIN MENU                    |\n");
                printf("\t\t\t\t|\t\t                              |\n");

                printf("\t\t\t\t|  PRESS 1 TO INITIALIZE LIBRARY              |\n\t\t\t\t|  PRESS 2 TO PRINT AVAILABLE BOOKS           |\n\t\t\t\t|  PRESS 3 TO ADD NEW BOOK TO LIBRARY STOCK   |\n\t\t\t\t|  PRESS 4 TO ISSSUE A BOOK                   |\n\t\t\t\t|  PRESS 5 TO PRINT STUDENTS RECORD           |\n\t\t\t\t|  PRESS 6 TO RETURN BOOK IN LIBRARY          |\n\t\t\t\t|  PRESS 7 TO SEARCH BOOK RECORD              |\n\t\t\t\t|  PRESS 8 TO UPDATE BOOKS COPIES             |\n\t\t\t\t|  PRESS 9 TO DELETE BOOKS RECORD             |\n\t\t\t\t|  PRESS -1 TO EXIT                           |");
                printf("\n\t\t\t\t_______________________________________________\n");
    }


void updateRecord()
    {
        char arr[30];
        printf("\n\n\n\n\t\tEnter book name : ");
        fflush(stdin);
        gets(arr);

        book_head=booksReading(book_head);
        struct book *temp=book_head;

        int flag=0;

        while(temp!=NULL)
        {
            if( (strcmp(temp->Book_Name,arr)) == 0)
            {
                printf("\n\n\t\t\tUPDATE BOOK DATA\n\n");
                flag=1;

               printf("\n\n\t\t\t\tEnter updated copies : ");
               scanf("%d",&temp->copies);

                   printf("\n\n\t\t\t\t******************************\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|    BOOK DATA UPDATED       |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t******************************\n");
            }

             temp=temp->link;
        }

        if(flag==0)
        {
               printf("\n\n\t\t\t\t******************************\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t| Book Record not found !!   |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t******************************\n");
        }
        else
        {
            FILE *book;
            book=fopen("BooksDetails.txt","w");

               temp=book_head;

                    while(temp!=NULL)
                    {
                      fprintf(book,"\n%10s %10s %5d %5d",temp->Book_Name,temp->Author_Name,temp->Book_id,temp->copies);
                      temp=temp->link;
                    }

                fclose(book);

        }

    }



void searchBook(char arr[30])
    {
        book_head=booksReading(book_head);
        struct book *temp=book_head;
        int flag=0;

        while(temp!=NULL)
        {
            if( (strcmp(temp->Book_Name,arr)) == 0)
            {
                printf("\n\n\t\t\tBook found and Available for Sale.\n\n");
                flag=1;
                printf("\t\t\t   Book Name\t  Author Name\t  Book Id\t  Copies    \n\n");
                printf("\t\t\t   %-10s\t  %-10s\t  %-10d\t  %-10d\n",temp->Book_Name,temp->Author_Name,temp->Book_id,temp->copies);
            }

             temp=temp->link;
        }

        if(flag==0)
        {
               printf("\n\n\t\t\t\t******************************\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t| Book Record not found !!   |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t******************************\n");
        }

    }

void deleteBook()
    {
        book_head=booksReading(book_head);

        struct book *temp=book_head;

        int flag=0;

        int id;
        printf("\n\n\t\t\t\tEnter Book Id : ");
        scanf("%d",&id);

        FILE *Books;
        Books=fopen("BooksDetails.txt","w");

        while(temp!=NULL)
        {
            if( temp->Book_id != id)
            {
                fprintf(Books,"\n%10s %10s %5d %5d",temp->Book_Name,temp->Author_Name,temp->Book_id,temp->copies);
            }

            if(temp->Book_id == id)
            {

                 flag=1;

        printf("\n\n\t\t\t\t******************************\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t| Book Deleted Successfully  |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t******************************\n");

            }
            temp= temp->link;
        }

        fclose(Books);

        if(flag==0)
        {

         printf("\n\n\t\t\t\t******************************\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t| Book Record not found !!   |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t******************************\n");
        }



    }

void AddBook()
    {
        FILE *Books;
        Books=fopen("BooksDetails.txt","a+");
        int num;

        struct book *first;
        first=(struct book*)malloc(sizeof(struct book));


        printf("\n\t\t\t\t Enter Book Details\n \n     ");
        printf("\t\t\t\t Enter Book Name     : ");
        fflush(stdin);
        gets(first->Book_Name);

        printf("\t\t\t\t Enter Author Name   : ");
        fflush(stdin);
        gets(first->Author_Name);

        printf("\t\t\t\t Enter Book ID       :  ");
        scanf("%d",&first->Book_id);

        printf("\t\t\t\t Enter no. of copies :  ");
         scanf("%d",&first->copies);

        fprintf(Books,"\n%10s %10s %5d %5d",first->Book_Name,first->Author_Name,first->Book_id,first->copies);

        printf("\n\n\t\t\t\t****************************\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t| Book Added Successfully  |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t****************************\n");

        fclose(Books);
    }


struct book *booksReading(struct book *head)
    {
        FILE *book;
         book=fopen("BooksDetails.txt","r");

         fseek(book,0,SEEK_END);
         int size=ftell(book);

         fclose(book);

        if(size==0)
            {
                head=NULL;
            }
        else
        {
            book=fopen("BooksDetails.txt","r");
            struct book *first;
            first=(struct book*)malloc(sizeof(struct book));
            fscanf(book,"%s %s %d %d",first->Book_Name,first->Author_Name,&first->Book_id,&first->copies);
            first->link=NULL;

            head=first;

            while(!feof(book))
            {
                struct book *second;
                second=(struct book*)malloc(sizeof(struct book));

                fscanf(book,"%s %s %d %d",second->Book_Name,second->Author_Name,&second->Book_id,&second->copies);
                second->link=NULL;
                first->link=second;

                first=second;

            }

            fclose(book);
        }


        return head;
    }



struct student *studentReading(struct student *head)
    {
         FILE *Student;
         Student=fopen("StudentsRecord.txt","r");

         fseek(Student,0,SEEK_END);
         int size=ftell(Student);
         fclose(Student);

               if(size==0)
                {
                    head=NULL;
                }
                else
                {
                    Student=fopen("StudentsRecord.txt","r");

                    struct student *first;
                    first=(struct student*)malloc(sizeof(struct student));
                    fscanf(Student,"%s %s %s %s %d",first->Student_name,first->Student_email,first->Book_Name,first->Author_Name,&first->Book_id);
                    first->link=NULL;

                    head=first;

                    while(!feof(Student))
                    {
                        struct student *second;
                        second=(struct student*)malloc(sizeof(struct student));

                        fscanf(Student,"%s %s %s %s %d",second->Student_name,second->Student_email,second->Book_Name,second->Author_Name,&second->Book_id);
                        second->link=NULL;
                        first->link=second;

                        first=second;

                    }

                    fclose(Student);

                }

        return head;
    }



void printing(struct book *head)
    {
        if(head == NULL)
        {
                printf("\n\t\t\t\tNo books records are available to show !!\n");
        }
        else
        {
           struct book *temp=NULL;
         temp=(struct book*)malloc(sizeof(struct book));

         temp=head;

          printf("\t\t\t\t   AVAILABLE BOOKS DETAILS\n\n");

          printf("\t\t\t*************************************************************\n");
          printf("\t\t\t*   Book Name\t  Author Name\t  Book Id\t  Copies    *\n");
          printf("\t\t\t*                                                           *\n");

         while(temp!=NULL)
         {
             printf("\t\t\t*   %-10s\t  %-10s\t  %-10d\t  %-10d*\n",temp->Book_Name,temp->Author_Name,temp->Book_id,temp->copies);
             temp=temp->link;
         }
          printf("\t\t\t*                                                           *\n");
          printf("\t\t\t* \t\t   SAMI'S PERSONAL LIBRARY\t\t    *\n");
          printf("\t\t\t*************************************************************\n");
        }

    }

void studentPrinting(struct student *head)
    {
         struct student *temp;
         temp=(struct student*)malloc(sizeof(struct student));

         temp=head;

        if( head==NULL )
        {
                    printf("\n\t\t\tNo student records are available to show !!\n");
        }
        else
        {
         printf("\t\t\t\t\t     AVAILABLE STUDENTS DETAILS\n\n");

         printf("\t\t********************************************************************************************\n");
         printf("\t\t*  Student Name\t  Student Email  \t\t Book Name\t Author Name\t Book Id   *\n");
         printf("\t\t*                                                                                          *\n");
          while(temp!=NULL)
         {
             printf("\t\t*  %-10s\t %-30s\t %-10s\t %-10s\t %-10d*\n",temp->Student_name,temp->Student_email,temp->Book_Name,temp->Author_Name,temp->Book_id);
             temp=temp->link;
         }

         printf("\t\t*                                                                                          *\n");
         printf("\t\t*    \t\t\t       SAMI'S PERSONAL LIBRARY\t\t\t\t           *\n");
         printf("\t\t********************************************************************************************\n");

        }

    }



struct book *initializeLibrary(struct book *book_head)
    {
        FILE *Books;
        Books=fopen("BooksDetails.txt","w");
        int num;

        struct book *first;
        first=(struct book*)malloc(sizeof(struct book));

        printf("Enter how many books do you want to start the library : ");
        scanf("%d",&num);

         printf("\n\t\t\t\tEnter Book Name     : ");
         fflush(stdin);
         gets(first->Book_Name);

         printf("\t\t\t\tEnter Author Name   : ");
         fflush(stdin);
         gets(first->Author_Name);

         printf("\t\t\t\tEnter Book ID       : ");
         scanf("%d",&first->Book_id);

         printf("\t\t\t\tEnter no. of copies : ");
         scanf("%d",&first->copies);

        fprintf(Books,"\n%10s %10s %5d %5d",first->Book_Name,first->Author_Name,first->Book_id,first->copies);

        first->link=NULL;
        book_head=first;

        for(int i=1;i<num;i++)
        {
            struct book *second;
            second=(struct book*)malloc(sizeof(struct book));


            printf("\n\n\t\t\t\tEnter Book Name     : ");
            fflush(stdin);
            gets(second->Book_Name);

            printf("\t\t\t\tEnter Author Name   : ");
            fflush(stdin);
            gets(second->Author_Name);

            printf("\t\t\t\tEnter Book ID       : ");
            scanf("%d",&second->Book_id);

            printf("\t\t\t\tEnter no. of copies : ");
            scanf("%d",&second->copies);

            fprintf(Books,"\n%10s %10s %5d %5d",second->Book_Name,second->Author_Name,second->Book_id,second->copies);

            second->link=NULL;
            first->link=second;
            first=second;
        }

        fclose(Books);

                printf("\n\n\t\t\t\t ******************************\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|  BOOKS ADDED SUCCESSFULLY    |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t ******************************\n");


        return book_head;

    };


void issueBook(int id)
    {

        int flag=0;
        struct book *reserve;
        reserve=(struct book*)malloc(sizeof(struct book));

        FILE *student;
        student=fopen("StudentsRecord.txt","a+");

        struct book *p;
        p=(struct book*)malloc(sizeof(struct book));

        book_head=booksReading(book_head);
        p=book_head;

          while(p!=NULL)
            {
                if(p->Book_id == id)
                {
                    flag=1;
                    FILE *book;
                    book=fopen("BooksDetails.txt","w");

                    struct student *R;
                    R=(struct student*)malloc(sizeof(struct student));

                    printf("\t\t\t\tEnter Student Name  : ");
                    fflush(stdin);
                    gets(R->Student_name);

                    printf("\t\t\t\tEnter Student Email : ");
                    fflush(stdin);
                    gets(R->Student_email);


                    fprintf(student,"\n%10s %20s %10s %10s %5d",R->Student_name,R->Student_email,p->Book_Name,p->Author_Name,p->Book_id);

                    fclose(student);

                    p->copies--;

                    if(p->copies == 0)
                    {
                     reserve->link=p->link;
                     p=reserve;
                    }

                    struct book *del=book_head;

                    while(del!=NULL)
                    {
                        if(del->copies != 0  )
                        {
                            fprintf(book,"\n%10s %10s %5d %5d",del->Book_Name,del->Author_Name,del->Book_id,del->copies);
                        }
                        del=del->link;
                    }
                    fclose(book);
                }
                p=p->link;
            }

            if(flag==1)
            {
            printf("\n\n\t\t\t\t****************************\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t| Book issued Successfully |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t|                          |\n");
                printf("\t\t\t\t****************************\n");
            }
            else
            {
                 printf("\n\n\t\t\t\t******************************\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t| Book Record not found !!   |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t|                            |\n");
                printf("\t\t\t\t******************************\n");
            }
    }



void returnBook(int id,char name[30])
    {
        int flag=0;
        struct student *p;
        p=(struct student*)malloc(sizeof(struct student));

        struct student *reserve;
        reserve=(struct student*)malloc(sizeof(struct student));

        book_head=booksReading(book_head);
        struct book *temp=book_head;

        student_head=studentReading(student_head);
        p=student_head;

        while(p!=NULL)
        {
            if(p->Book_id == id && (strcmp(p->Student_name,name)) == 0)
                {
                    flag=1;

                    FILE *book;
                    book=fopen("BooksDetails.txt","w");

                    int t=0;

                    while(temp!=NULL)
                    {
                        if(temp->Book_id == id )
                        {
                            temp->copies++;
                             fprintf(book,"\n%10s %10s %5d %5d",temp->Book_Name,temp->Author_Name,temp->Book_id,temp->copies);
                             t=1;
                        }
                        else
                        {
                            fprintf(book,"\n%10s %10s %5d %5d",temp->Book_Name,temp->Author_Name,temp->Book_id,temp->copies);
                        }
                        temp=temp->link;
                    }
                    if(t==0)
                    {
                        fprintf(book,"\n%10s %10s %5d %5d",p->Book_Name,p->Author_Name,p->Book_id,1);
                    }

                    fclose(book);

                    reserve->link=p->link;

                    p=reserve;

                    FILE *BookReturns;
                    BookReturns=fopen("StudentsRecord.txt","w");

                    struct student *del;
                    del=student_head;
                    while(del!=NULL)
                    {
                        if(del->Book_id != id  && (strcmp(del->Student_name,name)) != 0)
                        {
                            fprintf(BookReturns,"\n%10s %20s %10s %10s  %5d",del->Student_name,del->Student_email,del->Book_Name,del->Author_Name,del->Book_id);
                        }
                        del=del->link;
                    }
                    fclose(BookReturns);
                }
                 p=p->link;
        }

        if(flag==1)
        {
            printf("\n\n\t\t\t\t ******************************\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|  BOOK RETURNED SUCCESSFULLY  |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t|                              |\n");
                printf("\t\t\t\t ******************************\n");
        }
        else
        {
            printf("\n\n\t\tRecord Not Found !!!!\n");
        }

    }

void greetings()
    {
            printf("\n\n");
            printf("\t\t\t     ***********************************************************\n");
            printf("\t\t\t     *              FA20-BSE-007@cuilahore.edu.pk              *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *      WELCOME TO STUDENT LIBRARY  MANAGEMENT SYSTEM      *\n");
            printf("\t\t\t     *     ________________________________________________    *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                  DSA FINALS PROJECT                     *\n");
            printf("\t\t\t     *                 _____________________                   *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     *                   MUHAMMAD SAMIULLAH                    *\n");
            printf("\t\t\t     *                   FA20-BSE-007                          *\n");
            printf("\t\t\t     *                   SECTION B                             *\n");
            printf("\t\t\t     *                                                         *\n");
            printf("\t\t\t     ***********************************************************\n\n\n");


        }











