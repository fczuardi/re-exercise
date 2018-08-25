/*
See: https://www.codewars.com/kata/sum-of-two-lowest-positive-integers/python

 Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 integers. No floats or empty arrays will be passed.

 For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

 [10, 343445353, 3453445, 3453545353453] should return 3453455.

 Hint: Do not modify the original array.
 */

open Jest;
open Expect;

open SumOfTwoLowestPositiveIntegers;

describe("SumOfTwoLowestPositiveIntegers", () => {
  let testPairs = [|
    ([|5, 8, 12, 18, 22|], 13),
    ([|7, 15, 12, 18, 22|], 19),
    ([|26, 42, 12, 18, 22|], 30),
    ([|1, 8, 12, 18, 5|], 6),
    ([|13, 12, 5, 61, 22|], 17),
    ([|10, 343445353, 3453445, 3453545353453|], 3453455),
  |];
  let inputs = testPairs |> Array.map(fst);
  let outputs = testPairs |> Array.map(snd);

  describe("solution 1", () =>
    test("Baisc tests", () =>
      expect(inputs |> Array.map(solution1)) |> toEqual(outputs)
    )
  );

  describe("solution 2", () =>
    test("Baisc tests", () =>
      expect(inputs |> Array.map(solution2)) |> toEqual(outputs)
    )
  );
});
