    /* s is the input string of the form "1, -2, 356, 0" 
      v is the output array (must have enough room) 
    */ 
    convert(s, v) { 
      auto m,i,j,c,sign; 
      i = O;    /* array index */ 
      j = -1;   /* character index */ 
     
    init: /* initialize to convert an integer */ 
      m = 0; /* the integer value */ 
      sign = 0; /* sign = 1 if the integer is negative */ 
     
    loop: /* convert an integer */ 
      switch (c = char(s, ++j)) { /* char(s, i) is how you index a string */ 
        case '-': 
          if(sign) goto syntax; /* if already negative, syntax error */ 
          s = 1; /* this integer is negative */ 
        case ' ': 
          goto loop; 
        case '*e': /* *e is how B spells the null terminator, \0 in C */ 
        case ',': /* delimiter or end of string: store converted value */ 
          v[i++] = sign ? (-m) : m;  
          if( c == '*e' ) return(i); /* done */ 
          goto init; 
      } 
      /* none of the above cases . . . if a digit, add to m */ 
      if ( '0' <= c & c <= '9' ) { 
        m = 10*m + c-'0'; 
        goto loop; 
      } 
    /* syntax error . . . print message and return -1 */ 
    syntax: 
      printf("bad syntax*n"); 
      return(-1); 
    }
