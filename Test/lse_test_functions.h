/*****************************************************************************************************
** FILENAME       :    lse_test_functions.h
**
** DESCRIPTION    :    Header File of the lse_test.c
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

#ifndef __LSE_TESTFUNCTIONS_H__
#define __LSE_TESTFUNCTIONS_H__


/****************************** Global Variables ***************************************/
extern GSList* list_func;
extern GSList* list_match;


/****************************** Test Function Prototypes ***************************************/

//for [LSE]\01-1
extern void Mytestfunction_populatePaths(void);   //if the base path is provided by the user  
extern void Mytestfunction_populatePaths2(void);	//if the base path is not provided by the user or it is incorrect

//for [LSE]/01-2
extern void Mytestfunction_textSearch(void);      //if the files containing text are found
extern void Mytestfunction_textSearch2(void);	//if files containing the text are not found

//for [LSE]/01-3
extern void Mytestfunction_fileSearch(void);     //if file name/location is found
extern void Mytestfunction_fileSearch2(void);    //if file name/location is not found

//for [LSE]/01-4
extern void Mytestfunction_searchList(void);           //if correct file name/location is provided then display contents


#endif
