
#include "Datas.h"
#include "Cos.h"
#include "Jaccard.h"
#include "Levenshtein.h"
#include "UI.h"
#include "Search.h"

#define FILENAME "D:/3학년1학기/컴알/프로젝트/Project/Project/input.txt"
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
	cout << "파일을 여는 것에 성공하였습니다.";
	while (!in.eof()) {
		getline(in, buf);
		data.setArticles(buf);
	}

	//Start_menu(); //첫화면
	Search search = Search(data);
	search.getTarget();
	//void keywordInputPage2();
	search.search();
	search.printResult();

	//TODO 이부분도 어떤 함수에 넣는 게 낫겠는데..?!
	int num;
	cout << "볼 기사의 번호 : ";
	cin >> num;

	//각 알고리즘 -> 생성자 매개변수 : search.getResult();
	//TODO 결과 출력하는 것도 코드 작성해서 추가해야 함 !
	Cos cosAlgo = Cos(search.getResult());
	cosAlgo.run(num);

	Jaccard jaccardAlgo = Jaccard(search.getResult());
	jaccardAlgo.run(num);

	Levenshtein levenshAlgo = Levenshtein(search.getResult());
	levenshAlgo.run(num);

	system("pause");
	return 0;
}