#include <iostream>
#include "ChessBoard.hpp"
using namespace Chess;


int main(int argc, char** argv)
{    
    auto Board = ChessBoard();
    Board.DrawChessBoard(&argc,argv,true);
}

