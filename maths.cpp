#include "maths.h"
Point MPoint(double x1, double y1, double x2, double y2){
    Point mpoint{(x1 + x2)/2, (y1 + y2)/2};
    return mpoint;
}
Point IPoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    double m1 = Cslope(x1, y1, x2, y2), c1 = -m1 * x1 + y1;
    double m2 = Cslope(x3, y3, x4, y4), c2 = -m2 * x3 + y3;
    double ix = (m1 - m2 != 0) ? (c2 - c1)/(m1 - m2) : ULONG_MAX;
    double iy = (ix != ULONG_MAX) ? m1 * (ix) + c1 : ULONG_MAX;
    Point ipoint{ix, iy};
    return ipoint;
}
string MkLine(double x1, double y1, double x2, double y2){
    double m = Cslope(x1, y1, x2, y2), c = -m * x1 + y1;
    return (m < ULONG_MAX) ? ((m != 1) ? ((c != 0) ? ("y = " + to_string(m) + "x " + to_string(c)): ("y = " + to_string(m) + "x")): ((c != 0) ? ("y = x " + to_string(c)): ("y = x"))) : ("x = " + to_string(x1));
    }
string SubStr(string str,unsigned start,unsigned end){
    string new_string = "";
    for (; start <= end; new_string += str[start], start++);
    return new_string;
}
Matrix_Size Matrix_Len(double** matrix){
    unsigned i=0, j=0, first_time = 1;
    for (; *(matrix+i) != NULL; i++)
        if (first_time){
            for (;*(matrix[0] + j) < ULLONG_MAX; j++);
            first_time = false;}
    Matrix_Size size{i, j};
    return size;
}
size_t ArrLen(string* array){
    int i = 0;
    if (array) for (; 0 < array[i].length(); i++);
    return i;
}
unsigned Column_Len(double* column){
    unsigned i=0;
    for(; *(column+i) != ULLONG_MAX; i++);
    return i;
}
double Sum(int start, int end){
    double sum = 0;
    for (int i = start; i <= end; sum += i, i++);
    return sum;
}
double Cslope(double x1, double y1, double x2, double y2){return (x2 - x1 != 0) ? ((y2 - y1)/(x2 - x1)) : ULLONG_MAX;}
double Sum_Sequence(double* list){
    double result = 0;
    for (int i=0; i<Column_Len(list); i++)
        result += list[i];
    return result;
}
double Matrix_Determinate(double** matrix){
    double result = 0;
    Matrix_Size size = Matrix_Len(matrix);
    int c = 1;
    if (size.rows == 1 && size.columns == 1){return matrix[0][0];}
    if (size.rows && size.columns == size.rows){
        for (int i = 0; i < size.columns; i++){
            double** minor_matrix = MatrixMK(size.rows-1, size.columns-1);
            for (int j = 1; j < size.rows; j++){
                unsigned index = 0;
                for (int k = 0; k < size.columns; k++){
                    if (i != k){
                        minor_matrix[j-1][index] = matrix[j][k];
                        index++;
                    }
                }
            }
            result += matrix[0][i] * c * Matrix_Determinate(minor_matrix);
            c *= -1;
        }
        return result;
    }
}
double** MatrixMK(unsigned rows, unsigned columns){
    columns++; rows++;
    double** matrix = new double*[rows];
    for (int i=0; i<rows; i++){
        matrix[i] = new double[columns];
        for (int j=0; j<columns; j++){
            matrix[i][j] = 0;
        }
        matrix[i][columns-1] = ULLONG_MAX;
    }
    matrix[rows-1] = NULL;
    return matrix;
}
double** Fill_Matrix(unsigned rows, unsigned columns){
  double** matrix = MatrixMK(rows, columns);
  for (unsigned i = 0; i < rows; i++) {
        a:
        string input_data;
        cout << "Fill Row[" << i+1 << "]: ";
        getline(cin, input_data);
        if (ArrLen(Split(input_data, " ")) >= columns) {
          for (unsigned j=0; j<columns; j++){
              string new_data = "";
              for (; input_data.length() && input_data[0] != ' '; new_data += input_data[0], input_data.erase(input_data.begin()));
              if (input_data.length() > 0) input_data.erase(input_data.begin());
              matrix[i][j] = stod(new_data);
          }
        } else {
          cout << "Insufficient data" << endl;
          goto a;
        }
      }
  return matrix;}
