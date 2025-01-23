#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 3  // Number of employees

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
    float commission;
    float deduction;
};

void clearScreen() {
    system("cls");
}

// Display employee data with the active field highlighted
void displayEmployee(struct Employee *emp, int highlight, int employeeNumber) {
    clearScreen();
    printf("Editing Employee %d\n", employeeNumber);
    printf("Use Enter to navigate and edit fields:\n\n");

    printf("%s ID: %-10d %s Name: %-20s\n",
           (highlight == 0 ? ">>" : "  "), emp->id,
           (highlight == 1 ? ">>" : "  "), emp->name);
    printf("%s Age: %-10d %s Salary: %-10.2f\n",
           (highlight == 2 ? ">>" : "  "), emp->age,
           (highlight == 3 ? ">>" : "  "), emp->salary);
    printf("%s Commission: %-10.2f %s Deduction: %-10.2f\n",
           (highlight == 4 ? ">>" : "  "), emp->commission,
           (highlight == 5 ? ">>" : "  "), emp->deduction);
}

// Convert a string to uppercase
void convertToUpper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Line editor function to handle text input
void lineEditor(char *buffer, int size) {
    int index = 0;
    int ch;

    while (index < size - 1) {
        ch = getch();
        if (ch == 13) {  // Enter key
            break;
        } else if (ch == 8) {  // Backspace key
            if (index > 0) {
                index--;
                printf("\b \b");
            }
        } else if (isprint(ch)) {  // Printable character
            buffer[index++] = ch;
            putchar(ch);
        }
    }
    buffer[index] = '\0';
}

// Edit employee data using lineEditor for each field
void editEmployee(struct Employee *emp, int employeeNumber) {
    int highlight = 0;
    char buffer[50];

    printf("Editing Employee %d:\n", employeeNumber);
    printf("-----------------------\n");

    while (1) {
        displayEmployee(emp, highlight, employeeNumber);

        int ch = getch();
        if (ch == 13) {  // Enter key to edit the field
            clearScreen();
            switch (highlight) {
                case 0:
                    printf("Employee %d - Enter ID: ", employeeNumber);
                    lineEditor(buffer, sizeof(buffer));
                    emp->id = atoi(buffer);  // Convert to integer
                    break;
                case 1:
                    printf("Employee %d - Enter Name: ", employeeNumber);
                    lineEditor(emp->name, sizeof(emp->name));
                    convertToUpper(emp->name);  // Convert name to uppercase
                    break;
                case 2:
                    printf("Employee %d - Enter Age: ", employeeNumber);
                    lineEditor(buffer, sizeof(buffer));
                    emp->age = atoi(buffer);  // Convert to integer
                    break;
                case 3:
                    printf("Employee %d - Enter Salary: ", employeeNumber);
                    lineEditor(buffer, sizeof(buffer));
                    emp->salary = atof(buffer);  // Convert to float
                    break;
                case 4:
                    printf("Employee %d - Enter Commission: ", employeeNumber);
                    lineEditor(buffer, sizeof(buffer));
                    emp->commission = atof(buffer);  // Convert to float
                    break;
                case 5:
                    printf("Employee %d - Enter Deduction: ", employeeNumber);
                    lineEditor(buffer, sizeof(buffer));
                    emp->deduction = atof(buffer);  // Convert to float
                    break;
            }
            highlight++;
            if (highlight > 5) {
                break;
            }
        }
    }
}

// Display final data for each employee
void displayData(struct Employee emp, int employeeNumber) {
    printf("\nEmployee %d Data:\n", employeeNumber);
    printf("ID: %-10d Name: %-20s\n", emp.id, emp.name);
    printf("Age: %-10d Salary: %-10.2f\n", emp.age, emp.salary);
    printf("Commission: %-10.2f Deduction: %-10.2f\n", emp.commission, emp.deduction);
}

int main() {
    struct Employee employees[MAX_EMPLOYEES] = {0};

    // Start data entry for each employee
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        editEmployee(&employees[i], i + 1);
    }

    // Display all employee data
    clearScreen();
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        displayData(employees[i], i + 1);
    }

    return 0;
}
