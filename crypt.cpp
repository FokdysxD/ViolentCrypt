//============================================================================
// Name        : crypt.cpp
// Author      : Fok_dys_xD
// Version     :
// Copyright   : WTF License
// Description : Really Violent
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <fstream>
using namespace std;

string sexplicit[16] = {"jebany", "pierdolony", "piździelcu", "gówniany",
							"kurwiszonie", "niedomyty", "chuju", "skurczybyku",
							"sukinkocie", "paszczurze", "wyruchany", "zasyfiały",
							"naplecie", "skurwiały", "niedojebany", "jebako"};
string nonexplicit[16] = {"nicponiu", "gałganie", "niedorajdo", "gnojku",
								"potargany", "ciamajdo", "pomylony", "roztrzepany",
								"urwisie", "skarłowaciały", "korniszonie", "szubrawco",
								"rozdyndany", "spartaczony", "paszkwilu", "łysy"};
string globalstring;

string ReadFromFile(){
	  string line;
	  stringstream output;
	  ifstream myfile ("input.txt");
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      output << line;
	    }
	    myfile.close();
	  }
	  else cout << "Unable to open file";
	  cout<<output.str();
	  return output.str();
}

void WriteToFile(string str){
	ofstream myfile ("output.txt");
	  if (myfile.is_open())
	  {
	    myfile << str;
	    myfile.close();
	  }
	  else cout << "Unable to open file";
}
int hextoint(char ch){
	int res;
	switch(ch){
		case '1':
			res=1;
			break;
		case '2':
			res=2;
			break;
		case '3':
			res=3;
			break;
		case '4':
			res=4;
			break;
		case '5':
			res=5;
			break;
		case '6':
			res=6;
			break;
		case '7':
			res=7;
			break;
		case '8':
			res=8;
			break;
		case '9':
			res=9;
			break;
		case 'a':
			res=10;
			break;
		case 'b':
			res=11;
			break;
		case 'c':
			res=12;
			break;
		case 'd':
			res=13;
			break;
		case 'e':
			res=14;
			break;
		case 'f':
			res=15;
			break;
	}
	return res;
}
int CountWords(const char* str)
{
   if (str == NULL)
      return 0;

   bool inSpaces = true;
   int numWords = 0;

   while (*str != NULL)
   {
      if (std::isspace(*str))
      {
         inSpaces = true;
      }
      else if (inSpaces)
      {
         numWords++;
         inSpaces = false;
      }

      ++str;
   }

   return numWords;
}
char intToHex(int num){
	char ch;
	switch(num){
			case 1:
				ch='1';
				break;
			case 2:
				ch='2';
				break;
			case 3:
				ch='3';
				break;
			case 4:
				ch=4;
				break;
			case 5:
				ch='5';
				break;
			case 6:
				ch='6';
				break;
			case 7:
				ch='7';
				break;
			case 8:
				ch='8';
				break;
			case 9:
				ch='9';
				break;
			case 10:
				ch='a';
				break;
			case 11:
				ch='b';
				break;
			case 12:
				ch='c';
				break;
			case 13:
				ch='d';
				break;
			case 14:
				ch='e';
				break;
			case 15:
				ch='f';
				break;
		}
	return ch;
}
int checkWord(string str){
	int value = 20;
	if (str.empty())
	      value=0;

	for(int i=0; i < 16; i++){
		if(!str.compare(nonexplicit[i])){
			value=i;
			break;
		}
	}
	return value;
}
string encrypt(string input){
		std::stringstream ss, output;
		//cout<<"Wprowadz tekst do zaszyfrowania, bez polskich znakow: "<<endl;
		//getline(cin, input);
		string mystr[input.size()];
		for(int i=0; i<input.size(); ++i){
			ss << std::hex << (int)input.at(i);
			mystr[i] = ss.str();
			ss.str("");
		}
		output<<"Ty ";
		for(int i=0; i<input.size()-1; i++){
			output<<nonexplicit[hextoint(mystr[i].at(0))]<<" "<<nonexplicit[hextoint(mystr[i].at(1))]<<" ";
		}
		cout<<output.str();
		return output.str();
}
string decrypt(string input){
	//string input;
	//cout<<"Wprowadz tekst do odszyfrowania: "<<endl;
	//getline(cin, input);
	stringstream inputss(input);
	int count = CountWords(input.c_str());
	cout<<"Ilosc słów: "<<count<<endl;
	string arr[count];
	int iterator = 0;
	while(inputss.good() && iterator < count){
		//cout<<inputss.str()<<endl;
		inputss>>arr[iterator];
		iterator++;
	}
	int buf;
	stringstream output;
	for(int i=0; i < count; i++){
		cout<<arr[i]<<"  ";
		buf=checkWord(arr[i]);
		cout<<buf<<endl;
		output <<hex<<buf;
	}
	cout<<endl<<output.str()<<endl;


	int len = output.str().length();
	string lastoutput;
	for(int i=0; i< len; i+=2)
	{
	    string but = output.str().substr(i,2);
	    char chr = (char) (int) strtol(but.c_str(), NULL, 16);
	    lastoutput.push_back(chr);
	}
	cout<<endl<<lastoutput<<endl;
	return lastoutput;
}
void menu(){
	int option;
	do{
	cout<<"Wybierz opcję: "<<endl;
	cout<<"1. Zaszyfruj wiadomosc z pliku input.txt"<<endl;
	cout<<"2. Odszyfruj wiadomosc z pliku intput.txt"<<endl;
	cout<<"3. Wyjdz z programu"<<endl;
	cout<<": "<<endl;
	cin>>option;
	switch(option){
	case 1:
		WriteToFile(encrypt(ReadFromFile()));
		break;
	case 2:
		WriteToFile(decrypt(ReadFromFile()));
		break;
	}
	}while(option != 3);

}

int main()
{

	/*test = encrypt();
	decrypt(test);*/
	menu();
    return 0;
}
