#include <iostream>
#include <iomanip>

#include "StudentCard.hpp"

int main() {
    float userMathGrade, userArtGrade, userEnglishGrade;
    std::string userName;

    std::cout << "Hello Student, tell us something about you." << std::endl;
    std::cout << "What's your name?" << std::endl;
    std::cin >> userName;
    std::cout << "What's your math grade?" << std::endl;
    std::cin >> userMathGrade;
    std::cout << "What's your art grade?" << std::endl;
    std::cin >> userArtGrade;
    std::cout << "What's your english grade?" << std::endl;
    std::cin >> userEnglishGrade;

    StudentCard myStudentCard(userMathGrade, userArtGrade, userEnglishGrade, userName);

    std::cout << "So, you are " << myStudentCard.getName() << std::fixed << std::setprecision(1)
                << "! Your math grade is " << myStudentCard.getMathGrade() 
                << "! Your art grade is " << myStudentCard.getArtGrade() 
                << "! Your english grade is " << myStudentCard.getEnglishGrade() 
                << "!" << std::endl;
                
    return 0;
}