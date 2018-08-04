#include "strings.h"
size_t ArrLen(string* &array){
    int i = 0;
    if (array) for (; 0 < array[i].length(); i++);
    return i;
    //if (array) cout << array.size() << endl;
}
void push_back(string*& str_array, string item){
    size_t size = ArrLen(str_array);
    string *new_array = (string*) realloc(str_array, sizeof(string) * (size+2));
    if (new_array != NULL){
        str_array = new_array;
        str_array[size] = item;
    }else{free(new_array);}
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
string SubStr(string str,unsigned start,unsigned end){
    string new_string = "";
    for (; start <= end; new_string += str[start], start++);
    return new_string;
}
void Print(Matrix matrix){
    for (Row& row : matrix){
        for (double column : row){cout << column << " ";}
        cout << "\n";
    }
}
void Print(Row row){
    for (double column : row){
        cout << column << " ";
    }
    cout << endl;
}
void Print(string_array arr){
    for (string column : arr){
            cout << column << " ";
        }
        cout << endl;
}
void Print(char_array arr){
    for (int i = 0; i < CharArrLen(arr); i++)cout << arr[i];
    cout << '\n';
}
int CharArrLen(const char *Arr){
    int length = 0;
    while (Arr[length] != '\0')length++;
    return length;
}
int StrIndexOf(const char *str, char strtf){
    int index = -1;
    bool istrue = false;
    for (int i = 0; i < CharArrLen(str); i++){
        if (str[i] == strtf){index = i;break;}
    }
    return index;
}
int StrIndexOf(const char *str, const char* strtf){
    int index = -1;
    bool istrue = false;
    for (int i = 0; i < CharArrLen(str); i++){
        if (str[i] == strtf[0]){
            for (int k = 0; k < CharArrLen(strtf); k++){
                if (str[i+k] != strtf[k]){
                    istrue = false;
                    break;
                }
                else istrue = true;
            }
            if (istrue){index = i;break;}
        }
    }
    return index;
}
int StrIndexOf(const char *str, const char* strtf, unsigned start){
    int index = -1;
    bool istrue = false;
    if (start < CharArrLen(str)){for (int i = start; i < CharArrLen(str); i++){
        if (str[i] == strtf[0]){
            for (int k = 0; k < CharArrLen(strtf); k++){
                if (str[i+k] != strtf[k]){
                    istrue = false;
                    break;
                }
                else istrue = true;
            }
            if (istrue){index = i;break;}
        }
    }}
    return index;
}
int StrIndexOf(const char *str, char strtf, unsigned start){
    int index = -1;
    bool istrue = false;
    if (start < CharArrLen(str)){
        for (int i = start; i < CharArrLen(str); i++){
            if (str[i] == strtf){index = i;break;}
        }
    }
    return index;
}
int StrIndexOf(const char *str, const char* strtf, unsigned start, unsigned end){
    int index = -1, length = CharArrLen(str);
    bool istrue = false;
    if (start < length && end < length){for (int i = start; i < end; i++){
        if (str[i] == strtf[0]){
            for (int k = 0; k < CharArrLen(strtf); k++){
                if (str[i+k] != strtf[k]){
                    istrue = false;
                    break;
                }
                else istrue = true;
            }
            if (istrue){index = i;break;}
        }
    }}
    return index;
}
int StrIndexOf(const char *str, char strtf, unsigned start, unsigned end){
    int index = -1, length = CharArrLen(str);
    bool istrue = false;
    if (start < length && end < length){
        for (int i = start; i < end; i++){
            if (str[i] == strtf){index = i;break;}
        }
    }
    return index;
}
char (*automatic_allocated_string()){}
