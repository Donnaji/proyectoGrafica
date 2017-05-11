//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void prisma3(float altura, float largo, float profundidad, GLuint text);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo


	void dodecaedro (GLuint text,GLuint text1);

	//Casa
	void pared_int (float altura, float largo, float profundidad, GLuint text1,GLuint text2,GLuint text3);
	void pared_ext (float altura, float largo, float profundidad, GLuint text1);
	void pared (float altura, float largo, float profundidad, GLuint text1,GLuint text2);
	void techo (float altura, float largo, float profundidad, GLuint text,GLuint text1);
	void piso (float altura, float largo, float profundidad, GLuint text1);

	//void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text );
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);

	void tecla (float altura, float largo, float profundidad, GLuint text);

};
