#ifndef TAXES_EXAM_COMPANY_H
#define TAXES_EXAM_COMPANY_H
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Company {

private:
    string name;
    string nip;

public:
    Company() = default;
    ~Company() = default;

    bool checkNip(string nip_number);

    const string &getName() const;
    const string &getNip() const;

    void setName(const string &name_num);
    void setNip(const string &nip);
};

bool Company::checkNip(string nip_number) {
    int sum = 0;

    sum += (nip_number[0] - '0') * 6;
    sum += (nip_number[1] - '0') * 5;
    sum += (nip_number[2] - '0') * 7;
    sum += (nip_number[3] - '0') * 2;
    sum += (nip_number[4] - '0') * 3;
    sum += (nip_number[5] - '0') * 4;
    sum += (nip_number[6] - '0') * 5;
    sum += (nip_number[7] - '0') * 6;
    sum += (nip_number[8] - '0') * 7;

    return sum % 11 != 10;
}

void Company::setName(const string &name_num) {
    Company::name = name_num;
}

void Company::setNip(const string &nip_num) {
    if ( checkNip(nip_num) ) {
        Company::nip = nip_num;
    }
}

const string &Company::getName() const {
    return name;
}

const string &Company::getNip() const {
    return nip;
}

ostream &operator<<(ostream &os, Company &f) {
    os << f.getName();

    return os;
}

#endif
