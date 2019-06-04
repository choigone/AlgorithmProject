//
// Created by Goun Choi on 2019-05-31.
//

#ifndef PROJECT_KMP_H
#define PROJECT_KMP_H

#include "utility.h"

class KMP{
private:
    string text;
    string target;
    int *SP;
public:
    KMP(string text,string target);
    void setText(string text);
    int initSP(string target);
    int kmpSearch();
};

#endif //PROJECT_KMP_H
