#pragma once

#include <stack> 
#include "ArithmeticParserBaseListener.h"

/*
 * interpet an aritmetic expression on integer
 * supported operation: +,-,*,/
 */
class CalculatorListener: public ArithmeticParserBaseListener {

  // results stack
  std::stack<int> int_stack;

public:
  int get_result() {
    auto val = int_stack.top();
    int_stack.pop();
    return val;
  }

  virtual void exitMulDivOp(ArithmeticParser::MulDivOpContext* ctx) override {
    auto right = int_stack.top();
    int_stack.pop();
    auto left = int_stack.top();
    int_stack.pop();

    int val;
    if (ctx->op->getType() == ArithmeticParser::MUL) {
      val = left * right; 
    } else {
      val = left / right;
    }
    int_stack.push(val);
  }

  virtual void exitParenthesesOp(ArithmeticParser::ParenthesesOpContext * /*ctx*/) override { }

  virtual void exitSignExpOp(ArithmeticParser::SignExpOpContext* ctx) override { 
    auto val = int_stack.top();
    int_stack.pop();

    if (ctx->op->getType() == ArithmeticParser::SUB) {
      val *= -1; 
    }
    int_stack.push(val);
   }

  virtual void exitAddSubOp(ArithmeticParser::AddSubOpContext* ctx) override {
    auto right = int_stack.top();
    int_stack.pop();
    auto left = int_stack.top();
    int_stack.pop();

    int val;
    if (ctx->op->getType() == ArithmeticParser::ADD) {
      val = left + right; 
    } else {
      val = left - right;
    }
    int_stack.push(val);
  }

  virtual void exitToAtom(ArithmeticParser::ToAtomContext * /*ctx*/) override { }

  virtual void exitDigitOp(ArithmeticParser::DigitOpContext* ctx) override { 
    int_stack.push(std::stoi(ctx->getText()));
  }

  virtual void exitSignOp(ArithmeticParser::SignOpContext* ctx) override {
    auto val = int_stack.top();
    int_stack.pop();

    if (ctx->op->getType() == ArithmeticParser::SUB) {
      val *= -1; 
    }
    int_stack.push(val);
  }
};

