//This is my main function
// Created by OmarB on 9/28/2019.

#ifndef CS236_PROJECT_02_MAIN_H
#define CS236_PROJECT_02_MAIN_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

enum state_machine {comma=0, period=1, q_mark=2, left_paren=3, right_paren=4, colon=5, colon_dash=6, multiply=7,
        add=8, schemes=9, facts=10, rules=11, queries=12, s_id=13, s_string=14, comment=15, s_undef=16, e_o_f=17};

const string queries_s = "Queries";
const string schemes_s = "Schemes";
const string facts_s = "Facts";
const string rules_s = "Rules";

bool decide_machine(char, state_machine&);
bool decide_id_or_und(char, state_machine&);
bool id_state1(char);
bool finishes_1_step(state_machine&);
bool is_it_keyid(string);

void tokenizing_state_machine(ifstream&,vector<string>&, vector<string>&, vector<int>&);
void push_to_input_vectors(string, string, int, vector<string>&, vector<string>&, vector<int>&);

void dataLogProgram(vector<string>&, vector<string>&, vector<int>&);
void scheme(int&, vector<string>&, vector<string>&, vector<int>&);
bool does_token_match(string, const string[], int);

//declaring first sets
const string dP_first = "SCHEMES";
const string schL_first[2]= {"ID", ""};
const string fctL_first[2]= {"ID", ""};
const string rlL_first[2]= {"ID", ""};
const string qryL_first[2]= {"ID", ""};
const string sch_first = "ID";
const string fct_first = "ID";
const string rl_first = "ID";
const string qry_first = "ID";
const string hPd_first = "ID";
const string pd_first = "ID";
const string pdL_first[2] = {"COMMA",""};
const string prmtL_first[2] = {"COMMA",""};
const string strL_first[2] = {"COMMA",""};
const string idL_first[2] = {"COMMA",""};
const string prmt_first[3] = {"STRING","ID","LEFT_PAREN"};
const string exp_first = "LEFT_PAREN";
const string opt_first[2] = {"ADD","MULTIPLY"};

//declaring follow sets
const string dP_follow = "EOF";
const string schL_follow[15]= {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                         "MULTIPLY","ADD","FACTS","RULES","QUERIES","ID","STRING","EOF"};
const string fctL_follow[14]= {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                         "MULTIPLY","ADD","RULES","QUERIES","ID","STRING","EOF"};
const string rlL_follow[11]= {"COMMA","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","MULTIPLY","ADD",
                        "QUERIES","ID","STRING","EOF"};
const string qryL_follow= "EOF";
const string sch_follow[15] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                         "MULTIPLY","ADD","FACTS","RULES","QUERIES","ID","STRING","EOF"};
const string fct_follow[14] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                         "MULTIPLY","ADD","RULES","QUERIES","ID","STRING","EOF"};
const string rl_follow[11] = {"COMMA","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","MULTIPLY","ADD",
                        "QUERIES","ID","STRING","EOF"};
const string qry_follow[9] = {"COMMA","Q_MARK","LEFT_PAREN","RIGHT_PAREN","MULTIPLY","ADD","ID","STRING","EOF"};
const string hPd_follow[13] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                         "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
const string pd_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                        "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
const string pdL_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                         "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
const string prmtL_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                           "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
const string strL_follow[14] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                          "MULTIPLY","ADD","RULES","QUERIES","ID","STRING","EOF"};
const string idL_follow[15]= {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                        "MULTIPLY","ADD","FACTS","RULES","QUERIES","ID","STRING","EOF"};
const string prmt_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                          "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
const string exp_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                         "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
const string opt_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                         "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};

#endif //CS236_PROJECT_02_MAIN_H
