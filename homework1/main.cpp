#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


using namespace std;

int main() {
    ifstream file("in.txt");

    string line;
    vector <int> arr;

    if(file.is_open()){
        while(!file.eof()){
            int tmp;
            file >> tmp;
            arr.push_back(tmp);
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
    bool flag[2];

    for(int k = 3; k < arr.size(); k = k + 2){;
        int vec_multi = x_n * arr[k] - y_n * arr[k - 1];
        if(vec_multi > 0){
            flag[0] = true;
            float tmp_length;
            tmp_length = float(vec_multi) / l_n;
            if(length_left < tmp_length){
                length_left = tmp_length;
                left[0] = arr[k - 1];
                left[1] = arr[k];
            }
        }else{
            flag[1] = true;
            float tmp_length;
            tmp_length = (-1) * float(vec_multi) / l_n;
            if(length_right < tmp_length){
                length_right = tmp_length;
                right[0] = arr[k - 1];
                right[1] = arr[k];
            }
        }
    }

    if(flag[0] && flag[1]){
        cout << "Leftmost: " << left[0] << " " << left[1] << endl;
        cout << "Rightmost: " << right[0] << " " << right[1] << endl;
    }else if(flag[0] || flag[1]){
        if(flag[0]){
            cout << "Leftmost: " << left[0] << " " << left[1] << endl;
            cout << "Rightmost: " << 0 << " " << 0 << endl;
        }else{
            cout << "Leftmost: " << 0 << " " << 0 << endl;
            cout << "Rightmost: " << right[0] << " " << right[1] << endl;
        }
    }else{
        cout << "Leftmost: " << 0 << " " << 0 << endl;
        cout << "Rightmost: " << 0 << " " << 0 << endl;
    }

    return 0;
}
