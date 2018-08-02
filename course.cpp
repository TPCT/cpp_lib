void tree_print()
{
    cout << "Please enter the height of the tree: ";
    int height, space_counter = 0;
    cin >> height;
    height = (2*height) + 1;
    while (height >= 0){
        int min_counter = 0;
        while(min_counter < space_counter){
            cout << " ";
            min_counter++;
        }
        min_counter = 0;
        while (min_counter < height){
            cout << "*";
            min_counter++;
        }
        cout << '\n';
        height -= 2;
        space_counter++;
    }
    return 0;
}

string parse_time(unsigned long seconds){
    const unsigned SECONDS_PER_MIN = 60,
    SECONDS_PER_HOUR = SECONDS_PER_MIN * 60,
    SECONDS_PER_DAY = SECONDS_PER_HOUR  * 24,
    SECONDS_PER_MONTH = SECONDS_PER_DAY * 30,
    SECONDS_PER_YEAR = SECONDS_PER_MONTH * 12,
    SECONDS_PER_CENTURY = SECONDS_PER_YEAR * 100;
    unsigned centuries = 0, years = 0, months = 0, days = 0, hours = 0, minutes = 0;
    centuries = seconds / SECONDS_PER_CENTURY; seconds %= SECONDS_PER_CENTURY;
    years = seconds / SECONDS_PER_YEAR; seconds %= SECONDS_PER_YEAR;
    months = seconds / SECONDS_PER_MONTH; seconds %= SECONDS_PER_MONTH;
    days = seconds / SECONDS_PER_DAY; seconds %= SECONDS_PER_DAY;
    hours = seconds / SECONDS_PER_HOUR; seconds %= SECONDS_PER_HOUR;
    minutes = seconds / SECONDS_PER_MIN; seconds %= SECONDS_PER_MIN;
    string parsed_string = "";
    switch (centuries){
        case 1:
            parsed_string += "1 century ";
        default:
            parsed_string += to_string(centuries) + " centuries ";
            break;
    }
    switch (years){
        case 1:
            parsed_string += "1 year ";
        default:
            parsed_string += to_string(years) + " years ";
            break;
    }
    switch (months){
        case 1:
            parsed_string += "1 month ";
        default:
            parsed_string += to_string(months) + " months ";
            break;
    }
    switch (days){
        case 1:
            parsed_string += "1 day ";
        default:
            parsed_string += to_string(days) + " days ";
            break;
    }
    switch (hours){
        case 1:
            parsed_string += "1 hour ";
        default:
            parsed_string += to_string(hours) + " hours ";
            break;
    }
    switch (seconds){
        case 1:
            parsed_string += "1 second";
        default:
            parsed_string += to_string(seconds) + " seconds";
            break;
    }
    return parsed_string;
}


