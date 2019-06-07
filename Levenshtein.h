//
// Created by Goun Choi on 2019-06-05.
//

#ifndef PROJECT_LEVENSHTEIN_H
#define PROJECT_LEVENSHTEIN_H

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

class Levenshtein {
	vector<pair<double, string>> text;
public:
	const char* CHARS_TO_REMOVE1 = ".,:;\"()";
	Levenshtein(vector<pair<double, string>> text);
	void preprocess(string& text);
	int levenshtein(string& input1, string& input2);
	void run(int num);
};

#endif //PROJECT_LEVENSHTEIN_H
