//
// Created by OmarB on 9/28/2019.
//
#include "main.h"
string the_output = "";
string out_flow = "";
string scheme_flow="";
string fact_flow="";
string rule_flow="";
string query_flow="";
vector <string> domains;

int scheme_count=0;
int fact_count=0;
int rule_count=0;
int query_count=0;
void dataLogProgram(vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    int tk_num = 0;
    try{
        if (token_type[tk_num]==dP_first) {//tk_num is zero, it has to start at SCHEMES
            out_flow+=token_input[tk_num]+"(";//this is were schemes go...
            tk_num++;
            if (token_type[tk_num] == "COLON") {
                scheme_flow+=token_input[tk_num];
                tk_num++;
                scheme(tk_num, token_type, token_input, token_linenum);
                schemeList(tk_num, token_type, token_input, token_linenum);
                out_flow+=to_string(scheme_count)+")"+scheme_flow;
                if (token_type[tk_num] == "FACTS") {
                    out_flow+="\n"+token_input[tk_num]+"(";
                    tk_num++;
                    if (token_type[tk_num] == "COLON") {
                        fact_flow+=token_input[tk_num]; //begin fact flow
                        tk_num++;
                        factList(tk_num, token_type, token_input, token_linenum);
                        out_flow+=to_string(fact_count)+")"+fact_flow; //append fact flow with nums of facts
                        if (token_type[tk_num] == "RULES") {
                            out_flow += "\n" + token_input[tk_num] + "(";
                            tk_num++;
                            if (token_type[tk_num] == "COLON") {
                                rule_flow += token_input[tk_num]; //begin fact flow
                                tk_num++;
                                ruleList(tk_num, token_type, token_input, token_linenum);
                                out_flow += to_string(rule_count) + ")" + rule_flow; //append rule flow with nums of facts
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
                                    }else{throw tk_num;}
                                }else{throw tk_num;}
                            }else{throw tk_num;}
                        }else{throw tk_num;}
                    }else{throw tk_num;}
                }else{throw tk_num;}
            }else{throw tk_num;}
        }else{throw tk_num;}

        the_output = "Success!\n";
        the_output+=out_flow;
        sort(domains.begin(),domains.end());
        domains.erase( unique( domains.begin(), domains.end() ), domains.end() );
        the_output+="\nDomain("+to_string(domains.size())+"):";
        for(int i =0; i<domains.size(); i++){
            the_output+="\n"+domains[i];
        }
        the_output+="\n";
    }
    catch (int tk_num){
        the_output = "Failure!\n";
        the_output+="  ("+token_type[tk_num]+",\""+token_input[tk_num]+"\","+to_string(token_linenum[tk_num])+")";
    }
}

void schemeList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum) {
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

void factList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
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

void ruleList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if (does_token_match(token_type[tk_num], rlL_first, 2)) { //if its any first of fctList
        if(token_type[tk_num] == "ID"){//do not count token bc line is not passed
            rule(tk_num,token_type,token_input,token_linenum);
            ruleList(tk_num,token_type,token_input,token_linenum);
        }else {//this is for wh2en it's lambda
            //tk_num++;
        }
    }else if (!does_token_match(token_type[tk_num],rlL_follow,11)){
        throw tk_num;
    }
}

