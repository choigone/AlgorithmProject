//
// Created by Goun Choi on 2019-05-31.
//

#include "Search.h"

Search::Search(Datas d) {
	this->data = d;
}

void Search::search() {
	for (int i = 0; i < data.getArticles().size(); i++) {
		kmp.setText(data.getArticles()[i]);
		if (kmp.kmpSearch()) {
			this->result.push_back(make_pair(-1, data.getArticles()[i]));
		}
	}
}

void Search::getTarget() {
	void keywordInputPage1();
	//cout << "\n�˻��� ���ڿ��� �Է��ϼ��� : ";
	string temp;
	cin >> temp;
	kmp.setTarget(temp);
}

vector<pair<double,string>> Search::getResult() {
	return result;
}

void Search::printResult() {
	//void keywordInputPage2();
	for (int i = 0; i < result.size(); i++) {
		cout << "        "<<i+1<<". "<<result[i].second << endl;
	}
}