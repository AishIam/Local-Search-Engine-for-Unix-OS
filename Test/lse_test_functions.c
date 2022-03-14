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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit.h> // CU_ASSERT
#include <utility.h>

/************************** Global Variables **************************************/

//for populating through basepath
GSList *list_func = NULL;  //utility func


//for word match
GSList *list_match = NULL;   //utility func

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_populatePaths
**
**     DESCRIPTION         :    Function to test if the basepath which is taken as input from the user and 
**				populating the global GSList is actually populating the right sub paths or not. 
**
**     FUNCTION TAG        :    LSE/Test - 01
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/


void Mytestfunction_populatePaths(void){
	
	//GSlist initialized where file paths will be stored
	GSList *list1 = NULL; //test for populating
	char result[MAXPATHLEN] = {0};
	char *path = NULL;

	int i = 0;
	
	char *base_path = "/home/aish99/text_testing_folder";
	
	path = (char*) malloc (sizeof(char) * MAXPATHLEN);
	
	//4 paths
	list1 = g_slist_prepend(list1,"/home/aish99/text_testing_folder/Merge_sort/inc/utility.h");
	list1 = g_slist_prepend(list1,"/home/aish99/text_testing_folder/Merge_sort/src/.utility.c.swp");
	list1 = g_slist_prepend(list1,"/home/aish99/text_testing_folder/Merge_sort/src/main.c");
	list1 = g_slist_prepend(list1,"/home/aish99/text_testing_folder/Merge_sort/src/utility.c");
	
	
	list_func = populatePaths(base_path,result,path);
	
	if(list_func != NULL){
		for(i = 0; i < 4; i++){
		
			CU_ASSERT(strcmp((char*)g_slist_nth_data(list1,i), (char*)g_slist_nth_data(list_func,i)) == 0);
			
			//if(val != 0){
			//	printf("\n1 - Both lists are not same\n");
			//	break;
			//}
		}
	}
	
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_populatePaths2
**
**     DESCRIPTION         :    Function to test if the basepath which is taken as input from the user is 
**				incorrect or the user didn't enter any base path. Then the current path where
**				the executable is located will be our base path.
**
**     FUNCTION TAG        :    LSE/Test - 02
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_populatePaths2(void){
	
	GSList *list2 = NULL;
        GSList *list_func2 = NULL;
	char result2[MAXPATHLEN] = {0};
	char *path2 = NULL;
	char *base_path2 = ".";
	int i = 0;
	
	path2 = (char*) malloc (sizeof(char) * MAXPATHLEN);
	
	list2 = g_slist_prepend(list2,"/home/aish99/LSE_sprint/bin/test.txt");
	list2 = g_slist_prepend(list2,"/home/aish99/text_testing_folder/Merge_sort/src/main.c");
	list2 = g_slist_prepend(list2,"/home/aish99/LSE_sprint/bin/b.txt");
	
	list_func2 = populatePaths(base_path2,result2,path2);
	
	if(list_func != NULL){
		for(i = 0; i < 3; i++){
	
			CU_ASSERT(strcmp((char*)g_slist_nth_data(list2,i), (char*)g_slist_nth_data(list_func2, i)) == 0);
		}
	}
	
	

}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_textSearch
**
**     DESCRIPTION         :    Function to test if the list of file paths returned after looking up for a partiular
** 				text/string through the file paths present in basepath is correct or not.
**								 
**
**     FUNCTION TAG        :    LSE/Test - 03
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_textSearch(void){
	
	GSList *list3 = NULL;  //test  for matching
	char *string = "list";
	
	int len1 = 0;
	int len2 = 0;
	
	
	list3 = g_slist_prepend(list3,"/home/aish99/text_testing_folder/mylistmain.c");
	list3 = g_slist_prepend(list3,"/home/aish99/text_testing_folder/mylistfunctions.c");
	list3 = g_slist_prepend(list3,"/home/aish99/text_testing_folder/Merge_sort/src/utility.c");
	list3 = g_slist_prepend(list3,"/home/aish99/text_testing_folder/Merge_sort/Binary_Search/src/function.c");
	list3 = g_slist_prepend(list3,"/home/aish99/text_testing_folder/Merge_sort/Binary_Search/include/header.h.gch");
	list3 = g_slist_prepend(list3,"/home/aish99/text_testing_folder/list_error.c");
	
	list_match = textSearch(string,list_func);
	
	len1 = g_slist_length(list3);
	len2 = g_slist_length(list_match);
	
	CU_ASSERT(len2 == len1);
	
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_textSearch2
**
**     DESCRIPTION         :    Function to test if the list of file paths returned after looking up for a partiular
** 				  text/string is empty. If the user input text/string is not present int the files 
**				present inside sub paths of base path then the list should be empty.
**
**     FUNCTION TAG        :    LSE/Test - 04
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_textSearch2(void){
	
	GSList *list_match2 = NULL;
	char *string = "golden";
	int len = 0;
	
	list_match2 = textSearch(string,list_func);
	
	len = g_slist_length(list_match2);
	
	CU_ASSERT(len == 0);
	
	g_slist_free(list_match2);
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_fileSearch
**
**     DESCRIPTION         :    Function to test if our fileSearch function of utility.c is opening and displaying
**				the file contents when user enters a valid path.
**
**     FUNCTION TAG        :    LSE/Test - 05
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_fileSearch(void){
	
	char *filePath = "/home/aish99/text_testing_folder/mylistfunctions.c";
	int fd = 0;
	int val = 0;
	int val2 = 0;
	
	fd = open(filePath, O_RDONLY);
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
**				the any file contents when user enters an invalid path.
**
**     FUNCTION TAG        :    LSE/Test - 06
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_fileSearch2(void){
	
	char *filePath = "/home/aish99/text_testing_folder/wrong_file.c";

	int val2 = 0;
	
	val2 = fileSearch(filePath);
	
	CU_ASSERT(val2 != 0);
	
	
}

/*********************************************************************************************************
**     FUNCTION NAME       :    Mytestfunction_searchList
**
**     DESCRIPTION         :    Function to test if right file is opened and displayed when user enters correct
**				index to view the contents of a file. 
**
**     FUNCTION TAG        :    LSE/Test - 07
**
**     RETURNS             :    Return void.
**                               
***********************************************************************************************************/ 

void Mytestfunction_searchList(void){
	
	int op = 1;
	char *file_path = "/home/aish99/text_testing_folder/Merge_sort/src/utility.c";
	char *file_path2 = NULL;
	
	file_path2 = (char*) malloc (sizeof(char) * MAXPATHLEN);
	file_path2 = searchList(list_match,op);
	
	CU_ASSERT(strcmp(file_path2,file_path) == 0);
	

}

