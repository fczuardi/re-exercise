/*
 See https://www.codewars.com/kata/persistent-bugger/python

 Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.
 */

open Jest;
open Expect;

open PersistentBurguer;

describe("PersistentBurguer", () => {
  let testPairs = [|(39, 3), (4, 0), (25, 2), (999, 4)|];
  let inputs = testPairs |> Array.map(fst);
  let outputs = testPairs |> Array.map(snd);

  test("solution 1", () =>
    expect(Array.map(solution1, inputs)) |> toEqual(outputs)
  );
});
