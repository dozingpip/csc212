#include "freqtable.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

int main(int argc, char **argv) {
    // this program expects 1 command line argument
    if (argc != 2) {
        std::cout << "Usage: ./main <filename>\n";
        std::cout << "\t<filename> path to an input text file\n";
        return 0;
    }

    // create the frequency table
    FreqTable mytree;

    // open the text file and read its contents
    // insert every word into the tree
    std::ifstream in_file(argv[1]);
    for(std::string w ; in_file >> w ; ) {
        // only keep alphanumeric characters
        // (uses fancy lambda functions from C++ 11)
        w.erase(std::remove_if(w.begin(), w.end(), [](char c) {return !std::isalnum(c);}), w.end());
        // ignore empty words
        if (w.size() == 0) continue;
        // insert word into the three
            mytree.insert(w.c_str());
        // you can use std::cout at this point to inspect the words when your program runs
        // std::cout << w << std::endl;
    }
    if(mytree.contains("bloop")) std::cout<<"has"<<std::endl;
    else std::cout<<"nope"<<std::endl;
    std::cout<<mytree.size()<<std::endl;
    
    // print the frequency table
    mytree.print_all();
    std::cout<<std::endl<<"erasing"<<std::endl;
    mytree.erase("do");
    mytree.erase("56");
    mytree.erase("90");
    mytree.erase("x47");
    mytree.print_all();
    std::cout<<"n_elem: "<<mytree.size()<<std::endl;
    if(mytree.contains("bloop")) std::cout<<"has"<<std::endl;
    else std::cout<<"nope"<<std::endl;

    // here you can add more code to test all of your methods
    // TODO

    return 0;
}