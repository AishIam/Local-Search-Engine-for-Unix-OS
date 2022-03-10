/*****************************************************************************************************
** FILENAME       :    localSearchEngine.c
**
** DESCRIPTION    :    implementation of the Local Search Engine
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

/*********************************************************************************************************
**     FUNCTION NAME       :	main    
**
**     DESCRIPTION         :    It is a driver function for the application.
**
**     FUNCTION TAG	   :	--DRIVER_FUNCTION--
**
**     RETURNS             :	EXIT_SUCCESS - When the code runs successfully.
**				EXIT_FAILURE - When the code runs unsuccessfully.
**
*****************************************************************************************************/

int main()
{
	char result[MAXPATHLEN] = {0};
	char *path = NULL;
	char temp[MAXPATHLEN]; 
	char *base_path = NULL;
	path = (char*) malloc (sizeof(char) * MAXPATHLEN);
	printf("Enter a Base Path :: ");
	fgets(temp,MAXPATHLEN,stdin);
	base_path = (char*) malloc (strlen(temp) * sizeof(char));
	strcpy(base_path,temp);
	base_path[strcspn(base_path, "\n")] = 0;
	
	populatePaths(base_path,result,path);
	int retval = 0;
	int choice = 0;
	char ch;
	while(choice != 3){
		printf("1. To enter the file path and display the contents of the file.\n");
		printf("2. To search for all the files containing matching string and display the file names.\n");
		printf("3. Exit\n");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
				
		//Based on user's choice the switch loop will call the functions present in utility.c file
		switch(choice){
			
			case 1:
				//LSE / 01-3 -- search`es for a particular file, when the absolute path of the file is provided and display the contents of that file.
				retval = fileSearch();
				
				if(retval){
					printf("\nSome error occurred!"); // should be changed -- error file
				}
				break;
				
			case 2:
				/*LSE / 01-2 -- searches for a given word/sentence/string through all the files in the local file system 
				and list out all the files where a match was found.*/
				
				textSearch();
				
				printf("\nDo you want to display the contents of any above listed file(Y/N)?\n");
				scanf("%c", &ch);
				
				
				do{
					/*LSE / 01-4 --  to display the contents of the file when the user chooses a particular file from the 
					listing of the files provided as a sucess to search for a particular word/pattern/sentence. */
					
					//function 4 will be called
					
					printf("\nDo you want to display the contents of any above listed file(Y/N)? \n");
					scanf("%c", &ch);
					
				} while(ch == 'Y' || ch == 'y');   //do-while loop will run and the users can view the contents of 
													//the file until they enter a value other than Y
				
				break;
			
			case 3:
				break;
							
			default:
				//When user enters an invalid choice
				printf("Invalid choice!\n");
				break;
		}
	}
	

	return EXIT_SUCCESS;			
}
