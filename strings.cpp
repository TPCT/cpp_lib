    #include "strings.h"
    size_t ArrLen(string* &array){
        int i = 0;
        if (array) for (; 0 < array[i].length(); i++);
        return i;
        //if (array) cout << array.size() << endl;
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
    string SubStr(string str,unsigned start,unsigned end){
        string new_string = "";
        for (; start <= end; new_string += str[start], start++);
        return new_string;
    }
    String_Array Create_Array(unsigned size){return String_Array{(string *)malloc(sizeof(string)*size), size};}
    void Print(String_Array str_array){
        for (int i=0; i<str_array.size; i++)
            cout << str_array.array[i] << '\n';
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
    void push_back(String_Array &str_array, string item){
    string *new_array = (string*) realloc(str_array.array, sizeof(string) * (str_array.size+1));
    if (new_array != NULL){
        str_array.array = new_array;
        str_array.array[str_array.size] = item;
        str_array.size++;
    }else{free(new_array);}
}
    char (*automatic_allocated_string()){}
