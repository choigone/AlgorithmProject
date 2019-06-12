//
// Created by Goun Choi on 2019-06-05.
//

#include "Levenshtein.h"
#include<iomanip>

Levenshtein::Levenshtein(vector<pair<double, string>> text)
{
	this->text = text;
}

void Levenshtein::preprocess(string & text)
{
	for (int i = 0; CHARS_TO_REMOVE1[i]; ++i) {
		text.erase(remove(text.begin(), text.end(), CHARS_TO_REMOVE1[i]), text.end());
	}
	transform(text.begin(), text.end(), text.begin(), tolower);
}

int Levenshtein::levenshtein(string& input1, string& input2)
{
	for (int i = 1; i <= input1.length(); i++)
		dist[i][0] = i;
	for (int j = 1; j <= input2.length(); j++)
		dist[0][j] = j;

	for (int j = 1; j <= input2.length(); j++) {
		for (int i = 1; i <= input1.length(); i++) {
			if (input1[i - 1] == input2[j - 1]) dist[i][j] = dist[i - 1][j - 1];
			else dist[i][j] = min(dist[i - 1][j - 1] + 1, min(dist[i][j - 1] + 1, dist[i - 1][j] + 1));
		}
	}
	int temp = dist[input1.length()][input2.length()];
	
	return dist[input1.length()][input2.length()];
}

void Levenshtein::run(int num)
{
	string text1 = text[num].second;
	preprocess(text1);

	int i = 0;

	while (i < text.size()) {
		string text2 = text[i].second;
		preprocess(text2);
		text[i].first = 1-((double)levenshtein(text1, text2) / (double)max(text1.length(), text2.length()));
		i++;
	}
	sort(text.begin(), text.end());
}

void Levenshtein::getVector()
{
	cout << "    < Levenshtein distance >" << endl<<endl;
	for (int i = text.size()-2; i >=0; i--)
	{
		cout << setw(10) << left << text[i].first;
		cout << text[i].second << endl;
		//cout << "    " << text[i].second << endl<<text[i].first<<endl;
	}
	cout << endl << endl;
}