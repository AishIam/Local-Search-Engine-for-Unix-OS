/*****************************************************************************************************
** FILENAME       :    localSearchEngine.c
**
** DESCRIPTION    :    implementation of the Local Search Engine
**
** Revision History   :    V_0.3
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
**     FUNCTION NAME       :	main    
**
**     DESCRIPTION         :    It is a driver function for the application.
**
**     FUNCTION TAG	       :	--DRIVER_FUNCTION--
**
**     RETURNS             :	EXIT_SUCCESS - When the code runs successfully.
**								EXIT_FAILURE - When the code runs unsuccessfully.
**
*****************************************************************************************************/

int main()
{
	char result[MAXPATHLEN] = {0};
	char *path = NULL;
	char temp[MAXPATHLEN];
	char *base_path = NULL;
	char word[MAXPATHLEN];
	char *string = NULL;
	
	char absolute_file_path[MAXPATHLEN];
	char *file_path = NULL;
	char *file_path1 = NULL;
	
	int retval = 0;
	int choice = 0;
	char ch;
	int op = 0;
	
	//GSlist initialized where file paths will be stored
	GSList *wordMatch = NULL;
	path = (char*) malloc (sizeof(char) * MAXPATHLEN);
	
	printf("\n\n------------------------------------------ LOCAL SEARCH ENGINE STARTING ---------------------------------------------\n\n");
	
	printf("Do you want to enter a base path?(Y/n): \n");
	scanf("%c", &ch);
	
	// To clear out the \n from the stream
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
    		continue;
	}

	if(ch == 'Y' || ch == 'y'){
		
		//Taking base path as input from the user
		printf("Enter a Base Path :: ");
		fgets(temp,MAXPATHLEN,stdin);
	
		//allocating memory to base_path depending  on the length of the path entered by user
		base_path = (char*) malloc (strlen(temp) * sizeof(char));   
	
		//copying value of temp path to base path
		strcpy(base_path,temp);
		
		//stripping the \n from the fgets().
		base_path[strcspn(base_path, "\n")] = 0;
		
	}
	else{
		base_path = (char*) malloc ( 1  * sizeof(char) );   
		strcpy(base_path,".");
	}
	
	//LSE / 01-1 -- populating the GSList with all the sub file paths present inside the base path
	populatePaths(base_path,result,path);
	free(base_path);	
	free(path);	

	while(choice != 3){
		
		//LSE / 01-6 -- Menu driven console user interface
		printf("\n\n1. To enter the file path and display the contents of the file.\n");
		printf("2. To search for all the files containing matching string and display the file names.\n");
		printf("3. Exit\n");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
		
		// To clear out the \n from the stream
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {
    			continue;
		}
				
		//Based on user's choice the switch loop will call the functions present in utility.c file
		switch(choice){
			
			case 1:
				//LSE / 01-3 -- searches for a particular file, when the absolute path of the file is provided and display the contents of that file.
				
				printf("\nEnter an absolute file path: ");
				fgets(absolute_file_path, MAXPATHLEN, stdin);
				
				file_path = (char*) malloc (strlen(absolute_file_path) * sizeof(char));
				strcpy(file_path,absolute_file_path);
				file_path[strcspn(file_path, "\n")] = 0;
				fileSearch(file_path);
				free(file_path);
				if(retval){
					printf("\nSome error occurred!"); // should be changed -- error file
				}
				break;
				
			case 2:
				/*LSE / 01-2 -- searches for a given word/sentence/string through all the files in the local file system 
				and list out all the files where a match was found.*/
				
				printf("\nEnter the String to be searched : ");
				fgets(word,MAX_BUFF,stdin);

				string = (char*) malloc (strlen(word) * sizeof(char));
				strcpy(string,word);
				
				wordMatch = textSearch(string);
				
				free(string);
				//checking if GSList is empty or not. If it's empty then there was no match found for word/string entered by the user in the files inside basepath.
				if(g_slist_length(wordMatch) != 0)
				{
					printf("\nDo you want to display the contents of any above listed file(Y/N)?: ");
					scanf("%c", &ch);
					
					// To clear out the \n from the stream
					int c;
					while ((c = getchar()) != '\n' && c != EOF) {
    						continue;
					}
							
						
					//while loop will run and the users can view the contents of the file until they enter a value other than Y
					while(ch == 'Y' || ch == 'y'){
						/*LSE / 01-4 --  to display the contents of the file when the user chooses a particular file from the 
						listing of the files provided as a sucess to search for a particular word/pattern/sentence. */
						
						/* loop to repeat menu if index is wrong */
						while(file_path1 == NULL)
						{
							/* get index from user */
							printf("\nEnter index of the file whose contents you want to view: ");
							scanf("%d", &op);
							
							file_path1 = searchList(wordMatch,op);
						
							if(file_path1 == NULL)
							{
								printf("\nIndex entered is wrong! Please try again!");
							}
						}
						
						// To clear out the \n from the stream
						int c;
						while ((c = getchar()) != '\n' && c != EOF) {
    							continue;
						}
						file_path1 = NULL;
						printf("\nDo you want to display the contents of any above listed file again(Y/N)?: ");
						scanf("%c", &ch);
						
					}     
				}										
				else
				{
					//if GSList is empty
					printf("\nNo match found !! \n");											
				}
				
				break;
			
			case 3: 
				//to exit from the menu driven UI
				break;
							
			default:
				//When user enters an invalid choice
				printf("Invalid choice!\n");
				break;
		}
	}
	
	printf("\n\n----------------------------------------- EXITING LOCAL SEARCH ENGINE -----------------------------------------------\n\n");
	
	g_slist_free(list);
	g_slist_free(wordMatch);	
	free(file_path1);
	return EXIT_SUCCESS;				
}


