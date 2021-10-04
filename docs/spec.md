# Specification

## Lexical

### Character Set

```ebnf
character = any valid unicode character;
characters = (character);
```

### End of File

```ebnf
endOfFile = physical end of the file | \u0000 | \u001A
```

### End of Line

```ebnf
endOfLine = \u000A | \u000D\,\u000A\ | endOfFile
```

### White Space

```ebnf
whiteSpace = (\u0020 | \u0009 | \u000B | \u000C)
```

### Comments

```ebnf
comment = (blockComment | lineComment);
blockComment = "/*" (character | endOfLine) "*/";
lineComment = "//" (character) endOfLine;
```

```ebnf
digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
integer = (digit);
decimal = digit | (digit | ".");
number = integer | decimal;
```

### Tokens

```ebnf
tokens = ( token )

token = 
    | symbol
    | number
    | =
    | := # Might not actually be needed
    | :
    | ;
    | +
    | -
    | *
    | *^ # Power
    | /
    | %
    | )
    | (
    | +=
    | -=
    | *=
    | /=
    | %=
    | {
    | }
    | &
    | .
    | ,
    | |
    | ^
    | ^=
    | <<
    | >>
    | |=
    | <<=
    | >>=
    | !
    | ==
    | !=
    | &&
    | ||
    | '
    | "
    | =>
```

### Identifiers, Keywords, Types and other Symbols

```ebnf
symbol = ("_" | character) | ("_" | character | digit);
```

### Keywords

```ebnf
keyword =
| alias
| align
| assert
| auto
| byte
| coroutine
| deprecated
| else
| enum
| export
| extern
| fn
| for
| if
| import
| inline
| mut
| package
| return
| static
| struct
| test
| type
| union
| void
| wait
| while
| yield;
```

## Grammar

### Modules

```ebnf
packageDeclaration = package packageNames;
importDeclaration = (import stringLiteral ) | [moduleName] (packageNames)

moduleName = identifier;
packageNames = (identifer,.)

```

### Declarations

A module is a separate translation unit. Usually in the form of a source file.
A package consists of multiple modules.