string set_width_fill(string text, int width, char fill_char, bool left = false){
    int new_width = width - text.length();
    if (new_width > 0){
        if (left){
            for (int i = 0; i < new_width; i++){
                text += fill_char;
            }
        }
        else{
            for (int i = 0; i < new_width; i++){
                text = fill_char + text;
            }
        }
    }
        return text;
}
#include <tuple>
#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include "math.h"
tuple<double, double> MPoint(double x1, double y1, double x2, double y2){
    int mx = (x1 + x2)/2, my = (y1 + y2)/2;
    return make_tuple(mx, my);
}
tuple<double, double> MPoint(double x1, double y1, double x2, double y2, double& mx, double& my){
    mx = (x1+x2)/2;
    my = (y1+y2)/2;
    return make_tuple(mx, my);
}
tuple<double, double> IPoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    double m1 = Cslope(x1, y1, x2, y2), c1 = -m1 * x1 + y1;
    double m2 = Cslope(x3, y3, x4, y4), c2 = -m2 * x3 + y3;
    double ix = (m1 - m2 != 0) ? (c2 - c1)/(m1 - m2) : ULONG_MAX;
    double iy = (ix != ULONG_MAX) ? m1 * (ix) + c1 : ULONG_MAX;
    return make_tuple(ix, iy);
}
tuple<double, double> IPoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& ix, double& iy){
double m1 = Cslope(x1, y1, x2, y2), c1 = -m1 * x1 + y1;
    double m2 = Cslope(x3, y3, x4, y4), c2 = -m2 * x3 + y3;
    ix = (m1 - m2 != 0) ? (c2 - c1)/(m1 - m2) : ULONG_MAX;
    iy = (ix != ULONG_MAX) ? m1 * (ix) + c1 : ULONG_MAX;
    return make_tuple(ix, iy);
}
double Sum(int start, int end){
    double sum = 0;
    for (int i = start; i <= end; sum += i, i++);
    return sum;
}
double Cslope(double x1, double y1, double x2, double y2){return (x2 - x1 != 0) ? ((y2 - y1)/(x2 - x1)) : ULLONG_MAX;}
double Sum_Sequence(Row list){
    double result = 0;
    for (double element : list){
        result += element;
    }
    return result;
}
double Matrix_Determinate(Matrix matrix){
    double result = 0;
    int c = 1;
    if (matrix.size() == 1 && matrix[0].size() == 1){return matrix[0][0];}
    if (matrix.size() && matrix[0].size() == matrix.size()){
        for (int i = 0; i < matrix[0].size(); i++){
            Matrix minor_matrix(matrix.size() - 1, Row(0));
            for (int j = 1; j < matrix.size(); j++){
                for (int k = 0; k < matrix[0].size(); k++){
                    if (i != k){
                        minor_matrix[j-1].push_back(matrix[j][k]);
                    }
                }
            }
            result += matrix[0][i] * c * Matrix_Determinate(minor_matrix);
            c *= -1;
        }
        return result;
    }
}
string MkLine(double x1, double y1, double x2, double y2){
    double m = Cslope(x1, y1, x2, y2), c = -m * x1 + y1;
    return (m < ULONG_MAX) ? ((m != 1) ? ((c != 0) ? ("y = " + to_string(m) + "x " + to_string(c)): ("y = " + to_string(m) + "x")): ((c != 0) ? ("y = x " + to_string(c)): ("y = x"))) : ("x = " + to_string(x1));
    }
