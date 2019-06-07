//
// Created by Goun Choi on 2019-05-31.
//

#ifndef PROJECT_KMP_H
#define PROJECT_KMP_H

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
class KMP {
private:
	string text;
	string target;
	int *SP;
public:
	KMP(string text, string target);
	void setText(string text);
	void setTarget(string target);
	int initSP(string target);
	int kmpSearch();
};

#endif //PROJECT_KMP_H
