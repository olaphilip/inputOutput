#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    std::ifstream inputText("input.txt");
    std::ofstream outputText("output.txt");
    std::string currentLine;
    
    if (!inputText){ //checks to see if the input file has been opened
        return 1; //if no, return boolean
    }
    if (!outputText){
        return 1; //if no, return boolean
    }
    
    while (getline(inputText, currentLine)) {
        std::stringstream istream(currentLine);
        std::string wordPlay;
        int num[3];
        int numCounter = 0;
        
        while (getline(istream, wordPlay, ',')) {
            int a;
            std::stringstream wordP;
            wordP << wordPlay;
            wordP >> a;
            num[numCounter] = a;
            numCounter++;
        } //end while 
        
        std::string lineText;
        getline(inputText, lineText);
        int sum = 0;
        
        for (int j = 0; j < 3; ++j) {
            sum += num[j];
        } //end for
        std::ostringstream ostream;
        ostream << lineText;
        
        for (int k = 0; k < sum - 1; ++k) {
            ostream << ", " << lineText;
        } // end for
        outputText << ostream.str() << std::endl;
    }  // end while
    inputText.close();
    outputText.close();
    
    return 0;
} // end main