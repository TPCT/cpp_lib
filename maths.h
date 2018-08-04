#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef struct {double x=0; double y=0;} Point;
typedef struct {unsigned rows=0; unsigned columns=0;} Matrix_Size;
Point MPoint(double, double, double, double);
Point IPoint(double, double, double, double, double, double, double, double);
double Sum(int, int);
double Cslope(double, double, double, double);
double Sum_Sequence(double);
double Matrix_Determinate(double**);
double (*dynamically_allocated_array());
double* RowMK(unsigned columns);
double* Get_Column(double**, unsigned);
double* Rearrange(double*, bool);
double** Fill_Matrix(unsigned, unsigned);
double** MatrixMK(unsigned, unsigned);
double** Matrix_Addition(double**, double**);
double** Matrix_Subtraction(double**, double**);
double** Matrix_Scalar_Multiplication(double, double**);
double** Product_Matrix(double**, double**);
double** Formulate_Matrix(double**, unsigned, unsigned);
double** Matrix_Co_Factors(double**);
double** Matrix_Transpose(double**);
double** Matrix_Inverse(double**);
string MkLine(double, double, double, double);
string SubStr(string, unsigned, unsigned);
string* Split(const string, const string);
void Print(double**);
void Print(double**, int precision);
void factoring();
void Matrix_CFill(double**&, unsigned);
void push_back(string*&, string);
Matrix_Size Matrix_Len(double**);
size_t ArrLen(string*);
unsigned Column_Len(double* column);
