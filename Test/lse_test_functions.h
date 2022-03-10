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

/************************** Header Files **************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#include <CUnit.h>
#include <Basic.h>

#include <utility.h>

/****************************** Test Function Prototypes ***************************************/

//for [LSE]\01-1
extern void Mytestfunction_populatePaths(void);     //--change comment //if the files containing text are found
extern void Mytestfunction_populatePaths2(void);	//if files containing the text are not found

//for [LSE]/01-2
extern void Mytestfunction_textSeach(void);      //if the files containing text are found
extern void Mytestfunction_textSearch2(void);	//if files containing the text are not found

//for [LSE]/01-3
extern void Mytestfunction_fileSearch(void);     //if file name/location is found
extern void Mytestfunction_fileSearch2(void);    //if file name/location is not found

//for [LSE]/01-4
extern void Mytestfunction_searchList(void);           //if correct file name/location is provided then display contents
extern void Mytestfunction_searchList(void);			//if incorrect file name/location is provided.

#endif
