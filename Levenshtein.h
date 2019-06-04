//
// Created by Goun Choi on 2019-06-05.
//

#ifndef PROJECT_LEVENSHTEIN_H
#define PROJECT_LEVENSHTEIN_H

#include "utility.h"

class Levenshtein {
    vector<similText> text;
public:
    Levenshtein(vector<similText> text);
    void preprocess(string& text);
    int levenshtein(string& input1, string& input2);
    void run(int num);
};

#endif //PROJECT_LEVENSHTEIN_H
