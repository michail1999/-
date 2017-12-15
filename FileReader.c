#include <stdlib.h>
#include <stdio.h>
#include<string.h>

int main() {
	FILE *file;
	char file_name[30];
	scanf("%s", &file_name);
	file = fopen(file_name, "r");
	if (file == NULL) {
		while (file == NULL){
			printf("%s", "FILE NOT FOUND. Please, try again\n");
			scanf("%s", &file_name);
			file = fopen(file_name, "r");
		}
	}
	
	char text[1000];
	int i = 0;
	char *real_tail;

	while (fgets(text, sizeof(text), file)){
		real_tail = "";


		if (text[strlen(text) - 1] == '\n')
		{
			real_tail = "\\n";
			text[strlen(text) - 1] = '\0';
		};	
		printf("%s\n", text);
	}
	int size = ftell(file);
	printf("File size = %d bytes\n", size);
	fclose(file);
	return 0;
}
