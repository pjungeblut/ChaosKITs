struct Token { // In globalem Vektor, Zugriff über globale Variable.
  int type; // Definiere Konstanten.
  double value;
  Token(int type) : type(type) {}
  Token(int type, int value) : type(type), value(value) {}
};

struct Expression { // Die folgenden Klassen nur für den AST.
  virtual ~Expression() {};
  virtual double getValue() = 0;
};

struct Atom : public Expression {
  double value;
  Atom(int value) : value(value) {};
  double getValue() { return value; }
};

struct BinaryExpression : public Expression {
  Expression *lhs, *rhs;
  BinaryExpression(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs) {}
  ~BinaryExpression() { delete lhs; delete rhs; }
};

struct Addition : public BinaryExpression {
  Addition(Expression *lhs, Expression *rhs) : BinaryExpression(lhs, rhs) {}
  double getValue() { return lhs->getValue() + rhs->getValue(); }
};

Expression* parseF() {
  Expression *lhs;
  switch(tokens[token].type) {
    case NUMBER: return new Atom(tokens[token++].value);
    case LEFT_PAR:
      token++;
      lhs = parseA();
      token++;
      return lhs;
    default:
      return NULL;
}}

Expression* parseA_(Expression *lhs) {
  Expression *plus, *minus;
  if (token >= (int)tokens.size()) return lhs;
  switch(tokens[token].type) {
    case ADDITION:
      token++;
      plus = new Addition(lhs, parseS());
      return parseA_(plus);
    case SUBTRACTION:
      token++;
      minus = new Subtraction(lhs, parseS());
      return parseA_(minus);
    default:
      return lhs;
}}

Expression* parseA() {
  Expression *lhs = parseS(); return parseA_(lhs);
}
