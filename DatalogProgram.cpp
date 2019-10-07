//
// Created by OmarB on 10/7/2019.
//

#include "DatalogProgram.h"
DatalogProgram::DatalogProgram(vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum) {
    try {
        if (token_type[tk_num] == dP_first) {//tk_num is zero, it has to start at SCHEMES
            out_flow += token_input[tk_num] + "(";//this is were schemes go...
            tk_num++;
            if (token_type[tk_num] == "COLON") {
                scheme_flow += token_input[tk_num];
                tk_num++;
                scheme(tk_num, token_type, token_input, token_linenum);
                schemeList(tk_num, token_type, token_input, token_linenum);
                out_flow += to_string(scheme_count) + ")" + scheme_flow;
                if (token_type[tk_num] == "FACTS") {
                    out_flow += "\n" + token_input[tk_num] + "(";
                    tk_num++;
                    if (token_type[tk_num] == "COLON") {
                        fact_flow += token_input[tk_num]; //begin fact flow
                        tk_num++;
                        factList(tk_num, token_type, token_input, token_linenum);
                        out_flow += to_string(fact_count) + ")" + fact_flow; //append fact flow with nums of facts
                        if (token_type[tk_num] == "RULES") {
                            out_flow += "\n" + token_input[tk_num] + "(";
                            tk_num++;
                            if (token_type[tk_num] == "COLON") {
                                rule_flow += token_input[tk_num]; //begin fact flow
                                tk_num++;
                                ruleList(tk_num, token_type, token_input, token_linenum);
                                out_flow +=
                                        to_string(rule_count) + ")" + rule_flow; //append rule flow with nums of facts
                                if (token_type[tk_num] == "QUERIES") { //QUERIES COLON query queryList
                                    out_flow += "\n" + token_input[tk_num] + "(";
                                    tk_num++;
                                    if (token_type[tk_num] == "COLON") {
                                        query_flow += token_input[tk_num];
                                        tk_num++;
                                        query(tk_num, token_type, token_input, token_linenum);
                                        queryList(tk_num, token_type, token_input, token_linenum);
                                        out_flow += to_string(query_count) + ")" +
                                                    query_flow; //append query flow with nums of facts
                                    } else { throw tk_num; }
                                } else { throw tk_num; }
                            } else { throw tk_num; }
                        } else { throw tk_num; }
                    } else { throw tk_num; }
                } else { throw tk_num; }
            } else { throw tk_num; }
        } else { throw tk_num; }

        the_output = "Success!\n";
        the_output += out_flow;
        sort(domains.begin(), domains.end());
        domains.erase(unique(domains.begin(), domains.end()), domains.end());
        the_output += "\nDomain(" + to_string(domains.size()) + "):";
        for (int i = 0; i < (int) domains.size(); i++) {
            the_output += "\n" + domains[i];
        }
        the_output += "\n";
    }
    catch (int tk_num) {
        the_output = "Failure!\n";
        the_output +=
                "  (" + token_type[tk_num] + ",\"" + token_input[tk_num] + "\"," + to_string(token_linenum[tk_num]) +
                ")";
    }
}

DatalogProgram::~DatalogProgram() {
}

void DatalogProgram::schemeList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum) {
    if (does_token_match(token_type[tk_num], schL_first, 2)) { //if its any first of idList
        if(token_type[tk_num] == "ID"){//do not count token bc line is not passed
            scheme(tk_num,token_type,token_input,token_linenum);
            schemeList(tk_num,token_type,token_input,token_linenum);
        }else {//this is for when it's lambda
            //tk_num++;
        }
    }else if (!does_token_match(token_type[tk_num],schL_follow,15)){
        throw tk_num;
    }
}

void DatalogProgram::factList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if (does_token_match(token_type[tk_num], fctL_first, 2)) { //if its any first of fctList
        if(token_type[tk_num] == "ID"){//do not count token bc line is not passed
            fact(tk_num,token_type,token_input,token_linenum);
            factList(tk_num,token_type,token_input,token_linenum);
        }else {//this is for when it's lambda
            //tk_num++;
        }
    }else if (!does_token_match(token_type[tk_num],fctL_follow,14)){
        throw tk_num;
    }
}

void DatalogProgram::ruleList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if (does_token_match(token_type[tk_num], rlL_first, 2)) { //if its any first of fctList
        if(token_type[tk_num] == "ID"){//do not count token bc line is not passed
            //rule(tk_num,token_type,token_input,token_linenum);
            Rule rule(tk_num,token_type,token_input,token_linenum);    //creating instance of rule
            rule_flow+=rule.out_rule();
            rule_count = rule.get_rule_count();
            //Make rule object here by placing in the inputs-------------------------------------------------------------------
            ruleList(tk_num,token_type,token_input,token_linenum);
        }else {//this is for wh2en it's lambda
            //tk_num++;
        }
    }else if (!does_token_match(token_type[tk_num],rlL_follow,11)){
        throw tk_num;
    }
}

