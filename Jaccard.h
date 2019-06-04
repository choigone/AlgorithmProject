//
// Created by Goun Choi on 2019-06-04.
//

#ifndef PROJECT_JACCARD_H
#define PROJECT_JACCARD_H

#include "utility.h"

class Jaccard {
    vector<similText> text;
public:
    Jaccard(vector<similText> text);
    void preprocess(string& text);
    int jaccard(string str1, string str2);
    void run(int num);
    void removeTemp();
    string getStrCutByLength(string str, int maxLength);
};

#endif //PROJECT_JACCARD_H
