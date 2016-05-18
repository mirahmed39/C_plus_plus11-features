/**
 @file: Chain.h
 @auhtor: Mir Ahmed.
 @Details: This header file represents a generic class called Chain.
 As the name suggests, the chain class hold series of data and do some
 basic manipulations on it such as getting the size and reading a chain
 from the user input assuming that the user knows exactly how to input a
 Chain. Finally, the class also features the Big Five in C++11 and
 implements them in the implementation file.
 @Date: 02/10/2016.
*/
#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_
#include <iostream>
#include <cstddef>
using namespace std;

// Place comme nts that provide a brief explanation of the class.
template<typename Object>
class Chain {
 public:
    /**
    Default Constructor
    */
    Chain();

    /**
    Parameterized Constructor.
    This will be invoked for brace initialization for Chain object.
    @param: Item- an rvalue that will be inserted to the chain.
    */
    Chain(Object&& item);

    /**
    Copy Constructor
    */
    Chain(const Chain &rhs);

    /**
    Copy Assignment Operator.
    */
    Chain& operator=(const Chain &rhs);

    /**
    Move Constructor.
    */
    Chain(Chain &&rhs);

    /**
    Move Assignment Operator.
    */
    Chain& operator=(Chain &&rhs);

    Object& operator[](int index);

    Chain operator+(const Chain<Object>& rhs);

    Chain& operator+(Object&& item);

    /**
    @return the current size of the chain.
    */
    size_t Size();

    /**
    this function takes in input from the user.The input is a chain.
    @pre - the user knows the exact pattern of input.
    */
    void ReadChain();

    /**
    Overload of the stream output operator with a friend function.
    */
    template<typename T>
    friend ostream& operator<<(ostream& output, const Chain<T>& myChain);

    /**
    Destructor that is to be implemented.
    */
    ~Chain();
  // Here you have to add more methods.

 private:
    size_t size_;
    Object *array_;
};

#include "Chain.cpp"
#endif // CSCI_335_HOMEWORK1_CHAIN_

