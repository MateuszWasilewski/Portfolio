This folder contains my original backpropagation project written in early 2019.
It typically results in model accuracy 65-75% but accuracy decreases with too many iterations.

File run.sh shall be modified to compile and run subprograms which are desired.

In my opinion there are various problems with this program which will be adressed in the next version.

Main Program is controlled by commenting or adding desired functionalities in main function. 
Main Program requires .txt files generated by programs: generate_weights, original_to_txt, which shall be placed in special subdirectories.

Both main program and gen_weights have standard layer sizes implemented seperately as consts but they can be modified and program should work as well (not tested).
Sadly program takes a long time to run (15-30 min for 1 generation), at least from my experience.
Variable rate dictates learning rate of the program and is selected somewhat at random.

