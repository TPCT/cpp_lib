#include "algorithm.h"
bool Has_Duplicates(DBL_Array array){
    DBL_Array new_array = DBL_ARR_MK(new double[array.size], array.size);
    for (int i=0, j=0; i<array.size-1; i++){
        if (!Contains(new_array, array.array[i])){new_array.array[j] = array.array[i]; j++;}
        else return true;
    }
    return false;
}
bool Contains(DBL_Array array, double item){
    Arrange(array, smaller_than);
    unsigned start=0, end=array.size-1, mid;
    while (start != end){
        mid = (start+end)/2;
        if (item == array.array[mid] || item == array.array[start] || item == array.array[end]) return true;
        else if (item < array.array[mid]) end = mid-1;
        else start = mid+1;
    }
}
bool smaller_than(double a, double b){return a < b;}
bool greater_than(double a, double b){return a > b;}
bool Balanced(DBL_Array array){
    for (int i=0, j=0, k=0; i<array.size; i++){
        if ((int)array.array[i]%2 != 0) j++;
        else k++;
        if (k > array.size/2 || j > array.size/2) return false;
    }
    return true;
}
Matrix MatMK(Matrix_Size size){
    pptr new_matrix = new double*[size.rows];
    for (int i=0; i<size.columns; i++){
        new_matrix[i] = new double[size.columns];
        for (int j=0; j<size.columns; j++){
            new_matrix[i][j] = 0;
        }
    }
    return Matrix{new_matrix, size, 0};
}
DBL_Array DBL_ARR_MK(double arr[], unsigned size){return DBL_Array{arr, size};}
double factorial(double n){
    double result = 1;
    while (n){result *= n;n-=1;}
    return result;
}
double npr(double n, double r){return factorial(n)/factorial(n-r);}
double *Arrange(void* Array, unsigned size, bool (*comparison)(double, double)){
    double* ptr = static_cast<double*>(Array);
    for (int i=0; i<size-1; i++)
        for (int j=i+1; j<size; j++)
            if (comparison(ptr[j], ptr[i]))
                swap(ptr[i], ptr[j]);
}
double **Permute(DBL_Array* Array, unsigned *index, unsigned start, unsigned end, pptr container){
    end = (end < UINT_MAX) ? end : (*Array).size;
    if (!index){
        double *temp = (*Array).array;
        for (int i=0; i<=(*Array).size; i++, (temp)++);
        for (; (double)(*((*Array).array)) != 0; (temp)++);
        unsigned &ref = reinterpret_cast<unsigned &>(temp);
        index = &ref;
        *index = 0;
    }
    long long size = factorial((*Array).size);
    if (!container){container = new double*[(long long)factorial((*Array).size)];}
    if (start == end){
    double *new_array = new double[(*Array).size];
    for (int i=0; i<(*Array).size; i++){
        new_array[i] = (*Array).array[i];}
    container[*index] = new_array; (*index)++;}
    for (int i=start; i<end; i++){
        Swap((*Array).array[start], (*Array).array[i]);
        Permute(Array, index, start+1, end, container);
        Swap((*Array).array[start], (*Array).array[i]);
    }
    return container;
}
unsigned Number_Length(double number){
    number = (number < 0) ? (-1*number) : number;
    int length = 1;
    while (number >= 1){
        number = (number/10) - ((long long)number%10);
        length++;
    }
    return length;
}
unsigned precision(void * array, unsigned size){
    unsigned max_length = 0;
    double *ptr = static_cast<double*>(array);
    for (unsigned i=0; i<size; i++){
        unsigned size = Number_Length(*(ptr+i));
        if (size > max_length)
            max_length = size;
    }
    return max_length;
}
void Arrange(DBL_Array array, bool (*comparison)(double, double)){
    for (int i=0; i<array.size; i++){
        for (int j=0; j<i; j++){
            if (comparison(array.array[i], array.array[j])){
                Swap(array.array[j], array.array[i]);
            }
        }
    }

}
void Print(void* Array, unsigned size){
    double *ptr;
    ptr = static_cast<double*>(Array);
    for (int i=0; i<size; i++)
        cout << setw(4) << ptr[i];
    cout << '\n';
}
void Print(DBL_Array array){
    for (int i=0; i<array.size; i++)
        cout << setw(4) << array.array[i];
    cout << '\n';
}
void Swap(double &a, double &b){double temp = a; a = b; b = temp;}
void Reverse(DBL_Array array){
    for (int i=0; i<array.size/2; i++)
        Swap(array.array[i], array.array[array.size-(1+i)]);
}
void Special_Sort(DBL_Array array){
    Arrange(array, smaller_than);
    for (int i=0; i<array.size; i++){
        if ((int)array.array[i] % 2 != 0){
            for (int j=i+1; j<array.size; j++){
                if ((int)array.array[j] % 2 == 0){
                    Swap(array.array[i], array.array[j]);
                    break;
                }
            }
        }
    }}
void Rotate(DBL_Array array){
    for (int i=array.size-1; i>0; i--){
        Swap(array.array[i], array.array[i-1]);
    }
}
