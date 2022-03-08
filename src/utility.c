/*****************************************************************************************************
** FILENAME       :    utility.c
**
** DESCRIPTION    :    Contains the function utility
**
** Revision History   :    V_1.0
**
** DATE
** ------------------------------------------------------------------------------------------------
** 08 MAR 2022               
** 
** 
** Copyright © 2022 Capgemini Group All Rights Reserved
**
*****************************************************************************************************/

/*************************************************************************
                        HEADER FILES
**************************************************************************/

#include <utility.h>


void textSearch()
{
	FILE *fp;
	FILE *files;
	char* x;
	char *string = NULL;
	char temp[MAX];
	x = (char*) malloc (100 * sizeof(char));

	printf("\nEnter the String to be searched : ");
	fgets(temp,MAX,stdin);

	string = (char*) malloc (strlen(temp) * sizeof(char));
	strcpy(string,temp);
	
	string[strcspn(string, "\n")] = 0;
	sprintf(x,"find . -type f -name %c*%c > test.txt",34,34);
	
	if(system(x) != 0 )
	{
		printf("System call not possible\n");
	}

	char buff[10000];
	
	fp = fopen("test.txt","r+");
	
	printf("Files with string match are :: \n");

	while(fgets(buff,10000,fp) != NULL)
	{
		buff[strcspn(buff, "\n")] = 0;
		
		files = fopen(buff,"r+");
		if(files != NULL)
		{
		//	printf("%s",buff);
			while(!feof(files))
			{
				fgets(temp,MAX,files);
				if(strstr(temp,string) != NULL)
				{	
					printf("\t%s\n",buff);
					break;
				}
			}
		}

		fclose(files);
	}
		
	fclose(fp);


	free(string);
	free(x);
	printf("\n");
}