string SubStr(string str,int start,int end){
    string new_string = "";
    for (; start <= end; new_string += str[start], start++);
    return new_string;
}
Matrix Fill_Matrix(double rows, double columns){
    if (columns > 0 && rows > 0){
            char last_char;
            char ignored[] = {' ', '\n', '\0'};
            bool first_time = true;
            Matrix matrix(rows, vector<double>(columns));
            int index = 1, counter = 0;
            for (Row& row : matrix){
                a:
                string input_data;
                cout << "Fill Row[" << index << "]: ";
                if (first_time){cin.ignore(); first_time = false;}
                getline(cin, input_data);
                if (Split(input_data, " ").size() >= columns){
                for (double& element : row){
                    string new_data = "";
                    for (;input_data.length() && input_data[0] != ' '; new_data += input_data[0], input_data.erase(input_data.begin()));
                    if (input_data.length() > 0) input_data.erase(input_data.begin());
                    element = stoi(new_data);
                }
                index++;}
                else{cout << "Insufficient data" << endl; goto a;}
            }
            return matrix;
    }
    return Matrix(0, vector<double>(0));
}
Matrix Matrix_Addition(Matrix mat1, Matrix mat2){
        if (mat1.size() == mat2.size() > 0 && mat1[0].size() == mat2.size() > 0){
            Matrix summation_matrix(mat1.size(), vector<double>(mat1[0].size()));
            for (int row = 0; row < mat1.size(); row++){
                        for (int column = 0; column < mat1[row].size(); column++){
                            summation_matrix[row][column] = mat1[row][column] + mat2[row][column];
                        }
                    }
                    return summation_matrix;
        }else{return Matrix(0, vector<double>(0));}
}
Matrix Matrix_Subtraction(Matrix mat1, Matrix mat2){
    if (mat1.size() == mat2.size() > 0 && mat1[0].size() == mat2.size() > 0){
        Matrix summation_matrix(mat1.size(), vector<double>(mat1[0].size()));
        for (int row = 0; row < mat1.size(); row++){
                    for (int column = 0; column < mat1[row].size(); column++){
                        summation_matrix[row][column] = mat1[row][column] - mat2[row][column];
                    }
                }
                return summation_matrix;
    }else{return Matrix(0, vector<double>(0));}
}
Matrix Matrix_Scalar_Multiplication(double scalar, Matrix matrix){
        if (matrix.size() > 0 and matrix[0].size() > 0){
                Matrix summation_matrix(matrix.size(), vector<double>(matrix[0].size()));
                for (int row = 0; row < matrix.size(); row++){
                         for (int column = 0; column < matrix[row].size(); column++){summation_matrix[row][column] = scalar * matrix[row][column];}
                }
            return summation_matrix;
        }else{return Matrix(0, vector<double>(0));}
}
Matrix Product_Matrix(Matrix mat1, Matrix mat2){
    Matrix product_matrix(mat1.size(), Row(0));
    if (mat1.size() > 0 && mat2.size() > 0 && mat1[0].size() == mat2.size()){
        for (int i = 0; i < mat1.size(); i++){
            for (int k = 0; k < mat1[i].size(); k++){
                double result = 0;
                Row new_column = Get_Column(mat2, k);
                for (int j = 0; j < new_column.size(); j++ ){
                        result += mat1[i][j] * new_column[j];
                }
                product_matrix[i].push_back(result);
            }
        }
    }
    return product_matrix;
}
Matrix Formulate_Matrix(Matrix matrix, int rownum, int colnum){
    Matrix formulated_matrix;
    for (int i = 0; i < matrix.size(); i++){
        if (i != rownum){
            formulated_matrix.push_back(Row(0));
            for (int j = 0; j < matrix[i].size(); j++){
                if (j != colnum){
                    formulated_matrix[formulated_matrix.size()-1].push_back(matrix[i][j]);
                }
            }
        }
    }
    return formulated_matrix;
}
Matrix Matrix_Co_Factors(Matrix matrix){
    int c = 1;
    Matrix co_factor_matrix;
    if (matrix.size() == matrix[0].size() && matrix.size() > 0){
        for (int i = 0; i < matrix.size(); i++){
            co_factor_matrix.push_back(Row(0));
            for (int j = 0; j < matrix[i].size(); j++){
                co_factor_matrix[co_factor_matrix.size()-1].push_back(c * Matrix_Determinate(Formulate_Matrix(matrix, i, j)));
                c *= -1;
            }
        }
    }
    return co_factor_matrix;
}
Matrix Matrix_Transpose(Matrix matrix){
    Matrix transposed_matrix;
    if (matrix.size() > 0){
        for (int i = 0; i < matrix.size(); i++){
            transposed_matrix.push_back(Get_Column(matrix, i));
        }
    }
    return transposed_matrix;
}
Matrix Matrix_Inverse(Matrix matrix){
    Matrix Inverse;
    if (matrix.size() > 0 && matrix.size() == matrix[0].size()){
        double det = Matrix_Determinate(matrix);
        if (det != 0){Inverse = Matrix_Scalar_Multiplication(1/det, Matrix_Transpose(Matrix_Co_Factors(matrix)));}
    }
    return Inverse;
}
Row Get_Column(Matrix matrix, int colnum){
    if (matrix.size() > 0 && matrix[0].size() > 0 && colnum < matrix[0].size()){
        Row column(0);
        for (Row row : matrix){
            column.push_back(row[colnum]);
        }
        return column;
    }
    return Row(0);
}
Row Rearrange(vector<double> list, bool reversed = false){
    double index = 0;
        if (!reversed){
            while (index < list.size() - 1){
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
            while (index < list.size() - 1){
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
vector<string> Split(string str, string splitter){
    vector<string> chunks;
    string splitted_text = "";
    bool istrue = false;
    for (int i=0; i < str.length();){
        if (str[i] == splitter[0]){
            for (int j=0; j < splitter.length(); j++){
                        if (str[i+j] != splitter[j]){
                            break;
                        }else{istrue = true;}
            }
            if (istrue){i += splitter.length();
            chunks.push_back(splitted_text);
            splitted_text = ""; istrue = false;continue;
            }else{splitted_text += str[i];}
        }else{splitted_text += str[i];
        if (i+1 == str.length()){
            if (splitted_text.length()){chunks.push_back(splitted_text);}
        }
      }
    i++;
    }
    return chunks;
}
void Print_Matrix(Matrix matrix){
    for (Row& row : matrix){
        for (double column : row){cout << column << " ";}
        cout << "\n";
    }
}
void Print_Vector(Row row){
    for (double column : row){
        cout << column << " ";
    }
    cout << endl;
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
    return 0;
}
