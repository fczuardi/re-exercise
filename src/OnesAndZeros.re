/* implementation of https://www.codewars.com/kata/ones-and-zeros/python */

type t = array(int) => int;

let solution1: t =
  arr => {
    let reverseArray = arr => {
      let lastIndex = Array.length(arr) - 1;
      Array.mapi((i, _) => arr[lastIndex - i], arr);
    };

    let digitToDecimal = (position, bit) =>
      int_of_float(2.0 ** float_of_int(position)) * bit;

    let toSum = reverseArray(arr) |> Array.mapi(digitToDecimal);
    Array.fold_left((sum, item) => sum + item, 0, toSum);
  };

let solution2: t =
  arr => {
    let intArrayToString =
      Array.fold_left((s, item) => s ++ string_of_int(item), "");

    int_of_string("0b" ++ intArrayToString(arr));
  };
