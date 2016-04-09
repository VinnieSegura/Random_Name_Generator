/*
Simple random name generator, gather first name and last name from different files.
*/

#include <iostream> // Declares objects that control reading from and writing to the standard streams. This is often the only header you need to include to perform input and output from a C++ program.
#include <ctime> // Includes the Standard C library header <time.h> and adds the associated names to the std namespace.
#include <string> // Defines the container template class basic_string and various supporting templates.
#include <fstream> // Defines several classes that support iostreams operations on sequences stored in external files.

using namespace std;

int main()
{
	ifstream file("firstname.txt"); // Create an input file stream to read from the file named firstname.txt.

	if (!file) { // If firstname.txt does not exist.
		cout << "Error: Can't open the file named firstname.txt\n";
		exit(1);
	}
	
	if (file.is_open()) // If file firstname.txt it's open.
	{

		string firstname[21]; // Array of 21 strings to hold the first names.

		for (int i = 0; i < 21; ++i)
		{
			file >> firstname[i];
		}

		ifstream file2("lastname.txt"); // Create an input file stream to read from the file named lastname.txt.

		if (!file2) { // If lastname.txt does not exist.
			cout << "Error: Can't open the file named lastname.txt\n";
			exit(1);
		}

		if(file2.is_open()) // If file lastname.txt it's open.
		{
			string lastname[21]; // Array of 21 strings to hold the last names.

			for (int i = 0; i < 21; ++i)
			{
				file2 >> lastname[i];
			}

			srand(time(0)); // Generate random numbers by seeding rand with a starting value, in this case time(0) gives the time in seconds, to be used as seed.
			char gName;

			do
			{
				cout << "Generated Name: " << firstname[rand() % 21] << " " << lastname[rand() % 21] << endl;
				cout << "Generate another one?(Y/N) ";
				cin >> gName;
				cout << endl;
			} 
			while ((gName == 'Y') || (gName == 'y')); // If "Y" or "y" if pressed continue the generating random names.
			return 0; // If not "while" exit.
		}
	}
}