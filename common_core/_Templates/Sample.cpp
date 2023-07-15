#include "Sample.hpp"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
Sample::Sample(void) {
	// Make your Constructor here
}

/* Copy Constructor */
Sample::Sample (Sample const& src) {
	// Make your Copy Constructor here
	*this = src;
}

/* Parameter Constructor */
Sample::Sample (int const n) {
	// Make your Constructor here
}

/* ----- DESTRUCTOR ------------------ */

Sample::~Sample(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ---------- */

Sample&	Sample::operator=(Sample const& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- GETTER ----------------------- */

/* ----- SETTER ----------------------- */

/* ----- PUBLIC METHOD ------------- */

/* ----- PRIVATE METHOD ------------ */

/* ----- EXTERNAL FUNCTION --------- */

