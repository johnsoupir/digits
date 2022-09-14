![image](https://user-images.githubusercontent.com/50882613/190225781-9598c93f-0674-409a-8d10-be7f3c7d7919.png)

# Digits
A cool little C program to count the occerances of every digit from zero to your chosen number. 
This program was written with speed in mind. On my laptop it will run to 1 million in about 2 seconds.
Graphing the results in GNUPlot produces an interesting pattern. 

## Usage
Complie with: ```gcc digits.c -o digits```

Run with: ```./digits <end-number>```

Output is saved in a file, and is of the form: 

```<current number> <zeros in current> <zeros running total> <ones in current> <ones running total> ... <nines in current> <nines running total>``` 
  
  
### Cool video
  A video of the results in an animated GNUPlot:
  https://youtu.be/xAPqNJ5Vm3Q
