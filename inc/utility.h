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
#include <glib.h>
#include <dirent.h> 
#include <sys/types.h> 
#include <sys/param.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <fcntl.h> 
/*****************List errors defined in search_engine_error.c****************/

#define A_ERROR(err_level, err_code) list_error(err_level, err_code)

/****************************** Error codes **********************************/
#define ERROR_NONE 0
#define ERROR_MIN 1
#define ERROR_CRITICAL 2
#define ERROR_MAJOR 3
/****************************** Error list ***********************************/
#define ERROR_UNEXPECTED 0
#define ERROR_INVALID_INPUT 1
#define ERROR_OPENING_FILE 2
#define ERROR_CLOSING_FILE 3 
/****************************** Macros  ***************************************/
#define MAX_BUFF 100
#define MAX_PATH 100
/****************************** Functions  ***************************************/

extern GSList *list;

extern GSList* textSearch(char* string);
extern int fileSearch(char* str);
extern GSList* populatePaths(char* base_path,char* result, char* path);
extern char* searchList(GSList *wordMatch,int op);

#endif
