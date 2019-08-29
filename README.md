The tool translates XCSP3 benchmarks from XML format to C code
## Running the tool
1. `cd XCSP3-CPP-Parser`
XCSP3-CPP-Parser is the directory where the parser for XCSP3 programs is present. We have implemented the code inside the default XCSP3 C++ Parser.[<https://github.com/xcsp3team/XCSP3-CPP-Parser>]
Most of the changes were made in the file `XCSP3PrintCallbacks.h`, present in the `samples` sub-directory.
2. `cd samples; make` 
Move into the samples directory and compile the Parser. This will generate the executable named `.test` which can be used to translate the XML programs to C code.
3. `./test ../instances/try.xml`
Try out the executable by running on an example XCSP3 file. This will print the translated C code to standard output.

## Benchmarks
Our benchmarks are present in the `benchmarks` directory. The `extensional_benchmarks` and `intensional_benchmarks` sub-directories contains the constraint programs in XML format, downloaded from XCSP3 page [<http://www.xcsp.org>]. There are some scripts and the solution verifier which we used in our experiments, as discussed in paper.

##Generating different versions of C code
1. Line 267 in `XCSP3PrintCallbacks.h` declares a variable `run_klee`. This variable is set to 1 if code transformation is for KLEE and 0 if for LLBMC
2. Line 268 declares a variable named `flag_extensional_benchmarks`, to decide the extensional version desired. The comments in the following lines help with the choice.
3. Line 302 declares a variable named `flag_intensional_benchmarks`, to decide the intensional version desired. The comments in the following lines help with the choice
