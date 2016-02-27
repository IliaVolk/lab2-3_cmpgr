#include "header.h"




double roundSpin = 0;
double dFly = 0;
bool doFly = false;
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	

	////////////////
	gluLookAt(0, 0, 3, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	doScale();
	rotate();
	
	glPushMatrix();
	glRotatef(roundSpin, 0, 1, 0);
	glPushMatrix();
	
	glTranslatef(0.7, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glRotatef(90, 0, 1, 0);
	paintBee();
	glPopMatrix();
	glPopMatrix();
	
	
	//glScalef(1.0, 2.0, 1.0);
	
	//displayAxis();
	
	
	glutSwapBuffers();
}
double DDFLYCONST = 5.0;
double ddFly = DDFLYCONST;
void callInLoop(){
	Sleep(30);
	if (doFly){
		if (roundSpin > 360){
			roundSpin -= 360;
		}
		if (dFly > 60){
			ddFly = -DDFLYCONST;
		}
		if (dFly < -15){
			ddFly = DDFLYCONST;
		}
		roundSpin += 2;
		dFly += ddFly;
	}
	glutPostRedisplay();
}
