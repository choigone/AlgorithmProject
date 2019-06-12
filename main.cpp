#include "Datas.h"
#include "Cos.h"
#include "Jaccard.h"
#include "Levenshtein.h"
#include "UI.h"
#include "Search.h"

#define FILENAME "input.txt"
using namespace std;

int main() {
	ifstream in;
	in.open(FILENAME);
	Datas data = Datas();
	string buf;
	if (!in.is_open()) {
		cout << "������ �� �� �����ϴ�.";
		exit(1);
	}
	//cout << "������ ���� �Ϳ� �����Ͽ����ϴ�.";
	while (!in.eof()) {
		getline(in, buf);
		data.setArticles(buf);
	}

	Start_menu(); //ùȭ��
	Search search = Search(data);
	search.getTarget();
	search.search();

	keywordInputPage2();
	search.printResult();

	//TODO �̺κе� � �Լ��� �ִ� �� ���ڴµ�..?!
	int num;
	cout << endl;
	cout << "       ������������������������������������������������������������������������" << endl;
	cout << "        ���� ����� ��ȣ�� �Է��ϼ���! : ";
	cin >> num;
	system("cls");

	//�� �˰��� -> ������ �Ű����� : search.getResult();
	//TODO ��� ����ϴ� �͵� �ڵ� �ۼ��ؼ� �߰��ؾ� �� !
	Cos cosAlgo = Cos(search.getResult());
	cosAlgo.run(num-1);
	cosAlgo.getVector();

	Jaccard jaccardAlgo = Jaccard(search.getResult());
	jaccardAlgo.run(num-1);
	jaccardAlgo.getVector();

	Levenshtein levenshAlgo = Levenshtein(search.getResult());
	levenshAlgo.run(num-1);
	levenshAlgo.getVector(); 

	system("pause");
	return 0;
}