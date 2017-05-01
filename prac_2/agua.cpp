//Semestre 2016 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*****	Ismene Donaji Torres Camacho                     *****//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;
int camX = 0, camY = 0.0, camZ = 0;

float text_der = 1.0;
float text_izq = 0.0;

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;
CTexture t_dado8;
CTexture t_metal01;
CTexture t_dado;
CTexture t_base;
CTexture t_agua;

bool mov = true;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	
    // habilitar texturizado en 2d
	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//abrir la imagen y cargarga a una estructura
	t_dado.LoadTGA("dado.tga");
	//el arreglo asignado- crea una textura
	t_dado.BuildGLTexture();
	//cerrar imagen tga, se libera la estructura-la imagen se deja de utilizar
	t_dado.ReleaseImage();


	t_agua.LoadTGA("agua.tga");
	t_agua.BuildGLTexture();
	t_agua.ReleaseImage();

	t_base.LoadTGA("base.tga");
	t_base.BuildGLTexture();
	t_base.ReleaseImage();
}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void prisma(GLuint textura3, GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);  //Bottom
						  //glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0, 0); glVertex3fv(vertice[0]);
	glTexCoord2f(1, 0); glVertex3fv(vertice[1]);
	glTexCoord2f(1, 1); glVertex3fv(vertice[2]);
	glTexCoord2f(0, 1); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Top
						  //glColor3f(0.8,0.2,0.4);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0, 0); glVertex3fv(vertice[4]);
	glTexCoord2f(1, 0); glVertex3fv(vertice[5]);
	glTexCoord2f(1, 1); glVertex3fv(vertice[6]);
	glTexCoord2f(0, 1); glVertex3fv(vertice[7]);
	glEnd();


	glBegin(GL_POLYGON);	//Front
	
	glNormal3f(0.0f, 0.0f, 1.0f);
	 glVertex3fv(vertice[0]);
	 glVertex3fv(vertice[4]);
	 glVertex3fv(vertice[7]);
	 glVertex3fv(vertice[1]);
	glEnd();

	
	glBegin(GL_POLYGON);	//Right
	
	glNormal3f(1.0f, 0.0f, 0.0f);
	 glVertex3fv(vertice[0]);
	 glVertex3fv(vertice[3]);
	 glVertex3fv(vertice[5]);
	 glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
							
	glNormal3f(0.0f, 0.0f, -1.0f);
	 glVertex3fv(vertice[6]);
	 glVertex3fv(vertice[5]);
     glVertex3fv(vertice[3]);
	 glVertex3fv(vertice[2]);
	glEnd();


	glBegin(GL_POLYGON);  //Left
						 
	glNormal3f(-1.0f, 0.0f, 0.0f);
	 glVertex3fv(vertice[1]);
	 glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	 glVertex3fv(vertice[2]);
	glEnd();


}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
	

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
	
		glPushMatrix();
			glRotatef(eye_camX, 1.0, 0.0, 0.0);
			glRotatef(eye_camY, 0.0, 1.0, 0.0);
			glRotatef(eye_camZ, 0.0, 0.0, 1.0);
			glScalef(0.5, 0.5, 0.5);
			glTranslatef(1, 0, 0);
			prisma(t_base.GLindex, t_agua.GLindex);
		glPopMatrix();


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	text_izq-= 0.01;
	text_der-= 0.01;
	if(text_izq<-1)
		text_izq=0;
	if(text_der<0)
		text_der=1;

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 'i':
		case 'I':
			camX = (camX - 15) % 360;
			break;

		case 'o':
		case 'O':
			camY = (camY - 15) % 360;
			break;
		case 'p':
		case 'P':
			camZ = (camZ - 15) % 360;
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
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}