#include <iostream>
#include <GL/glut.h>
#include "Piece.hpp"

namespace Chess
{
    class ChessBoard
    {
    public:
        ChessBoard()
        {
            wPawn1 = Pawn(0, 50);
            wPawn2 = Pawn(50, 50);
            wPawn3 = Pawn(100, 50);
            wPawn4 = Pawn(150, 50);
            wPawn5 = Pawn(200, 50);
            wPawn6 = Pawn(250, 50);
            wPawn7 = Pawn(300, 50);
            wPawn8 = Pawn(350, 50);
            wRook1 = Rook(0,0);
            wRook2 = Rook(350,0);
            wKnight1 = Knight(50,0);
            wKnight2 = Knight(300,0);
            wBishop1 = Bishop(100,0);
            wBishop2 = Bishop(250,0);
            wQueen = Queen(150,0);
            wKing = King(200,0);
            std::cout << "Constructed board. pawn: " << wPawn1.getX();
        }

        static void drawSquare(int x , int y, bool isWhiteSquare)
        {
            isWhiteSquare ? glColor3f(0.74, 0.87, 0.99) : glColor3f(0.13, 0.12, 0.24);
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
                        (file % 2) ? drawSquare(xCoordinate, yCoordinate,0) : drawSquare(xCoordinate, yCoordinate,1);
                    }
                    else
                    {
                        (file % 2) ? drawSquare(xCoordinate, yCoordinate,1) : drawSquare(xCoordinate, yCoordinate,0);
                    }

                    xCoordinate += 50;
                }
                yCoordinate += 50;
                xCoordinate = 0;
            }

            wPawn1.Draw();
            wPawn2.Draw();
            wPawn3.Draw();
            wPawn4.Draw();
            wPawn5.Draw();
            wPawn6.Draw();
            wPawn7.Draw();
            wPawn8.Draw();
            wRook1.Draw();
            wRook2.Draw();
            wKnight1.Draw();
            wKnight2.Draw();
            wBishop1.Draw();
            wBishop2.Draw();
            wQueen.Draw();
            wKing.Draw();
            glFlush();
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
            glutMainLoop();
        }

    private:
        inline static ChessBoard *currentBoard;
        Pawn wPawn1, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8;
        Rook wRook1, wRook2;
        Knight wKnight1, wKnight2;
        Bishop wBishop1, wBishop2;
        King wKing;
        Queen wQueen;
        Pawn bPawn1, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8;
    };
}