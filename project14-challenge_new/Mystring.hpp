#ifndef Mystring_hpp
#define Mystring_hpp

#include <stdio.h>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);            // Move assignment
    
    void display() const;
    
    int get_length() const;                                                // getters
    const char *get_str() const;
   
    // Overloaded Operators
    bool operator==(const Mystring &rhs) const; // Equal
    bool operator!=(const Mystring &rhs) const ; // Not equal
    bool operator<(const Mystring &rhs) const; // Less than
    bool operator>(const Mystring &rhs) const; // Greater than
    Mystring operator-() const; // Change to lowercase
    Mystring &operator++(); // Change to uppercase - pre increment
    Mystring operator++(int); // Change to uppercase - post increment
    Mystring operator+(const Mystring &rhs) const;  // Plus - concatination
    Mystring &operator+=(const Mystring &rhs); // Overloaded +=
    Mystring operator*(const int &rhs) const; // Overloaded str *
    Mystring &operator*=(const int &rhs); // Overloaded *=
};


#endif /* Mystring_hpp */
