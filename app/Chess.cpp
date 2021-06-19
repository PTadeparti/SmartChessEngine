#include <iostream>
#include "ChessBoard.hpp"


int main(int argc, char** argv)
{
    auto Board = ChessBoard();
    Board.DrawChessBoard(&argc,argv,true);
}

