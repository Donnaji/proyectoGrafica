//..................................integrantes...................................//
//............................Miranda Castro Ana Karen........................//
//.............................Ismene DOnaji Torres Camacho ...........................//
//...............................................................................//


//#include <gl/gl.h>     // The GL Header File
//#include <windows.h>	//Solo para Windows
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>		// Descomentar para Linux
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>		// Solo para Windows

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

static GLuint ciudad_display_list;	//Display List for the Monito

float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;
float giroMonito = 0;
float rotMusIzq = 0;
float rotBraIzq = 0;
float rotBraIzqEn = 0;
float rotBraDer = 0;
float rotBraDerEn = 0;
float rotV = 0.0;
float rotD = 0.0;
float MovJ = 0.0;
boolean actJ=FALSE;
boolean actJ1=TRUE;


//Carga de Figuras
#define MAX_FRAMES 10
int i_max_steps = 25;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotMusIzq;
	float rotMusIzqInc;
	float rotBraIzq;
	float rotBraIzqInc;
	float rotBraIzqEn;
	float rotBraIzqEnInc;
	float rotBraDer;
	float rotBraDerInc;
	float rotBraDerEn;
	float rotBraDerEnInc;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;


int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

//luces

GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values negro
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values blanco
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values blanco
bool	light = false;

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CTexture textMesa;
CTexture textPata;
CTexture textWall;
CTexture textSilla;
CTexture textTecho;
CTexture textMarble;
CTexture textPiso;
CTexture textGlassWasser;
CTexture textBarrote;
CTexture textCuadro1;
CTexture textMarco;
CTexture textLibroCG;
CTexture textLibrolit;
CTexture textLibrolit1;
CTexture textPB;
CTexture textPuerta;
CTexture textPuerta_princ;
CTexture textMarco_1;
CTexture textMarco_2;
CTexture textMarco_3;
CTexture textGrass;
CTexture textSky;
CTexture textLibrero;


CTexture textAlmohada;
CTexture textColcha;
CTexture textMaderaBuro;
CTexture textMaderaCama;
CTexture textLampara;
CTexture textLaptop;
CTexture textPantalla;
CTexture textTeclado;
CTexture textTouchPad;
CTexture textGW;


CFiguras tablaMesa;
CFiguras pata1Mesa;
CFiguras pata2Mesa;
CFiguras pata3Mesa;
CFiguras pata4Mesa;
CFiguras asientoSilla;
CFiguras respaldoSilla1;
CFiguras respaldoSilla2;
CFiguras respaldoSilla3;
CFiguras respaldoSilla4;
CFiguras techoCasa;
CFiguras pisoCasa;
CFiguras cubo;
CFiguras sky;


CFiguras cama;
CFiguras buro;
CFiguras cono;
CFiguras lampara;
CFiguras laptop;

float abrirPuerta = 0;


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

//Sillas
CTexture Metal;
CTexture Forro;
CTexture Forro1;
CTexture Forro2;
CTexture Plastico;
CTexture Tapiz;
CTexture jenga;
CModel Mesa;
CModel sillon;
CModel sillon2;
CModel mueble;
CModel pin;
CTexture Ladrillo_Ch;
CTexture exterior;
CTexture interior;
CTexture Ladrillo_sqrt;
CTexture fire_ch;
CTexture psp;
CTexture Dodecaedro;
CTexture sillon3; 





