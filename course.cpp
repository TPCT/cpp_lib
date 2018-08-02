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

void factoring()
{
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
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
using Matrix =  vector<vector<double>>;
using Row = vector<double>;
vector<double> rearrange(vector<double> list, bool reversed = false){
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
double sum_sequence(vector<double> list){
    double result = 0;
    for (double element : list){
        result += element;
    }
    return result;
}
double matrix_determinate(vector<double> list){}
string substr(string str,int start,int end){
    string new_string = "";
    for (; start <= end; new_string += str[start], start++);
    return new_string;
}
vector<string> split(string str, string splitter){
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
void Print_Matrix(Matrix& matrix){
    for (Row& row : matrix){
        for (double column : row){cout << column << " ";}
        cout << "\n";
    }
}
Matrix fill_matrix(double rows, double columns){
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
                if (split(input_data, " ").size() >= columns){
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
Matrix Matrix_addition(Matrix mat1, Matrix mat2){
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
Matrix Matrix_subtraction(Matrix mat1, Matrix mat2){
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
Matrix Matrix_scalar_multiplication(double scalar, Matrix mat1){
        if (mat1.size() > 0 and mat1[0] > 0){
                Matrix summation_matrix(mat1.size(), vector<double>(mat1[0].size()));
                for (int row = 0; row < mat1.size(); row++){
                         for (int column = 0; column < mat1[row].size(); column++){summation_matrix[row][column] = scalar * mat1[row][column];}
                }
            return summation_matrix;
        }else{return Matrix(0, vector<double>(0));}
}
