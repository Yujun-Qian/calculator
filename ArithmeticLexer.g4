lexer grammar ArithmeticLexer;

options { language=Cpp; }

ADD:        '+';
SUB:        '-';
MUL:        '*';
DIV:        '/';
DEC_DIGIT:  [0-9]+;

WS:         [ \t\r]+ -> skip;
NEWLINE:    '\r'? '\n' ;
POPEN:      '(';
PCLOSE:     ')';
