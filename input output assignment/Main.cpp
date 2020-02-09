#include <iostream>
#include <fstream>
#include <string>
#include <vector>




int main()
{

	//Array for reference words
	const std::string REFERENCE[] = { "Asm", "Auto", "Bool", "Break", "Case", "Catch",
		"Char", "Class", "Const", "Const_cast", "Continue", "Default", "Delete", "Do", "Double"
		, "Dynamic_cast", "Else", "Enum", "Explicit", "Export", "Extern", "False", "Float",
		"For", "Friend", "Goto", "If", "Inline", "Int", "Long", "Mutable", "Namespace", "New", "Operator", "Private", "Protected", "Public", "Register"
		, "Reinterpret_cast", "Return", "Short", "Signed", "Sizeof", "Static", "Static_cast", "Struct",
		"Switch", "Template", "This", "Throw", "True", "Try", "Typedef", "Typeid",
		"Typename", "Union", "Unsigned", "Using", "Virtual", "Void", "Volatile", "Wchar_t", "While" };
	//array for reserved words
	const std::string Reserved[] = { "And", "And_eq", "Bitand", "Bitor", "Compl", "Not", "Not_eq", "Or", "Or_eq", "Xor", "Xor_eq"};

	std::ifstream fin;
	std::ofstream fout;

	//Reading file
	fin.open("Input or Output.txt");
	//Writing file
	fout.open("Keyword_reference_Sheet_upgraded.txt");

	// hold lines of text
	std::string TextLine;
	//variable that holds number of keyword for both
	int ReferenceNum = 0;
	int ReservedNum = 0;

	//store definiton
	std::vector<std::string> Ref_found;
	std::vector<std::string> Res_found;

	//reading text line by line
	while (std::getline(fin, TextLine))
	{
		//print of line of text to screen
		std::cout << TextLine << std::endl;

		//grabs the first word of the line
		std::string beginWord = TextLine.substr(0, TextLine.find(" "));
		std::cout << beginWord << "\n";
		//finding and counting Reference

		//Counting for the reference
		for (std::string keyword : REFERENCE)
		{
			if (beginWord == keyword)
			{
				Ref_found.push_back(TextLine);
				++ReferenceNum;
			}
		}

		//Counting for Reserved
		for (std::string keyword : Reserved)
		{
			if (beginWord == keyword)
			{
				Res_found.push_back(TextLine);
				++ReservedNum;
			}
		}

	}
	//close the file that was read
	fin.close();

	//display the Reference count
	fout << "C++ Reference Found = " << Ref_found.size() << "\n\n";
	for (std::string Definition : Ref_found)
	{
		fout << Definition << "\n";
	}

	//display of the reserved words count
	fout << "C ++ Reserved Words found = " << Res_found.size() << "\n\n";
	for (std::string Definition : Res_found)
	{
		fout << Definition << "\n";
	}
	//close the file that was writing
	fout.close();
}
