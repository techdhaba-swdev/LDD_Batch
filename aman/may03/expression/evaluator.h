#ifndef EVALUATOR_H// preprocessor directivw which checks macro has defined or not
#define EVALUATOR_H//preprocessor directive to define macro evaluatorh

char* infixToPostfix(char* expression);//function declration which takes char  pointer to character array named expression
int evaluatePostfix(char* expression);//function decalration which takes char namedexpression as argument and return int

#endif//end
