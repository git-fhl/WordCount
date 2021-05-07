#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE 500

int main(int argc, char* argv[])
{
	char data[MAX_LINE]; 
	FILE* fp;            
	int len;            
	int length = 0;

	fp = fopen(argv[2], "rt");
	if (fp == NULL) {
		exit(1);
	}
	else {
		
		while (fgets(data, MAX_LINE, fp) != NULL)
		{
			len = strlen(data);
			data[len - 1] = '\0'; 
		}

		if ((strcmp(argv[1], "-c") == 0)) {
	
			length = len;
			printf("×Ö·ûÊý:%d\n", length);
		}
		else if ((strcmp(argv[1], "-w") == 0)) {
			int i = 0;
			length = 1;
			for (i; i <= len; i++) {
				if ((data[i] == ',') || (data[i] == ' ')) {
					length++;
				}
			}
			printf("µ¥´ÊÊý:%d\n", length);
		}

		fclose(fp);
	}

	return 0;
}