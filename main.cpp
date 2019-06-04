#include "utility.h"
#include "Datas.h"
#include "Search.h"
#include "Cos.h"

int main() {
    ifstream in;
    in.open(FILENAME);
    Datas data;

    string buf;
    if(!in.is_open()){
        cout << "파일을 열 수 없습니다.";
        exit(1);
    }
    cout << "파일을 여는 것에 성공하였습니다.";
    while(!in.eof()){
        getline(in,buf);
        data.setArticles(buf);
    }

    Search search = Search(data);
    search.getTarget();
    search.search();
    search.printResult();

    //각 알고리즘 -> 생성자 매개변수 : search.getResult();
    Cos cosAlgo = Cos(search.getResult());
    //TODO 이부분도 어떤 함수에 넣는 게 낫겠는데..?!
    int num;
    cout << "볼 기사의 번호 : ";
    cin >> num;
    cosAlgo.run(num);




    return 0;
}