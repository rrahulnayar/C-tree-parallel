CILK_NWORKER=1 ./othello-parallel > temp_parallel_num1
CILK_NWORKER=2 ./othello-parallel > temp_parallel_num2
CILK_NWORKER=4 ./othello-parallel > temp_parallel_num3
CILK_NWORKER=8 ./othello-parallel > temp_parallel_num4
CILK_NWORKER=16 ./othello-parallel > temp_parallel_num5
