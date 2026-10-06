#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

class ChessBoard {
public:
    enum class Color {
        WHITE,
        BLACK
    };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;

        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        virtual std::string type() const = 0;

        virtual bool valid_move(
            int from_x,
            int from_y,
            int to_x,
            int to_y
        ) const = 0;

        virtual std::string symbol() const = 0;
    };

    class King : public Piece {
    public:
        King(Color color) : Piece(color) {}

        std::string type() const override {
            return color_string() + " king";
        }

        bool valid_move(
            int from_x,
            int from_y,
            int to_x,
            int to_y
        ) const override {
            int dx = abs(to_x - from_x);
            int dy = abs(to_y - from_y);

            return dx <= 1 && dy <= 1 &&
                   (dx != 0 || dy != 0);
        }

        std::string symbol() const override {
            if (color == Color::WHITE)
                return "WK";
            else
                return "BK";
        }
    };

    class Knight : public Piece {
    public:
        Knight(Color color) : Piece(color) {}

        std::string type() const override {
            return color_string() + " knight";
        }

        bool valid_move(
            int from_x,
            int from_y,
            int to_x,
            int to_y
        ) const override {
            int dx = abs(to_x - from_x);
            int dy = abs(to_y - from_y);

            return (dx == 2 && dy == 1) ||
                   (dx == 1 && dy == 2);
        }

        std::string symbol() const override {
            if (color == Color::WHITE)
                return "WN";
            else
                return "BN";
        }
    };

    ChessBoard() {
        squares.resize(8);

        for (auto &column : squares)
            column.resize(8);
    }

    std::vector<std::vector<std::unique_ptr<Piece>>> squares;

    // Funksjonsobjekter som ChessBoardPrint skal fylle inn
    std::function<void(const Piece &, const std::string &, const std::string &)>
        piece_moved;

    std::function<void(const Piece &, const std::string &)>
        piece_removed;

    std::function<void(const Piece &, const std::string &, const std::string &)>
        invalid_move;

    std::function<void(const std::string &)>
        no_piece;

    std::function<void(Color)>
        king_removed;

    std::function<void()>
        after_piece_move;

    bool move_piece(
        const std::string &from,
        const std::string &to
    ) {
        int from_x = from[0] - 'a';
        int from_y = std::stoi(std::string() + from[1]) - 1;

        int to_x = to[0] - 'a';
        int to_y = std::stoi(std::string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];

        if (!piece_from) {
            if (no_piece)
                no_piece(from);

            return false;
        }

        if (!piece_from->valid_move(
                from_x,
                from_y,
                to_x,
                to_y
            )) {

            if (invalid_move)
                invalid_move(*piece_from, from, to);

            return false;
        }

        auto &piece_to = squares[to_x][to_y];

        if (piece_to) {
            if (piece_from->color == piece_to->color) {
                if (invalid_move)
                    invalid_move(*piece_from, from, to);

                return false;
            }

            if (piece_removed)
                piece_removed(*piece_to, to);

            if (dynamic_cast<King *>(piece_to.get())) {
                if (king_removed)
                    king_removed(piece_to->color);
            }
        }

        if (piece_moved)
            piece_moved(*piece_from, from, to);

        piece_to = std::move(piece_from);

        if (after_piece_move)
            after_piece_move();

        return true;
    }
};