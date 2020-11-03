/*=============================================================================
 * parser for CSP instances represented in XCSP3 Format
 *
 * Copyright (c) 2015 xcp3.org (contact <at> xcsp3.org)
 * Copyright (c) 2008 Olivier ROUSSEL (olivier.roussel <at> cril.univ-artois.fr)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *=============================================================================
 */
#ifndef COSOCO_XCSP3PRINTCALLBACKS_H
#define COSOCO_XCSP3PRINTCALLBACKS_H

#include "XCSP3CoreCallbacks.h"
#include "XCSP3Variable.h"
#include <algorithm>
#include <string.h>
#include <list>
#include <map>
#include <tuple>
#include <vector>
#include <boost/lexical_cast.hpp>
// #include <bits/stdc++.h>
/**
 * This is an example that prints useful informations of a XCSP3 instance.
 * You need to create your own class and to override functions of the callback.
 * We suggest to make a map between XVariable and your own variables in order to
 * facilitate the constructions of constraints.
 *
 * see main.cc to show declaration of the parser
 *
 */

namespace XCSP3Core {

    class XCSP3PrintCallbacks : public XCSP3CoreCallbacks {

        XConstraintGroup *currentGroup;

    public:
        XCSP3PrintCallbacks();

        virtual void beginInstance(InstanceType type) override;

        virtual void endInstance() override;

        virtual void beginVariables() override;

        virtual void endVariables() override;

        virtual void beginVariableArray(string id) override;

        virtual void endVariableArray() override;

        virtual void beginConstraints() override;

        virtual void endConstraints() override;

        virtual void beginGroup(string id) override;

        virtual void endGroup() override;

        virtual void beginBlock(string classes) override;

        virtual void endBlock() override;

        virtual void beginSlide(string id, bool circular) override;

        virtual void endSlide() override;

        virtual void beginObjectives() override;

        virtual void endObjectives() override;


        virtual void buildVariableInteger(string id, int minValue, int maxValue) override;

        virtual void buildVariableInteger(string id, vector<int> &values) override;

        virtual void buildConstraintExtension(string id, vector<XVariable *> list, vector <vector<int> > &tuples, bool support, bool hasStar) override;

        virtual void buildConstraintExtension(string id, XVariable *variable, vector<int> &tuples, bool support, bool hasStar) override;

        virtual void buildConstraintExtensionAs(string id, vector<XVariable *> list, bool support, bool hasStar) override;

        virtual void buildConstraintIntension(string id, string expr) override;

        virtual void buildConstraintPrimitive(string id, OrderType op, XVariable *x, int k, XVariable *y) override;


        virtual void buildConstraintRegular(string id, vector<XVariable *> &list, string st, vector <string> &final, vector <XTransition> &transitions) override;

        virtual void buildConstraintMDD(string id, vector<XVariable *> &list, vector <XTransition> &transitions) override;

        virtual void buildConstraintAlldifferent(string id, vector<XVariable *> &list) override;

        virtual void buildConstraintAlldifferentExcept(string id, vector<XVariable *> &list, vector<int> &except) override;

        virtual void buildConstraintAlldifferentList(string id, vector <vector<XVariable *> > &lists) override;

        virtual void buildConstraintAlldifferentMatrix(string id, vector <vector<XVariable *> > &matrix) override;

        virtual void buildConstraintAllEqual(string id, vector<XVariable *> &list) override;

        virtual void buildConstraintNotAllEqual(string id, vector<XVariable *> &list) override;

        virtual void buildConstraintOrdered(string id, vector<XVariable *> &list, OrderType order) override;

        virtual void buildConstraintLex(string id, vector <vector<XVariable *> > &lists, OrderType order) override;

        virtual void buildConstraintLexMatrix(string id, vector <vector<XVariable *> > &matrix, OrderType order) override;

        virtual void buildConstraintSum(string id, vector<XVariable *> &list, vector<int> &coeffs, XCondition &cond) override;

        virtual void buildConstraintSum(string id, vector<XVariable *> &list, XCondition &cond) override;

        virtual void buildConstraintSum(string id, vector<XVariable *> &list, vector<XVariable *> &coeffs, XCondition &cond) override;

        virtual void buildConstraintAtMost(string id, vector<XVariable *> &list, int value, int k) override;

        virtual void buildConstraintAtLeast(string id, vector<XVariable *> &list, int value, int k) override;

        virtual void buildConstraintExactlyK(string id, vector<XVariable *> &list, int value, int k) override;

        virtual void buildConstraintAmong(string id, vector<XVariable *> &list, vector<int> &values, int k) override;

        virtual void buildConstraintExactlyVariable(string id, vector<XVariable *> &list, int value, XVariable *x) override;

        virtual void buildConstraintCount(string id, vector<XVariable *> &list, vector<int> &values, XCondition &xc) override;

        virtual void buildConstraintCount(string id, vector<XVariable *> &list, vector<XVariable *> &values, XCondition &xc) override;

        virtual void buildConstraintNValues(string id, vector<XVariable *> &list, vector<int> &except, XCondition &xc) override;

        virtual void buildConstraintNValues(string id, vector<XVariable *> &list, XCondition &xc) override;

        virtual void buildConstraintCardinality(string id, vector<XVariable *> &list, vector<int> values, vector<int> &occurs, bool closed) override;

        virtual void buildConstraintCardinality(string id, vector<XVariable *> &list, vector<int> values, vector<XVariable *> &occurs,
                                                bool closed) override;

        virtual void buildConstraintCardinality(string id, vector<XVariable *> &list, vector<int> values, vector <XInterval> &occurs,
                                                bool closed) override;

        virtual void buildConstraintCardinality(string id, vector<XVariable *> &list, vector<XVariable *> values, vector<int> &occurs,
                                                bool closed) override;

        virtual void buildConstraintCardinality(string id, vector<XVariable *> &list, vector<XVariable *> values, vector<XVariable *> &occurs,
                                                bool closed) override;

        virtual void buildConstraintCardinality(string id, vector<XVariable *> &list, vector<XVariable *> values, vector <XInterval> &occurs,
                                                bool closed) override;

        virtual void buildConstraintMinimum(string id, vector<XVariable *> &list, XCondition &xc) override;

        virtual void buildConstraintMinimum(string id, vector<XVariable *> &list, XVariable *index, int startIndex, RankType rank,
                                            XCondition &xc) override;

        virtual void buildConstraintMaximum(string id, vector<XVariable *> &list, XCondition &xc) override;

        virtual void buildConstraintMaximum(string id, vector<XVariable *> &list, XVariable *index, int startIndex, RankType rank,
                                            XCondition &xc) override;

        virtual void buildConstraintElement(string id, vector<XVariable *> &list, int value) override;

        virtual void buildConstraintElement(string id, vector<XVariable *> &list, XVariable *value) override;

        virtual void buildConstraintElement(string id, vector<XVariable *> &list, int startIndex, XVariable *index, RankType rank, int value) override;

        virtual void buildConstraintElement(string id, vector<XVariable *> &list, int startIndex, XVariable *index, RankType rank, XVariable *value) override;

        virtual void buildConstraintChannel(string id, vector<XVariable *> &list, int startIndex) override;

        virtual void buildConstraintChannel(string id, vector<XVariable *> &list1, int startIndex1, vector<XVariable *> &list2,
                                            int startIndex2) override;

        virtual void buildConstraintChannel(string id, vector<XVariable *> &list, int startIndex, XVariable *value) override;

        virtual void buildConstraintStretch(string id, vector<XVariable *> &list, vector<int> &values, vector <XInterval> &widths) override;

        virtual void buildConstraintStretch(string id, vector<XVariable *> &list, vector<int> &values, vector <XInterval> &widths, vector <vector<int> > &patterns) override;

        virtual void buildConstraintNoOverlap(string id, vector<XVariable *> &origins, vector<int> &lengths, bool zeroIgnored) override;

        virtual void buildConstraintNoOverlap(string id, vector<XVariable *> &origins, vector<XVariable *> &lengths, bool zeroIgnored) override;

        virtual void buildConstraintNoOverlap(string id, vector <vector<XVariable *> > &origins, vector <vector<int> > &lengths, bool zeroIgnored) override;

        virtual void buildConstraintNoOverlap(string id, vector <vector<XVariable *> > &origins, vector <vector<XVariable *> > &lengths, bool zeroIgnored) override;

        virtual void buildConstraintInstantiation(string id, vector<XVariable *> &list, vector<int> &values) override;

        virtual void buildObjectiveMinimizeExpression(string expr) override;

        virtual void buildObjectiveMaximizeExpression(string expr) override;


        virtual void buildObjectiveMinimizeVariable(XVariable *x) override;


        virtual void buildObjectiveMaximizeVariable(XVariable *x) override;


        virtual void buildObjectiveMinimize(ExpressionObjective type, vector<XVariable *> &list, vector<int> &coefs) override;


        virtual void buildObjectiveMaximize(ExpressionObjective type, vector<XVariable *> &list, vector<int> &coefs) override;


        virtual void buildObjectiveMinimize(ExpressionObjective type, vector<XVariable *> &list) override;


        virtual void buildObjectiveMaximize(ExpressionObjective type, vector<XVariable *> &list) override;


    };
}


using namespace XCSP3Core;

// allowing only for 100 length tuples in extension variables
// allowing only for 1000 variables at the moment
// allowing only for 1000 disjuction variables at the moment



int countvars = 0;
string arr[5000];      // array for keeping actual name of variables, against the no issued to it
int cntdisjunctions = 0;        // variable for counting disjuctions
string ext[100];          // for storing the variables in extensional constraint
int extens = 0;           //  variable for counting elements in ext
int extention = 0;      // for counting the variables of different extensional tuples stored in array ext
string extblock[5000];       // for counting the no of blocks in extensional constraints, currently allowing 1000

int mainext[500000];      // Allowing 1000 tuples for each block at the moment, This is for storing the tuples corresponding to a tuple, 
int no_tuples = 0;         // counter for filled boxes in mainext
string currentextblock;
bool supp;
int once = 0;     // this is for the 
// Maybe we don't need to store all tuples for all pairs of extensional constraints, because all tuples of a particular constraint is
// listed in a block
int done_int = 0; // this is for case flagint == 2 for intension variables, declaring the variable only once.
int done_vars = 0; // this is for case flag_var_vector == 2 for declaring variables with domain as a vector
string var_global; // this will the variable for case of flag_var_vector == 2 
int declare_var_for_abs = 0; // As name clearly suggests this is the var_for_absolute function, to be declared only once
int done_for_special = 0; // This is for the case of intensional constraint in knights file, type 13 in intensional one, please check there
int no_times = 0;  // this is for counting variables for the type 13 of intensional constraint



int run_klee = 1;        // This variable is 1 if code transformation is for klee and 0 if for llbmc 
int flag_extensional_benchmarks = 12;
int flag_exten = flag_extensional_benchmarks;    // if this  == 1, each argument of a extensional constraint is in one "if" condition, while if == 2 , all arguments of a single extensional constraint are in a single if condition

// if flag_exten == 1, each argument of a extensional constraint is in one "if" condition
// if flag_exten == 2 , all arguments of a single extensional constraint are in a single if condition
// If flag_exten == 3, it were using klee_assumes with conditions clubbed as in flag_exten == 2, we can also try klee_assumes with flag_exten == 1 type
// if flag_exten == 3, we will also declare the variables by klee_assume, thus trying to make less of C code, as we did in case of intensional constraints, but not necessarily club them in one klee_assume, so declare normally in a sequence of klee_assumes
// flag_exten == 6, is just == 3 with logical operators in place of bitwise operators as in == 3
// flag_exten == 4 is just like  == 2, so we use clubbed "if" conditions with bitwise operators. conditions inside the "if" thing looks like == 3
// flag_exten == 5 is just like == 1, we use different "if" conditions (non-clubbed) but with bitwise operators
// flag_exten == 11, is assume, logical and no grouping. Done 
// flag_exten == 12, is assume, bitwise and no grouping. Done


// There are 7,8,9 and 10th versions as well but they are generated using python parser not here, see definitions in report
// Now we create a new version for extensional, which is variables by malloc. - name it exten_version41
// exten_version41 will be like flag_exten == 2, but dynamic variables
// exten_version42 will be like flag_exten == 4, but dynamic variables
// exten_version51 will be like flag_exten == 41, but second way of dynamic variable declaration 
// exten_version52 will be like flag_exten == 42, but second way of dynamic variable declaration
// Exten_version511 and 521 are just exten51 and 52 respectively, just they are compiled without -O3 flag
// Exten_version61 - will be same as 41 and 51, with third way of declaring dynamic variables.
// Exten_version62 - will be same as 42 and 52, with third way of declaring dynamic variables. 
// For 61 and 62, I will not handle all cases. after declaring variables, I will change their value to 51 and 52 respectively. 



string exten_array[10000];          // This array is used for storing the variables of arguments of a extensional constraint
int counter_extensional = 0;        // This is a counter for counting the array length in exten_array.
bool global_support;                 // This is a global variable maintained to know the type of support for extensional constraint because it has to be printed in endConstraints function

int mdd = 0;           // This is the global variable which is label for counting number of mdd constraints, and this is used in conjunction with "nodeT" label, so that each mdd constraint has an distinct ending goto , eg. goto nodeT_12
int mdd_flag = 0;       // this controls the version of mdd. See the function for explanation

int flag_intensional_benchmarks = 1;
int flag_klee = flag_intensional_benchmarks;  // put this 0 for extensional files  //If this is == 1 then it is not pure C code (i.e it is with klee_assumes ) , if == 2 is for pure version1 of pure C code, == 3 for for version2 for pure C code, == 4 is for version3 for pure code
// To be safe put it to 1, when using flag_exten == 3 ------ NO, make it 0 when using extensional constraints


// This all is for intensional constraints. Though it will be same for declaration of variables in case of extensional as well
// Version1 - Non-pure version of C code - tries to contain maximum no of klee_assumes and avoid "if" conditions       --- flag_klee == 1 and flag_exten == 3(directory - exten_version3)
// version2 - if condition in different blocks --- flag_klee == 2 and flag_exten == 1(directory - exten_version1)
// version3 - (paper3) - if conditions are clubbed but we use a negation, ie. if(!expr) exit(0);  ---- This can be excluded from the list       --- flag_klee == 3 and no flag_exten used for this
// version4 (paper1) - if conditions are clubbed but we don't use negated version ie. if(expr) myvar=1 else exit(0);   --- flag_klee == 4 and flag_exten == 2(directory - exten_version2)
// version5 - if conditions are clubbed but we use bitwise operators  -- same as in flag_exten == 4    --- flag_klee == 5
// version6 - if conditions are non-clubbed with bitwise operators -- same as in flag_exten == 5,  --- flag_klee == 6  -- klee_assume version of this is flag_klee == 1
// Version7 - clubbed conditions in klee_assume with bitwise operators    --- flag_klee == 7  like flag_klee == 4 and 5
// Version8 - clubbed conditions in klee_assume with logical operators    --- flag_klee == 8  like flag_klee == 4 and 5
// Version9 - clubbed conditions in "if" block with logical operators. Entire file in a single "if" condition
// Version10 - clubbed conditions in "if" block with bitwise operators. Entire file in a single "if" condition

// Version9 and Version10 are produced by another file, not this file. So that is not handled here
// I now need to create for dynamic memory. Let me convert version1 (of report - version2 here i.e flag_klee == 2) and version4 (of report  -  version5 of here flag_klee == 5) to dynamic memory. 
// Naming them as version41 (flag_klee == 41) and version44 (flag_klee == 44)respectively. 


// Now for the case in which we are producing pure C code(no klee_assumes , flag_klee == 2) for that case we are trying to make
// a version where all intensional constraints of a type will be a single "if" block. 
// Presently this happens for Alldifferent, they are all put in a single "if" condition
// Later we can try to put even more constraints in a single file
// We can also think of declaring variables together in a single "if" condition

int variables_declared_type = 0; // This will have a value of 1 if declaring of variables is in function buildInteger of type 1 (i.e with a max and min possible value) and 2 if of type 2 (with variables having an array of possible values)
string vars_type_one[1000] = {"null"};      // This is the array for storing xml variables of type 1 (i.e with a max and min possible value)
string vars_type_two[1000] = {"null"};      // This is the array for storing xml variables of type 2 (i.e with a array of possible values)
string inten_type2[10000], inten_type3[10000], inten_type4[10000], inten_type5[10000], inten_type6[10000], inten_type7[10000], inten_type8[10000], inten_type910[10000], inten_type11[10000], inten_type12[10000], inten_type13[10000], inten_type200[10000];
int type2, type3, type4, type5, type6, type7, type8, type910, type11, type12, type13, type200 = 0;        // type200 is for the function in buildConstraintPrimitive
int implement_dist = 0;         // This is global variable for deciding if the dist function has been printed or not
string present_level_variable = "";     // This is the global variable for which variable is being used in present level for mdd printing



XCSP3PrintCallbacks::XCSP3PrintCallbacks() : XCSP3CoreCallbacks(), currentGroup(0) {

}


template<class T>
void displayList(vector <T> &list, string separator = " ") {
    if(list.size() > 8) {
        for(int i = 0; i < 3; i++)
            cout << list[i] << separator;
        cout << " ... ";
        for(int i = list.size() - 4; i < list.size(); i++)
            cout << list[i] << separator;
        cout << endl;
        return;
    }
    for(int i = 0; i < list.size(); i++)
        cout << list[i] << separator;
    cout << endl;
}


void displayList(vector < XVariable * > &list, string separator = " ") 
{
    if(list.size() > 8) {
        for(int i = 0; i < 3; i++)
            cout << list[i]->id << separator;
        cout << " ... ";

        for( unsigned int i = list.size() - 4; i< list.size(); i++)
            cout << list[i]->id << separator;
        cout << endl;
        return;
    }

    for( unsigned int i = 0; i<list.size(); i++)
    cout << list[i]->id << separator;
    cout <<endl;
}


void XCSP3PrintCallbacks::beginInstance(InstanceType type) {
    // cout << "Start Instance - type=" << type << endl;
    cout << "\nint dist(int a, int b)\n{ int dis = (a-b >= 0) ? a-b : b-a;\n return dis;\n}\n";
    // This is the function dist, it is printed at top of file as, we don't know how to get it printed if in middle of file
    if(run_klee == 1)
        cout << "#include <klee/klee.h>\n";
    else if(run_klee == 0)
        cout << "#include <llbmc.h>\n";
    else assert(0);
    cout << endl << "#include <assert.h>" << endl << "#include <stdio.h>" << endl << "#include <stdlib.h>" << endl << "int main () {" << endl;
    cout << "int cond0;\nint dummy = 0;\nint N;\n";     // This are for second style of dynamic variable declaraton
    if ((flag_exten == 61 || flag_exten == 62) && run_klee == 0){
        cout << "int m = __llbmc_nondef_int();\n";
    }
    else if((flag_exten == 61 || flag_exten == 62) && run_klee == 1){
        cout << "int m;\nklee_make_symbolic(&m, sizeof(m),\"m\");\n" << endl;
    }
}


void XCSP3PrintCallbacks::endInstance() {
    // cout << "End SAX parsing " << endl;
    cout << "return 0;" << endl;
    // Here the correspondence list is printed in comments, can be read by python file
    // which is used to edit the xml file.
    cout << "/* " << endl;
    for (int i = 0; i < countvars; ++i)
    {
        cout << i << " " << arr[i] << endl;
    }
    cout << " */" << "}" << endl;
}


void XCSP3PrintCallbacks::beginVariables() {
    // cout << " start variables declaration" << endl;
    for (int i = 0; i < 1000; ++i)
    {
        vars_type_two[i] = vars_type_one[i] = "null";
    }

}

