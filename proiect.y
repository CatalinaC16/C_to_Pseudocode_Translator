%{
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

extern FILE *yyin;
extern int yylex();

void yyerror(const char* s);

// Inlocuieste toate aparitiile unui substring cu alt substring.
static inline void ReplaceAllOccurrences(string &str, const string &from, const string &to) {
    size_t position = 0;
    // Cauta toate aparitiile substringului 'from' in stringul 'str'.
    while((position = str.find(from, position)) != string::npos) {
        // Inlocuieste aparitia gasita a substringului 'from' cu substringul 'to'.
        str.replace(position, from.length(), to);
        // Actualizeaza pozitia pentru a continua cautarea dupa inlocuire.
        position += to.length(); 
    }
}

// Elimina spatiile suplimentare reprezentate de linii goale consecutive intr-un string.
static inline void TrimSpaces(string &str) {
    size_t position = 0;
    // Cauta toate aparitiile secventei "\n\n" in stringul 'str'.
    while((position = str.find("\n\n", position)) != string::npos) {
        // Inlocuieste aparitia gasita a secventei "\n\n" cu un singur caracter de newline "\n".
        str.replace(position, 2, "\n");
    }
}

%}

%token <number> INTEGER
%token <str> IDENT CHARVAL VOID SCNF PRTF IF ELSE GREATER EQEQ LESSEQ GREATEREQ LESS INCREMENT DECREMENT INCL MULTIPLICATION DIVIDE RETURN PLUSEQ MINUSEQ
%token <doubflt> FLOATVAL
%token PLUS EQ MINUS SEMICOLON COMMA OPPARENTH OPENCURL SCANF DEN QUOTES 
%token INTRESERVE DOUBLERESERVE FLOATRESERVE CHARRESERVE DOT QUOTE  CLPARENTH CLOSECURL  MODULO AND FOR WHILE
%token DO


%union {
    int number;
    char* str;
    double doubflt;
}

// Declaratii pentru tipuri de date utilizate in gramatica
%type <str> doWhile
%type <str> decl_body parameter assgns assgn scnf prtf b_for_fun b_for_funs ifelse comparetype forLoop whileLoop incordec identOrInt call callBody

// Punctul de inceput al gramaticii
%start program

%%
program:
 // Regula pentru program: include directive sau functii sau mesaj de eroare
    INCL fncns|fncns|{cout<<"Enter a valid input"<<endl;}
    ;
    
fncns:
// Regula pentru lista de functii: poate fi o functie singulara sau o lista de functii
     fncns fncn|fncn;
     
fncn: 
    // Regula pentru definirea unei functii fara corp
    typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL CLOSECURL
        { cout << "FUNCTIE " << $2 << " " << $4 << "\nSFARSIT FUNCTIE " << $2 << "\n\n"; }
    |
    // Regula pentru definirea unei functii cu corp de instructiuni
    typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL b_for_funs CLOSECURL {    
        string s = "FUNCTIE " + string($2) + " " + string($4) + "\n" + string($7);
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s); 
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << $2 << "\n\n";
        }
    |
    // Regula pentru definirea unei functii cu return
    typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL b_for_funs RETURN IDENT SEMICOLON CLOSECURL {    
        string s = "FUNCTIE " + string($2) + " " + string($4) + "\n" + string($7) + "\n" + string($2) + "=" + string($9);
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s);
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << $2 << "\n\n";
        }
    |
    // Regula pentru definirea unei functii cu return si apel de functie
    typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL RETURN IDENT OPPARENTH IDENT CLPARENTH SEMICOLON CLOSECURL {    
        string s = "FUNCTIE " + string($2) + " " + string($4) + "\n " + string($7) + " " + string($2) + "=" + string($10);
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s);
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << $2 << "\n\n";
        }
    |
    // Regula pentru definirea unei functii cu corp de instructiuni si return de apel de functie
    typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL b_for_funs RETURN IDENT OPPARENTH IDENT CLPARENTH SEMICOLON CLOSECURL {    
        string s = "FUNCTIE " + string($2) + " " + string($4) + "\n" + string($7) + "\nreturn " + string($2) + "=" + string($11);
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s);
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << $2 << "\n\n";
        }
    ;

    
