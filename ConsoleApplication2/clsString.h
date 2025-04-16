#pragma once
#include<iostream>
#include<vector>



//#43 Replacing Word using Split
//#41 Reverse Words

using namespace std;

class clsString
{
private:

	string _Value;
	char _ch;

	static string JoinString(vector<string>vWords)
	{
		string S1 = "";

		for (int i = 0; i < vWords.size(); i++)
		{
			S1 += vWords[i] + " ";
		}

		return S1;
	}


public:
	static vector<string>Split(string S1, string delim = " ")
	{
		int pos;
		string Word;
		vector<string >vWords;

		while ((pos = S1.find(delim)) != S1.npos)
		{
			Word = S1.substr(0, pos);

			if (Word != "")
			{
				vWords.push_back(Word);
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			vWords.push_back(S1);
		}

		return vWords;
	}

	clsString()
	{

	}

	clsString(string Value)
	{
		_Value = Value;
	}

	clsString(char ch)
	{
		_ch = ch;
	}

	clsString(string Value, char ch)
	{
		_Value = Value;
		_ch = ch;
	}

	void setValue(string S1)
	{
		_Value = S1;
	}

	string GetString()
	{
		return _Value;
	}

	_declspec(property(get = GetString, put = setValue))string Value;

	void setChar(char ch)
	{
		_ch = ch;
	}

	char GetChar()
	{
		return _ch;
	}

	_declspec(property(get = GetChar, put = setChar)) char ch;

	static int CountWords(string S1)
	{
		vector<string>vWords = Split(S1);
		int Counter = 0;

		for (string S : vWords)
		{
			Counter++;
		}

		return Counter;
	}

	int CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstLetter && S1[i] != ' ')
			{
				cout << S1[i] << endl;
			}

			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}
	}

	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstLetter && S1[i] != ' ')
			{
				S1[i] = toupper(S1[i]);
			}

			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}

		return S1;
	}

	string UpperFirstLetterOfEachWord()
	{
		return (_Value = UpperFirstLetterOfEachWord(_Value));
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstLetter && S1[i] != ' ')
			{
				S1[i] = tolower(S1[i]);
			}

			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}

		return S1;
	}

	string LowerFirstLetterOfEachWord()
	{
		return (_Value = LowerFirstLetterOfEachWord(_Value));
	}

	static string UpperAllLetterInString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}

	string UpperAllLetterInString()
	{
		return (_Value = UpperAllLetterInString(_Value));
	}

	static string LowerAllLetterInString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}

	string LowerAllLetterInString()
	{
		return (_Value = LowerAllLetterInString(_Value));
	}

	static char InvertCharacterCase(char ch)
	{
		return (isupper(ch) ? tolower(ch) : toupper(ch));
	}

	char InvertCharacterCase()
	{
		return InvertCharacterCase(_ch);
	}

	static string InvertCharacterCaseOfWords(string S1)
	{
		for (int i = 0;i < S1.length(); i++)
		{
			S1[i] = InvertCharacterCase(S1[i]);
		}

		return S1;
	}

	string InvertCharacterCaseOfWords()
	{
		return(_Value = InvertCharacterCaseOfWords(_Value));
	}

	static int CountSmallLetter(string S1)
	{
		int Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}

		return Counter;
	}

	int CountSmallLetter()
	{
		return CountSmallLetter(_Value);
	}

	static int CountCapitalLetter(string S1)
	{
		int Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}

		return Counter;
	}

	int CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	static int CountCertainLetter(string S1, char SpecifiedLetter)
	{
		int Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] == SpecifiedLetter)
				Counter++;
		}

		return Counter;
	}

	int CountCertainLetter()
	{
		return CountCertainLetter(_Value, _ch);
	}

	static void PrintEachWordInString(string S1)
	{
		vector< string >VWords = Split(S1);

		for (string S : VWords)
			cout << S << endl;

	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static bool IsVowel(char ch)
	{
		ch = tolower(ch);

		return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
	}

	bool IsVowel()
	{
		return IsVowel(_ch);
	}

	static string ReplacingWord(string WordToReplace, string ReplacedWord, string S1)
	{
		vector<string>vWords = Split(S1);

		for (string& S : vWords)
		{
			if (S == WordToReplace)
				S = ReplacedWord;
		}

		return JoinString(vWords);
	}

	string ReplacingWord(string WordToReplace, string ReplacedWord)
	{
		return (_Value = ReplacingWord(WordToReplace, ReplacedWord, _Value));
	}

};


