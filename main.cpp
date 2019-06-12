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
		cout << "파일을 열 수 없습니다.";
		exit(1);
	}
	//cout << "파일을 여는 것에 성공하였습니다.";
	while (!in.eof()) {
		getline(in, buf);
		data.setArticles(buf);
	}

	Start_menu(); //첫화면
	Search search = Search(data);
	search.getTarget();
	search.search();

	keywordInputPage2();
	search.printResult();

	//TODO 이부분도 어떤 함수에 넣는 게 낫겠는데..?!
	int num;
	cout << endl;
	cout << "       ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "        읽을 기사의 번호를 입력하세요! : ";
	cin >> num;
	system("cls");

	//각 알고리즘 -> 생성자 매개변수 : search.getResult();
	//TODO 결과 출력하는 것도 코드 작성해서 추가해야 함 !
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