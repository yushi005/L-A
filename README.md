**PROJECT ON LEXICAL ANALYSER:**

**What is a lexical analyser?**

A lexical analyzer (lexer) is a program that processes an input stream of text (usually source code) and converts it into a sequence of tokens. Tokens are meaningful units like keywords, identifiers, operators, and literals, which are then used by the parser for further analysis.

**How It Works**
Reading the Code:

The program takes a sample C++-like code snippet as input.
It scans the code character by character, breaking it into meaningful components.
Tokenization Process:

It recognizes different types of tokens:
Keywords (e.g., int, float, return, if); 
Identifiers (e.g., variable and function names); 
Operators (+, -, ==, >=, etc.); 
Integer and Floating-point Literals (e.g., 3.14, 2, 0); 
Punctuation (e.g., {, }, ;, (, )); 
The program efficiently determines the type of each token using unordered sets for quick lookups and helper functions for number detection.
Logic Behind Token Classification:

Keywords, Operators, and Punctuation are checked against predefined sets.
Numbers are classified based on whether they contain a decimal point.
Anything else that isn’t predefined is treated as an identifier (likely a variable or function name).

Final Output:
The program prints each token along with its type, making it easy to understand how the code is broken down.
Key Takeaways
Uses efficient string processing techniques for token recognition.
Handles multi-character operators like >=, !=, +=.
Differentiates between integers and floating-point numbers correctly.
Uses unordered sets for fast lookups.

