#include "ChessBoardPrint.hpp"

#include <iostream>

using namespace std;

ChessBoardPrint::ChessBoardPrint(ChessBoard &board)
    : board(board) {

    board.piece_moved =
        [](const ChessBoard::Piece &piece,
           const string &from,
           const string &to) {

            cout << piece.type()
                 << " is moving from "
                 << from
                 << " to "
                 << to
                 << endl;
    };

    board.piece_removed =
        [](const ChessBoard::Piece &piece,
           const string &position) {

            cout << piece.type()
                 << " is being removed from "
                 << position
                 << endl;
    };

    board.invalid_move =
        [](const ChessBoard::Piece &piece,
           const string &from,
           const string &to) {

            cout << "can not move "
                 << piece.type()
                 << " from "
                 << from
                 << " to "
                 << to
                 << endl;
    };

    board.no_piece =
        [](const string &position) {

            cout << "no piece at "
                 << position
                 << endl;
    };

    board.king_removed =
        [](ChessBoard::Color color) {

            if (color == ChessBoard::Color::WHITE)
                cout << "White lost the game" << endl;
            else
                cout << "Black lost the game" << endl;
    };

    board.after_piece_move =
        [this]() {
            print();
    };
}
void ChessBoardPrint::print() const {
    for (int y = 7; y >= 0; --y) {
        cout << y + 1 << " ";

        for (int x = 0; x < 8; ++x) {
            if (board.squares[x][y])
                cout << board.squares[x][y]->symbol() << " ";
            else
                cout << ".. ";
        }

        cout << endl;
    }

    cout << "  a  b  c  d  e  f  g  h" << endl;
}