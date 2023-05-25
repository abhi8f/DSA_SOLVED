#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Symbol {
    char letter;
    int alphabetIndex;
    int positionIndex;
};

bool compareByWeight(const Symbol& symbol1, const Symbol& symbol2) {
    return (symbol1.alphabetIndex * symbol1.positionIndex) > (symbol2.alphabetIndex * symbol2.positionIndex);
}

string getMaxWeightString(const string& inputString) {
    vector<Symbol> symbols;
    vector<Symbol> lowercaseSymbols;
    vector<Symbol> uppercaseSymbols;
    
    // Store the symbols in a vector along with their alphabet index and position index
    for (int i = 0; i < inputString.length(); i++) {
        Symbol symbol;
        symbol.letter = inputString[i];
        symbol.positionIndex = i + 1;
        
        if (symbol.letter >= 'a' && symbol.letter <= 'z') {
            symbol.alphabetIndex = symbol.letter - 'a' + 1;
            lowercaseSymbols.push_back(symbol);
        } else if (symbol.letter >= 'A' && symbol.letter <= 'Z') {
            symbol.alphabetIndex = (symbol.letter - 'A' + 1) * 2;
            uppercaseSymbols.push_back(symbol);
        }
        
        symbols.push_back(symbol);
    }
    
    // Sort the lowercase symbols based on their weight (alphabet index * position index)
    sort(lowercaseSymbols.begin(), lowercaseSymbols.end(), compareByWeight);
    // Sort the uppercase symbols based on their weight (alphabet index * position index)
    sort(uppercaseSymbols.begin(), uppercaseSymbols.end(), compareByWeight);
    
    // Construct the resulting string
    string result;
    
    for (const Symbol& symbol : lowercaseSymbols) {
        result += symbol.letter;
    }
    
    for (const Symbol& symbol : uppercaseSymbols) {
        result += symbol.letter;
    }
    
    return result;
}

int main() {
    string inputString;
    cout << "Enter a string of unique symbols: ";
    getline(cin, inputString);
    
    string maxWeightString = getMaxWeightString(inputString);
    
    cout << "Max weight string: " << maxWeightString << endl;
    
    return 0;
}
