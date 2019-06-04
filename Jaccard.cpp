//
// Created by Goun Choi on 2019-06-04.
//

#include "Jaccard.h"

bool CompareSimil(const similText& x, const similText& y) {
    return x.similarity > y.similarity;
}

Jaccard::Jaccard(vector<similText> text)
{
    this->text = text;
}

void Jaccard::preprocess(string & text)
{
    for (int i = 0; CHARS_TO_REMOVE[i]; ++i) {
        text.erase(
                remove(text.begin(), text.end(), CHARS_TO_REMOVE[i]),
                text.end());
    }
    transform(text.begin(), text.end(), text.begin(), tolower);
}

void Jaccard::removeTemp() {
    string temp;
    for(int i=0;i<text.size();i++){
        (text[i].text).erase(remove_if((text[i].text).begin(), (text[i].text).end(), isspace), (text[i].text).end());
    }
}

string getStrCutByLength(string str, int maxLength){ // 잘라낼 문자열 및 반환받을 "절대 길이"를 인자로 가져옴.{
    auto itr = str.begin();
    if(str.length() > (maxLength * 3)) // 이 안에 들어간다면 2바이트 이상을 가진 문자가 문자열에 포함되어 있다.
    {
        int len = 0;
        while(itr != str.end())
        {
            if( len > (maxLength * 2) - 1 ) // 한글을 2바이트로 취급하고 싶으니까 * 2 로 확인
            {
                return str.substr(0, std::distance(str.begin(),itr)); // 받아온 절대 길이만큼 잘라내고 뒤에 ...을 붙인 뒤 반환
            }

            unsigned char c = *itr; // 음수 제거

            if( c > 128 ) // 아스키 기본 표현값을 벗어날 경우
            {
                itr += 2; // 2바이트 뒤로 넘기면서
                ++len; // 길이값을 1 늘림.
            }

            ++itr; // 그 외에도 1바이트 뒤로 넘기면서 (위에서 걸렸으면 총 3바이트)
            ++len; // 길이값을 1 더
        }

    }

    return str;
}
//두 단어씩 쪼개서 vector에 저장하기

//합집합과 교집합 구해서 유사도 저장
int Jaccard::jaccard(string str1, string str2) {
    vector<string> strSet1;
    vector<string> strSet2;
    vector<string> unionSet;

    string temp;
    for(int i=0;i<str1.length()/3 - 1;i++){
        temp = getStrCutByLength(str1.substr(i*3),2);
        strSet1.push_back(temp);
        cout << temp << " ";
    }

    for(int i=0;i<str2.length()/3 - 1;i++){
        temp = getStrCutByLength(str2.substr(i*3),2);
        strSet2.push_back(temp);
        cout << temp << " ";
    }

    int unionNum = 0;     // 합집합 개수
    int intersectionNum = 0;  // 교집합 개수

    for (int i = 0; i < (int)str1.size(); i++) {
        if (strSet1[i] != "") unionNum++; // str1의 원소개수 미리 체크(합집합 개수에 사용)
    }

    for (int i = 0; i < (int)str2.size(); i++) {
        for (int j = 0; j < (int)str1.size(); j++) {
            if ((!strcmp(strSet1[j].c_str(), strSet2[i].c_str())) && (strSet1[j] != "")) { // 교집합 개수 체크
                strSet1[j] = "X"; // 한번 체크한 문자열은 X로 만들어 또 체크하지 않도록 함
                intersectionNum++;
                break;
            }
            else if (j == ((int)str1.size() - 1) && (strSet2[i] != "")) unionNum++; // 합집합 개수 체크
        }
    }
    cout << "\n합집합 수 : " << unionNum << " 교집합 수 : " << intersectionNum << endl;

}

//int Jaccard::jaccard(string str1, string str2)
//{
//    int answer = 0;
//    vector <string> devideStr1(str1.size());
//    vector <string> devideStr2(str2.size());
//
//    // 1. 문자열 두개씩 쪼개기 단, 모두 숫자여야 저장
//    int saveNum = 0;
//    for (int i = 0; i < (int)str1.size() - 1; i++) {
//        char temp[3] = { 0, };
//        temp[0] = str1[i];
//        temp[1] = str1[i + 1];
//
//        if (((temp[0] >= 'A' && temp[0] <= 'Z') || (temp[0] >= 'a' && temp[0] <= 'z'))
//            && ((temp[1] >= 'A' && temp[1] <= 'Z') || (temp[1] >= 'a' && temp[1] <= 'z'))) devideStr1[saveNum++] = temp;
//    }
//
//    saveNum = 0;
//    for (int i = 0; i < (int)str2.size() - 1; i++) {
//        char temp[3] = { 0, };
//        temp[0] = str2[i];
//        temp[1] = str2[i + 1];
//
//        if (((temp[0] >= 'A' && temp[0] <= 'Z') || (temp[0] >= 'a' && temp[0] <= 'z'))
//            && ((temp[1] >= 'A' && temp[1] <= 'Z') || (temp[1] >= 'a' && temp[1] <= 'z'))) devideStr2[saveNum++] = temp;
//    }
//
//    cout << "str1 쪼갠거 : ";
//    for (int i = 0; i < (int)str1.size(); i++) cout << devideStr1[i] << "  ";
//    cout << "\nstr2 쪼갠거 : ";
//    for (int i = 0; i < (int)str2.size(); i++) cout << devideStr2[i] << "  ";
//
//    // 2. 합집합, 교집합 체크
//    int unionNum = 0;     // 합집합 개수
//    int intersectionNum = 0;  // 교집합 개수
//
//    for (int i = 0; i < (int)str1.size(); i++) {
//        if (devideStr1[i] != "") unionNum++; // str1의 원소개수 미리 체크(합집합 개수에 사용)
//    }
//
//    for (int i = 0; i < (int)str2.size(); i++) {
//        for (int j = 0; j < (int)str1.size(); j++) {
//            if ((!_stricmp(devideStr1[j].c_str(), devideStr2[i].c_str())) && (devideStr1[j] != "")) { // 교집합 개수 체크
//                devideStr1[j] = "X"; // 한번 체크한 문자열은 X로 만들어 또 체크하지 않도록 함
//                intersectionNum++;
//                break;
//            }
//            else if (j == ((int)str1.size() - 1) && (devideStr2[i] != "")) unionNum++; // 합집합 개수 체크
//        }
//    }
//
//    cout << "\n합집합 수 : " << unionNum << " 교집합 수 : " << intersectionNum << endl;
//
//    // 3. 결과 출력(자카드 유사도)
//    float tempAnswer = 0;
//    if (intersectionNum == 0 && unionNum == 0) tempAnswer = 1;
//    else tempAnswer = (float)intersectionNum / unionNum;
//
//    answer = (int)(tempAnswer * 65536);
//    return answer;
//}

void Jaccard::run(int num)
{
    string text1 = text[num].text;
    preprocess(text1);
    removeTemp();

    int i = 0;

    while (i < text.size()) {
        string text2 = text[i].text;
        preprocess(text2);
        text[i].similarity = jaccard(text1, text2);
        i++;
    }
    sort(text.begin(), text.end(), CompareSimil);
}