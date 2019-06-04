//
// Created by Goun Choi on 2019-06-04.
//

#include "Cos.h"

bool CompareSimil(const similText& x, const similText& y) {
    return x.similarity > y.similarity;
}

Cos::Cos(vector<similText> text) {
    this->text = text;
}

void Cos::preprocess(string& text) {
    for (int i = 0; CHARS_TO_REMOVE[i]; ++i) {
        text.erase(
                remove(text.begin(), text.end(), CHARS_TO_REMOVE[i]),
                text.end());
    }
    transform(text.begin(), text.end(), text.begin(), tolower);
}

string* Cos::tokenize(string text, int& size) {
    string* tokens = new string[MAX_TOKENS];
    stringstream stream(text);
    size = 0;
    while (stream.good() && size < MAX_TOKENS) {
        stream >> tokens[size++];
    }
    return tokens;
}

bool Cos::inArray(string str, string* strArray, int strArraySize) {
    for (int i = 0; i < strArraySize; ++i) {
        if (str == strArray[i]) {
            return true;
        }
    }
    return false;
}

int Cos::frequency(string token, string* tokens, int tokensSize) {
    int freq = 0;
    for (int i = 0; i < tokensSize; ++i) {
        if (token == tokens[i]) {
            ++freq;
        }
    }
    return freq;
}

int Cos::dotProduct(int* v1, int* v2, int size) {
    int prod = 0;
    for (int i = 0; i < size; ++i) {
        prod += v1[i] * v2[i];
    }
    return prod;
}

double Cos::magnitude(int* v, int size) {
    return sqrt(dotProduct(v, v, size));
}

double Cos::cosineSimilarity(string* tokens1, int tokens1Size,
                             string* tokens2, int tokens2Size) {
    string* distinctTokens = new string[tokens1Size + tokens2Size];
    int distinctTokensSize = 0;
    for (int i = 0; i < tokens1Size; ++i) {
        if (!inArray(tokens1[i], distinctTokens, distinctTokensSize)) {
            distinctTokens[distinctTokensSize++] = tokens1[i];
        }
    }
    for (int i = 0; i < tokens2Size; ++i) {
        if (!inArray(tokens2[i], distinctTokens, distinctTokensSize)) {
            distinctTokens[distinctTokensSize++] = tokens2[i];
        }
    }
    int* frequencies1 = new int[distinctTokensSize];
    int* frequencies2 = new int[distinctTokensSize];
    for (int i = 0; i < distinctTokensSize; ++i) {
        frequencies1[i] = frequency(distinctTokens[i], tokens1, tokens1Size);
        frequencies2[i] = frequency(distinctTokens[i], tokens2, tokens2Size);
    }
    delete[] distinctTokens;
    double sim = dotProduct(
            frequencies1, frequencies2, distinctTokensSize) /
                 (magnitude(frequencies1, distinctTokensSize) *
                  magnitude(frequencies2, distinctTokensSize));
    delete[] frequencies1;
    delete[] frequencies2;
    return sim;
}

void Cos::run(int num){
    string text1 = text[num].text;
    preprocess(text1);
    int tokens1Size;
    string* tokens1 = tokenize(text1, tokens1Size);
    int i = 0;

    while (i < text.size()) {
        string text2 = text[i].text;
        preprocess(text2);
        int tokens2Size;
        string* tokens2 = tokenize(text2, tokens2Size);
        text[i].similarity = cosineSimilarity(tokens1, tokens1Size, tokens2, tokens2Size);
        i++;
    }
    sort(text.begin(), text.end(), CompareSimil);
}