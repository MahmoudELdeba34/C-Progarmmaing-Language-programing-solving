#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define EXTENDED -32
#define Enter 13
#define ESC 27
#define TAB 9
#define Up 72
#define Home 71
#define Down 80
#define End 79
struct Employee
{
    char name[50];
    int ssn;
    int age;
    int salary;
    int commission;
    int deduction;
};
struct Point
{
    int x;
    int y;
};
struct Point points[6];
struct Employee emp[10];

void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void DrawVar()
{
    gotoxy(0, 5);
    printf("Name:");
    gotoxy(0, 10);
    printf("Age:");
    gotoxy(0, 15);
    printf("Comission:");

    gotoxy(25, 5);
    printf("SSN:");
    gotoxy(25, 10);
    printf("Salary:");
    gotoxy(25, 15);
    printf("Deduction:");
}
void EmployeeEnterData(int indx)
{
    gotoxy(40, 0);
    textattr(1);
    printf("Please Fill Employee Data:");
    textattr(15);
    DrawVar();
    int cntEnter = 1, indxPoint = 0;
        do
        {
            switch(indxPoint)
            {
            case 0:
                gotoxy(points[indxPoint].x, points[indxPoint].y);
                scanf("%s", emp[indx].name);
                _flushall();
                break;
            case 1:
                gotoxy(points[indxPoint].x, points[indxPoint].y);
                int ssnInput = -1;
                scanf("%i", &ssnInput);
                int chk = ValidateEmployeeBySSN(ssnInput);

                if(ssnInput <= 0 || chk != -1)
                {
                    system("cls");
                    gotoxy(40, 15);
                    textattr(4);
                    if(ssnInput <= 0)
                    {
                        printf("Please Enter SSN Greater Than 0!");
                    }
                    else
                    {
                        printf("This SSN IS Exist Before!");
                    }
                    getch();
                    system("cls");
                    EmployeeEnterData(indx);
                }
                else
                    emp[indx].ssn = ssnInput;
                _flushall();
                break;
            case 2:
                gotoxy(points[indxPoint].x, points[indxPoint].y);
                scanf("%i", &emp[indx].age);
                _flushall();
                break;
            case 3:
                gotoxy(points[indxPoint].x, points[indxPoint].y);
                scanf("%i", &emp[indx].salary);
                _flushall();
                break;
            case 4:
                gotoxy(points[indxPoint].x, points[indxPoint].y);
                scanf("%i", &emp[indx].commission);
                _flushall();
                break;
            case 5:
                gotoxy(points[indxPoint].x, points[indxPoint].y);
                scanf("%i", &emp[indx].deduction);
                _flushall();
                break;
            }
            _flushall();
            cntEnter++;
            indxPoint++;
        }
        while(cntEnter != 7);
}
int ValidateEmployeeByIndx(int indx)
{
    return (emp[indx].ssn == -1) ? 1 : -1;
}
int ValidateEmployeeBySSN(int SSN)
{
    for(int i = 0; i < 10; i++)
    {
        if(emp[i].ssn == SSN)
            return i;
    }

    return -1;
}
int ValidateEmployeeByName(char *Name)
{
    for(int i = 0; i < 10; i++)
    {
        if(strcmp(Name, emp[i].name) == 0)
            return i;
    }
    return -1;
}
void Case0()
{
    int indx = -1;
    do{
        system("cls");
        gotoxy(15 , 15);
        printf("Please Choose The Index U Want To Insert Into From 0 : 9\n");
        gotoxy(15 , 16);
        printf("Indx: ");
        gotoxy(21 , 16);
        scanf("%i", &indx);
    }
    while(indx < 0 || indx > 9);
    //Check if Value of Employee's SSN = -1 or Not;
    int checkExistBefore = ValidateEmployeeByIndx(indx);

    system("cls");
    if(checkExistBefore != -1)
    {
        EmployeeEnterData(indx);
        system("cls");
        textattr(2);
        gotoxy(15 , 15);
        printf("Successful Inserted Data!\n");
        getch();
    }
    else
    {
        textattr(4);
        gotoxy(15 , 15);
        printf("Sorry This Index is be inserted Before!\n");
        getch();
    }
}
void Case1()
{
    int cnt = 1;
    for(int i = 0; i < 10; i++)
    {
        if(emp[i].ssn != -1)
        {
            printf("Data of Employee No. %i\n", cnt++);
            printf("Employee Name: %s\n", emp[i].name);
            printf("Employee SSN: %i\n", emp[i].ssn);
            printf("Employee Age: %i\n", emp[i].age);
            printf("Employee Salary: %i\n", emp[i].salary);
            printf("Employee commission: %i\n", emp[i].commission);
            printf("Employee deduction: %i\n", emp[i].deduction);
            printf("Employee Net Salary: %i\n\n", (emp[i].salary + emp[i].commission - emp[i].deduction));
        }
    }
    if(cnt == 1)
    {
        system("cls");
        gotoxy(40, 15);
        textattr(4);
        printf("No Data To Show!");
    }
}
void Case2()
{
    int SSN = -1;

    gotoxy(15, 15);
    printf("Please Enter The Employee SSN\n");

    gotoxy(15 , 16);
    printf("SSN: ");
    gotoxy(21 , 16);
    scanf("%i", &SSN);
    int indx = ValidateEmployeeBySSN(SSN);
    system("cls");
    if(indx != -1 && SSN != -1)
    {
            printf("Employee Name: %s\n", emp[indx].name);
            printf("Employee SSN: %i\n", emp[indx].ssn);
            printf("Employee Age: %i\n", emp[indx].age);
            printf("Employee Salary: %i\n", emp[indx].salary);
            printf("Employee commission: %i\n", emp[indx].commission);
            printf("Employee deduction: %i\n", emp[indx].deduction);
            printf("Employee Net Salary: %i\n\n", (emp[indx].salary + emp[indx].commission - emp[indx].deduction));
    }
    else
    {
        textattr(4);
        gotoxy(15 , 15);
        printf("Sorry This SSN Is Not Found!\n");
    }
}
void Case3()
{
    char Name[50];

    gotoxy(15, 15);
    printf("Please Enter The Employee Name\n");

    gotoxy(15 , 16);
    printf("Name: ");

    gotoxy(21 , 16);
    scanf("%s", Name);

    int indx = ValidateEmployeeByName(Name);
    system("cls");
    if(indx != -1 && emp[indx].ssn != -1)
    {
        for(int i = 0; i < 10; i++)
        {
            if(emp[i].ssn != -1 && strcmp(emp[i].name, Name) == 0)
            {
                printf("Employee Name: %s\n", emp[i].name);
                printf("Employee SSN: %i\n", emp[i].ssn);
                printf("Employee Age: %i\n", emp[i].age);
                printf("Employee Salary: %i\n", emp[i].salary);
                printf("Employee commission: %i\n", emp[i].commission);
                printf("Employee deduction: %i\n", emp[i].deduction);
                printf("Employee Net Salary: %i\n\n", (emp[i].salary + emp[i].commission - emp[i].deduction));
            }
        }
    }
    else
    {
        textattr(4);
        gotoxy(15 , 15);
        printf("Sorry This Name Is Not Found!\n");
    }
}
void Case4()
{
    int SSN = -1;

    gotoxy(15, 15);
    printf("Please Enter The Employee SSN\n");

    gotoxy(15 , 16);
    printf("SSN: ");

    gotoxy(21 , 16);
    scanf("%i", &SSN);

    int indx = ValidateEmployeeBySSN(SSN);
    system("cls");
    if(indx != -1 && SSN != -1)
        {
            char ans;
            do
            {
                gotoxy(20 , 16);
                printf("Are You Sure To Delete Employee Data with SSN: %i?\n", SSN);
                gotoxy(20 , 17);
                printf("Enter Y: To Delete!\n");
                gotoxy(20 , 18);
                printf("N: To Not!\n");
                gotoxy(20 , 20);
                printf("Answer: \n");
                gotoxy(28 , 20);
                scanf("%c", &ans);
            }
            while(ans != 'Y' && ans != 'N');
            system("cls");

            if(ans == 'Y')
            {
                emp[indx].ssn = -1;
                textattr(2);
                gotoxy(15 , 15);
                printf("Successfully Deleted Employee with SSN: %i!\n", SSN);
            }
            else
            {
                textattr(2);
                gotoxy(15 , 15);
                printf("No Data Deleted!\n");
            }
        }
        else
        {
            textattr(4);
            gotoxy(15 , 15);
            printf("Sorry This SSN Is Not Found!\n");
        }
}
void Case5()
{

        char Name[50];

        gotoxy(15, 15);
        printf("Please Enter The Employee Name\n");

        gotoxy(15 , 16);
        printf("Name: ");

        gotoxy(21 , 16);
        scanf("%s", Name);

        int indx = ValidateEmployeeByName(Name);
        system("cls");

        if(indx != -1 && emp[indx].ssn != -1)
        {
            char ans;
            do
            {
                system("cls");
                gotoxy(20 , 16);
                printf("Are You Sure To Delete Employee Data with Name: %s?\n", Name);
                gotoxy(20 , 17);
                printf("Enter Y: To Delete!\n");
                gotoxy(20 , 18);
                printf("N: To Not!\n");
                gotoxy(20 , 20);
                printf("Answer: \n");
                gotoxy(28 , 20);
                scanf("%c", &ans);
            }
            while(ans != 'Y' && ans != 'N');
            system("cls");
            if(ans == 'Y')
            {
                int cnt = 0;
                for(int i = 0; i < 10; i++)
                {
                    if(emp[i].ssn != -1 && strcmp(emp[i].name, Name) == 0){
                        emp[i].ssn = -1;
                        cnt++;
                    }
                }
                textattr(2);
                gotoxy(15 , 15);
                printf("Successfully Deleted No. %i Employees with Name: %s!\n", cnt, Name);
            }
            else
            {
                textattr(2);
                gotoxy(15 , 15);
                printf("No Data Deleted!\n");
            }
        }
        else
        {
            textattr(4);
            gotoxy(15 , 15);
            printf("Sorry This Name Is Not Found!\n");
        }

}
void Case6()
{
    char ans;
    do
    {
        system("cls");
        gotoxy(20 , 16);
        printf("Are You Sure Delete All Employee Data..\n");
        gotoxy(20 , 17);
        printf("Enter Y: to Delete All\n");
        gotoxy(20 , 18);
        printf("N: To Not\n");
        gotoxy(20 , 20);
        printf("Answer: \n");
        gotoxy(28 , 20);
        scanf("%c", &ans);
    }
    while(ans != 'Y' && ans != 'N');
    system("cls");

    if(ans == 'Y')
    {
        for(int i = 0; i < 10; i++)
        {
            emp[i].ssn = -1;
        }
        textattr(2);
        gotoxy(15 , 15);
        printf("Successfully Deleted All Employees\n");
    }
    else
    {
        textattr(2);
        gotoxy(15 , 15);
        printf("No Data Deleted!\n");
    }
}





