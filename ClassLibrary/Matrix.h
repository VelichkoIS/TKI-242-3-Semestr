#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

/**
* @brief шаблон одномерного массива
*/
template<class C1>
class Matrix
{
private:
	size_t size;
	shared_ptr<C1[]> firstPtr;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	Matrix() : size{ 0 }, firstPtr{ nullptr }
	{
	}
	/**
	* @brief конструктор копировани€
	* @param other другой объект класса Matrix
	*/
	Matrix(const Matrix& other) : size{ other.size }
	{
		firstPtr.reset(new C1[size]);
		for (size_t i = 0; i < size; i++)
		{
			firstPtr[i] = other.firstPtr[i];
		}
	}
	/**
	* @brief конструктор
	* @parak size размер массива
	*/
	Matrix(const size_t& size) : size{ size }
	{
		firstPtr.reset(new C1[size]);
	}
	/**
	* @brief констукор перемещени€
	* @param other другой объект класса Matrix
	*/
	Matrix(Matrix&& other) noexcept : size{ other.size }
	{
		other.size = 0;
		firstPtr = move(other.firstPtr);
		other.firstPtr = nullptr;
	}
	/**
	* @brief устанавливает значение пол€ size
	* @param size размер массива
	*/
	void setSize(const size_t size)
	{
		this->size = size;
	};
	/**
	* @brief устанавливает значение firstPtr
	* @param arr указатель на первый элемент массива
	*/
	void setFirstPtr(const shared_ptr<C1[]> firstPtr)
	{
		this->firstPtr = firstPtr;
	};
	/**
	* @brief возвращает значение пол€ size
	*/
	size_t getSize() const
	{
		return size;
	};
	/**
	* @brief возвращает значение пол€ firstPtr
	*/
	shared_ptr<C1[]> getFirstPtr()
	{
		return firstPtr;
	};
	/**
	* @brief сериализаци€ в строку
	*/
	string toString() const
	{
		stringstream ss;
		ss << "–азмер массива: " + to_string(size) + endl;
		for (size_t i = 0; i < size; i++)
		{
			ss << firstPtr[i] << endl;
		}
		return ss.str();
	};
	/**
	* @brief деструктор
	*/
	~Matrix() {};
	/**
	* @brief оператор присваивани€
	* @param other другой объект класса Matrix
	*/
	Matrix& operator=(const Matrix& other)
	{
		size = other.size;
		firstPtr.reset(new C1[size]);
		for (size_t i = 0; i < size; i++)
		{
			firstPtr[i] = other.firstPtr[i];
		}
		return *this;
	};
	/**
	* @brief оператор перемещени€
	* @param константна€ rvalue ссылка на объект класса Matrix
	*/
	Matrix& operator=(Matrix&& other)
	{
		size = other.size;
		other.size = 0;
		firstPtr = move(other.firstPtr);
		return *this;
	};
	/**
	* @brief оператор разыменовывани€ элемента коллекции по индексу
	* @param index индекс элемента
	*/
	C1& operator[](const size_t index) const
	{
		return firstPtr[index];
	};
	/**
	* @brief оператор вывода в ostream
	* @param os поток вывода
	* @param value данные дл€ вывода
	*/
	friend ostream& operator<<(ostream& os, const Matrix<C1>& value);
	/**
	* @brief оператор ввода в istream
	* @param is поток ввода
	* @param value вводимые данные
	*/
	friend istream& operator>>(istream& is, Matrix<C1>& matrix);
};

/**
* @brief оператор вывода в поток
* @param os поток вывода
* @param value значение
*/
template<class C1>
ostream& operator<<(ostream& os, const Matrix<C1>& value)
{
	os << value.toString();
	return os;
};

/**
* @brief оператор ввода
* @param is поток ввода
* @param matrix массив куда будут передоватьс€ данные
*/
template<class C1>
istream& operator>>(istream& is, Matrix<C1>& matrix)
{
	matrix.setSize(size_t(is));
	matrix.setFirstPtr(new C1[size]);
	for (size_t i = 0; i < matrix.getSize(); i++)
	{
		is >> matrix.firstPtr[i];
	}
	return is;
};