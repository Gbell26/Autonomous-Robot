# Autonomous-Robot
Autonomous Robot that navigates using ultrasonic sensor and an artificial neural network to change directions

![IMG_0103](https://github.com/Gbell26/Autonomous-Robot/assets/107581827/7fc93290-16ee-42d0-881b-dd0be86db63b)

![IMG_0102](https://github.com/Gbell26/Autonomous-Robot/assets/107581827/589df0e4-c29f-4b3b-b168-8e7b2916bcb5)

Neural networked tested with XOR truth table, then trained with distances
example outputs from NN:

Arduino NN XOR outputs:
  Training Pattern: 0
  Input 1 1   Target 0   Output 0.00735 
  Training Pattern: 1
  Input 0 1   Target 1   Output 0.99400 
  Training Pattern: 2
  Input 0 0   Target 0   Output 0.00530 
  Training Pattern: 3
  Input 1 0   Target 1   Output 0.99399 
  Training Pattern: 4
  Input 0 0   Target 0   Output 0.00530 
  Training Pattern: 5
  Input 1 0   Target 1   Output 0.99399 
  Training Pattern: 6
  Input 0 1   Target 1   Output 0.99400 
  Training Pattern: 7
  Input 1 1   Target 0   Output 0.00735 
  Training Pattern: 8
  Input 0 0   Target 0   Output 0.00530 
  Training Pattern: 9
  Input 0 1   Target 1   Output 0.99400 
  Training Pattern: 10
  Input 1 0   Target 1   Output 0.99399 
  Training Pattern: 11
  Input 0 0   Target 0   Output 0.00530 
  Training Pattern: 12
  Input 1 1   Target 0   Output 0.00735 
  Training Pattern: 13
  Input 0 0   Target 0   Output 0.00530 
  Training Pattern: 14
  Input 0 1   Target 1   Output 0.99400 
  Training Pattern: 15
  Input 1 0   Target 1   Output 0.99399 
  Training Pattern: 16
  Input 1 1   Target 0   Output 0.00735 
  Training Pattern: 17
  Input 0 1   Target 1   Output 0.99400 
  Training Pattern: 18
  Input 1 0   Target 1   Output 0.99399 
  Training Pattern: 19
  Input 0 0   Target 0   Output 0.00530 
  Training Pattern: 20
  Input 1 1   Target 0   Output 0.00735





trained on distances:

Training Pattern: 0
  Input 74.0000000000 112.0000000000   Target 1   Output 1.00000 
  Training Pattern: 1
  Input 103.0000000000 36.0000000000   Target 0   Output 0.00000 
  Training Pattern: 2
  Input 80.0000000000 73.0000000000   Target 0   Output 0.23420 
  Training Pattern: 3
  Input 52.0000000000 84.0000000000   Target 1   Output 1.00000 
  Training Pattern: 4
  Input 100.0000000000 31.0000000000   Target 0   Output 0.00000 
  Training Pattern: 5
  Input 68.0000000000 44.0000000000   Target 0   Output 0.00003 
  Training Pattern: 6
  Input 89.0000000000 90.0000000000   Target 1   Output 0.97848 
  Training Pattern: 7
  Input 59.0000000000 25.0000000000   Target 0   Output 0.00000 
  Training Pattern: 8
  Input 97.0000000000 104.0000000000   Target 1   Output 0.99939 
  Training Pattern: 9
  Input 24.0000000000 13.0000000000   Target 0   Output 0.01996 
  Training Pattern: 10
  Input 24.0000000000 94.0000000000   Target 1   Output 1.00000 
  Training Pattern: 11
  Input 88.0000000000 91.0000000000   Target 1   Output 0.99345 
  Training Pattern: 12
  Input 94.0000000000 39.0000000000   Target 0   Output 0.00000 
  Training Pattern: 13
  Input 62.0000000000 26.0000000000   Target 0   Output 0.00000 
  Training Pattern: 14
  Input 91.0000000000 67.0000000000   Target 0   Output 0.00004 
  Training Pattern: 15
  Input 105.0000000000 27.0000000000   Target 0   Output 0.00000 
Training Pattern: 16
  Input 85.0000000000 58.0000000000   Target 0   Output 0.00001 
  Training Pattern: 17
  Input 22.0000000000 37.0000000000   Target 1   Output 0.99999 
  Training Pattern: 18
  Input 65.0000000000 43.0000000000   Target 0   Output 0.00008 
  Training Pattern: 19
  Input 78.0000000000 65.0000000000   Target 0   Output 0.00846 
  Training Pattern: 20
  Input 47.0000000000 40.0000000000   Target 0   Output 0.20267 
  Training Pattern: 21
  Input 55.0000000000 45.0000000000   Target 0   Output 0.04156 
  Training Pattern: 22
  Input 60.0000000000 73.0000000000   Target 1   Output 0.99997 
  Training Pattern: 23
  Input 54.0000000000 90.0000000000   Target 1   Output 1.00000 
  Training Pattern: 24
  Input 78.0000000000 68.0000000000   Target 0   Output 0.04683 
  Training Pattern: 25
  Input 12.0000000000 40.0000000000   Target 1   Output 1.00000 
  Training Pattern: 26
  Input 5.0000000000 54.0000000000   Target 1   Output 1.00000 
  Training Pattern: 27
  Input 7.0000000000 59.0000000000   Target 1   Output 1.00000 
  Training Pattern: 28
  Input 46.0000000000 47.0000000000   Target 1   Output 0.97279 
  Training Pattern: 29
  Input 39.0000000000 10.0000000000   Target 0   Output 0.00000 
  Training Pattern: 30
  Input 24.0000000000 36.0000000000   Target 1   Output 0.99994 
  Training Pattern: 31
  Input 83.0000000000 59.0000000000   Target 0   Output 0.00003 
  Training Pattern: 32
  Input 94.0000000000 102.0000000000   Target 1   Output 0.99964 
Training Pattern: 33
  Input 6.0000000000 10.0000000000   Target 1   Output 0.99436 
  Training Pattern: 34
  Input 0.0000000000 40.0000000000   Target 1   Output 1.00000 
  Training Pattern: 35
  Input 16.0000000000 69.0000000000   Target 1   Output 1.00000 
  Training Pattern: 36
  Input 43.0000000000 55.0000000000   Target 1   Output 0.99995 
  Training Pattern: 37
  Input 64.0000000000 31.0000000000   Target 0   Output 0.00000 
  Training Pattern: 38
  Input 86.0000000000 90.0000000000   Target 1   Output 0.99634 
  Training Pattern: 39
  Input 20.0000000000 23.0000000000   Target 1   Output 0.99052 87


actual outputs from getResults function:
//inputs 
43 //left
143 //right
//output
1.00 // turn right

//inputs
3 // left 
42 // right
//output
1.00 // turn right

//inputs
40 //left
42 //right
//output
0.98 // turn right

//inputs
40 // left
10 //right
//output
0.00 // turn left

resources used to write neural network:
http://robotics.hobbizine.com/arduinoann.html
https://www.cs.bham.ac.uk//~jxb/INC/nn.html
https://www.the-diy-life.com/running-an-artificial-neural-network-on-an-arduino-uno/
https://www.coursera.org/learn/neural-networks-deep-learning
