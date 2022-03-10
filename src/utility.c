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

int flag = 0;

GSList *list = NULL;

void populatePaths(char* base_path,char* result, char* path)
{
	DIR *d;
  	struct dirent *dir;
  	if(flag == 0)
	{
		flag = 1;
		chdir(base_path);	
	}	
	d = opendir( "." );
  	
	if( d == NULL ) 
	{
   		 return;
	}
	while( ( dir = readdir( d ) ) ) {
    		if( strcmp( dir->d_name, "." ) == 0 || 
        	strcmp( dir->d_name, ".." ) == 0 )
	{
      		continue;
	}

	if( dir->d_type == DT_DIR )
	{
      		chdir( dir->d_name );
      		populatePaths(base_path,result, path);
      		chdir( ".." );
	} 
	else 
	{
		int l = 0;
		getcwd( result, MAXPATHLEN );
		if(path != NULL)
			l = strlen(path);
		snprintf(path+l,MAXPATHLEN - l,"%s/%s",result ,dir->d_name);
		list = g_slist_prepend(list,strdup(path));
		memset(path, 0, MAXPATHLEN);	
    	}
  }

	closedir( d );
}

void textSearch()
{
	// add comments
	FILE *fp;
	FILE *files;
	char* x;
	char *string = NULL;
	char temp[MAX];
	int count = 0;

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
    		continue;
	}
	
	x = (char*) malloc (100 * sizeof(char));

	printf("\nEnter the String to be searched : ");
	fgets(temp,MAX,stdin);

	string = (char*) malloc (strlen(temp) * sizeof(char));
	strcpy(string,temp);
	
	string[strcspn(string, "\n")] = 0;
	sprintf(x,"find . -type f -name %c*%c > test.txt",34,34);
	
	if(system(x) != 0 )
	{
		printf("System call not possible\n");   //error file
	}

	char buff[10000];
	
	fp = fopen("test.txt","r+");
	
	printf("Files with string match are :: \n");

	count = 1;

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
					printf("\t%d  %s\n", count,buff);
					count++;
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

int fileSearch()
{
	/* local variables */
	char file_path[PATH_MAX];
	char buffer[MAX];
	int read_len;
	FILE *fp;
	
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
    		continue;
	}
	
	/* get file path from user */
	printf("Enter the path of the file: ");
	fgets(file_path, PATH_MAX, stdin);
	
	/* remove \n from the file path */
	read_len = strlen(file_path);
	if(file_path[read_len - 1] == '\n')
	{
		file_path[read_len - 1] = '\0';
	}
	
	/* Open file specified by user in read mode */
	fp = fopen(file_path, READ_MODE);
	if(fp == NULL)
	{
		fprintf(stderr, "\nCould not open file!"); //Error Handling
		return EXIT_FAILURE;
	}
	
	printf("\nFile contents are:\n--------------------------------\n");
	/* Get lines from the file */
	while(fgets(buffer, MAX, fp) != NULL)
	{
		printf("%s", buffer);
	}
	
	printf("\n");
	
	/* Close the file */
	fclose(fp);
	
	/* Return success */
	return EXIT_SUCCESS;
}
