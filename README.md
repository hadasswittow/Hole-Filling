# Hole-Filling
Lightricks home assignment

# Answers for the questions:
1. The time complexity of the algorithm that fills the hole, assuming that the hole and boundary were already found, when m is boundary pixels and n is hole pixels is O(nm), because for every pixel in the hole we iterate through all boundary pixels. When trying to express the complexity only in terms of n, we see that m is the scope of the hole and n is the area of the hole, so for most holes the approximated scope will be O(sqrt(n)), therefore we get the complexity is - O(nsqrt(n)) = O(n^1.5) .

2. To get an approximated time comlexity of O(n), we will wans to cancle the iterating through all the boundary pixels for every hole pixel, and instead just calculate the hole color according to the connected boundary pixels. So we will need to starts from the hole pixels that are connected to the boundary and keep on going inside the hole. The time copmlexity will then be O(n) because we iterated only the hole pixels and had a calculation of constant time on it.

![SCREESHOT DECSRIPTION](bandw.jpg) 
![SCREESHOT DECSRIPTION](hole_filled.jpg)
