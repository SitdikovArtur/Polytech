#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <typeinfo>

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
    int h0, v_x, v_y, x, h, i = 0, k = 0;
    vector <pair <int, int> > arr;

    file >> h0 >> v_x >> v_y;

    if(file.is_open()){
        while(!file.eof()) {
            file >> x >> h;
            arr.emplace_back(x, h);
            i++;
        }
    }
    file.close();

    i = i - 1;

    if(v_x == 0 || v_y == 0){
        cout << 0;
        return 0;
    }

    double y, x_0 = 0, res_x = 0;;
    bool flag = false;
    while(k <= i && k >= 0){
        y = trajectory(x_0, arr[k].first, v_x, v_y, h0);
        if(y > 0 && y <= arr[k].second){
            v_x = (-1) * v_x;
            x_0 = arr[k].first - x_0;
            if(v_x > 0){
                k = k + 1;
            }else {
                k = k - 1;
            }
            flag = true;
        }else if(y > 0 && y > arr[k].second){
            if(v_x > 0){
                k = k + 1;
            }else {
                k = k - 1;
            }
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

    if(k == i) {
        double *result = end(x_0, v_y, v_x, h0);
        if(v_x < 0){
            res_x = result[0];
        }else{
            res_x = result[1];
        }
    }else if(k < 0){
        double *result = end(x_0, v_y, v_x, h0);
        if(v_x > 0){
            res_x = result[0];
        }else{
            res_x = result[1];
        }
    }

    if(res_x > arr[i].first){
        cout << i;
    }else{
        for(int j = 0; j <= i; j++){
            if(res_x < arr[j].first){
                cout << j;
                break;
            }
        }
    }

    return 0;
}
