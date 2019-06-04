//
// Created by Goun Choi on 2019-05-31.
//

#ifndef PROJECT_SEARCH_H
#define PROJECT_SEARCH_H

#include "utility.h"
#include "KMP.h"
#include "Datas.h"

class Search{
private:
    Datas data;
    string target;
    vector<similText> result;
    KMP kmp = KMP(NULL,target);
public:
    Search(Datas d);
    void search();
    void getTarget();
    vector<similText> getResult();
    void printResult();
};

#endif //PROJECT_SEARCH_H
