#include "tmatrix.h"

#include <gtest.h>


static const size_t sz1 = 10;
static const size_t sz2 = 15;

template <typename T>
class Fixtures : public ::testing::Test
{
public:
	T* tmp1;
	T* tmp2;

	TDynamicVector<T>* vec;  
	TDynamicVector<T>* v0;  
	TDynamicVector<T>* v1;
	TDynamicVector<T>* v2;


	void SetUp()
	{
		v0 = nullptr;
		tmp1 = new T[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		v1 = new TDynamicVector<T>(tmp1, 10);
		tmp2 = new T[10]{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		v2 = new TDynamicVector<T>(tmp2, 10);
		vec = new TDynamicVector<T>(*v1);

	}
	void Destroy()
	{
		delete vec; delete v0; delete v1; delete v2; 
		delete[] tmp1; tmp1 = nullptr;
		delete[] tmp2; tmp2 = nullptr;

	}

	void BuildDynamicVector(size_t s = 5)
	{
		vec = new TDynamicVector<T>(s);
		v0 = new TDynamicVector<T>(*vec);

	}
};

TYPED_TEST_CASE_P(Fixtures);

TYPED_TEST_CASE_P(Fixtures, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(this->BuildDynamicVector(1));
}

TYPED_TEST_CASE_P(Fixtures, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(this->BuildDynamicVector(MAX_VECTOR_SIZE + 1));
}

TYPED_TEST_CASE_P(Fixtures, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(this->BuildDynamicVector(-5));
}

TYPED_TEST_CASE_P(Fixtures, can_create_copied_vector)
{
	ASSERT_NO_THROW(this->BuildDynamicVector());
}

TYPED_TEST_CASE_P(Fixtures, copied_vector_is_equal_to_source_one)
{
	EXPECT_EQ((*(this->vec)), (*(this->v1)));
}

TYPED_TEST_CASE_P(Fixtures, copied_vector_has_its_own_memory)
{
	EXPECT_NE((this->vec), (this->v1));
}

TYPED_TEST_CASE_P(Fixtures, can_get_size)
{
	EXPECT_EQ(10, (this->vec->size()));
}

TYPED_TEST_CASE_P(Fixtures, can_set_and_get_element)
{
	this->vec[0][0] = 4;

	EXPECT_EQ((this->vec[0][0]), 4);
}

TYPED_TEST_CASE_P(Fixtures, throws_when_set_element_with_negative_index)
{
	ASSERT_ANY_THROW(this->vec->at(-1) = 4);
}

TYPED_TEST_CASE_P(Fixtures, throws_when_set_element_with_too_large_index)
{
	ASSERT_ANY_THROW(this->vec->at(50));
}

TYPED_TEST_CASE_P(Fixtures, can_assign_vector_to_itself)
{
	*(this->vec) = *(this->vec);

	EXPECT_EQ(*(this->vec), *(this->vec));
}

TYPED_TEST_CASE_P(Fixtures, can_assign_vectors_of_equal_size)
{
	*(this->vec) = *(this->v2);

	EXPECT_EQ(*(this->vec), *(this->v2));
}


REGISTER_TYPED_TEST_CASE_P(Fixtures, can_create_vector_with_positive_length, cant_create_too_large_vector, throws_when_create_vector_with_negative_length,
	can_create_copied_vector, copied_vector_is_equal_to_source_one, copied_vector_has_its_own_memory, can_get_size, can_set_and_get_element, throws_when_set_element_with_negative_index,
	throws_when_set_element_with_too_large_index, can_assign_vector_to_itself, can_assign_vectors_of_equal_size);

typedef::testing::Types<int, double> VectorTypes;

INSTANTIATE_TYPED_TEST_CASE_P(VectorTypesInstantiation, Fixtures, VectorTypes);

//TEST(TDynamicVector, can_create_vector_with_positive_length)
//{
//  ASSERT_NO_THROW(TDynamicVector<int> v(5));
//}
//
//TEST(TDynamicVector, cant_create_too_large_vector)
//{
//  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
//}
//
//TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
//{
//  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
//}
//
//TEST(TDynamicVector, can_create_copied_vector)
//{
//  TDynamicVector<int> v(10);
//
//  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
//}
//
//TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
//{
//	size_t length = 10;
//	int* arr = new int[length];
//
//	for (size_t i = 0; i < length; i++) {
//		arr[i] = i;
//	}
//
//	TDynamicVector<int> source(arr, length);
//
//	delete[] arr;
//
//	TDynamicVector<int> copy(source);
//
//	ASSERT_EQ(source, copy);
//}
//
//TEST(TDynamicVector, copied_vector_has_its_own_memory)
//{
//	int* q = new int[sz1] {0, 1, 2, 3, 4, 5};
//	TDynamicVector<int> v1(q, sz1);
//	delete[] q;
//	TDynamicVector<int> v2(v1);
//	TDynamicVector<int>* point1 = &v1;
//	TDynamicVector<int>* point2 = &v2;
//
//	EXPECT_NE(point1, point2);
//}
//
//TEST(TDynamicVector, can_get_size)
//{
//  TDynamicVector<int> v(4);
//
//  EXPECT_EQ(4, v.size());
//}
//
//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}
//
//TEST(TDynamicVector, throws_when_set_element_with_negative_index)
//{
//	TDynamicVector<int> v(10);
//	ASSERT_ANY_THROW((v.at(-1) = 5));
//}
//
//TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
//{
//	TDynamicVector<int> v(4);
//	ASSERT_ANY_THROW(v.at(5) = 4);
//}
//
//TEST(TDynamicVector, can_assign_vector_to_itself)
//{
//	int* q = new int[sz1] {0, 1, 2, 3, 4, 5};
//	TDynamicVector<int> v1(q, sz1);
//	TDynamicVector<int> v2(q, sz1);
//	delete[] q;
//
//	v1 = v1;
//	EXPECT_EQ(v1, v2);
//}
//
//TEST(TDynamicVector, can_assign_vectors_of_equal_size)
//{
//	size_t length = 10;
//	TDynamicVector<int> v(length);
//
//	for (size_t i = 0; i < length; i++) {
//		v[i] = i;
//	}
//
//	TDynamicVector<int> v2(length);
//	v2 = v;
//
//	ASSERT_EQ(v, v2);
//}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	int* q = new int[sz1] {0, 1, 2, 3, 4, 5};
	TDynamicVector<int> v1(q, sz1);
	delete[] q;
	int* b = new int[sz2];
	for (int i = 0; i < sz2; i++)
		b[i] = 3 + i;
	TDynamicVector<int> v2(b, sz2);
	delete[] b;
	v1 = v2;
	EXPECT_EQ(v1.size(), v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	size_t l2 = 20;
	TDynamicVector<int> v2(l2);

	v2 = v1;
	ASSERT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  size_t l1 = 10;
  TDynamicVector<int> v1(l1);

  for (size_t i = 0; i < l1; i++) {
	  v1[i] = i;
  }

  TDynamicVector<int> v2(v1);

  ASSERT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	ASSERT_EQ(v1, v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	int* a = new int[5] {1, 2, 3, 4, 5};
	TDynamicVector<int> v(a, 10);
	delete[] a;

	int* b = new int[3] {4, 54, 98};
	TDynamicVector<int> v1(b, 8);
	delete[] b;

	EXPECT_EQ(0, v == v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	int scalar = 100;
	v1 = v1 + scalar;

	TDynamicVector<int> v2(l1);

	for (size_t i = 0; i < l1; i++) {
		v2[i] = i + scalar;
	}

	ASSERT_EQ(v1, v2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	int scalar = 100;
	v1 = v1 - scalar;

	TDynamicVector<int> v2(l1);

	for (size_t i = 0; i < l1; i++) {
		v2[i] = i - scalar;
	}

	ASSERT_EQ(v1, v2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	int scalar = 100;
	v1 = v1 * scalar;

	TDynamicVector<int> v2(l1);

	for (size_t i = 0; i < l1; i++) {
		v2[i] = i * scalar;
	}

	ASSERT_EQ(v1, v2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	TDynamicVector<int> v2(l1);

	for (size_t i = 0; i < l1; i++) {
		v2[i] = i * 2;
	}

	TDynamicVector<int> v3 = v1 + v2;
	TDynamicVector<int> v4(l1);

	for (size_t i = 0; i < l1; i++) {
		v4[i] = i + i * 2;
	}

	ASSERT_EQ(v3, v4);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	size_t l1 = 10;
	size_t l2 = 20;

	TDynamicVector<int> v1(l1);
	TDynamicVector<int> v2(l2);

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	TDynamicVector<int> v2(l1);

	for (size_t i = 0; i < l1; i++) {
		v2[i] = i * 2;
	}

	TDynamicVector<int> v3 = v1 - v2;
	TDynamicVector<int> v4(l1);

	for (size_t i = 0; i < l1; i++) {
		v4[i] = i - i * 2;
	}

	ASSERT_EQ(v3, v4);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	size_t l1 = 10;
	size_t l2 = 20;

	TDynamicVector<int> v1(l1);
	TDynamicVector<int> v2(l2);

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	size_t l1 = 10;
	TDynamicVector<int> v1(l1);

	for (size_t i = 0; i < l1; i++) {
		v1[i] = i;
	}

	TDynamicVector<int> v2(l1);

	for (size_t i = 0; i < l1; i++) {
		v2[i] = i * 2;
	}

	int currentRes = v1 * v2;
	TDynamicVector<int> v4(l1);
	int actualRes = 0;

	for (size_t i = 0; i < l1; i++) {
		actualRes += i * i * 2;
	}

	ASSERT_EQ(currentRes, actualRes);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	size_t l1 = 10;
	size_t l2 = 20;

	TDynamicVector<int> v1(l1);
	TDynamicVector<int> v2(l2);

	ASSERT_ANY_THROW(v1 * v2);
}

