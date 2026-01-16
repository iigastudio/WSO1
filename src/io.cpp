/***********************************************************************
// OOP244 Workshop #1: io module
//
// File        io.cpp
// Version     1.0
// Date        17-01-2026
// Author      Tamara Brinckman
// Description:
// Phonebook search functions
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Tamara            17.01.2026      Lab
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "io.h"
#include "cstr.h"

namespace seneca {

   // Reads a name from console input
   void read(char* name) {
      std::cout << "Name>\n ";
      std::cin >> name;
   }

   // Reads a PhoneRec from a tab-separated file
   bool read(PhoneRec& pr, std::FILE* fptr) {
      return fscanf(fptr, "%s %s %lld", pr.m_name, pr.m_lastName, &pr.m_phoneNumber) == 3;
   }

   // Prints a phone number in format (999) 999-9999
   void print(long long phoneNumber) {
      std::cout << "(" << phoneNumber / 10000000 << ") "
                << (phoneNumber / 10000) % 1000 << "-"
                << phoneNumber % 10000;
   }

   // Prints a PhoneRec with optional filter
   void print(const PhoneRec& pr, size_t& row, const char* filter) {
      char lowerName[16];
      char lowerLastName[26];
      char lowerFilter[51];

      tolower(lowerName, pr.m_name);
      tolower(lowerLastName, pr.m_lastName);

      bool match = false;

      if (filter == nullptr) {
         match = true;
      } else {
         tolower(lowerFilter, filter);
         if (strstr(lowerName, lowerFilter) != nullptr ||
             strstr(lowerLastName, lowerFilter) != nullptr) {
            match = true;
         }
      }

      if (match) {
         std::cout << row << ": " << pr.m_name << " " << pr.m_lastName << " ";
         print(pr.m_phoneNumber);
         std::cout << std::endl;
         row++;
      }
   }

   // Prints an array of PhoneRec pointers with optional filter
   void print(PhoneRec* ptrs[], size_t size, const char* filter) {
      size_t row = 1;
      for (size_t i = 0; i < size; i++) {
         print(*ptrs[i], row, filter);
      }
   }

   // Sets up an array of pointers to point to elements of a PhoneRec array
   void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size) {
      for (size_t i = 0; i < size; i++) {
         ptrs[i] = &recs[i];
      }
   }

   // Sorts an array of PhoneRec pointers by first name or last name
   void sort(PhoneRec* ptrs[], size_t size, bool byLastName) {
      for (size_t i = 0; i < size - 1; i++) {
         for (size_t j = i + 1; j < size; j++) {
            bool swap = false;

            if (byLastName) {
               if (strcmp(ptrs[i]->m_lastName, ptrs[j]->m_lastName) > 0) {
                  swap = true;
               }
            } else {
               if (strcmp(ptrs[i]->m_name, ptrs[j]->m_name) > 0) {
                  swap = true;
               }
            }

            if (swap) {
               PhoneRec* temp = ptrs[i];
               ptrs[i] = ptrs[j];
               ptrs[j] = temp;
            }
         }
      }
   }

}
