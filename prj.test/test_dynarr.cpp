//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.h"

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
	std::ptrdiff_t capacity() const noexcept {
		return cap - data_;
	}
private:
	std::ptrdiff_t size_ = 0;
	float* data_ = nullptr;
	float* cap = nullptr;
};
 
//copy maker
DynArr::DynArr(const DynArr& x) 
	: size_(x.size_) {
	data_ = new float[x.size_];
	cap = &(*this)[(*this).Size()-1];
	for (int i = 0; i < x.size_; i++) {
		*(data_ + i) = x[i];
	}
}

//size maker
DynArr::DynArr(const std::ptrdiff_t s) 
	: size_(s) {
	if (s <= 0) {
		throw std::invalid_argument("Size must be a positive number");
	}
	data_ = new float[s] {0.0f};
	cap = &(*this)[(*this).Size()-1];
}

//crush
DynArr::~DynArr() {
	delete[] data_;
	data_ = nullptr;
	cap = nullptr;
}

//size
std::ptrdiff_t DynArr::Size() const {
	return size_;
}

void DynArr::Resize(const std::ptrdiff_t s) {
	if (s <= 0) {
		throw std::invalid_argument("Size must be a positive number");
	}
	if (s <= (*this).capacity()) {
		size_ = s;
	}
	else {
		DynArr b(*this);
		delete[] data_;
		data_ = nullptr;
		cap = nullptr;
		data_ = new float[s];
		cap = &(*this)[(*this).Size() - 1];
		size_ = s;
		for (int i = 0; i < s; i++) {
			if (i < b.Size()) {
				*(data_ + i) = b[i];
			}
			else {
				*(data_ + i) = 0;
			}
		}
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

/*TEST_CASE("dynarr ctor") {
	DynArr arr_def;
	CHECK_EQ(arr_def.Size(), 0);

	const int Size = 5;
	DynArr arr_s(Size);
	CHECK_EQ(arr_s.Size(), Size);
	CHECK_NOTHROW(arr_s[arr_s.Size() - 1]);
}



TEST_CASE("dynarr op[]") {
	const int Size = 5;
	DynArr arr(Size);
	CHECK_EQ(arr[0], doctest::Approx(0.0f));
	CHECK_EQ(arr[arr.Size() - 1], doctest::Approx(0.0f));
	REQUIRE(arr[3] == doctest::Approx(0.0f));
	CHECK_THROWS(arr[arr.Size() + 1]);
	DynArr b(arr);
	CHECK_EQ(arr[0], b[0]);
	arr[3] = 2;
	CHECK(arr[3] != b[3]);
	CHECK_NOTHROW(b[arr.Size() - 1]);
}

TEST_CASE("dynarr res") {
	const int Size = 5;
	DynArr arr(Size);
	arr[Size - 1] = 12;
	arr.Resize(12);
	CHECK_NOTHROW(arr[11]);
	CHECK(arr[Size + 1] == 0);
	CHECK(arr[Size - 1] == 12);
	arr.Resize(6);
	CHECK_THROWS(arr[11]);
	arr[4] = 5;
	CHECK_EQ(arr[4], 5);
	CHECK(arr[5] == 0.0f);
}*/

int main() {
	DynArr a(10);
	std::cout << a.capacity();
}