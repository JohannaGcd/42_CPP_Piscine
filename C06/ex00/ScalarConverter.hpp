#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

 #include <string>

class ScalarConverter {

	private:
		ScalarConverter();
		~ScalarConverter();

	public:
		static void convert(const std::string& str);

};

#endif