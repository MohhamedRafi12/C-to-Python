# C-to-Python

Various examples and short exercises on bridging Python and compiled code
  
# PROJECT 2 
Python baseline was 29s
C Shared lib was 2.46s
Python MC lib was 1.53s

We are only measuing the wall time since that what timeit -r1 -n1 measures as well. 

The speed up mostly occurs with the memory chunking (making sections of the monte carlo box) and the vectorized numpy arrays. 
We are generating up to a certain amount of the grid to being with at once instead of processing each point. We are also now avoiding 
using the sqrt since that would increase time.