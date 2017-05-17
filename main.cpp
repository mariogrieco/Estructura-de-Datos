#include "iostream"
#include "stdlib.h"
#include "string.h"
#include "string"
#include "fstream"

using namespace std;

#include "Helpers.h"


int main(int argc, char const *argv[])
{	
	List<Creator> data;
	Creator a(2);
	Creator b(1);
	Creator c(33);

	data.insert(a,&Creator::getEdad,false);
	data.insert(c,&Creator::getEdad,false);
	data.insert(b,&Creator::getEdad,false);
	data.view(&Creator::getEdad);
	
	cout << endl;
	// cout << data.indexOf(*(new Creator(33)),&Creator::getEdad) << '\n';

	data.get(1)->setEdad(100);

	cout << data.get(1)->getEdad() << endl;
}
/*

Nombres	Descripción
memcpy	copia n bytes entre dos áreas de memoria que no deben solaparse
memmove	copia n bytes entre dos áreas de memoria; al contrario que memcpy las áreas pueden solaparse
memchr	busca un valor a partir de una dirección de memoria dada y devuelve un puntero a la primera ocurrencia del valor buscado o NULL si no se encuentra
memcmp	compara los n primeros caracteres de dos áreas de memoria
memset	sobre escribe un área de memoria con un patrón de bytes dado
strcat	añade una cadena al final de otra
strncat	añade los n primeros caracteres de una cadena al final de otra
strchr	localiza un carácter en una cadena, buscando desde el principio
strrchr	localiza un carácter en una cadena, buscando desde el final
strcmp	compara dos cadenas alfabéticamente ('a'!='A')
strncmp	compara los n primeros caracteres de dos cadenas numéricamente ('a'!='A')
strcoll	compara dos cadenas según la colación actual ('a'=='A')
strcpy	copia una cadena en otra
strncpy	copia los n primeros caracteres de una cadena en otra
strerror	devuelve la cadena con el mensaje de error correspondiente al número de error dado
strlen	devuelve la longitud de una cadena
strspn	devuelve la posición del primer carácter de una cadena que no coincide con ninguno de los caracteres de otra cadena dada
strcspn	devuelve la posición del primer carácter que coincide con alguno de los caracteres de otra cadena dada
strpbrk	encuentra la primera ocurrencia de alguno de los caracteres de una cadena dada en otra
strstr	busca una cadena dentro de otra
strtok	parte una cadena en una secuencia de tokens
strxfrm	transforma una cadena en su forma de colación (??)
strrev	invierte una cadena
*/