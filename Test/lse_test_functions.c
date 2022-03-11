/*****************************************************************************************************
** FILENAME       :    lse_test_functions.c
**
** DESCRIPTION    :    Stubs for unit testing of Local Search Engine framework
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

/************************** Header Files **************************************/

#include <utility.h>
#include <lse_test_functions.h>

//for populating through basepath
GSList *list_func = NULL;

//for word match
GSList *list_match = NULL;

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_populatePaths
**
**     DESCRIPTION         :    Function to test if the basepath which is taken as input from the user and 
**								populating the global GSList is actually populating the right sub paths or not. 
**
**     FUNCTION TAG        :    LSE/Test - 01
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/


void Mytestfunction_populatePaths(void){
	
	//GSlist initialized where file paths will be stored
	GSList *list = NULL;
	char result[MAXPATHLEN] = {0};
	char *path = NULL;
	int len1 = 0;
	int len2 = 0;
	int i = 0;
	
	char *base_path = "/mnt/c/Users/Aishwarya/OneDrive/Desktop/text_testing_folder";
	
	path = (char*) malloc (sizeof(char) * MAXPATHLEN);
	
	//11 paths
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/list_error.c");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/bin/final");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/bin/output.png");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/bin/final");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/bin/output.png");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/include/header.h");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/include/header.h.gch");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/make/makefile");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/obj/function.o");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/obj/main.o");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/src/function.c");
	
	list_func = populatePaths(base_path,result,path);
	len1 = g_slist_length(list);
	len2 = g_slist_length(list_func);
	
	if(list_func != NULL){
		for(i = 1; i < 12; i++){
			int val = strcmp(g_slist_nth_data(list,len1-i), g_slist_nth_data(list_func, len2-i))
			CU_ASSERT(val == 0);
			if(val != 0){
				printf("\n1 - Both lists are not same\n");
				break;
			}
		}
	}
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_populatePaths2
**
**     DESCRIPTION         :    Function to test if the basepath which is taken as input from the user is 
**								incorrect or the user didn't enter any base path. Then the current path where
**								the executable is located will be our base path.
**
**     FUNCTION TAG        :    LSE/Test - 02
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_populatePaths2(void){
	
	GSList *list2 = NULL;
	GSList *list_func2 = NULL;
	
	char result[MAXPATHLEN] = {0};
	char *path = NULL;
	int len1 = 0;
	int len2 = 0;
	int i = 0;
	
	char *base_path = ".";
	
	path = (char*) malloc (sizeof(char) * MAXPATHLEN);
	
	list2 = g_slist_prepend(list2,"/mnt/c/Users/Aishwarya/OneDrive/Desktop/Local_Search_Engine_sprint1/bin/a");
	list2 = g_slist_prepend(list2,"/mnt/c/Users/Aishwarya/OneDrive/Desktop/Local_Search_Engine_sprint1/bin/b");
	list2 = g_slist_prepend(list2,"/mnt/c/Users/Aishwarya/OneDrive/Desktop/Local_Search_Engine_sprint1/bin/input/input.txt");
	list2 = g_slist_prepend(list2,"/mnt/c/Users/Aishwarya/OneDrive/Desktop/Local_Search_Engine_sprint1/bin/main");
	list2 = g_slist_prepend(list2,"/mnt/c/Users/Aishwarya/OneDrive/Desktop/Local_Search_Engine_sprint1/bin/test.txt");
	
	list_func2 = populatePaths(base_path,result,path);
	len1 = g_slist_length(list2);
	len2 = g_slist_length(list_func2);
	
	if(list_func != NULL){
		for(i = 1; i <= len1; i++){
			int val = strcmp(g_slist_nth_data(list2,len1-i), g_slist_nth_data(list_func2, len2-i))
			CU_ASSERT(val == 0);
			if(val != 0){
				printf("\n2 - Both lists are not same\n");
				break;
			}
		}
	}
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_textSeach
**
**     DESCRIPTION         :    Function to test if the list of file paths returned after looking up for a partiular
** 								 text/string through the file paths present in basepath is correct or not.
**								 
**
**     FUNCTION TAG        :    LSE/Test - 03
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_textSeach(void){
	
	GSList *list3 = NULL;
	char *string = "list";
	int i = 0;
	int count = 0;
	int len1 = 0;
	int len2 = 0;
	FILE *files;
	char temp[MAX_BUFF];
	
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/mylistmain.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/mylistfunctions.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/src/utility.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/obj/main.o");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/src/function.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/include/header.h.gch");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/list_error.c");
	
	for(i = 0; i < g_slist_length(list_func); i++)
	{
		files = fopen((char*)g_slist_nth_data(list_func,i),"r");
		if(files != NULL)
		{
			while(!feof(files))
			{
				fgets(temp,MAX_BUFF,files);
				if(strstr(temp,string) != NULL)
				{	
					list_match = g_slist_prepend(list_match,strdup((char*)g_slist_nth_data(list_func,i)));
					count++;
					break;
				}
			}
		}
		if(files != NULL)
			fclose(files);
	}
	
	len1 = g_slist_length(list3);
	len2 = g_slist_length(list_match);
	
	if(list_func != NULL){
		for(i = 1; i <= len1; i++){
			int val = strcmp(g_slist_nth_data(list3,len1-i), g_slist_nth_data(list_match, len2-i))
			CU_ASSERT(val == 0);
			if(val != 0){
				printf("\n3 - Both lists are not same\n");
				break;
			}
		}
	}
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_textSeach
**
**     DESCRIPTION         :    Function to test if the list of file paths returned after looking up for a partiular
** 								text/string is empty. If the user input text/string is not present int the files 
**								present inside sub paths of base path then the list should be empty.
**
**     FUNCTION TAG        :    LSE/Test - 04
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_textSeach(void){
	
	GSList *list_match2 = NULL;
	
	char *string = "golden";
	int i = 0;
	int count = 0;
	int len = 0;
	
	FILE *files;
	char temp[MAX_BUFF];
	
	for(i = 0; i < g_slist_length(list_func); i++)
	{
		files = fopen((char*)g_slist_nth_data(list_func,i),"r");
		if(files != NULL)
		{
			while(!feof(files))
			{
				fgets(temp,MAX_BUFF,files);
				if(strstr(temp,string) != NULL)
				{	
					list_match2 = g_slist_prepend(list_match2,strdup((char*)g_slist_nth_data(list_func,i)));
					count++;
					break;
				}
			}
		}
		if(files != NULL)
			fclose(files);
	}
	
	len = g_slist_length(list_match2);
	
	CU_ASSERT(len == 0);
	
	if(len != 0){
		printf("\n4 - List is not empty\n");
	}
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_fileSearch
**
**     DESCRIPTION         :    
**
**     FUNCTION TAG        :    LSE/Test - 05
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_fileSearch2
**
**     DESCRIPTION         :    
**
**     FUNCTION TAG        :    LSE/Test - 06
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_searchList
**
**     DESCRIPTION         :    
**
**     FUNCTION TAG        :    LSE/Test - 07
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_searchList2
**
**     DESCRIPTION         :    
**
**     FUNCTION TAG        :    LSE/Test - 08
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 
