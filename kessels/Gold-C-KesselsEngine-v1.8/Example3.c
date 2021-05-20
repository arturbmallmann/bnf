/*

This file was generated by the "C - Kessels engine template.c" template.

*/


#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>                  /* wchar_t */
#include <sys/stat.h>

#include "engine.h"                 /* The Kessels engine. */
#include "grammar.h"                /* Generated by GOLD. */



#define TRIMREDUCTIONS 0            /* 0=off, 1=on */
#define DEBUG          1            /* 0=off, 1=on */




/* Struct for transporting data between rules. Add whatever you need.
   Note: you could also use global variables to store stuff, but using
   a struct like this makes the interpreter thread-safe. */
struct ContextStruct {
  wchar_t *ReturnValue;             /* In this template all rules return a string. */
  int Indent;                       /* For printing debug messages. */
  int Debug;                        /* 0=off, 1=on */
  };




/* Forward definition of the RuleJumpTable. It will be filled with a link
   to a subroutine for every rule later on. */
void (*RuleJumpTable[])(struct TokenStruct *Token, struct ContextStruct *Context);




/***** Helper subroutines ***************************************************/




/* Make a readable copy of a string. All characters outside 32...127 are
   displayed as a HEX number in square brackets, for example "[0A]". */
void ReadableString(wchar_t *Input, wchar_t *Output, long Width) {
  char s1[BUFSIZ];
  long i1;
  long i2;

  /* Sanity check. */
  if ((Output == NULL) || (Width < 1)) return;
  Output[0] = 0;
  if (Input == NULL) return;

  i1 = 0;
  i2 = 0;
  while ((i2 < Width - 1) && (Input[i1] != 0)) {
    if ((Input[i1] >= 32) && (Input[i1] <= 127)) {
        Output[i2++] = Input[i1];
      } else {
        if (Width - i2 > 4) {
          sprintf(s1,"%02X",Input[i1]);
          Output[i2++] = '[';
          Output[i2++] = s1[0];
          Output[i2++] = s1[1];
          Output[i2++] = ']';
          }
        }
    i1++;
    }
  Output[i2] = 0;
  }




void ShowIndent(int Indent) {
  int i;
  for (i = 0; i < Indent; i++) fprintf(stdout,"  ");
  }




/***** Rule subroutine template *********************************************/




/* This subroutine is a template of things that can happen in the
   subroutine of a rule. It shows how to access the value of symbols
   and how to call rules, and how to transport results and stuff via
   the Context.

   For example the rule:

     <Increment> ::= <Expression> '+' Number

   Has 3 sub-tokens:

     Token->Tokens[0] = token for <Expression>, a rule
     Token->Tokens[1] = token for '+', a symbol
     Token->Tokens[2] = token for Number, a symbol

   We know Token->Tokens[0] is a rule, because that's what the grammar
   says. We may assume that the engine has fully populated the sub-tokens
   and don't have to perform any checks. We can immediately call the
   subroutine of the rule, like this:

     RuleJumpTable[Token->Tokens[0]->ReductionRule](Token->Tokens[0],Context);

   The subroutine should hand back it's results via the Context. Here
   is an example of how to store a result in the context:

     Context->ReturnValue = (wchar_t *)wcsdup(....);

   Symbols are literal strings from the input (that was parsed by the
   engine), stored in the sub-token. We can get the value of the "Number"
   symbol like this:

     Value = (wchar_t *)wcsdup(Token->Tokens[2]->Data);

   Further reading:
   - See "engine.h" for the definition of the TokenStruct.
   - See "readme.txt" for a short discussion on how to use the content
     of a Token.
   - See "example4.c" for a working template example.
   */

