./othello-parallel_def1 >temp_parallel_def1
./othello-parallel_def2 >temp_parallel_def2
./othello-parallel_def3 >temp_parallel_def3
./othello-parallel_def4 >temp_parallel_def4
./othello-parallel_def5 >temp_parallel_def5
./othello-serial_def1 >temp_serial_def1
./othello-serial_def2 >temp_serial_def2
./othello-serial_def3 >temp_serial_def3
./othello-serial_def4 >temp_serial_def4
./othello-serial_def5 >temp_serial_def5

CILK_NWORKER=1 ./othello-parallel > temp_parallel_num1
CILK_NWORKER=2 ./othello-parallel > temp_parallel_num2
CILK_NWORKER=4 ./othello-parallel > temp_parallel_num3
CILK_NWORKER=8 ./othello-parallel > temp_parallel_num4
CILK_NWORKER=16 ./othello-parallel > temp_parallel_num5
CILK_NWORKER=32 ./othello-parallel > temp_parallel_num6
CILK_NWORKER=64 ./othello-parallel > temp_parallel_num7
CILK_NWORKER=128 ./othello-parallel > temp_parallel_num8
CILK_NWORKER=256 ./othello-parallel > temp_parallel_num9

