//
// Created by Goun Choi on 2019-06-05.
//

#include "Levenshtein.h"

bool CompareSimil(const similText& x, const similText& y) {
    return x.similarity > y.similarity;
}

Levenshtein::Levenshtein(vector<similText> text)
{
    this->text = text;
}

void Levenshtein::preprocess(string & text)
{
    for (int i = 0; CHARS_TO_REMOVE[i]; ++i) {
        text.erase(
                remove(text.begin(), text.end(), CHARS_TO_REMOVE[i]),
                text.end());
    }
    transform(text.begin(), text.end(), text.begin(), tolower);
}

int Levenshtein::levenshtein(string & input1, string & input2)
{
    int dist[1001][1001];

    for (int i = 1; i <= input1.length(); i++)
        dist[i][0] = i;
    for (int j = 1; j <= input2.length(); j++)
        dist[0][j] = j;

    for (int j = 1; j <= input2.length(); j++) {
        for (int i = 1; i <= input1.length(); i++) {
            if (input1[i - 1] == input2[j - 1]) dist[i][j] = dist[i - 1][j - 1];
            else dist[i][j] = min(dist[i - 1][j - 1] + 1, min(dist[i][j - 1] + 1, dist[i - 1][j] + 1));
        }
    }
    for (int j = 0; j <= input2.length(); j++) {
        for (int i = 0; i <= input1.length(); i++)
            printf("%d\t", dist[i][j]);
        printf("\n");
    }
    return dist[input1.length()][input2.length()];
}

void Levenshtein::run(int num)
{
    string text1 = text[num].text;
    preprocess(text1);

    int i = 0;

    while (i < text.size()) {
        string text2 = text[i].text;
        preprocess(text2);
        text[i].similarity = 1-(levenshtein(text1, text2)/max(text1.length(),text2.length()));
        i++;
    }
    sort(text.begin(), text.end(), CompareSimil);
}