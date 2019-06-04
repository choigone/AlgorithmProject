//
// Created by Goun Choi on 2019-05-31.
//

#include "Datas.h"

void Datas::setArticles(string str) {
    this->articles.push_back(str);
}

vector<string> Datas::getArticles() {
    return articles;
}