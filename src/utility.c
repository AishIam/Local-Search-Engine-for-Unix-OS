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

GSList* textSearch()
{
	int i = 0;
	int count = 0;
	char *string = NULL;
	char temp[MAX_BUFF];
	GSList *wordMatch = NULL;	
	FILE *files;	
	// To clear out the \n from the stream
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
    		continue;
	}

	printf("\nEnter the String to be searched : ");
	fgets(temp,MAX_BUFF,stdin);

	string = (char*) malloc (strlen(temp) * sizeof(char));
	strcpy(string,temp);

	//Stripping the \n from the fgets().	
	string[strcspn(string, "\n")] = 0;
	
	printf("Files with string match are :: \n");

	for(i = 0; i < g_slist_length(list); i++)
	{
		files = fopen((char*)g_slist_nth_data(list,i),"r");
		if(files != NULL)
		{
			while(!feof(files))
			{
				fgets(temp,MAX_BUFF,files);
				if(strstr(temp,string) != NULL)
				{	
					printf("\t%d  %s\n", count +1, (char*)g_slist_nth_data(list,i));
					wordMatch = g_slist_prepend(wordMatch,strdup((char*)g_slist_nth_data(list,i)));
					count++;
					break;
				}
			}
		}
		if(files != NULL)
			fclose(files);
	}
	printf("\n");		
	free(string);

	return (wordMatch);
}

int fileSearch(char *file_path)
{
	/* local variables */
	char buffer[MAX_BUFF];
	int fd = 0;
	int sz = 0;
	
	//int c;
	
	//while ((c = getchar()) != '\n' && c != EOF) {
    	//	continue;
	//}
	
	/* Open file specified by user in read mode */
	fd = open(file_path, O_RDONLY);
	if(fd < 0)
	{
		perror("\nCould not open file!"); //Error Handling
		return EXIT_FAILURE;
	}
	
	printf("\nFile contents are:\n--------------------------------\n");

	sz = read(fd, buffer, MAX_BUFF);
	buffer[sz] = '\0';
	while(sz != 0)
	{
		printf("%s", buffer);
		sz = read(fd, buffer, MAX_BUFF);
		buffer[sz] = '\0';
	}
	
	printf("\n");
	
	/* Close the file */	
	if(close(fd) < 0)
	{
		perror("\nCould not close file!"); //Error Handling
		return EXIT_FAILURE;
	}
	
	/* Return success */
	return EXIT_SUCCESS;
}
