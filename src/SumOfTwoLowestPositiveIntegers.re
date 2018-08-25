/*
See: https://www.codewars.com/kata/sum-of-two-lowest-positive-integers/python

 Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 integers. No floats or empty arrays will be passed.

 For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

 [10, 343445353, 3453445, 3453545353453] should return 3453455.

 Hint: Do not modify the original array.
 */

let solution1 = arr => {
  let arrCopy = Array.copy(arr);
  let sorted = {
    /* Array.sort mutates the original array */
    arrCopy |> Array.sort(compare);
    arrCopy;
  };

  sorted[0] + sorted[1];
};

let solution2 = arr => {
  let lowest = ref(max_int);
  let secondLowest = ref(max_int);
  arr
  |> Array.iter(value =>
       if (value > lowest^) {
         secondLowest := min(value, secondLowest^);
       } else {
         secondLowest := lowest^;
         lowest := value;
       }
     );

  lowest^ + secondLowest^;
};
