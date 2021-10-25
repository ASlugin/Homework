#pragma once

// Ñonverts from infix notation to postfix notation
// Returns error code:
//  0 - successfully
// -1 - unacceptable characters
// -2 - stack error
int fromInfixToPostfix(const char string[], char output[]);