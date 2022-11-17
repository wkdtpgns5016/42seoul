#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T arr[], int size, void (*f)(const T& t));

template <typename T>
void print(const T& t);

#endif