double** Matrix_Addition(double** mat1, double** mat2){
        Matrix_Size size0 = Matrix_Len(mat1), size1 = Matrix_Len(mat2);
        double** matrix = MatrixMK(size0.rows, size0.columns);
        if (size0.rows == size1.rows && size0.columns == size1.columns && size0.rows && size0.columns){
            for (unsigned i = 0; i<size0.rows; i++){
                for (unsigned j = 0; j<size0.columns; j++)
                    matrix[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        return matrix;
}
double** Matrix_Subtraction(double** mat1, double** mat2){
        Matrix_Size size0 = Matrix_Len(mat1), size1 = Matrix_Len(mat2);
        double** matrix = MatrixMK(size0.rows, size0.columns);
        if (size0.rows == size1.rows && size0.columns == size1.columns && size0.rows && size0.columns){
            for (unsigned i = 0; i<size0.rows; i++){
                for (unsigned j = 0; j<size0.columns; j++)
                    matrix[i][j] = mat1[i][j] - mat2[i][j];
            }
        }
        return matrix;
}
double** Matrix_Scalar_Multiplication(double scalar, double** matrix){
        Matrix_Size size = Matrix_Len(matrix);
        double** multimat = MatrixMK(size.rows, size.columns);
        if (size.rows > 0 and size.columns > 0)
                for (int i = 0; i<size.rows; i++)
                    for (int j=0; j < size.columns; j++)
                         multimat[i][j] = scalar * matrix[i][j];
        return multimat;
}
double** Product_Matrix(double** mat1, double** mat2){
    Matrix_Size size0 = Matrix_Len(mat1), size1 = Matrix_Len(mat2);
    double** matrix = MatrixMK(size0.rows, size1.columns);
    if (size1.rows > 0 && size0.rows> 0 && size0.columns == size1.rows){
        for (int i = 0; i < size0.rows; i++){
            for (int k = 0; k < size1.columns; k++){
                double result = 0;
                double* new_column = Get_Column(mat2, k);
                for (int j = 0; j < Column_Len(new_column); j++ ){
                        result += mat1[i][j] * new_column[j];
                }
                matrix[i][k] = result;
            }
        }
    }
    return matrix;
}
double** Formulate_Matrix(double** matrix, unsigned rownum, unsigned colnum){
    Matrix_Size size = Matrix_Len(matrix);
    double** formulated_matrix = MatrixMK(size.rows-1, size.columns-1);
    unsigned k=0;
    for (int i = 0; i < size.rows; i++){
        unsigned w = 0;
        if (i != rownum){
            for (int j = 0; j < size.columns; j++){
                if (j != colnum){
                    formulated_matrix[k][w] = matrix[i][j];
                    w++;}
            }
            k++;
        }
    }
    return formulated_matrix;
}
double** Matrix_Co_Factors(double** matrix){
    int c = 1;
    Matrix_Size size = Matrix_Len(matrix);
    double** co_factor_matrix = MatrixMK(size.rows, size.columns);
    if (size.rows == size.columns && size.rows > 0){
        for (int i = 0; i < size.rows; i++){
            for (int j = 0; j < size.columns; j++){
                co_factor_matrix[i][j] = c * Matrix_Determinate(Formulate_Matrix(matrix, i, j));
                cout << endl;
                c *= -1;
            }
        }
    }
    return co_factor_matrix;
}
double** Matrix_Transpose(double** matrix){
    Matrix_Size size = Matrix_Len(matrix);
    double** transposed_matrix = MatrixMK(size.columns, size.rows);
    if (size.rows > 0){
        for (int i = 0; i < size.rows; i++){
            transposed_matrix[i] = Get_Column(matrix, i);
        }
    }
    return transposed_matrix;
}
double** Matrix_Inverse(double** matrix){
    Matrix_Size size = Matrix_Len(matrix);
    double** Inverse = MatrixMK(size.rows, size.columns);
    if (size.rows > 0 && size.rows == size.columns){
        double det = Matrix_Determinate(matrix);
        if (det != 0){Inverse = Matrix_Scalar_Multiplication(1/det, Matrix_Transpose(Matrix_Co_Factors(matrix)));}
    }
    return Inverse;
}
double* RowMK(unsigned columns){
    double* column = new double[columns+1];
    for (int i=0; i<columns; i++){
        column[i] = 0;
    }
    column[columns] = ULLONG_MAX;
    return column;
}
double* Get_Column(double** matrix, unsigned colnum){
    Matrix_Size size = Matrix_Len(matrix);
    double* row = RowMK(size.rows+1);
    if (size.rows > 0 && size.columns > 0 && colnum < size.columns){
        unsigned index = 0;
        for (int i=0; i<size.rows; i++, index++)
            row[index] = matrix[i][colnum];
    }
    row[size.rows] = ULONG_MAX;
    return row;
}
double* Rearrange(double* list, bool reversed = false){
        unsigned index = 0;
        if (!reversed){
            while (index < Column_Len(list) - 1){
                if (list[index] > list[index + 1]){
                    double index0 = list[index], index1 = list[index + 1];
                    list[index] = index1;
                    list[index + 1] = index0;
                    index = 0;
                    continue;
                }
                index++;
            }
        }else{
            while (index < Column_Len(list) - 1){
                if (list[index] < list[index + 1]){
                    double index0 = list[index], index1 = list[index + 1];
                    list[index] = index1;
                    list[index + 1] = index0;
                    index = 0;
                    continue;
                }
                index++;
            }
        }
    return list;
}
string *Split(string str, string splitter) {
  bool istrue = false;
  string *chunks = NULL, splitted_text;
  for (int i = 0; i < str.length();) {
    if (str[i] == splitter[0]) {
      for (int j = 0; j < splitter.length(); j++){
        if (str[i + j] != splitter[j]){
          istrue = false;
          break;
        }
        else istrue = true;
      }
      if (istrue){
        i += splitter.length();
        if (splitted_text.length()) push_back(chunks, splitted_text);
        splitted_text = "";
        istrue = false;
        continue;
      } else {
        splitted_text += str[i];
      }
    } else {
      splitted_text += str[i];
      if (i + 1 == str.length()) {
        if (splitted_text.length()) {
          if (splitted_text.length()) push_back(chunks, splitted_text);
        }
      }
    }
    i++;
  }
  return chunks;
}
void Print(double** matrix){
    Matrix_Size size = Matrix_Len(matrix);
    for (int i=0; i<size.rows; i++){
        for (int j=0; j<size.columns; j++)
            cout << left << setw(17) << matrix[i][j];
        cout << '\n';
    }
}
void Print(double** matrix, unsigned int precision){
    Matrix_Size size = Matrix_Len(matrix);
    for (int i=0; i<size.rows; i++){
        for (int j=0; j<size.columns; j++)
            cout << setw(precision) << matrix[i][j];
        cout << '\n';
    }
}
void factoring(){
    a:
        int number, is_negative = false;
        cout << "Please enter number to get it's factors: ";
        cin >> number;
        int next_count = 2;
        if (number > 0){
            cout << 1 << " ";}
        else
            {
                cout << "(" << -1 << ", " << 1 << ") ";
                is_negative = true;
                number *= -1;
            }
        while (next_count <= number)
        {
            if (number % next_count == 0)
            {
                if (is_negative)
                {
                    cout << "(" << next_count << ", " << -next_count << ") " ;
                }
                else
                {
                    cout << next_count << " ";
                }
            }
            next_count += 1;
        }
        cout << "\n";
        goto a;
}
void Matrix_CFill(double** &matrix, unsigned c){
    Matrix_Size size = Matrix_Len(matrix);
    if (size.rows && size.columns){
        for (int i=0; i<3/*size.rows*/; i++){
            for (int j=0; j<3/*size.columns*/; j++){
                matrix[i][j] = c;
            }
        }
    }
}
void push_back(string*& str_array, string item){
    size_t size = ArrLen(str_array);
    string *new_array = (string*) realloc(str_array, sizeof(string) * (size+2));
    if (new_array != NULL){
        str_array = new_array;
        str_array[size] = item;
    }else{free(new_array);}
}
