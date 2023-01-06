/********************************************************************************
* file_read.c: Inneh�ller funktionsdefinition f�r fill�sning.
********************************************************************************/
#include "file_read.h"

/********************************************************************************
* file_read: L�ser angiven fil och skriver ut inneh�llet i terminalen.
********************************************************************************/
int file_read(char* filepath)
{
	FILE* istream = fopen(filepath, "r");

	if (!istream)
	{
		fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
		return 1;
	}
	else
	{
		char s[100] = { '\0' };

		while (fgets(s, sizeof(s), istream))
		{
			printf("%s", s);
		}

		fclose(istream);
		return 0;
	}
}