void RuleTemplate(struct TokenStruct *Token, struct ContextStruct *Context) {
  int i;

  /* Debugging: show the description of the rule. */
  if (Context->Debug > 0) {
    ShowIndent(Context->Indent);
    fprintf(stdout,"Executing rule: %s\n",Grammar.RuleArray[Token->ReductionRule].Description);
    }

  /* For all the sub-Tokens. */
  for (i = 0; i < Grammar.RuleArray[Token->ReductionRule].SymbolsCount; i++) {
    /* See if the Token is a Symbol or a Rule. */
    if (Token->Tokens[i]->ReductionRule < 0) {
        /* It's a Symbol. Make a copy of the Data. Most symbols are grammar,
           for example '+', 'function', 'while', and such, and you won't
           need to look at the Data. Other symbols are literals from the input
           script, for example numbers, strings, variable names, and such. */
        if (Context->ReturnValue != NULL) free(Context->ReturnValue);
        Context->ReturnValue = (wchar_t *)wcsdup(Token->Tokens[i]->Data);

        /* Debugging: show a description of the Symbol, and it's value. */
        if (Context->Debug > 0) {
          ShowIndent(Context->Indent + 1);
          fprintf(stdout,"Token[%u] = Symbol('%s') = '%s'\n",i,
            Grammar.SymbolArray[Token->Tokens[i]->Symbol].Name,
            Context->ReturnValue);
          }

      } else {
        /* It's a rule. */

        /* Debugging: show a description of the rule. */
        if (Context->Debug > 0) {
          ShowIndent(Context->Indent + 1);
          fprintf(stdout,"Token[%u] = Rule = %s\n",i,
            Grammar.RuleArray[Token->Tokens[i]->ReductionRule].Description);
          }

        /* Call the rule's subroutine via the RuleJumpTable. */
        Context->Indent = Context->Indent + 1;
        RuleJumpTable[Token->Tokens[i]->ReductionRule](Token->Tokens[i],Context);
        Context->Indent = Context->Indent - 1;

        /* At this point you will probably want to save the Context->ReturnValue
           somewhere. */

        /* Debugging: show the value that was returned by the rule's subroutine. */
        if (Context->Debug > 0) {
          ShowIndent(Context->Indent + 2);
          fprintf(stdout,"Result value = %s\n",Context->ReturnValue);
          }
        }
    }

  /* Do whatever processing is needed by the rule. Remember to free() the
     Values you have saved. */
  }




/***** Rule subroutines *****************************************************/




