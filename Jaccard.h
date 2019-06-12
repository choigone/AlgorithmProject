//
// Created by Goun Choi on 2019-06-04.
//

#ifndef PROJECT_JACCARD_H
#define PROJECT_JACCARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <functional>
using namespace std;

class Jaccard {
	vector<pair<double, string>> text;
public:
	const char* CHARS_TO_REMOVE2 = ".,:;\"()";
	Jaccard(vector<pair<double, string>> text);
	void preprocess(string& text);
	double jaccard(string str1, string str2);
	void run(int num);
	void removeTemp(string& str);
	string getStrCutByLength(string str, int maxLength);
	void getVector();
};

#endif //PROJECT_JACCARD_H
