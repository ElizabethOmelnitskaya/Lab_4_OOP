#pragma once
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
class Fibonacci
{
private:
	int FirstNumber = 0, SecondNumber = 1, const_Size = 20;
	char FirstString = 'a', SecondString = 'b';

	T first, second;
	int Size;

public:
	class const_iterator : public iterator<bidirectional_iterator_tag, T> {
	private:
		int pos;
		T cur, next;
	public:
		const_iterator(){
			pos = 0;
			cur = first;
			next = second;
		}

		const_iterator(const T& cur, const T& next, int pos){
			this->cur = cur;
			this->next = next;
			this->pos = pos;
		}

		const_iterator(const const_iterator& other) {
			pos = other.pos;
			cur = other.cur;
			next = other.next;
		}

		const_iterator& operator=(const const_iterator& other) {
			cur = other.cur;
			pos = other.pos;
			next = other.next;
			return *this;
		}

		bool operator<(const const_iterator& other) const {
			return pos < other.pos;
		}

		bool operator>(const const_iterator& other) const {
			return pos > other.pos;
		}

		bool operator<=(const const_iterator& other) const {
			return *this < other || *this == other;
		}

		bool operator>=(const const_iterator& other) const {
			return *this > other || *this == other;
		}

		bool operator==(const const_iterator& other) const {
			return cur == other.cur && next == other.next && pos == other.pos;
		}

		bool operator!=(const const_iterator& other) const {
			return cur != other.cur || next != other.next || pos != other.pos;
		}

		T& operator*(){ return cur; }

		const_iterator& operator++() {
			T tmp = cur;
			cur = next;
			next += tmp;
			++pos;
			return *this;
		}

		const_iterator operator++(int) {
			T tmp = cur;
			cur = next;
			next += tmp;
			pos++;
			return *this;
		}

		const_iterator& operator--() {
			T tmp = next;
			next = cur;
			cur = tmp - cur;
			--pos;
			return *this;
		}

		const_iterator operator--(int) {
			T tmp = next;
			next = cur;
			cur = tmp - cur;
			pos--;
			return *this;
		}

		const_iterator& operator+(int num) const {
			const_iterator result(*this);
			if (num > 0)
				for (int i = 0; i < num; i++)
					result++;
			else
				for (int i = 0; i > num; i--)
					result--;
			return result;
		}

		const_iterator& operator-(int num) const {
			const_iterator result(*this);
			if (num > 0)
				for (int i = 0; i < num; i++)
					result--;
			else
				for (int i = 0; i > num; i--)
					result++;
			return result;
		}

		int operator-(const const_iterator& other) const {
			return pos - other.pos;
		}

		const_iterator& operator+=(int num) {
			if (num > 0)
				for (int i = 0; i < num; i++)
					(*this)++;
			else
				for (int i = 0; i > num; i--)
					(*this)--;
			return *this;
		}

		const_iterator& operator-=(int num) {
			if (num > 0)
				for (int i = 0; i < num; i++)
					(*this)--;
			else
				for (int i = 0; i > num; i--)
					(*this)++;
			return *this;
		}

		T& operator[](int num) const { return *(*this + num); }

		void sort(const_iterator &other) {
			T tmp = cur;
			cur = other.cur;
			other.cur = tmp;
			tmp = next;
			next = other.next;
			other.next = tmp;
			tmp = pos;
			pos = other.pos;
			other.pos = tmp;
		}
	};

	Fibonacci();
	Fibonacci(int);
	Fibonacci(int, const T&, const T&); //конструктор, задающий размер контейнера и первые два значения 

	const_iterator cbegin() const { //возвращающий константные stl-итераторы 
		return const_iterator(first, second, 0); 
	} 

	const_iterator cend() const { //возвращающий константные stl-итераторы 
		const_iterator result(first, second, 0);
		result += size() - 1;
		return result;
	}

	T& at(int index) const{ // возвращающий index - ое значение
		if (index >= size() || index < 0)
			throw "Index out of range!";
		const_iterator it = cbegin();
		it += index;
		return *it;
	}

	void resize(int); //изменение размера контейнера
	int size() const; //возвращает размер контейнера

	~Fibonacci();
};

template <>//для int, long, float, double - задает 0 и 1 
Fibonacci<int>::Fibonacci(){
	Size = const_Size;
	first = FirstNumber;
	second = SecondNumber;
}

template<>
Fibonacci<long int>::Fibonacci() {
	Size = const_Size;
	first = FirstNumber;
	second = SecondNumber;
}

template<>
Fibonacci<float>::Fibonacci() {
	Size = const_Size;
	first = FirstNumber;
	second = SecondNumber;
}

template<>
Fibonacci<double>::Fibonacci() {
	Size = const_Size;
	first = FirstNumber;
	second = SecondNumber;
}

template<>
Fibonacci<int>::Fibonacci(int Size) {
	this->Size = Size;
	first = FirstNumber;
	second = SecondNumber;
}

template<>
Fibonacci<long int>::Fibonacci(int Size) {
	this->Size = Size;
	first = FirstNumber;
	second = SecondNumber;
}

template<>
Fibonacci<float>::Fibonacci(int Size) {
	this->Size = Size;
	first = FirstNumber;
	second = SecondNumber;
}

template<>
Fibonacci<double>::Fibonacci(int Size) {
	this->Size = Size;
	first = FirstNumber;
	second = SecondNumber;
}


template<> //для string - задает "a" и "b"
Fibonacci<std::string>::Fibonacci() {
	Size = const_Size;
	first.append(&FirstString);
	second.append(&SecondString);
}

template<>
Fibonacci<std::string>::Fibonacci(int Size) {
	this->Size = Size;
	first.append(&FirstString);
	second.append(&SecondString);;
}

template <typename T>
Fibonacci<T>::Fibonacci(int Size, const T& first, const T& second){
	this->Size = Size;
	this->first = first;
	this->second = second;
}

template <typename T>
void Fibonacci<T>::resize(int Size) { this->Size = Size; }

template <typename T>
int Fibonacci<T>::size() const { return Size; } //{ return this->size_var; }

template <typename T>
Fibonacci<T>::~Fibonacci() {}