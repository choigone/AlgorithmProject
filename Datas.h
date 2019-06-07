//
// Created by Goun Choi on 2019-05-31.
//

#ifndef PROJECT_DATAS_H
#define PROJECT_DATAS_H

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

class Datas {
private:
	vector<string> articles;
public:
	void setArticles(string str);
	vector<string> getArticles();
};

#endif //PROJECT_DATAS_H
