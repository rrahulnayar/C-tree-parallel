#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "othello.h"

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
#define DEPTH 2

int minimax(Board *b, int depth, int color) {
	// if node is a terminal node or depth <= 0: return the heuristic value of node
	if (depth <= 0) {
		return CountBitsOnBoard(b, color);
	}
	Board legal_moves;
	int num_moves = EnumerateLegalMoves(*b, color, &legal_moves);
	//printf("depth = %d\n", depth);
	//printf("b.disks[X_BLACK] = 0x%16llx\n", (*b).disks[X_BLACK]);
	//printf("b.disks[O_WHITE] = 0x%16llx\n", (*b).disks[O_WHITE]);
	//printf("legal_moves      = 0x%16llx, num_moves = %d\n", legal_moves.disks[color], num_moves);
	// α = -∞
	int bestValue = color == O_WHITE ? INT_MIN : INT_MAX;
	// for child in node:                       # evaluation is identical for both players
	int moveIndex;
	int minimaxValue[num_moves];
	int minimaxMove[num_moves];
	Board copiesOfBoard[num_moves];
	for (moveIndex = 0; moveIndex < num_moves; ++moveIndex) {
		ull temp = ((ull)1) << (63-__builtin_clzll(legal_moves.disks[color]));
		minimaxMove[moveIndex] = __builtin_clzll(legal_moves.disks[color]);
		legal_moves.disks[color] -= temp;
		copiesOfBoard[moveIndex].disks[color] = (*b).disks[color] + temp;
		copiesOfBoard[moveIndex].disks[OTHERCOLOR(color)] = (*b).disks[OTHERCOLOR(color)];
		minimaxValue[moveIndex] = minimax(&copiesOfBoard[moveIndex], depth - 1, OTHERCOLOR(color));
	}
	;
	// if depth == DEPTH: do flip with best move
	if (depth == DEPTH) {
		int bestMove = -1;
		for (moveIndex = 0; moveIndex < num_moves; ++moveIndex) {
			if (bestMove < 0 || minimaxValue[moveIndex] > bestValue) {
				bestValue = minimaxValue[moveIndex];
				bestMove = minimaxMove[moveIndex];
			}
		}
		if (num_moves > 0 && bestMove >= 0) {
			Move m = BIT_TO_MOVE(bestMove);
			int nflips = FlipDisks(m, b, color, 0, 1);
			if (nflips == 0) {
				printf("Illegal move: no disks flipped!!\n");
			}
			PlaceOrFlip(m, b, color);
			return 1;
		} else {
			return 0;
		}
	// else use heuristic to recursively return bestValue
	} else {
		for (moveIndex = 0; moveIndex < num_moves; ++moveIndex) {
			// α = max(α, -minimax(child, depth-1))
			bestValue = color == O_WHITE ? max(bestValue, minimaxValue[moveIndex]) : min(bestValue, minimaxValue[moveIndex]);
		}
		// return α
		return bestValue; 
	}
}

int GoodAITurn(Board *b, int color)
{
	// Put your code for minimax here
	// just call minimax
	// minimax handles the flip by checking whether depth == DEPTH
	return minimax(b, DEPTH, color); 
}
