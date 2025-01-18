#include <stdio.h>
#include <string.h>

// Define a structure for Employee
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to input employee data
void inputEmployee(struct Employee *emp) {
    printf("Enter employee ID: ");
    scanf("%d", &emp->id); // Accessing struct member using arrow operator
    printf("Enter employee name: ");
    scanf(" %[^\n]", emp->name); // Read string with spaces
    printf("Enter employee salary: ");
    scanf("%f", &emp->salary); // Accessing struct member using arrow operator
}

// Function to display employee data
void displayEmployee(struct Employee *emp) {
    printf("\nEmployee Details:\n");
    printf("ID: %d\n", emp->id);          // Accessing struct member using arrow operator
    printf("Name: %s\n", emp->name);      // Accessing struct member using arrow operator
    printf("Salary: %.2f\n", emp->salary); // Accessing struct member using arrow operator
}

int main() {
    struct Employee emp; // Declare an Employee struct
    struct Employee *empPtr = &emp; // Declare a pointer to Employee and assign it the address of emp

    // Input employee data
    inputEmployee(empPtr);

    // Display employee data
    displayEmployee(empPtr);

    return 0;
}
