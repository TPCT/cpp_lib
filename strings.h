#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;
using char_array = char*;
typedef string* sptr;
typedef struct {sptr array; unsigned size = 0;} String_Array;
string SubStr(string, unsigned, unsigned);
String_Array Split(const string, const string);
void Print(String_Array);
//void Print(char_array);
int StrIndexOf(const char*, char);
int StrIndexOf(const char*, const char*);
int StrIndexOf(const char*, char, unsigned);
int StrIndexOf(const char*,const char*, unsigned);
int StrIndexOf(const char*, char, unsigned, unsigned);
int StrIndexOf(const char*,const char*, unsigned, unsigned);
int CharArrLen(const char*);
void push_back(String_Array&, string);
unsigned precision(void*, unsigned);
unsigned Number_Length(double);
size_t ArrLen(string*&);
