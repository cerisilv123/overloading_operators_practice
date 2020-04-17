
#include <iostream>
#include <cstring>
#include "Mystring.hpp"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source)
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}


// Overloaded Equality operator
bool Mystring::operator==(const Mystring &rhs) const {
    return (strcmp(str, rhs.str) == 0);
}

// Overloaded Not Equal operator
bool Mystring::operator!=(const Mystring &rhs) const {
    return (strcmp(str, rhs.str) != 0);
}

// Overloaded less than operator
bool Mystring::operator<(const Mystring &rhs) const {
    return (strcmp(str, rhs.str) < 0);
}

// Overloaded greater than operator
bool Mystring::operator>(const Mystring &rhs) const {
    return (strcmp(str, rhs.str) > 0);
}

// Overloaded change to lowercase operator
Mystring Mystring::operator-() const {
    char * buff = new char[strlen(this->str) + 1]; // n2 = -n1 // n1.operator-() const; 
    strcpy(buff, this->str);
    for (size_t i = 0; i < strlen(buff); i++) {
        buff[i] = tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff; 
    return temp;
}

// Concatination operator overloader
Mystring Mystring::operator+(const Mystring &rhs) const {
    size_t buff_size = strlen(str) + strlen(rhs.str) + 1;
    char *buff = new char [buff_size];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Overloaded +=
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs.str;
    return *this;
}

// Overloaded str *
Mystring Mystring::operator*(const int &rhs) const {
    char *buff = new char [strlen(str) * rhs + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < rhs - 1; i++) {
        strcat(buff, str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Overloaded *=
Mystring &Mystring::operator*=(const int &rhs) {
    *this = *this * rhs;
    return *this; 
}

// Change to uppercase - pre increment
Mystring &Mystring::operator++() {
    for (size_t i = 0; i < strlen(this->str); i++ ) {
        this->str[i] = toupper(this->str[i]);
    }
    return *this;
}

// Change to uppercase - post increment
Mystring Mystring::operator++(int) {
    Mystring temp {*this};
    operator++(); // Call pre increment!
    return temp;
}

