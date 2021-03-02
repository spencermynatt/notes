
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
using namespace std;


string exit() {
	string input;
	cout << "type a to leave\n";
	cin >> input;
	if (input == "a") {
		exit(0);
	};
}
void avoid_draw_over() {
glEnable(GL_DEPTH_TEST);
	
}
void resize(int w, int h)
{

	//void glutReshapeFunc(void (*func)(int width, int height));
//we will take the this and
//put it into glutReshapefunc
//which reshapes the window

	/*


Rendering vertices (as in glVertex ) depends 
on the current state of matrices called "model-view matrix" and "projection matrix",

The commands glTranslatef, glPushMatrix, glLoadIdentity,
glLoadMatrix, glOrtho, gluPerspective and the whole family 
affect the current matrix (which is either of the above),

The command glMatrixMode selects the matrix (model-view or projection) 
which is affected by the forementioned commands.

(Also, there's also the texture matrix used for texture coordinates, but it's seldomly used.)

So the common use case is:

have the model-view matrix active most of the time,
whenever you have to initialize the projection matrix 
(usually at the beginning or when the window is resized, perhaps), 
switch the active to projection, set up a perspective, and revert back to model-view.*/
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	//P_transformed = M_projection * M_modelview * P;, //initilizes marix
	glLoadIdentity(); //puts 1s on all the rows
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
/*
aps from an object's local coordinate space into world space,
view from world space to camera space, projection from camera to screen.*/
}
float angle = 30.0f;
float camera_angle = 0.0f;

void draw_scene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //DRAWING PERSPECTIVE
	glLoadIdentity();
	glRotatef(camera_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(-0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glVertex3f(0.4f, 0.5f, 0.0f);
	glVertex3f(-0.4f, 0.5f, 0.0f);
	glEnd();
	glutSwapBuffers();

}



int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("playing");
	avoid_draw_over();
	glutDisplayFunc(draw_scene);
	glutReshapeFunc(resize);
	exit();
	glutMainLoop();
	return 0;


}
