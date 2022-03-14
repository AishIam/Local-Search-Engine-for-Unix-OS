/*****************************************************************************************************
** FILENAME       :    utility.c
**
** DESCRIPTION    :    Contains the function utility
**
** Revision History   :    V_0.4
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

/*********************************************************************************************************
**     FUNCTION NAME       :    populatePaths
**
**     DESCRIPTION         :    Function to take basepath as input from the user and populate all the 
**								sub file paths in a global GSList. If user doesn't enters a base path or enters a
**								wrong base path then file paths of current directory will be stored in GSList.
**
**     FUNCTION TAG        :    LSE/ 01 -1
**
**     RETURNS             :    Return void.
**                               
**
***********************************************************************************************************/

int flag = 0;

GSList *list = NULL;

GSList* populatePaths(char* base_path,char* result, char* path)
{
	DIR *d;
  	struct dirent *dir;
	/*Switching to base path on the first pass in the function, since it a recursive function*/
	if(flag == 0 && strcmp(base_path,"."))
	{
		flag = 1;
		if(chdir(base_path) != 0){
			printf("\nWrong Base Path !!!\nStaring with default Base\n");	
		}
	}	
	d = opendir( "." );
  	
	if( d == NULL ) 
	{
   		 return NULL;
	}
	/*Every directory has . and .. files as default and those are not file but are just pointers to parent and present dir so skipping over them.*/
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
		if((strstr(dir->d_name,".c\0") != NULL) || (strstr(dir->d_name,".h\0") != NULL) || (strstr(dir->d_name,".txt\0") != NULL))

		{
			snprintf(path+l,MAXPATHLEN - l,"%s/%s",result ,dir->d_name);
			
			list = g_slist_prepend(list,strdup(path));
			memset(path, 0, MAXPATHLEN);
		}	
    	}
  }
	closedir( d );
	
	return list;
}

/*********************************************************************************************************
**     FUNCTION NAME       :    textSearch
**
**     DESCRIPTION         :    Function to ask the user to enter a word/string and then looking up for all the files stored
**								in the global GSlist and find those files containing the matching word or string. Lastly,
**								a new GSList with the paths of the files found is populated and the file names are
**								displayed to the user.
**
**     FUNCTION TAG        :    LSE/ 01 -2
**
**     RETURNS             :    Return GSList*
**                               
**
***********************************************************************************************************/

GSList* textSearch(char* str,GSList* list)
{
	/*Declaration*/
	int i = 0;
	int count = 0;
	char *string = str;
	char temp[MAX_BUFF];
	GSList *wordMatch = NULL;	
	FILE *files;	
	
	printf("Files with string match are :: \n");

	for(i = 0; i < g_slist_length(list); i++)
	{	//Getting File path from the populated file directory.
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
	return (wordMatch);
}

/*********************************************************************************************************
**     FUNCTION NAME       :    fileSearch
**
**     DESCRIPTION         :    Function to ask a user to enter an absolute file path and displaying that 
**								file's contents.
**
**     FUNCTION TAG        :    LSE/ 01 -3
**
**     RETURNS             :    EXIT_SUCCESS - When the code runs successfully.
**								EXIT_FAILURE - When the code runs unsuccessfully.
**                               
***********************************************************************************************************/

int fileSearch(char *file_path)
{
	/* local variables */
	char buffer[MAX_BUFF];
	int fd = 0;
	int sz = 0;
	printf("\nfile path :: %s",file_path);	
	/* Open file specified by user in read mode */
	fd = open(file_path, O_RDONLY);
	
	if(fd < 0)
	{
		perror("\nCould not open file!"); //Error Handling
		return EXIT_FAILURE;
	}
	
	printf("\nFile contents are:\n--------------------------------\n");
	
	/* Read from the file */
	sz = read(fd, buffer, MAX_BUFF);
	
	/* Adding a null character to the buffer */
	buffer[sz] = '\0';

	/* Loop to keep reading from file till the end */
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

/*********************************************************************************************************
**     FUNCTION NAME       :    searchList
**
**     DESCRIPTION         :    Function to ask users whether they want to display the contents of any file from 
**								the list of files displayed in LSE/ 01-2 then access the paths stored in GSList
**								of LSE/ 01-2 and display the contents of the chosen file.
**
**     FUNCTION TAG        :    LSE/ 01 -4
**
**     RETURNS             :    EXIT_SUCCESS - When the code runs successfully.
**								EXIT_FAILURE - When the code runs unsuccessfully.
**                               
***********************************************************************************************************/

char* searchList(GSList *wordMatch, int op)
{
	/* local variables */
	char *file_path = NULL;
	int len = 0;
	
	/*return len of the GSList*/
	len = g_slist_length(wordMatch);
	file_path = (char *)g_slist_nth_data(wordMatch, len-op);	
	
	if(file_path == NULL)
	{
		return NULL;
	}
		
	/* error message if index given by user is wrong */
	/* execute the function to display the contents */
	fileSearch(file_path); 
	
	return file_path;
}
