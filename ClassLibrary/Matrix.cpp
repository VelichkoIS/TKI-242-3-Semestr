#include "Matrix.h"
#include <sstream>

template<class C1>
Matrix<C1>::Matrix() : size{0}, firstPtr{nullptr}
{
}

template<class C1>
Matrix<C1>::Matrix(const Matrix& other) : size{other.size}
{
	firstPtr.reset(new C1[size]);
	for (size_t i = 0; i < size; i++)
	{
		firstPtr[i] = other.firstPtr[i];
	}
}

template<class C1>
Matrix<C1>::Matrix(const size_t& size) : size{size}
{
	firstPtr.reset(new C1[size]);
}

template<class C1>
Matrix<C1>::Matrix(Matrix&& other) noexcept : size{other.size}
{
	other.size = 0;
	firstPtr = move(other.arr);
}

template<class C1>
Matrix<C1>::~Matrix()
{
}

template<class C1>
void Matrix<C1>::setSize(const size_t size)
{
	this.size = size;
}

template<class C1>
void Matrix<C1>::setFirstPtr(const shared_ptr<C1[]> arr)
{
	this.arr = arr;
	size = arr.use_count();
}

template<class C1>
size_t Matrix<C1>::getSize() const
{
	return size;
}

template<class C1>
shared_ptr<C1[]> Matrix<C1>::getFirstPtr()
{
	return firstPtr;
}

template<class C1>
string Matrix<C1>::toString() const
{
	stringstream ss;
	ss << "Размер массива: " + to_string(size) + endl;
	for (size_t i = 0; i < size; i++)
	{
		ss << firstPtr[i] << endl;
	}
	return ss.str();
}

template<class C1>
Matrix<C1>& Matrix<C1>::operator=(const Matrix& other)
{
	size = other.size;
	firstPtr.reset(new C1[size]);
	for (size_t i = 0; i < size; i++)
	{
		firstPtr[i] = other.arr[i];
	}
	return *this;
}

template<class C1>
Matrix<C1>& Matrix<C1>::operator=(Matrix&& other)
{
	size = other.size;
	other.size = 0;
	firstPtr = move(other.arr);
	return *this;
}

template<class C1>
C1& Matrix<C1>::operator[](const size_t index) const
{
	return firstPtr[index];
}

template<class C1>
ostream& operator<<(ostream& os, const Matrix<C1>& value)
{
	os << value.toString();
	return os;
}

template<class C1>
istream& operator>>(istream& is, Matrix<C1>& matrix)
{
	matrix.setSize(size_t(is));
	matrix.setFirstPtr(new C1[size]);
	for (size_t i = 0; i < matrix.getSize(); i++)
	{
		is >> matrix.arr[i];
	}
	return is;
}