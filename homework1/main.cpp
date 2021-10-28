#include <iostream>
#include <fstream>
#include <string>
#include <strstream>

using namespace std;

int main() {
    ifstream file("C:\\Users\\Artur\\CLionProjects\\task1\\in.txt");
    string line;
    int k = 0;

    if(file.is_open()){
        while(getline(file, line)){
            k++;
        }

        int* arr = new int[k];

        int j = 0;
        while(getline(file, line)){
            char tmp[line.size()];
            strstream x;
            x << line;
            while(x >> tmp){
                arr[j] = stoi(tmp);
                j = j + 1;
            }
        }

        int n = sizeof(*arr) / sizeof(arr[0]);
        int* arr_x = new int[k / 2];
        int* arr_y = new int[k / 2];

        int x = 0;
        int y = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                arr_x[x] = arr[i];
                x = x + 1;
            }else{
                arr_y[y] = arr[i];
                y = y + 1;
            }
        }



    }
    file.close();

    return 0;
}
