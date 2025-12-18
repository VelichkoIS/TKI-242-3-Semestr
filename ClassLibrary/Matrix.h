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
	* @brief конструктор копирования
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
	* @brief констукор перемещения
	* @param other другой объект класса Matrix
	*/
	Matrix(Matrix&& other) noexcept : size{ other.size }
	{
		other.size = 0;
		firstPtr = move(other.firstPtr);
		other.firstPtr = nullptr;
	}
	/**
	* @brief устанавливает значение поля size
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
	* @brief возвращает значение поля size
	*/
	size_t getSize() const
	{
		return size;
	};
	/**
	* @brief возвращает значение поля firstPtr
	*/
	shared_ptr<C1[]> getFirstPtr()
	{
		return firstPtr;
	};
	/**
	* @brief сериализация в строку
	*/
	string toString() const
	{
		stringstream ss;
		ss << "Размер массива: " + to_string(size) + endl;
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
	* @brief оператор присваивания
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
	* @brief оператор перемещения
	* @param константная rvalue ссылка на объект класса Matrix
	*/
	Matrix& operator=(Matrix&& other)
	{
		size = other.size;
		other.size = 0;
		firstPtr = move(other.firstPtr);
		return *this;
	};
	/**
	* @brief оператор разыменовывания элемента коллекции по индексу
	* @param index индекс элемента
	*/
	C1& operator[](const size_t index) const
	{
		return firstPtr[index];
	};
	/**
	* @brief оператор вывода в ostream
	* @param os поток вывода
	* @param value данные для вывода
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
* @param matrix массив куда будут передоваться данные
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