b_for_funs:
    // Regula pentru concatenarea instructiunilor dintr-un bloc de functii
    b_for_fun b_for_funs { $$ = strdup((string($1) + "\n" + string($2)).c_str()); }
    |
    // Regula pentru o singura instructiune dintr-un bloc de functii
    b_for_fun { $$ = $1; }
    ;

b_for_fun:
    // Regula pentru asignare
    assgns { $$ = $1; }
    |
    // Regula pentru scanf (citire de la intrare)
    scnf { $$ = $1; }
    |
    // Regula pentru printf (scriere la iesire)
    prtf { $$ = $1; }
    |
    // Regula pentru structura de control if-else
    ifelse {
        string s = string($1);
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n"));
        // Inlocuieste "ELSEIF" urmat de tab cu "ALTFELIF"
        ReplaceAllOccurrences(s, string("\nELSEIF"), string("\nALTFELIF"));
        // Inlocuieste "ELSE" urmat de tab cu "ALTFEL"
        ReplaceAllOccurrences(s, string("\n\tELSE"), string("\nALTFEL"));
        // Elimina tab-urile care preced newline-urile
       // ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s); 
        if (s[0] == 'D') {
            // Adauga "SFARSIT DACA" la sfarsitul instructiunii daca incepe cu 'D'
            string a = "\nSFARSIT DACA";
            $$ = strdup((s + a).c_str());
        } else {
            $$ = strdup(s.c_str());
        }
    }
    |
    // Regula pentru bucla for
    forLoop { $$ = $1; }
    |
    // Regula pentru bucla while
    whileLoop { $$ = $1; }
    |
    // Regula pentru bucla do-while
    doWhile { $$ = $1; }
    ;


    
typ_f:
    // Regula pentru tipurile de date returnate de functii
    VOID | DOUBLERESERVE | FLOATRESERVE | CHARRESERVE | INTRESERVE
    ;
    
parameter:
    // Regula pentru parametrii unei functii, poate fi gol (VOID) sau o lista de asignari
    VOID { $$ = strdup(""); }
    |
    assgns
    ;

assgns:
    // Regula pentru o lista de asignari, concatenand fiecare asignare cu newline
    assgns assgn { $$ = strdup((string($1) + "\n" + string($2)).c_str()); }
    |
    // Regula pentru o singura asignare
    assgn { $$ = $1; }
    ;
    
