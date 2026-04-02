#include <bits/stdc++.h>
using namespace std;

struct Student
{
    char name[256];
    int score;
};

bool cmp(struct Student* a , struct Student* b)
{
    return a->score > b->score;
};


int main(){
    vector<struct Student*> students;

    sort(students.begin() , students.end() , cmp);

    return 0;
}