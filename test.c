//#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

const GLfloat vertex[] = { -0.9 , 0.9 , 0.9 , 0.9 , 0 , -0.9 };
GLboolean isLine = GL_FALSE;

void disp( void ) {
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2 , GL_FLOAT , 0 , vertex);
	glDrawArrays((isLine == GL_TRUE ? GL_LINE_LOOP : GL_POLYGON) , 0 , 3);

	glFlush();
}

void mouse(int button , int state , int x , int y) {
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN) return;
	isLine = (isLine == GL_TRUE ? GL_FALSE : GL_TRUE);
	glutPostRedisplay();
}

int main(int argc , char ** argv) {
	glutInit(&argc , argv);
	glutInitWindowPosition(100 , 50);
	glutInitWindowSize(400 , 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("Kitty on your lap");
	glutDisplayFunc(disp);
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}