assgn:
    // Regula pentru o asignare cu declaratie de tip si corp
    assgn_type decl_body SEMICOLON { $$ = $2; }
    |
    // Regula pentru o asignare cu declaratie de tip si identificator
    assgn_type IDENT { $$ = $2; }
    |
    // Regula pentru o asignare cu declaratie de tip, identificator si alta asignare
    assgn_type IDENT COMMA assgn { $$ = strdup((string($2) + " " + string($4)).c_str()); }
    |
    // Regula pentru o asignare cu declaratie de tip, identificator, virgula, corp si punct si virgula
    assgn_type IDENT COMMA decl_body SEMICOLON { $$ = strdup((string($4)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o valoare intreaga
    IDENT EQ INTEGER SEMICOLON { $$ = strdup((string($1) + "=" + to_string($3)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o valoare float
    IDENT EQ FLOATVAL SEMICOLON { $$ = strdup((string($1) + "=" + to_string($3)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu un caracter
    IDENT EQ CHARVAL SEMICOLON { $$ = strdup((string($1) + "=" + string($3)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de adunare de identificatori
    IDENT EQ IDENT PLUS IDENT SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + "+" + string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de adunare de identificator si valoare intreaga
    IDENT EQ IDENT PLUS INTEGER SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + "+" + to_string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de inmultire de identificatori
    IDENT EQ IDENT MULTIPLICATION IDENT SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + " mul " + string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de inmultire de identificator si valoare intreaga
    IDENT EQ IDENT MULTIPLICATION INTEGER SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + " mul " + to_string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de scadere de identificatori
    IDENT EQ IDENT MINUS IDENT SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + "-" + string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de scadere de identificator si valoare intreaga
    IDENT EQ IDENT MINUS INTEGER SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + "-" + to_string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de impartire de identificatori
    IDENT EQ IDENT DIVIDE IDENT SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + " div " + string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de impartire de identificator si valoare intreaga
    IDENT EQ IDENT DIVIDE INTEGER SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + " div " + to_string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de mod de identificatori
    IDENT EQ IDENT MODULO IDENT SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + " mod " + string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o expresie de mod de identificator si valoare intreaga
    IDENT EQ IDENT MODULO INTEGER SEMICOLON { $$ = strdup((string($1) + "=" + string($3) + " mod " + to_string($5)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu un apel de functie
    IDENT EQ call SEMICOLON { $$ = strdup((string($1) + "=" + string($3)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o operatie de adunare si asignare
    IDENT PLUSEQ INTEGER SEMICOLON { $$ = strdup((string($1) + "+=" + to_string($3)).c_str()); }
    |
    // Regula pentru o asignare de identificator cu o operatie de scadere si asignare
    IDENT MINUSEQ INTEGER SEMICOLON { $$ = strdup((string($1) + "-=" + to_string($3)).c_str()); }
    ;

assgn_type:
    // Regula pentru tipurile de date pentru asignari
    DOUBLERESERVE | FLOATRESERVE | CHARRESERVE | INTRESERVE
    ;

    
decl_body:
    // Regula pentru asignarea unui identificator cu o valoare intreaga
    IDENT EQ INTEGER { $$ = strdup((string($1) + "=" + to_string($3)).c_str()); }
    |
    // Regula pentru asignarea unui identificator cu o valoare float
    IDENT EQ FLOATVAL { $$ = strdup((string($1) + "=" + to_string($3)).c_str()); }
    |
    // Regula pentru asignarea unui identificator cu un caracter
    IDENT EQ CHARVAL { $$ = strdup((string($1) + "=" + string($3)).c_str()); }
    |
    // Regula pentru asignarea unui identificator cu o valoare intreaga, urmata de alta asignare
    IDENT EQ INTEGER COMMA decl_body { $$ = strdup((string($1) + "=" + to_string($3) + "\n" + string($5)).c_str()); }
    |
    // Regula pentru asignarea unui identificator cu o valoare float, urmata de alta asignare
    IDENT EQ FLOATVAL COMMA decl_body { $$ = strdup((string($1) + "=" + to_string($3) + "\n" + string($5)).c_str()); }
    |
    // Regula pentru asignarea unui identificator cu un caracter, urmata de alta asignare
    IDENT EQ CHARVAL COMMA decl_body { $$ = strdup((string($1) + "=" + string($3) + "\n" + string($5)).c_str()); }
    |
    // Regula pentru asignarea unui identificator cu alt identificator, urmata de alta asignare
    IDENT EQ IDENT COMMA decl_body { $$ = strdup((string($1) + "=" + string($3) + "\n" + string($5)).c_str()); }
    |
    // Regula pentru asignarea unui identificator cu alt identificator
    IDENT EQ IDENT { $$ = strdup((string($1) + "=" + string($3)).c_str()); }
    |
    // Regula pentru un identificator fara asignare (declaratie goala)
    IDENT { $$ = strdup(""); }
    ;

ifelse:
    // Regula pentru structura if cu o conditie si un bloc de functii
    IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL {
        string s = string("DACA") + " " + string($3) + " " + string($4) + " " + string($5) + " ATUNCI" + "\n" + string($8);
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        $$ = strdup(s.c_str());
    }
    |
    // Regula pentru structura if cu o conditie si bloc gol
    IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL CLOSECURL {
        string s=(string("DACA ") + string($3) + " " + string($4) + " " + string($5) + string(" ATUNCI")).c_str();
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        $$ = strdup(s.c_str());
        
    }
    |
    // Regula pentru structura else if cu o conditie si un bloc de functii
    ELSE IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL {
       string s=(string("\r\t\t\tALTFEL DACA ") + string($4) + " " + string($5) + " " + string($6) + " ATUNCI" + "\n" + string($9)).c_str();
        $$ = strdup(s.c_str());
    }
    |
    // Regula pentru structura else if cu o conditie si bloc gol
    ELSE IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL CLOSECURL {
        string s=(string("\r\t\t\tALTFEL DACA ") + string($4) + " " + string($5) + " " + string($6) + string(" ATUNCI")).c_str();
        $$ = strdup(s.c_str());
    }
    |
    // Regula pentru structura else cu un bloc de functii
    ELSE OPENCURL b_for_funs CLOSECURL {
        string s=(string("\r\t\t\tALTFEL ") + string($3)).c_str();
        $$ = strdup(s.c_str());
    }
    |
    // Regula pentru structura else cu bloc gol
    ELSE OPENCURL CLOSECURL {
        string s=(string("\r\t\t\tALTFEL ") + string("ATUNCI")).c_str();
        $$ = strdup(s.c_str());
    }
    |
    // Regula pentru structura if-else if cu un bloc de functii si un alt if-else
    IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL ifelse {
        string s = string("DACA") + " " + string($3) + " " + string($4) + " " + string($5) + " ATUNCI" + "\n" + string($8) + "\n" + string($10);
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        $$ = strdup(s.c_str());
    }
    |
    // Regula pentru structura else if cu un bloc de functii si un alt if-else
    ELSE IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL ifelse {
        string s =(string("\r\t\t\tALTFEL DACA") + " " + string($4) + " " + string($5) + " " + string($6) + " ATUNCI" + "\n" + string($9) + "\n" + string($11)).c_str();
        $$ = strdup(s.c_str());
        
    }
    ;


forLoop:
    // Regula pentru bucla for cu variabile de inceput si sfarsit specificate prin valori intregi si un bloc de functii
    FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype INTEGER SEMICOLON IDENT incordec CLPARENTH OPENCURL b_for_funs CLOSECURL {
        string a = "PENTRU " + string($3) + " ← " + to_string($5) + ", " + to_string($9) + " EXECUTA\n\t";
        string b = $15;
        ReplaceAllOccurrences(b, string("\n"), string("\n\t"));
        string c = "\nSFARSIT PENTRU";
        $$ = strdup((a + b + c).c_str());
    }
    |
    // Regula pentru bucla for cu variabile de inceput specificate prin valori intregi si sfarsit specificat prin identificator, si un bloc de functii
    FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype IDENT SEMICOLON IDENT incordec CLPARENTH OPENCURL b_for_funs CLOSECURL {
        string a = "PENTRU " + string($3) + " ← " + to_string($5) + ", " + string($9) + " EXECUTA\n\t";
        string b = $15;
        ReplaceAllOccurrences(b, string("\n"), string("\n\t"));
        string c = "\nSFARSIT PENTRU";
        $$ = strdup((a + b + c).c_str());
    }
    |
    // Regula pentru bucla for cu variabile de inceput si sfarsit specificate prin valori intregi si bloc gol
    FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype INTEGER SEMICOLON IDENT incordec CLPARENTH OPENCURL CLOSECURL {
        $$ = strdup(("PENTRU " + string($3) + " ← " + to_string($5) + ", " + to_string($9) + " EXECUTA\n\t").c_str());
    }
    |
    // Regula pentru bucla for cu variabile de inceput specificate prin valori intregi si sfarsit specificat prin identificator, si bloc gol
    FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype IDENT SEMICOLON IDENT incordec CLPARENTH OPENCURL CLOSECURL {
        $$ = strdup(("PENTRU " + string($3) + " ← " + to_string($5) + ", " + string($9) + " EXECUTA\n\t").c_str());
    }
    ;

whileLoop:
    // Regula pentru bucla while cu o conditie si un bloc de functii
    WHILE OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL {
        string s = string("CAT TIMP ") + string($3) + string($4) + string($5) + "\n" + string($8) + "\n\r\tSFARSIT CAT TIMP";
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        $$ = strdup(s.c_str());
    }
    |
    // Regula pentru bucla while cu o conditie si bloc gol
    WHILE OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL CLOSECURL {
        $$ = strdup((string("CAT TIMP ") + string($3) + string($4) + string($5) + "\b\nSFARSIT CAT TIMP").c_str());
    }
    ;

doWhile:
    // Regula pentru bucla do-while cu un bloc de functii si o conditie
    DO OPENCURL b_for_funs CLOSECURL WHILE OPPARENTH IDENT comparetype identOrInt CLPARENTH SEMICOLON {
        string s = string("REPETA\n") + string($3) + "\n\r\t\tCAT TIMP " + string($7) + string($8) + string($9) + "\n\r\t\tSFARSIT REPETA";
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        $$ = strdup(s.c_str());
    }
    ;

incordec:
    // Regula pentru operatorul de incrementare
    INCREMENT { $$ = strdup("+"); }
    |
    // Regula pentru operatorul de decrementare
    DECREMENT { $$ = strdup("-"); }
    ;

comparetype:
    // Regula pentru operatorul de comparatie "mai mare"
    GREATER { $$ = strdup((string($1)).c_str()); }
    |
    // Regula pentru operatorul de comparatie "egal"
    EQEQ { $$ = strdup((string($1)).c_str()); }
    |
    // Regula pentru operatorul de comparatie "mai mic"
    LESS { $$ = strdup((string($1)).c_str()); }
    |
    // Regula pentru operatorul de comparatie "mai mare sau egal"
    GREATEREQ { $$ = strdup((string($1)).c_str()); }
    |
    // Regula pentru operatorul de comparatie "mai mic sau egal"
    LESSEQ { $$ = strdup((string($1)).c_str()); }
    ;

identOrInt:
    // Regula pentru un identificator
    IDENT { $$ = strdup((string($1)).c_str()); }
    |
    // Regula pentru o valoare intreaga
    INTEGER { $$ = strdup(to_string($1).c_str()); }
    ;
 
call:
    // Regula pentru un apel de functie cu argumente
    IDENT OPPARENTH callBody CLPARENTH { $$ = strdup((string($1) + " " + string($3)).c_str()); }
    |
    // Regula pentru un apel de functie fara argumente
    IDENT OPPARENTH CLPARENTH { $$ = $1; }
    ;
    
callBody:
    // Regula pentru un singur argument in apelul de functie
    IDENT { $$ = strdup((string($1)).c_str()); }
    |
    // Regula pentru mai multe argumente in apelul de functie
    IDENT COMMA callBody { $$ = strdup((string($1) + " " + string($3)).c_str()); }
    ;

prtf:
    // Regula pentru functia de afisare (printf) cu un identificator
    PRTF OPPARENTH QUOTES COMMA IDENT CLPARENTH SEMICOLON { $$ = strdup(("AFISEAZA " + string($5)).c_str()); }
    ;

scnf:
    // Regula pentru functia de citire (scanf) cu un identificator
    SCNF OPPARENTH QUOTES COMMA AND IDENT CLPARENTH SEMICOLON { $$ = strdup(("CITESTE " + string($6)).c_str()); }
    ;

%%

void yyerror(const char* s){
    cout<<"eroare: "<<s<<endl;
}

int yywrap(){
    return 1;
}

int main(int argc, char *argv[])
{
    yyin=fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
    return 0;
}