// you will need to make changes in variable declaration to make it separate from constraints declaration
void XCSP3PrintCallbacks::endVariables() {
    // cout << " end variables declaration" << endl << endl;
    
    // This all is for variable type 1, at the moment I am not mixing both the types in a single if condition
    // This is in accordance as we are not mixing different types of intensional constraints together

    if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
        done_vars = 1;
        string q = "myvar" + std::to_string(cntdisjunctions);
        cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
        var_global = q;
        cntdisjunctions++;
     }

    if(flag_exten == 61)
        flag_exten = 51;
    else if(flag_exten == 62)
        flag_exten = 52;
    
    if(flag_klee == 3)
        cout << "if(!(" ;   // Take negation of what we desire and make it exit(0) if this is true
    else if(flag_klee == 4 || flag_klee == 5 || flag_exten == 2 || flag_exten == 4 || flag_exten == 42 || flag_exten == 52)
        cout << "if((";
    else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
    }
    else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
    }
    else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6 || flag_exten == 1 || flag_exten == 3 || flag_exten == 5 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12 || flag_klee == 41 || flag_exten == 41 || flag_exten == 51)        // Do nothing about it here, so its chill
        ;
    else assert(0);

    for (int i = 0; i < 1000; ++i)
    {
        if(vars_type_one[i] != "null"){
            // cout << vars_type_one[i] << endl;
            // The code justs breaks the string on underscores and adds it in the array
            int k = 0;string temp[100];
            std::stringstream test(vars_type_one[i]);
            std::string segment;
            std::vector<std::string> seglist;
            while(std::getline(test, segment, '_'))
            {
               seglist.push_back(segment);
               temp[k] = seglist[k];
               k++;
            }
            if(flag_exten == 4 || flag_klee == 5 || flag_klee == 7){
                cout << "(var" + std::to_string(i) << " >= " << temp[0] << " & var" + std::to_string(i) << " <= " << temp[1] << ") & "; // just replacing "&&" with "&"
            }
            else if(flag_exten == 42 || flag_exten == 52){
                cout << "((*var" + std::to_string(i) << ") >= " << temp[0] << " & (*var" + std::to_string(i) << ") <= " << temp[1] << ") & "; // just replacing "&&" with "&"
            }
            else {
               cout << "(var" + std::to_string(i) << " >= " << temp[0] << " && var" + std::to_string(i) << " <= " << temp[1] << ") && "; 
            }
        }
    }
        
        if(flag_klee == 3){
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        }
        else if(flag_klee == 4 || flag_klee == 5 || flag_exten == 2 || flag_exten == 4 || flag_exten == 42 || flag_exten == 52){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else if(flag_klee == 1 || flag_klee == 2  || flag_klee == 6 || flag_exten == 1 || flag_exten == 3 || flag_exten == 5 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12 || flag_klee == 41 || flag_exten == 41 || flag_exten == 51)        // Do nothing about it here, so its chill
            ;

        else assert(0);



    

    if(flag_klee == 3)
        cout << "if(!(" ;   // Take negation of what we desire and make it exit(0) if this is true
    else if(flag_klee == 4 || flag_klee == 5 || flag_exten == 2 || flag_exten == 4 || flag_exten == 42 || flag_exten == 52)
        cout << "if((";
    else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
    }
    else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
    }
    else if(flag_klee == 1 || flag_klee == 2  || flag_klee == 6 || flag_exten == 1 || flag_exten == 3 || flag_exten == 5 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12 || flag_klee == 41 || flag_exten == 41 || flag_exten == 51)        // Do nothing about it here, so its chill
        ;
    else assert(0);

    for (int i = 0; i < 1000; ++i)
    {
        if(vars_type_two[i] != "null"){
            // cout << vars_type_one[i] << endl;
            // The code justs breaks the string on underscores and adds it in the array
            int k = 0;string temp[100];
            std::stringstream test(vars_type_two[i]);
            std::string segment;
            std::vector<std::string> seglist;
            while(std::getline(test, segment, '_'))
            {
               seglist.push_back(segment);
               temp[k] = seglist[k];
               k++;
            }
            
            if(flag_exten == 4 || flag_klee == 5 || flag_klee == 7){
                cout << "(var" + std::to_string(i) << " >= " << temp[0] << " & var" + std::to_string(i) << " <= " << temp[1] << " & ";  // Just replacing "&&" with "&"
            }
            else if(flag_exten == 42 || flag_exten == 52){
                cout << "((*var" + std::to_string(i) << ") >= " << temp[0] << " & (*var" + std::to_string(i) << ") <= " << temp[1] << " & ";  // Just replacing "&&" with "&"
            }
            else {
                cout << "(var" + std::to_string(i) << " >= " << temp[0] << " && var" + std::to_string(i) << " <= " << temp[1] << " && ";
            }
            
            // This loop prints the non-allowed values in the initial domain of variables
            for (int j = 2; j < k; ++j)         // The not allowed values start from this array index
            {
                if(flag_exten == 4 || flag_klee == 5 || flag_klee == 7){
                    cout << "var" + std::to_string(i) << " != " << temp[j] << " & ";       // Just replacing "&&" with "&"
                }
                else if (flag_exten == 41){
                    cout << "(*var" + std::to_string(i) << ") != " << temp[j] << " & ";  
                }
                else {
                    cout << "var" + std::to_string(i) << " != " << temp[j] << " && ";
                }
            }
            if(flag_exten == 4 || flag_klee == 5 || flag_klee == 7 || flag_exten == 42 || flag_exten == 52)
                cout << " 1) & ";  // To match the last unmatched "&"
            else{
                cout << " 1) && ";  // To match the last unmatched "&&"
            }
        }
    }
        
        if(flag_klee == 3){
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;            // end of klee_assume statement
        }
        else if(flag_klee == 4  || flag_klee == 5 || flag_exten == 2 || flag_exten == 4 || flag_exten == 42 || flag_exten == 52){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 1 || flag_klee == 2  || flag_klee == 6 || flag_exten == 1 || flag_exten == 3 || flag_exten == 5 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12 || flag_klee == 41 || flag_exten == 41 || flag_exten == 51)        // Do nothing about it here, so its chill, no need to add goto statement
            ;
        else assert(0);

}


void XCSP3PrintCallbacks::beginVariableArray(string id) {
    // cout << "    array: " << id << endl;
}


void XCSP3PrintCallbacks::endVariableArray() {
}


void XCSP3PrintCallbacks::beginConstraints() {
    // cout << " start constraints declaration" << endl;
    for (int i = 0; i < 10000; ++i)
    {
        inten_type2[i] = inten_type3[i] = inten_type4[i] = inten_type5[i] = inten_type6[i] = inten_type7[i] = inten_type8[i] = inten_type910[i] = inten_type11[i] = inten_type12[i] = inten_type13[i] = inten_type200[i] = "null";
        exten_array[i] = "null";
    }
}


