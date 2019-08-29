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
int a2[1000];                   // array for storing the variable for counting disjuctions
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
int flag_klee = 2;  //If this is == 1 then it is not pure C code (i.e it is with klee_assumes ) , if == 2 it si pure C code


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
    cout << "#include <klee/klee.h>" << endl << "#include <assert.h>" << endl << "#include <stdio.h>" << endl << "#include <stdlib.h>" << endl << "int main () {" << endl;
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
}


void XCSP3PrintCallbacks::endVariables() {
    // cout << " end variables declaration" << endl << endl;
}


void XCSP3PrintCallbacks::beginVariableArray(string id) {
    // cout << "    array: " << id << endl;
}


void XCSP3PrintCallbacks::endVariableArray() {
}


void XCSP3PrintCallbacks::beginConstraints() {
    // cout << " start constraints declaration" << endl;
}


void XCSP3PrintCallbacks::endConstraints() {
    // cout << "\n end constraints declaration" << endl << endl;

    
    // This is for the last block of extensional constraints which does not get printed
    // Now it is getting printed, so it is fine
    // if(no_tuples > 0){
    //     string temporary[100];
    //     int i = 0;
    //     std::stringstream test(currentextblock);std::string segment;std::vector<std::string> seglist;

    //     while(std::getline(test, segment, '_'))
    //     {
    //        seglist.push_back(segment);
    //        cout << seglist[i] << "  " << segment <<endl;
    //        temporary[i] = "var" + seglist[i];
    //        i++;
    //     }
    //     // cout << i << " hello";
    //     extblock[extention] = currentextblock;
    //     cout << "int ext" << currentextblock << " = 1;" << endl;
    //     extention++;

    //     cout << "if(";
    //     int counter = 0;
    //     while(counter < (no_tuples/i))
    //     {    
    //         cout << "( ";
    //         for(int k = 0; k < i-1; k++){    // or maybe k <= i, but not list.size as block has changed
    //             cout << temporary[k] << " == " << mainext[counter*(i)+k] << " && ";
    //         }
    //         cout << temporary[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
    //         counter++;
    //     }
    //     cout << " 0) " << endl;      // for the last "||"

    //     if(!supp){
    //         cout << "ext" + currentextblock << " = 0 ;" << endl;
    //     }
    //     else if (supp){
    //         cout << "ext" + currentextblock << " = 1;" << endl;
    //     }
    // }

    cout << "int cntdis = 1;" << endl;
    cout << "int exten = 1;" << endl;
    
    if(cntdisjunctions > 0){
        cout << "if( ";
        for (int i = 0; i < cntdisjunctions-1; ++i)
        {
            cout << "myvar" << i << " == 1" << " && ";
        }
        cout << "myvar" << cntdisjunctions-1 << " == 1 )" << endl;      // for the last variable
        cout << "cntdis = 1;" << endl;
        cout << "else cntdis = 0;" << endl;
    }

    if(extention > 0){
        cout << "if( ";
        for (int i = 0; i < extention-1; ++i)
        {
            cout << "ext" << extblock[i] << " == 1" << " && ";
        }
        cout << "ext" << extblock[extention-1] << " == 1 )" << endl;      // for the last variable
        cout << "exten = 1;" << endl;
        cout << "else exten = 0;" << endl;
        // cout << "printf(\"SAT\\n\");" << endl;
        // cout << "else printf(\"UNSAT\\n\");" << endl;
    }

    cout << "if( cntdis == 1 && exten == 1)" << endl << "assert(0);" << endl;
    cout << "else printf(\"UNSAT\\n\");" << endl;

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
    int flag_here;
    if(flag_klee == 1)
        flag_here = 1;
    else if(flag_klee == 2)     // for C code
        flag_here = 2;
    
    // This is using klee_assumes
    if(flag_here == 1){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        cout << "klee_assume( var" << countvars << " >= " << minValue << " );" << endl << "klee_assume( var" << countvars << " <= " << maxValue  << " );" << endl;
        arr[countvars] = id;
        countvars++;
    }

    // This is pure C code for this function
    if(flag_here == 2){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
         }
        cout << "if ((" << n << " >= " << minValue << ") && (" << n << " <= " << maxValue << ") && ("<< var_global << " == 1)) {" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        arr[countvars] = id;
        countvars++;
    }
}


