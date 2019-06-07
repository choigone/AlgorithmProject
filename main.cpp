
#include "Datas.h"
#include "Cos.h"
#include "Jaccard.h"
#include "Levenshtein.h"
#include "UI.h"
#include "Search.h"

#define FILENAME "D:/3�г�1�б�/�ľ�/������Ʈ/Project/Project/input.txt"
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
	cout << "������ ���� �Ϳ� �����Ͽ����ϴ�.";
	while (!in.eof()) {
		getline(in, buf);
		data.setArticles(buf);
	}

	//Start_menu(); //ùȭ��
	Search search = Search(data);
	search.getTarget();
	//void keywordInputPage2();
	search.search();
	search.printResult();

	//TODO �̺κе� � �Լ��� �ִ� �� ���ڴµ�..?!
	int num;
	cout << "�� ����� ��ȣ : ";
	cin >> num;

	//�� �˰��� -> ������ �Ű����� : search.getResult();
	//TODO ��� ����ϴ� �͵� �ڵ� �ۼ��ؼ� �߰��ؾ� �� !
	Cos cosAlgo = Cos(search.getResult());
	cosAlgo.run(num);

	Jaccard jaccardAlgo = Jaccard(search.getResult());
	jaccardAlgo.run(num);

	Levenshtein levenshAlgo = Levenshtein(search.getResult());
	levenshAlgo.run(num);

	system("pause");
	return 0;
}