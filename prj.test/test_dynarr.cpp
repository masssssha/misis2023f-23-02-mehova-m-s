#include <dynarr/dynarr.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("dynarr ctor") {
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
	arr[3] = 2.0f;
	CHECK(arr[3] != b[3]);
	CHECK_NOTHROW(b[arr.Size() - 1]);
}

TEST_CASE("dynarr res") {
	const int Size = 5;
	DynArr arr(Size);
	arr[Size - 1] = 12;
	arr.Resize(12);
	CHECK_NOTHROW(arr[11]);
	CHECK(arr[Size + 1] == 0.0f);
	CHECK(arr[Size - 1] == 12.0f);
	arr.Resize(6);
	CHECK_THROWS(arr[11]);
	arr[4] = 5;
	CHECK_EQ(arr[4], 5.0f);
	CHECK(arr[5] == 0.0f);
}

TEST_CASE("dynarr =") {
	DynArr a(10);
	for (int i = 0; i < a.Size(); i++) {
		a[i] = i;
	}
	DynArr b = a;
	CHECK(b[8] == a[8]);
	for (int i = 0; i < b.Size(); i++) {
		b[i] += 10;
	}
	CHECK(b[5] != a[5]);
	a = b;
	CHECK(b[5] == a[5]);
	a[2] = 0;
	CHECK(a[2] != b[5]);
}