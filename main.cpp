#include "List.h"
#include "Company.h"
#include <fstream>

int main() {
    ifstream input;

    ofstream piotrkow;
    ofstream tomaszow;
    ofstream radom;

    piotrkow.open("piotrkow.txt", ios::trunc);
    tomaszow.open("tomaszow.txt", ios::trunc);
    radom.open("radom.txt", ios::trunc);

    input.open("nipy.txt");

    while ( !input.eof() ) {
        string name_str;
        string nip_str;
        string irs_str;
        string whole_line;

        getline(input, whole_line);
        for ( int i = 0; i < whole_line.length() - 1; ++i ) {
            // forming nip
            if ( i < 9 ) {
                nip_str += whole_line[i];
            }
            // forming name
            if (i >= 9 ) {
                name_str += whole_line[i];
            }
        }

        Company current_company;
        try {
            current_company.setNip(nip_str);
            current_company.setName(name_str);
        }
        catch (const logic_error &err) {
            cout << err.what() << endl;
        }

        LinkedList<Company> List;
        List.push(current_company);

        while ( List.counter != 0 ) {
            Company to_assign = List.pop();
            string to_check = to_assign.getNip();
            to_check = to_check.substr(0,3);

            if ( to_check == "771" ) {
                piotrkow << to_assign.getNip() << to_assign.getName() << endl;
            }
            else if ( to_check == "772" ) {
                radom << to_assign.getNip() << to_assign.getName() << endl;
            }
            else if ( to_check == "773" ) {
                tomaszow << to_assign.getNip() << to_assign.getName() << endl;
            }
            else {
                cout << "None" << endl;
            }
        }

    }

    piotrkow.close();
    radom.close();
    tomaszow.close();

    return 0;
}