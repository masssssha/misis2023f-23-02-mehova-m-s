/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"*/

#include <iostream>
#include <cstddef>
#include <stdexcept>

class DynArr {
public:
	DynArr() = default;
	explicit DynArr(const DynArr& x);    //done
	DynArr(const std::ptrdiff_t s);     //done
	~DynArr();                          //done
	std::ptrdiff_t Size() const;        //done
	void Resize(const std::ptrdiff_t s);
	float& operator[](const std::ptrdiff_t i);        //done
	const float& operator[](const std::ptrdiff_t i) const;    //done
private:
	std::ptrdiff_t size_ = 0;
	float* data_ = nullptr;
};
 
//copy maker
DynArr::DynArr(const DynArr& x) 
	: size_(x.size_) {
	data_ = new float[x.size_];
	for (int i = 0; i < x.size_; i++) {
		*(data_ + i) = x[i];
	}
}

//size maker
DynArr::DynArr(const std::ptrdiff_t s) 
	: size_(s) {
	if (s <= 0) {
		throw std::out_of_range("Index out of range");
	}
	data_ = new float[s] {0.0f};
}

//crush
DynArr::~DynArr() {
	delete[] data_;
	data_ = nullptr;
}

//size
std::ptrdiff_t DynArr::Size() const {
	return size_;
}

void DynArr::Resize(const std::ptrdiff_t s) {
	if (s <= 0) {
		throw std::out_of_range("Index out of range");
	}
	if (s <= size_) {
		size_ = s;
	}
	else {

	}
}

//[]
float& DynArr::operator[](const std::ptrdiff_t i) {
	if (i < 0 || i >= size_) {
		throw std::out_of_range("Index out of range");
	}
	return *(data_ + i);
}

const float& DynArr::operator[](const std::ptrdiff_t i) const {
	if (i < 0 || i >= size_) {
		throw std::out_of_range("Index out of range");
	}
	return *(data_+i);
}


int main() {
	DynArr a(5);
	DynArr b(a);
	a[2] = 5;
	a[6] = 4;
	for (int i = 0; i < 5; i++) {
		std::cout << "a: " << a[i] << std::endl;
		std::cout << "b: " << b[i] << std::endl;
	}
}


/*TEST_CASE("dynarr ctor") {
	DynArr arr_def;
	CHECK_EQ(arr_def.Size(), 0);

	const int Size = 5;
	DynArr arr_s(Size);
	CHECK_EQ(arr_s.Size(), Size);
}

TEST_CASE("dynarr op[]") {
	const int Size = 5;
	DynArr arr(Size);
	DynArr b(arr);
	//CHECK_EQ(arr[0], doctest::Approx(0.0f));
	//CHECK_EQ(arr[arr.Size() - 1], doctest::Approx(0.0f));
	//REQUIRE(arr[0] == doctest::Approx(0.0f));
	//CHECK_EQ(arr[0], b[0]);
	//CHECK_THROWS(arr[20]);
	//arr[3] = 2;
	//CHECK(arr[0] == b[0]);
}

TEST_CASE("dynarr res") {
	const int Size = 5;
	DynArr arr(Size);
	arr.Resize(12);
	CHECK_NOTHROW(arr[11]);
	arr.Resize(6);
	CHECK_THROWS(arr[11]);
	arr[4] = 5;
	CHECK_EQ(arr[4], 5);
	CHECK(arr[5] == 0.0f);
}*/