#include <cv.h>
#include <highgui.h>
#include <stdio.h>

//xyをトラックバーで指定して画面に数字で出すプログラム
//サンプルのサイトからもらってきて改変

/* グローバル変数 */
CvFont font;
IplImage *img = 0;

/* プロトタイプ宣言 */
void on_trackbar1 (int val);
void on_trackbar2 (int val);

int
main (int argc, char *argv[])
{
  // (1)画像領域を確保し，初期化する
  img = cvCreateImage (cvSize (400, 200), IPL_DEPTH_8U, 3);
  cvZero (img);
  cvInitFont (&font, CV_FONT_HERSHEY_DUPLEX, 1.0, 1.0,0,1.0,8.0);

  // (2)ウィンドウ，およびトラックバーを作成する
  cvNamedWindow ("Image", CV_WINDOW_AUTOSIZE);
  cvCreateTrackbar ("Trackbar_x", "Image", 0, 100, on_trackbar1);
  cvCreateTrackbar ("Trackbar_y", "Image", 0, 100, on_trackbar2);
  cvShowImage ("Image", img);
  cvWaitKey (0);

  cvDestroyWindow ("Image");
  cvReleaseImage (&img);

  return 0;
}

/* コールバック関数 */
void
on_trackbar1 (int val)
{
  char str[64];

  // (3)トラックバー2を，トラックバー1に同期させる
//  cvSetTrackbarPos ("Trackbar_y", "Image", val);

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

  // (4)トラックバー2の値を描画する
  cvRectangle (img, cvPoint (0, 50), cvPoint (400, 100), cvScalar (0,0,0,0), CV_FILLED,8,0);
  snprintf (str, 64, "%d", val);
  cvPutText (img, str, cvPoint (15, 80), &font, CV_RGB (200, 200, 0));
  cvShowImage ("Image", img);

}
