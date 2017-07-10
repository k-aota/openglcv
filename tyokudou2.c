#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <time.h>

//xyをトラックバーで指定して画面に数字で出すプログラム
//サンプルのサイトからもらってきて改変

/* グローバル変数 */
CvFont font;
IplImage *img = 0;
double a, b;
int p_x = 0;
int p_y = 0;
static int t_x = 0;
static int t_y = 0;
static int r = 0; /* 回転角 */

/* プロトタイプ宣言 */
void on_trackbar1 (int val);
void on_trackbar2 (int val);


//prog2
GLdouble vertex[][3] = {
  { 0.0, 0.0, 0.0 },
  { 1.0, 0.0, 0.0 },
  { 1.0, 1.0, 0.0 },
  { 0.0, 1.0, 0.0 },
  { 0.0, 0.0, 1.0 },
  { 1.0, 0.0, 1.0 },
  { 1.0, 1.0, 1.0 },
  { 0.0, 1.0, 1.0 }
};

GLdouble vertex0[][3] = {
  {  0.0, 0.0, 0.0 },
  { 50.0, 0.0, 0.0 },
  { 50.0, 1.0, 0.0 },
  {  0.0, 1.0, 0.0 },
  {  0.0, 0.0, 50.0 },
  { 50.0, 0.0, 50.0 },
  { 50.0, 1.0, 50.0 },
  {  0.0, 1.0, 50.0 }
};

int edge0[][2] = {
  { 0, 1 },
  { 1, 2 },
  { 2, 3 },
  { 3, 0 },
  { 4, 5 },
  { 5, 6 },
  { 6, 7 },
  { 7, 4 },
  { 0, 4 },
  { 1, 5 },
  { 2, 6 },
  { 3, 7 }
};

int face[][4] = {
  { 0, 1, 2, 3 },
  { 1, 5, 6, 2 },
  { 5, 4, 7, 6 },
  { 4, 0, 3, 7 },
  { 4, 5, 1, 0 },
  { 3, 2, 6, 7 }
};

GLdouble normal[][3] = {
  { 0.0, 0.0,-1.0 },
  { 1.0, 0.0, 0.0 },
  { 0.0, 0.0, 1.0 },
  {-1.0, 0.0, 0.0 },
  { 0.0,-1.0, 0.0 },
  { 0.0, 1.0, 0.0 }
};


GLfloat light0pos[] = { 0.0, 3.0, 5.0, 1.0 };
GLfloat light1pos[] = { 5.0, 3.0, 0.0, 1.0 };

GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat red[] = { 0.0, 0.2, 0.2, 1.0 };
GLfloat blue[] = {0.2, 0.2, 0.8, 1.0};
GLfloat white[] = {0.8, 1.0, 0.8, 1.0};

void cube(void)
{
  int i;
  int j;

  glBegin(GL_QUADS);
  for (j = 0; j < 6; ++j) {
    glNormal3dv(normal[j]);
    for (i = 0; i < 4; ++i) {
      glVertex3dv(vertex[face[j][i]]);
    }
  }
  glEnd();
}
void cube0(void)
{
  int i;
  int j;

  glBegin(GL_LINES);
  for (i = 0; i < 12; ++i) {
    glVertex3dv(vertex0[edge0[i][0]]);
    glVertex3dv(vertex0[edge0[i][1]]);
  }
  glEnd();
}

void idle(void)
{
  glutPostRedisplay();
}
void display0(void)
{
  int i;
  int j;
  //static int r = 0; /* 回転角 */

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  /* 視点位置と視線方向 */
  gluLookAt(35.0, 90.0, 15.0, 25.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//  gluLookAt(35.0, 90.0, 40.0, 25.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /* 光源の位置設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1pos);

  /* 二つ目の図形の描画 */
  glPushMatrix();
  glTranslated(p_x, 0.0, p_y*(-1));
  printf("%d\t", p_x);
  printf("%d\n", p_y);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
  cube();
  /* 三つ目の図形の描画 */
  glPushMatrix();
  glTranslated(p_x*(-1.0), 0.0, p_y-25.0);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
  cube0();
  glPopMatrix();
  /*モデルビュー変換行列の復帰*/
  glPopMatrix();
  glutSwapBuffers();
  /* 一周回ったら回転角を 0 に戻す */
  if (++r >= 50) r = 0;
}
void display(void)
{
  int i;
  int j;
  static int r = 0; /* 回転角 */

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  /* 視点位置と視線方向 */
  gluLookAt(35.0, 90.0, 15.0, 25.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//  gluLookAt(35.0, 90.0, 40.0, 25.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /* 光源の位置設定 */
    glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1pos);

  /*モデルビュー変換行列の保存*/
  glPushMatrix();
  /* 図形の回転 */
  //glRotated((double)r, 0.0, 1.0, 0.0);
  glTranslated((double)r, 0.0, (-1)*(double)r*((double)t_y/(double)t_x));
  //glTranslated((double)r, 0.0, 0.0);
  /* 図形の色 (赤)  */
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
  /* 図形の描画 */
  cube();

  /* 二つ目の図形の描画 */
  glPushMatrix();
  glTranslated(p_x, 0.0, p_y*(-1));
  printf("%d\t", t_x);
  printf("%d\t", t_y);
  printf("%d\t", p_x);
  printf("%d\n", p_y);
  //glRotated((double)(2 * r), 0.0, 1.0, 0.0);
  glTranslated((double)r*(-1.0), 0.0, (double)r*((double)t_y/(double)t_x));
  //glTranslated((double)r*(-1.0), 0.0, 0.0);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
  cube();
  /* 三つ目の図形の描画 */
  glPushMatrix();
  glTranslated(p_x*(-1.0), 0.0, p_y-25.0);
  //glTranslated((double)r*(-1.0), 0.0, 0.0);
  //glRotated((double)(2 * r), 0.0, 1.0, 0.0);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
  cube0();

  glPopMatrix();

  /*モデルビュー変換行列の復帰*/
  glPopMatrix();

  glutSwapBuffers();

  /* 一周回ったら回転角を 0 に戻す */
  if (++r >= 50) r = 0;
}

void resize(int w, int h)
{
  glViewport(0, 0, w, h);

  /* 透視変換行列の設定 */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);//視野角

  /* モデルビュー変換行列の設定 */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void mouse(int button, int state, int x, int y)
{
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
      /* アニメーション開始 */
      glutIdleFunc(idle);
    }
    else {
      /* アニメーション停止 */
      glutIdleFunc(0);
    }
    break;
  case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN) {
      /* コマ送り (1ステップだけ進める) */
        glutPostRedisplay();
    }
    break;
  default:
    break;
  }
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case 'q':
  case 'Q':
  case '\033':  /* '\033' は ESC の ASCII コード */
    exit(0);//プログラムの終了
  default:
    break;
  }
}

