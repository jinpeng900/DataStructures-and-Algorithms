#include<bits/stdc++.h>
using namespace std;

// 普通模式匹配算法
void get_next(string T , int next[]){
    int i = 1 , j = 0;
    next[1] = 0;
    while(i < T.size()){
        if(j == 0 || T[i] == T[j]){
            i++;
            j++;
            next[i] = j;        // 若 pi = pj , 则 next[j+1] = i+1
        }
        else{
            j = next[j];        // 若 pi != pj , 则 j = next[j] , 循环继续
        }
    }
}


// 优化后的 KMP 算法
void get_nextval(string T , int nextval[]){
    int i = 1 , j = 0;
    nextval[1] = 0;
    while(i < T.size()){
        if(j == 0 || T[i] == T[j]){
            i++;
            j++;
            if(T[i] != T[j]){
                nextval[i] = j;
            }
            else{
                nextval[i] = nextval[j];
            }
        }
        else{
            j = nextval[j];
        }
    }
}



int Index_KMP(string S , string T){
    int i = 1 , j = 1;
    int next[T.size() + 1];
    get_next(T , next);
    while(i <= S.size() && j <= T.size()){
        if(j == 0 || S[i] == T[j]){
            i++;
            j++;
        }
        else{
            j = next[j];        // 若 pi != pj , 则 j = next[j] , 循环继续
        }
    }
    if(j > T.size()){
        return i - T.size();
    }
    else{
        return 0;
    }
}
