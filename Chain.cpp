/**
 @file: Chain.cpp
 @auhtor: Mir Ahmed.
 @Details: This file implements the member function of the generic class Chain.
 @Date: 02/10/2016.
*/
#include"Chain.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

template<typename Object>
Chain<Object>::Chain() : size_{0}, array_{nullptr}
{
    //nothing here.
}

template<typename Object>
Chain<Object>::Chain(Object&& item): size_{1}
{
    array_ = new Object[size_];
    array_[0] = item;
}

template<typename Object>
Chain<Object>:: Chain(const Chain<Object> &rhs) //copy constructor
{
    size_ = rhs.size_;
    array_= new Object[size_];
    for(int i=0; i< size_; i++)
        array_[i] = rhs.array_[i];
}

template<typename Object>
Chain<Object>::Chain(Chain<Object> &&rhs) //move constructor
{
    size_ = rhs.size_;
    array_ = rhs.array_;

    rhs.array_= nullptr;
    rhs.size_= 0;
}

template<typename Object>
Chain<Object>& Chain<Object>::operator=(const Chain<Object> &rhs) //copy assignment operator
{
    delete []array_;
    array_ = nullptr;
    size_ = 0;

    size_ = rhs.size_;
    array_= new Object[size_];
    for(int i=0; i< size_; i++)
        array_[i] = rhs.array_[i];

    return *this;
}

template<typename Object>
Chain<Object>& Chain<Object>::operator=(Chain<Object> &&rhs) // move assignment operator
{
    std::swap(size_, rhs.size_);
    std::swap(array_, rhs.array_);
    return *this;
}

template<typename Object>
Object& Chain<Object>::operator[](int index)
{
    if(index >= size_)
        throw runtime_error("Out Of Range Exception!!!"); // aborting
    else
        return array_[index];
}

template<typename Object>
Chain<Object> Chain<Object>::operator+(const Chain<Object>& rhs)
{
    Chain<Object> newChain;
    int sizeCombined = size_ + rhs.size_;
    newChain.array_ = new Object[sizeCombined];
    newChain.size_ = sizeCombined;

    // copying the first array
    for(int i=0; i<size_; i++)
        newChain.array_[i] = array_[i];
    //copying the second array
    for(int i=size_, k=0; i<sizeCombined && k<rhs.size_; i++,k++)
        newChain.array_[i] = rhs.array_[k];
    return newChain;
}

template<typename Object>
Chain<Object>& Chain<Object>::operator+(Object&& item)
{
    int sizeAccomodate = size_+1;
    Chain<Object> copyChain;
    copyChain = std::move(*this);
    array_ = new Object[sizeAccomodate];
    size_ = sizeAccomodate;

    for(int i=0; i<copyChain.size_; i++)
        array_[i] = copyChain.array_[i];

    array_[sizeAccomodate-1] = item;

    return *this;
}

template<typename T>
ostream& operator<<(ostream& output, const Chain<T>& myChain)
{
    if(myChain.array_ == nullptr && myChain.size_ == 0)
        output  << "[]" << endl;
    else
    {
        output<<"[";
        for(int i=0; i< myChain.size_-1; i++)
        {
            output << myChain.array_[i] << " ";
        }
            output << myChain.array_[myChain.size_ -1] << "]" <<endl;
    }
    return output;
}

template<typename Object>
void Chain<Object>::ReadChain()
{
    stringstream ss;
    Object item;
    string inputChain;
    getline(cin, inputChain);

    inputChain= inputChain.substr(1, inputChain.length()-2); //getting rid of the braces from the user input.
    int countSize= 0;
    for(int i=0; i<inputChain.length(); i++)
    {
        if(isspace(inputChain[i]))
            countSize++;
    }
    countSize++; // we need to add one because total elements is number of spaces plus 1.
    array_ = new Object[countSize];
    ss<<inputChain;
    for(int j = 0; j < countSize; j++)
    {
        ss>>item;
        array_[j] = item;
        size_++;
    }
}
template<typename Object>
size_t Chain<Object>::Size()
{
    return size_;
}

template<typename Object>
Chain<Object>::~Chain()
{
    delete []array_;
    array_ = nullptr;
    size_ = 0;
}










