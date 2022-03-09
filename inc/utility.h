/*****************************************************************************************************
** FILENAME       :    utility.h
**
** DESCRIPTION    :    Header File of the Local Search Engine
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
#ifndef __UTILITY_H__
#define __UTILITY_H__

/************************** Header Files **************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
/****************************** Macros  ***************************************/
#define MAX 100
#define PATH_MAX 100
#define READ_MODE "r"
/****************************** Functions  ***************************************/
extern void textSearch();
extern int fileSearch();


#endif
