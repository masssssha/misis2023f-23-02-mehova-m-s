#include <iostream>
#include <cstddef>
#include <stdexcept>

float bbb = 5;
float error = -1;

class DynArr {
public:
	DynArr() = default;
	DynArr(const DynArr&);
	DynArr(const std::ptrdiff_t s);
	~DynArr() = default;
	std::ptrdiff_t size() const;
	void resize(const std::ptrdiff_t s);
	float& operator[](const std::ptrdiff_t i);
	const float& operator[](const std::ptrdiff_t i) const;
private:
	std::ptrdiff_t size_ = 0;
	float* data_ = nullptr;

};

int main() {
	DynArr a(20);
	std::cout << a.size() << std::endl;
	a.resize(15);
	std::cout << a.size() << std::endl;
	std::cout << a[20] << std::endl;
}

DynArr::DynArr(const std::ptrdiff_t s) {
	size_ = s;
}

std::ptrdiff_t DynArr::size() const {
	return size_;
}

void DynArr::resize(const std::ptrdiff_t s) {
	size_ = s;
}

float& DynArr::operator[](const std::ptrdiff_t i) {
	if (i < 0 || i >= size_) {
		std::cout << "Index out of range";
		return error;
	}
	else {
		return bbb;
	}
}

const float& DynArr::operator[](const std::ptrdiff_t i) const {
	if (i < 0 || i >= size_) {
		throw std::out_of_range("Index out of range");
	}
	else {
		return bbb;
	}
}