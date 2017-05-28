/* Последовательность чисел Фибоначчи: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987... */
#pragma once
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T> class const_iterator;

template <typename T> class Fibonacci {
private:
	T first, second;
	int Size;
public:
	friend class const_iterator<T>;
	
	Fibonacci(int size) {
		this->Size = size;
		this->first = 0;
		this->second = 1;
	};

	Fibonacci(int size, T First, T Second) {
		this->first = First;
		this->second = Second;
		this->Size = size;
	};

	const_iterator<T> cbegin() const { return const_iterator<T>(*this); };

	const_iterator<T> cend() const { return const_iterator<T>(*this, this->Size); };

	static void next(T& a, T& b) {
		T n = a + b;
		a = b;
		b = n;
	};

	static void previous(T& a, T& b) {
		T p = b - a;
		b = a;
		a = p;
	};

	static T calculate(T&a, T&b, int step) {
		while (step-- > 0) next(a, b);
		while (step++ > -1) previous(a, b);
		return b;
	};

	T at(int index) const {
		switch (index) {
		case 0: 
			return a;
		case 1: 
			return b;
		default: {
			T a = this->first;
			T b = this->second;
			return calculate(first, second, index);
		}
		}
	};

	void realize(int size) { this->Size = size; };

	int size() { return this->Size; };
};


template <typename T>
class const_iterator : public iterator<bidirectional_iterator_tag, T> {
	Fibonacci<T> const& fib;
	T a, b;
	int calc, _index;
public:
	const_iterator(Fibonacci<T> const& F) :fib(F) {
		a = fib.first;
		b = fib.second;
		_index = 0;
		calc = 1;
	}

	const_iterator(Fibonacci<T> const& F, int index) :fib(F) {
		a = fib.first;
		b = fib.second;
		_index = index;
		calc = 1;
	}

	const_iterator& operator++() {
		this->_index++;
		return *this;
	}

	const_iterator operator++(int) { this->_index--; }

	const_iterator& operator--() {
		this->_index--;
		return *this;

	}

	const_iterator operator--(int) {
		this->_index--;
		return *this;
	}

	const_iterator& operator-=(int index) {
		this->it_index -= index;
		return *this;
	}

	const_iterator& operator+=(int index) {
		this->it_index += index;
		return *this;
	}

	T operator*() {
		int step = (_index)-(calc);
		switch (step) {
		case -1: 
			return a;
		case 0: 
			return b;
		default:  {
			calc += step;
			return 	fib.calculate(a, b, step);
			}
		}
	}

	T* operator ->() { return &operator*(); }
	
	bool operator>(const_iterator &iter) { return (this->_index > iter._index); }
	
	bool operator<(const_iterator &iter) { return (this->_index < iter._index); }
	
	bool operator>=(const_iterator &iter) {	return (this->_index >= iter._index); }
	
	bool operator<=(const_iterator &iter) { return (this->_index <= iter._index); }
	
	bool operator==(const_iterator &iter) {	return (this->_index == iter._index); }
	
	bool operator!=(const_iterator &iter) { return !(this->_index == iter._index); }
	
	const_iterator& operator =(const const_iterator& iter) {
		this->_index = iter._index;
		this->calc = iter.calc;
		this->a = iter.a;
		this->b = iter.b;
		return *this;
	}
};

template<>
Fibonacci<string>::Fibonacci(int size) {
	Size = size;
	first = "a";
	second = "b";
}

template<>
void Fibonacci<string>::previous(string& s1, string& s2) {
	string p = p.erase(0, s1.length()); // erase удаляет из строки 
									   //последовательность символ 
									   //заданной длины, начиная 
								       //с указанной позиции. 
	s2 = s1;
	s1 = p;
}

template<>
void Fibonacci<string>::next(string& s1, string&s2) {
	string n = s1.append(s2);// добавляет строку(символ) к концу строки. 
	s1 = s2;
	s2 = n;
};
