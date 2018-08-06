#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdint>
using namespace std;
typedef double* dptr;
typedef double** pptr;
typedef struct{unsigned rows=0; unsigned columns=0;} Matrix_Size;
typedef struct{pptr matrix=0; Matrix_Size size; unsigned index=0;} Matrix;
typedef struct{dptr array=0; unsigned size=0;} DBL_Array;
Matrix MatMK(Matrix_Size);
DBL_Array DBL_ARR_MK(double[], unsigned);
bool greater_than(double, double);
bool smaller_than(double, double);
double *Arrange(void*, unsigned, bool (*)(double, double));
double npr(double, double);
double factorial(double);
unsigned Number_Length(double);
unsigned precision(void *, unsigned);
double **Permute(DBL_Array*, unsigned *index=0, unsigned start=0, unsigned end=-1, pptr container=0);
void Print(void*, unsigned);
void Print(DBL_Array);
void Swap(int, int);
void Reverse(DBL_Array);