void XCSP3PrintCallbacks::buildVariableInteger(string id, vector<int> &values) {
    // This implementation won't work as I just can't consider the min and max value, domain can be like 2,4,6 where this approach will fail

    int flag_var_vector;
    if(flag_klee == 1)
        flag_var_vector = 3;
    else if(flag_klee == 2)     // for C code
        flag_var_vector = 4;

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
        arr[countvars] = id;
        countvars++;
    }

    // Now changing strategy for declaring variables for with domain of type of a vector. 
    // This will allocate just one variable for declaring range of all such variables, use reduction in no of variables used
    // This is a version of pure C code. Another is flag_var_vector == 4
    else if(flag_var_vector == 2){
         cout << "int var" << countvars << ";" << endl;
         string n = "var" + std::to_string(countvars);
         cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
         if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
         }
            cout << "if ((" << n << " == " << values[0];
            for (int i = 1; i < values.size(); ++i)
            {
                cout << " || " << n << " == " << values[i];
            }
            cout << " ) && " << var_global << " == 1) {" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;
            arr[countvars] = id;
            countvars++;
    }

    // This strategy will not use any variable for declaring but only klee_assume, it can reduce the number of paths for KLEE
    else if(flag_var_vector == 3){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        auto minmax = std::minmax_element(std::begin(values), std::end(values));
        int min = *(minmax.first);
        int max = *(minmax.second);
        cout << "klee_assume(" << n << " >= " << min << ");\n";
        cout << "klee_assume(" << n << " <= " << max << ");\n";

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
                cout << "klee_assume(" << n << " != " << i << ");\n";
            }
        }
        arr[countvars] = id;
        countvars++;
    }

    // This is the implementation in only C code, no klee_assumes, ofc klee_make_symbolic will be there. This will be C code version for
    // flag_var_vector == 3, will implement later
    else if(flag_var_vector == 4){
        cout << "int var" << countvars << ";" << endl;
        string n = "var" + std::to_string(countvars);
        cout << "klee_make_symbolic(&var" << countvars << ", sizeof(var" << countvars << "), \"" << n << "\");" << endl;
        auto minmax = std::minmax_element(std::begin(values), std::end(values));
        int min = *(minmax.first);
        int max = *(minmax.second);
        
        if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
         }
         cout << "if ((" << n << " >= " << min << ") && (" << n << " <= " << max << ") && ( "; 
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
                cout << n << " != " << i << ") && ( ";
            }
         }
         cout << var_global << " == 1)) {" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;
         arr[countvars] = id;
         countvars++;
        }

}