/*void finish(int r, int t_x)
{
  if(r-5<t_x&&r+5>t_x){
    printf("You Win !!\n");
    exit(0);
  }
}*/

/* ARGSUSED1 */
void keyboard2(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
          glutLeaveMainLoop();
         //exit(0);
         break;
   }
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, green);
  glLightfv(GL_LIGHT1, GL_SPECULAR, green);
}

int main(int argc, char *argv[])
{
  unsigned char c;

  //アスキーアート？(そんなことするならなんか画像表示)
  printf("AAAAA\n");
  printf("  A  \n");
  printf("AAAAA\n");
  //ランダムな配置
  srand(time(NULL));
  p_x = rand()%51;
  srand(time(NULL));
  p_y = rand()%51-25;

  //ターゲットの表示
  glutInitWindowPosition(1000, 100);
  glutInitWindowSize(600, 600);
  glutInit(&argc, argv);
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display0);
  glutReshapeFunc(resize);
  //glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard2);
  init();
  glutMainLoop();

  //以下トラックバー
  //unsigned char c;
  // (1)画像領域を確保し，初期化する
  img = cvCreateImage (cvSize (400, 200), IPL_DEPTH_8U, 3);
  cvZero (img);
  cvInitFont (&font, CV_FONT_HERSHEY_DUPLEX, 1.0, 1.0,0,1.0,8.0);
  // (2)ウィンドウ，およびトラックバーを作成する
  cvNamedWindow ("Image", CV_WINDOW_AUTOSIZE);
  cvCreateTrackbar ("Trackbar_x", "Image", 0, 50, on_trackbar1);
  cvCreateTrackbar ("Trackbar_y", "Image", 0, 50, on_trackbar2);
  cvShowImage ("Image", img);
  cvWaitKey (0);

  //トラックバーの値はメモっておいて、トラックバー終了する
  while (1) {
    c = cvWaitKey(2) & 0xff;
    t_x = cvGetTrackbarPos("Trackbar_x", "Image");
    t_y = cvGetTrackbarPos("Trackbar_y", "Image");
    if (c == '\x1b')//ESC
      break;
  }

  cvDestroyWindow ("Image");
  cvReleaseImage (&img);

  //結果表示
  glutInitWindowPosition(1000, 100);
  glutInitWindowSize(600, 600);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  //finish(r, t_x);
  init();
  glutMainLoop();
  return 0;
}


/* コールバック関数 */
void
on_trackbar1 (int val)
{
  char str[64];
  a=(double)cvGetTrackbarPos("Trackbar_x","Image");
  //a=(double)cvGetTrackbarPos("Trackbar_y","Image");

  // (4)トラックバー1の値を描画する
  cvRectangle (img, cvPoint (0, 0), cvPoint (400, 50), cvScalar (0,0,0,0), CV_FILLED,8,0);
  snprintf (str, 64, "%d", val);
  cvPutText (img, str, cvPoint (15, 30), &font, CV_RGB (0, 200, 100));
  cvShowImage ("Image", img);
}

void
on_trackbar2 (int val)
{
  char str[64];
  int pos1, pos2;
  //a=(double)cvGetTrackbarPos("Trackbar_x","Image");
  b=(double)cvGetTrackbarPos("Trackbar_y","Image");

  // (4)トラックバー2の値を描画する
  cvRectangle (img, cvPoint (0, 50), cvPoint (400, 100), cvScalar (0,0,0,0), CV_FILLED,8,0);
  snprintf (str, 64, "%d", val);
  cvPutText (img, str, cvPoint (15, 80), &font, CV_RGB (200, 200, 0));
  cvShowImage ("Image", img);

}
