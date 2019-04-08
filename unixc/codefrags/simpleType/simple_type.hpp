#ifndef _SIMPLE_TYPE_HPP_
#define _SIMPLE_TYPE_HPP_

#include<iostream>
using namespace std;

//函数模版
template<typename T>
void swapT(T & a,T & b){
	T temp;
	temp=a;
	a=b;
	b=temp;
}

//类模版
//template<typename T>

#endif
