/*
Jared Williams
Chapter 16 part 1
*/

#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character exception: start is not a letter (A-Z, a-z)";
    }
};

class InvalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range exception: target is not a letter";
    }
};

char character(char start, int offset);

int main() {
    try {
        cout << "character('a', 1): " << character('a', 1) << endl;         //b
        cout << "character('a', -1): ";
        character('a', -1);                                                 //throws an invalidRangeException
        cout << "character('Z', -1): " << character('Z', -1) << endl;       //Y
        cout << "character('?', 5): ";
        character('?', 5);                                                  //throws an invalidCharacterException
        cout << "character('A', 32): ";
        character('A', 32);                                                 //throws an invalidRangeException
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw InvalidCharacterException();
    }

    char result = start + offset;

    if (!isalpha(result)) {
        throw InvalidRangeException();
    }

    if (islower(start) && isupper(result)) {
        throw InvalidRangeException();                                      //can't do a upper-case to lower-case transition
    }

    return result;
}