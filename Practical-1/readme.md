# Learningss

//Practical-1
P-1:
In this we stored the first element of the array as a temporary variable.
Then we shifted remaining element,one position to the left.
At last, the temporary element is placed at the last index.
this process is repeated h times.
Also when h is very large, repeating is insuffient because after every n rotations, the array becomes the same again. 

P-2:
For every element in the array, we compare it with all the elements after it.
If a matching element is found, it means that book ID appears more than once.
Before printing, we check whether that duplicate has already been printed to avoid repeated output.
The solution compares each element with all elements after it.
Therefore, the array is scanned many times using nested loops. Time Complexity becomes O(n²).

For 100,000 records, this becomes very slow because nearly every element is compared with every other element.
so we use a frequency array or a hash map.while reading each element, it increase its frequency.
and print only those elements whose frequency is greater than 1.This reduces the complexity to O(n)

P-3:
Traverse the sentence one character at a time.
Build each word until a space is encountered.
Whenever a complete word is obtained,
Compare its length with the current longest word.
If it is longer, we update the longest word.
Continue until the sentence ends and Finally, print the longest word and its length.