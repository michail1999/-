#include <stdio.h>

#include <stdlib.h>


int main() {
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int d, m, y, i;

    printf("Enter the date starting at 01-01-1900 before 01-01-3000 species dd-mm-yyyy: ");
    scanf("%d-%d-%d",  &d, &m, &y);

        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
            month[1] = 29;

if (y < 1900 || y>3000 || m < 1 || m > 12 || d < 1 || d > month[m - 1]) {
            printf("The date was entered incorrectly. Please enter a valid date dd-mm-yyyy. \n");
            getchar();
            getchar();
            return 1;

      }

    for (i = 1900; i < y; i++)
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
           d= d + 366;
        else
           d= d + 365;

    for (i = 0; i < m - 1; i++)
        d += month[i];

    printf("This day %s\n", day[d % 7]);
    getchar();
    getchar();
    return 0;
}
