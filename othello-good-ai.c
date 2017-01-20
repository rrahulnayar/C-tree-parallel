#include <stdlib.h>
#include <stdio.h>

#include "othello.h"

#define DEPTH 5

#define NEG_infinite -9043908423094

int GoodAITurn(Board *b, int color)
{

  Board legal_moves;
  int num_moves = EnumerateLegalMoves(*b, color, &legal_moves);
  Board copy_b=*b;
  int *a;
  int *b_a;
  int max=0;
  int min_num=0;
  
  
  

  if(num_moves>0)

  {
	a = (int *)calloc(num_moves,sizeof(int));
	b_a=a;
  	for( int each=0;each<num_moves;each++){
			

		    ull moves = legal_moves.disks[color];
		    // clz returns the bit number of the first bit set counting from the msb
		    int highestBit = __builtin_clzll(moves);
		    for (int i=0; i<each; i++) {
		      // Remove the highest bit from possible moves
		      moves -= ((ull)1) << (63-highestBit);
		      // Get the next highest bit
		      highestBit = __builtin_clzll(moves);
		    }
		    Move m = BIT_TO_MOVE(highestBit);
		    // Set the third parameter to 1 to echo disks flipped
		    int nflips = FlipDisks(m, &copy_b,color, 0, 1);
		    if (nflips == 0) {
		        printf("Illegal move: no disks flipped!!\n");
		    }
		    PlaceOrFlip(m, &copy_b, color);
		    //PrintBoard(*b);
		    a[each]=getScoreBoard(&copy_b,color,1);
                     


	}
       
        max=*b_a;
        for( int k=1;k<num_moves;k++){
		if(max<a[k])
		{ max=a[k]; min_num=k;}

        }


	ull moves1 = legal_moves.disks[color];
	// clz returns the bit number of the first bit set counting from the msb
	int highestBit1 = __builtin_clzll(moves1);
	for (int i=0; i<min_num; i++) {
	  // Remove the highest bit from possible moves
	  moves1 -= ((ull)1) << (63-highestBit1);
	  // Get the next highest bit
	  highestBit1 = __builtin_clzll(moves1);
	}
	Move m1 = BIT_TO_MOVE(highestBit1);
	// Set the third parameter to 1 to echo disks flipped
	int nflips1 = FlipDisks(m1, b,color, 0, 1);
	if (nflips1 == 0) {
	    printf("Illegal move: no disks flipped!!\n");
	}
	PlaceOrFlip(m1, b, color);
        //printf("printing ouput from GoodAI\n");
        //PrintBoard(*b);
        return 1;


        
  

  }
  return 0;
}

int getScoreBoard(Board *b, int color,int depth)
{

  Board legal_moves;
  int num_moves = EnumerateLegalMoves(*b, color, &legal_moves);
  Board copy_b=*b;
  int *a,*b_a;
  int max,min_num;
  if (num_moves > 0 || depth< DEPTH) {
  	a = (int *)calloc(num_moves,sizeof(int));
  	b_a=a;

  for( int each=0;each<num_moves;each++){
			

		    ull moves = legal_moves.disks[color];
		    // clz returns the bit number of the first bit set counting from the msb
		    int highestBit = __builtin_clzll(moves);
		    for (int i=0; i<each; i++) {
		      // Remove the highest bit from possible moves
		      moves -= ((ull)1) << (63-highestBit);
		      // Get the next highest bit
		      highestBit = __builtin_clzll(moves);
		    }
		    Move m = BIT_TO_MOVE(highestBit);
		    // Set the third parameter to 1 to echo disks flipped
		    int nflips = FlipDisks(m, &copy_b,color, 0, 1);
		    if (nflips == 0) {
		        printf("Illegal move: no disks flipped!!\n");
		    }
		    PlaceOrFlip(m, &copy_b, color);
		    //PrintBoard(*b);
		    a[each]=getScoreBoard(&copy_b,~color,depth++);
                    
 }
 
  max=*b_a;
  for(int k=1;k<num_moves;k++)
  {
	if(max<a[k])
	max=a[k];


  }
  if(NEG_infinite>(-1*max))
  return NEG_infinite;
  else
  return (-1*max);
  






  } else  return CountBitsOnBoard(b,color);

}
