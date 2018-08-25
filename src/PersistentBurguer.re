/*
 See https://www.codewars.com/kata/persistent-bugger/python

 Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.
 */

let solution1 = n => {
  let charToInt = c => Char.code(c) - Char.code('0');

  let stringToDigitsArray = s =>
    Array.init(String.length(s), String.get(s)) |> Array.map(charToInt);

  let multiplyDigits = Array.fold_left((a, b) => a * b, 1);

  let rec persistence = (n, count) => {
    let s = string_of_int(n);
    switch (String.length(s)) {
    | 1 => count
    | n =>
      let digitsArray = stringToDigitsArray(s);
      let multiplied = multiplyDigits(digitsArray);
      persistence(multiplied, count + 1);
    };
  };

  persistence(n, 0);
};
