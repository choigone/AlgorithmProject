//
// Created by Goun Choi on 2019-06-04.
//

#include "Jaccard.h"
#include<iomanip>
Jaccard::Jaccard(vector<pair<double, string>> text)
{
	this->text = text;
}

void Jaccard::preprocess(string & text)
{
	for (int i = 0; CHARS_TO_REMOVE2[i]; ++i) {
		text.erase(remove(text.begin(), text.end(), CHARS_TO_REMOVE2[i]), text.end());
	}
	transform(text.begin(), text.end(), text.begin(), tolower);
}

//void Jaccard::removeTemp(string str) {
//   str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
//}

void Jaccard::removeTemp(string& str) {
	string newString = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str.erase(i, 1);
		}
	}
}

string Jaccard::getStrCutByLength(string str, int maxLength) { // 잘라낼 문자열 및 반환받을 "절대 길이"를 인자로 가져옴.
	auto itr = str.begin();
	if (str.length() > (maxLength * 3)) // 이 안에 들어간다면 2바이트 이상을 가진 문자가 문자열에 포함되어 있다.
	{
		int len = 0;
		while (itr != str.end())
		{
			if (len > (maxLength * 2) - 1) // 한글을 2바이트로 취급하고 싶으니까 * 2 로 확인
			{
				return str.substr(0, std::distance(str.begin(), itr)); // 받아온 절대 길이만큼 잘라내고 뒤에 ...을 붙인 뒤 반환
			}

			unsigned char c = *itr; // 음수 제거

			if (c > 128) // 아스키 기본 표현값을 벗어날 경우
			{
				itr += 2; // 2바이트 뒤로 넘기면서
				++len; // 길이값을 1 늘림.
			}

			++itr; // 그 외에도 1바이트 뒤로 넘기면서 (위에서 걸렸으면 총 3바이트)
			++len; // 길이값을 1 더
		}

	}

	return str;
}

//int Jaccard::jaccard(string str1, string str2) {
//   removeTemp(str1);
//   vector<string> strSet1;
//   vector<string> strSet2;
//   vector<string> unionSet;
//   vector<string> interSet;
//
//   string temp;
//   cout << temp;
//   for (int i = 0; i < str1.length() / 3 - 1; i++) {
//      temp = getStrCutByLength(str1.substr(i * 3), 2);
//      strSet1.push_back(temp);
//   }
//
//   for (int i = 0; i < str2.length() / 3 - 1; i++) {
//      temp = getStrCutByLength(str2.substr(i * 3), 2);
//      strSet2.push_back(temp);
//   }
//
//   for (int i = 0; i < strSet1.size(); i++) {
//      for (int j = 0; j < strSet2.size(); j++) {
//         if (strSet1[i] == strSet2[j]) interSet.push_back(strSet2[j]);
//      }
//   }
//   unionSet.insert(unionSet.end(), strSet1.begin(), strSet1.end());
//   unionSet.insert(unionSet.end(), strSet2.begin(), strSet2.end());
//
//   unionSet.erase(unique(unionSet.begin(), unionSet.end()), unionSet.end());
//   interSet.erase(unique(interSet.begin(), interSet.end()), interSet.end());
//
//   return interSet.size() / unionSet.size();
//
//}

double Jaccard::jaccard(string str1, string str2) {
	removeTemp(str1);
	removeTemp(str2);
	vector<string> strSet1;
	vector<string> strSet2;
	vector<string> unionSet;
	vector<string> interSet;

	int count = 0;
	int flag = 0;
	string temp = "";

	for (int i = 0; i < str1.length(); ) {
		if (str1[i] >> 7) {
			temp += str1.substr(i, 3);
			i += 3;
			count++;
			flag = 3;
		}
		else {
			temp += str1.substr(i, 1);
			i++;
			count++;
			flag = 1;
		}
		if (count == 2) {
			strSet1.push_back(temp);
			temp = "";
			count = 0;
			i -= flag;
		}
	}
	count = 0;
	flag = 0;
	temp = "";
	for (int i = 0; i < str2.length(); ) {
		if (str2[i] >> 7) {
			temp += str2.substr(i, 3);
			i += 3;
			count++;
			flag = 3;
		}
		else {
			temp += str2.substr(i, 1);
			i++;
			count++;
			flag = 1;
		}
		if (count == 2) {
			strSet2.push_back(temp);
			temp = "";
			count = 0;
			i -= flag;
		}
	}


	for (int i = 0; i < strSet1.size(); i++) {
		for (int j = 0; j < strSet2.size(); j++) {
			if (strSet1[i] == strSet2[j]) interSet.push_back(strSet2[j]);
		}
	}
	unionSet.insert(unionSet.end(), strSet1.begin(), strSet1.end());
	unionSet.insert(unionSet.end(), strSet2.begin(), strSet2.end());

	sort(unionSet.begin(), unionSet.end());
	unionSet.erase(unique(unionSet.begin(), unionSet.end()), unionSet.end());
	sort(interSet.begin(), interSet.end());
	interSet.erase(unique(interSet.begin(), interSet.end()), interSet.end());

	return (double)interSet.size() / (double)unionSet.size();

}

void Jaccard::run(int num)
{
	string text1 = text[num].second;
	preprocess(text1);

	int i = 0;

	while (i < text.size()) {
		string text2 = text[i].second;
		preprocess(text2);
		text[i].first = jaccard(text1, text2);
		i++;
	}
	sort(text.begin(), text.end());
}

void Jaccard::getVector()
{
	cout << "    < Jaccard similarity >" << endl << endl;
	for (int i = text.size()-2; i >=0; i--)
	{
		cout << setw(10) << left << text[i].first;
		cout << text[i].second << endl;
		//cout << "    " << text[i].second << endl << text[i].first << endl;
	}
	cout << endl << endl;
}