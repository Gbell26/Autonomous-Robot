# Autonomous-Robot
Autonomous Robot that navigates using ultrasonic sensor and an artificial neural network to change directions

![IMG_0103](https://github.com/Gbell26/Autonomous-Robot/assets/107581827/7fc93290-16ee-42d0-881b-dd0be86db63b)

![IMG_0102](https://github.com/Gbell26/Autonomous-Robot/assets/107581827/589df0e4-c29f-4b3b-b168-8e7b2916bcb5)

Neural networked tested with XOR truth table, then trained with distances <br>
example outputs from NN:<br>
<br><br>
Arduino NN XOR outputs:<br>
  Training Pattern: 0<br>
  Input 1 1   Target 0   Output 0.00735 <br>
  Training Pattern: 1<br>
  Input 0 1   Target 1   Output 0.99400 <br>
  Training Pattern: 2<br>
  Input 0 0   Target 0   Output 0.00530<br> 
  Training Pattern: 3<br>
  Input 1 0   Target 1   Output 0.99399<br> 
  Training Pattern: 4<br>
  Input 0 0   Target 0   Output 0.00530<br> 
  Training Pattern: 5<br>
  Input 1 0   Target 1   Output 0.99399<br> 
  Training Pattern: 6<br>
  Input 0 1   Target 1   Output 0.99400<br> 
  Training Pattern: 7<br>
  Input 1 1   Target 0   Output 0.00735<br> 
  Training Pattern: 8<br>
  Input 0 0   Target 0   Output 0.00530 <br>
  Training Pattern: 9<br>
  Input 0 1   Target 1   Output 0.99400<br> 
  Training Pattern: 10<br>
  Input 1 0   Target 1   Output 0.99399 <br>
  Training Pattern: 11<br>
  Input 0 0   Target 0   Output 0.00530 <br>
  Training Pattern: 12<br>
  Input 1 1   Target 0   Output 0.00735 <br>
  Training Pattern: 13<br>
  Input 0 0   Target 0   Output 0.00530 <br>
  Training Pattern: 14<br>
  Input 0 1   Target 1   Output 0.99400 <br>
  Training Pattern: 15<br>
  Input 1 0   Target 1   Output 0.99399 <br>
  Training Pattern: 16<br>
  Input 1 1   Target 0   Output 0.00735 <br>
  Training Pattern: 17<br>
  Input 0 1   Target 1   Output 0.99400 <br>
  Training Pattern: 18<br>
  Input 1 0   Target 1   Output 0.99399 <br>
  Training Pattern: 19<br>
  Input 0 0   Target 0   Output 0.00530 <br>
  Training Pattern: 20<br>
  Input 1 1   Target 0   Output 0.00735<br>
<br>
<br>



trained on distances:<br>
<br>
Training Pattern: 0<br>
  Input 74.0000000000 112.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 1<br>
  Input 103.0000000000 36.0000000000   Target 0   Output 0.00000 <br>
  Training Pattern: 2<br>
  Input 80.0000000000 73.0000000000   Target 0   Output 0.23420 <br>
  Training Pattern: 3<br>
  Input 52.0000000000 84.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 4<br>
  Input 100.0000000000 31.0000000000   Target 0   Output 0.00000 <br>
  Training Pattern: 5<br>
  Input 68.0000000000 44.0000000000   Target 0   Output 0.00003 <br>
  Training Pattern: 6<br>
  Input 89.0000000000 90.0000000000   Target 1   Output 0.97848 <br>
  Training Pattern: 7<br>
  Input 59.0000000000 25.000000000   Target 0   Output 0.00000 <br>
  Training Pattern: 8<br>
  Input 97.0000000000 104.0000000000   Target 1   Output 0.99939<br> 
  Training Pattern: 9<br>
  Input 24.0000000000 13.0000000000   Target 0   Output 0.01996<br> 
  Training Pattern: 10<br>
  Input 24.0000000000 94.0000000000   Target 1   Output 1.00000<br> 
  Training Pattern: 11<br>
  Input 88.0000000000 91.0000000000   Target 1   Output 0.99345<br> 
  Training Pattern: 12<br>
  Input 94.0000000000 39.0000000000   Target 0   Output 0.00000<br> 
  Training Pattern: 13<br>
  Input 62.0000000000 26.0000000000   Target 0   Output 0.00000 <br>
  Training Pattern: 14<br>
  Input 91.0000000000 67.0000000000   Target 0   Output 0.00004 <br>
  Training Pattern: 15<br>
  Input 105.0000000000 27.0000000000   Target 0   Output 0.00000 <br>
Training Pattern: 16<br>
  Input 85.0000000000 58.0000000000   Target 0   Output 0.00001 <br>
  Training Pattern: 17<br>
  Input 22.0000000000 37.0000000000   Target 1   Output 0.99999 <br>
  Training Pattern: 18<br>
  Input 65.0000000000 43.0000000000   Target 0   Output 0.00008 <br>
  Training Pattern: 19<br>
  Input 78.0000000000 65.0000000000   Target 0   Output 0.00846 <br>
  Training Pattern: 20<br>
  Input 47.0000000000 40.0000000000   Target 0   Output 0.20267 <br>
  Training Pattern: 21<br>
  Input 55.0000000000 45.0000000000   Target 0   Output 0.04156 <br>
  Training Pattern: 22<br>
  Input 60.0000000000 73.0000000000   Target 1   Output 0.99997 <br>
  Training Pattern: 23<br>
  Input 54.0000000000 90.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 24<br>
  Input 78.0000000000 68.0000000000   Target 0   Output 0.04683 <br>
  Training Pattern: 25<br>
  Input 12.0000000000 40.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 26<br>
  Input 5.0000000000 54.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 27<br>
  Input 7.0000000000 59.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 28<br>
  Input 46.0000000000 47.0000000000   Target 1   Output 0.97279 <br>
  Training Pattern: 29<br>
  Input 39.0000000000 10.0000000000   Target 0   Output 0.00000 <br>
  Training Pattern: 30<br>
  Input 24.0000000000 36.0000000000   Target 1   Output 0.99994 <br>
  Training Pattern: 31<br>
  Input 83.0000000000 59.0000000000   Target 0   Output 0.00003 <br>
  Training Pattern: 32<br>
  Input 94.0000000000 102.0000000000   Target 1   Output 0.99964 <br>
Training Pattern: 33<br>
  Input 6.0000000000 10.0000000000   Target 1   Output 0.99436 <br>
  Training Pattern: 34<br>
  Input 0.0000000000 40.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 35<br>
  Input 16.0000000000 69.0000000000   Target 1   Output 1.00000 <br>
  Training Pattern: 36<br>
  Input 43.0000000000 55.0000000000   Target 1   Output 0.99995 <br>
  Training Pattern: 37<br>
  Input 64.0000000000 31.0000000000   Target 0   Output 0.00000 <br>
  Training Pattern: 38<br>
  Input 86.0000000000 90.0000000000   Target 1   Output 0.99634 <br>
  Training Pattern: 39<br>
  Input 20.0000000000 23.0000000000   Target 1   Output 0.99052 87<br>
<br>
<br>
actual outputs from getResults function:<br>
//inputs <br>
43 //left<br>
143 //right<br>
//output<br>
1.00 // turn right<br>
<br><br>
//inputs<br>
3 // left <br>
42 // right<br>
//output<br>
1.00 // turn right<br>
<br><br>
//inputs<br>
40 //left<br>
42 //right<br>
//output<br>
0.98 // turn right<br>
<br><br>
//inputs<br>
40 // left<br>
10 //right<br>
//output<br>
0.00 // turn left<br>
<br><br>
resources used to write neural network:<br>
http://robotics.hobbizine.com/arduinoann.html<br>
https://www.cs.bham.ac.uk//~jxb/INC/nn.html<br>
https://www.the-diy-life.com/running-an-artificial-neural-network-on-an-arduino-uno/<br>
https://www.coursera.org/learn/neural-networks-deep-learning<br>