void XCSP3PrintCallbacks::endConstraints() {
    // cout << "\n end constraints declaration" << endl << endl;

    // We need to handle the intensional constraints here now !!!
    // Don't use "else if" here because multiple of them can be true
    if(type2 > 0){
      if(flag_klee == 3)
        cout << "if(!(";
      
      else if(flag_klee == 4 || flag_klee == 5)
        cout << "if((";
      
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
      
      else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
        goto outside;       // this can be label that holds for all these cases as in these settigs are global
      
      else assert(0);

        
        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type2[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type2[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if (flag_klee == 5 || flag_klee == 7){
                    cout << "(" << temp[0] << " != " << temp[1] << " & " << temp[2] << " + " << temp[3] << " >=2 ) & ";     // using bitwise
                }
                else {
                    cout << "(" << temp[0] << " != " << temp[1] << " && " << temp[2] << " + " << temp[3] << " >=2 ) && ";
                }
            }
        }
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;            // ending of klee_assume statement here.
        }
        else assert(0);
    }  

    
    if(type3 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
        }

        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
        }

        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;

        else assert(0);
        
        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type3[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type3[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "( 0 > (" << temp[0] << " - " << temp[1] << ")*(" << temp[2] << " - " << temp[3] << ")) & ";
                }
                else {
                    cout << "( 0 > (" << temp[0] << " - " << temp[1] << ")*(" << temp[2] << " - " << temp[3] << ")) && ";
                }
            }
        }
        
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);

    }

    
    if(type4 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type4[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type4[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "(" << temp[0] << " - " << temp[1] << " == " << temp[2] << ") & ";
                }
                else {
                    cout << "(" << temp[0] << " - " << temp[1] << " == " << temp[2] << ") && ";
                }
            }
        }
        
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);
    }

    
    if(type5 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type5[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type5[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "((" << temp[0] << " - " << temp[1] << ") != (" << temp[2] << " - " << temp[3] << ")) & ";
                }
                else {
                    cout << "((" << temp[0] << " - " << temp[1] << ") != (" << temp[2] << " - " << temp[3] << ")) && ";
                }
            }
        }
        
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }

        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);
    }

    // Here question arises which is a better thing to use, use dist function or write that code for each part
    // Here i am using the function
    if(type6 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type6[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type6[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "(" << temp[0] << " == dist(" << temp[1] << ", " << temp[2] << ")) & ";
                }
                else {
                    cout << "(" << temp[0] << " == dist(" << temp[1] << ", " << temp[2] << ")) && ";
                }
            }
        }
        
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if (flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);
    }

    
    if(type7 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type7[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type7[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")%" << temp[3] << " == " << temp[4] << ") & ";
                }
                else {
                    cout << "((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")%" << temp[3] << " == " << temp[4] << ") && ";
                }
            }
        }
        
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);
    }

    
    if(type8 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type8[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type8[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")/" << temp[3] << " == " << temp[4] << ") & ";
                }
                else {
                    cout << "((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")/" << temp[3] << " == " << temp[4] << ") && ";
                }
            }
        }
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);
    }

    
    if(type910 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type910[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type910[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "(" << temp[0] << temp[1] << temp[2] << ") & ";
                }
                else {
                    cout << "(" << temp[0] << temp[1] << temp[2] << ") && ";
                }
            }
        }
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" <<  endl;
        }
        else assert(0);
    }

    
    if(type11 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type11[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type11[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "(" << temp[0] << " != dist(" << temp[1] << ", " << temp[2] << ")) & ";
                }
                else {
                   cout << "(" << temp[0] << " != dist(" << temp[1] << ", " << temp[2] << ")) && "; 
                }
            }
        }
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8)
            cout << " 1));" << endl;
        else assert(0);
    }

    
    if(type12 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type12[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type12[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "(" << temp[0] << " == (" << temp[1] << " + "  << temp[2] <<  ") & ";
                }
                else {
                    cout << "(" << temp[0] << " == (" << temp[1] << " + "  << temp[2] <<  ") && ";
                }
            }
        }
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);
    }

    // or(and(eq(dist(div(%0,100),div(%1,100)),1),eq(dist(mod(%0,100),mod(%1,100)),2)),and(eq(dist(div(%0,100),div(%1,100)),2),eq(dist(mod(%0,100),mod(%1,100)),1)))
    
    if(type13 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type13[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type13[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "((" << "dist(" << temp[0] << "/100, " << temp[1] << "/100) == 1  & dist(" << temp[0] << "%100, " << temp[1] << "%100) == 2) | (" << "dist(" << temp[0] << "/100, " << temp[1] << "/100) == 2 & dist(" << temp[0] << "%100, " << temp[1] << "%100) == 1)) & ";
                }
                else{
                    cout << "((" << "dist(" << temp[0] << "/100, " << temp[1] << "/100) == 1  && dist(" << temp[0] << "%100, " << temp[1] << "%100) == 2) || (" << "dist(" << temp[0] << "/100, " << temp[1] << "/100) == 2 && dist(" << temp[0] << "%100, " << temp[1] << "%100) == 1)) && ";
                }
            }
        }
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);

    }

    // example for this is haystacks file, for understanding please see the intensional constraint file
    if(type200 > 0){
        if(flag_klee == 3)
            cout << "if(!(";
        else if(flag_klee == 4 || flag_klee == 5)
            cout << "if((";
        else if((flag_klee == 7 || flag_klee == 8) && run_klee == 1){
        cout << "klee_assume((";
       }
       else if((flag_klee == 7 || flag_klee == 8) && run_klee == 0){
        cout << "__llbmc_assume((";
       }
        else if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6)
            goto outside;
        else assert(0);

        for (int i = 0; i < 10000; ++i)
        {
            if(inten_type200[i] != "null"){
                int k = 0;  string temp[100];
                std::stringstream test(inten_type200[i]);
                std::string segment;
                std::vector<std::string> seglist;
                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temp[k] = seglist[k];
                   k++;
                }
                if(flag_klee == 5 || flag_klee == 7){
                    cout << "(" << temp[0] << temp[1] << temp[2] << ") & ";
                }
                else {
                    cout << "(" << temp[0] << temp[1] << temp[2] << ") && ";
                }
            }
        }
        if(flag_klee == 3)
            cout << " 1))" << endl << "exit(0);" << endl;  // To match the last unmatched "&&"
        
        else if(flag_klee == 4 || flag_klee == 5){
            cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;
        }
        else if(flag_klee == 7 || flag_klee == 8){
            cout << " 1));" << endl;
        }
        else assert(0);

    }

    outside:

    // Now this is last extensional constraint left to be printed, only in case of extensional constraint
    if(no_tuples > 0){
        if(flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52){
            cout << "if(";
        }
       
        else if((flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12) && run_klee == 1)  {     // almost same as flag_exten == 2, just that in place of "if" we are using klee_assume
            if(global_support)
                cout << "klee_assume(";
            else if(!global_support)
                cout << "klee_assume(!(";
        }
        
        else if((flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12) && run_klee == 0)  {     // almost same as flag_exten == 2, just that in place of "if" we are using klee_assume
            if(global_support)
                cout << "__llbmc_assume(";
            else if(!global_support)
                cout << "__llbmc_assume(!(";
        }
        
        else assert(0);
        
        for (int cnt = 0; cnt < counter_extensional; ++cnt)
        { 
            string temporary[100];
            // std::istringstream iss(currentextblock); string enn2 = "";
            int i = 0;
            std::stringstream test(exten_array[cnt]);   // for this partcular element of the array
            std::string segment;
            std::vector<std::string> seglist;

            while(std::getline(test, segment, '_'))
            {
               seglist.push_back(segment);
               temporary[i] = "var" + seglist[i];
               i++;             // This is always the length of the tuple
            }

            int counter = 0;
            while(counter < (no_tuples/i))
            {    
                cout << "( ";
                for(int k = 0; k < i-1; k++){    // or maybe k <= i, but not list.size as block has changed
                    if(flag_exten == 1 || flag_exten == 2 || flag_exten == 6 || flag_exten == 11){
                        cout << temporary[k] << " == " << mainext[counter*(i)+k] << " && ";
                    }
                    else if(flag_exten == 3 || flag_exten == 4 || flag_exten == 5 || flag_exten == 12){
                        cout << temporary[k] << " == " << mainext[counter*(i)+k] << " & ";      // just replacing "&&" with "&"
                    }
                    else if(flag_exten == 41 || flag_exten == 51){
                        cout << "(*" << temporary[k] << ") == " << mainext[counter*(i)+k] << " && ";
                    }
                    else if(flag_exten == 42 || flag_exten == 52){
                        cout << "(*" << temporary[k] << ") == " << mainext[counter*(i)+k] << " & ";
                    }
                    else assert(0);
                }
                if (flag_exten == 1 || flag_exten == 2 || flag_exten == 6 || flag_exten == 11){
                    cout << temporary[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
                }
                else if(flag_exten == 3 || flag_exten == 4 || flag_exten == 5 || flag_exten == 12){
                    cout << temporary[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " | ";        // just replacing "||" with "|"
                }
                else if(flag_exten == 41 || flag_exten == 51){
                    cout << "(*" << temporary[i-1] << ") == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
                }
                else if(flag_exten == 42 || flag_exten == 52){
                    cout << "(*" << temporary[i-1] << ") == " << mainext[counter*(i)+(i-1)] << " )" << " | ";
                }
                else assert(0);
                counter++;
            }
        }

        if(flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52){
            cout << " 0) " << endl;      // for the last "||"
        }
        
        else if(flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12){      // almost same as flag_exten == 2, just that in place of "if" we are using klee_assume
            if(global_support)
                cout << " 0); " << endl;      // for the last "||"
            else if(!global_support)
                cout << " 0)); " << endl;      // for the last "||", 2 closing brackets here
        }

        else assert(0);
        

        if(!global_support && (flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52)){           // if it is of conflict type we can straight-way exit(0), if the constraint is satisfied as for conflict it should not be satisfied
            // cout << "ext" + enn << " = 0 ;" << endl;
            cout << "exit(0);" << endl;
        }
        
        // Also we don't need to conjunct the var_global in every "if" condition because if it fails, the program exits, so it is implied
        else if (global_support && (flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52)){          // For support type, exit(0) will be in the else part
            // cout << "ext" + enn << " = 1;" << endl;
            cout << var_global << " = 1;" << endl;
            // cout << "else ext" + enn << " = 0;" << endl;
            cout << "else exit(0);" << endl;
        }
        else if (flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12)  // do nothing here, no need to add goto here ofc
            ;
        
        else assert(0);
    }


    // Now we don't need these disjunctions and extention variables as we are using just one variable now, hence there will be directly assert(0) point after the last condition, nothing before that so the changes

    // cout << "int cntdis = 1;" << endl;
    // cout << "int exten = 1;" << endl;
    
    if(cntdisjunctions > 0){
        // cout << "if( ";
        // for (int i = 0; i < cntdisjunctions-1; ++i)
        // {
        //     cout << "myvar" << i << " == 1" << " && ";
        // }
        // cout << "myvar" << cntdisjunctions-1 << " == 1 )" << endl;      // for the last variable
        // cout << "cntdis = 1;" << endl;
        // cout << "else cntdis = 0;" << endl;
    }

    if(extention > 0){          // Now this code is not needed as we now have taken just one variable for extensional constraints as well
        // cout << "if( ";
        // for (int i = 0; i < extention-1; ++i)
        // {
        //     cout << "ext" << extblock[i] << " == 1" << " && ";
        // }
        // cout << "ext" << extblock[extention-1] << " == 1 )" << endl;      // for the last variable
        // cout << "exten = 1;" << endl;
        // cout << "else exten = 0;" << endl;
        // // cout << "printf(\"SAT\\n\");" << endl;
        // // cout << "else printf(\"UNSAT\\n\");" << endl;
    }

    // cout << "if( cntdis == 1 && exten == 1)" << endl << "assert(0);" << endl;
        
    cout << "assert(0);" << endl;
    // cout << "else printf(\"UNSAT\\n\");" << endl;
}


void XCSP3PrintCallbacks::beginGroup(string id) {
    // cout << " start group of constraint " << id << "hello " << endl;
    // currentGroup = new XConstraintGroup(id, "");
    // cout << ConstraintType;
}


void XCSP3PrintCallbacks::endGroup() {
    // cout << " end group of constraint" << endl;
    // delete currentGroup;
    // currentGroup = 0;
}


void XCSP3PrintCallbacks::beginBlock(string classes) {
    // cout << " start block of constraint classes = " << classes << endl;
}


void XCSP3PrintCallbacks::endBlock() {
    // cout << " end group of constraint" << endl;
}


void XCSP3PrintCallbacks::beginSlide(string id, bool circular) {
    // cout << " start slide " << id << endl;
}


void XCSP3PrintCallbacks::endSlide() {
    // cout << " end slide" << endl;
}


void XCSP3PrintCallbacks::beginObjectives() {
    // cout << " start Objective " << endl;
    // some objects related to objective, where to be found, I can code once I have the objects
}


void XCSP3PrintCallbacks::endObjectives() {
    // cout << " end Objective " << endl;
}


void XCSP3PrintCallbacks::buildVariableInteger(string id, int minValue, int maxValue) {
    // cout << " var " << id << " : " << minValue << "..." << maxValue << endl;

    // This is using klee_assumes
    // Even used for extensional constraints when I am using klee_assumes, I am not clubbing these klee_assumes, can be done but leave it
    if(flag_klee == 1 || flag_exten == 3 || flag_exten == 6){      
            cout << "int var" << countvars << ";" << endl;
            string n = "var" + std::to_string(countvars);
            
            if(run_klee == 1){
                cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
                cout << "klee_assume( var" << countvars << " >= " << minValue << " );" << endl << "klee_assume( var" << countvars << " <= " << maxValue  << " );" << endl;
            }
            
            else if(run_klee == 0){
                cout << "var" << countvars << " = __llbmc_nondef_int();" << endl;
                cout << "__llbmc_assume( var" << countvars << " >= " << minValue << " );" << endl << "__llbmc_assume( var" << countvars << " <= " << maxValue  << " );" << endl;
            }

            else assert(0);
    }

    
    // This is pure C code for this function with conditions being broken into different "if" conditions
    else if(flag_klee == 2 || flag_klee == 6 || flag_exten == 1 || flag_exten == 5){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        
        if(run_klee == 1){
            cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        }
        else if(run_klee == 0){
            cout << "var" << countvars << " = __llbmc_nondef_int();" << endl;
        }

        if(done_vars == 0){       // Have declared myvar0 or whichever number myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
        }

        if(flag_exten == 5 || flag_klee == 6){
            cout << "if((" << n << " >= " << minValue << ") & (" << n << " <= " << maxValue << ")) {" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
        else {
            cout << "if((" << n << " >= " << minValue << ") && (" << n << " <= " << maxValue << ")) {" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
    }

    // This is pure C code with all conditions clubbed in one big "if" condition
    // We will print these variables either in the endConstraints() function or in the varaible declaration of type2
    // flag_exten == 4 is just same as == 2 , just replacing logical operators with bitwise logical operators
    else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8 || flag_exten == 2 || flag_exten == 4){

        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        
        if(run_klee == 1){
            cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        }
        else if(run_klee == 0){
            cout << "var" << countvars << " = __llbmc_nondef_int();" << endl;
        }

        vars_type_one[countvars] = std::to_string(minValue) + "_" + std::to_string(maxValue);       // Now this has all the required variables with their ranges 
    }

    
    else if(flag_klee == 41){
        cout << "int* var" << countvars << " = (int*)malloc(sizeof(int));" << endl;
        string n = "*var" + std::to_string(countvars);
        
        if(run_klee == 1){
            cout << "klee_make_symbolic(var" << countvars << ", sizeof(int), \"" << n << "\");" << endl;
        }
        else if(run_klee == 0){
            cout << "*var" << countvars << " = __llbmc_nondef_int();" << endl;
        }

        if(done_vars == 0){       // Have declared myvar0 or whichever number myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
        }

        if(flag_exten == 5 || flag_klee == 6){
            cout << "if((" << n << " >= " << minValue << ") & (" << n << " <= " << maxValue << ")) {" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
        else {
            cout << "if((" << n << " >= " << minValue << ") && (" << n << " <= " << maxValue << ")) {" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
    }

    else assert(0);

    arr[countvars] = id;
    countvars++;
}


void XCSP3PrintCallbacks::buildVariableInteger(string id, vector<int> &values) {
    // This implementation won't work as I just can't consider the min and max value, domain can be like 2,4,6 where this approach will fail

    int flag_var_vector = 0;
    
    if(flag_klee == 1 || flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12)       // for flag_exten == 3, we are using klee_assumes, so same as in flag_klee == 1
        flag_var_vector = 3;
    
    else if(flag_klee == 2 || flag_klee == 6 || flag_exten == 1 || flag_exten == 5)     // for C code with conditions being broken into different "if" conditions
        flag_var_vector = 4;
    
    else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8 || flag_exten == 2 || flag_exten == 4 || flag_exten == 42 || flag_exten == 52 || flag_exten == 62)     // for C code with condition in a single "if" conditions, here for all variables in a single if condition
        flag_var_vector = 5;
    
    else if(flag_klee == 41 || flag_exten == 41)
        flag_var_vector = 41;

    else if(flag_exten == 51 || flag_exten == 61)
        flag_var_vector = 51;
    
    else assert(0);

    // This is obsolete type
    if (flag_var_vector == 1){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        // cout << "klee_assume ( var" << countvars << " >= " << minValue << " );" << endl << "klee_assume( var" << countvars << " <= " << maxValue  << " );" << endl;
        cout << "int myvar" << cntdisjunctions << ";" << endl;
        cout << "if (" << n << " == " << values[0];
        for (int i = 1; i < values.size(); ++i)
        {
            cout << " || " << n << " == " << values[i];
        } 
        string q = "myvar" + std::to_string(cntdisjunctions);   // THis is the disjunction variable for the particular case.
        cntdisjunctions++;
        cout << " ) {" << q << "= 1;}" << endl  << "else {" << q << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;
    }

    // Now changing strategy for declaring variables for with domain of type of a vector. 
    // This will allocate just one variable for declaring range of all such variables, use reduction in no of variables used
    // Difference btw this and in which flag_var_vector == 4, is that 4th one eliminates the non-possible values between min and max, whereas here it enumerates only the possible values
    // This is a version of pure C code. Another is flag_var_vector == 4
    else if(flag_var_vector == 2){
         cout << "int var" << countvars << ";" << endl;
         string n = "var" + std::to_string(countvars);
         if(run_klee == 1){
            cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
            }

         else if(run_klee == 0){
            cout << "var" << countvars << " = __llbmc_nondef_int();" << endl;
            }
         if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
         }
            cout << "if ((" << var_global << " == 1) && (" << n << " == " << values[0];     // This is doen to enable short-circuiting
            for (int i = 1; i < values.size(); ++i)
            {
                cout << " || " << n << " == " << values[i];
            }
            cout << ") {" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;
    }

    // This strategy will not use any variable for declaring but only klee_assume, it can reduce the number of paths for KLEE
    // Used in case when flag_exten == 3, delacre variables using klee_assumes
    else if(flag_var_vector == 3){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        auto minmax = std::minmax_element(std::begin(values), std::end(values));
        int min = *(minmax.first);
        int max = *(minmax.second);

        if(run_klee == 1){
            cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
            cout << "klee_assume(" << n << " >= " << min << ");\n";
            cout << "klee_assume(" << n << " <= " << max << ");\n";
        }
        else if(run_klee == 0){
            cout << "var" << countvars << " = __llbmc_nondef_int();" << endl;
            cout << "__llbmc_assume(" << n << " >= " << min << ");\n";
            cout << "__llbmc_assume(" << n << " <= " << max << ");\n";
        }
    
        

        // now klee_assumes for removing the values which do not occur in domain for each variable
        for (int i = min; i < max; ++i)
        {
            int decide = 0;
            for (int j = 0; j < values.size(); ++j)
            {
                if(i == values[j])
                    decide = 1;         // I am not using break here, because I am not sure whether "break" will only break from inside loop or outside as well, I don't want to break from outside loop
                    // if decide == 1 then that value is present in the array, else it is absent, then that variable can't take that absent value
            }
            if (decide == 0){
                if(run_klee == 1)
                    cout << "klee_assume(" << n << " != " << i << ");\n";
                else if(run_klee == 0)
                    cout << "__llbmc_assume(" << n << " != " << i << ");\n";
            }
        }
    }

    // This is the implementation in only C code, no klee_assumes, ofc klee_make_symbolic will be there. This will be C code version for
    // flag_var_vector == 3, will implement later
    else if(flag_var_vector == 4){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        auto minmax = std::minmax_element(std::begin(values), std::end(values));
        int min = *(minmax.first);
        int max = *(minmax.second);

        if(run_klee == 1){
            cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        }
        else if(run_klee == 0){
            cout << "var" << countvars << " = __llbmc_nondef_int();" << endl;
        }
        
        if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
         }
         if(flag_exten == 5 || flag_klee == 6){
             cout << "if((" << n << " >= " << min << ") & (" << n << " <= " << max << ") & ";   // just using bitwise operators
         }
        
        else {
            cout << "if((" << n << " >= " << min << ") && (" << n << " <= " << max << ") && "; 
        }
         
         for (int i = min; i < max; ++i)
         {
            int decide = 0;
            for (int j = 0; j < values.size(); ++j)
            {
                if(i == values[j])
                    decide = 1;         // I am not using break here, because I am not sure whether "break" will only break from inside loop or outside as well, I don't want to break from outside loop
                    // if decide == 1 then that value is present in the array, else it is absent, then that variable can't take that absent value
            }
            if (decide == 0){
                if(flag_exten == 5 || flag_klee == 6){
                    cout << "(" << n << " != " << i << ") & "; // using bitwise operator
                }
                else {
                    cout << "(" << n << " != " << i << ") && "; 
                }
            }
         }
         cout << "1) {" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;
        
    }


    // This will be pure C code with all atomic "if" conditions related to delaring variables of this type in a single "if" condition 
    else if(flag_var_vector == 5){
        string n, k;
        if(flag_exten == 42){
            cout << "int* var" << countvars << " = (int*)malloc(sizeof(int));" << endl;
            n = "*var" + std::to_string(countvars);     // the name will be this
        }
        else if(flag_exten == 52 || flag_exten == 62){
            cout << "int* var" << countvars << ";" << endl;
            n = "*var" + std::to_string(countvars);     // the name will be this
            k = "var" + std::to_string(countvars); 
        }
        else{
            cout << "int var" << countvars << ";" << endl;
            n = "var" + std::to_string(countvars);
        }
        
        auto minmax = std::minmax_element(std::begin(values), std::end(values));
        int min = *(minmax.first);
        int max = *(minmax.second);

        if(flag_exten == 42){
            if(run_klee == 1){
                cout << "klee_make_symbolic(var" << countvars << ", sizeof(int), \"" << n << "\");" << endl;
            }
            else if(run_klee == 0){
                cout << "*var" << countvars << " = __llbmc_nondef_int();" << endl;
            }
        }
        
        else if(flag_exten == 52 || flag_exten == 62) {
            if(run_klee == 1 && flag_exten == 52){
                cout << "klee_make_symbolic(&cond0, sizeof(cond0), \"cond0\");" << endl;        // The middle guy has sizeof(int) as we want to make what var1 points to as symbolic, address can't be symbolic
                cout << "if (cond0) {\n\t dummy += 1;" << endl;
                cout << "\tvar" << countvars << " = malloc(sizeof(int));\n}" << endl;      // Not sure if it works
                cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n\t dummy +=2;\n}\n";
                cout << "klee_make_symbolic(var" << countvars << ", sizeof(int), \"" << n << "\");" << endl;        // The middle guy has sizeof(int) as we want to make what var1 points to as symbolic, address can't be symbolic 
             }
            
            else if(run_klee == 1 && flag_exten == 62){
                cout << "if (m < N) {\n\t" << k << " = &dummy;\n}" << endl;
                cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n}\n";
                cout << "klee_make_symbolic(var" << countvars << ", sizeof(int), \"" << n << "\");" << endl;
            }
            
            else if(run_klee == 0 && flag_exten == 62){
                cout << "if (m < N) {\n\t" << k << " = &dummy;\n}" << endl;
                cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n}\n";
                cout << "*var" << countvars << " = __llbmc_nondef_int();\n";
            }

            else if(run_klee == 0 && flag_exten == 52){
                cout << "cond0 = __llbmc_nondef_int();" << endl;
                cout << "if (cond0) {\n\t dummy += 1;" << endl;
                cout << "\tvar" << countvars << " = malloc(sizeof(int));\n}" << endl;      // Not sure if it works
                cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n\t dummy +=2;\n}\n";
                cout << "*var" << countvars << " = __llbmc_nondef_int();\n";
             }
        }
        
        
        else {
            if(run_klee == 1){
                cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
            }
            else if(run_klee == 0){
                cout << "var" << countvars << " = __llbmc_nondef_int();" << endl;
            }
        }
        
        vars_type_two[countvars] = std::to_string(min) + "_" + std::to_string(max);
        int decide;

        for (int i = min; i < max; ++i)
         {
            decide = 0;
            for (int j = 0; j < values.size(); ++j)
            {
                if(i == values[j])
                    decide = 1;         // I am not using break here, because I am not sure whether "break" will only break from inside loop or outside as well, I don't want to break from outside loop
                    // if decide == 1 then that value is present in the array, else it is absent, then that variable can't take that absent value
            }
            if (decide == 0){
                vars_type_two[countvars] += ("_" + std::to_string(i));    // the underscore just separates the values
            }
         }
    }

    
    // This is for declaring variables dynamically. Just the declaration is dynamic, rest everything is same
    else if(flag_var_vector == 41){
     cout << "int* var" << countvars << ";\n\t var" << countvars << " = (int*)malloc(sizeof(int));" << endl;
     string n = "*var" + std::to_string(countvars);     // the name will be this
     if(run_klee == 1){
        cout << "klee_make_symbolic(var" << countvars << ", sizeof(int), \"" << n << "\");" << endl;        // The middle guy has sizeof(int) as we want to make what var1 points to as symbolic, address can't be symbolic
      }
    
      else if(run_klee == 0){
        cout << "*var" << countvars << " = __llbmc_nondef_int();" << endl;      // Not sure if it works
     }
     
      if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
     }
        cout << "if (" << n << " == " << values[0];     // This is doen to enable short-circuiting
        for (int i = 1; i < values.size(); ++i)
        {
            cout << " || " << n << " == " << values[i];
        }
        cout << ") {" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;
    }

    
    else if(flag_var_vector == 51){
         cout << "int* var" << countvars << ";" << endl;
         string n = "*var" + std::to_string(countvars);     // the name will be this
         string k = "var" + std::to_string(countvars); 
         
         if(run_klee == 1 && flag_exten == 51){
            cout << "klee_make_symbolic(&cond0, sizeof(cond0), \"cond0\");" << endl;        // The middle guy has sizeof(int) as we want to make what var1 points to as symbolic, address can't be symbolic
            cout << "if (cond0) {\n\t dummy += 1;" << endl;
            cout << "\tvar" << countvars << " = malloc(sizeof(int));\n}" << endl;      // Not sure if it works
            cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n\t dummy +=2;\n}\n";
            cout << "klee_make_symbolic(var" << countvars << ", sizeof(int), \"" << n << "\");" << endl;        // The middle guy has sizeof(int) as we want to make what var1 points to as symbolic, address can't be symbolic 
          }
        
         else if(run_klee == 1 && flag_exten == 61){
            cout << "if (m < N) {\n\t" << k << " = &dummy;\n}" << endl;
            cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n}\n";
            cout << "klee_make_symbolic(var" << countvars << ", sizeof(int), \"" << n << "\");" << endl;
         }

          else if(run_klee == 0 && flag_exten == 51){
            cout << "cond0 = __llbmc_nondef_int();" << endl;
            cout << "if (cond0) {\n\t dummy += 1;" << endl;
            cout << "\tvar" << countvars << " = malloc(sizeof(int));\n}" << endl;      // Not sure if it works
            cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n\t dummy +=2;\n}\n";
            cout << "*var" << countvars << " = __llbmc_nondef_int();\n";
         }

          else if(run_klee == 0 && flag_exten == 61){
            cout << "if (m < N) {\n\t" << k << " = &dummy;\n}" << endl;
            cout << "else {\n\t" << "var" << countvars << " = malloc(sizeof(int));\n}\n";
            cout << "*var" << countvars << " = __llbmc_nondef_int();\n";
          }
         
          if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
         }
            cout << "if (" << n << " == " << values[0];     // This is doen to enable short-circuiting
            for (int i = 1; i < values.size(); ++i)
            {
                cout << " || " << n << " == " << values[i];
            }
            cout << ") {" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;
    }


    // int *var0;
    // int cond0 = __llbmc_nondef_int();
    // if (cond0) {
    //    dummy += 1;
    //    var0 = malloc(sizeof(int));
    // } else {
    //    var0 = malloc(sizeof(int));
    //    dummy += 2;
    // }


    else assert(0);

    arr[countvars] = id;
    countvars++;
}


