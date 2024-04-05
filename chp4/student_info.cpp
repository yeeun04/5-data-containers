//student_info.cpp
#include "Student_info.h"

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
    //�л� �̸�, �߰���� ����, �⸻��� ���� �о� ����
    is >> s.name >> s.midterm >> s.final;
    // ���� ������ ����
    read_hw(cin, s.homework);
    return is;
}

// �Է� ��Ʈ������ ���� ������ �о vector<double>�� ����.
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // ���� ������ ����
        hw.clear();

        // �Է��� ���� ����
        double x; // cin���� ����ϱ�

        // �Һ���: ���ݱ��� count�� ������ �Է¹޾�����
        // �Է¹��� ������ ���� sum
        while (in >> x) {
            hw.push_back(x);
        }

        // ���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
        in.clear();
        return in;
    }
}