parser grammar ArithmeticParser;

options { tokenVocab=ArithmeticLexer; language=Cpp; }

expression
    : op=(ADD|SUB) expression # SignExpOp
    | expression op=(MUL|DIV) expression # MulDivOp
    | expression op=(ADD|SUB) expression # AddSubOp
    | POPEN expression PCLOSE # ParenthesesOp
    | atom # ToAtom
;

atom
    : DEC_DIGIT # DigitOp
    | op=(ADD|SUB) DEC_DIGIT # SignOp
;

