#include "colors.h"
#include "Cure.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Cure::Cure(void) {
	// Make your Constructor here
}

/* Parameter Constructor */
Cure::Cure(std::string name) {
	// Make your Constructor here
}

/* Copy Constructor */
Cure::Cure(const Cure& rhs) {
	*this = rhs;
	// Make your Copy Constructor here
}

/* ----- DESTRUCTOR ------------------- */

Cure::~Cure(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ------------ */

Cure& Cure::operator=(const Cure& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- PROTECTED METHOD ------------- */

/* ----- PRIVATE METHOD --------------- */

