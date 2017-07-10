#include <GL/glut.h>

GLdouble vertex[][3] = {
  /* 変更なし */
};

int edge[][2] = {
  /* 変更なし */
};

void idle(void)
{
  /* 変更なし */
}

void display(void)
{
  int i;
  static int r = 0; /* 回転角 */

  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();

  /* 視点位置と視線方向 */
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /* 図形の回転 */
  glRotated((double)r, 0.0, 1.0, 0.0);

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
  if (++r >= 360) r = 0;
}

void resize(int w, int h)
{
  /* 変更なし */
}

void mouse(int button, int state, int x, int y)
{
  /* 変更なし */
}

void keyboard(unsigned char key, int x, int y)
{
  /* 変更なし */
}

void init(void)
{
  /* 変更なし */
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
  return 0;
}
