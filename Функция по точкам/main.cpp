#include <iostream>
#include <cmath>

using namespace std;

double st(float num, int s){
    int i = 0;
    float res = 1;
    while(i < s){
        res = num * res;
        i = i + 1;
    }
    return res;
}

double f(double x){
    return cos(x) / sqrt(5 - st(x, 3));
}

int main() {
    int a = -5;
    int b = 0;
    float step = 0.1;
    int elements = (b - a) / step;
    float y[elements];
    for(int i = 0; i <= elements; i++){
        y[i] = f(a);
        a = a + step;
    }
    for(int i = 0; i <= elements; i++){
        cout << y[i] << " ";
    }
    return 0;
}
