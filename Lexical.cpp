#include <bits/stdc++.h>
using namespace std;

enum TokenType {
    KEYWORD, IDENTIFIER, OPERATOR, INTEGER_LITERAL, FLOAT_LITERAL, PUNCTUATION, UNKNOWN
};

unordered_set<string> keywords = {
    "int", "float", "double", "char", "void", "return", "if", "else", "for", "while",
    "break", "continue", "class", "struct", "public", "private", "protected"
};

unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!",
    "+=", "-=", "*=", "/=", "%=", "++", "--"
};

unordered_set<char> punctuation = {';', '(', ')', '{', '}', '[', ']', ',', '.'};

struct Token {
    string value;
    TokenType type;
};

bool isIntegerLiteral(const string& token) {
    for (char ch : token) {
        if (!isdigit(ch)) return false;
    }
    return !token.empty();
}

bool isFloatLiteral(const string& token) {
    bool dotSeen = false;
    for (char ch : token) {
        if (ch == '.') {
            if (dotSeen) return false;
            dotSeen = true;
        } else if (!isdigit(ch)) {
            return false;
        }
    }
    return dotSeen && !token.empty();
}

TokenType getTokenType(const string& token) {
    if (keywords.find(token) != keywords.end()) return KEYWORD;
    if (isIntegerLiteral(token)) return INTEGER_LITERAL;
    if (isFloatLiteral(token)) return FLOAT_LITERAL;
    if (operators.find(token) != operators.end()) return OPERATOR;
    if (token.size() == 1 && punctuation.find(token[0]) != punctuation.end()) return PUNCTUATION;
    return IDENTIFIER;
}

vector<Token> tokenize(string code) {
    vector<Token> tokens;
    string token = "";

    for (size_t i = 0; i < code.length(); i++) {
        char ch = code[i];

        if (isspace(ch)) {
            if (!token.empty()) {
                tokens.push_back({token, getTokenType(token)});
                token = "";
            }
            continue;
        }
        if (isdigit(ch) || (ch == '.' && !token.empty() && isdigit(token[0]))) {
            token += ch;
            while (i + 1 < code.length() && (isdigit(code[i + 1]) || code[i + 1] == '.')) {
                token += code[i + 1];
                i++;
            }
            tokens.push_back({token, getTokenType(token)});
            token = "";
            continue;
        }

        if (operators.find(string(1, ch)) != operators.end()) {
            if (!token.empty()) {
                tokens.push_back({token, getTokenType(token)});
                token = "";
            }
            string op(1, ch);
            if (i + 1 < code.length() && operators.find(op + code[i + 1]) != operators.end()) {
                op += code[i + 1];
                i++;
            }
            tokens.push_back({op, OPERATOR});
            continue;
        }

        if (punctuation.find(ch) != punctuation.end()) {
            if (!token.empty()) {
                tokens.push_back({token, getTokenType(token)});
                token = "";
            }
            tokens.push_back({string(1, ch), PUNCTUATION});
            continue;
        }

        token += ch;
    }

    if (!token.empty()) {
        tokens.push_back({token, getTokenType(token)});
    }

    return tokens;
}

void printTokens(const vector<Token>& tokens) {
    for (const auto& token : tokens) {
        string type;
        switch (token.type) {
            case KEYWORD: type = "KEYWORD"; break;
            case IDENTIFIER: type = "IDENTIFIER"; break;
            case OPERATOR: type = "OPERATOR"; break;
            case INTEGER_LITERAL: type = "INTEGER_LITERAL"; break;
            case FLOAT_LITERAL: type = "FLOAT_LITERAL"; break;
            case PUNCTUATION: type = "PUNCTUATION"; break;
            default: type = "UNKNOWN";
        }
        cout << "[" << type << "] " << token.value << endl;
    }
}

int main() {
    string code = "int main() { float x = 3.14; if (x > 2.0) return 0; }";
    cout << "Source Code: " << code << "\n\nTokenized Output:\n";
    vector<Token> tokens = tokenize(code);
    printTokens(tokens);
    return 0;
}