void XCSP3PrintCallbacks::buildConstraintExtension(string id, vector<XVariable *> list, vector <vector<int> > &tuples, bool support, bool hasStar) 
{
    // cout << "\n    extension constraint : " << id << endl;
    // cout << "        " << (support ? "support" : "conflict") << " arity:" << list.size() << " nb tuples: " << tuples.size() << " star: " << hasStar << endl;
    // cout << "        ";

    // Now I will try to club many constraints of same type in a single block, for this, I will create a global variable array
    // Which will be checked when ever it hits this function, if it will empty then perhaps this function might be being hit for first time
    // but if the array is not time, it indicates a change of type of extensional constraint and hence a "if" condition will be printed
    // Last one will be printed in the endConstraints function
    // The name of the current_exten will be the first be the combination of the first argument to this extensional constraint, because other arguments to this will to the ExtensionAs function, add them there
    // Basically change of the block is what is enn != currentextblock , already implemented :). 
    // So basically what has to be done is nothing big, just add the arguments from ExtensionAs function to the mainext array, it will automatically get printed


    int flagext = 3;
    supp = support;  // This is used for printing the last block of constraint, for flagext == 3

    if(flagext == 1)        // all the conditions have different variables, named myvar1,...
    {
        string n[100];      // allowing only for 100 length tuples in extension variables
        if(!support){
            for (int i = 0; i < list.size(); ++i)
            {   
                for(int j = 0; j < 1000;  ++j){
                    if(arr[j] == list[i]->id){
                        n[i] = "var" + std::to_string(j); // now i has the list of variables
                    } 
                }
            }

            for (int i = 0; i < tuples.size(); ++i)
            {
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                cout << "if(";
                for(int j = 0; j < list.size(); ++j){
                    cout << n[j] << " == " << tuples[i][j] << " && ";
                }
                cout << " 1 " << ")" << endl;       // "1" is added ot adjust the last "&&" which gets printed
                string q = "myvar" + std::to_string(cntdisjunctions);   // THis is the disjunction variable for the particular case.
                cntdisjunctions++;
                cout << q << " = 0;" << endl;
            }
        
        }

        else if (support){
            for (int i = 0; i < list.size(); ++i)
            {   
                for(int j = 0; j < 1000;  ++j){
                    if(arr[j] == list[i]->id){
                        n[i] = "var" + std::to_string(j);  break;     // now i has the list of variables
                    } 
                }
            }

            for (int i = 0; i < tuples.size(); ++i)
            {
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                cout << "if(";
                for(int j = 0; j < list.size(); ++j){
                    cout << n[j] << " == " << tuples[i][j] << " && ";
                }
                cout << " 1 " << ")" << endl;       // "1" is added ot adjust the last "&&" which gets printed
                string q = "myvar" + std::to_string(cntdisjunctions);   // THis is the disjunction variable for the particular case.
                cntdisjunctions++;
                cout << q << " = 1;" << endl;
            }

        }
    }
    
    
    else if(flagext == 2){    // lesser variables
        string enn = "";      // storing the tuples temporarily
        int started = 0;
        string temp[10000];         // store the vars temporarily
        bool exists1, exists2;
        
        for(int i = 0; i < list.size(); ++i)
        {   
            for(int j = 0; j < 1000;  ++j)
            {
                if(arr[j] == list[i]->id)
                {
                    if(!(exists1 = std::find(std::begin(ext), std::end(ext), "var" + std::to_string(j)) != std::end(ext)))
                    { 
                        // enters only if there the var is not in the list
                        ext[extens] = "var" + std::to_string(j); // now i has the list of variables
                        extens++ ;
                    }
                    temp[i] = std::to_string(j);
                    enn += std::to_string(j);      // store temporarily something like "15" or "948"
                } 
            }
        }
            
        
        if(!(exists2 = std::find(std::begin(extblock), std::end(extblock), enn) != std::end(extblock))){
            extblock[extention] = enn;
            cout << "int ext" << enn << " = 1;" << endl;
            extention++;
        }


        if(!support)        // case of conflict
        {
            for (int i = 0; i < tuples.size(); ++i)
            {
                cout << "if(";
                for(int j = 0; j < list.size(); ++j){
                    cout << "var" + temp[j] << " == " << tuples[i][j] << " && ";
                }
                cout << " 1 " << ")" << endl;       // "1" is added ot adjust the last "&&" which gets printed
                string q = "ext" + enn;   // THis is the disjunction variable for the particular case.
                // cout << q << " = 0;" << endl;
                cout << "exit(0);" << endl;
            }
        }

        else if(support)
        {
            for (int i = 0; i < tuples.size(); ++i)
            {
                cout << "if(";
                for(int j = 0; j < list.size(); ++j){
                    cout << ext[j] << " == " << tuples[i][j] << " && ";
                }
                cout << " 1 " << ")" << endl;       // "1" is added ot adjust the last "&&" which gets printed
                string q = "ext" + enn;   // THis is the disjunction variable for the particular case.
                // cout << q << " = 1;" << endl;
                cout << var_global << " = 1;" << endl;
                cout << "else exit(0);" << endl;
            }
        }

    }

    else if(flagext == 3)
    {  // lesser variables but all the conditions of a block within the same if conditon
        // in the second case, it was very similar but the if conditons were broken on the "||" operator
        string enn = ""; string temp[100];

        for(int i = 0; i < list.size(); ++i)
            {   
                for(int j = 0; j < 1000;  ++j)
                {
                    if(arr[j] == list[i]->id)
                    {             
                        temp[i] = std::to_string(j);
                        enn += (std::to_string(j) + "_");      // store temporarily something like "1 5" or "9 48"
                    } 
                }
            }

        
        if(enn != currentextblock){  // this might occur for the first block and whenever the change of block occurs
            // cout << enn << "   "  << currentextblock << endl;

            // this will occur for the first block of extensional constraint
            // Don't print constraints for first block until it changes the block, so, this is done for flag_exten == 2
                if(no_tuples == 0){
                    // cout << "CASE1" << endl;
                    currentextblock = enn;
                    for (int i = 0; i < tuples.size(); ++i){
                        for(int j = 0; j < list.size(); ++j){
                            mainext[no_tuples] = tuples[i][j];
                            no_tuples++;
                        }
                   }
                   exten_array[counter_extensional] = enn;
                   counter_extensional++;
                   global_support = support;
               }
            
                
                else if(no_tuples != 0) {       // this will occur when change of blocks occur and hence hence printing should be performed here
                                                // Also things must be refreshed for next block
                    // cout << "CASE2" << endl;
                   //  no_tuples = 0;
                   //  currentextblock = enn;      // this is the enn with underscores
                    
                   //  for (int i = 0; i < tuples.size(); ++i){
                   //      for(int j = 0; j < list.size(); ++j){
                   //          mainext[no_tuples] = tuples[i][j];
                   //          no_tuples++;
                   //          // cout << tuples[i][j] << endl;
                   //      }
                   // }


                    // In this implementation using underscores as separator, i must not be decremented by 1 

                    extblock[extention] = enn;
                        // cout << "int ext" << enn << " = 1;" << endl;
                    extention++;

                    if(flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52){
                        cout << "if(";
                    }
                    
                    else if((flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12) && run_klee == 1)  {    // almost same as flag_exten == 2, just that in place of "if" we are using klee_assume
                        if(support)
                            cout << "klee_assume(";
                        else if(!support)
                            cout << "klee_assume(!(";
                    }
                    
                    else if((flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12) && run_klee == 0) {      // almost same as flag_exten == 2, just that in place of "if" we are using klee_assume
                        if(global_support)
                            cout << "__llbmc_assume(";
                        else if(!global_support)
                            cout << "__llbmc_assume(!(";
                    }
                    
                    else assert(0);

                    for (int cnt = 0; cnt < counter_extensional; ++cnt)
                    { 
                        string temporary[100];
                        // std::istringstream iss(currentextblock); string enn2 = "";
                        int i = 0;
                        std::stringstream test(exten_array[cnt]);   // for this particular element of the array
                        std::string segment;
                        std::vector<std::string> seglist;

                        while(std::getline(test, segment, '_'))
                        {
                           seglist.push_back(segment);
                           temporary[i] = "var" + seglist[i];
                           i++;             // This is always the length of the tuple
                        }

                        int counter = 0;
                        while(counter < (no_tuples/i))
                        {    
                            cout << "( ";
                            for(int k = 0; k < i-1; k++){    // or maybe k <= i, but not list.size as block has changed
                                if(flag_exten == 1 || flag_exten == 2 || flag_exten == 6 || flag_exten == 11){
                                    cout << temporary[k] << " == " << mainext[counter*(i)+k] << " && ";
                                }
                                else if(flag_exten == 3 || flag_exten == 4 || flag_exten == 5 || flag_exten == 12){       // Here flag_exten == 4 and == 5 will be same as with klee_assume (as flag_exten == 3)
                                    cout << temporary[k] << " == " << mainext[counter*(i)+k] << " & ";      // just replacing "&&" with "&"
                                }
                                else if(flag_exten == 41 || flag_exten == 51){
                                    cout << "(*" << temporary[k] << ") == " << mainext[counter*(i)+k] << " && ";
                                }
                                else if(flag_exten == 42 || flag_exten == 52){
                                    cout << "(*" << temporary[k] << ") == " << mainext[counter*(i)+k] << " & ";      // just replacing "&&" with "&"
                                }
                                else assert(0);
                            }

                            if (flag_exten == 1 || flag_exten == 2 || flag_exten == 6 || flag_exten == 11){
                                cout << temporary[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
                            }
                            else if(flag_exten == 3 || flag_exten == 4 || flag_exten == 5 || flag_exten == 12){    // Here flag_exten == 4 and == 5 will be same as with klee_assume (as flag_exten == 3)
                                cout << temporary[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " | ";        // just replacing "||" with "|"
                            }
                            else if(flag_exten == 41 || flag_exten == 51){
                                cout << "(*" << temporary[i-1] << ") == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
                            }
                            else if(flag_exten == 42 || flag_exten == 52){
                                cout << "(*" << temporary[i-1] << ") == " << mainext[counter*(i)+(i-1)] << " )" << " | ";        // just replacing "||" with "|"
                            }
                            else assert(0);
                            counter++;
                        }
                    }

                    if(flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52){
                        cout << " 0) " << endl;      // for the last "||"
                    }
                    
                    else if(flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12) {      // almost same as flag_exten == 2, just that in place of "if" we are using klee_assume
                        if(support)
                            cout << " 0); " << endl;      // for the last "||"
                        else if(!support)
                            cout << " 0)); " << endl;      // for the last "||", 2 closing brackets here
                    }
                    else assert(0);

                   // flag_exten == 3 it is klee_assume so no exit(0)
                   if(!support && (flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52)){           // if it is of conflict type we can straight-way exit(0), if the constraint is satisfied as for conflict it should not be satisfied
                        // cout << "ext" + enn << " = 0 ;" << endl;
                        cout << "exit(0);" << endl;
                    }
                    
                    // Also we don't need to conjunct the var_global in every "if" condition because if it fails, the program exits, so it is implied
                    else if (support && (flag_exten == 1 || flag_exten == 2 || flag_exten == 4 || flag_exten == 5 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52)){          // For support type, exit(0) will be in the else part
                        // cout << "ext" + enn << " = 1;" << endl;
                        cout << var_global << " = 1;" << endl;
                        // cout << "else ext" + enn << " = 0;" << endl;
                        cout << "else exit(0);" << endl;
                    }
                    
                    else if (flag_exten == 3 || flag_exten == 6 || flag_exten == 11 || flag_exten == 12)  // do nothing here, no need to add goto here
                        ;
                    
                    else assert(0);
                    
                    // Now code for refreshing things for this new block
                    
                    currentextblock = enn;      // this is the enn with underscores
                    no_tuples = 0;
                    counter_extensional = 0;         // reset this guy
                    global_support = support;       // for this new guy
                    for (int i = 0; i < tuples.size(); ++i){
                        for(int j = 0; j < list.size(); ++j){
                            mainext[no_tuples] = tuples[i][j];
                            no_tuples++;
                        }
                     }
                   exten_array[counter_extensional] = enn;
                   counter_extensional++;

            }
        }

    }

    
    // This is incomplete
    else if(flagext == 4){
        // This will be the modularised version of extensional constraint
        // length is the no of elements in one tuple
        // size is the no of tuples in the conflict clause
        if(once != 1){
            cout << "void extenconstraint (char list[20][20], int tuples[200][10], int length, int size) {" << endl; 
            cout << "for(int i = 0; i < size; ++i){" << endl;
            cout << "for(int j = 0; j < length; ++j)" << endl << "{" << endl;
            cout << "if(list[j] == tuples[i][j]) printf(\"UNSAT\n\");" << endl; 
            cout << "}" << endl << "}" << endl;
            once = 1;
        }

        string n[100];
        for (int i = 0; i < list.size(); ++i)
        {   
            for(int j = 0; j < 1000;  ++j){
                if(arr[j] == list[i]->id){
                    n[i] = "var" + std::to_string(j);      // now i has the list of variables
                } 
            }
        }
    }

    else assert(0);
}


void XCSP3PrintCallbacks::buildConstraintExtension(string id, XVariable *variable, vector<int> &tuples, bool support, bool hasStar) {
    cout << "\n    extension constraint with one variable: " << id << endl;
    cout << "  " << (support ? "support" : "conflict") << " nb tuples: " << tuples.size() << " star: " << hasStar << endl;
    cout << (*variable) << endl;
}


// This function is called when a type of extensional constraint has several agruments
void XCSP3PrintCallbacks::buildConstraintExtensionAs(string id, vector<XVariable *> list, bool support, bool hasStar) {

    // cout << "  " << (support ? "support" : "conflict") << " nb tuples: " << " star: " << hasStar << endl;

    // In this type of version all the arguments of a extensional constraint will be broken into independent "if" condition

    if(flag_exten == 1 || flag_exten == 5 || flag_exten == 11 || flag_exten == 12){
        string enn = ""; string temp[100];
        int counthere = 0;
        
        for(int i = 0; i < list.size(); ++i)
        {   
            for(int j = 0; j < 1000;  ++j)
            {
                if(arr[j] == list[i]->id)
                {             
                    temp[i] = "var" + std::to_string(j);
                    enn += (std::to_string(j) + "_");      // store temporarily something like "1 5" or "9 48"
                } 
            }
        }
        extblock[extention] = enn;
        // cout << "int ext" << enn << " = 1;" << endl;
        extention++;

        if (flag_exten == 1 || flag_exten == 5)
            cout << "if(";
        else if (flag_exten == 11 || flag_exten == 12){
            if(run_klee == 1) {
                if (support) {
                    cout << "klee_assume(";
                } else {
                    cout << "klee_assume(!(";
                }
            }
            else if(run_klee == 0) {
                if (support) {
                    cout << "__llbmc_assume(";
                } else {
                    cout << "__llbmc_assume(!(";
                }
            }
            else assert(0);
        }   
        else assert(0);

        int counter = 0;
        int i = list.size();
        while(counter < (no_tuples/i))
        {    
            cout << "( ";
            for(int k = 0; k < i-1; k++){    // or maybe k <= i, but not list.size as block has changed
                if(flag_exten == 5 || flag_exten == 12){        // using bitwise operators
                    cout << temp[k] << " == " << mainext[counter*(i)+k] << " & ";
                }
                else {
                    cout << temp[k] << " == " << mainext[counter*(i)+k] << " && ";
                }
            }
            if(flag_exten == 5|| flag_exten == 12){
                cout << temp[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " | ";    // using bitwise operators
            }
            else {
               cout << temp[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " || "; 
            }

            counter++;
        }
        
        if (flag_exten == 1 || flag_exten == 5)
            cout << " 0) " << endl;      // for the last "||"
        else {
            if(support)
                cout << " 0); " << endl;      // for the last "||"
            else if(!support)
                cout << " 0)); " << endl;      // for the last "||", 2 closing brackets here
        }
        
        if (flag_exten == 1 || flag_exten == 5){
            if(!support){
                // cout << "ext" + enn << " = 0 ;" << endl;
                cout << "exit(0);" << endl;
            }
            else if(support){
                // cout << "ext" + enn << " = 1;" << endl;
                cout << var_global << " = 1;" << endl;
                // cout << "else ext" + enn << " = 0;" << endl;
                cout << "else exit(0);" << endl;
            }
        }

    }

    // In this case all arguments of a given extensional constraint will be added in the mainext array and will be printed as single "if" condition

    else if(flag_exten == 2 || flag_exten == 3 || flag_exten == 4 || flag_exten == 6 || flag_exten == 41 || flag_exten == 42 || flag_exten == 51 || flag_exten == 52){
        string enn = ""; string temp[100];
        int counthere = 0;
        
        for(int i = 0; i < list.size(); ++i)
        {   
            for(int j = 0; j < 1000;  ++j)
            {
                if(arr[j] == list[i]->id)
                {             
                    temp[i] = "var" + std::to_string(j);
                    enn += (std::to_string(j) + "_");      // store temporarily something like "1 5" or "9 48"
                } 
            }
        }

        // so now you have enn that is the variable list as a argument in the extensional constraint
        // Just adding this in the exten_array, and later it will be printed in the Extension block
        exten_array[counter_extensional] = enn;
        // cout << enn << getchar();
        counter_extensional++;
    }

    else assert(0);
}


void XCSP3PrintCallbacks::buildConstraintIntension(string id, string expr){
    // cout << "\n  intension constraints : " << id << " : " << expr << endl;
    // handling some cases 
    
    string elm1, elm2, elm3, elm4, elm5, elm6, elm7;

    // XConstraintInstension *c = new XConstraintIntension(id, expr);

    // std::vector<XVariable *> arguments;
    // XConstraint *original;

    // c->unfoldParameters(currentGroup, arguments, original);

    int which;
    int type = 0;  // Lets take by default
    
    // or(and(eq(dist(div(%0,100),div(%1,100)),1),eq(dist(mod(%0,100),mod(%1,100)),2)),and(eq(dist(div(%0,100),div(%1,100)),2),eq(dist(mod(%0,100),mod(%1,100)),1)))
    if(expr.find("or") < expr.find("and") && expr.find("and") < expr.find("eq") && expr.find("eq") < expr.find("dist") && expr.find("dist") < expr.find("div") && expr.find("div") < expr.size())
        type = 13;

    // For cases with and(ne(%0,%1),ge(add(%2,%3),2))
    else if (expr.find("and") < expr.find("ne") && expr.find("ne") << expr.find("ge") && expr.find("ge") << expr.find("add") && expr.find("add") < expr.size())
        type = 2;

    // gt(0,mul(sub(%0,%1),sub(%2,%3)))
    else if(expr.find("gt") < expr.find("mul") && expr.find("mul") << expr.find("sub") && expr.find("sub") < expr.size())
        type = 3;

    // eq(sub(%0,%1),%2)
    else if(expr.find("eq") < expr.find("sub") && expr.find("sub") < expr.size())
        type = 4;

    // ne(sub(x[0],x[8]),sub(x[1],x[9]))
    else if(expr.find("ne") < expr.find("sub") && expr.find("sub") < expr.size())
        type = 5;

    // eq(mod(add(%0,%1,%2),%3),%4)
    else if(expr.find("eq") < expr.find("mod") && expr.find("mod") < expr.find("add") && expr.find("add") < expr.size())
        type = 7;

    // eq(div(add(%0,%1,%2),%3),%4)
    else if(expr.find("eq") < expr.find("div") && expr.find("div") < expr.find("add") && expr.find("add") < expr.size())
        type = 8;
    
    // eq(%0,dist(%1,%2))
    else if(expr.find("eq") < expr.find("dist") && expr.find("dist") < expr.size())
        type = 6;

    // ne(%0,dist(%1,%2))
    else if(expr.find("ne") < expr.find("dist") && expr.find("dist") < expr.size())
        type = 11;
    
    // eq(%0,add(%1,%2))
    else if(expr.find("eq") < expr.find("add") && expr.find("add") < expr.size())
        type = 12;

    // Keep these two always at last, you can understand why these are least competitive
    // ne(%0,%1)
    
    else if(expr.find("ne") < expr.size())
        type = 9;

    // eq(%0,%1)
    else if(expr.find("eq") < expr.size())
        type = 10;

    else assert(0);

    // this is now a dead code was used earlier
    if(type == 1)
    {
        if(expr.find("add(") < expr.size()){
            which = 1;
            std::size_t ps1 = expr.find("eq");
            std::size_t ps2 = expr.find("add(");
            std::size_t ps3 = expr.find(",");  // returns the first postion, i guess, so it is for the "eq"
            
            elm1 = expr.substr(ps1+3, ps3-ps1-3);     // length upto comma
            elm2 = expr.substr(ps2+4, expr.size()-ps2-4-2); // the add expression , the last 2 subtracted for removing the last 2 brackets
            std::size_t ps4 = elm2.find(",");           // this finds the comma of the add
            elm3 = elm2.substr(0, ps4);
            elm4 = elm2.substr(ps4+1, elm2.size()-ps4-1);
            // cout << "elm1 :" << elm1 << endl << "elm2 :" << elm2 << endl << "elm3 :" << elm3 << endl << "elm4 :" << elm4 << endl;
        }
        
        
        if(expr.find("dist(") < expr.size()){
            which = 2;
            std::size_t ps1 = expr.find("eq");
            std::size_t ps2 = expr.find("dist(");
            std::size_t ps3 = expr.find(",");  // returns the first postion, i guess, so it is for the "eq"
            
            elm1 = expr.substr(ps1+3, ps3-ps1-3);     // length upto comma
            elm2 = expr.substr(ps2+5, expr.size()-ps2-5-2); // the add expression , the last 2 subtracted for removing the last 2 brackets
            std::size_t ps4 = elm2.find(",");           // this finds the comma of the add
            elm3 = elm2.substr(0, ps4);
            elm4 = elm2.substr(ps4+1, elm2.size()-ps4-1);
        }

        // cout << elm1 << endl << elm3 << endl << elm4 << endl;

        int flagint = 2;
        // this gives me the 3 variables in the relation x + y = z;
        string temp[100]; int k = 0;
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
                k++;
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
                k++;
            }
            if (elm4 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
                k++;
            }
        }

        // cout << "elm1: " << temp[0]  << " elm2: " << temp[1] << " elm3 : " << temp[2] <<endl;

        if(which == 1){  // Case of add, no need of "if" statements
            cout << "klee_assume(" << temp[0] <<  " == " << temp[1] << " + "  << temp[2] <<  ");" << endl;
        }
        
        // cout << cntdisjunctions << endl;
        if(which == 2 && flagint == 1){   // case of dist in which for each constraint there is a different variable
            cout << "int myvar" << cntdisjunctions << ";" << endl;
            cout << "if(" << temp[0] << " == " << temp[1] << " - " << temp[2] << ")" << endl;
            cout << "myvar" + std::to_string(cntdisjunctions) << " = 1;" << endl;
            cout << "else if(" << temp[0] << " == " << temp[2] << " - " << temp[1] << ")" << endl;
            cout << "myvar" + std::to_string(cntdisjunctions) << " = 1;" << endl;
            cout << "else " << "myvar" + std::to_string(cntdisjunctions) << " = 0;" << endl;
            cntdisjunctions++;
        }

        // from the objects build the constraints in form of klee_assume
        
        // This is the case of "dist" in which each constraint has same variable
        else if (which == 2 && flagint == 2){
            // I hope this formula of using of cntdisjunctions doesn't create problem with other function using the same cntdisjunctions
            if (done_int == 0){
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                cntdisjunctions = 1;
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                done_int = 1;
            }
            cout << "if((" << temp[0] << " == " << temp[1] << " - " << temp[2] << " || " <<
             temp[0] << " == " << temp[2] << " - " << temp[1] << ") && " << " myvar" << cntdisjunctions-1 << " == 1 )" << endl;     // The -1 in cntdisjunctions is needed, don't remove
             // this condition is essential because at no previous condition should this variable be 0
            cout << "myvar" + std::to_string(cntdisjunctions-1) << " = 1;" << endl;
            cout << "else " << "myvar" + std::to_string(cntdisjunctions-1) << " = 0;" << endl;      // The -1 in cntdisjunctions is needed, don't remove
            // here cntdisjunctions is not incremented so, the same variable holds for all intension variable
            // this works because in if condition the fact is included that at any previous condition it has not failed
        }
    
    }

    
    // For cases with and(ne(%0,%1),ge(add(%2,%3),2))
    else if(type == 2)
    {
        int first = expr.find(",");             // gives position for first comma
        int ne = expr.find("ne");
        int firclose = expr.find(")");          // gives position of the first ) position.
        int ge = expr.find("ge");
        string subs1 = expr.substr(ge);
        int sec = subs1.find(",");          // gives position of comma inside the "ge" bracket
        int add = subs1.find("add");            // gives position of "and" inside the "ge" bracket
        int secclose = subs1.find(")");
        elm1 = expr.substr(ne+3, first-ne-3);
        // cout << "ELm1:" << elm1 << "\n";
        elm2 = expr.substr(first+1, ge-2-first-1);
        // cout << "ELm2:" << elm2 << "\n";
        elm3 = subs1.substr(add+4, sec-add-4);
        // cout << "ELm3:" << elm3 << "\n";
        elm4 = subs1.substr(sec+1, secclose-1-sec);
        // cout << "ELm4:" << elm4 << "\n";

        string temp[100]; int k = 0;
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
                k++;
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
                k++;
            }

            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
                k++;
            }
            if (elm4 == arr[j]){
                std::string s = std::to_string(j);
                temp[3] = "var" + s;            // the temp should be like var"j"
                k++;
            }
        }
        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << " != " << temp[1] << " );\n";  // for the first condition of klee "a != b"
            cout << "klee_assume(" << temp[2] << " + " << temp[3] << " >= 2" << ");\n";  // for the second condition that " a + b >= 2"
        }
        // Now I will write C code for this
        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 6){
                cout << "if((" << temp[0] << " != " << temp[1] << ") & (" << temp[2] << " + " << temp[3] << " >=2 ))";
            }
            else if(flag_klee == 41){
                cout << "if((*" << temp[0] << " != *" << temp[1] << ") && (*" << temp[2] << " + *" << temp[3] << " >=2 ))";
            }
            else {
                cout << "if((" << temp[0] << " != " << temp[1] << ") && (" << temp[2] << " + " << temp[3] << " >=2 ))";
            }

            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
        }

        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type2[type2] = temp[0] + "_" + temp[1] + "_" + temp[2] + "_" + temp[3];
            type2++;
        } 
        else assert(0);

    }

    // for cases with  gt(0,mul(sub(%0,%1),sub(%2,%3)))
    else if(type == 3){
        string subs1 = expr.substr(expr.find("sub")); //breaks from first sub till end
        int first = subs1.find(",");         // first comma in subs1
        string subs2 = subs1.substr(first);  // breaks from second "sub" till end
        subs2 = subs2.substr(subs2.find("sub"));
        int firclose = subs1.find(")");       // finds the first ")" in subs1 , this is the bracket just after elm2
        int second = subs2.find(",");         // finds the second "," in subs that is the comma after second "sub"
        int lastclose = subs2.find(")");      // finds the first ")" in subs2

        elm1 = subs1.substr(4, first-4);
        // cout << "ELm1:" << elm1 << "\n";
        elm2 = subs1.substr(first+1, firclose-1-first);
        // cout << "ELm2:" << elm2 << "\n";
        elm3 = subs2.substr(4, second-4);
        // cout << "ELm3:" << elm3 << "\n";
        elm4 = subs2.substr(second+1, lastclose-second-1);
        // cout << "ELm4:" << elm4 << "\n"; 
        
        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
            }
            if (elm4 == arr[j]){
                std::string s = std::to_string(j);
                temp[3] = "var" + s;            // the temp should be like var"j"
            }
        } 

        if(flag_klee == 1){
            cout << "klee_assume(0 > (" << temp[0] << " - " << temp[1] << ")*(" << temp[2] << " - " << temp[3] << "));\n";
        }

        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 6){  // here it is same but still for safety making 2 cases
                cout << "if(0 > (" << temp[0] << " - " << temp[1] << ")*(" << temp[2] << " - " << temp[3] << "))";
            }
            else if(flag_klee == 41){
                cout << "if(0 > (*" << temp[0] << " - *" << temp[1] << ")*(*" << temp[2] << " - *" << temp[3] << "))";
            }
            else {
                cout << "if(0 > (" << temp[0] << " - " << temp[1] << ")*(" << temp[2] << " - " << temp[3] << "))";
            }
            
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl;     //exit(0) to curb paths for KLEE 
         }

        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type3[type3] = temp[0] + "_" + temp[1] + "_" + temp[2] + "_" + temp[3];
            type3++;
        } 
        else assert(0);

    }


    // eq(sub(%0,%1),%2)
    else if(type == 4){
        expr = expr.substr(3); // from "sub"
        int first = expr.find(",");     // first comma
        int firclose = expr.find(")");    // first closing bracket
        elm1 = expr.substr(4, first-4);
        elm2 = expr.substr(first+1, firclose-1-first);
        elm3 = expr.substr(firclose+2, expr.size()-firclose-3);
        // cout << "ELm1:" << elm1 << "\n";
        // cout << "ELm2:" << elm2 << "\n";
        // cout << "ELm3:" << elm3 << "\n";

        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
            }
        } 
        
        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << " - " << temp[1] << " == " << temp[2] << ");\n";
        }

        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 6){
                cout << "if((" << temp[0] << " - " << temp[1] << " == " << temp[2] << "))";
            }
            else if(flag_klee == 41){
                cout << "if((*" << temp[0] << " - *" << temp[1] << " == *" << temp[2] << "))";
            }
            else {
                cout << "if((" << temp[0] << " - " << temp[1] << " == " << temp[2] << "))";
            }
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
        }  

        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type4[type4] = temp[0] + "_" + temp[1] + "_" + temp[2];
            type4++;
        }  

        else assert(0);
    }

    
    // ne(sub(x[0],x[8]),sub(x[1],x[9]))
    else if(type == 5){
        expr = expr.substr(3);
        int first = expr.find(",");  // first comma
        int firclose = expr.find(")");
        string subs1 = expr.substr(firclose+2);     // breaks from the just before second "sub"
        int sec = subs1.find(",");  // comma in that string
        
        elm1 = expr.substr(4, first-4);
        // cout << "ELm1:" << elm1 << "\n";
        elm2 = expr.substr(first+1, firclose-1-first);
        // cout << "ELm2:" << elm2 << "\n";
        elm3 = subs1.substr(4, sec-4);
        // cout << "ELm3:" << elm3 << "\n";
        elm4 = subs1.substr(sec+1, subs1.size()-sec-3);
        // cout << "ELm4:" << elm4 << "\n"; 

        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
            }
            if (elm4 == arr[j]){
                std::string s = std::to_string(j);
                temp[3] = "var" + s;            // the temp should be like var"j"
            }
        } 
        
        if(flag_klee == 1){
            cout << "klee_assume((" << temp[0] << " - " << temp[1] << ") != (" << temp[2] << " - " << temp[3] << "));\n";
        }
        
        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 6){     // here also it is same but still left for safety
                cout << "if(((" << temp[0] << " - " << temp[1] << ") != (" << temp[2] << " - " << temp[3] << ")))";
            }
            else if(flag_klee == 41){
                cout << "if(((*" << temp[0] << " - *" << temp[1] << ") != (*" << temp[2] << " - *" << temp[3] << ")))";
            }
            else{
                cout << "if(((" << temp[0] << " - " << temp[1] << ") != (" << temp[2] << " - " << temp[3] << ")))";
            }
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
        }

        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type5[type5] = temp[0] + "_" + temp[1] + "_" + temp[2] + "_" + temp[3];
            type5++;
        } 
        else assert(0);
    }

    // eq(%0,dist(%1,%2))
    else if (type == 6){
        // Here i am implementing the modular version, this would make things faster as it will eliminate "if"
        // conditions and hence reduce the paths for KLEE, this would be good I guess 
        // the implemention with "if" conditions is implemented in the first case with type == 1
        // We can't use the "abs" function from C library, this will highly reduce the no of test cases, 
        // We can either use an implementation of abs function or the ternary operator
        // Ternary operator does not increase path for KLEE, great! , klee select is used, path not increased
        // implementation like klee_assume(var21 == var_for_abs >= 0 ? var_for_abs : var_for_abs*(-1)); doesn't work
        // it has to be broken into :
        // var_for_abs = (var_for_abs >= 0) ? var_for_abs : var_for_abs*(-1);
        // klee_assume(var5 == var_for_abs);

        expr = expr.substr(3); // from "sub"
        int first = expr.find(",");     // first comma
        string subs1 = expr.substr(expr.find("dist"));
        int sec = subs1.find(",");    // second comma
        elm1 = expr.substr(0, first);
        elm2 = subs1.substr(5, sec-5);
        elm3 = subs1.substr(sec+1, subs1.size()-sec-3);
        // cout << "ELm1:" << elm1 << "\n";
        // cout << "ELm2:" << elm2 << "\n";
        // cout << "ELm3:" << elm3 << "\n";

        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
            }
        } 
        if(declare_var_for_abs == 0 && (flag_klee == 1 || flag_klee == 2 || flag_klee == 6 || flag_klee == 41)){
            cout << "int var_for_abs;\n";
            declare_var_for_abs = 1;
        }
        
        if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6){
            cout << "var_for_abs = " << temp[1] << " - " << temp[2] << ";\n";
            cout << "var_for_abs = (var_for_abs >= 0) ? var_for_abs : var_for_abs*(-1);\n";
        }

        else if(flag_klee == 41){
            cout << "var_for_abs = *" << temp[1] << " - *" << temp[2] << ";\n";
            cout << "var_for_abs = (var_for_abs >= 0) ? var_for_abs : var_for_abs*(-1);\n";
        }
        

        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << " == var_for_abs );\n";
        }
        
        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 6){
                cout << "if(" << temp[0] << " == var_for_abs)";
            }
            else if(flag_klee == 41){
                cout << "if(*" << temp[0] << " == var_for_abs)";    
            }
            else{
                cout << "if(" << temp[0] << " == var_for_abs)";
            }
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
       }

       else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type6[type6] = temp[0] + "_" + temp[1] + "_" + temp[2];
            type6++;
        } 
        else assert(0);
    }


   
    // eq(mod(add(%0,%1,%2),%3),%4)
    else if(type == 7){
        expr = expr.substr(10);     // from after "add"
        int first = expr.find(","); 
        elm1 = expr.substr(1, first-1);
        // cout << "ELm1:" << elm1 << "\n";
        
        string subs1 = expr.substr(first+1);
        int sec = subs1.find(",");
        elm2 = subs1.substr(0,sec);
        // cout << "ELm2:" << elm2 << "\n";
        
        string subs2 = subs1.substr(sec+1);
        int thr = subs2.find(",");
        elm3 = subs2.substr(0,thr-1);
        // cout << "ELm3:" << elm3 << "\n";
        
        string subs3 = subs2.substr(thr+1);
        int fourth = subs3.find(",");
        elm4 = subs3.substr(0,fourth-1);
        // cout << "ELm4:" << elm4 << "\n";

        string subs4 = subs3.substr(fourth);
        elm5 = subs4.substr(1,subs4.size()-2);
        // cout << "ELm5:" << elm5 << "\n";

        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
            }
            if (elm5 == arr[j]){
                std::string s = std::to_string(j);
                temp[3] = "var" + s;            // the temp should be like var"j"
            }
        }
        
        if(flag_klee == 1){
            cout << "klee_assume(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")%" << elm4 << ") == " << temp[3] << ");\n";
       }

       else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 6){
                cout << "if(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")%" << elm4 << " == " << temp[3] << "))";
            }
            else if(flag_klee == 41){
                cout << "if(((*" << temp[0] << " + *" << temp[1] << " + *" << temp[2] << ")%(" << elm4 << ") == *" << temp[3] << "))";
            }
            else {
                cout << "if(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")%" << elm4 << " == " << temp[3] << "))";
            }
            // cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
       }

       else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type7[type7] = temp[0] + "_" + temp[1] + "_" + temp[2] + "_" + elm4 + "_" + temp[3];
            type7++;
        } 
        else assert(0);
    }

    
    // eq(div(add(%0,%1,%2),%3),%4)
    else if(type == 8){
        expr = expr.substr(10);     // from after "add"
        int first = expr.find(","); 
        elm1 = expr.substr(1, first-1);
        // cout << "ELm1:" << elm1 << "\n";
        
        string subs1 = expr.substr(first+1);
        int sec = subs1.find(",");
        elm2 = subs1.substr(0,sec);
        // cout << "ELm2:" << elm2 << "\n";
        
        string subs2 = subs1.substr(sec+1);
        int thr = subs2.find(",");
        elm3 = subs2.substr(0,thr-1);
        // cout << "ELm3:" << elm3 << "\n";
        
        string subs3 = subs2.substr(thr+1);
        int fourth = subs3.find(",");
        elm4 = subs3.substr(0,fourth-1);
        // cout << "ELm4:" << elm4 << "\n";

        string subs4 = subs3.substr(fourth);
        elm5 = subs4.substr(1,subs4.size()-2);
        // cout << "ELm5:" << elm5 << "\n";

        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
            }
            if (elm5 == arr[j]){
                std::string s = std::to_string(j);
                temp[3] = "var" + s;            // the temp should be like var"j"
            }
        }
        
        if(flag_klee == 1){
            cout << "klee_assume(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")/" << elm4 << ") == " << temp[3] << ");\n";
        }

        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 6){
                cout << "if(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")/" << elm4 << " == " << temp[3] << "))";
            }
            else if(flag_klee == 41){
                cout << "if(((*" << temp[0] << " + *" << temp[1] << " + *" << temp[2] << ")/(" << elm4 << ") == *" << temp[3] << "))"; 
            }
            else{
                cout << "if(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")/" << elm4 << " == " << temp[3] << "))"; 
            }

            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
       }

       else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type8[type8] = temp[0] + "_" + temp[1] + "_" + temp[2] + "_" + elm4 + "_" + temp[3];
            type8++;
        } 
        else assert(0);
    }

    
    // ne(%0,%1) || eq(%0,%1)
    else if(type == 9 || type == 10){
        expr = expr.substr(3);
        // cout << expr << "\n";
        int first = expr.find(",");  // first comma
        elm1 = expr.substr(0,first);
        // cout << elm1 << "\n";
        elm2 = expr.substr(first+1, expr.size()-first-2);
        // cout << elm2 << "\n";
        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
        }
        string sign = (type == 9) ? " != " : " == ";  
        
        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << sign << elm2 << ");\n";
        }

        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 41){
                cout << "if(*" << temp[0] << sign << elm2 << ")";      // written same for flag_klee 2 and 6 since there are no logical operators
            }
            else{
                cout << "if((" << temp[0] << sign << elm2 << "))";      // written same for flag_klee 2 and 6 since there are no logical operators
            }
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
        }
        
        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
               inten_type910[type910] = temp[0] + "_" + sign + "_" + elm2;
                type910++;
        } 
        else assert(0);
    }
    
    
    // ne(%0,dist(%1,%2))
    else if (type == 11){
        // Here i am implementing the modular version, this would make things faster as it will eliminate "if"
        // conditions and hence reduce the paths for KLEE, this would be good I guess 
        // the implemention with "if" conditions is implemented in the first case with type == 1
        // We can't use the "abs" function from C library, this will highly reduce the no of test cases, 
        // We can either use an implementation of abs function or the ternary operator
        // Ternary operator does not increase path for KLEE, great! , klee select is used, path not increased
        // implementation like klee_assume(var21 == var_for_abs >= 0 ? var_for_abs : var_for_abs*(-1)); doesn't work
        // it has to be broken into :
        // var_for_abs = (var_for_abs >= 0) ? var_for_abs : var_for_abs*(-1);
        // klee_assume(var5 == var_for_abs);

        expr = expr.substr(3); // from "sub"
        int first = expr.find(",");     // first comma
        string subs1 = expr.substr(expr.find("dist"));
        int sec = subs1.find(",");    // second comma
        elm1 = expr.substr(0, first);
        elm2 = subs1.substr(5, sec-5);
        elm3 = subs1.substr(sec+1, subs1.size()-sec-3);
        // cout << "ELm1:" << elm1 << "\n";
        // cout << "ELm2:" << elm2 << "\n";
        // cout << "ELm3:" << elm3 << "\n";

        string temp[100];
        int done_elm1 = 0; // this was done because in some cases elm1 was not a variable but an integer

        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
                done_elm1 = 1;
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
            }
        } 
        if(declare_var_for_abs == 0 && (flag_klee == 1 || flag_klee == 2 || flag_klee == 6 || flag_klee == 41)){
            cout << "int var_for_abs;\n";
            declare_var_for_abs = 1;
        }
        
        if(done_elm1 == 0)
            temp[0] = elm1;     // for cases when elm1 is an integer and not a variable

        if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6 || flag_klee == 41){ // This is not used for flag_klee == 3
            if(flag_klee == 41){
                cout << "var_for_abs = *" << temp[1] << " - *" << temp[2] << ";\n";
            }
            else{
                cout << "var_for_abs = " << temp[1] << " - " << temp[2] << ";\n";
            }
            cout << "var_for_abs = (var_for_abs >= 0) ? var_for_abs : var_for_abs*(-1);\n";
        }
        
        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << " != (" << temp[1] << " + "  << temp[2] <<  "));\n";
        }
        
        else if(flag_klee == 2|| flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 41){
                cout << "if((" << temp[0] << " != (*" << temp[1] << " + *"  << temp[2] << ")))";              // flag_klee ==  2 and 6 same as there are no logical operators
            }
            else{
                cout << "if((" << temp[0] << " != (" << temp[1] << " + "  << temp[2] << ")))";              // flag_klee ==  2 and 6 same as there are no logical operators
            }
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
        }

        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type11[type11] = temp[0] + "_" + temp[1] + "_" + temp[2];
            type11++;
        } 
        else assert(0);
    }
    

    // eq(%0,add(%1,%2))
    else if (type == 12){
        expr = expr.substr(3); // from "sub"
        int first = expr.find(",");     // first comma
        string subs1 = expr.substr(expr.find("add"));
        int sec = subs1.find(",");    // second comma
        elm1 = expr.substr(0, first);
        elm2 = subs1.substr(4, sec-4);
        elm3 = subs1.substr(sec+1, subs1.size()-sec-3);
        // cout << "ELm1:" << elm1 << "\n";
        // cout << "ELm2:" << elm2 << "\n";
        // cout << "ELm3:" << elm3 << "\n";

        int done_elm3 = 0;
        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
            if (elm3 == arr[j]){
                std::string s = std::to_string(j);
                temp[2] = "var" + s;            // the temp should be like var"j"
                done_elm3 = 1;
            }
        } 

        if(done_elm3 == 0){
            temp[2] = elm3;
        }
        
        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << " == (" << temp[1] << " + "  << temp[2] <<  "));\n";
        }
        
        else if(flag_klee == 2 || flag_klee == 6){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if((" << temp[0] << " == (" << temp[1] << " + "  << temp[2] << ")))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
       }

       else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type12[type12] = temp[0] + "_" + temp[1] + "_" + temp[2];
            type12++;
        } 
        else assert(0);

    }


    // or(and(eq(dist(div(%0,100),div(%1,100)),1),eq(dist(mod(%0,100),mod(%1,100)),2)),and(eq(dist(div(%0,100),div(%1,100)),2),eq(dist(mod(%0,100),mod(%1,100)),1)))
    // Here you only need to find %0 and %1
    else if(type == 13){
        expr = expr.substr(19);
        int first = expr.find(",");
        elm1 = expr.substr(0, first);
        // cout << elm1 << "\n";
        string subs1 = expr.substr(expr.find("("));   // break from the second "(" in overall expr
        int sec = subs1.find(","); 
        elm2 = subs1.substr(1, sec-1);
        // cout << elm2 << "\n";
        if(done_for_special == 0 && (flag_klee == 1 || flag_klee == 2 || flag_klee == 41)){
            cout << "int final, var_for_abs1, var_for_abs2, var_for_abs3, var_for_abs4, check1, check2, check3, check4 = 0;\n";
            done_for_special = 1;
        }
        // cout << "int final" << no_times << " = 0;\n";
        // no_times ++;

        string temp[100];
        for(int j = 0; j < 1000; j++){
            if (elm1 == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (elm2 == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
        }

        if(flag_klee == 1 || flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            
            if(flag_klee == 41){
                cout << "var_for_abs1 = (*" << temp[0] << "/100) - " << "(*" << temp[1] << "/100)" << ";\n";
            }
            else{
                cout << "var_for_abs1 = (" << temp[0] << "/100) - " << "(" << temp[1] << "/100)" << ";\n";
            }
            cout << "var_for_abs1 = (var_for_abs1 >= 0) ? var_for_abs1 : var_for_abs1*(-1);\n";
            cout << "check1 = (var_for_abs1 == 1) ? 1 : 0;\n";

            if(flag_klee == 41){
                cout << "var_for_abs2 = (*" << temp[0] << "%100) - " << "(*" << temp[1] << "%100)" << ";\n";
            }
            else{
                cout << "var_for_abs2 = (" << temp[0] << "%100) - " << "(" << temp[1] << "%100)" << ";\n";
            }
            cout << "var_for_abs2 = (var_for_abs2 >= 0) ? var_for_abs2 : var_for_abs2*(-1);\n";
            cout << "check2 = (var_for_abs2 == 2) ? 1 : 0;\n";

            if(flag_klee == 41){
                cout << "var_for_abs3 = (*" << temp[0] << "/100) - " << "(*" << temp[1] << "/100)" << ";\n";
            }
            else{
                cout << "var_for_abs3 = (" << temp[0] << "/100) - " << "(" << temp[1] << "/100)" << ";\n";
            }
            cout << "var_for_abs3 = (var_for_abs3 >= 0) ? var_for_abs3 : var_for_abs3*(-1);\n";
            cout << "check3 = (var_for_abs3 == 2) ? 1 : 0;\n";

            if(flag_klee == 41){
                cout << "var_for_abs4 = (*" << temp[0] << "%100) - " << "(*" << temp[1] << "%100)" << ";\n";
            }
            else{
              cout << "var_for_abs4 = (" << temp[0] << "%100) - " << "(" << temp[1] << "%100)" << ";\n";  
            }
            cout << "var_for_abs4 = (var_for_abs4 >= 0) ? var_for_abs4 : var_for_abs4*(-1);\n";
            cout << "check4 = (var_for_abs4 == 1) ? 1 : 0;\n";

            cout << "final = ((check1 == 1 && check2 == 1) || (check3 == 1 && check4 == 1)) ? 1 : 0;\n";
        }

        // cout << "if (final == 0) {printf(\"UNSAT\"); exit(0);}\n";
        if(flag_klee == 1){
            cout << "klee_assume(final == 1);\n";      // I am not sure if I need to make different final variables here, will understnad when I check my solutions
        }
        
        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(final == 1)";           // same for flag_klee ==  2 and 6 as there are no logical operators
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //exit(0) to curb paths for KLEE 
        }

        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type13[type13] = temp[0] + "_" + temp[1];
            type13++;
        }
        else assert(0);
    }

    else if (type == 0)
        assert(0);
}


