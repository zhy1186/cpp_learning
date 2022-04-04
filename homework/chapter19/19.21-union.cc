#include <iostream>
#include <string>
#include <utility>

class Token {
 public:
  Token() : tok(INT), ival(0){};
  Token(const Token& t) : tok(t.tok) { copyUnion(t); }
  Token(Token&& t) : tok(std::move(t.tok)) { moveUnion(std::move(t)); }
  Token& operator=(const Token&);
  Token& operator=(Token&&);
  ~Token() {
    if (tok == STR) sval.std::string::~string();
  }

  Token& operator=(const std::string&);
  Token& operator=(char);
  Token& operator=(int);
  Token& operator=(double);

 private:
  enum { INT, CHAR, DBL, STR } tok;
  union {
    char cval;
    int ival;
    double dval;
    std::string sval;
  };
  void copyUnion(const Token&);
  void moveUnion(Token&&);
};

Token& Token::operator=(const Token& t) {
  if (tok == STR && t.tok != STR) sval.std::string::~string();
  if (tok == STR && t.tok == STR)
    sval = t.sval;
  else
    copyUnion(t);
  tok = t.tok;
  return *this;
}

Token& Token::operator=(Token&& t) {
  if (this != &t) {
    if (t.tok == STR) t.sval.std::string::~string();
    moveUnion(std::move(t));
    tok = std::move(t.tok);
  }
  return *this;
}

Token& Token::operator=(int i) {
  if (tok == STR) sval.std::string::~string();
  ival = i;
  tok = INT;
  return *this;
}

Token& Token::operator=(double d) {
  if (tok == STR) sval.std::string::~string();
  dval = d;
  tok = DBL;
  return *this;
}

Token& Token::operator=(char c) {
  if (tok == STR) sval.std::string::~string();
  cval = c;
  tok = CHAR;
  return *this;
}

Token& Token::operator=(const std::string& s) {
  if (tok == STR)
    sval = s;
  else
    new (&sval) std::string(s);
  tok = STR;
  return *this;
}

void Token::copyUnion(const Token& t) {
  switch (t.tok) {
    case Token::INT:
      ival = t.ival;
      break;
    case Token::CHAR:
      cval = t.cval;
      break;
    case Token::DBL:
      dval = t.dval;
      break;
    case Token::STR:
      new (&sval) std::string(t.sval);
      break;
  }
}

void Token::moveUnion(Token&& t) {
  switch (t.tok) {
    case INT:
      ival = std::move(t.ival);
      break;
    case CHAR:
      cval = std::move(t.cval);
      break;
    case DBL:
      dval = std::move(t.dval);
      break;
    case STR:
      new (&sval) std::string(std::move(t.sval));
      break;
  }
}

int main(int argc, char** argv) {
  Token t;
  int a = 42;
  t = a;

  return 0;
}
