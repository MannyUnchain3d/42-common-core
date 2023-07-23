#include "Sample.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Sample::Sample(void) {
	// Make your Constructor here
}

/* Parameter Constructor */
Sample::Sample(std::string type) {
	// Make your Constructor here
}

/* Copy Constructor */
Sample::Sample(Sample const& rhs) {
	// Make your Copy Constructor here
	*this = rhs;
}

/* ----- DESTRUCTOR ------------------- */

Sample::~Sample(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ------------ */

Sample&	Sample::operator=(Sample const& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- GETTER ----------------------- */

/* ----- SETTER ----------------------- */

/* ----- PUBLIC METHOD ---------------- */

/* ----- PROTECTED METHOD ------------- */

/* ----- PRIVATE METHOD --------------- */

/* ----- EXTERNAL FUNCTION ------------ */