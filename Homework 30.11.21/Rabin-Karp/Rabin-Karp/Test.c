#include "Test.h"
#include "RabinKarp.h"

bool testPassed(void)
{
    bool result = rabinKarpSearchInFile("carelessness", "InputTest.txt") == 5727;
    result = result && rabinKarpSearchInFile("Genoa", "InputTest.txt") == 29 && rabinKarpSearchInFile("Genoa", "Outpat.txt") == -2;
    result = result && rabinKarpSearchInFile("ahahahahah", "InputTest.txt") == -1 && rabinKarpSearchInFile("as if it had only", "InputTest.txt") == 5740;
    return result;
}