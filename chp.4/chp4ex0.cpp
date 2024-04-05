// chp4ex0.cpp
// �߰����, �⸻���, �׸��� ���� ���� ��� �ް�
// ������ ��� ��� ������ ����ϱ�.
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

// �߰����� ����, �⸻���� ����, ���� ���� ��������
// �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// vector<double>�� �߾Ӱ��� ����.
// �Լ��� ȣ���ϸ� �μ��� ������ ���͸� ��°�� ����
double median(vector<double> vec) {
    // ���� ������ �Է� ������ Ȯ��
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    // ������ ����
    sort(vec.begin(), vec.end());

    // ���� ������ �߾Ӱ��� ����
    vec_sz mid = size / 2;
    return size % 2 == 0
        ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// �߰����� ����, �⸻���� ����, ���� ������ ���ͷ�
// �л��� ���� ������ ����.
// �� �Լ��� �μ��� �����ϱ� �ʰ� median �Լ��� �ش� �۾��� ����.
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
}; //�����ݷ��� ���� �ʵ��� ����

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // �л� �̸��� ��� ������ �о� �����ϰ�
    //���� �� �̸��� ã��
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        //Arron: max(0,5) = 5
        students.push_back(record);
    }

    //�л� ������ ���ĺ� ������ ����
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0;
        i != students.size(); ++i) {
        //�̸��� ������ ������ �����Ͽ� maxlen +1����
        //���ڸ� ���
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');
        // ���� ������ ����� ����
        try {
            double final_grade = grade(students[i]);
            // ����� ���
            streamsize prec = cout.precision(); // ���� cout precision
            cout << "Final grade: " << setprecision(3)
                << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }

    }  //for��

    return 0;
} // main ��