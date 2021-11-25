#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream file("in.txt");

    int x_n, y_n, x, y, left_x, left_y, right_x, right_y, count = 0;
    float vec_multi,  l_n, length, length_left = 0, length_right = 0;
    bool flag1 = false, flag2 = false;

    if(file.is_open()) {
        while (!file.eof()) {
            if(count != 0 && count != 1){
                if(count % 2 != 0) {
                    file >> y;
                    vec_multi = x_n * y - y_n * x;
                    length = vec_multi / l_n;
                    if (vec_multi <= 0) {
                        flag2 = true;
                        length = (-1) * length;
                        if (length_right <= length) {
                            length_right = length;
                            right_x = x;
                            right_y = y;
                        }
                    }else if (vec_multi > 0){
                        flag1 = true;
                        if (length_left <= length) {
                            length_left = length;
                            left_x = x;
                            left_y = y;
                        }
                    }
                }else{
                    file >> x;
                }
            }else if(count != 0){
                file >> y_n;
                l_n = sqrt(x_n * x_n + y_n * y_n);
            }else{
                file >> x_n;
            }
            count++;
        }
    }
    file.close();

    if(flag1 && flag2){
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