/* <Calculations> ::= <Calculate> <Calculations> */
void Rule_Calculations(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <Calculations> ::=  */
void Rule_Calculations2(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <Calculate> ::= print '(' <Expression> ')' */
void Rule_Calculate_print_LParan_RParan(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <Expression> ::= <MultiplyDivide> '+' <Expression> */
void Rule_Expression_Plus(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <Expression> ::= <MultiplyDivide> '-' <Expression> */
void Rule_Expression_Minus(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <Expression> ::= <MultiplyDivide> */
void Rule_Expression(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <MultiplyDivide> ::= <Value> '*' <MultiplyDivide> */
void Rule_MultiplyDivide_Times(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <MultiplyDivide> ::= <Value> '/' <MultiplyDivide> */
void Rule_MultiplyDivide_Div(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <MultiplyDivide> ::= <Value> */
void Rule_MultiplyDivide(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <Value> ::= DecLiteral */
void Rule_Value_DecLiteral(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/* <Value> ::= '(' <Expression> ')' */
void Rule_Value_LParan_RParan(struct TokenStruct *Token, struct ContextStruct *Context) {
  RuleTemplate(Token,Context);
  };




/***** Rule jumptable *******************************************************/




void (*RuleJumpTable[])(struct TokenStruct *Token, struct ContextStruct *Context) = {

  /* 0. <Calculations> ::= <Calculate> <Calculations> */
  Rule_Calculations,

  /* 1. <Calculations> ::=  */
  Rule_Calculations2,

  /* 2. <Calculate> ::= print '(' <Expression> ')' */
  Rule_Calculate_print_LParan_RParan,

  /* 3. <Expression> ::= <MultiplyDivide> '+' <Expression> */
  Rule_Expression_Plus,

  /* 4. <Expression> ::= <MultiplyDivide> '-' <Expression> */
  Rule_Expression_Minus,

  /* 5. <Expression> ::= <MultiplyDivide> */
  Rule_Expression,

  /* 6. <MultiplyDivide> ::= <Value> '*' <MultiplyDivide> */
  Rule_MultiplyDivide_Times,

  /* 7. <MultiplyDivide> ::= <Value> '/' <MultiplyDivide> */
  Rule_MultiplyDivide_Div,

  /* 8. <MultiplyDivide> ::= <Value> */
  Rule_MultiplyDivide,

  /* 9. <Value> ::= DecLiteral */
  Rule_Value_DecLiteral,

  /* 10. <Value> ::= '(' <Expression> ')' */
  Rule_Value_LParan_RParan 
  };




/***** Main *****************************************************************/




/* Load input file from disk into memory. */
wchar_t *LoadInputFile(char *FileName) {
  FILE *Fin;
  char *Buf1;
  wchar_t *Buf2;
  struct stat statbuf;
  size_t BytesRead;
  unsigned long i;

  /* Sanity check. */
  if ((FileName == NULL) || (*FileName == '\0')) return(NULL);

  /* Open the file. */
  Fin = fopen(FileName,"rb");
  if (Fin == NULL) {
    fprintf(stdout,"Could not open input file: %s\n",FileName);
    return(NULL);
    }

  /* Get the size of the file. */
  if (fstat(fileno(Fin),&statbuf) != 0) {
    fprintf(stdout,"Could not stat() the input file: %s\n",FileName);
    fclose(Fin);
    return(NULL);
    }

  /* Allocate memory for the input. */
  Buf1 = (char *)malloc(statbuf.st_size + 1);
  Buf2 = (wchar_t *)malloc(sizeof(wchar_t) * (statbuf.st_size + 1));
  if ((Buf1 == NULL) || (Buf2 == NULL)) {
    fprintf(stdout,"Not enough memory to load the file: %s\n",FileName);
    fclose(Fin);
    if (Buf1 != NULL) free(Buf1);
    if (Buf2 != NULL) free(Buf2);
    return(NULL);
    }

  /* Load the file into memory. */
  BytesRead = fread(Buf1,1,statbuf.st_size,Fin);
  Buf1[BytesRead] = '\0';

  /* Close the file. */
  fclose(Fin);

  /* Exit if there was an error while reading the file. */
  if (BytesRead != statbuf.st_size) {
    fprintf(stdout,"Error while reading input file: %s\n",FileName);
    free(Buf1);
    free(Buf2);
    return(NULL);
    }

  /* Convert from ASCII to Unicode. */
  for (i = 0; i <= BytesRead; i++) Buf2[i] = Buf1[i];
  free(Buf1);

  return(Buf2);
  }




void ShowErrorMessage(struct TokenStruct *Token, int Result) {
  int Symbol;
  int i;
  wchar_t s1[BUFSIZ];

  switch(Result) {
    case PARSELEXICALERROR:
      fprintf(stdout,"Lexical error");
      break;
    case PARSECOMMENTERROR:
      fprintf(stdout,"Comment error");
      break;
    case PARSETOKENERROR:
      fprintf(stdout,"Tokenizer error");
      break;
    case PARSESYNTAXERROR:
      fprintf(stdout,"Syntax error");
      break;
    case PARSEMEMORYERROR:
      fprintf(stdout,"Out of memory");
      break;
    }
  if (Token != NULL) fprintf(stdout," at line %d column %d",Token->Line,Token->Column);
  fprintf(stdout,".\n");

  if (Result == PARSELEXICALERROR) {
    if (Token->Data != NULL) {
        ReadableString(Token->Data,s1,BUFSIZ);
        fprintf(stdout,"The grammar does not specify what to do with '%S'.\n",s1);
      } else {
        fprintf(stdout,"The grammar does not specify what to do.\n");
        }
    }
  if (Result == PARSETOKENERROR) {
    fprintf(stdout,"The tokenizer returned a non-terminal.\n");
    }
  if (Result == PARSECOMMENTERROR) {
    fprintf(stdout,"The comment has no end, it was started but not finished.\n");
    }
  if (Result == PARSESYNTAXERROR) {
    if (Token->Data != NULL) {
        ReadableString(Token->Data,s1,BUFSIZ);
        fprintf(stdout,"Encountered '%S', but expected ",s1);
      } else {
        fprintf(stdout,"Expected ");
        }
    for (i = 0; i < Grammar.LalrArray[Token->Symbol].ActionCount; i++) {
      Symbol = Grammar.LalrArray[Token->Symbol].Actions[i].Entry;
      if (Grammar.SymbolArray[Symbol].Kind == SYMBOLTERMINAL) {
        if (i > 0) {
          fprintf(stdout,", ");
          if (i >= Grammar.LalrArray[Token->Symbol].ActionCount - 2) fprintf(stdout,"or ");
          }
        fprintf(stdout,"'%S'",Grammar.SymbolArray[Symbol].Name);
        }
      }
    fprintf(stdout,".\n");
    }
  }




int main(int argc, char *argv[]){
  wchar_t *InputBuf;
  struct TokenStruct *Token;
  struct ContextStruct Context;
  int Result;

  /* Load the inputfile into memory. */
  InputBuf = LoadInputFile("Example.input");
  if (InputBuf == NULL) exit(1);

  /* Run the Parser. */
  Result = Parse(InputBuf,wcslen(InputBuf),TRIMREDUCTIONS,DEBUG,&Token);

  /* Interpret the results. */
  if (Result != PARSEACCEPT) {
      ShowErrorMessage(Token,Result);
    } else {
      /* Initialize the Context. */
      Context.Debug = DEBUG;
      Context.Indent = 0;
      Context.ReturnValue = NULL;

      /* Start execution by calling the subroutine of the first Token on
         the TokenStack. It's the "Start Symbol" that is defined in the
         grammar. */
      RuleJumpTable[Token->ReductionRule](Token,&Context);
      }

  /* Cleanup. */
  DeleteTokens(Token);
  free(InputBuf);
  }
