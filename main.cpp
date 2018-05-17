#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	vector<string> scheme = {
								"ab->b",
								"b->E",
								"a->b",
								"E->.a"
							};
	string word = "bbaab";

	cout << "—хема " << endl;
	for (size_t i = 0; i < scheme.size(); i++)
	{
		cout << scheme[i] << endl;
	}
	

	cout << "¬ведите слово ";
	cin >> word;
	cout <<endl<< "–ешение " << endl;
	string new_mod_s = "";
	//string new_s = "E"+word+"E";
	//word = new_s;

	cout << word << "=>";
	
	
	for (size_t i = 0; i < scheme.size(); i++)
	{
		string::size_type pos = scheme[i].find("->");
		if (pos != string::npos)
		{
			new_mod_s=scheme[i].substr(0,pos);
			//cout << new_mod_s << std::endl;
		}	
		string::size_type pos2 = word.find(new_mod_s);

		
		while (pos2 != std::string::npos)
		{
			string c = scheme[i].substr(pos + 2);
			if (c[0] == '.') { 
				if (c == ".E") word.replace(pos2, new_mod_s.length(), "");
				else word.replace(pos2, new_mod_s.length(), c.substr(1));
				cout << word << endl;
				break; }
			if (new_mod_s == "E") { word = c.substr(1) + word; 
			cout << word << endl;
			}

			if(c== "E") word.replace(pos2, new_mod_s.length(), "");
			else word.replace(pos2, new_mod_s.length(), c);

			if (word == "") { word += "E"; 
			if(c[0]=='.') cout <<word << endl;
			else cout << word << "=>";
			}
			else		
			cout << word << "=>";
				
				pos2 = word.find(new_mod_s);
		}
		//cout << word << endl;
	

		
	}
	
	system("pause");
}

