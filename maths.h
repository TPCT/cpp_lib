#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef double** pptr;
typedef struct{const unsigned rows=0; const unsigned columns=0;} Matrix_Size;
typedef struct{const pptr matrix=0; const Matrix_Size size; unsigned index=0;} Matrix;
Matrix MatMK(Matrix_Size);
bool greater_than(double, double);
bool smaller_than(double, double);
double *Arrange(void*, unsigned, bool (*)(double, double));
double npr(double, double);
double factorial(double);
unsigned Number_Length(double);
unsigned precision(void *, unsigned);
void permute(void**, unsigned, unsigned);
void Print(void*, unsigned);
void Swap(int, int);
