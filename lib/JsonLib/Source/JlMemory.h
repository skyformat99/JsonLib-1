////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  JsonLib
//
//  This module provides the core memory allocation functions. They rely on macros JlAlloc and JlFree. These are
//  by default defined in JsonLib.h as calloc and free. However they can be defined as anything else with the same
//  prototype by defining the macros JlAlloc and JlFree in a header file and then setting a global project define of
//  JL_INCLUDE_H to point to that file. This will allow the use of a different memory allocator, as long as the
//  prototype matches calloc and free.
//
//  This is free and unencumbered software released into the public domain - November 2019 waterjuice.org
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  IMPORTS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JsonLib.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  MACROS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define JlNew( TYPE )           ((TYPE*) JlAlloc( sizeof(TYPE) ))

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  PUBLIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  JlStrDup
//
//  Duplicates a string like strdup (But uses JlAlloc function)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char*
    JlStrDup
    (
        char const*     SourceString
    );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  JlRealloc
//
//  Allocates a new buffer of a different size from the original buffer and copies the contents across, then deallocates
//  the original buffer.
//  If an error occurs NULL is returned. Otherwise a valid pointer is returned and OriginalBuffer is NO LONGER VALID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void*
    JlRealloc
    (
        void*       OriginalBuffer,
        size_t      OriginalSize,
        size_t      NewSize
    );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  JlMemoryWriteCountValue
//
//  Writes the count value to the location pointed to by CountFieldPtr and CountFieldSize. This will write
//  an 8bit, 16bit, 32bit, or 64bit size value to the struct.
//  This will return JL_STATUS_COUNT_FIELD_TOO_SMALL if the count field is too small for the number being written.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JL_STATUS
    JlMemoryWriteCountValue
    (
        void*           CountFieldPtr,
        size_t          CountFieldSize,
        size_t          CountValue
    );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  JlMemoryReadCountValue
//
//  Reads the count value from the structure using the pointer CountFieldPtr and CountFieldSize values. This will read
//  an 8bit, 16bit, 32bit, or 64bit size value from the struct and always return a size_t value.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t
    JlMemoryReadCountValue
    (
        void const*     CountFieldPtr,
        size_t          CountFieldSize
    );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  JlMemoryVerifyCountFieldLargeEnoughForValue
//
//  Verifies that the size_t value will fit in an unsigned int of specified size (in bytes)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JL_STATUS
    JlMemoryVerifyCountFieldLargeEnoughForValue
    (
        size_t          CountFieldSize,
        size_t          Value
    );