#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

std::string	read_file_into_string(std::string filename)
{
	std::ifstream f(filename);
   	std::string str;
	
   	if(f)
	{
		std::ostringstream ss;
		ss << f.rdbuf();
		str = ss.str();
   	}
	else
	{
		std::cout << "Error: invaild file\n";
		exit(1);
	}
	return str;
}

void	write_string_to_file(std::string filename, std::string replace)
{
	std::string newfile;

	newfile = filename + ".replace";
	std::ofstream out(newfile);
   	out << replace;
   	out.close();
}

std::string convert_s1_to_s2(std::string content, std::string s1, std::string s2)
{
	std::string replace;
	std::string::size_type start;
	std::string::size_type n;

	start = 0;
	replace = "";
	while (content.length() > 0)
	{
		n = content.find(s1, 0);
		if (n == std::string::npos)
		{
			replace += content.substr(0);
			break;
		}
		replace += content.substr(0, n);
		replace += s2;
		content = content.substr(n + s1.length());
	}
	return (replace);
}

int main(int ac, char **av)
{
	std::string content;
	std::string replace;

	if (ac != 4)
	{
		std::cout << "Error: argument error\n";
		exit(1);
	}
	content = read_file_into_string(av[1]);
	replace = convert_s1_to_s2(content, av[2], av[3]);
	write_string_to_file(av[1], replace);
	return (0);
}