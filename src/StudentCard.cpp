#include "StudentCard.hpp"

#include <iostream>
#include <string>

	//setters
	void StudentCard::setMathGrade(float _mathGrade) {
		mathGrade = _mathGrade;
	}
	void StudentCard::setArtGrade(float _artGrade) {
		artGrade = _artGrade;
	}
	void StudentCard::setEnglishGrade(float _englishGrade) {
		englishGrade = _englishGrade;
	}
	void StudentCard::setAverageGrade(float _averageGrade) {
		averageGrade = _averageGrade;
	}
	void StudentCard::setName(std::string _name) {
		name = _name;
	}

	//getters
	float StudentCard::getMathGrade() const { return mathGrade; }
	float StudentCard::getArtGrade() const { return artGrade; }
	float StudentCard::getEnglishGrade() const { return englishGrade; }
	float StudentCard::getAverageGrade() const { return averageGrade; }
	std::string StudentCard::getName() const { return name; }

	//methods
	void StudentCard::calculateAverage() { 
		float tempAverageGrade = ( (mathGrade + artGrade + englishGrade) / 3.0f );

		if ( mathGrade == -1.0f || artGrade == -1.0f || englishGrade == -1.0f ) {
			std::cout << "Missing grade!" <<std::endl;

			averageGrade = -1.0f;

			return;
		}

		averageGrade = tempAverageGrade;
		
		std::cout << "Calculation completed correctly!" << std::endl;

		return;
	}