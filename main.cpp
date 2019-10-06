#include "./main.h"

int main(int argc, char **argv) {
    vector <string> token_type;// this will store the token types
    vector <string> token_input;// this will store the received token inputs
    vector <int> token_linenum;// this will store the line number in case of errors


    ifstream txt_file;
    if (argc < 1){
        cout<<"ERROR: no file."<<endl;
        return -1;
    }

    //-----this is where I implement my Project 01
    txt_file.open(argv[1]);
    tokenizing_state_machine(txt_file, token_type,token_input,token_linenum);
    txt_file.close();
    //-----implementation of Project 01 ends with my now finished token lists

    /*for (int i=0; i<token_type.size(); i++)
        cout<<'('<<token_type[i]<<",\""<<token_input[i]<<"\","<<token_linenum[i]<<')'<<endl;
    cout<<"list_lize<total tokens> = "<<token_type.size();
    cout<<endl;*/
    dataLogProgram(token_type,token_input,token_linenum);
    print_out_string();

    return 0;
}