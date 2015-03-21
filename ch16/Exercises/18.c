#include <stdio.h>

typedef enum {EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING} Piece;

typedef enum {WHITE, BLACK} Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

Square board[8][8] = {
    {{ROOK,  BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING,  BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK,  BLACK}},
    {{PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK}, {PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE}, {PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE}},
    {{ROOK,  WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN,  WHITE}, {KING, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK,  WHITE}},
};


int main(void)
{
    int row, col;
    /* Print piece numbers */
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            printf("%d ", board[row][col].piece);
        }
        printf("\n");
    }
    printf("\n");
    /* Print piece colors */
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            printf("%d ", board[row][col].color);
        }
        printf("\n");
    }
}
