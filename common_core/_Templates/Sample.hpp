#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream>
class Sample {
	public:
		Sample(void); // Default Constructor
		Sample(std::string name); // Parameter Constructor
		Sample(Sample const& rhs); // Copy Constructor
		~Sample(void); // Default Deconstructor

		Sample& operator=(Sample const& rhs); // Operator Overload

		virtual	~Sample(void); // Virtual Deconstructor

	protected:
		void	_protectedMethod(void); // Protected Method
		int		_protectedAttribute; // Protected Attribute

	private:
		void	_privateMethod(void); // Private Method
		int		_privateAttribute; // Private Attribute
};

#endif