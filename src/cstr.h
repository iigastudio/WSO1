/***********************************************************************
// OOP244 Workshop #1: cstr module
//
// File        cstr.h
// Version     1.0
// Date        17-01-2026
// Author      Tamara Brinckman
// Description:
// C-style string functions
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Tamara          17.01.2026       Lab
***********************************************************************/

#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

#include <cstddef>

namespace seneca {

   // Concatenates the src string to the end of des string
   char* strcat(char* des, const char* src);

   // Converts an uppercase ASCII character to lowercase
   char tolower(char ch);

   // Converts all characters in src to lowercase and copies them into des
   char* tolower(char* des, const char* src);

   // Converts all characters in the input string to lowercase in place
   char* tolower(char* str);

   // Compares two C-style strings lexicographically
   int strcmp(const char* s1, const char* s2);

   // Compares up to 'len' characters of two strings lexicographically
   int strcmp(const char* s1, const char* s2, size_t len);

   // Copies src into des including null terminator
   char* strcpy(char* des, const char* src);

   // Copies up to 'len' characters from src to des
   char* strcpy(char* des, const char* src, size_t len);

   // Copies up to 'len' characters from src to des (like std::strncpy)
   char* strncpy(char* des, const char* src, size_t len);

   // Returns the length of the C-style string str
   size_t strlen(const char* str);

   // Finds the first occurrence of toFind in str
   const char* strstr(const char* str, const char* toFind);

   // Returns true if ch is an alphabetic character
   bool isalpha(char ch);

   // Returns true if ch is a whitespace character
   bool isspace(char ch);

}
#endif // !SENECA_CSTR_H