int main()
{
    int cursor = 0, flag = 0;
    char ch;
    char Options[8][20]={"New", "DisplayAll", "DisplayById", "DisplayByName", "DeleteById", "DeleteByName", "DeleteAll", "Exit"};
    //Fill Data of Point Array
    points[0] = (struct Point){6, 5};
    points[1] = (struct Point){30, 5};
    points[2] = (struct Point){4, 10};
    points[3] = (struct Point){32, 10};
    points[4] = (struct Point){10, 15};
    points[5] = (struct Point){35, 15};
    //Fill all SSN by Default Value -1 that mean this index is free to be inserted.
    for (int i = 0; i < 10; i++) {
        emp[i].ssn = -1;
    }


    do
    {
        system("cls");
        for (int i = 0; i < 8; i++)
        {
            if(i == cursor)
                textattr(4);
            else
                textattr(7);

            gotoxy(15, 15 + i);
            _cprintf("%s", Options[i]);
        }

        ch = getch();
        switch(ch)
        {
            case EXTENDED:
            ch=getch();
            switch(ch)
            {
                case Up:
                cursor--;
                if(cursor < 0)
                    cursor = 7;
                break;
                case Down:
                cursor++;
                if(cursor > 7)
                    cursor = 0;
                break;
                case Home:
                cursor = 0;
                break;
                case End:
                cursor = 7;
                break;
            }
            break;
            case Enter:
            switch(cursor)
            {
                case 0:
                system("cls");
                Case0();
                //getch();
                break;
                case 1:
                system("cls");
                Case1();
                getch();
                break;
                case 2:
                system("cls");
                Case2();
                getch();
                break;
                case 3:
                system("cls");
                Case3();
                getch();
                break;
                case 4:
                system("cls");
                Case4();
                getch();
                break;
                case 5:
                system("cls");
                Case5();
                getch();
                break;
                case 6:
                system("cls");
                Case6();
                getch();
                break;
                case 7:
                flag = 1;
                break;
            }
            break;
            case ESC:
            flag=1;
            break;
            case TAB:
            cursor++;
            if(cursor > 7){cursor = 0;}
            break;
        }

    }
    while(flag == 0);


    return 0;
}
