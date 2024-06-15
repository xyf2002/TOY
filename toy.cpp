#include <cstdio>
enum Token_Type {
  EOF_TOKEN = 0,
  NUMERIC_TOKEN,
  IDENTIFIER_TOKEN,
  PARAN_TOKEN,
  DEF_TOKEN
};

static int get_token() {
  static int LastChar = '';

  while (isspace(LastChar))
    LastChar = fgetc(file);

  if (isalpha(LastChar)) {
    Identifier_string = LastChar;

    while (isalnum((LastChar = fgetc(file))))
      Identifier_string += LastChar;
    if (Identifier_string == "def")
      return DEF_TOKEN;
    return IDENTIFIER_TOKEN;
  }
  if (isdigit(LastChar)) {
    std::string NumStr;
    do {
      NumStr += LastChar;
      LastChar = fgetc(file);
    } while (isdigit(LastChar));
    Numeric_Val = strtod(NumStr.c_str(), 0);
    return NUMERIC_TOKEN;
  }
  if (LastChar == '#') {
    do
      LastChar = fgetc(file);
    while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');
    if (LastChar != EOF)
      return get_token();
  }
  if (LastChar == EOF)
    return EOF_TOKEN;
  int ThisChar = LastChar;
  LastChar = fgetc(file);
  return ThisChar;
}

class BaseAST {
public:
  virtual ~BaseAST();
}

class VariableAST : public BaseAST {
  std::string Var_Name;
  // string object to store name of
  // the variable.
public:
  VariableAST(std::string &name) : Var_Name(name) {} // ..//
  parameterized constructor of variable AST class to be initialized with the
      string passed to the constructor.
};

class NumericAST : public BaseAST {
  int numeric_val;

public:
  NumericAST(intval) : numeric_val(val) {}
};

Class BinaryAST : public BaseAST {
  std::string Bin_Operator; // string object to store
  // binary operator
  BaseAST *LHS, *RHS; // Objects used to store LHS and
                      // RHS of a binary Expression. The LHS and RHS binary
                      // operation can be of any type, hence a BaseAST object
                      // is used to store them.
public:
  BinaryAST(std::string op, BaseAST * lhs, BaseAST * rhs)
      : Bin_Operator(op), LHS(lhs), RHS(rhs) {} // Constructor
  // to initialize binary operator, lhs and rhs of the binary
  // expression.
};

class FunctionDeclAST {
  std::string Func_Name;
  std::vector<std::string> Arguments;

public:
  FunctionDeclAST(const std::string &name, const std::vector<std::string> &args)
      : Func_Name(name), Arguments(args){};
};

class FunctionDefnAST {
  FunctionDeclAST *Func_Decl;
  BaseAST *Body;

public:
  FunctionDefnAST(FunctionDeclAST *proto, BaseAST *body)
      : Func_Decl(proto), Body(body) {}
};

class FunctionCallAST : public BaseAST {
  std::string Function_Callee;
  std::vector<BaseAST *> Function_Arguments;

public:
  FunctionCallAST(const std::string &callee, std::vector<BaseAST *> &args)
      : Function_Callee(callee), Function_Arguments(args) {}
};
