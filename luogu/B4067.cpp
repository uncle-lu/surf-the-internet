#include<iostream>
#include <string>
#include <cstring>
using namespace std;
char arr_0[6][6] = {
    ".....",
    ".***.",
    ".***.",
    ".***.",
    ".....",
};
char arr_1[6][6] = {
    "****.",
    "****.",
    "****.",
    "****.",
    "****.",
};
char arr_2[6][6] = {
    ".....",
    "****.",
    ".....",
    ".****",
    ".....",
};
char arr_3[6][6] = {
    ".....",
    "****.",
    ".....",
    "****.",
    ".....",
};
char str[1000010];

int main() {
    cin >> str;
    int len = strlen(str);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < len; j++) {
            if(str[j] == '0')
                cout << arr_0[i];
            else if(str[j] == '1')
                cout << arr_1[i];
            else if(str[j] == '2')
                cout << arr_2[i];
            else if(str[j] == '3')
                cout << arr_3[i];
        }
        cout << endl;
    }
    return 0;
}