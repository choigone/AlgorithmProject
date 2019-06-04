//
// Created by Goun Choi on 2019-05-31.
//

#include "Search.h"

Search::Search(Datas d) {
    this->data = d;
}

void Search::search() {
    similText temp;
    temp.similarity = -1;
    for(int i=0;i<data.getArticles().size();i++){
        kmp.setText(data.getArticles()[i]);
        if(kmp.kmpSearch()){
            temp.text = data.getArticles()[i];
            this->result.push_back(temp);
        }
    }
}

void Search::getTarget() {
    cout << "검색할 문자열을 입력하세요 : ";
    cin >> this->target;
}

vector<similText> Search::getResult() {
    return result;
}

void Search::printResult() {
    for(int i=0;i<result.size();i++){
        cout << result[i].text << endl;
    }
}