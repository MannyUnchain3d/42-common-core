#ifndef __SAMPLE_HPP__
# define __SAMPLE_HPP__

class Sample {
	public:
		Sample(void); // Class Constructor
		Sample(Sample const &src); // Class Copy Constructor
		~Sample(void); // Class Deconstructor

		Sample	&operator=(Sample const &rhs); // Operator Overload

		virtual	~Sample(void); // Virtual Deconstructor
};

#endif