all:  tyokudou2

#OPENCV_CFLAGS = `pkg-config opencv-2.3.1 --cflags`
#OPENCV_LIBS   = `pkg-config opencv-2.3.1 --libs`
OPENCV_CFLAGS = `pkg-config opencv --cflags`
OPENCV_LIBS   = `pkg-config opencv --libs`
GLUT_CFLAGS = `pkg-config gl --cflags` `pkg-config glu --cflags`
GLUT_LIBS   = `pkg-config gl --libs` `pkg-config glu --libs` -lglut

#xy: xy.c
#	gcc -o $@ $< ${OPENCV_CFLAGS} ${OPENCV_LIBS}
tyokudou2: tyokudou2.c
	gcc -o $@ $< ${OPENCV_CFLAGS} ${OPENCV_LIBS} ${GLUT_CFLAGS} ${GLUT_LIBS}

	