void XCSP3PrintCallbacks::buildConstraintPrimitive(string id, OrderType op, XVariable *x, int k, XVariable *y) {
    // It comes here if all arguments are variables
    // cout << "\n   intension constraint " << id << ": " << x->id << (k >= 0 ? "+" : "") << k << " op " << y->id << endl;
    // for cases with ne(%0,%1) 
    
    // Need to implement a version in which all these conditions are in a single "if" condition and not broken separately

    if(op == 5 || op == 6){        // op == 6 corresponds to ne , described in file Constants.h
        string temp[100]; string sign = " != ";
        for(int j = 0; j < 1000; j++){
            if (x->id == arr[j]){
                std::string s = std::to_string(j);
                temp[0] = "var" + s;            // the temp should be like var"j"
            }
            if (y->id == arr[j]){
                std::string s = std::to_string(j);
                temp[1] = "var" + s;            // the temp should be like var"j"
            }
        }
        if(op == 5)
            sign = " == "; // other case is already handled by initialization

        if(flag_klee == 1){
                cout << "klee_assume(" << temp[0] << sign << temp[1] << ");\n";
        }

        else if(flag_klee == 2 || flag_klee == 6 || flag_klee == 41){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            if(flag_klee == 41){
                cout << "if(*" << temp[0] << sign << " *" << temp[1] << ")";
            }
            else{
               cout << "if(" << temp[0] << sign << temp[1] << ")"; 
            }
            cout << "{" << var_global << "= 1;}" << endl  << "else {exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }

        else if(flag_klee == 3 || flag_klee == 4 || flag_klee == 5 || flag_klee == 7 || flag_klee == 8){
            inten_type200[type200] = temp[0] + "_" + sign + "_" + temp[1];
            type200++;
        }

        else assert(0);
    }

    // // for cases with eq(%0,%1)
    
    // else if(op == 5){             // op == 5 corresponds to eq , described in file Constants.h
    //     string temp[100];
    //     for(int j = 0; j < 1000; j++){
    //         if (x->id == arr[j]){
    //             std::string s = std::to_string(j);
    //             temp[0] = "var" + s;            // the temp should be like var"j"
    //         }
    //         if (y->id == arr[j]){
    //             std::string s = std::to_string(j);
    //             temp[1] = "var" + s;            // the temp should be like var"j"
    //         }
    //     }
    //     if(flag_klee == 1){
    //         cout << "klee_assume(" << temp[0] << " == " << temp[1] << ");\n";
    //     }

    //     else if(flag_klee == 2){
    //         if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
    //             done_vars = 1;
    //             string q = "myvar" + std::to_string(cntdisjunctions);
    //             cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
    //             var_global = q;
    //             cntdisjunctions++;
    //         }
    //         cout << "if((" << var_global << " == 1) && (" << temp[0] << sign << elm2 << "))";
    //         cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;exit(0);}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
    //     }
    // }

    else{
        assert(0);
    }

}


void XCSP3PrintCallbacks::buildConstraintRegular(string id, vector<XVariable *> &list, string start, vector <string> &final, vector <XTransition> &transitions) {
    cout << "\n    regular constraint" << endl; //no
    cout << "        ";
    displayList(list);
    cout << "        start: " << start << endl;
    cout << "        final: ";
    displayList(final, ",");
    cout << endl;
    cout << "        transitions: ";
    for(unsigned int i = 0; i < (transitions.size() > 4 ? 4 : transitions.size()); i++) {
        cout << "(" << transitions[i].from << "," << transitions[i].val << "," << transitions[i].to << ") ";
    }
    if(transitions.size() > 4) cout << "...";
    cout << endl;
}


using namespace std;


// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    vector<pair<int, int> > *adj;    // Pointer to an array containing adjacency lists
    list<int> DFSUtil(int v, bool visited[], list<int> result);  // A function used by DFS
    vector<tuple<int, int, int>> speDFSUtil(int src, int des, int edge_weight, bool visited[], vector<tuple<int, int, int>> result);
    public:
        Graph(int V);   // Constructor
        vector<pair<int, int> > * addEdge(int u, int v, int wt);   // function to add an edge to graph
        vector<tuple<int, int, int>> DFS(int v);    // DFS traversal of the vertices reachable from v
        list<int> BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<pair<int, int> >[V];
}
 