//...............................Silla uno
void SillaNew1()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();
		
		glPushMatrix();//Asiento
			glTranslatef(25, 2.0, -15);
			glScalef(1, 0.25, 1);

			fig7.prisma2(Forro2.GLindex,Forro2.GLindex);
		glPopMatrix();

		glPushMatrix();//Respaldo
			glTranslatef(25, 2.375, -15.375);
			glScalef(1, 1,0.25);
			fig7.prisma2(Forro2.GLindex,Forro2.GLindex);
		glPopMatrix();

		glPushMatrix();//PataIzq
			glTranslatef(24.625, 1.625, -15);
			glScalef(0.1, 0.5, 1);
			fig7.prisma2(Metal.GLindex,Metal.GLindex);
		glPopMatrix();

		glPushMatrix();//PataDer
			glTranslatef(25.375, 1.625, -15);
			glScalef(0.1, 0.5, 1);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();

		glPushMatrix();//AgarraderaDerechaVertical
			glTranslatef(25.45, 2.25, -14.6);
			glScalef(0.05, 0.4, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();

		glPushMatrix();//AgarraderaDerechaHorizontal
			glTranslatef(24.53, 2.45, -14.925);
			glScalef(0.05, 0.05, 0.7);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();

		glPushMatrix();//AgarraderaIzquierdaVertical
			glTranslatef(24.53, 2.25, -14.6);
			glScalef(0.05, 0.4, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();

		glPushMatrix();//AgarraderaDerechaHorizontal
			glTranslatef(25.45, 2.45, -14.925);
			glScalef(0.05, 0.05, 0.7);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		//glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}
//....................................................Silla dos
void SillaNew2()
{
	glPushMatrix();
		
		glPushMatrix();//Asiento
			glTranslatef(29, 2.0, -15);
			glScalef(1, 0.1, 1);
			fig7.prisma2(Forro1.GLindex ,Forro1.GLindex);
		glPopMatrix();

		glPushMatrix();//PataFrontRight
			glTranslatef(29.45, 1.55, -14.6);
			glRotatef(25,0,0,1);
			glRotatef(-15,1,0,0);
			glScalef(0.05, 1, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//PataFrontLeft
			glTranslatef(28.55, 1.55, -14.6);
			glRotatef(-25,0,0,1);
			glRotatef(-15,1,0,0);
			glScalef(0.05, 1, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//PataBackRight
			glTranslatef(29.45, 1.55, -15.4);
			glRotatef(25,0,0,1);
			glRotatef(15,1,0,0);
			glScalef(0.05, 1, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//PataBackLeft
			glTranslatef(28.55, 1.55, -15.4);
			glRotatef(-25,0,0,1);
			glRotatef(15,1,0,0);
			glScalef(0.05, 1, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Respaldo
			glTranslatef(29.55, 2.5, -15.6);
			glRotatef(-15,0,0,1);
			glRotatef(-15,1,0,0);
			glScalef(0.05, 1, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Respaldo
			glTranslatef(28.45, 2.5, -15.6);
			glRotatef(15,0,0,1);
			glRotatef(-15,1,0,0);
			glScalef(0.05, 1, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños1
			glTranslatef(29, 2.9, -15.71);
			//glRotatef(15,0,0,1);
			//glRotatef(-15,1,0,0);
			glScalef(1.3, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños2
			glTranslatef(29, 2.8, -15.69);
			//glRotatef(15,0,0,1);
			//glRotatef(-15,1,0,0);
			glScalef(1.3, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños3
			glTranslatef(29, 2.7, -15.66);
			//glRotatef(15,0,0,1);
			//glRotatef(-15,1,0,0);
			glScalef(1.2, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños4
			glTranslatef(29, 2.6, -15.63);
			glScalef(1.15, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños5
			glTranslatef(29, 2.5, -15.6);
			glScalef(1.1, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños6
			glTranslatef(29, 2.4, -15.57);;
			glScalef(1, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños7
			glTranslatef(29, 2.3, -15.55);
			glScalef(0.95, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños8
			glTranslatef(29, 2.2, -15.52);
			glScalef(0.95, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
		glPushMatrix();//Travesaños9
			glTranslatef(29, 2.1, -15.49);
			glScalef(0.9, 0.05, 0.05);
			fig7.prisma2(Metal.GLindex ,Metal.GLindex);
		glPopMatrix();
	glPopMatrix();

}

void silla()
{
	glPushMatrix();
	glPushMatrix();
	glTranslated(0, 0.0, 0.60);
	glScalef(2, 0.3, 2);
	fig7.prisma2(textSilla.GLindex, textSilla.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.7, 1.5);
	glScalef(2, 5.5, -0.2);
	fig7.prisma2(textSilla.GLindex, textSilla.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.8, -1.1, -0.23);
	glScalef(0.3, 2.4, 0.3);
	fig7.prisma2(textSilla.GLindex, textSilla.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.8, -1.1, -0.23);
	glScalef(0.3, 2.4, 0.3);
	fig7.prisma2(textSilla.GLindex, textSilla.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.8, -1.1, 1.4);
	glScalef(0.3, 2.4, 0.3);
	fig7.prisma2(textSilla.GLindex, textSilla.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.8, -1.1, 1.4);
	glScalef(0.3, 2.4, 0.3);
	fig7.prisma2(textSilla.GLindex, textSilla.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2.7, 1.3);
	glScalef(1.5, 4, -0.2);
	fig7.prisma2(sillon3.GLindex, sillon3.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.3, 0.60);
	glScalef(1.5, 0.2, 1.5);
	fig7.prisma2(sillon3.GLindex, sillon3.GLindex);
	glPopMatrix();


	glPopMatrix();


}

void Jenga()
{
	glPushMatrix();


glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 6.2, -25);
	glTranslatef(0, MovJ, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 6.2, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 6.2, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 6.0, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 6.0, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 6.0, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.8, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.8, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.8, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//--------------------------------------------------------
	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.6, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.6, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.6, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.4, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 5.4, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 5.4, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.2, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.2, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.2, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//--------------------------------------------------------------------------
	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.0, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.0, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 5.0, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.8, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 4.8, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 1.8, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.6, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.6, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.6, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//------------------------------------------------------------

	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.4, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.4, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.4, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.2, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 4.2, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 4.2, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.0, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.0, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 4.0, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//-------------------------------------------------------------
	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.8, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.8, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.8, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.6, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 3.6, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 3.6, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.4, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.4, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.4, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.2, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.2, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.2, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 3.0, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 3.0, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 3.0, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.8, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.8, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.8, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//--------------------------------------------------------
	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.6, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.6, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.6, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.4, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 2.4, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 2.4, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.2, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.2, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.2, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//--------------------------------------------------------------------------
	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.0, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.0, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 2.0, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.8, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 1.8, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 1.8, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.6, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.6, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.6, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//------------------------------------------------------------

	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.4, -25);
	
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29,1.4, -25.33);
	glTranslatef(rotBraDerEn, 0, 0);
	glTranslatef(0, rotBraDer, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.4, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.2, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 1.2, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 1.2, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.0, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.0, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 1.0, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//-------------------------------------------------------------
	glPushMatrix(); //Creamos jenga pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 0.8, -25);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 0.8, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 0.8, -24.67);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 0.6, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29.33, 0.6, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(28.67, 0.6, -25);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga  pieza1
	glDisable(GL_LIGHTING);
	glTranslatef(29, 0.4, -25);
	//glRotatef(90, 0, 1, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(Forro.GLindex,Forro.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza2
	glDisable(GL_LIGHTING);
	glTranslatef(29, 0.4, -25.33);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creamos jenga pieza3
	glDisable(GL_LIGHTING);
	glTranslatef(29, 0.4, -24.67);
	//glTranslatef(rotBraDer, 0, 0);
	glScalef(1, 0.2, 0.33);
	fig7.prisma2(jenga.GLindex,jenga.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

}

void ciudad ()
{

		glPushMatrix(); //Camino1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Camino2
			glTranslatef(-23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,7.0);
			glRotatef(90,1,0,0);
			glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,-7.0);
			glRotatef(90,1,0,0);
			//glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

			

}

void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
		glScalef(0.5, 0.5, 0.5);
		fig7.prisma(2.0 ,2.0 ,1 ,text2.GLindex,0,0,0,0,0);

		glPushMatrix();//Cuello
			glTranslatef(0, 1.0, 0.0);
			fig7.cilindro(0.25, 0.25, 15, 0);
			glPushMatrix();//Cabeza
				glTranslatef(0, 1.0, 0);
				fig7.esfera(0.75, 15, 15, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo derecho-->
			glTranslatef(1.25, 0.65, 0);
			fig7.esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(0.25, 0, 0);
				glRotatef(rotBraDerEn, 0, 1, 0);
				glRotatef(rotBraDer, 0, 0, 1);
				glRotatef(25, 1, 0, 0);
				glTranslatef(0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, 0,0,0,0,0,0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo izquierdo <--
			glTranslatef(-1.25, 0.65, 0);
			fig7.esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(-0.25, 0, 0);
				glRotatef(rotBraIzqEn, 0, 1, 0);
				glRotatef(rotBraIzq, 0, 0, 1);
				glRotatef(25, 1, 0, 0); 
				glTranslatef(-0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, 0,0,0,0,0,0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//Cintura
			glColor3f(0, 0, 1);
			glTranslatef(0, -1.5, 0);
			fig7.prisma(1, 2, 1, 0,0,0,0,0,0);

			glPushMatrix(); //Pie Derecho -->
				glTranslatef(0.75, -0.5, 0);
				glRotatef(-15, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, 0,0,0,0,0,0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, 0,0,0,0,0,0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, 0,0,0,0,0,0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix(); //Pie Izquierdo -->
				glTranslatef(-0.75, -0.5, 0);
				glRotatef(rotMusIzq, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, 0,0,0,0,0,0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15+rotRodIzq, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, 0,0,0,0,0,0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, 0,0,0,0,0,0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


		glPopMatrix();


		glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}

//NEW CASA//////////////////////////////////////

void VentiladorT()
{
	//glNewList(1, GL_COMPILE)
		glPushMatrix();
			glRotatef(rotV, 0, 1, 0);

			glPushMatrix();//Centro
				glColor3f(0,0,0);
				glTranslatef(0.0, 0.0, 0);
				fig7.esfera(0.75, 15, 15, 0);
			glPopMatrix();
			
			glPushMatrix();//Soporte
			glColor3f(0,0,0);
			glTranslatef(0.0, 0.0, 0.0);
			fig7.cilindro(0.15, 4.5, 15, 0);
			glPopMatrix();
			
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				glRotatef(22.5, 0, 1, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				glRotatef(45, 0, 1, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				glRotatef(67.5, 0, 1, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				glRotatef(90, 0, 1, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				glRotatef(112.5, 0, 1, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				glRotatef(135, 0, 1, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();//Helices
				glTranslatef(0.0, 0, 0);
				glRotatef(157.5, 0, 1, 0);
				fig7.prisma(0.1, 15, 0.75, 0,0,0,0,0,0);
			glPopMatrix();


		glPopMatrix();


		//glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}

void dibujaLaptop(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosBuro, GLfloat yPosBuro, GLfloat zPosBuro)
{
		glPushMatrix();		
			glScalef(xMadera, yMadera, zMadera); 
			glTranslatef(xPosBuro, yPosBuro, zPosBuro); //figura 
			//contorno
			glPushMatrix();
				glTranslatef(7.0,0.5,0.25);
				glScalef(14.0,1.0,0.5);
				 laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(7.0,11.5,0.25);
				glScalef(14.0,1.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();

 		glPushMatrix();
				glTranslatef(0.5,6.0,0.25);
				glScalef(1.0,10.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(13.5,6.0,0.25);
				glScalef(1.0,10.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();
 	glPushMatrix();
				glTranslatef(7.0,6.0,0.125);
				glScalef(12.0,10.0,0.25);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(7.0,6.0,0.375);
				glScalef(12.0,10.0,0.25);
				laptop.prisma(1.0,1.0,1.0, textPantalla.GLindex,0,0,0,0,0);
			glPopMatrix();

 		//teclado
			glPushMatrix();
				glTranslatef(7.0,-0.75,5.0);
				glScalef(14.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(7.0,-0.25,0.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	
 			glPushMatrix();
				glTranslatef(7.0,-0.25,6.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(2.5,-0.25,8.0);
				glScalef(5.0,0.5,2.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	
 		glPushMatrix();
				glTranslatef(11.5,-0.25,8.0);
				glScalef(5.0,0.5,2.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(7.0,-0.25,9.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	
 		glPushMatrix();
				glTranslatef(0.5,-0.25,5.0);
				glScalef(1.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(13.5,-0.25,5.0);
				glScalef(1.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex,0,0,0,0,0);
			glPopMatrix();	
 		//teclas
			glPushMatrix();
				glTranslatef(7.0,-0.25,3.5);
				glScalef(12.0,0.5,5.0);
				laptop.prisma(1.0,1.0,1.0, textTeclado.GLindex,0,0,0,0,0);
			glPopMatrix();	

			//touchpad
			glPushMatrix();
				glTranslatef(7.0,-0.25,8.0);
				glScalef(4.0,0.5,2.0);
				laptop.tecla(1.0,1.0,1.0, textTouchPad.GLindex);
			glPopMatrix();	
 		glPopMatrix();
}

void mesa(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosMesa, GLfloat yPosMesa, GLfloat zPosMesa){
	//mesa	
		//tabla
		glPushMatrix();
			glScalef(xMadera, yMadera, zMadera);
			glTranslatef(xPosMesa, yPosMesa, zPosMesa);
			glPushMatrix();
				glScalef(10,.5,5);
				tablaMesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex,0,0,0,0,0);
			//patas
			glPopMatrix();
			glPushMatrix();
				glTranslatef(4, -2.75, 2);
				glScalef( .5,5,.5);
				pata1Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex,0,0,0,0,0);
				glTranslatef(0, 0, -8);
				pata2Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex,0,0,0,0,0);
				glTranslatef(-16, 0, 0);
				pata3Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex,0,0,0,0,0);
				glTranslatef(0, 0, 8);
				pata4Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex,0,0,0,0,0);
			glPopMatrix();
		glPopMatrix();

		return;
}

void silla(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosSilla, GLfloat yPosSilla, GLfloat zPosSilla){
	float numBarrotes = -2.9;
	glPushMatrix();
		//posicion y tamaño
		glScalef(xMadera, yMadera, zMadera);
		glTranslatef(xPosSilla, yPosSilla, zPosSilla);
		//figura
		glPushMatrix();
			glScalef(3,.5,3);
			asientoSilla.prisma (1.0, 1.0, 1.0, textSilla.GLindex,0,0,0,0,0);//1
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.35, -3.25,-1.35);
			glScalef( .3,6,.3);
			pata1Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex,0,0,0,0,0);
			glTranslatef(-9.0, 0, 0);
			pata2Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex,0,0,0,0,0);
			glTranslatef(0, 0, 9);
			pata3Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex,0,0,0,0,0);
			glTranslatef(9, 0, 0);
			pata4Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex,0,0,0,0,0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.45, 4.25, -1.45);
			glScalef( 0.1,8.0,0.1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex,0,0,0,0,0);
			for(int numBar = 1; numBar <= 10; numBar++){
				glTranslatef(numBarrotes,0,0);
				respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex,0,0,0,0,0);
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,1,-1.45);
			glScalef( 2.3,0.1,0.1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex,0,0,0,0,0);
			//
			for(int numBar = 1; numBar <= 30; numBar++){
				glTranslatef(0,2,0);
				respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex,0,0,0,0,0);
			}
			glTranslatef(0,12,0);
			glScalef( 1.5,1,1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex,0,0,0,0,0);
		glPopMatrix();
	glPopMatrix();

	return;
}

void comedor(void){
	glPushMatrix();
			mesa(2,2,2,0,1,0);
	glPopMatrix();
	//SILLAS
	glPushMatrix();
		glTranslatef(0,0,-0.5);
		glRotatef(25, 0,1,0);
		glTranslatef(2,0,-0.5);
		silla(1,1,1,5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,-5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,0,-1,-4.5);
		glPopMatrix();
		//giramos con respecto Z
		glScalef(1,1,-1);
		glPushMatrix();				
		glPushMatrix();
			silla(1,1,1,5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,-5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,0,-1,-4.5);
		glPopMatrix();
	glPopMatrix();
		return;
}
void ropero(void){
			glPushMatrix();
				glTranslatef(-8,-20,50);
				fig5.prisma(50.0,1.0,30.0, textMesa.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,35);
				glRotatef(90,1,0,0);
				fig5.prisma(1.0,6.0,50.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,65);
				glRotatef(90,1,0,0);
				fig5.prisma(1.0,6.0,50.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,57.5);
				glRotatef(90,1,0,0);
				fig5.prisma(0.5,6.0,50.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,42.5);
				glRotatef(90,1,0,0);
				fig5.prisma(0.5,6.0,50.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-45,50);
				fig5.prisma(0.5,6.0,31.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,5,50);
				fig5.prisma(0.5,6.0,31.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,50);
				fig5.prisma(0.5,6.0,30.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-30,50);
				fig5.prisma(0.5,6.0,30.0, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-10,39);
				fig5.prisma(0.5,6.0,7.5, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-10,61);
				fig5.prisma(0.5,6.0,7.5, textSilla.GLindex,0,0,0,0,0);
			glPopMatrix();
}

void Chimenea(void){
			glPushMatrix();
				glTranslatef(82.8,6.6,-50);
				fig5.prisma(17.0,1.0,10.0, Ladrillo_Ch.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(82,0,-50);
				fig5.prisma(4.6,0.6,3.4, fire_ch.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(82,2.2,-50);
				glRotatef(90,1,0,0);
				glScalef(1,6,8);
				glDisable(GL_LIGHTING);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				fig5.prisma2(Ladrillo_sqrt.GLindex,Ladrillo_sqrt.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			
}

void Cascadafuente(void){
			glPushMatrix();
				glTranslatef(57.8,3.7,-13);
				fig5.prisma(10,35.0,1.0, textTeclado.GLindex,0,0,0,0,0);
			glPopMatrix();

}

void casa( void ){
//*****casa*****
	glPushMatrix(); //Creamos paredes
		glTranslatef(0,20,0);
		fig1.skybox2(60.0, 85.0, 85.0, interior.GLindex);
	glPopMatrix();
	glPushMatrix(); //Creamos paredes
		glTranslatef(0,20,0);
		fig1.skybox2(60.3, 85.3, 85.3, exterior.GLindex);
	glPopMatrix();
	glPushMatrix();//Tapiz
			glTranslatef(0.0, 20.0, 42.4);
			glRotatef(180,0,0,1);
			glScalef(85, 60, 0.1);
			fig7.prisma2(Tapiz.GLindex ,Tapiz.GLindex);
			
		glPopMatrix();
	glPushMatrix();
		glTranslatef(0,50,0);
		techoCasa.prisma(1,90,90, textTecho.GLindex,0,0,0,0,0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,-10,0);
		pisoCasa.prisma(1,85,85, textPiso.GLindex,0,0,0,0,0);
		//patio
		glTranslatef(0,-3,0);
		//pisoCasa.prisma(1,250,250, textGrass.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27.5,10,-42);
		pisoCasa.prisma(40,30,1, textPata.GLindex,0,0,0,0,0);
		glTranslatef(30,0,0);
		pisoCasa.prisma(40,30,1, textPata.GLindex,0,0,0,0,0);
		glTranslatef(15,0,0);
		pisoCasa.prisma(40,30,1, textPata.GLindex,0,0,0,0,0);
		glPushMatrix();
			glTranslatef(15.5,0,0);
			pisoCasa.prisma(40,1,1, textMarco_1.GLindex,0,0,0,0,0);
			glTranslatef(9,0,0);
			pisoCasa.prisma(40,1,1, textMarco_2.GLindex,0,0,0,0,0);
			glTranslatef(-4.5,18.5,0);
			pisoCasa.prisma(2.5,8,1, textMarco_3.GLindex,0,0,0,0,0);
		glPopMatrix();
		//puerta
		glTranslatef(15,-1,0);
		glRotatef(abrirPuerta, 0,1,0);
		glTranslatef(5,-0.4,0);//eran 20 en x
		pisoCasa.prisma(37,8,1, textPuerta_princ.GLindex,0,0,0,0,0);
	glPopMatrix();
			
	//ventana 1
	glPushMatrix();
		glTranslatef(-34.5,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex,0,0,0,0,0);
	glPopMatrix();
	// barrotes ventana
	glPushMatrix();
		glTranslatef(-42,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex,0,0,0,0,0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex,0,0,0,0,0);
	glPopMatrix();
	//ventana 2
	glPushMatrix();
		glTranslatef(-19,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex,0,0,0,0,0);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(-11,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex,0,0,0,0,0);
	glPopMatrix();
	//ventana 3
	glPushMatrix();
		glTranslatef(-3,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex,0,0,0,0,0);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(5,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex,0,0,0,0,0);
	glPopMatrix();
	//ventana 4
	glPushMatrix();
		glTranslatef(13,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex,0,0,0,0,0);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(19.8,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex,0,0,0,0,0);
	glPopMatrix();	
	//cierra ventana
	glPushMatrix();
		glTranslatef(31,38.5,-42);
		cubo.prisma(17,23,1, textPata.GLindex,0,0,0,0,0);
	glPopMatrix();
	return;
}

void cuadro(void){
	glPushMatrix();
		glTranslatef(0,0,0);
		cubo.prisma(5,0.1,10, textCuadro1.GLindex,0,0,0,0,0);
		//glTranslatef(0,0,-.05);
		//cubo.prisma(17,16,.05, textMarco.GLindex);
	glPopMatrix();
	return;
}
void poster(void){
	glPushMatrix();
		glTranslatef(0,0,0);
		cubo.prisma(5,0.07,5, psp.GLindex,0,0,0,0,0);
		//glTranslatef(0,0,-.05);
		//cubo.prisma(17,16,.05, textMarco.GLindex);
	glPopMatrix();
	return;
}
//****ROSE****
void dibujaCama (GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosCama, GLfloat yPosCama, GLfloat zPosCama)
{			
			glPushMatrix(); 
			glScalef(xMadera, yMadera, zMadera); //posicion y tamaño 
			glTranslatef(xPosCama, yPosCama, zPosCama); //figura 

			//dibujamos la cabecera
			glPushMatrix(); 
				glTranslatef(9.0,1.5,0.5);
				glScalef(18.0,3.0,1.0);  //Tamaño de cabecera
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,6.0,0.5);
				glScalef(1.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(4.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(14.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,6.0,0.5);
				glScalef(1.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,9.5,0.5);
				glScalef(18.0,1.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,5.0,0.5);
				glScalef(1.0,10.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();


			//dibujamos la base de la cama
			glPushMatrix(); 
				glTranslatef(0.5,1.0,11.0);
				glScalef(1.0,2.0,22.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,1.0,11.0);
				glScalef(1.0,2.0,22.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,1.0,21.5);
				glScalef(18.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();


			//colchon
			glPushMatrix(); 
				glTranslatef(9.0,3.5,11.0);
				glScalef(18.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,3.5,11.0);
				glScalef(1.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,3.5,11.0);
				glScalef(1.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex,0,0,0,0,0);
			glPopMatrix();

			//almohada izquierda
			glPushMatrix(); 
				glTranslatef(4.0,5.5,3.0);
				glScalef(8.0,1.0,4.0);
				cama.prisma(1.0,1.0,1.0, textAlmohada.GLindex,0,0,0,0,0);
			glPopMatrix();

			//almohada derecha
			glPushMatrix(); 
				glTranslatef(14.0,5.5,3.0);
				glScalef(8.0,1.0,4.0);
				cama.prisma(1.0,1.0,1.0, textAlmohada.GLindex,0,0,0,0,0);
			glPopMatrix();


			//enfrente
			glPushMatrix(); 
				glTranslatef(9.0,6.5,21.5);
				glScalef(16.0,1.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,2.5,21.5);
				glScalef(16.0,5.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,4.0,21.5);
				glScalef(1.0,8.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,4.0,21.5);
				glScalef(1.0,8.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();


			//patas
			glPushMatrix(); 
				glTranslatef(0.5,-1.0,21.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,-1.0,21.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,-1.0,0.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,-1.0,0.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex,0,0,0,0,0);
			glPopMatrix();
			glPopMatrix();
}

void dibujaBuro(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosBuro, GLfloat yPosBuro, GLfloat zPosBuro)
{
		glPushMatrix();		
			glScalef(xMadera, yMadera, zMadera); 
			glTranslatef(xPosBuro, yPosBuro, zPosBuro); //figura 
			//contorno
			glPushMatrix();
				glTranslatef(1.5,5.5,1.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,5.5,8.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,5.5,1.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,5.5,8.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,10.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,10.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,10.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();


			glPushMatrix();
				glTranslatef(8.0,6.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,6.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,6.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,2.5,1.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,2.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,2.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,2.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			//rellenos
			glPushMatrix();
				glTranslatef(13.5,6.5,5.0);
				glScalef(1.0,7.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(2.5,6.5,5.0);
				glScalef(1.0,7.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			//pared atras
			glPushMatrix();
				glTranslatef(8.0,6.5,1.5);
				glScalef(12.0,9.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();


			//base arriba
			glPushMatrix();
				glTranslatef(8.0,11.5,5.0);
				glScalef(16.0,1.0,10.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();


			//cajones
			glPushMatrix();
				glTranslatef(8.0,8.5,9.25);
				glScalef(12.0,3.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,4.5,9.25);
				glScalef(12.0,3.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,8.5,9.75);
				glScalef(2.0,1.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,4.5,9.75);
				glScalef(2.0,1.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex,0,0,0,0,0);
			glPopMatrix();
		glPopMatrix();
}

void book( GLuint textura3){
	glPushMatrix();
			cubo.prisma(1,1,1, textura3,0,0,0,0,0);
	glPopMatrix();
}
//END CASA////////////////////////////////////


GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	
	//glEnable(GL_TEXTURE_2D);
	glShadeModel (GL_SMOOTH);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	Metal.LoadTGA("ImagenesSillas/Metal.tga");
	Metal.BuildGLTexture();
	Metal.ReleaseImage();

	Forro.LoadTGA("ImagenesSillas/plastico1.tga");
	Forro.BuildGLTexture();
	Forro.ReleaseImage();

	Forro1.LoadTGA("ImagenesSillas/forro2.tga");
	Forro1.BuildGLTexture();
	Forro1.ReleaseImage();

	jenga.LoadTGA("ImagenesSillas/plastico2.tga");
	jenga.BuildGLTexture();
	jenga.ReleaseImage();

	Ladrillo_Ch.LoadTGA("Chimenea/Ladrillo.tga");
	Ladrillo_Ch.BuildGLTexture();
	Ladrillo_Ch.ReleaseImage();

	Ladrillo_sqrt.LoadTGA("Chimenea/stonewall.tga");
	Ladrillo_sqrt.BuildGLTexture();
	Ladrillo_sqrt.ReleaseImage();

	fire_ch.LoadTGA("Chimenea/firech.tga");
	fire_ch.BuildGLTexture();
	fire_ch.ReleaseImage();

	Tapiz.LoadTGA("casa/pared.tga");
	Tapiz.BuildGLTexture();
	Tapiz.ReleaseImage();

	exterior.LoadTGA("casa/exterior.tga");
	exterior.BuildGLTexture();
	exterior.ReleaseImage();

	interior.LoadTGA("casa/tapizado.tga");
	interior.BuildGLTexture();
	interior.ReleaseImage();

	textCuadro1.LoadBMP("casa/nintendo.bmp");
	textCuadro1.BuildGLTexture();
	textCuadro1.ReleaseImage();

	psp.LoadTGA("casa/psp.tga");
	psp.BuildGLTexture();
	psp.ReleaseImage();

	textLibroCG.LoadBMP("casa/codDaVinci.bmp");
	textLibroCG.BuildGLTexture();
	textLibroCG.ReleaseImage();

	textLibrolit.LoadBMP("casa/gamesofthrones.bmp");
	textLibrolit.BuildGLTexture();
	textLibrolit.ReleaseImage();

	textLibrolit1.LoadTGA("casa/hungergames.tga");
	textLibrolit1.BuildGLTexture();
	textLibrolit1.ReleaseImage();

	Forro2.LoadTGA("ImagenesSillas/pielsilla.tga");
	Forro2.BuildGLTexture();
	Forro2.ReleaseImage();

	Plastico.LoadTGA("ImagenesSillas/agua.tga");
	Plastico.BuildGLTexture();
	Plastico.ReleaseImage();

	
	sillon3.LoadBMP("sillon.bmp");
	sillon3.BuildGLTexture();
	sillon3.ReleaseImage();



	///////////////////////////////////////////
	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	
	//NEW////////////////////////////////////////////

	textMesa.LoadBMP("casa/wood_5.bmp");
	textMesa.BuildGLTexture();
	textMesa.ReleaseImage();

	textPata.LoadBMP("casa/brick_3.bmp");
	textPata.BuildGLTexture();
	textPata.ReleaseImage();

	textWall.LoadBMP("casa/brick_2.bmp");
	textWall.BuildGLTexture();
	textWall.ReleaseImage();

	textSilla.LoadBMP("casa/madera.bmp");
	textSilla.BuildGLTexture();
	textSilla.ReleaseImage();
	
	textTecho.LoadBMP("casa/brick_3.bmp");
	textTecho.BuildGLTexture();
	textTecho.ReleaseImage();

	textMarble.LoadBMP("casa/marble_2.bmp");
	textMarble.BuildGLTexture();
	textMarble.ReleaseImage();

	textPiso.LoadBMP("casa/floor-parquet.bmp");
	textPiso.BuildGLTexture();
	textPiso.ReleaseImage();

	textGlassWasser.LoadBMP("casa/glass_2.bmp");
	textGlassWasser.BuildGLTexture();
	textGlassWasser.ReleaseImage();

	textBarrote.LoadBMP("casa/brickwall.bmp");
	textBarrote.BuildGLTexture();
	textBarrote.ReleaseImage();


	//................................dodecaedro
	Dodecaedro.LoadTGA("12.tga");
	Dodecaedro.BuildGLTexture();
	Dodecaedro.ReleaseImage();

	textMarco.LoadBMP("casa/burned wood.bmp");
	textMarco.BuildGLTexture();
	textMarco.ReleaseImage();

	textPuerta.LoadBMP("casa/door_3.bmp");
	textPuerta.BuildGLTexture();
	textPuerta.ReleaseImage();

	textPuerta_princ.LoadBMP("casa/door_3_4_puerta.bmp");
	textPuerta_princ.BuildGLTexture();
	textPuerta_princ.ReleaseImage();

	textMarco_1.LoadBMP("casa/door_3_1_izq.bmp");
	textMarco_1.BuildGLTexture();
	textMarco_1.ReleaseImage();

	textMarco_2.LoadBMP("casa/door_3_2_der.bmp");
	textMarco_2.BuildGLTexture();
	textMarco_2.ReleaseImage();

	textMarco_3.LoadBMP("casa/door_3_3_cen.bmp");
	textMarco_3.BuildGLTexture();
	textMarco_3.ReleaseImage();

	textGrass.LoadBMP("casa/grass_2.bmp");
	textGrass.BuildGLTexture();
	textGrass.ReleaseImage();

	textSky.LoadBMP("casa/blue-sky-texture.bmp");
	textSky.BuildGLTexture();
	textSky.ReleaseImage();

	textLibrero.LoadBMP("casa/strata.bmp");
	textLibrero.BuildGLTexture();
	textLibrero.ReleaseImage();

	textGW.LoadBMP("casa/glass window.bmp");
	textGW.BuildGLTexture();
	textGW.ReleaseImage();
	
	//*****ROSE******
	textAlmohada.LoadBMP("casa/almohada.bmp");
	textAlmohada.BuildGLTexture();
	textAlmohada.ReleaseImage();

	textColcha.LoadBMP("casa/colcha.bmp");
	textColcha.BuildGLTexture();
	textColcha.ReleaseImage();

	textMaderaBuro.LoadBMP("casa/buro.bmp");
	textMaderaBuro.BuildGLTexture();
	textMaderaBuro.ReleaseImage();

	textMaderaCama.LoadBMP("casa/maderaCama.bmp");
	textMaderaCama.BuildGLTexture();
	textMaderaCama.ReleaseImage();

	textLampara.LoadBMP("casa/lampara.bmp");
	textLampara.BuildGLTexture();
	textLampara.ReleaseImage();

	textLaptop.LoadBMP("casa/laptop.bmp");
	textLaptop.BuildGLTexture();
	textLaptop.ReleaseImage();

	textPantalla.LoadBMP("casa/windows.bmp");
	textPantalla.BuildGLTexture();
	textPantalla.ReleaseImage();

	textTeclado.LoadTGA("ImagenesSillas/rock.tga");
	textTeclado.BuildGLTexture();
	textTeclado.ReleaseImage();

	textTouchPad.LoadBMP("casa/touchpad.bmp");
	textTouchPad.BuildGLTexture();
	textTouchPad.ReleaseImage();

	//..........................Modelos 3ds..........................//

	Mesa._3dsLoad("Table 2.3ds");
	sillon._3dsLoad("Casa/sillon.3DS");
	sillon2._3dsLoad("Casa/sillon.3DS");
	mueble._3dsLoad("Casa/mueble.3DS");
	pin._3dsLoad("hulk.3ds");
	//END NEW//////////////////////////////

	objCamera.Position_Camera(25,2.5f,-10,25,2.5f,-11, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotMusIzq = 0;
		KeyFrame[i].rotMusIzqInc = 0;
		KeyFrame[i].rotBraIzq = 0;
		KeyFrame[i].rotBraIzqInc = 0;
		KeyFrame[i].rotBraDer = 0;
		KeyFrame[i].rotBraDerInc = 0;

		KeyFrame[i].rotBraIzqEn = 0;
		KeyFrame[i].rotBraIzqEnInc = 0;
		KeyFrame[i].rotBraDerEn = 0;
		KeyFrame[i].rotBraDerEnInc = 0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;
	}
	//NEW//////////////////NEW//////////////////NEW//////////////////

}

void luces() {
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);


	/*glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular2);
	glLightfv(GL_LIGHT1, GL_POSITION, SPosition);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, SPosition2);*/
}
void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();
	glPushMatrix();
	
	//CONTROL DE LUCES
	luces();
	if (light)
		glEnable(GL_LIGHT0);
	else
		glDisable(GL_LIGHT0);

	glEnable(GL_LIGHTING);
	//FIN DE CONTROL DE LUCES

	glRotatef(g_lookupdown,1.0f,0,0);
		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //-------------------------------Creamos Silla
				glDisable(GL_LIGHTING);
				glTranslatef(1,-2.5,-10);
				glScalef(1,1.8,1);
				SillaNew1();
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //-------------------------------Creamos otra Silla
				glDisable(GL_LIGHTING);
				glTranslatef(13,-2,-52);
				glRotatef(-90,0,1,0);
				glScalef(1,1.5,1);
				SillaNew2();
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//SillA
			glPushMatrix();
			glTranslated(26, 1, -20);
			glScalef(0.40, 0.3, 0.40);
			silla();
			glPopMatrix();

			glPushMatrix(); //-------------------------------Creamos jenga
				glDisable(GL_LIGHTING);
				glTranslatef(11,1.5,-10);
				glScalef(0.5, 0.5, 0.5);
				Jenga();
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();
			glDisable(GL_COLOR_MATERIAL);//........................Poner mesa 3ds
				glRotatef(0, 1, 0, 0);
				glScalef(0.05, 0.05, 0.05);
				glTranslatef(480, 33, -450);
				//glTranslatef(GiroX, GiroY, GiroZ);
				//glRotatef(rotKit, 0, 1, 0);
				//glRotatef(rotKit2, 1, 0, 0);
				//glRotatef(rotKit3, 0, 0, 1);
				//Pongo aquí la carroceria del carro
				Mesa.GLrender(NULL,_SHADED,1.0);  //_WIRED O _POINTS
			glPopMatrix();

			glPushMatrix(); //-------------------------------Creamos chimenea
				glDisable(GL_LIGHTING);
				glTranslatef(1,1,1);
				glScalef(0.5, 0.5, 0.5);
				Chimenea();
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //-------------------------------Creamos cascada
				glDisable(GL_LIGHTING);
				glTranslatef(1,1,1);
				glScalef(0.5, 0.5, 0.5);
				Cascadafuente();
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//...........................dibuja poster psp
				glDisable(GL_LIGHTING);
					glTranslatef(42.75,4,-15);
					poster();
				glEnable(GL_LIGHTING);
				glPopMatrix();

			glPushMatrix();//...........................dibuja poster nintendo
				glDisable(GL_LIGHTING);
				glTranslatef(17.3,4,-15);
					cuadro();
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//------------------------------dodecaedro
				glTranslatef(21,2.0,-20);
				glScalef(0.5,0.5,0.5);
				glRotatef(rotD,0,1,0);
				glRotatef(rotD,1,0,0);
				glRotatef(rotD,1,0,0);
				glDisable(GL_LIGHTING);
				fig5.dodecaedro(Dodecaedro.GLindex,0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//------------------------------dodecaedromini
				glTranslatef(25,2.0,-23);
				glScalef(0.08,0.08,0.08);
				glRotatef(rotD*2,0,1,0);
				glRotatef(rotD,1,0,0);
				glRotatef(rotD,1,0,0);
				glDisable(GL_LIGHTING);
				fig5.dodecaedro(Dodecaedro.GLindex,0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//.........................dibuja ventilador
				glRotatef(0, 0,1,0);
				glTranslatef(30,7.5,-15);
				glScalef(0.3,0.3,0.3);
				glDisable(GL_LIGHTING);
				VentiladorT();
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//...........................dibujamos sillon 3ds
				glTranslatef(40,0,-27);
				glScalef(0.04,0.04,0.06);
				//glDisable(GL_LIGHTING);
				sillon.GLrender(NULL,_SHADED,1.0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//...........................dibujamos sillon2 3ds
				glTranslatef(20,0,-27);
				glScalef(0.04,0.04,0.06);
				//glDisable(GL_LIGHTING);
				sillon.GLrender(NULL,_SHADED,1.0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_COLOR_MATERIAL);//........................Poner Pin.3ds
			glRotatef(90,0,1,0);
			glScalef(0.05, 0.05, 0.05);
			glTranslatef(120, 5, 550);
			pin.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
			glPopMatrix();

			/*glPushMatrix();//....................................modelo mueble 3ds
				glTranslatef(30,0,-8);
				//glRotatef(-90,0,1,0);
				glScalef(0.03,0.03,0.03);
				//glDisable(GL_LIGHTING);
				mueble.GLrender(NULL,_SHADED,1.0);
				glEnable(GL_LIGHTING);
			glPopMatrix();*/

			

			glPushMatrix();//...........................dibujamos libros
				glTranslatef(20,1.85,-26);
				glScalef(1,0.1,0.66);
				//glDisable(GL_LIGHTING);
				book(textLibroCG.GLindex);	
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//...........................dibujamos libros
				glTranslatef(19,1.85,-26);
				glScalef(1,0.1,0.66);
				glRotatef(25,0,1,0);
				//glDisable(GL_LIGHTING);
				book(textLibrolit.GLindex);	
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//...........................dibujamos libros
				glTranslatef(20.8,1.85,-27);
				glScalef(1,0.1,0.66);
				glRotatef(-60,0,1,0);
				//glDisable(GL_LIGHTING);
				book(textLibrolit1.GLindex);	
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//.......................otra silla
				glTranslatef(23.5,1,-22);
				glRotatef(90, 0,1,0);
				silla(0.3,0.15,0.3,0,0,0);
			glPopMatrix();

			glPushMatrix(); //...................Creamos  pieza  jenga
				//glDisable(GL_LIGHTING);
				glTranslatef(26, 1.8, -23);
				//glTranslatef(rotBraDer, 0, 0);
				glRotatef(rotD,0,1,0);
				glScalef(1, 0.2, 0.33);
				glScalef(0.5, 0.5, 0.5);
				fig7.prisma2(jenga.GLindex,jenga.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //...................Creamos  pieza  jenga
				//glDisable(GL_LIGHTING);
				glTranslatef(26, 1.8, -21);
				//glTranslatef(rotBraDer, 0, 0);
				glScalef(1, 0.2, 0.33);
				glScalef(0.5, 0.5, 0.5);
				fig7.prisma2(Forro.GLindex,Forro.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //...................Creamos  pieza  jenga
				//glDisable(GL_LIGHTING);
				glTranslatef(24.8, 1.8, -22);
				//glTranslatef(rotBraDer, 0, 0);
				glScalef(1, 0.2, 0.33);
				glScalef(0.5, 0.5, 0.5);
				fig7.prisma2(jenga.GLindex,jenga.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			

			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					glCallList(ciudad_display_list);
					glTranslatef(posX, posY, posZ);
					glRotatef(giroMonito, 0, 1, 0);
					monito();
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();	

			

			glPushMatrix(); //Flecha
				glScalef(7,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma_anun(text3.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			 
			glPushMatrix(); //................................agua
				glTranslatef(30,2,-5.75);
				glRotated(-90,1,0,0);
				glScalef(3,0.1,3);


				glDisable(GL_LIGHTING);
				fig3.prisma_anun(Plastico.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			//CASA///////////////////
			//¨****casa*****
			glPushMatrix();
				glScalef(1.0, 0.5, 1.0);
				glTranslatef(30, 3, -17.2);
				glRotatef(180, 0, 1, 0);
				glDisable(GL_LIGHTING);
				glScalef(0.3, 0.3, 0.3);
					casa();
				
				glPushMatrix();
					
					//****LIBROS****

					

					
					//****COMEDOR***
					/*glPushMatrix();
						glTranslatef(-20,0,25);
						glScalef(1.3,1.3,1.3);
						comedor();
					glPopMatrix();
					//mesa y laptop
					glPushMatrix();
						glRotatef(90, 0,1,0);
						mesa(1,1.5,1,-25,1.4,24);
					glPopMatrix();
				
					glPushMatrix();
						glRotatef(90, 0,1,0);
						dibujaLaptop(.3,.3,.3,-90,9,77);
					glPopMatrix();

					glPushMatrix();
						glRotatef(280, 0,1,0);
						silla(1,1,1,29,0,-24.5);
					glPopMatrix();*/

					//*****ROSE*****
					glPushMatrix(); 
						glPushMatrix();
							glTranslatef(0,0,-0.5); 
							glRotatef(90, 0,1,0); 
							glTranslatef(2,0,-0.5);
							//dibujaCama(1.1,1.1,1.1,14.0,-5.5,-37.0); 
						glPopMatrix();
						glPushMatrix();
							glRotatef(90, 0,1,0); 
							//dibujaBuro(1,1,1,-2,-9.5,-42.0); 
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0,47,0);
							glScalef(1.2,1.2,1.2);
							lampara.cono(2.0,0.4,100,textLampara.GLindex);
						glPopMatrix();
					glPopMatrix();
					//******JOAN*****
					//ropero
					glPushMatrix();
						glRotatef(0, 0,1,0);
						glTranslatef(-36.5,23,-65.5);
						glScalef(.7,.7,.7);
						ropero();
					glPopMatrix();

					
				glPopMatrix();


			glEnable(GL_LIGHTING);
			glPopMatrix();
					

			glColor3f(1.0,1.0,1.0);

		glPopMatrix();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-11,12.0,-14.0,(void *)font,"Proyecto Final - Laboratorio");
			pintaTexto(-11,10.5,-14,(void *)font,"Listas de Dibujo");
			pintaTexto(-11,8.5,-14,(void *)font,s);
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.01;
	fig3.text_der-= 0.01;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;

	//Movimiento del dado
	if (rotV<360)
	{
		rotV++;
		rotD++;
	}
	else
	{
		rotV=0;
		rotD=0;
	} 
	if (actJ1)
	{
		MovJ=MovJ+0.2;
		if(MovJ>8)
			{
				actJ1=FALSE;
				actJ=TRUE;
				
		//rotD++;
			}
	} 
	if (actJ)
	{
		MovJ=MovJ-0.2;
		 if(MovJ<0)
		 {
			actJ=FALSE;
			actJ1=TRUE;
		//rotD=0;
		 }
	} 
	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotMusIzqInc = (KeyFrame[playIndex + 1].rotMusIzq - KeyFrame[playIndex].rotMusIzq) / i_max_steps;
				KeyFrame[playIndex].rotBraIzqInc = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;
				KeyFrame[playIndex].rotBraDerInc = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;

				KeyFrame[playIndex].rotBraIzqEnInc = (KeyFrame[playIndex + 1].rotBraIzqEn - KeyFrame[playIndex].rotBraIzqEn) / i_max_steps;
				KeyFrame[playIndex].rotBraDerEnInc = (KeyFrame[playIndex + 1].rotBraDerEn - KeyFrame[playIndex].rotBraDerEn) / i_max_steps;
			}
		}
		else
		{
			posX+=KeyFrame[playIndex].incX;
			posY+=KeyFrame[playIndex].incY;
			posZ+=KeyFrame[playIndex].incZ;

			
			rotRodIzq+=KeyFrame[playIndex].rotInc;
			giroMonito+=KeyFrame[playIndex].giroMonitoInc;
			rotMusIzq += KeyFrame[playIndex].rotMusIzqInc;
			rotBraIzq += KeyFrame[playIndex].rotBraIzqInc;
			rotBraDer += KeyFrame[playIndex].rotBraDerInc;

			rotBraIzqEn += KeyFrame[playIndex].rotBraIzqEnInc;
			rotBraDerEn += KeyFrame[playIndex].rotBraDerEnInc;
			i_curr_steps++;
		}
		
	}

	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n",FrameIndex);			

				KeyFrame[FrameIndex].posX=posX;
				KeyFrame[FrameIndex].posY=posY;
				KeyFrame[FrameIndex].posZ=posZ;

				KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
				KeyFrame[FrameIndex].giroMonito = giroMonito;
				KeyFrame[FrameIndex].rotMusIzq = rotMusIzq;
				KeyFrame[FrameIndex].rotBraIzq = rotBraIzq;
				KeyFrame[FrameIndex].rotBraDer = rotBraDer;

				KeyFrame[FrameIndex].rotBraIzqEn = rotBraIzqEn;
				KeyFrame[FrameIndex].rotBraDerEn = rotBraDerEn;
				
			
				FrameIndex++;
			}
			
			break;

		case 'l':						
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				posX=KeyFrame[0].posX;
				posY=KeyFrame[0].posY;
				posZ=KeyFrame[0].posZ;

				rotRodIzq=KeyFrame[0].rotRodIzq;
				giroMonito = KeyFrame[0].giroMonito;
				rotMusIzq = KeyFrame[0].rotMusIzq;
				rotBraIzq = KeyFrame[0].rotBraIzq;
				rotBraDer = KeyFrame[0].rotBraDer;

				

				//First Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotMusIzqInc = (KeyFrame[playIndex + 1].rotMusIzq - KeyFrame[playIndex].rotMusIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotBraIzqInc = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;
				KeyFrame[playIndex].rotBraDerInc = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;
				KeyFrame[playIndex].rotBraIzqEnInc = (KeyFrame[playIndex + 1].rotBraIzqEn - KeyFrame[playIndex].rotBraIzqEn) / i_max_steps;
				KeyFrame[playIndex].rotBraDerEnInc = (KeyFrame[playIndex + 1].rotBraDerEn - KeyFrame[playIndex].rotBraDerEn) / i_max_steps;

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case 'y':						
		case 'Y':
			posZ++;
			printf("%f \n", posZ);
			break;

		case 'g':						
		case 'G':
			posX--;
			printf("%f \n", posX);
			break;

		case 'h':						
		case 'H':
			posZ--;
			printf("%f \n", posZ);
			break;

		case 'j':						
		case 'J':
			posX++;
			printf("%f \n", posX);
			break;
		case 'Z':
			light = !light;
			if (light)
				printf("encender luz\n");
			else
				printf("apagar luz\n");
			break;
		case '2':
			objCamera.Position_Camera(25, 4.0f, -20, 25, 2.5f, -45, 0, 1, 0);
			break;
		case '3':
			objCamera.Position_Camera(25,2.5f,-10,25,2.5f,-11, 0, 1, 0);
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:
			if(FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n",FrameIndex);			

				KeyFrame[FrameIndex].posX=posX;
				KeyFrame[FrameIndex].posY=posY;
				KeyFrame[FrameIndex].posZ=posZ;

				KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
				KeyFrame[FrameIndex].giroMonito=giroMonito;
				KeyFrame[FrameIndex].rotMusIzq = rotMusIzq;
				KeyFrame[FrameIndex].rotBraIzq = rotBraIzq;
				KeyFrame[FrameIndex].rotBraDer = rotBraDer;
				KeyFrame[FrameIndex].rotBraIzqEn = rotBraIzqEn;
				KeyFrame[FrameIndex].rotBraDerEn = rotBraDerEn;
				
			
				FrameIndex++;
			}
			
		
			break;

		case 1:
			if(play==false && FrameIndex >1)
			{

				posX=KeyFrame[0].posX;
				posY=KeyFrame[0].posY;
				posZ=KeyFrame[0].posZ;

				rotRodIzq=KeyFrame[0].rotRodIzq;
				giroMonito=KeyFrame[0].giroMonito;
				rotMusIzq = KeyFrame[0].rotMusIzq;
				rotBraIzq = KeyFrame[0].rotBraIzq;
				rotBraDer = KeyFrame[0].rotBraDer;
				//First Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotMusIzqInc = (KeyFrame[playIndex + 1].rotMusIzq - KeyFrame[playIndex].rotMusIzq) / i_max_steps;
				KeyFrame[playIndex].rotBraIzqInc = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;
				KeyFrame[playIndex].rotBraDerInc = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;
				KeyFrame[playIndex].rotBraIzqEnInc = (KeyFrame[playIndex + 1].rotBraIzqEn - KeyFrame[playIndex].rotBraIzqEn) / i_max_steps;
				KeyFrame[playIndex].rotBraDerEnInc = (KeyFrame[playIndex + 1].rotBraDerEn - KeyFrame[playIndex].rotBraDerEn) / i_max_steps;
				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}
}

void menu( int id)
{
	/*switch (id)
	{
		case 1:
			g_fanimacion^= true; //Activamos/desactivamos la animacíon
			break;
		

	}*/
}

int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (800, 600);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
  //glutAddMenuEntry	  ("Animacion Carro", 1);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}
