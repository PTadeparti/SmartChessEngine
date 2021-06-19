#include <iostream>
#include <GL/glut.h>

class ChessBoard
{
public:
    static void drawBlack(int x, int y)
    {
        glBegin(GL_POLYGON);
        glVertex2i(x, y);
        glVertex2i(x, y + 50);
        glVertex2i(x + 50, y + 50);
        glVertex2i(x + 50, y);
        glEnd();
    }
    static void drawWhite(int x, int y)
    {
        glBegin(GL_LINE_LOOP);
        glVertex2i(x, y);
        glVertex2i(x, y + 50);
        glVertex2i(x + 50, y + 50);
        glVertex2i(x + 50, y);
        glEnd();
    }

    static void display(void)
    {
        int xCoordinate = 50, yCoordinate = 50;
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(1.0);

        for (int rank = 0; rank <= 7; ++rank)
        {

            for (int file = 0; file <= 7; ++file)
            {
                if (rank % 2)
                {
                    (file % 2) ? drawWhite(xCoordinate, yCoordinate) : drawBlack(xCoordinate, yCoordinate);
                }
                else
                {
                    (file % 2) ? drawBlack(xCoordinate, yCoordinate) : drawWhite(xCoordinate, yCoordinate);
                }
                xCoordinate += 50;
            }
            yCoordinate += 50;
            xCoordinate = 50;
        }

        glFlush();
    }

    void DrawChessBoard(int *argcp, char **argv, bool isWhite)
    {
        glutInit(argcp, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

        glutInitWindowPosition(100, 100);
        glutInitWindowSize(600, 600);
        glutCreateWindow("Chess");

        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 640.0, 0.0, 640.0);
        glutDisplayFunc(display);
        glutMainLoop();      
    }

private:
};