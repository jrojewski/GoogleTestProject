#pragma once

#include <iostream>
#include <string>

class StudentCard {
private:
	float mathGrade = -1.0f;
	float artGrade = -1.0f;
	float englishGrade = -1.0f; 
	float averageGrade = -1.0f;
	std::string name;

public:

	//constructors
	StudentCard(std::string _name) : name(_name) {};
	StudentCard(float _mathGrade, float _artGrade, float _englishGrade, std::string _name) : mathGrade(_mathGrade), artGrade(_artGrade), englishGrade(_englishGrade), name(_name) {};

	//setters
	void setMathGrade(float _mathGrade);
	void setArtGrade(float _artGrade);
	void setEnglishGrade(float _englishGrade);
	void setAverageGrade(float _averageGrade);
	void setName(std::string _name);

	//getters
	float getMathGrade() const;
	float getArtGrade() const;
	float getEnglishGrade() const;
	float getAverageGrade() const;
	std::string getName() const;

	//methods
	void calculateAverage();
};