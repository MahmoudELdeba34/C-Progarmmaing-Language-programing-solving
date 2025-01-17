#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h> //علشان احول الحروف الى رحوف كبيره

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
    float commission;
    float deduction;
};

// دى علشان انضف الشاشه
void clearScreen() {
    system("cls");
}

// دالة لعرض بيانات الموظف مع إظهار الخانه النشطه
void displayEmployee(struct Employee *emp, int highlight) {
    clearScreen();
    printf("Use Enter to navigate and edit fields:\n\n");

    // عرض الخانات مع اظهار الحقل النشط
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

// دى انا حابب اعملها ودى بتحل الحروف ال انا دخلتها الى حروف كبيره
void convertToUpper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// دى بتظهر بايانات الموظف
void editEmployee(struct Employee *emp) {
    int highlight = 0;  // بدء من حقل ID
    int ch;

    while (1) {
        displayEmployee(emp, highlight);

        ch = getch();
        if (ch == 13) { // Enter key to edit the field and move to the next
            clearScreen();
            switch (highlight) {
                case 0:
                    printf("Enter ID: ");
                    scanf("%d", &emp->id);
                    break;
                case 1:
                    printf("Enter Name: ");
                    int index = 0;
                    while (index < sizeof(emp->name) - 1) { // الحفاظ على الحجم بتاعى
                        ch = getch(); // قراءة حرف واحد
                        if (ch == 13) { // Enter key
                            break; // الخروج عند الضغط على Enter
                        } else if (ch == 8) { // Backspace key
                            if (index > 0) { // التأكد من وجود حرف لحذفه
                                index--;
                                printf("\b \b"); // حذف الحرف من الشاشة
                            }
                        } else if (isprint(ch)) { // التحقق مما إذا كان حرف قابل للطباعة
                            emp->name[index++] = ch; // إضافة الحرف إلى الاسم
                            putchar(ch); // عرض الحرف
                        }
                    }
                    emp->name[index] = '\0'; //انهاء اللللوووووووووب
                    convertToUpper(emp->name); // تحويل الاسم إلى حروف كبيرة
                    break;
                case 2:
                    printf("Enter Age: ");
                    scanf("%d", &emp->age);
                    break;
                case 3:
                    printf("Enter Salary: ");
                    scanf("%f", &emp->salary);
                    break;
                case 4:
                    printf("Enter Commission: ");
                    scanf("%f", &emp->commission);
                    break;
                case 5:
                    printf("Enter Deduction: ");
                    scanf("%f", &emp->deduction);
                    break;
            }
            highlight++;
            if (highlight > 5) {
                break; // إذا أدخلت البيانات في جميع الحقول، اخرج من الحلقة
            }
        }
    }
}

void displayData(struct Employee emp) {
    printf("\nEmployee Data:\n");
    printf("ID: %-10d Name: %-20s\n", emp.id, emp.name);
    printf("Age: %-10d Salary: %-10.2f\n", emp.age, emp.salary);
    printf("Commission: %-10.2f Deduction: %-10.2f\n", emp.commission, emp.deduction);
}

int main() {
    struct Employee emp = {0, "", 0, 0.0, 0.0, 0.0};

    // بدء إدخال بيانات الموظف
    editEmployee(&emp);

    clearScreen();
    displayData(emp); // عرض البيانات بعد إدخالها

    return 0;
}
