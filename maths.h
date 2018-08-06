#include <iostream>
#include <climits>
#include <string>
#include <iomanip>
using namespace std;
/* this typedef to make the same pointer changes it's value multiple times
    typedef struct {const double x=0; const double y=0;} Point;
    typedef struct {ptr row=0; unsigned size=0;} Row;
    typedef struct {unsigned rows=0; unsigned columns=0;} Matrix_Size;
    typedef struct {pptr matrix=0; Matrix_Size size; unsigned index=0;} Matrix;
*/
typedef double** pptr;
typedef double* dptr;
typedef string* sptr;
typedef struct {const double x=0; const double y=0;} Point;
typedef struct {const unsigned rows=0; const unsigned columns=0;} Matrix_Size;
typedef struct {const pptr matrix=0; const Matrix_Size size; unsigned index=0;} Matrix;
typedef struct {const dptr row=0; const unsigned size=0;} Row;
typedef struct {sptr array; unsigned size = 0;} String_Array;
typedef struct {dptr array=0; unsigned size=0;} DBL_Array;
double Sum(int, int);
double Cslope(double, double, double, double);
double Sum_Sequence(double);
double Matrix_Determinant(Matrix);
double (*dynamically_allocated_array());
double npr(double, double);
double factorial(double);
void Print(Matrix);
void Print(Matrix, int precision);
void Print(String_Array);
void factoring();
void Matrix_CFill(Matrix, unsigned);
void push_back(String_Array&, string);
void Swap(double &a, double &b);
unsigned Column_Len(dptr column);
Matrix_Size Matrix_Len(Matrix);
size_t ArrLen(string*);
pptr Permute(DBL_Array*, unsigned *, unsigned, unsigned, pptr);
Row RowMK(unsigned columns);
Row Get_Column(Matrix, unsigned);
dptr Rearrange(dptr, bool);
Matrix Fill_Matrix(Matrix_Size);
Matrix MatrixMK(Matrix_Size);
Matrix Matrix_Addition(Matrix, Matrix);
Matrix Matrix_Subtraction(Matrix, Matrix);
Matrix Matrix_Scalar_Multiplication(double, Matrix);
Matrix Product_Matrix(Matrix, Matrix);
Matrix Formulate_Matrix(Matrix, unsigned, unsigned);
Matrix Matrix_Co_Factors(Matrix);
Matrix Matrix_Transpose(Matrix);
Matrix Matrix_Inverse(Matrix);
string MkLine(double, double, double, double);
string SubStr(string, unsigned, unsigned);
String_Array Split(const string, const string);
Point MPoint(double, double, double, double);
Point IPoint(double, double, double, double, double, double, double, double);
