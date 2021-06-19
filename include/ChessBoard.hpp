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
            wPawn1 = Pawn(0, 50, Colour::white);
            wPawn2 = Pawn(50, 50, Colour::white);
            wPawn3 = Pawn(100, 50, Colour::white);
            wPawn4 = Pawn(150, 50, Colour::white);
            wPawn5 = Pawn(200, 50, Colour::white);
            wPawn6 = Pawn(250, 50, Colour::white);
            wPawn7 = Pawn(300, 50, Colour::white);
            wPawn8 = Pawn(350, 50, Colour::white);
            wRook1 = Rook(0, 0, Colour::white);
            wRook2 = Rook(350, 0, Colour::white);
            wKnight1 = Knight(50, 0, Colour::white);
            wKnight2 = Knight(300, 0, Colour::white);
            wBishop1 = Bishop(100, 0, Colour::white);
            wBishop2 = Bishop(250, 0, Colour::white);
            wQueen = Queen(150, 0, Colour::white);
            wKing = King(200, 0, Colour::white);

            bPawn1 = Pawn(0, 300, Colour::black);
            bPawn2 = Pawn(50, 300, Colour::black);
            bPawn3 = Pawn(100, 300, Colour::black);
            bPawn4 = Pawn(150, 300, Colour::black);
            bPawn5 = Pawn(200, 300, Colour::black);
            bPawn6 = Pawn(250, 300, Colour::black);
            bPawn7 = Pawn(300, 300, Colour::black);
            bPawn8 = Pawn(350, 300, Colour::black);
            bRook1 = Rook(0, 350, Colour::black);
            bRook2 = Rook(350, 350, Colour::black);
            bKnight1 = Knight(50, 350, Colour::black);
            bKnight2 = Knight(300, 350, Colour::black);
            bBishop1 = Bishop(100, 350, Colour::black);
            bBishop2 = Bishop(250, 350, Colour::black);
            bQueen = Queen(150, 350, Colour::black);
            bKing = King(200, 350, Colour::black);
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

            bPawn1.Draw();
            bPawn2.Draw();
            bPawn3.Draw();
            bPawn4.Draw();
            bPawn5.Draw();
            bPawn6.Draw();
            bPawn7.Draw();
            bPawn8.Draw();
            bRook1.Draw();
            bRook2.Draw();
            bKnight1.Draw();
            bKnight2.Draw();
            bBishop1.Draw();
            bBishop2.Draw();
            bQueen.Draw();
            bKing.Draw();
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
        Rook bRook1, bRook2;
        Knight bKnight1, bKnight2;
        Bishop bBishop1, bBishop2;
        King bKing;
        Queen bQueen;
    };
}