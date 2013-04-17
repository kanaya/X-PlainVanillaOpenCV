/*
 * This code is based on http://opencv.jp/sample/video_io.html
 *
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <ctype.h>

int main (int argc, char **argv) {
  CvCapture *capture = 0;
  IplImage *frame = 0;
  double w = 320, h = 240;
  int c;

  if (argc == 1 || (argc == 2 && strlen (argv[1]) == 1 && isdigit (argv[1][0]))) {
    capture = cvCreateCameraCapture (argc == 2 ? argv[1][0] - '0' : 0);
  }

  cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_WIDTH, w);
  cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_HEIGHT, h);

  cvNamedWindow ("Capture", CV_WINDOW_AUTOSIZE);

  while (1) {
    frame = cvQueryFrame (capture);
    cvShowImage ("Capture", frame);
    c = cvWaitKey (2);
    if (c == '\x1b') {
      break;
    }
  }

  cvReleaseCapture (&capture);
  cvDestroyWindow ("Capture");

  return 0;
}
