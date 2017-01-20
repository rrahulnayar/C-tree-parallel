
CC = icpc
#CC_FLAGS = -std=c99

ifeq ($(DEBUG), 1)
	CC_FLAGS += -g
else
	CC_FLAGS += -O2
endif

all: othello-serial othello-parallel othello-serial_def1 othello-serial_def2 othello-serial_def3 othello-serial_def4 othello-serial_def5 othello-parallel_def1 othello-parallel_def2 othello-parallel_def3 othello-parallel_def4 othello-parallel_def5

clean:
	rm -f othello-serial othello-parallel othello-serial_def1 othello-serial_def2 othello-serial_def3 othello-serial_def4 othello-serial_def5 othello-parallel_def1 othello-parallel_def2 othello-parallel_def3 othello-parallel_def4 othello-parallel_def5

othello-serial: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai.c -o othello-serial #-cilk-serialize

othello-parallel: hwtimer.h othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_parallel.c -o othello-parallel

othello-serial_def1: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_def1.c -o othello-serial_def1 #-cilk-serialize

othello-serial_def2: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_def2.c -o othello-serial_def2 #-cilk-serialize

othello-serial_def3: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_def3.c -o othello-serial_def3 #-cilk-serialize

othello-serial_def4: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_def4.c -o othello-serial_def4 #-cilk-serialize

othello-serial_def5: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_def5.c -o othello-serial_def5 #-cilk-serialize

othello-parallel_def1: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_parallel_def1.c -o othello-parallel_def1 #-cilk-serialize

othello-parallel_def2: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_parallel_def2.c -o othello-parallel_def2 #-cilk-serialize

othello-parallel_def3: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_parallel_def3.c -o othello-parallel_def3 #-cilk-serialize

othello-parallel_def4: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_parallel_def4.c -o othello-parallel_def4 #-cilk-serialize

othello-parallel_def5: othello.c hwtimer.h othello.h othello-human.c othello-simple-ai.c othello-good-ai.c
	$(CC) $(CC_FLAGS) othello.c othello-human.c othello-simple-ai.c othello-good-ai_parallel_def5.c -o othello-parallel_def5 #-cilk-serialize

