#include "maths.h"
void intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int& ix, int& iy){
    double m1 = (x1 - x2) == 0 ? (INFINITY) : ((y1 - y2) == 0 ? 0 : (y2-y1)/(x2-x1)),
           m2 = (x3 - x4) == 0 ? (INFINITY) : ((y3 - y4) == 0 ? 0 : (y4-y3)/(x4-x3));
    if (m1 == m2)
        ix = INFINITY, iy=INFINITY;
    else{
        ix = (m1 == INFINITY) ? (x1) : ((m2 == INFINITY) ? (x3) : ((y3 - y1 + m1 * x1 - m2 * x3)/(m1 - m2)));
        iy = (m1 == 0) ? (y1) : ((m2 == 0) ? (y3) : (m1*(ix - x1) + y1));
    }
}
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
Matrix_Size Matrix_Len(pptr matrix){
    unsigned i=0, j=0, first_time = 1;
    for (; *(matrix+i) != NULL; i++)
        if (first_time){
            for (;*(matrix[0] + j) < ULLONG_MAX; j++);
            first_time = false;}
    Matrix_Size size{i, j};
    return size;
}
size_t ArrLen(sptr array){
    int i = 0;
    if (array) for (; 0 < array[i].length(); i++);
    return i;
}
unsigned Column_Len(dptr column){
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
double factorial(double n){
    double result = 1;
    while (n){result *= n;n-=1;}
    return result;
}
double npr(double n, double r){return factorial(n)/factorial(n-r);}
double Sum_Sequence(double* list){
    double result = 0;
    for (int i=0; i<Column_Len(list); i++)
        result += list[i];
    return result;
}
double Matrix_Determinant(Matrix matrix){
    double result = 0;
    Matrix_Size size = matrix.size;
    int c = 1;
    if (size.rows == 1 && size.columns == 1){return matrix.matrix[0][0];}
    if (size.rows && size.columns == size.rows){
        for (int i = 0; i < size.columns; i++){
            Matrix_Size new_size{size.rows-1, size.columns-1};
            Matrix minor_matrix = MatrixMK(new_size);
            for (int j = 1; j < size.rows; j++){
                unsigned index = 0;
                for (int k = 0; k < size.columns; k++){
                    if (i != k){
                        minor_matrix.matrix[j-1][index] = matrix.matrix[j][k];
                        index++;
                    }
                }
            }
            result += matrix.matrix[0][i] * c * Matrix_Determinant(minor_matrix);
            c *= -1;
        }
        return result;
    }
}
pptr Permute(DBL_Array* Array, unsigned *index, unsigned start, unsigned end, pptr container){
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
    if (!container){container = new double*[(*Array).size];}
    if (start == end){
         double *new_array = new double[(*Array).size];
        for (int i=0; i<(*Array).size; i++){
        new_array[i] = (*Array).array[i];}
        container[*index] = new_array;
        (*index)++;
    }
    for (int i=start; i<end; i++){
        Swap((*Array).array[start], (*Array).array[i]);
        Permute(Array, index, start+1, end, container);
        Swap((*Array).array[start], (*Array).array[i]);
    }
    return container;
}
Matrix MatrixMK(Matrix_Size size){
    pptr matrix = new double*[size.rows];
    for (int i=0; i<size.rows; i++){
        matrix[i] = new double[size.columns];
        for (int j=0; j<size.columns; j++){
            matrix[i][j] = 0;
        }
    }
    return Matrix{matrix, size, 0};
}
Matrix Fill_Matrix(Matrix_Size size){
  Matrix matrix = MatrixMK(size);
  for (unsigned i = 0; i < size.rows; i++) {
        a:
        string input_data;
        cout << "Fill Row[" << i+1 << "]: ";
        cin >> skipws;
        getline(cin, input_data);
        if (Split(input_data, " ").size >= size.columns) {
          for (unsigned j=0; j<size.columns; j++){
              string new_data = "";
              for (; input_data.length() && input_data[0] != ' '; new_data += input_data[0], input_data.erase(input_data.begin()));
              if (input_data.length() > 0) input_data.erase(input_data.begin());
              matrix.matrix[i][j] = stod(new_data);
          }
        } else {
          cout << "Insufficient data" << endl;
          goto a;
        }
      }
  return matrix;}
Matrix Matrix_Addition(Matrix mat1, Matrix mat2){
        Matrix_Size size0 = mat1.size, size1 = mat2.size;
        Matrix matrix = MatrixMK(size0);
        if (size0.rows == size1.rows && size0.columns == size1.columns && size0.rows && size0.columns){
            for (unsigned i = 0; i<size0.rows; i++){
                for (unsigned j = 0; j<size0.columns; j++)
                    matrix.matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];
            }
        }
        return matrix;
}
Matrix Matrix_Subtraction(Matrix mat1, Matrix mat2){
        Matrix_Size size0 = mat1.size, size1 = mat2.size;
        Matrix matrix = MatrixMK(size0);
        if (size0.rows == size1.rows && size0.columns == size1.columns && size0.rows && size0.columns){
            for (unsigned i = 0; i<size0.rows; i++){
                for (unsigned j = 0; j<size0.columns; j++)
                    matrix.matrix[i][j] = mat1.matrix[i][j] - mat2.matrix[i][j];
            }
        }
        return matrix;
}
Matrix Matrix_Scalar_Multiplication(double scalar, Matrix matrix){
        Matrix_Size size = matrix.size;
        Matrix multimat = MatrixMK(size);
        if (size.rows > 0 and size.columns > 0)
                for (int i = 0; i<size.rows; i++)
                    for (int j=0; j < size.columns; j++)
                         multimat.matrix[i][j] = scalar * matrix.matrix[i][j];
        return multimat;
}
Matrix Product_Matrix(Matrix mat1, Matrix mat2){
    Matrix_Size size0 = mat1.size, size1 = mat2.size;
    Matrix matrix = MatrixMK(size0);
    if (size1.rows > 0 && size0.rows> 0 && size0.columns == size1.rows){
        for (int i = 0; i < size0.rows; i++){
            for (int k = 0; k < size1.columns; k++){
                double result = 0;
                Row new_column = Get_Column(mat2, k);
                for (int j = 0; j < new_column.size; j++ ){
                        result += mat1.matrix[i][j] * new_column.row[j];
                }
                matrix.matrix[i][k] = result;
            }
        }
    }
    return matrix;
}
Matrix Formulate_Matrix(Matrix matrix, unsigned rownum, unsigned colnum){
    Matrix_Size size{matrix.size.rows-1, matrix.size.columns-1};
    Matrix formulated_matrix = MatrixMK(size);
    unsigned k=0;
    for (int i = 0; i < size.rows; i++){
        unsigned w = 0;
        if (i != rownum){
            for (int j = 0; j < size.columns; j++){
                if (j != colnum){
                    formulated_matrix.matrix[k][w] = matrix.matrix[i][j];
                    w++;}
            }
            k++;
        }
    }
    return formulated_matrix;
}
Matrix Matrix_Co_Factors(Matrix matrix){
    int c = 1;
    Matrix_Size size = matrix.size;
    Matrix co_factor_matrix = MatrixMK(size);
    if (size.rows == size.columns && size.rows > 0){
        for (int i = 0; i < size.rows; i++){
            for (int j = 0; j < size.columns; j++){
                co_factor_matrix.matrix[i][j] = c * Matrix_Determinant(Formulate_Matrix(matrix, i, j));
                cout << endl;
                c *= -1;
            }
        }
    }
    return co_factor_matrix;
}
Matrix Matrix_Transpose(Matrix matrix){
    Matrix_Size size = matrix.size;
    Matrix transposed_matrix = MatrixMK(size);
    if (size.rows > 0){
        for (int i = 0; i < size.rows; i++){
            transposed_matrix.matrix[i] = Get_Column(matrix, i).row;
        }
    }
    return transposed_matrix;
}
Matrix Matrix_Inverse(Matrix matrix){
    Matrix_Size size = matrix.size;
    if (size.rows > 0 && size.rows == size.columns){
        double det = Matrix_Determinant(matrix);
        if (det != 0){
            Matrix Inverse = Matrix_Scalar_Multiplication(1/det, Matrix_Transpose(Matrix_Co_Factors(matrix)));
            return Inverse;
        }
    }
    return MatrixMK(Matrix_Size{0, 0});
}
Row RowMK(unsigned columns){
    dptr column = new double[columns];
    for (int i=0; i<columns; i++){
        column[i] = 0;
    }
    return Row{column, columns};
}
Row Get_Column(Matrix matrix, unsigned colnum){
    Matrix_Size size = matrix.size;
    Row row = RowMK(size.rows);
    if (size.rows > 0 && size.columns > 0 && colnum < size.columns){
        unsigned index = 0;
        for (int i=0; i<size.rows; i++, index++)
            row.row[index] = matrix.matrix[i][colnum];
    }
    return row;
}
dptr Rearrange(dptr list, bool reversed = false){
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
String_Array Split(string str, string splitter) {
  bool istrue = false;
  string *chunks = NULL, splitted_text;
  String_Array chunks_Array{chunks, 0};
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
        if (splitted_text.length()) push_back(chunks_Array, splitted_text);
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
          if (splitted_text.length()) push_back(chunks_Array, splitted_text);
        }
      }
    }
    i++;
  }
  return chunks_Array;
}
void Print(Matrix matrix){
    Matrix_Size size = matrix.size;
    for (int i=0; i<size.rows; i++){
        for (int j=0; j<size.columns; j++)
            cout << left << setw(17) << matrix.matrix[i][j];
        cout << '\n';
    }
}
void Print(Matrix matrix, unsigned int precision){
    Matrix_Size size = matrix.size;
    for (int i=0; i<size.rows; i++){
        for (int j=0; j<size.columns; j++)
            cout << setw(precision) << matrix.matrix[i][j];
        cout << '\n';
    }
}
void Print(String_Array str_array){
    for (int i=0; i<str_array.size; i++)
        cout << str_array.array[i] << '\n';
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
void Matrix_CFill(Matrix matrix, unsigned c){
    Matrix_Size size = matrix.size;
    if (size.rows && size.columns){
        for (int i=0; i<size.rows; i++){
            for (int j=0; j<size.columns; j++){
                matrix.matrix[i][j] = c;
            }
        }
    }
}
void push_back(String_Array &str_array, string item){
    string *new_array = (string*) realloc(str_array.array, sizeof(string) * (str_array.size+1));
    if (new_array != NULL){
        str_array.array = new_array;
        str_array.array[str_array.size] = item;
        str_array.size++;
    }else{free(new_array);}
}
void Swap(double &a, double &b){double temp = a; a = b; b = temp;}