void XCSP3PrintCallbacks::buildConstraintExtension(string id, vector<XVariable *> list, vector <vector<int> > &tuples, bool support, bool hasStar) 
{
    // cout << "\n    extension constraint : " << id << endl;
    // cout << "        " << (support ? "support" : "conflict") << " arity:" << list.size() << " nb tuples: " << tuples.size() << " star: " << hasStar << endl;
    // cout << "        ";

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
    
    else if(flagext == 2){  // lesser variables
        string enn = "";      // storing the tuples temporarily
        int started = 0;
        string temp[10000];      // store the vars temporarily
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
                cout << q << " = 0;" << endl;
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
                cout << q << " = 1;" << endl;
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
            // if(no_tuples == 0)       // this will occur for the first block
            // {
            //     currentextblock = enn;
            //     for (int i = 0; i < tuples.size(); ++i){
            //         for(int j = 0; j < list.size(); ++j){
            //             mainext[no_tuples] = tuples[i][j];
            //             no_tuples++;
            //         }
            //    }

            //    // We must print for the first block as well, I don't know where this will fail, so check once each time
            //     string temporary[100];
            //     int i = 0;
            //     std::stringstream test(enn);
            //     std::string segment;
            //     std::vector<std::string> seglist;

            //     while(std::getline(test, segment, '_'))
            //     {
            //        seglist.push_back(segment);
            //        temporary[i] = "var" + seglist[i];
            //        i++;
            //     }
            //     // In this implementation using underscores as separator, i must not be decremented by 1 

            //     extblock[extention] = enn;
            //     cout << "int ext" << enn << " = 1;" << endl;
            //     extention++;

            //     cout << "if(";
            //     int counter = 0;
            //     while(counter < (no_tuples/i))
            //     {    
            //         cout << "( ";
            //         for(int k = 0; k < i-1; k++){    // or maybe k <= i, but not list.size as block has changed
            //             cout << temporary[k] << " == " << mainext[counter*(i)+k] << " && ";
            //         }
            //         cout << temporary[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
            //         counter++;
            //     }
            //     cout << " 0) " << endl;      // for the last "||"

            //     if(!support){
            //         cout << "ext" + enn << " = 0 ;" << endl;
            //     }
            //     else if (support){
            //         cout << "ext" + enn << " = 1;" << endl;
            //         cout << "else ext" + enn << " = 0;" << endl;
            //     }

            // }
            
            // else {       // this will occur when change of blocks occur and hence hence printing should be performed here
                        // Also things must be refreshed for next block
                no_tuples = 0;
                currentextblock = enn;      // this is the enn with underscores
                
                for (int i = 0; i < tuples.size(); ++i){
                    for(int j = 0; j < list.size(); ++j){
                        mainext[no_tuples] = tuples[i][j];
                        no_tuples++;
                    }
               }
                string temporary[100];
                // std::istringstream iss(currentextblock); string enn2 = "";
                int i = 0;
                std::stringstream test(enn);
                std::string segment;
                std::vector<std::string> seglist;

                while(std::getline(test, segment, '_'))
                {
                   seglist.push_back(segment);
                   temporary[i] = "var" + seglist[i];
                   i++;
                }

                // In this implementation using underscores as separator, i must not be decremented by 1 

                extblock[extention] = enn;
                cout << "int ext" << enn << " = 1;" << endl;
                extention++;

                cout << "if(";
                int counter = 0;
                while(counter < (no_tuples/i))
                {    
                    cout << "( ";
                    for(int k = 0; k < i-1; k++){    // or maybe k <= i, but not list.size as block has changed
                        cout << temporary[k] << " == " << mainext[counter*(i)+k] << " && ";
                    }
                    cout << temporary[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
                    counter++;
                }
                cout << " 0) " << endl;      // for the last "||"

                if(!support){
                    cout << "ext" + enn << " = 0 ;" << endl;
                }
                else if (support){
                    cout << "ext" + enn << " = 1;" << endl;
                    cout << "else ext" + enn << " = 0;" << endl;
                }

                // Now code for refreshing things for this new block
               //  currentextblock = enn;      // this is the enn with underscores
               //  no_tuples = 0;
               //  for (int i = 0; i < tuples.size(); ++i){
               //      for(int j = 0; j < list.size(); ++j){
               //          mainext[no_tuples] = tuples[i][j];
               //          no_tuples++;
               //      }
               // }
            // }
        }

    }
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
}


void XCSP3PrintCallbacks::buildConstraintExtension(string id, XVariable *variable, vector<int> &tuples, bool support, bool hasStar) {
    cout << "\n    extension constraint with one variable: " << id << endl;
    cout << "  " << (support ? "support" : "conflict") << " nb tuples: " << tuples.size() << " star: " << hasStar << endl;
    cout << (*variable) << endl;
}


