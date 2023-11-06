#!/bin/bash

# Check if at least one class name is provided as an argument
if [ $# -lt 1 ]; then
	echo "Usage: $0 <class_name1> [<class_name2> <class_name3> ...]"
	exit 1
fi

# Loop through all the provided class names
for class_name in "$@"; do
	hpp_file="${class_name}.hpp"
	cpp_file="${class_name}.cpp"

	# Check if the class files already exist
	if [ -e $hpp_file ] || [ -e $cpp_file ]; then
		echo "Class files already exist for $class_name: $hpp_file, $cpp_file"
		continue
	fi

# Convert class_name to uppercase for include guards
	include_guard=$(echo "$class_name" | tr '[:lower:]' '[:upper:]')

	# Generate the content for Sample.hpp
	cat > $hpp_file << EOF
#ifndef ${include_guard}_HPP
# define ${include_guard}_HPP

# include <iostream>

class ${class_name} {
	public:
		${class_name}(void);
		${class_name}(std::string name);
		${class_name}(${class_name}const& rhs);
		virtual ~${class_name}(void);

		${class_name}& operator=(${class_name}const& rhs);

	protected:
		void _protectedMethod(void);
		int _protectedAttribute;

	private:
		void _privateMethod(void);
		int _privateAttribute;
};

#endif
EOF

	# Generate the content for Sample.cpp
	cat > $cpp_file << EOF
#include "colors.h"
#include "${hpp_file}"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
${class_name}::${class_name}(void) {
	// Make your Constructor here
}

/* Parameter Constructor */
${class_name}::${class_name}(std::string name) {
	// Make your Constructor here
}

/* Copy Constructor */
${class_name}::${class_name}(${class_name} const& rhs) {
	*this = rhs;
	// Make your Copy Constructor here
}

/* ----- DESTRUCTOR ------------------- */

${class_name}::~${class_name}(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ------------ */

${class_name}& ${class_name}::operator=(${class_name} const& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- GETTER ----------------------- */

/* ----- SETTER ----------------------- */

/* ----- PUBLIC METHOD ---------------- */

void ${class_name}::publicMethod(void) {
	// Implement public method here
}

/* ----- PROTECTED METHOD ------------- */

void ${class_name}::_protectedMethod(void) {
	// Implement protected method here
}

/* ----- PRIVATE METHOD --------------- */

void ${class_name}::_privateMethod(void) {
	// Implement private method here
}
EOF

	echo "Class files generated for $class_name: $hpp_file, $cpp_file"
done
