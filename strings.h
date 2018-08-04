#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
using Matrix =  vector<vector<double>>;
using Row = vector<double>;
using string_array = vector<string>;
using char_array = char*;
string SubStr(string, unsigned, unsigned);
string* Split(const string, const string);
//string *copyarray(string*, unsigned);
void push_back(string*&, string);
void Print(Matrix);
void Print(Row);
void Print(string_array);
void Print(char_array);
int StrIndexOf(const char*, char);
int StrIndexOf(const char*, const char*);
int StrIndexOf(const char*, char, unsigned);
int StrIndexOf(const char*,const char*, unsigned);
int StrIndexOf(const char*, char, unsigned, unsigned);
int StrIndexOf(const char*,const char*, unsigned, unsigned);
int CharArrLen(const char*);
size_t ArrLen(string*&);
