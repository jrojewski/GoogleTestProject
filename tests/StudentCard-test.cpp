#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "StudentCard.hpp"

class StudentCardNameConstructorTest : public ::testing::Test {
protected:
	StudentCard* DaveStudentCard;

	void SetUp() override {
		DaveStudentCard = new StudentCard("Dave");
	}

	void TearDown() override {
		delete DaveStudentCard;
	}
};

TEST_F(StudentCardNameConstructorTest, DaveTest) {
	EXPECT_EQ(DaveStudentCard->getName(), "Dave");
}

TEST_F(StudentCardNameConstructorTest, MathGradeTest) {
	EXPECT_EQ(DaveStudentCard->getMathGrade(), -1.0f);
}

TEST_F(StudentCardNameConstructorTest, ArtGradeTest) {
	EXPECT_EQ(DaveStudentCard->getArtGrade(), -1.0f);
}

TEST_F(StudentCardNameConstructorTest, EnglishGradeTest) {
	EXPECT_EQ(DaveStudentCard->getEnglishGrade(), -1.0f);
}

class FullBobStudentCardTest : public ::testing::Test {
protected:
	StudentCard* FullBobStudentCard;

	void SetUp() override {
		FullBobStudentCard = new StudentCard(5.0f, 4.5f, 3.5f, "Bob");
	}

	void TearDown() override {
		delete FullBobStudentCard;
	}
};

TEST_F(FullBobStudentCardTest, BobTest) {
	EXPECT_EQ(FullBobStudentCard->getName(), "Bob");
}

TEST_F(FullBobStudentCardTest, MathGradeTest) {
	EXPECT_EQ(FullBobStudentCard->getMathGrade(), 5.0f);
}

TEST_F(FullBobStudentCardTest, ArtGradeTest) {
	EXPECT_EQ(FullBobStudentCard->getArtGrade(), 4.5f);
}

TEST_F(FullBobStudentCardTest, EnglishGradeTest) {
	EXPECT_EQ(FullBobStudentCard->getEnglishGrade(), 3.5f);
}

struct studentCard_state {
	float initialMathGrade;
	float initialArtGrade;
	float initialEnglishGrade;
	float finalAverage;

	friend std::ostream& operator<< (std::ostream& os, const studentCard_state& obj) {
		return os
			<< "initialMathGrade: " << obj.initialMathGrade
			<< ", initialArtGrade: " << obj.initialArtGrade
			<< ", initialEnglishGrade: " << obj.initialEnglishGrade
			<< ", finalAverage: " << obj.finalAverage;
	}
};

class CalculateAverageTest : public ::testing::TestWithParam<studentCard_state> {

};

TEST_P(CalculateAverageTest, FirstTest) {
	studentCard_state currentState = GetParam();
	StudentCard* AverageStudentCard;
	AverageStudentCard = new StudentCard("Average");

	AverageStudentCard->setMathGrade(currentState.initialMathGrade);
	AverageStudentCard->setArtGrade(currentState.initialArtGrade);
	AverageStudentCard->setEnglishGrade(currentState.initialEnglishGrade);

	AverageStudentCard->calculateAverage();

	EXPECT_NEAR(AverageStudentCard->getAverageGrade(), GetParam().finalAverage, 0.05f);
}

INSTANTIATE_TEST_CASE_P(CalculateAverages, CalculateAverageTest, ::testing::Values(
	studentCard_state{ 3.0f, 3.0f, 3.0f, 3.00f },
	studentCard_state{ 4.0f, 4.0f, 4.0f, 4.00f },
	studentCard_state{ 5.0f, 5.0f, 5.0f, 5.00f },
	studentCard_state{ 5.0f, 4.5f, 3.5f, 4.30f },
	studentCard_state{ 4.5f, 4.5f, 3.0f, 4.00f },
	studentCard_state{ 4.0f, 3.0f, 4.5f, 3.83f },
	studentCard_state{ -1.0f, 5.0f, 5.0f, -1.0f }
));