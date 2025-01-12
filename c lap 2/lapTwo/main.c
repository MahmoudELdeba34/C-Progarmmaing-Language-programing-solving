#include <stdio.h>
int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;
    int ageYears, ageMonths, ageDays;

    // Entering birth date
    do {
        printf("Please enter your birth year (1980-2023): ");
        scanf("%d", &birthYear);
    } while (birthYear < 1980 || birthYear > 2023);

    do {
        printf("Please enter your birth month (1-12): ");
        scanf("%d", &birthMonth);
    } while (birthMonth < 1 || birthMonth > 12);

    do {
        printf("Please enter your birth day: ");
        scanf("%d", &birthDay);
    } while (birthDay < 1 || birthDay > 31); // Max limit is 31 will be done

    // Entering current date
    do {
        printf("Please enter the current year: ");
        scanf("%d", &currentYear);
    } while (currentYear < birthYear);

    do {
        printf("Please enter the current month (1-12): ");
        scanf("%d", &currentMonth);
    } while (currentMonth < 1 || currentMonth > 12);

    do {
        printf("Please enter the current day: ");
        scanf("%d", &currentDay);
    } while (currentDay < 1 || currentDay > 31);

    // Validate day based on month for birth and current dates
    switch (birthMonth) {
        case 4: case 6: case 9: case 11:
            if (birthDay > 30) birthDay = 30;
            break;
            //leap year to calculate feb month if 29 or 28

        case 2:
            if ((birthYear % 4 == 0 && birthYear % 100 != 0) || birthYear % 400 == 0) {
                if (birthDay > 29) birthDay = 29;
            } else {
                if (birthDay > 28) birthDay = 28;
            }
            break;
    }

    switch (currentMonth) {
        case 4: case 6: case 9: case 11:
            if (currentDay > 30) currentDay = 30;
            break;
        case 2:
            if ((currentYear % 4 == 0 && currentYear % 100 != 0) || currentYear % 400 == 0) {
                if (currentDay > 29) currentDay = 29;
            } else {
                if (currentDay > 28) currentDay = 28;
            }
            break;
    }

    // Calculate age
    ageYears = currentYear - birthYear;
    ageMonths = currentMonth - birthMonth;
    ageDays = currentDay - birthDay;


    if (ageDays < 0) {
        ageDays += 30; // Assuming the previous month had 30 days
        ageMonths--;
    }
    if (ageMonths < 0) {
       ageMonths += 12;
       ageYears--;
    }

    // Display the age
    printf("Your age is %d years, %d months, and %d days.\n", ageYears, ageMonths, ageDays);

    return 0;
}



