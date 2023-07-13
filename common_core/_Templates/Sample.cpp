#include "Sample.hpp"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
Sample::Sample(void){
	return ;
}

/* Copy Constructor */
Sample::Sample(Sample const& src)
{
	*this = src;
}

/* ----- DESTRUCTOR ------------------ */

Sample::~Sample(void)
{
	return ;
}

/* ----- OPERATOR OVERLOADS ---------- */

Sample	&Sample::operator=(Sample const& rhs)
{
	// Make your Assignment here
	return (*this);
}

/* ----- GETTER ----------------------- */

/* ----- SETTER ----------------------- */

/* ----- PUBLIC METHOD(S) ------------- */

/* ----- PRIVATE METHOD(S) ------------ */

/* ----- EXTERNAL FUNCTION(S) --------- */

