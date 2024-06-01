                                            /*EMPLOYEES MANAGEMENT SYSTEM*/
/*Name: Hafiz Muhammad Zaman Khan                          Reg no:FA21-BSE-063                         Section:B */


#include <stdio.h>                   //including all the necessary header files
#include <stdlib.h>                  //Header file
#include <windows.h>                 //Header file for console window
#include <conio.h>                   //header file for clear screen
#include <string.h>                  //header file for strings

/*Defining structure for Employees Record*/
struct emprecord
{
    int reg_no;
    char fullname[30];
    int age;
    int salary;
    char address[50];
    char rank[50];
    char emailaddress[50];
    char phoneno[50];
    char username[50];
    char password[30];

};

/*Function for showing Password in asterisk form*/
void takepassword(char pass[50])
{
    int i;
    char ch;
    while(1)
    {
        ch = getch();               // Getting character and storing it in ch variable
        if(ch == 13 || ch == 9)        //13 is for enter and 9 is for tab(ASCII CODE)
        {
            pass[i] = '\0';
            break;
        }
        else if(ch == 8)               //8 is for backspace(ASCII CODE)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");      //Backspaces the character
            }
        }
        else
        {
            pass[i++] = ch;
            printf("*");             // prints the password in asterisk form
        }
    }
}

/*Function for Storing Records in a Binary File*/
void employees_rec(FILE *tp)
{
    struct emprecord erec,emp;   //Declaring all the necessary variables
    char password2[30];         // For Confirming entered password
    char op;
    FILE *fp;                    //Creating a File Pointer

    system("cls");              //Clear screen

    do                  //Start of do while
    {

        printf("\n|Enter your full name|  :\t");       //Getting Full Name of Employee
        fflush(stdin);
        gets(erec.fullname);
        fflush(stdin);
        printf("|Enter Employee Username| :\t");       //Getting Username of Employee
        gets(erec.username);
        printf("|Enter Registration no|   :\t");       //Getting Registration no. of Employee
        scanf("%d",&erec.reg_no);
        printf("|Enter Employee Age|      :\t");       //Getting  Employee's age
        scanf("%d",&erec.age);
        printf("|Enter Employee Salary|   :\t");       //Defining Salary of Employee
        scanf("%d",&erec.salary);
        printf("|Enter Employee Rank|     :\t");       //Giving Rank to the Employee
        fflush(stdin);
        gets(erec.rank);
        printf("|Enter Employee Address|  :\t");       //Getting Employee's Address
        fflush(stdin);
        gets(erec.address);
        printf("|Enter your E-mail|       :\t");       //Getting E-mail of Employee
        fflush(stdin);
        gets(erec.emailaddress);
        printf("|Enter your Contact no|   :\t");
        fflush(stdin);                                      //Getting Contact no. of Employee
        gets(erec.phoneno);
        fflush(stdin);
        printf("|Enter your password|     :\t");       //Defining Password of Employee
        takepassword(erec.password);
        printf("\n|Confirm your password|   :\t");     //Confirming Password of Employee
        fflush(stdin);
        takepassword(password2);

        if(strcmp(erec.password,password2)==0)           //Comparing the password for Confirmation
        {
            fp = fopen("Employees.dat","ab+");           // Opening fp file in ab+ mode
            fwrite(&erec,sizeof(struct emprecord),1,fp); // Writing the Records of Employees in Binary File(fp)
            if(fwrite != 0) printf("\n\nUser resgistration success");
            else printf("\n\nSorry! Something went wrong :(");
            fclose(fp);                                  // closing the file
        }
        else
        {
            printf("\n\nPassword donot matched");  //else condition

            Beep(750,300);
        }
        printf("\nAdd Another Record (y/n)");     //option for adding another record
        scanf("%c",&op);
        system("cls");
    }
    while(op!='n');                           // End of do while

}

/*Function for Listing Employees records*/
void employees_list(FILE *tp)
{
    struct emprecord erec,emp;
    FILE *fp;                 //File Pointer
    system("cls");
    printf("%10s %15s %15s %15s %5s %10s %20s %15s %20s","|REG NO.|","|Full name|","|Username|","|Rank|","|Age|","|Salary|","|Address|","|Phone Number|","|Email Address|");
    fp = fopen("Employees.dat","rb+");    //Opening fp File in Binary mode
    while(fread(&emp,sizeof(struct emprecord),1,fp))   //Reading all the records in fp file
    {
        printf("\n");
        printf("%8d %15s %15s %15s %5d %10d %20s %15s %20s",emp.reg_no,emp.fullname,emp.username,emp.rank,emp.age,emp.salary,emp.address,emp.phoneno,emp.emailaddress);
    }                                                   // Printing all the records
    printf("\n\nPress any key to go back :) ");
    getch();
    fclose(fp);            // closing the file
    system("cls");

}

