/*
    See:
    https://www.codewars.com/kata/highest-and-lowest/train/python

    Details:
    In this little assignment you are given a string of space separated numbers, and have to return the highest and lowest number.

 Example:

 high_and_low("1 2 3 4 5")  # return "5 1"
 high_and_low("1 2 -3 4 5") # return "5 -3"
 high_and_low("1 9 3 4 -5") # return "9 -5"

 Notes:

     * All numbers are valid Int32, no need to validate them.
     * There will always be at least one number in the input string.
     * Output string must be two numbers separated by a single space, and highest number is first.

 */

let solution1 = s => {
  /* using bucklescript Js.String.split since the target is javascript */
  /* if we were to compile to native, maybe we could use Str.split */
  let splitted = Js.String.split(" ", s);

  /* sort mutates the array */
  Array.sort(compare, splitted);

  let len = Array.length(splitted);
  Js.Array.joinWith(" ", [|splitted[len - 1], splitted[0]|]);
};

let solution2 = s => {
  let splitted = Js.String.split(" ", s);

  let mapToInt = Array.map(item => int_of_string(item));

  let highAndLowFold =
    Array.fold_left(
      (acc, n) => (max(fst(acc), n), min(snd(acc), n)),
      (min_int, max_int),
    );

  let pairToString = p =>
    string_of_int(fst(p)) ++ " " ++ string_of_int(snd(p));

  splitted |> mapToInt |> highAndLowFold |> pairToString;
};