// To add an edge in the graph, this function is for mdd
vector<pair<int, int> > * Graph::addEdge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    // adj[v].push_back(make_pair(u, wt));      // I don't think we need bidirectional graph, so we can remove this statement
    return adj;
}

list<int> Graph::DFSUtil(int v, bool visited[], list<int> result)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    // cout << v << " ";
    result.push_back(v);
    // Recur for all the vertices adjacent to this vertex
    vector<pair<int, int> >::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[i->first])        // of course it would first element, second element is weight
            result = DFSUtil(i->first, visited, result);

    return result;
}

vector<tuple<int, int, int>> Graph::speDFSUtil(int src, int v, int wt, bool visited[], vector<tuple<int, int, int>> result)
{
    // Mark the current node as visited and print it
    // except for the first case
    if(src != -1){
        visited[v] = true;
        // cout << v << " ";
        result.push_back(make_tuple(src, v, wt));
    }

    // Recur for all the vertices adjacent to this vertex
    vector<pair<int, int>>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        // if (!visited[i->first])        // of course it would first element, second element is weight
            result = speDFSUtil(v, i->first, i->second, visited, result);       // push the destination and wt of that edge
    }

    return result;
}

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil()
vector<tuple<int, int, int>> Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    vector<tuple<int, int, int>> result;       // store the result of dfs
    // Call the recursive helper function to print DFS traversal
    result = speDFSUtil(-1, v, 0, visited, result);     // for first we say that -1 points to the start node, let the weight connecting -1 to root be 0
    return result;

}


list<int> Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
    list<int> result;       // the result of BFS
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    vector<pair<int, int> >::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        // cout << s << " ";
        result.push_back(s);        // store bfs in this list
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[i->first])
            {
                visited[i->first] = true;
                queue.push_back(i->first);
            }
        }
    }
    return result;
}




