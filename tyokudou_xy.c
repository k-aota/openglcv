//これをそのまま直動に変える？
//直動に変えた。座標が値ででる
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

//xyをトラックバーで指定して画面に数字で出すプログラム
//サンプルのサイトからもらってきて改変

/* グローバル変数 */
CvFont font;
IplImage *img = 0;

/* プロトタイプ宣言 */
void on_trackbar1 (int val);
void on_trackbar2 (int val);


//直方体の情報だからさわらなくておけ
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

int edge[][2] = {
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

int x=0;//移動をカウント
static int r = 0; /* 回転角 */
//int WinID[2];

double a, b;

void idle(void)
{
  glutPostRedisplay();
  x=x+1;
  printf("%d\n", x);
}

void display0(void)
{
  int i;
  //static int r = 0; /* 回転角 */
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  /* 視点位置と視線方向 */
  gluLookAt(30.0, 40.0, 50.0, 20.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  /* 図形の並進移動 */
  //r=a;
  glTranslated((double)r/**(-1.0)*/, 0.0, 0.0);
  /* 図形の描画 */
  glColor3d(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  for (i = 0; i < 12; ++i) {
    glVertex3dv(vertex[edge[i][0]]);
    glVertex3dv(vertex[edge[i][1]]);
  }
  glEnd();

  glutSwapBuffers();

  /* 一周回ったら回転角を 0 に戻す */
  if (++r >= 50) {
    r = 0;
    x = 0;
  };
}

void display1(void)
{
  int i;
  //static int r = 0; /* 回転角 */
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  /* 視点位置と視線方向 */
  gluLookAt(30.0, 40.0, 50.0, 20.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  /* 図形の並進移動 */
  //r=a;
  glTranslated((double)r/**(-1.0)*/, 0.0, 0.0);
  /* 図形の描画 */
  glColor3d(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  for (i = 0; i < 12; ++i) {
    glVertex3dv(vertex[edge[i][0]]);
    glVertex3dv(vertex[edge[i][1]]);
  }
  glEnd();

  glutSwapBuffers();

  /* 一周回ったら回転角を 0 に戻す */
  if (++r >= 50) {
    r = 0;
    x = 0;
  };
}
/*void init2(void)
{
   glClearColor (1.0, 1.0, 1.0, 1.0);
   glShadeModel (GL_FLAT);
}*/
/*void display2(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glLoadIdentity ();             // clear the matrix
           // viewing transformation
   gluLookAt (0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//eye,obj,upこれをいじれば視点変えれそう
   glTranslatef(1.0,0.0,0.0);//これをいじるとオブジェクト座標が変わる
   glScalef (1.0, 1.0, 1.0);      // modeling transformation
   glutWireCube(3.0);
   glFlush ();
}*/

/*void reshape2 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
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
void resize(int w, int h)
{
  glViewport(0, 0, w, h);

  /* 透視変換行列の設定 */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);

  /* モデルビュー変換行列の設定 */
  glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
      /* アニメーション開始 */
      glutIdleFunc(idle);
      x=r;
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
//        x=x+1;
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
    //cvの終了
    cvDestroyWindow ("Image");
    cvReleaseImage (&img);
    //判定
    if ((x>10)&&(x<30)) {
      printf("You win!/n");
    }else{
      printf("You lose!\n");
    };
    exit(0);
  default:
    break;
  }
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
}

int
main (int argc, char *argv[])
{
  unsigned char c;

  //アスキーアート？(そんなことするならなんか画像表示)
  printf("AAAAA\n");
  printf("  A  \n");
  printf("AAAAA\n");
  //ランダムな配置
  int p_x = 20;
  int p_y = 40;
  //これは仮の値です

  //ターゲットの表示
  glutInitWindowPosition(1000, 100);
  glutInitWindowSize(500, 500);
  glutInit(&argc, argv);
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  //WinID[0] = glutCreateWindow("Window 1");
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display0);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard2);
  init();
  //printf("%d", x);
  glutMainLoop();
  /*glutInitWindowPosition (1000, 100);
  glutInitWindowSize (500, 500);
  glutInit(&argc, argv);
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
  //glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow (argv[0]);
  //init ();
  glutDisplayFunc(display1);
  glutReshapeFunc(resize);
  //glutReshapeFunc(reshape2);
  glutKeyboardFunc(keyboard2);
  glutMainLoop();
*/
  //以下トラックバー
  //unsigned char c;
  // (1)画像領域を確保し，初期化する
  img = cvCreateImage (cvSize (400, 200), IPL_DEPTH_8U, 3);
  cvZero (img);
  cvInitFont (&font, CV_FONT_HERSHEY_DUPLEX, 1.0, 1.0,0,1.0,8.0);
  // (2)ウィンドウ，およびトラックバーを作成する
  cvNamedWindow ("Image", CV_WINDOW_AUTOSIZE);
  cvCreateTrackbar ("Trackbar_x", "Image", 0, 50, on_trackbar1);
  cvCreateTrackbar ("Trackbar_y", "Image", 0, 100, on_trackbar2);
  cvShowImage ("Image", img);
  cvWaitKey (0);

  //トラックバーの値はメモっておいて、トラックバー終了する
  while (1) {
    c = cvWaitKey(2) & 0xff;
    if (c == '\x1b')//ESC
      break;
  }

  cvDestroyWindow ("Image");
  cvReleaseImage (&img);

  //結果アニメーション
  glutInitWindowPosition(1000, 100);
  glutInitWindowSize(500, 500);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  //WinID[0] = glutCreateWindow("Window 1");
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display1);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  init();
  //printf("%d", x);
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
