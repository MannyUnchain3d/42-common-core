#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define BLINK		"\033[5m"
# define NC			"\033[0m"

class Sample {
	public:
		Sample(void); // Class Constructor
		Sample(const Sample& src); // Class Copy Constructor
		~Sample(void); // Class Deconstructor

		Sample& operator=(const Sample& rhs); // Operator Overload

		virtual	~Sample(void); // Virtual Deconstructor
};

#endif