void XCSP3PrintCallbacks::buildConstraintExtensionAs(string id, vector<XVariable *> list, bool support, bool hasStar) {

    // cout << "  " << (support ? "support" : "conflict") << " nb tuples: " << " star: " << hasStar << endl;

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
    cout << "int ext" << enn << " = 1;" << endl;
    extention++;

    cout << "if(";
    int counter = 0;
    int i = list.size();
    while(counter < (no_tuples/i))
    {    
        cout << "( ";
        for(int k = 0; k < i-1; k++){    // or maybe k <= i, but not list.size as block has changed
            cout << temp[k] << " == " << mainext[counter*(i)+k] << " && ";
        }
        cout << temp[i-1] << " == " << mainext[counter*(i)+(i-1)] << " )" << " || ";
        counter++;
    }
    cout << " 0) " << endl;      // for the last "||"
    if(!support){
        cout << "ext" + enn << " = 0 ;" << endl;
    }
    else if (support){
        cout << "ext" + enn << " = 1;" << endl;
        cout << "else ext" + enn << " = 0;" << endl;
    }
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
        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(" << temp[0] << " != " << temp[1] << " && (" << temp[2] << " + " << temp[3] << " >=2 ) && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        } 

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

        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(0 > (" << temp[0] << " - " << temp[1] << ")*(" << temp[2] << " - " << temp[3] << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
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

        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if((" << temp[0] << " - " << temp[1] << " == " << temp[2] << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }   
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
        
        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if((" << temp[0] << " - " << temp[1] << ") != (" << temp[2] << " - " << temp[3] << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
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
        if(declare_var_for_abs == 0){
            cout << "int var_for_abs;\n";
            declare_var_for_abs = 1;
        }
        cout << "var_for_abs = " << temp[1] << " - " << temp[2] << ";\n";
        cout << "var_for_abs = (var_for_abs >= 0) ? var_for_abs : var_for_abs*(-1);\n";
        
        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << " == var_for_abs );\n";
        }
        
        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(" << temp[0] << " == var_for_abs ) && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
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
        
        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(" << temp[0] << " == (" << temp[1] << " + "  << temp[2] << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
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
        if(declare_var_for_abs == 0){
            cout << "int var_for_abs;\n";
            declare_var_for_abs = 1;
        }
        
        if(done_elm1 == 0)
            temp[0] = elm1;     // for cases when elm1 is an integer and not a variable

        cout << "var_for_abs = " << temp[1] << " - " << temp[2] << ";\n";
        cout << "var_for_abs = (var_for_abs >= 0) ? var_for_abs : var_for_abs*(-1);\n";
        
        if(flag_klee == 1){
            cout << "klee_assume(" << temp[0] << " != (" << temp[1] << " + "  << temp[2] <<  "));\n";
        }
        
        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(" << temp[0] << " != (" << temp[1] << " + "  << temp[2] << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
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

       else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")%" << elm4 << ") == " << temp[3] << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
       }
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

        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(((" << temp[0] << " + " << temp[1] << " + " << temp[2] << ")/" << elm4 << ") == " << temp[3] << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
       }

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

        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(" << temp[0] << sign << elm2 << ") && (" << var_global << " == 1))";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
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
        if(done_for_special == 0){
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

        cout << "var_for_abs1 = (" << temp[0] << "/100) - " << "(" << temp[1] << "/100)" << ";\n";
        cout << "var_for_abs1 = (var_for_abs1 >= 0) ? var_for_abs1 : var_for_abs1*(-1);\n";
        cout << "check1 = (var_for_abs1 == 1) ? 1 : 0;\n";

        cout << "var_for_abs2 = (" << temp[0] << "%100) - " << "(" << temp[1] << "%100)" << ";\n";
        cout << "var_for_abs2 = (var_for_abs2 >= 0) ? var_for_abs2 : var_for_abs2*(-1);\n";
        cout << "check2 = (var_for_abs2 == 2) ? 1 : 0;\n";

        cout << "var_for_abs3 = (" << temp[0] << "/100) - " << "(" << temp[1] << "/100)" << ";\n";
        cout << "var_for_abs3 = (var_for_abs3 >= 0) ? var_for_abs3 : var_for_abs3*(-1);\n";
        cout << "check3 = (var_for_abs3 == 2) ? 1 : 0;\n";

        cout << "var_for_abs4 = (" << temp[0] << "%100) - " << "(" << temp[1] << "%100)" << ";\n";
        cout << "var_for_abs4 = (var_for_abs4 >= 0) ? var_for_abs4 : var_for_abs4*(-1);\n";
        cout << "check4 = (var_for_abs4 == 1) ? 1 : 0;\n";

        cout << "final = ((check1 == 1 && check2 == 1) || (check3 == 1 && check4 == 1)) ? 1 : 0;\n";
        // cout << "if (final == 0) {printf(\"UNSAT\"); exit(0);}\n";
        if(flag_klee == 1){
            cout << "klee_assume(final == 1);\n";      // I am not sure if I need to make different final variables here, will understnad when I check my solutions
        }
        
        else if(flag_klee == 2){
            if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
                done_vars = 1;
                string q = "myvar" + std::to_string(cntdisjunctions);
                cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
                var_global = q;
                cntdisjunctions++;
            }
            cout << "if(final == 1);\n";
            cout << "{" << var_global << "= 1;}" << endl  << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; 
        }
    }

    else if (type == 0)
        assert(0);

}


void XCSP3PrintCallbacks::buildConstraintPrimitive(string id, OrderType op, XVariable *x, int k, XVariable *y) {
    // It comes here if all arguments are variables
    // cout << "\n   intension constraint " << id << ": " << x->id << (k >= 0 ? "+" : "") << k << " op " << y->id << endl;
    // for cases with ne(%0,%1) 
    if(op == 6){        // op == 6 corresponds to ne , described in file Constants.h
        string temp[100];
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
        cout << "klee_assume(" << temp[0] << " != " << temp[1] << ");\n";
    }

    // for cases with eq(%0,%1)
    
    else if(op == 5){             // op == 5 corresponds to eq , described in file Constants.h
        string temp[100];
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
        cout << "klee_assume(" << temp[0] << " == " << temp[1] << ");\n";
    }

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


void XCSP3PrintCallbacks::buildConstraintMDD(string id, vector<XVariable *> &list, vector <XTransition> &transitions) {
    cout << "\n    mdd constraint" << endl;//no
    cout << "        ";
    displayList(list);
    cout << "        transitions: ";
    for(unsigned int i = 0; i < (transitions.size() > 4 ? 4 : transitions.size()); i++) {
        cout << "(" << transitions[i].from << "," << transitions[i].val << "," << transitions[i].to << ") ";
    }
    if(transitions.size() > 4) cout << "...";
    cout << endl;
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
    
    int flag_all_different;
    int flag_var_vector;
    if(flag_klee == 1)
        flag_all_different = 1;
    else if(flag_klee == 2)     // for C code
        flag_all_different = 2;
    
    // This is with klee_assumes
    if(flag_all_different == 1){
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                cout << "klee_assume(" << temp[i] <<  "!=" << temp[j] << ");" << endl; 
            }
        }
    }

    // This will be the pure C code for this function
    if(flag_all_different == 2){
        // I am using the same variable for declaring variables, 
        if(done_vars == 0){       // Have declared myvar0 or whichever no myvar is that for once as only one variable is being used for declaring variables
            done_vars = 1;
            string q = "myvar" + std::to_string(cntdisjunctions);
            cout << "int myvar" << cntdisjunctions << " = 1;" << endl;
            var_global = q;
            cntdisjunctions++;
         }

        cout << "if(";
        for(int i = 0; i < k; i++){         // Now start the counter from 2
            for(int j = i+1; j < k; j++){
                cout << "(" << temp[i] <<  "!=" << temp[j] << ") && "; 
            }
        }
        cout << var_global << " == 1)" << "{" << var_global << "= 1;}" << endl << "else {" << var_global << "= 0;}" << endl; //<< "assert(" << q << " == 1);" << endl;; ;


    }
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
    cout << "\n    allEqual constraint" << id << endl;
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
            term[i] = "---------------";
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
        while(term[i] != "---------------"){
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