void XCSP3PrintCallbacks::buildConstraintMDD(string id, vector<XVariable *> &list, vector <XTransition> &transitions) {
    std::map<string, int> level_map;
    std::map<string, int> node_map;     // this will have a maping of each node to a counter which basically counts the number of parental nodes for this particular node
    std::map<string, int> number_nodemap;       // this is a map from node to a integer
    // for node_map all nodes have a counter initialised to 0
    std::map<int, string> reverse_number_nodemap;       // this is a map from integer to a corresponding node
    std::map<string, int>::iterator secit;      // iterator for a map
    std::map<string, int>::iterator it;      // iterator for a map


    int level = 0, lastlevel = 0, number = 0;          // this is for the starting level
    level_map["root"] = 0;          // here 0 is the level in mdd for root
    int max_node = 0;           // This variable will store the number of the largest node encountered will now, so that if I create new nodes, they are number after this max_node
    present_level_variable = ""; string name;

    // This function just assigns levels to nodes according to levels of their parent. Root is initialised to level 0
    // these levels are used to find which variable in the list is related to this level, hence this code is common to all mdd versions
    for(unsigned int i = 0; i < (transitions.size()); i++){
        // cout << "(" << transitions[i].from << "," << transitions[i].val << "," << transitions[i].to << ") \n";
        secit = level_map.find(transitions[i].from);
        level_map[transitions[i].to] = secit->second + 1;          // the child nodes of the parent has one level up
        if(secit->second + 1 > lastlevel)
            lastlevel = secit->second + 1;          // this is the max level in the mdd, it is level of nodeT
        
        secit = node_map.find(transitions[i].from);
        if (secit == node_map.end()) {      // if it is not in map, add it, else move on
            node_map[transitions[i].from] = 0;          // counters for all nodes initialsed to 0
        }

        secit = node_map.find(transitions[i].to);
        if (secit == node_map.end()){       // if it is not in map, add it, else move on
            node_map[transitions[i].to] = 0;          // counters for all nodes initialsed to 0
        }

        it = number_nodemap.find(transitions[i].from);
        if(it == number_nodemap.end()){                 // add in the map if only it hasn't been added
            number_nodemap[transitions[i].from] = number;
            reverse_number_nodemap[number] = transitions[i].from;       // also add in the reverse map
            number++; 
        }

        it = number_nodemap.find(transitions[i].to);
        if(it == number_nodemap.end()){                 // add in the map if only it hasn't been added
            number_nodemap[transitions[i].to] = number;
            reverse_number_nodemap[number] = transitions[i].to;         // also add in the reverse map
            number++; 
        }
        if(transitions[i].to != "nodeT"){       // don't use for this
            string num = transitions[i].to.substr(1);           // if node is n17, i_dec will be 17
            int i_dec = std::stoi(num); 
            if(i_dec > max_node)
                max_node = i_dec;
        }
        if(transitions[i].from != "root"){
            string num = transitions[i].from.substr(1);
            int i_dec = std::stoi(num);
            if(i_dec > max_node)
                max_node = i_dec;
        }
    }
    
    // The variable "number" has all the number of nodes in the mdd

    // for (std::map<string,int>::iterator it=number_nodemap.begin(); it!=number_nodemap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    // This mdd version is mdd to C code using if conditions and goto's. 
    if (mdd_flag == 1){
        // Now the level_map has information of all levels of nodes, root corresponds to 0 and nodeT to last level
        // you should check for change of variable and not the node of mdd, because several nodes can be linked to a same variable, so take care
        for(unsigned int i = 0; i < (transitions.size()); i++){
            level = level_map.find(transitions[i].from)->second;    // This gives the level of the this node
            for(int j = 0; j < 1000; j++){
                if (list[level]->id == arr[j]){
                    std::string s = std::to_string(j);
                    name = "var" + s;            // the temp should be like var"j"
                }
            }

            if(present_level_variable != transitions[i].from){      // this means that their is a change of variable , so first thing to be printed should be "if" and then "else if's" for subsequent conditions
                // exit(0); must not be printed for the first case itself, so check if present_level_variable != ""
                if(level != lastlevel && present_level_variable != ""){     // for the last level don't print exit(0); otherwise there will be straight code exit, which is not what is should be
                    cout << "exit(0);\n";                       // this is for the previous level end of all , but it shouldn't be used at end of a mdd, because then there is no goto after in last "if" condition
                    cout << transitions[i].from + "_" + std::to_string(mdd) << ":\n";       // this is the goto label for this particular node
                }
                present_level_variable = transitions[i].from;
                cout << "if(";
            }
            else {
                cout << "else if(";
            }
            cout << name << " == " << transitions[i].val << "){" << endl;   // this name is the variable
            cout << "goto " << transitions[i].to  + "_" + std::to_string(mdd) << ";\n}\n";
        }
        cout << "nodeT_" + std::to_string(mdd) + ":\n" << endl;   // This just bring that partcular mdd out of if conditions back to straight line
        mdd += 1;           // so that next each goto label for different mdd constraints are distinct
    }

    // This version used BFS
    // this version will be converting mdd to tree and then to C code using goto's and if conditions, perhaps very similar to mdd_flag 1
    // just duplicate the nodes in mdd which have more than one incoming branch using a counter for goto and make a separate body for that goto and it will be done
    else if (mdd_flag == 2){
        // Now the level_map has information of all levels of nodes, root corresponds to 0 and nodeT to last level
        // This will have a counter for goto which is incremented from the transitions.to node
        int v, w;   
        Graph g(number);
        std::vector<pair<int, int> > * adj;         // this will have the same result as adj in Graph class
        for(unsigned int i = 0; i < (transitions.size()); i++){
            adj = g.addEdge(number_nodemap.find(transitions[i].from)->second, number_nodemap.find(transitions[i].to)->second, transitions[i].val);
        }

        std::list<int> result = g.BFS(number_nodemap.find("root")->second);     // start BFS from root node
        std::list<int>::iterator i;

        // This will print in BFS order, now the down nodes have the all the counter from parental nodes and they should be printed equal to the number of their respective counter

        for (i = result.begin(); i != result.end(); ++i)
        {
            string no_de = reverse_number_nodemap.find(*i)->second;     // this gives the node
            level = level_map.find(no_de)->second;
            if(level == lastlevel)          // if it is lastlevel it means it for nodeT, so continue, because there is no list[level] for lastlevel
                continue;           
            
            for(int j = 0; j < 1000; j++){
                if (list[level]->id == arr[j]){
                    std::string s = std::to_string(j);
                    name = "var" + s;            // the temp should be like var"j"
                }
            }
            
            // The same code is repeated in a loop down, try to think of a way of eliminating repitition of the same code

            // this is for the first turn
            if(no_de != "root")     // print this only if the node is not a root node
                cout << no_de + "_" + std::to_string(mdd) + "_" + std::to_string(node_map[no_de]-1) << ":\n";       // this is the goto label for this particular node, here several labels will be added, all from its parental nodes, this is the only difference from goto version of mdd(non-tree) version 
            // -1 in the last label is explained by the fact that you need to substract one as the counter has already been incremented for the next label

            for (auto it = adj[*i].begin(); it!=adj[*i].end(); it++)
            {
                if(it == adj[*i].begin())    // for the first case print "if" for other cases print "else if"
                    cout << "if(";
                else 
                    cout << "else if(";
                v = it->first;          // this is the destination node number
                w = it->second;         // this is the weight of the edge for this pair
                string dest = reverse_number_nodemap.find(v)->second;       // find name of destination node
                cout << name << " == " << w << "){" << endl;            // this name is the variable corresponding to source node
                cout << "goto " << dest  + "_" + std::to_string(mdd) +  "_"  + std::to_string(node_map[dest]) << ";\n}\n";
                node_map[dest] += 1;       // increment the counter by 1
            }
            cout << "exit(0);\n";


            // body should be printed for each counter subsequent of that node, excluding for the first one
            for(int care = 0; care < node_map[no_de]-1; care++){
                if(no_de != "root")     // print this only if the node is not a root node
                    cout << no_de + "_" + std::to_string(mdd) + "_" + std::to_string(care) << ":\n";       // this is the goto label for this particular node, here several labels will be added, all from its parental nodes, this is the only difference from goto version of mdd(non-tree) version 
                // -1 in the last label is explained by the fact that you need to substract one as the counter has already been incremented for the next label

                for (auto it = adj[*i].begin(); it!=adj[*i].end(); it++)
                {
                    if(it == adj[*i].begin())    // for the first case print "if" for other cases print "else if"
                        cout << "if(";
                    else 
                        cout << "else if(";
                    v = it->first;          // this is the destination node number
                    w = it->second;         // this is the weight of the edge for this pair
                    string dest = reverse_number_nodemap.find(v)->second;       // find name of destination node
                    cout << name << " == " << w << "){" << endl;            // this name is the variable corresponding to source node
                    cout << "goto " << dest  + "_" + std::to_string(mdd) +  "_"  + std::to_string(node_map[dest]) << ";\n}\n";
                    node_map[dest] += 1;       // increment the counter by 1
                }
                cout << "exit(0);\n";
            }

        }

        it = node_map.find("nodeT");
        for(int cnt = 0; cnt < it->second; cnt++){
            cout << "nodeT_" + std::to_string(mdd) + "_" + std::to_string(cnt) + ":\n" << endl;         // This just bring that partcular mdd out of if conditions back to straight line
        }
        mdd += 1;           // so that next each goto label for different mdd constraints are distinct
        // getchar();
    }


    // This might use DFS, btw the mdd is already given in DFS, so doing dfs again makes little sense
    // this version will be converting mdd to tree and then to C code using nested if conditions, try to make use of common branches at top and then break into if conditions recursively
    // This should use some recursive function, to explore the graph, or rather simple convert mdd to a tree and then do dfs
    // for converting to a tree add nodes for multiple incoming edges to a single node, so that it becomes a tree
    else if(mdd_flag == 3){
        // vector <XTransition> copy_transitions;
        // std::map<string, int> dest_counter;         // this has information about the counter of the destination, we will add nodes whenever the counter > 1, so to convert mdd to tree
        // copy_transitions = transitions;             // copy of the mdd, make changes only in the copy, not in the transitions ( original mdd )
        int v, w, previous_level;
        Graph g(number);
        std::map<string, bool> should_it_be_elseif;      // this map tells that whether if or else if should be printed for variables, it is based on whether that variable has been encountered before and also level change has been there
        std::vector<pair<int, int> > * adj;         // this will have the same result as adj in Graph class
        
        for(unsigned int i = 0; i < (transitions.size()); i++){
            adj = g.addEdge(number_nodemap.find(transitions[i].from)->second, number_nodemap.find(transitions[i].to)->second, transitions[i].val);
            should_it_be_elseif[transitions[i].from] = false;       // by default all are set to false at beginning of any new constraint set
        }

        std::vector<tuple<int, int, int>> result = g.DFS(number_nodemap.find("root")->second);     // start BFS from root node
        std::vector<tuple<int, int, int>>::iterator i;

        
        // Now we have the edges in DFS of the tree, with the tuple(first, second, third)
        for(i = result.begin(); i != result.end(); i++){
            previous_level = level;
            level = level_map.find(reverse_number_nodemap[std::get<0>(*i)])->second;    // This gives the level of the this node
            for(int j = 0; j < 1000; j++){
                if (list[level]->id == arr[j]){
                    std::string s = std::to_string(j);
                    name = "var" + s;            // the temp should be like var"j"
                }
            }

            if(previous_level > level){
                // cout << "(" << reverse_number_nodemap[std::get<0>(*i)] << ", " << reverse_number_nodemap[std::get<1>(*i)] << " , " << std::get<2>(*i)  << " \n ";
                // cout << previous_level << "   " << level << "\n";
                int closing = previous_level - level;
                for(int clo = level; clo < previous_level; clo++){      // number of closing brackets is equal to the difference in level
                    cout << "exit(0);\n}\n";          // a closing bracket for the earlier constraint as it DFS has climbed up the tree
                }
                // here you need to switch false the should_it_be_elseif flag for all the variables for which tree has been climbed up
                // we will search in level_map for all the levels we are moving up and set false for all the variables in them
                // we need a loop here as there can be jump of multiple levels and we can't track all past levels
                for(int l = previous_level; l > level; l--){
                    for(auto it = level_map.begin(); it != level_map.end(); it++){
                            if(it->second == l){           // now all variables at this level needs to be switched off
                                should_it_be_elseif[it->first] = false;
                                // cout << "Assigned false : " << it->first << "\n";
                            }
                    }
                }
            }
            
            if(should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] == false){
                cout << "if(" << name << " == " << std::get<2>(*i) <<  "){\n";                     // std::get<2>(*i) - which is the weight element
                should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] = true;       // set to true as it has been encountered now, this will be set to false when there is a level change  
            }
            
            else{ 
                cout << "else if(" << name << " == " << std::get<2>(*i) << "){\n";       // std::get<2>(*i) - which is the weight element
            }

            if(reverse_number_nodemap[std::get<1>(*i)] == "nodeT"){         // if the destination is a closing node
                cout << "goto nodeT_" << std::to_string(mdd) << ";\n}\n";       // This is also a closing place so false must be set false as well
                // Let this be off only when there is a level change
                // should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] = false;     // false for the last one
            }
        }
        
        for(int clo = 0; clo < level; clo++){       // number of closing brackets is equal to the difference in level
            cout << "exit(0);\n}\n";          // a closing bracket for the earlier constraint as it DFS has climbed up the tree     
        }
        cout << "nodeT_" << mdd << ":\n";
        mdd++;              // to be incremented for next mdd constraint
    }



    // this version will be converting mdd to tree and then to C code using klee_assume, it will be very close to mdd_flag 3
    // for klee_assume this version uses bitwise operators
    else if(mdd_flag == 4){
        int v, w, previous_level;
        Graph g(number);
        std::map<string, bool> should_it_be_elseif;      // this map tells that whether if or else if should be printed for variables, it is based on whether that variable has been encountered before and also level change has been there
        std::vector<pair<int, int> > * adj;         // this will have the same result as adj in Graph class
        
        for(unsigned int i = 0; i < (transitions.size()); i++){
            adj = g.addEdge(number_nodemap.find(transitions[i].from)->second, number_nodemap.find(transitions[i].to)->second, transitions[i].val);
            should_it_be_elseif[transitions[i].from] = false;       // by default all are set to false at beginning of any new constraint set
        }

        std::vector<tuple<int, int, int>> result = g.DFS(number_nodemap.find("root")->second);     // start BFS from root node
        std::vector<tuple<int, int, int>>::iterator i;

        if(run_klee == 1)
            cout << "klee_assume(";
        else if(run_klee == 0)
            cout << "__llbmc_assume(";
        else assert(0);

        // Now we have the edges in DFS of the tree, with the tuple(first, second, third)
        for(i = result.begin(); i != result.end(); i++){
            previous_level = level;
            level = level_map.find(reverse_number_nodemap[std::get<0>(*i)])->second;    // This gives the level of the this node
            for(int j = 0; j < 1000; j++){
                if (list[level]->id == arr[j]){
                    std::string s = std::to_string(j);
                    name = "var" + s;            // the temp should be like var"j"
                }
            }

            if(previous_level > level){
                // cout << "(" << reverse_number_nodemap[std::get<0>(*i)] << ", " << reverse_number_nodemap[std::get<1>(*i)] << " , " << std::get<2>(*i)  << " \n ";
                // cout << previous_level << "   " << level << "\n";
                int closing = previous_level - level;
                for(int clo = level; clo < previous_level; clo++){      // number of closing brackets is equal to the difference in level
                    cout << "))";          // a closing bracket for the earlier constraint as it DFS has climbed up the tree
                }
                // cout << " | ";

                // here you need to switch false the should_it_be_elseif flag for all the variables for which tree has been climbed up
                // we will search in level_map for all the levels we are moving up and set false for all the variables in them
                // we need a loop here as there can be jump of multiple levels and we can't track all past levels
                for(int l = previous_level; l > level; l--){
                    for(auto it = level_map.begin(); it != level_map.end(); it++){
                            if(it->second == l){           // now all variables at this level needs to be switched off
                                should_it_be_elseif[it->first] = false;
                                // cout << "Assigned false : " << it->first << "\n";
                            }
                    }
                }
            }

            // this is because we want extra brackets
            else if (level > previous_level){
                for(int c = previous_level; c < level; c++){
                    cout << "(";        // for extra brackets for lower levels
                }
            }

            // " & " operator has higher preference than "==" so putting extra paranthesis aroung each condition 

            if(should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] == false){
                cout << "((" << name << " == " << std::get<2>(*i) << ")";                     // std::get<2>(*i) - which is the weight element
                should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] = true;       // set to true as it has been encountered now, this will be set to false when there is a level change  
            }
            
            else{ 
                cout << " | ((" << name << " == " << std::get<2>(*i) << ")";       // std::get<2>(*i) - which is the weight element
            }

            // for nodeT don't emit " & "
            if(reverse_number_nodemap[std::get<1>(*i)] == "nodeT"){         // if the destination is a closing node
                cout << ")";       // This is also a closing place so false must be set false as well
            }
            else cout << " & ";


            // cout << reverse_number_nodemap[std::get<0>(*i)] << " SEC  " << should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] << "SEE IT HERE\n";
            
            // cout << "(" << name << " == " << std::get<2>(*i);                     // std::get<2>(*i) - which is the weight element
            // if(reverse_number_nodemap[std::get<1>(*i)] == "nodeT"){         // if the destination is a closing node
            //     cout << ")";       // This is also a closing place so false must be set false as well
            // }
            // else cout << " & ";
            
        }
        for(int clo = 0; clo < level; clo++){       // number of closing brackets is equal to the difference in level
            cout << "))";          // a closing bracket for the earlier constraint as it DFS has climbed up the tree     
        }
        cout << ");\n";     // this one for closing klee_assume
        // getchar();
        mdd++;              // to be incremented for next mdd constraint
    }

    // this version will be converting mdd to tree and then to C code using klee_assume, it will be very close to mdd_flag 3
    // for klee_assume this version uses logical operator
    else if(mdd_flag == 5){
        int v, w, previous_level;
        Graph g(number);
        std::map<string, bool> should_it_be_elseif;      // this map tells that whether if or else if should be printed for variables, it is based on whether that variable has been encountered before and also level change has been there
        std::vector<pair<int, int> > * adj;         // this will have the same result as adj in Graph class
        
        for(unsigned int i = 0; i < (transitions.size()); i++){
            adj = g.addEdge(number_nodemap.find(transitions[i].from)->second, number_nodemap.find(transitions[i].to)->second, transitions[i].val);
            should_it_be_elseif[transitions[i].from] = false;       // by default all are set to false at beginning of any new constraint set
        }

        std::vector<tuple<int, int, int>> result = g.DFS(number_nodemap.find("root")->second);     // start BFS from root node
        std::vector<tuple<int, int, int>>::iterator i;

        if(run_klee == 1)
            cout << "klee_assume(";
        else if(run_klee == 0)
            cout << "__llbmc_assume(";
        else assert(0);

        // Now we have the edges in DFS of the tree, with the tuple(first, second, third)
        for(i = result.begin(); i != result.end(); i++){
            previous_level = level;
            level = level_map.find(reverse_number_nodemap[std::get<0>(*i)])->second;    // This gives the level of the this node
            for(int j = 0; j < 1000; j++){
                if (list[level]->id == arr[j]){
                    std::string s = std::to_string(j);
                    name = "var" + s;            // the temp should be like var"j"
                }
            }

            if(previous_level > level){
                // cout << "(" << reverse_number_nodemap[std::get<0>(*i)] << ", " << reverse_number_nodemap[std::get<1>(*i)] << " , " << std::get<2>(*i)  << " \n ";
                // cout << previous_level << "   " << level << "\n";
                int closing = previous_level - level;
                for(int clo = level; clo < previous_level; clo++){      // number of closing brackets is equal to the difference in level
                    cout << "))";          // a closing bracket for the earlier constraint as it DFS has climbed up the tree
                }
                // cout << " || ";

                // here you need to switch false the should_it_be_elseif flag for all the variables for which tree has been climbed up
                // we will search in level_map for all the levels we are moving up and set false for all the variables in them
                // we need a loop here as there can be jump of multiple levels and we can't track all past levels
                for(int l = previous_level; l > level; l--){
                    for(auto it = level_map.begin(); it != level_map.end(); it++){
                            if(it->second == l){           // now all variables at this level needs to be switched off
                                should_it_be_elseif[it->first] = false;
                                // cout << "Assigned false : " << it->first << "\n";
                            }
                    }
                }
            }

            // this is because we want extra brackets
            else if (level > previous_level){
                for(int c = previous_level; c < level; c++){
                    cout << "(";        // for extra brackets for lower levels
                }
            }

            // " & " operator has higher preference than "==" so putting extra paranthesis aroung each condition 

            if(should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] == false){
                cout << "((" << name << " == " << std::get<2>(*i) << ")";                     // std::get<2>(*i) - which is the weight element
                should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] = true;       // set to true as it has been encountered now, this will be set to false when there is a level change  
            }
            
            else{ 
                cout << " || ((" << name << " == " << std::get<2>(*i) << ")";       // std::get<2>(*i) - which is the weight element
            }

            // for nodeT don't emit " & "
            if(reverse_number_nodemap[std::get<1>(*i)] == "nodeT"){         // if the destination is a closing node
                cout << ")";       // This is also a closing place so false must be set false as well
            }
            else cout << " && ";


            // cout << reverse_number_nodemap[std::get<0>(*i)] << " SEC  " << should_it_be_elseif[reverse_number_nodemap[std::get<0>(*i)]] << "SEE IT HERE\n";
            
            // cout << "(" << name << " == " << std::get<2>(*i);                     // std::get<2>(*i) - which is the weight element
            // if(reverse_number_nodemap[std::get<1>(*i)] == "nodeT"){         // if the destination is a closing node
            //     cout << ")";       // This is also a closing place so false must be set false as well
            // }
            // else cout << " & ";
            
        }
        for(int clo = 0; clo < level; clo++){       // number of closing brackets is equal to the difference in level
            cout << "))";          // a closing bracket for the earlier constraint as it DFS has climbed up the tree     
        }
        cout << ");\n";     // this one for closing klee_assume
        // getchar();
        mdd++;              // to be incremented for next mdd constraint
    }

    else assert(0);
    // getchar();
}


void XCSP3PrintCallbacks::buildConstraintAlldifferent(string id, vector<XVariable *> &list) {
    // cout << "\n    allDiff constraint" << id << endl;
    
    string temp[100000]; int k = 0;     // the size of this array should be big
    for(int i = 0; i < list.size(); i++ ){
        for(int j = 0; j < 1000; j++){
            if (list[i]->id == arr[j]){
                std::string s = std::to_string(j);
                temp[k] = "var" + s;            // the temp should be like var"j"
                k++;
            }
        }
    }
    // each element is different from the other elements in the "temp" list
    
    // This is with klee_assumes
    // also used when flag_exten == 3, using klee_assumes for extensional constraints as well

    if(flag_klee == 1 || flag_exten == 3){
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                if(run_klee == 1){
                    cout << "klee_assume(" << temp[i] <<  "!=" << temp[j] << ");" << endl; 
                }
                else if (run_klee == 0){
                    cout << "__llbmc_assume(" << temp[i] <<  "!=" << temp[j] << ");" << endl; 
                }
            }
        }
    }

    // This will be the pure C code for this function
    else if(flag_klee == 2 || flag_klee == 6 || flag_exten == 1 || flag_exten == 5 || flag_klee == 41){
        // I am using the same variable for declaring variables, 
        if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
         }

        cout << "if((";      // Writing this first to allow shortcircuting
        for(int i = 0; i < k; i++){         // Now start the counter from 2
            for(int j = i+1; j < k; j++){
                if(flag_klee == 6 || flag_exten == 5){
                    cout << "(" << temp[i] <<  "!=" << temp[j] << ") & "; 
                }
                else if(flag_klee == 41){
                    cout << "(*" << temp[i] <<  "!= *" << temp[j] << ") && ";       // logical operator for flag_klee == 41 
                }
                else {
                    cout << "(" << temp[i] <<  "!=" << temp[j] << ") && "; 
                }
            }
        }
        cout << " 1))" << endl; // This is just for the last unmatched "&&"
        cout << "{" << var_global << "= 1;}" << endl << "else {exit(0);}" << endl; // exit(0) is added to curb paths
    }

    // We can also implement a case in which all alldiff come in a single "if" block but that will really be huge
    else if(flag_klee == 3){
        cout << "if(!(";
        for(int i = 0; i < k; i++){         // Now start the counter from 2
            for(int j = i+1; j < k; j++){
                cout << "(" << temp[i] <<  "!=" << temp[j] << ") && "; 
            }
        }
        cout << " 1))" << endl << "exit(0);" << endl;
    }


    else if(flag_klee == 4 || flag_klee == 5 || flag_exten == 2 || flag_exten == 4){
        cout << "if((";
        for(int i = 0; i < k; i++){         // Now start the counter from 2
            for(int j = i+1; j < k; j++){
                if(flag_klee == 5 || flag_klee == 7 || flag_exten == 4 ){
                    cout << "(" << temp[i] <<  "!=" << temp[j] << ") & "; 
                }
                else {
                    cout << "(" << temp[i] <<  "!=" << temp[j] << ") && "; 
                }
            }
        }
        
        if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
             }
        cout << " 1))" << endl << var_global << " = 1;" << endl << "else exit(0);" << endl;

    }

    else if(flag_klee == 7 || flag_klee == 8){
        if(run_klee == 1){
            cout << "klee_assume((";
        }
        else if(run_klee == 0){
            cout << "__llbmc_assume((";
        }
        for(int i = 0; i < k; i++){         // Now start the counter from 2
            for(int j = i+1; j < k; j++){
                if(flag_klee == 7){
                    cout << "(" << temp[i] <<  "!=" << temp[j] << ") & "; 
                }
                else {
                    cout << "(" << temp[i] <<  "!=" << temp[j] << ") && "; 
                }
            }
        }
        cout << " 1));" << endl;
    }

    else assert(0);
}


// All different, except means that from the list either all elements take different value or take the same value as listed in except tag.
void XCSP3PrintCallbacks::buildConstraintAlldifferentExcept(string id, vector<XVariable *> &list, vector<int> &except) {
    // cout << "\n    allDiff constraint with exceptions" << id << endl;
    // Eihter all of them are equal to the value described in the except clause
    string tmp;
    for(int j = 0; j < 1000; j++){
            if(list[0]->id == arr[j]){
                tmp = "var" + std::to_string(j);
                break;
            }
        }

    cout << "if (" << tmp << " == " << except[0] << ")" << endl << " { ";  // generalize it for all values from except list
    for (int i = 1; i < list.size(); ++i)
    {
        string tmp;
        for(int j = 0; j < 1000; j++){
            if(list[i]->id == arr[j]){
                tmp = "var" + std::to_string(j);
                break;
        }
    }

        cout << tmp << " = " << except[0] << ";" << endl;
    }


    cout << " } " << endl;
    cout << "else {" << endl;

    // else all of them are different 
    string temp[100]; int k = 0;
        for(int i = 0; i < list.size(); i++ ){
            for(int j = 0; j < 1000; j++){
                if (list[i]->id == arr[j]){
                    std::string s = std::to_string(j);
                    temp[k] = "var" + s;            // the temp should be like var"j"
                    k++;
                }
            }
        }
        // each element is different from the other elements in the "temp" list
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                cout << "klee_assume(" << temp[i] <<  "!=" << temp[j] << ");" << endl; 
            }
        }
    
    cout << "}" << endl;
}



void XCSP3PrintCallbacks::buildConstraintAlldifferentList(string id, vector <vector<XVariable *> > &lists) {
    // cout << "\n    allDiff list constraint" << id << endl;
    for(unsigned int i = 0; i < lists.size(); i++) {
        buildConstraintAlldifferent(id, lists[i]);
    }
}


