/*
* Haris Sattar
* Vector.h
* 2/14/16
* This is the header file for Vector_test.cpp
*/

#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

template <class T>
class Vector
{
public:

	typedef T * iterator;

	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, const T& initial);
	Vector(const Vector<T>& v);           // copy constructor
	~Vector();

	unsigned int capacity() const;         // return capacity of vector (in elements)
	unsigned int size() const;             // return the number of elements in the vector
	bool empty() const;

	iterator begin();                      // return an iterator pointing to the first element
	iterator end();                        // return an iterator pointing to one past the last element
	T& front();                           // return a reference to the first element
	T& back();                            // return a reference to the last element
	void push_back(const T& value);       // add a new element
	void pop_back();                       // remove the last element

	void reserve(unsigned int capacity);   // adjust capacity
	void resize(unsigned int size);        // adjust size

	T& operator[](unsigned int index);    // return reference to numbered element
	Vector<T>& operator=(const Vector<T>&);
	bool operator==(const Vector<T>&);

private:
	unsigned int my_size;
	unsigned int my_capacity;
	T* buffer;
};

template <class T>
Vector<T>::Vector()
{
	buffer = 0;
	resize(0);
}

template <class T>
Vector<T>::Vector(unsigned int size)
{
	buffer = 0;
	resize(size);
}

template <class T>
Vector<T>::Vector(unsigned int size, const T& initial)
{
	my_size = size;
	my_capacity = my_size;
	buffer = new T[my_capacity];

	for (int i = 0; i < my_size; i++)
		buffer[i] = initial;
}

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	my_size = v.size();
	my_capacity = v.capacity();
	buffer = new T[my_capacity];

	for (int i = 0; i < my_size; i++)
		buffer[i] = v.buffer[i];
}

template <class T>
Vector<T>::~Vector()
{
	my_size = 0;
	my_capacity = 0;
	delete [] buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
        return buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
        return buffer + my_size;
}

template <class T>
unsigned int Vector<T>::capacity() const
{
	return my_capacity;
}

template <class T>
unsigned int Vector<T>::size() const
{
	return my_size;
}

template <class T>
bool Vector<T>::empty() const
{
	return my_size == 0;
}

template <class T>
void Vector<T>::reserve(unsigned int capacity)
{
	if (buffer == 0) {
		my_size = 0;
		my_capacity = 0;
	}

	if (capacity <= my_capacity)
		return;

	T* new_buffer = new T[capacity];

	for (int i = 0; i < my_size; i++)
		new_buffer[i] = buffer[i];

	my_capacity = capacity;
	delete [] buffer;
	buffer = new_buffer;
}

template <class T>
void Vector<T>::resize(unsigned int size)
{
	reserve(size);
	my_size = size;
}

template <class T>
void Vector<T>::pop_back()
{
	if (my_size == 0)
		return;

	my_size--;
}

template <class T>
void Vector<T>::push_back(const T& value)
{
	if (my_size >= my_capacity)
		reserve(my_capacity + 5);

	buffer[my_size] = value;
	my_size++;
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& right)
{
	if (size != right.size)
		return false;

	int i, j;
	for (i = 0, j = 0; i < size && j < right.size; i++, j++)
		if (buffer[i] != right.buffer[j])
			return false;

	return true;
}

template <class T>
T& Vector<T>::operator[](unsigned int index)
{
	return buffer[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& right)
{
	delete [] buffer;
	my_size = right.size();
	my_capacity = right.capacity();
	buffer = new T[my_capacity];

	for (int i = 0; i < my_size; i++)
		buffer[i] = right.buffer[i];
}

template <class T>
T& Vector<T>::front()
{
	return buffer[0];
}

template <class T>
T& Vector<T>::back()
{
	return buffer[my_size - 1];
}

#endif
