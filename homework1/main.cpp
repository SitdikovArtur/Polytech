#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main() {
    ifstream file("in.txt");

    string line;
    int x_n, y_n, x, y, left_x, left_y, right_x, right_y, count = 0;
    float vec_multi,  l_n, tmp_length, length_left = 0, length_right = 0;
    bool flag1, flag2;

    if(file.is_open()) {
        while (!file.eof()) {
            switch (count) {
                case 0:
                    file >> x_n;
                    break;
                case 1:
                    file >> y_n;
                    l_n = float(sqrt(x_n * x_n + y_n * y_n));
                    break;
                default:
                    if (count % 2 == 0) {
                        file >> x;
                    } else {
                        file >> y;
                        vec_multi = x_n * y - y_n * x;
                        if (vec_multi > 0) {
                            flag1 = true;
                            tmp_length = float(vec_multi) / l_n;
                            if (length_left < tmp_length) {
                                length_left = tmp_length;
                                left_x = x;
                                left_y = y;
                            }
                        } else {
                            flag2 = true;
                            tmp_length = (-1) * float(vec_multi) / l_n;
                            if (length_right < tmp_length) {
                                length_right = tmp_length;
                                right_x = x;
                                right_y = y;
                            }
                        }
                    }
            }
            count++;
        }
    }
    file.close();

    if(flag1 && flag1){
        cout << "Leftmost: " << left_x << " " << left_y << endl;
        cout << "Rightmost: " << right_x << " " << right_y << endl;
    }else if(flag1 || flag2){
        if(flag1){
            cout << "Leftmost: " << left_x << " " << left_y << endl;
            cout << "Rightmost: " << 0 << " " << 0 << endl;
        }else{
            cout << "Leftmost: " << 0 << " " << 0 << endl;
            cout << "Rightmost: " << right_x << " " << right_y << endl;
        }
    }else{
        cout << "Leftmost: " << 0 << " " << 0 << endl;
        cout << "Rightmost: " << 0 << " " << 0 << endl;
    }
    return 0;
}
