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
GSList *list = NULL; //test for populating
GSList *list_func = NULL;  //utility func

//for word match
GSList *list3 = NULL;  //test  for matching
GSList *list_match = NULL;   //utility func

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
	char result[MAXPATHLEN] = {0};
	char *path = NULL;
	int len1 = 0;
	int len2 = 0;
	int i = 0;
	
	char *base_path = "/mnt/c/Users/Aishwarya/OneDrive/Desktop/text_testing_folder";
	
	path = (char*) malloc (sizeof(char) * MAXPATHLEN);
	
	//7 paths
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/list_error.c");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/include/header.h");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/include/header.h.gch");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/src/function.c");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/src/main.c");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/inc/utility.h");
	list = g_slist_prepend(list,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/src/.utility.c.swp");
	
	list_func = populatePaths(base_path,result,path);
	len1 = g_slist_length(list);
	len2 = g_slist_length(list_func);
	
	if(list_func != NULL){
		for(i = 1; i < 8; i++){
			int val = strcmp((char*)g_slist_nth_data(list,len1-i), (char*)g_slist_nth_data(list_func, len2-i))
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
			int val = strcmp((char*)g_slist_nth_data(list2,len1-i), (char*)g_slist_nth_data(list_func2, len2-i))
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
	
	char *string = "list";
	int i = 0;
	int count = 0;
	int len1 = 0;
	int len2 = 0;
	
	
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/mylistmain.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/mylistfunctions.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/src/utility.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/src/function.c");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/Binary_Search/include/header.h.gch");
	list3 = g_slist_prepend(list3,"/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/list_error.c");
	
	list_match = textSearch(list_func, string);
	
	len1 = g_slist_length(list3);
	len2 = g_slist_length(list_match);
	
	if(list_func != NULL){
		for(i = 1; i <= len1; i++){
			int val = strcmp((char*)g_slist_nth_data(list3,len1-i), (char*)g_slist_nth_data(list_match, len2-i))
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
	
	int len = 0;
	
	list_match2 = textSearch(list_func,string);
	
	len = g_slist_length(list_match2);
	
	CU_ASSERT(len == 0);
	
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_fileSearch
**
**     DESCRIPTION         :    Function to test if our fileSearch function of utility.c is opening and displaying
**								the file contents when user enters a valid path.
**
**     FUNCTION TAG        :    LSE/Test - 05
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_fileSearch(void){
	
	char *filePath = "/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/mylistfunctions.c";
	char buffer[MAX_BUFF];
	int fd = 0;
	int val = 0;
	int val2 = 0;
	
	fd = open(file_path, O_RDONLY);
	if(fd < 0)
	{
		val = -1;
	}
	
	val2 = fileSearch(filePath);
	
	CU_ASSERT(val2 == val);
	
	close(fd);
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_fileSearch2
**
**     DESCRIPTION         :    Function to test if our fileSearch function of utility.c is not opening and displaying
**								the any file contents when user enters an invalid path.
**
**     FUNCTION TAG        :    LSE/Test - 06
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_fileSearch(void){
	
	char *filePath = "/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/wrong_file.c";
	char buffer[MAX_BUFF];
	int fd = 0;
	int val = 0;
	int val2 = 0;
	
	fd = open(file_path, O_RDONLY);
	if(fd < 0)
	{
		val = -1;
	}
	
	val2 = fileSearch(filePath);
	
	CU_ASSERT(val2 == val);
	
	close(fd);
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_searchList
**
**     DESCRIPTION         :    Function to test if right file is opened and displayed when user enters correct
**								index to view the contents of a file. 
**
**     FUNCTION TAG        :    LSE/Test - 07
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_searchList(void){
	
	int op = 3;
	int len = 0;
	char *file_path = "/mnt/c/Users/Aishwarya/Desktop/text_testing_folder/Merge_sort/src/utility.c";
	char *file_path2 = NULL;
	
	file_path2 = searchList(list_match,op);
	
	CU_ASSERT(strcmp(file_path2,file_path) == 0);

}

