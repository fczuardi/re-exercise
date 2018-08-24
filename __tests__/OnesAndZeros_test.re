open Jest;
open Expect;

open OnesAndZeros;

describe("OnesAndZeros", () => {
  let inputs = [|
    [|0, 0, 0, 1|],
    [|0, 0, 1, 0|],
    [|1, 1, 1, 1|],
    [|0, 1, 1, 0|],
  |];
  let outputs = [|1, 2, 15, 6|];

  test("solution 1", () => {
    let binaryArrayToNumber = solution1;
    expect(inputs |> Array.map(binaryArrayToNumber)) |> toEqual(outputs);
  });

  test("solution 2", () => {
    let binaryArrayToNumber = solution2;
    expect(inputs |> Array.map(binaryArrayToNumber)) |> toEqual(outputs);
  });
});
