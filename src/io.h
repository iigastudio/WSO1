/***********************************************************************
// OOP244 Workshop #1: io module
//
// File        io.h
// Version     1.0
// Date        17-01-2026
// Author      Tamara Brinckman
// Description:
// Phonebook search functions
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Tamara          17.01.2026        Lab
***********************************************************************/

#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstdio>

namespace seneca {

   struct PhoneRec {
      char m_name[16];
      char m_lastName[26];
      long long m_phoneNumber;
   };

   // Reads a name from console input
   void read(char* name);

   // Reads a PhoneRec from a tab-separated file
   bool read(PhoneRec& pr, std::FILE* fptr);

   // Prints a phone number in format (999) 999-9999
   void print(long long phoneNumber);

   // Prints a PhoneRec with optional filter
   void print(const PhoneRec& pr, size_t& row, const char* filter = nullptr);

   // Prints an array of PhoneRec pointers with optional filter
   void print(PhoneRec* ptrs[], size_t size, const char* filter = nullptr);

   // Sets up an array of pointers to point to elements of a PhoneRec array
   void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size);

   // Sorts an array of PhoneRec pointers by first name or last name
   void sort(PhoneRec* ptrs[], size_t size, bool byLastName);

}
#endif // !SENECA_IO_H
