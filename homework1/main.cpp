#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int add_memory(int* array){
    int array_size = sizeof array;
    int* new_array = new int[2 * array_size];
    memcpy(new_array, array, array_size);
    return *new_array;
}

int main() {
    ifstream file("in.txt");

    string line;

    int* arr = new int[100];
    int i = 0;

    if(file.is_open()){
        while(!file.eof()){
            int tmp;
            file >> tmp;
            arr[i] = tmp;
            i = i + 1;
            if(i != 0 && i % 10 == 0){
                *arr = add_memory(arr);
            }
        }
    }
    file.close();

    int x_n = arr[0];
    int y_n = arr[1];
    float l_n = float(sqrt(x_n * x_n + y_n * y_n));
    int left[2];
    int right[2];
    float length_left = 0;
    float length_right = 0;

    for(int k = 3; k < i; k = k + 2){;
        int vec_multi = x_n * arr[k] - y_n * arr[k - 1];
        if(vec_multi > 0){
            float tmp_length;
            tmp_length = float(vec_multi) / l_n;
            if(length_left < tmp_length){
                length_left = tmp_length;
                left[0] = arr[k - 1];
                left[1] = arr[k];
            }
        }else{
            float tmp_length;
            tmp_length = (-1) * float(vec_multi) / l_n;
            if(length_right < tmp_length){
                length_right = tmp_length;
                right[0] = arr[k - 1];
                right[1] = arr[k];
            }
        }
    }

    delete[] arr;

    cout << "Leftmost: " << left[0] << " " << left[1] << endl;
    cout << "Rightmost: " << right[0] << " " << right[1];
    return 0;
}