/*Function for modifying records*/
void modify_rec( FILE *fptr)
{
    FILE *temp,*fp1;            // creating two binary files
    struct emprecord erec;
    int choice;
    char empname[50];
    while(1)                    // while loop
    {
        system("cls");
        printf("\n\nEnter the Employee Username which record\n");
        printf("you want to modify/update Or press n to exit : ");
        fflush(stdin);
        gets(empname);
        if(strcmp(empname,"n")==0)   //Breaking point of while loop
        {
            break;
        }
        fp1 = fopen("Employees.dat","rb");       //opening fp1 in rb mode(read mode)
        temp = fopen("Temp.dat","wb");           //opening temp file in wb mode(write mode)
        while(fread(&erec,sizeof(struct emprecord),1,fp1))   //Reading all the records of fp1
        {
            if(strcmp(erec.username,empname)==0)                 //Comparing username with the name
            {
B:
                system("cls");                                   /* goto statement so control goes back to the menu after modifying a single element of a record*/
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\ Record Modification\n");
                printf("\t\t\t\t1. Modify name\n");
                printf("\t\t\t\t2. Modify Username\n");
                printf("\t\t\t\t3. Modify Registration No.\n");
                printf("\t\t\t\t4. Modify Age\n");                       /*switch menu*/
                printf("\t\t\t\t5. Modify Salary\n");
                printf("\t\t\t\t6. Modify Rank\n");
                printf("\t\t\t\t7. Modify Address\n");
                printf("\t\t\t\t8. Modify E-mail\n");
                printf("\t\t\t\t9. Modify Contact\n");
                printf("\t\t\t\t10. Modify Password\n");
                printf("\t\t\t\t11. Exit System\n");
                printf("\t\t\t\tSelect your desired option : ");
                scanf("%d",&choice);                           //Enter your choice

                switch(choice)
                {
                case 1:
                    system("cls");                                          /*List of cases*/
                    printf("\n|Enter your full name|  :\t");          /*According to each case the update info is stored in structure variables*/
                    fflush(stdin);
                    gets(erec.fullname);                                   //Modify full name of employee
                    printf("Your name is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;


                case 2:
                    system("cls");
                    fflush(stdin);
                    printf("|Enter Employee Username| :\t");
                    gets(erec.username);                                    //Modify User name of employee
                    printf("Your Username is modified successfully :) ");
                    printf("\nress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 3:
                    system("cls");
                    printf("|Enter Registration no|   :\t");
                    scanf("%d",&erec.reg_no);                               //Modify Reg NO of employee
                    printf("Your Registration no is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 4:
                    system("cls");
                    printf("|Enter Employee Age|      :\t");
                    scanf("%d",&erec.age);                                  //Modify Age of employee
                    printf("The age of this employee is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 5:
                    system("cls");
                    printf("|Enter Employee Salary|   :\t");
                    scanf("%d",&erec.salary);                               //Modify Salary of employee
                    printf("The Employee Salary is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 6:
                    system("cls");
                    printf("|Enter Employee Rank|     :\t");
                    fflush(stdin);
                    gets(erec.rank);                                          //Modify Rank of employee
                    printf("The Employee Rank is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 7:
                    system("cls");
                    printf("|Enter Employee Address|  :\t");
                    fflush(stdin);
                    gets(erec.address);                                     //Modify Addres of employee
                    printf("This Employee Address is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 8:
                    system("cls");
                    printf("|Enter your E-mail|       :\t");
                    fflush(stdin);
                    gets(erec.emailaddress);                                //Modify Email Address of employee
                    printf("The E-mail of this employee is modified successfully :) ");
                    printf("\nress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 9:
                    system("cls");
                    printf("|Enter your Contact no|   :\t");
                    fflush(stdin);                                      //Getting Contact no. of Employee
                    gets(erec.phoneno);                           //Modify Phone no of employee
                    printf("Contact no of this employee is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 10:
                    system("cls");
                    fflush(stdin);
                    printf("|Enter your password|     :\t");
                    takepassword(erec.password);                            //Modify Password of employee
                    printf("The password of this employee is modified successfully :) ");
                    printf("\nPress any key to go back on Updation menu\n");
                    getch();
                    goto B;
                    break;

                case 11:                                  //Exit point of switch
                    system("cls");
                    break;


                }


            }
            fwrite(&erec,sizeof(struct emprecord),1,temp);      //writing the updated info in a temporary file

        }
        fclose(fp1);                                              /*closing both of the file*/
        fclose(temp);

        temp = fopen("Temp.dat","rb+");                           //opening temp file in rb+ mode(read mode)
        fp1 = fopen("Employees.dat","wb+");                        //opening fp1 file in wb+ mode(write mode)


        while(fread(&erec,sizeof(struct emprecord),1,temp))      /*Reading all the records of temp files and writing them in fp1 file*/
        {
            fwrite(&erec,sizeof(struct emprecord),1,fp1);
        }
        fclose(fp1);                                       /*closing both of the files*/
        fclose(temp);
    }
    system("cls");
}

/*Function for deleting records*/
void delete_rec( FILE *fptr)
{
    system("cls");
    FILE *temp,*fp1;                   //creating two binary files
    struct emprecord erec;
    int choice;
    char empname[50];
    int userfound=0;                    //Declaring a userfound variable
    while(1)                           //while loop
    {
        printf("Enter the Employee username which record\n");
        printf("you want to delete Or press n to exit : ");
        fflush(stdin);
        gets(empname);
        if(strcmp(empname,"n")==0)      //Breaking point of while loop
        {
            break;
        }
        fp1 = fopen("Employees.dat","rb");      //opening fp1 in rb mode(read mode)
        temp = fopen("Temp.dat","wb");          //opening fp1 in wb mode(write mode)


        while(fread(&erec,sizeof(struct emprecord),1,fp1))   //Reading all the records from fp1
        {
            if(strcmp(erec.username,empname)==0)                 //if condition executes if the required record is found and
            {
                //userfound becomes equal to one
                userfound=1;
                printf("\n\nThis employee details is deleted successfully\n\n");
            }
            else
                fwrite(&erec,sizeof(struct emprecord),1,temp);        //All the records other than the required record is shifted to temp file


        }
        fclose(fp1);                                        /*closing both the files*/
        fclose(temp);
        if(userfound!=1)
        {
            printf("\n\nRecord against this username is not exists :(\n\n");
        }
        if(userfound)                                        //condition is executed if userfound becomes equal to 1
        {
            temp = fopen("Temp.dat","rb+");                      // opening temp file in rb+ mode(read mode)
            fp1 = fopen("Employees.dat","wb+");                  // opening fp1 file in wb+ mode(write mode)


            while(fread(&erec,sizeof(struct emprecord),1,temp))  /*Reading all the records of temp files and writing them in fp1 file*/
            {
                fwrite(&erec,sizeof(struct emprecord),1,fp1);
            }
            fclose(fp1);                                       /*Closing both of the files*/
            fclose(temp);
        }

    }
    system("cls");
}
int main()                                            // Main function
{
    system("color 0a");                     //Command for changing text color in console
    int select,choice;
    struct emprecord erec,emp;
    char password2[50];                       /*Declaring all the necessary variables*/
    char username[25];
    char password[50];
    char username2[50];
    char pswrd[50];
    int opt;
    char op;
    FILE *fp;                              //File pointer
    int usrFound = 0;                      //userFound variable

    printf("\n\n\n\n\n\n\t\t\t\t*************************************");
    printf("\n\n\t\t\t\t    EMPLOYEE MANAGEMENT SYSTEM\n");
    printf("\n\t\t\t\t*************************************");
    printf("\n\n\n\n\n\t\t\t\t1. Administrator\n");
                                                                 /*Main menu of Employee management System*/
    printf("\n\t\t\t\t2. Employer Details\n");
    printf("\n\t\t\t\t3. Exit\n\n");
    printf("\t\t\t\tSelect your desired option : ");
    scanf("%d",&select);
    while(1)                                              //while loop
    {
        if(select == 3)                               //Breaking point of while
        {   system("cls");
            exit(0);
        }
        switch(select)                                  //Switch
        {
        case 1:                                       //case 1
            system("cls");
            printf("\n\n\n\t\t\t\t\tWelcome to Administration Department\n\n\n");
            printf("\t\t\t\t\t\t Login Details\n\n");
            printf("\t\t\t\tUsername : ");                                 /* Credentials for the Administrative control */
            scanf("%s",&username);
            printf("\n\t\t\t\tPassword : ");
            takepassword(password);
            if(strcmp(username,"admin")==0)                                 /*Admin credential verification*/
            {
                if(strcmp(password,"6732")==0)
                {
                    system("cls");
                    do                                                       //Start of do whiile
                    {

                        printf("\n\n\n\n\t\t\t\t\t  Welcome Administrator\n\n");
                        printf("\t\t\t\t\t1. Add Employee's Records\n\n");            /*Administrator control menu*/
                        printf("\t\t\t\t\t2. List Employee's Records\n\n");
                        printf("\t\t\t\t\t3. Modify Employee's Records\n\n");
                        printf("\t\t\t\t\t4. Delete Employee's Records\n\n");
                        printf("\t\t\t\t\t5. Go to Main Menu\n\n");
                        printf("\n\n\t\t\t\t\tSelect your desired option : ");
                        scanf("%d",&choice);
                        switch(choice)                                            //switch
                        {
                        case 1:
                            employees_rec(fp);
                            break;
                        /*List of cases where functions are called according to the given case*/
                        case 2:
                            employees_list(fp);   //employees_list function is used to list all records
                            break;

                        case 3:
                            system("cls");
                            modify_rec(fp);       //modify_rec function is used to modify fields in a particular record
                            break;

                        case 4:
                            delete_rec(fp);      //delete_rec function is used to delete records
                            break;

                        case 5:                            //Returning Point to the start of main function(i.e main menu)
                            system("cls");
                            main();
                        }
                    }
                    while (1);                            //End of do while

                }
                else
                {
                    printf("\n\n\t\t\t\t\tInvalid Password\n");
                    getch();
                }

            }                                                     /*if either of the credentials does not match than gives a invalid message*/
            else
            {
                printf("\n\n\t\t\t\t\tInvalid Username\n");
                getch();
            }
            break;
        case 2:                                     //case 2
            system("cls");
            printf("\n\n\n\n\n\t\t\tEnter you Login Details to Access your Information");
            fflush(stdin);
            printf("\n\n\n\t\t\tEnter your username:\t");                 /*Employee account credential*/
            gets(username2);
            printf("\n\n\t\t\tEnter your password:\t");
            takepassword(pswrd);

            fp = fopen("Employees.dat","rb+");                    //opening fp file in rb+ mode(read mode)

            while(fread(&emp,sizeof(struct emprecord),1,fp))     //Reading all the records of fp file
            {
                if(strcmp(emp.username,username2)==0)            /*Verification of username and password of employee*/
                {
                    if(strcmp(emp.password,pswrd)==0)
                    {
                        system("cls");
                        printf("\n\t\t\t\t\t\tWelcome %s",emp.fullname);
                        printf("\n\n");
                        printf("| Registration Number | :\t%d\n",emp.reg_no);
                        printf("|      Full Name      | :\t%s\n",emp.fullname);      /*List of all the info about the employee*/
                        printf("|      Username       | :\t%s\n",emp.username);
                        printf("|    Phone Number     | :\t%s\n",emp.phoneno);
                        printf("|        Age          | :\t%d\n",emp.age);
                        printf("|       Salary        | :\t%d\n",emp.salary);
                        printf("|        Rank         | :\t%s\n",emp.rank);
                        printf("|       Address       | :\t%s\n",emp.address);
                        printf("|    E-mail Address   | :\t%s\n",emp.emailaddress);
                        printf("\n\nPress any key to go on main menu :) "); //Press n to go back to main menu
                        getch();
                        system("cls");
                        main();

                    }
                    else                                           //if credentials does not display an invalid message
                    {
                        printf("\n\nInvalid Password!");
                        Beep(800,300);
                        getch();
                    }
                    usrFound = 1;
                }
            }
            if(usrFound==0)                                  /*if userfound is 0 it means that the employee is not registered so it shows an error message*/
            {
                printf("\n\nUser is not registered!");
                system("cls");
                main();                                       //Returns to main
                Beep(800,300);
                getch();
            }
            fclose(fp);                               //closing the file

            break;
        }
    }
    return 0;
}                                          //End
