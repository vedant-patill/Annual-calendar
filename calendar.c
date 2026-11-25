#include <stdio.h>

// Function to determine if the given year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

// Function to get the day of the week for January 1st of the given year
// Returns 0 for Sunday, 1 for Monday, ..., 6 for Saturday
int getFirstDayOfYear(int year) {
    int day;
    int d1 = (year - 1) / 4;
    int d2 = (year - 1) / 100;
    int d3 = (year - 1) / 400;
    day = (year + d1 - d2 + d3) % 7;
    return day;
}

int main() {
    int year, month, day, daysInMonth, weekDay = 0, startingDay;

    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter the year: ");
    scanf("%d", &year);

    // Adjust February days if it is a leap year
    if (isLeapYear(year)) {
        monthDays[1] = 29;
    }

    // Find the starting day of January 1st
    startingDay = getFirstDayOfYear(year);

    printf("\n================ CALENDAR - %d ================\n", year);

    for (month = 0; month < 12; month++) {
        daysInMonth = monthDays[month];

        printf("\n\n  ------------ %s %d ------------\n", months[month], year);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print leading spaces for the first week of the month
        for (weekDay = 0; weekDay < startingDay; weekDay++) {
            printf("     ");
        }

        // Print all days of the current month
        for (day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);

            // Move to the next line after Saturday
            if (++weekDay > 6) {
                printf("\n");
                weekDay = 0;
            }
        }

        // Set the starting day for the next month
        startingDay = weekDay;
    }

    printf("\n\n=================================================\n");
    return 0;
}
