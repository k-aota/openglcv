#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>


/* プロトタイプ宣言 */

extern CvFont font;
extern IplImage *img = 0;

extern void on_trackbar1 (int val);
extern void on_trackbar2 (int val);
//extern int main (int argc, char *argv[]);

//sample-cube.c(opengl)
void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
   gluLookAt (0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//eye,obj,upこれをいじれば視点変えれそう
   glTranslatef(1.0,1.0,-5.0);//これをいじるとオブジェクト座標が変わる
   glScalef (1.0, 1.0, 1.0);      /* modeling transformation */
   glutWireCube(3.0);
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

/* ARGSUSED1 */
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(320, 240)
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

/*
void main()
{
  while (ok押されるまで)
  {
  //トラックバーで値を取得(x,y) xy.c参照
  ax = (double)cvGetTrackbarPos("Trackbar1", "Image");
  ay = (double)cvGetTrackbarPos("Trackbar2", "Image");



  ハンドを座標点に表示()sample-cube.cに値を代入すればそれっぽい
  }
  for(hoge)
  アニメーション()同じくsample-cube.cに値をいれる
  いい感じに数秒たつ

  結果判定()
  ２点間の距離が一定値以内ならばok
  結果表示()
  get/faildの表示

  return 0;
}*/
/*
めも欄
ハンドの座標は３次元で持っておく
*/
