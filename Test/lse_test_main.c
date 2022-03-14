/*****************************************************************************************************
** FILENAME       :    lse_test_main.c
**
** DESCRIPTION    :    Main function to call the CUNIT Framework
**
** Revision History   :    V_0.1
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
#include <string.h>
#include <sys/types.h>


#include <CUnit.h>
#include <Basic.h>

#include <utility.h>
#include <lse_test_functions.h>

/******************************************************************************
 Function     : init_lse
 Description  : Initializes the suite
 Input        : Nothing
 Output       : int
***************************************************************************/
int init_lse(void)
{
    return 0;
}

/******************************************************************************
 Function     : clean_lse
 Description  : clean the suite after successful run
 Input        : Nothing
 Output       : int
***************************************************************************/
int clean_lse(void)
{
    return 0;
}

/*************************************************************************************
 Function     : main
 Description  :This is the main function to test backend functions in utility.c
 Input        : None
 Output       : int
************************************************************************************/

int main(int argc, char *argv[])
{
    CU_pSuite pSuite = NULL;

    /* Register  */
    if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();

    /* Add init and cleanup handlers */
    pSuite = CU_add_suite("LOCAL SEARCH ENGINE TEST SUITE",init_lse, clean_lse);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* test cases added */
    
    //LSE/Test - 01
    if(NULL == CU_add_test(pSuite,"Mytestfunction_populatePaths_ID_1", Mytestfunction_populatePaths))
    {
       	CU_cleanup_registry();
        return CU_get_error();
    }
    
    //LSE/Test - 02
    if(NULL == CU_add_test(pSuite,"Mytestfunction_populatePaths_ID_2", Mytestfunction_populatePaths2))
    {
       	CU_cleanup_registry();
        return CU_get_error();
    }
    
    //LSE/Test - 03
    if(NULL == CU_add_test(pSuite,"Mytestfunction_textSearch_ID_3", Mytestfunction_textSearch))
    {
       	CU_cleanup_registry();
        return CU_get_error();
    }
    
    //LSE/Test - 04
    if(NULL == CU_add_test(pSuite,"Mytestfunction_textSearch2_ID_4", Mytestfunction_textSearch2))
    {
       	CU_cleanup_registry();
        return CU_get_error();
    }
    
    //LSE/Test - 05
    if(NULL == CU_add_test(pSuite,"Mytestfunction_fileSearch_ID_5", Mytestfunction_fileSearch))
    {
       	CU_cleanup_registry();
        return CU_get_error();
    }
    
    //LSE/Test - 06
    if(NULL == CU_add_test(pSuite,"Mytestfunction_fileSearch2_ID_6", Mytestfunction_fileSearch2))
    {
       	CU_cleanup_registry();
        return CU_get_error();
    }
    
   //LSE/Test - 07
    if(NULL == CU_add_test(pSuite,"Mytestfunction_searchList_ID_7", Mytestfunction_searchList))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
	

    /* Set the mode and  invoke test(s) */ 
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    /* unregister and do cleanup */
    CU_cleanup_registry(); 
    
   
    
    return CU_get_error();
}
