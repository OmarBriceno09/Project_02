//
// Created by OmarB on 9/28/2019.
//
#include "main.h"
void dataLogProgram(vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    int tk_num = 0;
    try{
        if (token_type[tk_num]=="SCHEMES") {//tk_num is zero, it has to start at SCHEMES
            tk_num++;
            if (token_type[tk_num] == "COLON") {
                tk_num++;
                scheme(tk_num, token_type, token_input, token_linenum);
            }else{throw tk_num;}
        }else{throw tk_num;}

        cout<<does_token_match("COMMA",schL_follow,15)<<endl;//this works
        cout<<does_token_match("SCHEMES",schL_follow,15)<<endl;

    }
    catch (int tk_num){
        cout<<"error of <"<<token_type[tk_num]<<"> with input <"<<token_input[tk_num]<<"> at line "<<token_linenum[tk_num]<<endl;
    }
}

void scheme(int &tk_num, vector<string> &token_type, vector<string> &token_input, vector<int> &token_linenum){
    if(token_type[tk_num]==sch_first){ //if its ID
        tk_num++;
        if(token_type[tk_num] == "LEFT_PAREN"){
            tk_num++;
            if(token_type[tk_num] == "ID"){
                tk_num++;
                cout<<"implement Id list"<<endl;
            }else{throw tk_num;}
        }else{throw tk_num;}
    }else{throw tk_num;}
}

bool does_token_match(string token, const string the_list[], int list_size){
    for(int i=0; i<list_size; i++){
        if(token.compare(the_list[i])==0)
            return true;
    }
    return false;
}
