/*Implement basic string operations such as length calculation, copy, reverse, and concatenation using character single
 dimensional arrays without using built-in string library functions.*/

#include <iostream>
#include <string>
using namespace std;


int strlength(char str[], int &length){
    int n = 0;
    while(str[n] != '\0'){
        n++;
    }
    length = n;
    return length;
}

void strcopy(char source[], char destination[]){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
}

void strreverse(char str[]){
    int length = 0;
    strlength(str, length);
    int st = 0;
    int end = length - 1;
    while(st < end){
        char temp = str[st];
        str[st] = str[end];
        str[end] = temp;
        st++;
        end--;
    }
}

void strconcat(char str1[], char str2[]){
    int i = 0;
    while(str1[i] != '\0'){
        i++;
    }

    int j = 0;
    while(str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}


int main(){
    int length = 0;
    char str1[100], str2[50], destination[100];
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 50);

    int option = 0;
    while(true){
        cout << "\nChoose an operation:\n1. Length Calculation\n2. Copy String\n3. Reverse String\n4. Concatenate Strings\n5. Exit\n";
        cin >> option;
        cin.ignore(); // to ignore the newline character after integer input

        switch(option){
            case 1:
                strlength(str1, length);
                cout << "Length of first string: " << length << endl;
                break;
            case 2:
                strcopy(str1, destination);
                destination[length] = '\0'; // Null terminate the copied string
                cout << "Copied string: " << destination << endl;
                break;
            case 3:
                strreverse(str1);
                cout << "Reversed first string: " << str1 << endl;
                break;
            case 4:
                strconcat(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}