void XCSP3PrintCallbacks::buildConstraintAlldifferentMatrix(string id, vector <vector<XVariable *> > &matrix) {
    cout << "\n    allDiff matrix constraint" << id << endl;
    for(unsigned int i = 0; i < matrix.size(); i++) {
        string temp[100]; int p = 0;
        for(int k = 0; k < matrix[i].size(); k++ ){
            for(int j = 0; j < 1000; j++){
                if (matrix[i][k]->id == arr[j]){
                    temp[p] = "var" + std::to_string(j);            // the temp should be like var"j"
                    p++;
                }
            }
        }
        // each element is different from the other elements in the "temp" list
        for(int k = 0; k < p; k++){
            for(int j = k+1; j < p; j++){
                cout << "klee_assume(" << temp[k] <<  "!=" << temp[j] << ");" << endl; 
            }
          }
    }
}


void XCSP3PrintCallbacks::buildConstraintAllEqual(string id, vector<XVariable *> &list) {
    // cout << "\n    allEqual constraint" << id << endl;
    // cout << "        ";
    string temp[100]; int k = 0;
        for(int i = 0; i < list.size(); i++ ){
            for(int j = 0; j < 1000; j++){
                if (list[i]->id == arr[j]){
                    std::string s = std::to_string(j);
                    temp[k] = "var" + s;            // the temp should be like var"j"
                    k++;
                }
            }
        }
        // each element is different from the other elements in the "temp" list
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                cout << "klee_assume(" << temp[i] <<  "==" << temp[j] << ");" << endl; 
            }
        }
    assert(0);          // because I have not yet touched this code

    displayList(list);
}


void XCSP3PrintCallbacks::buildConstraintNotAllEqual(string id, vector<XVariable *> &list) {
    cout << "\n    not allEqual constraint" << id << endl;
    cout << "        ";
    displayList(list);
}


void XCSP3PrintCallbacks::buildConstraintOrdered(string id, vector<XVariable *> &list, OrderType order) {
    cout << "\n    ordered constraint" << endl;
    string sep;
    if(order == LT) sep = " < ";
    if(order == LE) sep = " <= ";
    if(order == GT) sep = " > ";
    if(order == GE) sep = " >= ";
    cout << "        ";
    displayList(list, sep);
}


void XCSP3PrintCallbacks::buildConstraintLex(string id, vector <vector<XVariable *> > &lists, OrderType order) {
    cout << "\n    lex constraint   nb lists: " << lists.size() << endl;
    string sep;
    if(order == LT) sep = " < ";
    if(order == LE) sep = " <= ";
    if(order == GT) sep = " > ";
    if(order == GE) sep = " >= ";
    cout << "        operator: " << sep << endl;
    for(unsigned int i = 0; i < lists.size(); i++) {
        cout << "        list " << i << ": ";
        cout << "        ";
        displayList(lists[i], " ");
    }
}


void XCSP3PrintCallbacks::buildConstraintLexMatrix(string id, vector <vector<XVariable *> > &matrix, OrderType order) {
    cout << "\n    lex matrix constraint   matrix  " << endl;
    string sep;
    if(order == LT) sep = " < ";
    if(order == LE) sep = " <= ";
    if(order == GT) sep = " > ";
    if(order == GE) sep = " >= ";

    for(unsigned int i = 0; i < (matrix.size() < 4 ? matrix.size() : 3); i++) {
        cout << "        ";
        displayList(matrix[i]);
    }
    cout << "        Order " << sep << endl;
}


void XCSP3PrintCallbacks::buildConstraintSum(string id, vector<XVariable *> &list, vector<int> &coeffs, XCondition &cond) {
    // cout << "\n        sum constraint:" << cond << endl;

        // The array term contains the term like "1*a , 2*b, 3*c"
        string tmp; 
        string term[100]; // initialising to a long value
        string finterm = "";

        for (int i = 0; i < 100; ++i)
        {
            term[i] = "null";
            // cout << "i : " << i << "  term : " << term[i] << endl;
        }

        for(int i = 0; i < list.size(); i++){
            // cout << coeffs[i] << "SEE BEOFe";
            for(int j = 0; j < 1000; j++){
            
                if (list[i]->id == arr[j]){
                    tmp = "var" + std::to_string(j);            // the temp should be like var"j"
                    term[i] = std::to_string(coeffs[i]) + " * " + tmp;
                }
            }
        }

        int i = 0;
        while(term[i] != "null"){
            // cout << " + " << term[i];
            if(finterm != "")
                finterm = finterm + " + "  + term[i];
            else
                finterm = term[0];
            i++;
        }

        // cout << finterm << endl;

        // cout << cond.operandType << cond.op << cond.var << cond.min << cond.max << cond.val << endl;
        if(cond.operandType == 0)  // non-interval type
        {   
            if(cond.op == 0)        // le than
            {
                cout << "klee_assume(" << finterm << " <= " << cond.val << ") ;"<< endl;
            }

            if(cond.op == 1)        // lt than
            {
                cout << "klee_assume(" << finterm << " < " << cond.val << ") ;"<< endl;
            }

            if(cond.op == 2)        // ge than
            {
                cout << "klee_assume(" << finterm << " >= " << cond.val << ") ;"<< endl;
            }
            if(cond.op == 3)        // gt than
            {
                cout << "klee_assume(" << finterm << " > " << cond.val << ") ;"<< endl;
            }
        }
        
        if(cond.operandType == 1)  // interval type
        {
            cout << "klee_assume(" << finterm << " >= " << cond.min << ") ;"<< endl;
            cout << "klee_assume(" << finterm << " <= " << cond.max << ") ;"<< endl;

        }
        
        if(cond.operandType == 2)  // interval type
        {
            if(cond.op == 0)        // le than
            {
                cout << "klee_assume(" << finterm << " <= " << cond.var << ") ;"<< endl;
            }

            if(cond.op == 1)        // lt than
            {
                cout << "klee_assume(" << finterm << " < " << cond.var << ") ;"<< endl;
            }

            if(cond.op == 2)        // ge than
            {
                cout << "klee_assume(" << finterm << " >= " << cond.var << ") ;"<< endl;
            }

            if(cond.op == 3)        // gt than
            {
                cout << "klee_assume(" << finterm << " > " << cond.var << ") ;"<< endl;
            }
        }
}


void XCSP3PrintCallbacks::buildConstraintSum(string id, vector<XVariable *> &list, XCondition &cond) {
    cout << "\n        unweighted sum constraint:";
    cout << "        ";
    displayList(list, "+");
    cout << cond << endl;

}


void XCSP3PrintCallbacks::buildConstraintSum(string id, vector<XVariable *> &list, vector<XVariable *> &coeffs, XCondition &cond) {
    cout << "\n        scalar sum constraint:";
    if(list.size() > 8) {
        for(int i = 0; i < 3; i++)
            cout << coeffs[i]->id << "*" << *(list[i]) << " ";
        cout << " ... ";
        for(unsigned int i = list.size() - 4; i < list.size(); i++)
            cout << coeffs[i]->id << "*" << *(list[i]) << " ";
    } else {
        for(unsigned int i = 0; i < list.size(); i++)
            cout << coeffs[i]->id << "*" << *(list[i]) << " ";
    }

    cout << cond << endl;
}


void XCSP3PrintCallbacks::buildConstraintAtMost(string id, vector<XVariable *> &list, int value, int k) {
    cout << "\n    AtMost constraint: val=" << value << " k=" << k << endl;
    cout << "        ";
    displayList(list);
}


void XCSP3PrintCallbacks::buildConstraintAtLeast(string id, vector<XVariable *> &list, int value, int k) {
    cout << "\n    Atleast constraint: val=" << value << " k=" << k << endl;
    cout << "        ";
    displayList(list);
}


void XCSP3PrintCallbacks::buildConstraintExactlyK(string id, vector<XVariable *> &list, int value, int k) {
    cout << "\n    Exactly constraint: val=" << value << " k=" << k << endl;
    cout << "        ";
    displayList(list);
}


void XCSP3PrintCallbacks::buildConstraintAmong(string id, vector<XVariable *> &list, vector<int> &values, int k) {
    cout << "\n    Among constraint: k=" << k << endl;
    cout << "        ";
    displayList(list);
    cout << "        values:";
    displayList(values);

}


void XCSP3PrintCallbacks::buildConstraintExactlyVariable(string id, vector<XVariable *> &list, int value, XVariable *x) {
    cout << "\n    Exactly Variable constraint: val=" << value << " variable=" << *x << endl;
    cout << "        ";
    displayList(list);
}


void XCSP3PrintCallbacks::buildConstraintCount(string id, vector<XVariable *> &list, vector<int> &values, XCondition &xc) {
    cout << "\n    count constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        values: ";
    cout << "        ";
    displayList(values);
    cout << "        condition: " << xc << endl;
}


void XCSP3PrintCallbacks::buildConstraintCount(string id, vector<XVariable *> &list, vector<XVariable *> &values, XCondition &xc) {
    cout << "\n    count constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        values: ";
    displayList(values);
    cout << "        condition: " << xc << endl;
}


void XCSP3PrintCallbacks::buildConstraintNValues(string id, vector<XVariable *> &list, vector<int> &except, XCondition &xc) {
    cout << "\n    NValues with exceptions constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        exceptions: ";
    displayList(except);
    cout << "        condition:" << xc << endl;
}


void XCSP3PrintCallbacks::buildConstraintNValues(string id, vector<XVariable *> &list, XCondition &xc) {
    cout << "\n    NValues  constraint" << endl;
    cout << "        ";
    
    displayList(list);
    // condition is not coming
    cout << "        condition:" << xc << "HELLO" << endl;
}


void XCSP3PrintCallbacks::buildConstraintCardinality(string id, vector<XVariable *> &list, vector<int> values, vector<int> &occurs, bool closed) {
    cout << "\n    Cardinality constraint (int values, int occurs)  constraint closed: " << closed << endl;
    cout << "        ";
    displayList(list);
    cout << "        values:";
    displayList(values);
    cout << "        occurs:";
    displayList(occurs);
}


void XCSP3PrintCallbacks::buildConstraintCardinality(string id, vector<XVariable *> &list, vector<int> values, vector<XVariable *> &occurs, bool closed) {
    cout << "\n    Cardinality constraint (int values, var occurs)  constraint closed: " << closed << endl;
    cout << "        ";
    displayList(list);
    cout << "        values:";
    displayList(values);
    cout << "        occurs:";
    displayList(occurs);
}


void XCSP3PrintCallbacks::buildConstraintCardinality(string id, vector<XVariable *> &list, vector<int> values, vector <XInterval> &occurs, bool closed) {
    cout << "\n    Cardinality constraint (int values, interval occurs)  constraint closed: " << closed << endl;
    cout << "        ";
    displayList(list);
    cout << "        values:";
    displayList(values);
    cout << "        occurs:";
    displayList(occurs);
}


void XCSP3PrintCallbacks::buildConstraintCardinality(string id, vector<XVariable *> &list, vector<XVariable *> values, vector<int> &occurs,
                                                     bool closed) 
{
    cout << "\n    Cardinality constraint (var values, int occurs)  constraint closed: " << closed << endl;
    cout << "        ";
    displayList(list);
    cout << "        values:";
    displayList(values);
    cout << "        occurs:";
    displayList(occurs);
}


void XCSP3PrintCallbacks::buildConstraintCardinality(string id, vector<XVariable *> &list, vector<XVariable *> values, vector<XVariable *> &occurs,
                                                     bool closed) 
{
    cout << "\n    Cardinality constraint (var values, var occurs)  constraint closed: " << closed << endl;
    cout << "        ";
    displayList(list);
    cout << "        values:";
    displayList(values);
    cout << "        occurs:";
    displayList(occurs);
}


void XCSP3PrintCallbacks::buildConstraintCardinality(string id, vector<XVariable *> &list, vector<XVariable *> values, vector <XInterval> &occurs, bool closed) 
{
    cout << "\n    Cardinality constraint (var values, interval occurs)  constraint closed: " << closed << endl;
    cout << "        ";
    displayList(list);
    cout << "        values:";
    displayList(values);
    cout << "        occurs:";
    displayList(occurs);
}


void XCSP3PrintCallbacks::buildConstraintMinimum(string id, vector<XVariable *> &list, XCondition &xc) {
    cout << "\n    minimum  constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        condition: " << xc << endl;
}


void XCSP3PrintCallbacks::buildConstraintMinimum(string id, vector<XVariable *> &list, XVariable *index, int startIndex, RankType rank, XCondition &xc) 
{
    cout << "\n    arg_minimum  constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        index:" << *index << endl;
    cout << "        Start index : " << startIndex << endl;
    cout << "        condition: " << xc << endl;

}


void XCSP3PrintCallbacks::buildConstraintMaximum(string id, vector<XVariable *> &list, XCondition &xc) {
    cout << "\n    maximum  constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        condition: " << xc << endl;
}


void XCSP3PrintCallbacks::buildConstraintMaximum(string id, vector<XVariable *> &list, XVariable *index, int startIndex, RankType rank, XCondition &xc) {
    cout << "\n    arg_maximum  constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        index:" << *index << endl;
    cout << "        Start index : " << startIndex << endl;
    cout << "        condition: " << xc << endl;
}


void XCSP3PrintCallbacks::buildConstraintElement(string id, vector<XVariable *> &list, int value) {
    cout << "\n    element constant constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        value: " << value << endl;
}


void XCSP3PrintCallbacks::buildConstraintElement(string id, vector<XVariable *> &list, XVariable *value) {
    cout << "\n    element variable constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        value: " << *value << endl;
}


void XCSP3PrintCallbacks::buildConstraintElement(string id, vector<XVariable *> &list, int startIndex, XVariable *index, RankType rank, int value) {
    cout << "\n    element constant (with index) constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        value: " << value << endl;
    cout << "        Start index : " << startIndex << endl;
    cout << "        index : " << *index << endl;
}


void XCSP3PrintCallbacks::buildConstraintElement(string id, vector<XVariable *> &list, int startIndex, XVariable *index, RankType rank, XVariable *value) {
    cout << "\n    element variable (with index) constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        value: " << *value << endl;
    cout << "        Start index : " << startIndex << endl;
    cout << "        index : " << *index << endl;
}


void XCSP3PrintCallbacks::buildConstraintChannel(string id, vector<XVariable *> &list, int startIndex) {
    cout << "\n    channel constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        Start index : " << startIndex << endl;
}


void XCSP3PrintCallbacks::buildConstraintChannel(string id, vector<XVariable *> &list1, int startIndex1, vector<XVariable *> &list2, int startIndex2) 
{
    cout << "\n    channel constraint" << endl;
    cout << "        list1 ";
    displayList(list1);
    cout << "        list2 ";
    displayList(list2);
}


void XCSP3PrintCallbacks::buildConstraintChannel(string id, vector<XVariable *> &list, int startIndex, XVariable *value) {
    cout << "\n    channel constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        value: " << *value << endl;
}


void XCSP3PrintCallbacks::buildConstraintStretch(string id, vector<XVariable *> &list, vector<int> &values, vector <XInterval> &widths) {
    cout << "\n    stretch constraint" << endl;
    cout << "        ";
    displayList(list);
    cout << "        values :";
    displayList(values);
    cout << "        widths:";
    displayList(widths);
}


void XCSP3PrintCallbacks::buildConstraintStretch(string id, vector<XVariable *> &list, vector<int> &values, vector <XInterval> &widths, vector <vector<int> > &patterns) {
    cout << "\n    stretch constraint (with patterns)" << endl;
    cout << "        ";
    displayList(list);
    cout << "        values :";
    displayList(values);
    cout << "        widths:";
    displayList(widths);
    cout << "        patterns";
    for(unsigned int i = 0; i < patterns.size(); i++)
        cout << "(" << patterns[i][0] << "," << patterns[i][1] << ") ";
    cout << endl;
}


void XCSP3PrintCallbacks::buildConstraintNoOverlap(string id, vector<XVariable *> &origins, vector<int> &lengths, bool zeroIgnored) {
    cout << "\n    nooverlap constraint" << endl;
    cout << "        origins";
    displayList(origins);
    cout << "        lengths";
    displayList(lengths);
}


void XCSP3PrintCallbacks::buildConstraintNoOverlap(string id, vector<XVariable *> &origins, vector<XVariable *> &lengths, bool zeroIgnored) {
    cout << "\n    nooverlap constraint" << endl;
    cout << "        origins:";
    displayList(origins);
    cout << "        lengths";
    displayList(lengths);
}


void XCSP3PrintCallbacks::buildConstraintNoOverlap(string id, vector <vector<XVariable *> > &origins, vector <vector<int> > &lengths, bool zeroIgnored) {
    cout << "\n    kdim (int lengths) nooverlap constraint" << endl;
    cout << "origins: " << endl;
    for(unsigned int i = 0; i < origins.size(); i++) {
        cout << "        ";
        displayList(origins[i]);
    }
    cout << "lengths: " << endl;
    for(unsigned int i = 0; i < origins.size(); i++) {
        cout << "        ";
        displayList(lengths[i]);
    }

}


void XCSP3PrintCallbacks::buildConstraintNoOverlap(string id, vector <vector<XVariable *> > &origins, vector <vector<XVariable *> > &lengths, bool zeroIgnored) {
    cout << "\n    kdim (lenghts vars nooverlap constraint" << endl;
    cout << "origins: " << endl;
    for(unsigned int i = 0; i < origins.size(); i++) {
        cout << "        ";
        displayList(origins[i]);
    }
    cout << "lengths: " << endl;
    for(unsigned int i = 0; i < origins.size(); i++) {
        cout << "        ";
        displayList(lengths[i]);
    }
}


void XCSP3PrintCallbacks::buildConstraintInstantiation(string id, vector<XVariable *> &list, vector<int> &values) {
    cout << "\n    instantiation constraint" << endl;
    cout << "        list:";
    displayList(list);
    cout << "        values:";
    displayList(values);

}


void XCSP3PrintCallbacks::buildObjectiveMinimizeExpression(string expr) {
    // cout << "\n    objective: minimize" << expr << endl;
}


void XCSP3PrintCallbacks::buildObjectiveMaximizeExpression(string expr) {
    cout << "\n    objective: maximize" << expr << endl;
}


void XCSP3PrintCallbacks::buildObjectiveMinimizeVariable(XVariable *x) {
    // cout << "\n    objective: minimize variable " << x << endl;
}


void XCSP3PrintCallbacks::buildObjectiveMaximizeVariable(XVariable *x) {
    cout << "\n    objective: maximize variable " << x << endl;
}


void XCSP3PrintCallbacks::buildObjectiveMinimize(ExpressionObjective type, vector<XVariable *> &list, vector<int> &coefs) {
    XCSP3CoreCallbacks::buildObjectiveMinimize(type, list, coefs);
}


void XCSP3PrintCallbacks::buildObjectiveMaximize(ExpressionObjective type, vector<XVariable *> &list, vector<int> &coefs) {
    XCSP3CoreCallbacks::buildObjectiveMaximize(type, list, coefs);
}


void XCSP3PrintCallbacks::buildObjectiveMinimize(ExpressionObjective type, vector<XVariable *> &list) {
    XCSP3CoreCallbacks::buildObjectiveMinimize(type, list);
}


void XCSP3PrintCallbacks::buildObjectiveMaximize(ExpressionObjective type, vector<XVariable *> &list) {
    XCSP3CoreCallbacks::buildObjectiveMaximize(type, list);
}


#endif //COSOCO_XCSP3PRINTCALLBACKS_H
