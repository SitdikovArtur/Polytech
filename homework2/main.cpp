#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if(argc > 2){
        cout << "Too much arguments" << endl;
        exit(1);
    }else if(argc == 1){
        cout << "Not enough input arguments" << endl;
        exit(2);
    }

    ifstream file(argv[1]);
    double h0, v_x, v_y, x, h, y, i = 0;
    vector <pair <float, float> > arr;

    file >> h0 >> v_x >> v_y;

    if(v_x == 0 || v_y == 0){
        cout << 0;
        return 0;
    }

    if(file.is_open()){
        while(!file.eof()) {
            file >> x >> h;
            arr.emplace_back(x, h);
            i++;
        }
    }
    file.close();

    if(i == 0){
        cout << (2 * v_x * v_y) / 9.81;
        return 0;
    }

    i = i - 1;
    double t = (v_y + sqrt(v_y * v_y + 2 * 9.81 * h0)) / 9.81;
    double temp, time = 0, x_0 = 0;
    int result = 0;

    while(result >= 0){
        temp = (arr[result].first - x_0) / v_x;
        time = time + temp;
        x_0 = arr[result].first;
        if(time >= t){
            if(v_x > 0){
                cout << result - 1;
                return 0;
            }else{
                cout << result + 1;
                return 0;
            }
        }
        y = h0 + v_y * time - 9.81 * time * time / 2;
        if(y > arr[result].second){
            if(v_x > 0){
                result++;
            }else{
                result--;
            }
        }else{
            v_x = v_x * (-1);
            if(v_x > 0){
                result++;
            }else{
                result--;
            }
        }
    }

    cout << 0;

    return 0;
}
