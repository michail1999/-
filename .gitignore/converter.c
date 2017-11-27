#include <stdio.h>


int main()
{
    double temperature;
    double k, c, f;
    char system;
    printf("Enter temperature ");
    printf("\nEnter system K-kelvin, C-celsius, F-fahrenheit\n");
    scanf("%lg",&temperature);
    getchar();
    system = getchar();
    if (system == 'C')
    {
        c = temperature;
        k = temperature+273.15;
        f = (temperature*1.8)+32;
        printf("%.2f%s",c,"C\n");
        printf("%.2f%s",k,"K\n");
        printf("%.2f%s",f,"F\n");
    }

    else if (system == 'K')
    {
        k = temperature;
        f = 1.8*(temperature-273.15)+32;
        c = temperature-273.15;
        printf("%.2f%s",k,"K\n");
        printf("%.2f%s",f,"F\n");
        printf("%.2f%s",c,"C\n");
    }
    else if (system == 'F')
    {
        f = temperature;
        c = (temperature-32)*(5/9);
        k = (temperature+459.67)*(5/9);
        printf("%.2f%s",c,"C\n");
        printf("%.2f%s",k,"K\n");
        printf("%.2f%s",f,"F\n");
    }
    else
    {
        c = temperature;
        k = temperature+273.15;
        f = (temperature+32)*1.8;
        printf("%.2f%s",c,"C\n");
        printf("%.2f%s",k,"K\n");
        printf("%.2f%s",f,"F\n");
    }
}
