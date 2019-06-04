//
// Created by Goun Choi on 2019-05-31.
//

#include "KMP.h"

KMP::KMP(string text, string target) {
    this->text = text;
    this->target = target;
}

void KMP::setText(string text) {
    this->text = text;
}

int KMP::initSP(string target) {
    int count = 0;
    int i,j,m = target.length();
    SP = new int[m];
    SP[0] = -1;
    for(i=1,j=-1;i<=m-1;i++){
        count++;
        while((j>=0)&&(target[j+1]!=target[j])){
            count++;
            j = SP[j];
        }
        count++;
        if(target[j+1]==target[i]){
            j++;
        }
        SP[i]=j;
    }
    return count;
}

int KMP::kmpSearch() {
    int count=0;
    int i,j,m = target.length(),n = text.length();
    count = initSP(target);
    for(i=0,j=-1;i<=n-1;i++){
        count++;
        while((j>=0)&&(target[j+1]!=text[i])){
            count++;
            j = SP[j];
        }
        count++;
        if(target[j+1] == text[i]){
            j++;
        }

        if(j==m-1) return 1;
        else return 0;
//            (i-j);
//            j = SP[j];

    }
}