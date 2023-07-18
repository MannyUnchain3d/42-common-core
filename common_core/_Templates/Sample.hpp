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
		Sample(void); // Default Constructor
		Sample(Sample const& rhs); // Copy Constructor
		Sample(int const n); // Parameter Constructor
		~Sample(void); // Default Deconstructor

		Sample& operator=(Sample const& rhs); // Operator Overload

		virtual	~Sample(void); // Virtual Deconstructor

	private:
		void	_privateMethod(void); // Private Method
		int		_privateAttribute; // Private Attribute

	protected:
		void	_protectedMethod(void); // Protected Method
		int		_protectedAttribute; // Protected Attribute
};

#endif