//query queryList | lambda
void queryList(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
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

void scheme(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
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

void fact(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
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

//headPredicate COLON_DASH predicate predicateList PERIOD
void rule(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if(token_type[tk_num]==rl_first) { //if its ID
        rule_flow += "\n  ";
        headPredicate(tk_num,token_type,token_input,token_linenum,rule_flow);
        if(token_type[tk_num] == "COLON_DASH") {
            rule_flow +=" "+token_input[tk_num]+" ";
            tk_num++;
            predicate(tk_num,token_type,token_input,token_linenum,rule_flow);
            predicateList(tk_num,token_type,token_input,token_linenum,rule_flow);
            if(token_type[tk_num] == "PERIOD") {
                rule_flow += token_input[tk_num];
                tk_num++;//rule will end
            }else{throw tk_num;}
        }else{throw tk_num;}
    }else{throw tk_num;}
    rule_count++;
}

//predicate Q_MARK
void query(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if(token_type[tk_num]==qry_first) { //if its ID
        query_flow += "\n  ";
        predicate(tk_num,token_type,token_input,token_linenum,query_flow);
        if(token_type[tk_num] == "Q_MARK") {
            query_flow += token_input[tk_num];
            tk_num++;
        }else{throw tk_num;}
    }else{throw tk_num;}
    query_count++;
}

//ID LEFT_PAREN parameter parameterList RIGHT_PAREN
void predicate(int &tk_num, vector<string> &token_type, vector<string> &token_input,
               vector<int> &token_linenum, string& curr_out_flow){
    if(token_type[tk_num]==pd_first) {//if id is first
        curr_out_flow += token_input[tk_num];
        tk_num++;
        if (token_type[tk_num] == "LEFT_PAREN") {//first 1
            curr_out_flow += token_input[tk_num];
            tk_num++;
            parameter(tk_num,token_type,token_input,token_linenum,curr_out_flow);
            parameterList(tk_num,token_type,token_input,token_linenum,curr_out_flow);
            if (token_type[tk_num] == "RIGHT_PAREN") {//first 1
                curr_out_flow += token_input[tk_num];
                tk_num++;//predicate ends, recurr back
            } else {throw tk_num;}
        } else {throw tk_num;}
    }else{throw tk_num;}
}

//ID LEFT_PAREN ID idList RIGHT_PAREN
void headPredicate(int &tk_num, vector<string> &token_type, vector<string> &token_input,
                   vector<int> &token_linenum, string& curr_out_flow){
    if(token_type[tk_num]==hPd_first) {//if id is first
        if (token_type[tk_num] == "ID") {//first 1
            curr_out_flow += token_input[tk_num];
            tk_num++;
            if (token_type[tk_num] == "LEFT_PAREN") {
                curr_out_flow += token_input[tk_num];
                tk_num++;
                if (token_type[tk_num] == "ID") {//first 1
                    curr_out_flow += token_input[tk_num];
                    tk_num++;
                    idList(tk_num,token_type,token_input,token_linenum, curr_out_flow);
                    if (token_type[tk_num] == "RIGHT_PAREN") {//first 1
                        curr_out_flow += token_input[tk_num];
                        tk_num++;//back recurr!!
                    } else {throw tk_num;}
                } else {throw tk_num;}
            } else {throw tk_num;}
        } else {throw tk_num;}
    }else{throw tk_num;}
}

//COMMA predicate predicateList | lambda
void predicateList(int &tk_num, vector<string> &token_type, vector<string> &token_input,
        vector<int> &token_linenum, string& curr_out_flow){
    if(does_token_match(token_type[tk_num],pdL_first,2)){
        if(token_type[tk_num] == "COMMA"){//first 1
            curr_out_flow+=token_input[tk_num];
            tk_num++;
            predicate(tk_num,token_type,token_input,token_linenum, curr_out_flow);
            predicateList(tk_num,token_type,token_input,token_linenum, curr_out_flow);
        }else {//this is for when it's lambda
            //tk_num++;
        }
    }else if(!does_token_match(token_type[tk_num],pdL_follow,12)){
        throw tk_num;//if not in follow list throw error
    }
}

//COMMA parameter parameterList | lambda
void parameterList(int &tk_num, vector<string> &token_type, vector<string> &token_input,
        vector<int> &token_linenum, string& curr_out_flow){
    if(does_token_match(token_type[tk_num],prmtL_first,2)){
        if(token_type[tk_num] == "COMMA"){//first 1
            curr_out_flow+=token_input[tk_num];
            tk_num++;
            parameter(tk_num,token_type,token_input,token_linenum, curr_out_flow);
            parameterList(tk_num,token_type,token_input,token_linenum, curr_out_flow);
        }else {//this is for when it's lambda
            //tk_num++;
        }
    }else if(!does_token_match(token_type[tk_num],prmtL_follow,12)){
        throw tk_num;//if not in follow list throw error
    }
}

//COMMA STRING stringList | lambda
void stringList(int &tk_num, vector<string> &token_type, vector<string> &token_input,
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

void idList(int &tk_num, vector<string> &token_type, vector<string> &token_input,
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

//STRING | ID | expression
void parameter(int &tk_num, vector<string> &token_type, vector<string> &token_input,
            vector<int> &token_linenum, string& curr_out_flow){
    if(does_token_match(token_type[tk_num],prmt_first,3)){
        if(token_type[tk_num] == "STRING") {//first #1
            curr_out_flow += token_input[tk_num];
            tk_num++;//end #1
        }else if (token_type[tk_num] == "ID"){//first #2
            curr_out_flow += token_input[tk_num];
            tk_num++;//end #2
        }else if(token_type[tk_num] == "LEFT_PAREN"){
            expression(tk_num,token_type,token_input,token_linenum, curr_out_flow);
        }//no lambda this time ;(
    }else if(!does_token_match(token_type[tk_num],prmt_follow,12)){
        throw tk_num;//if not in follow list throw error
    }
}

//LEFT_PAREN parameter the_operator parameter RIGHT_PAREN
void expression(int &tk_num, vector<string> &token_type, vector<string> &token_input,
               vector<int> &token_linenum, string& curr_out_flow){
    if(token_type[tk_num]==exp_first){
        curr_out_flow += token_input[tk_num];
        tk_num++;
        parameter(tk_num,token_type,token_input,token_linenum, curr_out_flow);
        the_operator(tk_num,token_type,token_input,token_linenum, curr_out_flow);
        parameter(tk_num,token_type,token_input,token_linenum, curr_out_flow);
        if(token_type[tk_num]=="RIGHT_PAREN"){
            curr_out_flow += token_input[tk_num];
            tk_num++;//recurr back
        }else{throw tk_num;}
    }else{throw tk_num;}
}

//ADD | MULTIPLY
void the_operator(int &tk_num, vector<string> &token_type, vector<string> &token_input,
                vector<int> &token_linenum, string& curr_out_flow){
    if(does_token_match(token_type[tk_num],opt_first,3)){
        if(token_type[tk_num]=="ADD"){
            curr_out_flow += token_input[tk_num];
            tk_num++;//end #1 recurr back
        }if(token_type[tk_num]=="MULTIPLY"){
            curr_out_flow += token_input[tk_num];
            tk_num++;//end #2 recurr back
        }
    }else{throw tk_num;}
}

bool does_token_match(string token, const string the_list[], int list_size){
    for(int i=0; i<list_size; i++){
        if(token.compare(the_list[i])==0)
            return true;
    }
    return false;
}

void print_out_string(){//prints the out string
    cout<<the_output;
}