#include "utility.h"

int main() {
    ifstream in;
    in.open(FILENAME);
    Datas data;

    string buf;
    if(!in.is_open()){
        cout << "파일을 열 수 없습니다.";
        exit(1);
    }
    while(!in.eof()){
        getline(in,buf);
        data.setArticles(buf);
    }

    return 0;
}