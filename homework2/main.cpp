#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double trajectory(double x_0, double x_h, int v_x, int v_y, int y_0){
    return y_0 + (x_h - 2 * x_0) * v_y / v_x - 9.81 / (2 * pow(v_x, 2)) * pow((x_h - 2 * x_0), 2);
}

double *end(double x_0, int v_y, int v_x, int y_0){
    double left = 2 * x_0 + (v_y - sqrt(pow(v_y, 2) + 2 * 9.81 * y_0)) / (9.81 / v_x);
    double right = 2 * x_0 + (v_y + sqrt(pow(v_y, 2) + 2 * 9.81 * y_0)) / (9.81 / v_x);
    auto *result = new double[2];
    result[0] = left;
    result[1] = right;
    return result;
}

int main(int argc, char* argv[]) {
    if(argc > 2){
        cout << "Too much arguments" << endl;
        exit(1);
    }else if(argc == 1){
        cout << "Not enough input arguments" << endl;
        exit(2);
    }

    ifstream file(argv[1]);
    int h0, v_x, v_y, i = 0;
    int* arr = new int[100];

    if(file.is_open()){
        while(!file.eof()) {
            int tmp;
            file >> tmp;
            arr[i] = tmp;
            i = i + 1;
        }
    }
    file.close();

    h0 = arr[0];
    v_x = arr[1];
    v_y = arr[2];
    int arr_x[(i - 4) / 2];
    int arr_h[(i - 4) / 2];

    int k = 0;
    int n = 0;
    for(int j = 3; j < (i - 1); j = j + 2){
        arr_x[k] = arr[j];
        k = k + 1;
    }
    for(int j = 4; j < (i - 1); j = j + 2){
        arr_h[n] = arr[j];
        n = n + 1;
    }

//    for(int j = 0; j < i - 1; j++){
//        cout << arr[j] << " ";
//    }

//    for(int j = 0; j < (i - 4) / 2; j++){
//        cout << arr_x[j] << " " << arr_h[j] << endl;
//    }

    double x_0 = 0;
    double y;

    double res_x = 0;
    k = 0;
    bool flag = false;
    while(k < ((i - 4) / 2)){
        y = trajectory(x_0, arr_x[k], v_x, v_y, h0);
        cout << y << endl;
        if(y > 0 && y < arr_h[k]){
            v_x = (-1) * v_x;
            x_0 = arr_x[k] - x_0;
            if(v_x > 0){
                k = k + 1;
            }else {
                k = k - 1;
            }
            flag = true;
        }else if(y > 0 && y > arr_h[k]){
            k = k + 1;
            flag = false;
            continue;
        }else{
            double* result = end(x_0, v_y, v_x, h0);
            if(flag) {
                if (v_x > 0) {
                    res_x = result[0];
                } else {
                    res_x = result[1];
                }
            }else{
                if(v_x < 0){
                    res_x = result[0];
                }else{
                    res_x = result[1];
                }
            }
            break;
        }
    }

    if(k == ((i - 4) / 2)) {
        double *result = end(x_0, v_y, v_x, h0);
        if(v_x < 0){
            res_x = result[0];
        }else{
            res_x = result[1];
        }
    }

    cout << res_x << endl;

    if(res_x > arr_x[(i - 4) / 2 - 1]){
        cout << (i - 4) / 2 - 1;
    }else{
        for(int j = 0; j < (i - 4) / 2; j++){
            if(res_x < arr_x[j]){
                cout << j;
            }
        }
    }

    delete[] arr;
    return 0;
}
