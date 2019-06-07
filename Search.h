#include "Datas.h"
#include "KMP.h"

class Search {
private:
	Datas data;
	string target;
	vector<pair<double, string>> result;
	KMP kmp = KMP("",target);
public:
	Search(Datas d);
	void search();
	void getTarget();
	vector<pair<double, string>> getResult();
	void printResult();
};