//query queryList | lambda
void DatalogProgram::queryList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if (does_token_match(token_type[tk_num], qryL_first, 2)) { //if its any first of fctList
        if(token_type[tk_num] == "ID"){//do not count token bc line is not passed
            query(tk_num,token_type,token_input,token_linenum);
            queryList(tk_num,token_type,token_input,token_linenum);
        }else {//this is for wh2en it's lambda
            //tk_num++;
        }
    }else if (token_type[tk_num]!=qryL_follow){
        throw tk_num;
    }
}

void DatalogProgram::scheme(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if(token_type[tk_num]==sch_first){ //if its ID
        scheme_flow+="\n  "+token_input[tk_num];
        tk_num++;
        if(token_type[tk_num] == "LEFT_PAREN"){
            scheme_flow+=token_input[tk_num];
            tk_num++;
            if(token_type[tk_num] == "ID"){
                scheme_flow+=token_input[tk_num];
                tk_num++;
                idList(tk_num,token_type,token_input,token_linenum,scheme_flow);
                if(token_type[tk_num] == "RIGHT_PAREN"){
                    scheme_flow+=token_input[tk_num];
                    tk_num++;//here scheme will end
                }else{throw tk_num;}
            }else{throw tk_num;}
        }else{throw tk_num;}
    }else{throw tk_num;}
    scheme_count++;
}

void DatalogProgram::fact(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if(token_type[tk_num]==fct_first) { //if its ID
        fact_flow += "\n  " + token_input[tk_num];
        tk_num++;
        if(token_type[tk_num] == "LEFT_PAREN") {
            fact_flow += token_input[tk_num];
            tk_num++;
            if(token_type[tk_num] == "STRING"){
                fact_flow+=token_input[tk_num];
                domains.push_back(token_input[tk_num]);
                tk_num++;
                stringList(tk_num,token_type,token_input,token_linenum,fact_flow);
                if(token_type[tk_num] == "RIGHT_PAREN"){
                    fact_flow+=token_input[tk_num];
                    tk_num++;
                    if(token_type[tk_num] == "PERIOD"){
                        fact_flow+=token_input[tk_num];
                        tk_num++;//here fact will end
                    }else{throw tk_num;}
                }else{throw tk_num;}
            }else{throw tk_num;}
        }else{throw tk_num;}
    }else{throw tk_num;}
    fact_count++;
}

//predicate Q_MARK
void DatalogProgram::query(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if(token_type[tk_num]==qry_first) { //if its ID
        query_flow += "\n  ";

        Predicate predicate(tk_num,token_type,token_input,token_linenum);
        query_flow += predicate.return_the_predicate();
        if(token_type[tk_num] == "Q_MARK") {
            query_flow += token_input[tk_num];
            tk_num++;
        }else{throw tk_num;}
    }else{throw tk_num;}
    query_count++;
}

//COMMA STRING stringList | lambda
void DatalogProgram::stringList(int &tk_num, vector<string> &token_type, vector<string> &token_input,
                vector<int> &token_linenum, string& curr_out_flow){
    if(does_token_match(token_type[tk_num],strL_first,2)){
        if(token_type[tk_num] == "COMMA"){//first 1
            curr_out_flow+=token_input[tk_num];
            tk_num++;
            if(token_type[tk_num] == "STRING") {//STRING
                curr_out_flow+=token_input[tk_num];
                domains.push_back(token_input[tk_num]);
                tk_num++;
                stringList(tk_num,token_type,token_input,token_linenum, curr_out_flow);
            }else{throw tk_num;}
        }else {//this is for when it's lambda
            //tk_num++;
        }
    }else if(!does_token_match(token_type[tk_num],strL_follow,14)){
        throw tk_num;//if not in follow list throw error
    }
}

void DatalogProgram::idList(int &tk_num, vector<string> &token_type, vector<string> &token_input,
            vector<int> &token_linenum, string& curr_out_flow){
    if(does_token_match(token_type[tk_num],idL_first,2)){ //if its any first of idList
        if(token_type[tk_num] == "COMMA"){//first 1
            curr_out_flow+=token_input[tk_num];
            tk_num++;
            if(token_type[tk_num] == "ID") {//STRING
                curr_out_flow+=token_input[tk_num];
                tk_num++;
                idList(tk_num,token_type,token_input,token_linenum, curr_out_flow);
            }else{throw tk_num;}
        }else {//this is for when it's lambda
            //tk_num++;
        }
    }else if(!does_token_match(token_type[tk_num],idL_follow,15)){
        throw tk_num;//if not in follow list throw error
    }
}

bool DatalogProgram::does_token_match(string token, const string the_list[], int list_size){
    for(int i=0; i<list_size; i++){
        if(token.compare(the_list[i])==0)
            return true;
    }
    return false;
}

string DatalogProgram::datalogProgram_string(){//prints the out string
    return the_output;
}