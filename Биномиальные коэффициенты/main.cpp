#include <iostream>

using namespace std;

double fact(int number){
    if(number == 0){
        return 1;
    }else if(number == 1){
        return 1;
    }else{
        return number * fact(number - 1);
    }
}

int* bin(int num){
    int *array = new int[num];
    for(int i = 0; i < num + 1; i++){
        array[i] = fact(num) / (fact(i) * fact(num - i));
    }
    return array;
}

int main() {
    int a = 10;
    int* cof = bin(a);
    for(int i = 0; i < a + 1; i++){
        cout << cof[i] << " ";
    }
    return 0;
}
