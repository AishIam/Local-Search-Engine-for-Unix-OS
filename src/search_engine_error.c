//error file//
#include <stdio.h>
#include <utility.h>
/************************************************
 *             GLOBAL VARIABLES
************************************************/
int g_error_level=ERROR_MAJOR;
char *g_error_level_str[]={
    "Input Error"               //Invalid Error
    "File doesn't exist"        //File do not Exist
    "Could not open the file"   //File opening failed
    "Could not close the file"  //File Closing failed
}; 
/************************************************
* FUNCTIONNAME: list_error
*
* DESCRIPTION: Prints the error message along with the error number
*
* RETURNS: Returns void
 ************************************************/
void list_error(int err_level,int err_code){
    if(err_level <= g_error_level){
        printf("Error : (%s) \n",g_error_level_str[error_level]);
    }
}

