GOLD Kessels engine for C/C++

The engine comes with a special GOLD template "C - Kessels Engine grammar.h.pgt"
which generates a "grammar.h" file, containing the exact same information
as a .cgt (Compiled Grammar Table) file. This means that the complete grammar
will literally be compiled into your program. Initialization is very fast
because there is no loading of a .cgt file from disk.

A second GOLD template "C - Kessels Engine template.c.pgt" is included that
will create the source for a bare-bones interpreter for you. All you have to
do is fill in the blanks... The "example3.c" program was generated this way.



How to use the engine:


1. Copy the *.pgt templates to the GOLD templates folder. GOLD will
   automatically find and list the templates. On my machine the folder
   is:

      C:\Program Files\GOLD Parser Builder\Templates

2. Create a grammar with GOLD. A small test-grammar has been included
   in file "grammar.grm".

3. In GOLD select "Tools" -> "Create a Skeleton Program"
   - Select "C - Kessels Engine grammar.h"
   - Click "Create"
   - Select "grammar.h"
   - Do you want to replace it - YES.

4. Write a program that calls the parser and interprets the results.
   The easiest way is by creating a template.c with the second GOLD
   template:

   In GOLD select "Tools" -> "Create a Skeleton Program"
   - Select "C - Kessels Engine template.c"
   - Click "Create"
   - Enter a filename, for example "template.c".

   Alternatively you can write your own program. Example1 calls the
   parser and shows output similar to the parse tree in the GOLD test
   window, Example2 demonstrates the tokenizer, Example3 was generated
   by the template, and Example4 is a small calculator that does some
   actual work.

5. Add the "grammar.h", "engine.c", and "engine.h" files to your project.
   There are no special settings needed, the files should flatly compile
   on all C/C++ compilers. A simple "makemic" file is included to compile
   the examples with Microsoft C on Windows (any version). If you want to
   compile on Unix/Linux then use "makemic" as an example for your own
   makefile, adapting it should be easy. On Windows you can compile by
   executing the following commands in a Command Prompt window. The first
   line sets your environment, the second runs Microsoft's "nmake" utility.

       "C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\bin\vcvars32.bat"
       nmake /f makemic



PARSER API

The parser is basically just a single function ("Parse()") that takes a
text buffer as input, and two selection parameters. It returns a struct
full of data with the results (which you cleanup by calling
"DeleteParseData()"). It boils down to adding the following lines to your
program:

  #include "parser.h"
  ....
  Result = Parse(
    InputBuf,                    /* Pointer to the input data. */
    strlen(InputBuf),            /* Number of characters in the input. */
    TRIMREDUCTIONS,              /* 0 = don't trim, 1 = trim reductions. */
    DEBUG,                       /* 0 = no debug, 1 = print debug info. */
    &Token);                     /* The output. */
  ....
  DeleteTokens(Token);

Calling just a single function, can it be that easy? Yes, and no. The parser
does all the hard work and parses and structures the input data for you.
The next step is interpreting the results and do whatever work is necessary,
such as calling functions, evaluating expressions, allocating variables, and
stuff like that. The struct contains the following data:

  struct TokenStruct {
    int ReductionRule;                  /* Index into Grammar.RuleArray[]. */
    struct TokenStruct **Tokens;        /* Array of reduction Tokens. */
    int Symbol;                         /* Index into Grammar.SymbolArray[]. */
    wchar_t *Data;                      /* String with data from the input. */
    int Line;                           /* Line number in the input. */
    int Column;                         /* Column in the input. */
    };

A token can be one of two things: a "symbol" (Token->ReductionRule = -1) or a
"reduction" (Token->ReductionRule >= 0). A symbol is a character string, for
example "+", "function", "176", and other literal strings from the input.
Symbols use the following fields:

    [symbol]
    Token->ReductionRule = -1
    Token->Symbol = index into Grammar.SymbolArray[]
    Token->Data = character string from the input.

The Token->Symbol is an index into the Grammar.SymbolArray[]. The Grammar is a
big struct with lots of arrays and stuff that was compiled by GOLD. Take a
look at "engine.h" for the definitions, and "grammar.h" for the contents.

A reduction is a token that holds pointers to other tokens. It maps to a
rule from your grammar. For example the following rule:

    <Calculations>   ::= <Calculate> <Calculations>

Will generate a Token with the following content:

    [reduction]
    Token->ReductionRule = index into Grammar.RuleArray[] of the rule.
    Token->Tokens[0] = Token for "<Calculate>"
    Token->Tokens[1] = Token for "<Calculations>"

So, the Token->ReductionRule tells you which rule it is, and the Tokens[]
are the elements of the rule. Goto Token->Tokens[0] to find another reduction
Token, or perhaps a symbol. Following tokens will eventually bring you to
a Symbol.

And here the lesson ends. The rest is up to you. Take a look at Example1.c
and Example4.c for working examples.


