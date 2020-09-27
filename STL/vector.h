#include<iostream>
using namespace std;

template <typename T>
class Vector	{
	int cs;
	int ms;
	T *arr;
	Vector()	{
		cs = 0;
		ms=1;
		arr = new T[ms];
	}
	void push_back(const int d)	{
		if(cs==ms)	{
			//Array is full
			T *oldarr = arr;
			arr = new T[2*ms];
			ms*=2
			for(int i=0;i<cs;i++)	{
				arr[i] = oldarr[i];
			}
			delete [] oldarr;
		}
		arr[cs] = d;
		cs++;
	}
	
	void pop_back()	{
		cs--;
	}
	T front()	const{
		return arr[0];
	}
	
	T back()	const{
		return arr[cs-1];
	}
	
	void empty()	const{
		return cs==0;
	}
	
	void capacity()	const{
		return ms;
	}
	
	int size()	{
		return cs;
	}
	
	T at(const int i)	{
		return arr[i];
	}
	
	//operator overloading
	T operator[](const int i)	{
		return arr[i];
	}
};
