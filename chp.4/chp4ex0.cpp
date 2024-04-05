// chp4ex0.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"


using namespace std;

// 중간시험 점수, 기말시험 점수, 종합 과제 점수에서
// 학생의 종합 점수를 가함
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// vector<double>의 중앙값을 구함.
// 함수를 호출하면 인수로 제공된 백터를 통째로 복사
double median(vector<double> vec) {
    // 과제 점수의 입력 유무를 확인
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    // 점수를 정렬
    sort(vec.begin(), vec.end());

    // 과제 점수의 중앙값을 구함
    vec_sz mid = size / 2;
    return size % 2 == 0
        ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// 중간시험 점수, 기말시험 점수, 과제 점수의 백터로
// 학생의 종합 점수를 가함.
// 이 함수는 인수를 복사하기 않고 median 함수가 해당 작업을 실행.
double grade(double mt, double ft, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("No homework!");

    return grade(mt, ft, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}


struct  Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
}; //세미콜론을 잊지 않도록 주의

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // 학생 이름과 모든 점수를 읽어 저장하고
    //가장 긴 이름을 찾음
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        //Arron: max(0,5) = 5
        students.push_back(record);
    }

    //학생 정보를 알파벳 순으로 정렬
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0;
        i != students.size(); ++i) {
        //이름과 오른쪽 공백을 포함하여 maxlen +1개의
        //문자를 출력
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');
        // 종합 점수를 계산해 생성
        try {
            double final_grade = grade(students[i]);
            // 결과를 출력
            streamsize prec = cout.precision(); // 지금 cout precision
            cout << "Final grade: " << setprecision(3)
                << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }

    }  //for끝

    return 0;
} // main 끝