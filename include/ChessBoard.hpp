#include <iostream>
#include <GL/glut.h>
#include "Piece.hpp"

#define EMPTY 0
#define P 1
#define R 2
#define KN 3
#define B 4
#define Q 5
#define K 6
#define squareSize 50
#define windowHeight 600
#define windowWidth 600

namespace Chess
{
    class ChessBoard
    {
    public:
        Piece *chessBoard[8][8];
        bool isPieceSelected = false;

        ChessBoard()
        {

            int initialBoard[8][8] = {{R, KN, B, Q, K, B, KN, R},
                                      {P, P, P, P, P, P, P, P},
                                      {0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0},
                                      {-P, -P, -P, -P, -P, -P, -P, -P},
                                      {-R, -KN, -B, -Q, -K, -B, -KN, -R}};

            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    int pieceKey = initialBoard[y][x];
                    Colour c = pieceKey < 0 ? Colour::black : Colour::white;
                    switch (abs(pieceKey))
                    {
                    case R:
                        chessBoard[x][y] = new Rook(x * squareSize, y * squareSize, c);
                        break;
                    case KN:
                        chessBoard[x][y] = new Knight(x * squareSize, y * squareSize, c);
                        break;
                    case B:
                        chessBoard[x][y] = new Bishop(x * squareSize, y * squareSize, c);
                        break;
                    case Q:
                        chessBoard[x][y] = new Queen(x * squareSize, y * squareSize, c);
                        break;
                    case K:
                        chessBoard[x][y] = new King(x * squareSize, y * squareSize, c);
                        break;
                    case P:
                        chessBoard[x][y] = new Pawn(x * squareSize, y * squareSize, c);
                        break;
                    case EMPTY:
                        chessBoard[x][y] = new Empty(x * squareSize, y * squareSize, c);
                        break;
                    }
                }
            }
        }

        static void drawSquare(int x, int y, bool isLightSquare)
        {
            isLightSquare ? glColor3f(0.8, 0.8, 1) : glColor3f(0.4, 0.4, 0.5);
            glBegin(GL_POLYGON);
            glVertex2i(x, y);
            glVertex2i(x, y + 50);
            glVertex2i(x + 50, y + 50);
            glVertex2i(x + 50, y);
            glEnd();
        }

        void display(void)
        {
            int xCoordinate = 0, yCoordinate = 0;
            glClear(GL_COLOR_BUFFER_BIT);
            glPointSize(1.0);
            glColor3f(0.23, 0.22, 0.44);
            for (int rank = 0; rank <= 7; ++rank)
            {

                for (int file = 0; file <= 7; ++file)
                {
                    if (rank % 2)
                    {
                        (file % 2) ? drawSquare(xCoordinate, yCoordinate, 0) : drawSquare(xCoordinate, yCoordinate, 1);
                    }
                    else
                    {
                        (file % 2) ? drawSquare(xCoordinate, yCoordinate, 1) : drawSquare(xCoordinate, yCoordinate, 0);
                    }
                    chessBoard[file][rank]->Draw();
                    xCoordinate += squareSize;
                }
                yCoordinate += squareSize;
                xCoordinate = 0;
            }

            glFlush();
        }

        void mouse(int button, int state, int mouseX, int mouseY)
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                mouseY = windowHeight - mouseY;

                for (int x = 0; x < 8; x++)
                {
                    for (int y = 0; y < 8; y++)
                    {
                        chessBoard[x][y]->setIsSelected(false);
                        if ((mouseX > (x * squareSize )) && (mouseX < (x * squareSize + squareSize/2 )) && (mouseY > (y * squareSize )) && (mouseY < (y * squareSize + squareSize/2 )))
                        {
                            isPieceSelected = true;
                            chessBoard[x][y]->setIsSelected(true);                            
                            chessBoard[x][y]->Draw();
                        }
                    }
                }
            }            
        }

        static void mouseCallback(int button, int state, int mouseX, int mouseY)
        {
            currentBoard->mouse(button, state, mouseX, mouseY);
        }

        static void drawCallback()
        {
            currentBoard->display();
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

            currentBoard = this;
            glutDisplayFunc(drawCallback);
            glutMouseFunc(mouseCallback);
            glutMainLoop();
        }

    private:
        inline static ChessBoard *currentBoard;
    };
}