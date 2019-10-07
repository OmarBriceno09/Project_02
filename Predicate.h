//
// Created by OmarB on 10/7/2019.
//

#ifndef PROJECT_02_PREDICATE_H
#define PROJECT_02_PREDICATE_H
#include <fstream>
#include <vector>
#include "Parameter.h"
using namespace std;

//ID LEFT_PAREN parameter parameterList RIGHT_PAREN
class Predicate {
public:
    Predicate(int &tk_num, vector<string> &, vector<string> &, vector<int> &);
    ~Predicate();

    string id="";
    vector <string> the_parameter_list;

    string return_the_predicate();

private:
    string predicate_string = "";

    void the_predicate(int &tk_num, vector<string> &, vector<string> &, vector<int> &);
    void parameterList(int&, vector<string>&, vector<string>&, vector<int>&);

    bool does_token_match(string, const string[], int);

    const string pd_first = "ID";
    const string prmtL_first[2] = {"COMMA",""};

    const string prmtL_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                                     "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
};


#endif //PROJECT_02_PREDICATE_H
