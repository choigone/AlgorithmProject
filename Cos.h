//
// Created by Goun Choi on 2019-06-04.
//

#ifndef PROJECT_COSALGO_H
#define PROJECT_COSALGO_H

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
const int MAX_STOPWORDS = 200;
const int MAX_TOKENS = 400;
const int MAX_FILES = 300;

class Cos {
	vector<pair<double,string>> text;
public:
	const char* CHARS_TO_REMOVE = ".,:;\"()";
	Cos(vector<pair<double, string>> text);
	void preprocess(string& text);
	string* tokenize(string text, int& size);
	bool inArray(string str, string* strArray, int strArraySize);
	int frequency(string token, string* tokens, int tokensSize);
	int dotProduct(int* v1, int* v2, int size);
	double magnitude(int* v, int size);
	double cosineSimilarity(string* tokens1, int tokens1Size, string* tokens2, int tokens2Size);
	void run(int num);
};

#endif //PROJECT_COSALGO_H
