#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    char string[255], *ps = NULL;
    FILE *f;
    int sizze = 0, pos = 0;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        while (f == NULL) {
            printf("Please enter the correct file name\n");
            scanf("%s\n", argv[1]);
        }
    }
    while (fgets(string, sizeof(string), f))
    {
            ps = fgets(string, sizeof(string), f);
            pos++;
            printf("%s\n", ps);
    }
    rewind(f);
    while ((fgetc(f)) != EOF)
        sizze++;
    fclose(f);
    printf("Written %d records, total %d bytes\n", pos, sizze);
    return 0;
}
