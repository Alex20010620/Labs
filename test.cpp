#include "pch.h"

#include "LinkedList.h"

LinkedList list;

TEST(TestCaseList, push_front) {
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);
	EXPECT_EQ(5, list.get_size());
	list.clear();
}


TEST(TestCaseList, push_back) {
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	EXPECT_EQ(6, list.get_size());
	list.clear();
}


TEST(TestCaseList, add) {
	list.push_back(3);
	list.push_front(1);
	list.insert(2, 2);		// (index, data) 
	EXPECT_EQ(3, list.get_size());	// 1, 2, 3
}

TEST(TestCaseList, insert_front) {
	list.insert(0, 0);		 
	EXPECT_EQ(4, list.get_size());	// 0, 1, 2, 3
}

TEST(TestCaseList, remove) {
	list.clear();
	EXPECT_EQ(0, list.get_size());	// -
}

TEST(TestCaseList, insert_repeatly) {
	LinkedList temp_list;
	for (size_t i = 0; i < 5; i++) {
		list.push_back(i);
	}
	list.clear();
	for (size_t i = 4; i > 0; i--) {
		list.insert(i, 0);
	}
	list.insert(0, 0);

	for (size_t i = 0; i < 5; i++)
		EXPECT_EQ(temp_list.at(i), list.at(i)); // 0, 1, 2, 3, 4
}

TEST(TestCaseList, is_empty) {
	list.clear();
	EXPECT_TRUE(list.isEmpty());
}

TEST(TestCaseList, reverse) {
	LinkedList not_reversed;
	for (size_t i = 0; i < 10; i++) {
		not_reversed.push_back(i);
		list.push_front(i);
	}
	not_reversed.reverse();

	for (size_t i = 0; i < 10; i++) {
		EXPECT_EQ(list.at(i), not_reversed.at(i));
	}
}
TEST(TestCaseList, set_front) {
	list.set(0, 125);
	EXPECT_EQ(list.at(0), 125);
}