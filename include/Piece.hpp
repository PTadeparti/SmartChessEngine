#include <iostream>
namespace Chess
{
    void drawRectangle(int, int, int, int);
    void drawTriangle(int, int, int, int);
    void drawCircle(int, int, int);
    enum Colour
    {
        white = 0,
        black = 1
    };

    class Piece
    {

    public:
        virtual void Draw() = 0;
        virtual void Move(int, int, int, int) = 0;

        Piece(Colour colour)
        {
            this->colour = colour;
        }

        Piece(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        Piece()
        {
            colour = Colour::white;
        }

        int getColour()
        {
            return colour;
        }

        void setColour(Colour value)
        {
            colour = value;
        }

        int getX()
        {
            return x;
        }

        void setX(int value)
        {
            x = value;
        }

        int getY()
        {
            return y;
        }

        void setY(int value)
        {
            y = value;
        }

    protected:
        Colour colour;
        int x, y;
    };

    class Pawn : public Piece
    {
    public:
        Pawn(int x, int y)
        {

            setX(x);
            setY(y);
        }

        Pawn()
        {
            setX(0);
            setY(0);
        }

        void Draw()
        {
            glColor3f(1, 1, 1);
            drawTriangle(getX() + 10, getY() + 10, getX() + 40, getY() + 30);
            drawCircle(getX() + 25, getY() + 35, 10);
        }

        void Move(int xCurrent, int yCurrent, int xNext, int yNext)
        {
        }

    private:
    };

    class Rook : public Piece
    {
    public:
        Rook(int x, int y)
        {

            setX(x);
            setY(y);
        }

        Rook()
        {
            setX(0);
            setY(0);
        }

        void Draw()
        {
            drawRectangle(getX() + 15, getY() + 10, getX() + 35, getY() + 35);
            drawRectangle(getX() + 10, getY() + 35, getX() + 40, getY() + 45);
        }

        void Move(int xCurrent, int yCurrent, int xNext, int yNext)
        {
        }

    private:
    };

    class Knight : public Piece
    {
    public:
        Knight(int x, int y)
        {

            setX(x);
            setY(y);
        }

        Knight()
        {
            setX(0);
            setY(0);
        }

        void Draw()
        {
            drawRectangle(getX() + 10, getY() + 10, getX() + 18, getY() + 35);
            drawRectangle(getX() + 10, getY() + 35, getX() + 35, getY() + 40);
            drawTriangle(getX() + 25, getY() + 40, getX() + 40, getY() + 20);
        }

        void Move(int xCurrent, int yCurrent, int xNext, int yNext)
        {
        }

    private:
    };

    class Bishop : public Piece
    {
    public:
        Bishop(int x, int y)
        {

            setX(x);
            setY(y);
        }

        Bishop()
        {
            setX(0);
            setY(0);
        }

        void Draw()
        {
            glColor3f(1, 1, 1);
            drawRectangle(getX() + 10, getY() + 10, getX() + 40, getY() + 13);
            drawRectangle(getX() + 20, getY() + 13, getX() + 30, getY() + 32);
            drawTriangle(getX() + 15, getY() + 32, getX() + 35, getY() + 40);
            
        }

        void Move(int xCurrent, int yCurrent, int xNext, int yNext)
        {
        }

    private:
    };

    class Queen : public Piece
    {
    public:
        Queen(int x, int y)
        {

            setX(x);
            setY(y);
        }

        Queen()
        {
            setX(0);
            setY(0);
        }

        void Draw()
        {
            glColor3f(1, 1, 1);
            drawRectangle(getX() + 8, getY() + 10, getX() + 42, getY() + 30);            
            drawTriangle(getX() + 10, getY() + 30, getX() + 20, getY() + 43);
            drawTriangle(getX() + 20, getY() + 30, getX() + 30, getY() + 43);
            drawTriangle(getX() + 30, getY() + 30, getX() + 40, getY() + 43);
            
        }

        void Move(int xCurrent, int yCurrent, int xNext, int yNext)
        {
        }

    private:
    };

    class King : public Piece
    {
    public:
        King(int x, int y)
        {

            setX(x);
            setY(y);
        }

        King()
        {
            setX(0);
            setY(0);
        }

        void Draw()
        {
            glColor3f(1, 1, 1);
            drawRectangle(getX() + 10, getY() + 10, getX() + 40, getY() + 15);
            drawRectangle(getX() + 18, getY() + 15, getX() + 32, getY() + 30);
            drawRectangle(getX() + 23, getY() + 30, getX() + 27, getY() + 45);
            drawRectangle(getX() + 20, getY() + 38, getX() + 30, getY() + 42);            
        }

        void Move(int xCurrent, int yCurrent, int xNext, int yNext)
        {
        }

    private:
    };

    void drawRectangle(int x1, int y1, int x2, int y2)
    {
        glBegin(GL_POLYGON);
        glVertex2i(x1, y1);
        glVertex2i(x1, y2);
        glVertex2i(x2, y2);
        glVertex2i(x2, y1);
        glEnd();
    }

    void drawCircle(int x, int y, int r)
    {        
        glPointSize(r);
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }

    void drawTriangle(int x1, int y1, int x2, int y2)
    {
        glBegin(GL_POLYGON);
        glVertex2i(x1, y1);
        glVertex2i((x1 + x2) / 2, y2);
        glVertex2i(x2, y1);
        glEnd();
    }
}