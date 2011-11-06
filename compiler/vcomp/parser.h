//-------------------
// Moteur 3d
// version WIN32 et POCKETPC
// Sylvain Huet
// Premiere version : 03/09/2002
// Derniere mise a jour : 05/10/2002
//



#ifndef _PARSER_
#define _PARSER_

#define MAXParser 1024

class FileSystem;
class File;
class Terminal;
class Memory;
class Parser
{
private :
	Terminal* term;
	char* srcname;	// nom de la source
	char* src;	// buffer source
	int index;	// index de lecture

	char savedchar;	// caract�re sauvegard� (momentan�ment remplac� par \0)
	int indexsavedchar; //index du caract�re sauvegard�

	int again;   // token a relire
	int lign;       // ligne courante
	int offligne;   // offset caractere debut ligne

	int lign0;      // ligne courante (DERNIER TOKEN LU)
	int offligne0;  // offset caractere debut ligne (DERNIER TOKEN LU)
	int offchar0;   // offset caractere courant (DERNIER TOKEN LU)


	void savechar(int i);
	void restorechar();
	void againchar();
	int nextchar();
	int gettoken(int filter);

public :
	char* token;
	Parser(Terminal* t,FileSystem* fs,char *filename);
	Parser(Terminal* t,char *buffer);
	~Parser();

	char* next(int filter);
	void giveback();

	void echoposition();

	int parsekeyword(char* keyword);
	int parsekeyword(char* keyword,int filter);
	int getstring(Memory* m,char separator);
};




// test de lettre
int isletter(int c);
// test de chiffre decimal
int isnum(int c);
// test de lettre
int ishex(int c);

// test de lettre ou de chiffre
int isletnum(int c);

// test si un mot est un label (une lettre puis des lettres ou des chiffres)
int islabel(char* src);
// test si un mot est un nombre d�cimal (que des chiffres)
int isdecimal(char* src);
// test si un mot est un nombre hexad�cimal (que des chiffres)
int ishexadecimal(char* src);
// test si un mot est un flottant (que des chiffres avec un point apr�s la premi�re position)
int isfloat(char* src);

// retourne le code ascii correspondant � un chiffre hexad�cimal
int ctoh(int c);
// retourne le chiffre correspondant � un code ascii hexad�cimal
int htoc(int c);

// lecture d'une cha�ne d�cimale (s'arr�te au premier caract�re incorrect)
int mtl_atoi(char* src);
// lecture d'une cha�ne hexad�cimale (s'arr�te au premier caract�re incorrect)
int mtl_htoi(char* src);
// lecture d'une cha�ne flottant (s'arr�te au premier caract�re incorrect)
mtl_float mtl_atof(char* src);


#endif
