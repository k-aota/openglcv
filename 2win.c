#include <GL/glut.h>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int WinID[2]; //ウィンドウID

int main(int argc, char **argv)
{
	glutInit(&argc,argv);

	//ウィンドウ1つ目
	glutInitDisplayMode(GLUT_RGBA| GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(640,480);
	WinID[0] = glutCreateWindow("Window 1");
	GLUT_CALL_FUNC(); //コールバック関数の登録
	MY_INIT(); //各種初期化


	//ウィンドウ2つ目
	glutInitDisplayMode(GLUT_RGBA| GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(320,240);
	WinID[1] = glutCreateWindow("Window 2");
	GLUT_CALL_FUNC2();//コールバック関数の登録
	MY_INIT2();//各種初期化

	glutMainLoop();

	return 0;
}
