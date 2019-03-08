Reading /home/david/bucklescript/jscomp/others/js_string.ml
---
title: Js.String
---
 `make value` converts the given value to a string


Examples:
```ocaml

  make 3.5 = "3.5";;
  make [|1;2;3|]) = "1,2,3";;

```

```reason
!!!
  make 3.5 = "3.5";;
  make [|1;2;3|]) = "1,2,3";;
!!!
```


### Js.String.make
```reason
[@bs.val] external make : 'a => t = "String";
```

```ocaml
external make : 'a -> t = "String" [@@bs.val]

```

 `fromCharCode n`
  creates a string containing the character corresponding to that number; {i n} ranges from 0 to 65535. If out of range, the lower 16 bits of the value are used. Thus, `fromCharCode 0x1F63A` gives the same result as `fromCharCode 0xF63A`.


Examples:
```ocaml

  fromCharCode 65 = "A";;
  fromCharCode 0x3c8 = {js|ψ|js};;
  fromCharCode 0xd55c = {js|한|js};;
  fromCharCode -64568 = {js|ψ|js};;

```

```reason

  fromCharCode(65) == "A";
  fromCharCode(968) == {js|ψ|js};
  fromCharCode(54620) == {js|한|js};
  fromCharCode - 64568 == {js|ψ|js};
  
```


### Js.String.fromCharCode
```reason
[@bs.val] external fromCharCode : int => t = "String.fromCharCode";
```

```ocaml
external fromCharCode : int -> t = "String.fromCharCode" [@@bs.val]

```

### Js.String.fromCharCodeMany
```reason
[@bs.val] [@bs.splice]
external fromCharCodeMany : array(int) => t = "String.fromCharCode";
```

```ocaml
external fromCharCodeMany : int array -> t = "String.fromCharCode" [@@bs.val] [@@bs.splice]
```

 `fromCharCodeMany \[|n1;n2;n3|\`] creates a string from the characters corresponding to the given numbers, using the same rules as `fromCharCode`.


Examples:
```ocaml

  fromCharCodeMany([|0xd55c, 0xae00, 33|]) = {js|한글!|js};;

```

```reason

  fromCharCodeMany([|(54620, 44544, 33)|]) == {js|한글!|js};
  
```


 `fromCodePoint n`
  creates a string containing the character corresponding to that numeric code point. If the number is not a valid code point, {b raises} `RangeError`. Thus, `fromCodePoint 0x1F63A` will produce a correct value, unlike `fromCharCode 0x1F63A`, and `fromCodePoint -5` will raise a `RangeError`.
  

Examples:
```ocaml

  fromCodePoint 65 = "A";;
  fromCodePoint 0x3c8 = {js|ψ|js};;
  fromCodePoint 0xd55c = {js|한|js};;
  fromCodePoint 0x1f63a = {js|😺|js};;

```

```reason

  fromCodePoint(65) == "A";
  fromCodePoint(968) == {js|ψ|js};
  fromCodePoint(54620) == {js|한|js};
  fromCodePoint(128570) == {js|😺|js};
  
```



### Js.String.fromCodePoint
```reason
[@bs.val] /** ES2015 */
external fromCodePoint : int => t = "String.fromCodePoint";
```

```ocaml
external fromCodePoint : int -> t = "String.fromCodePoint" [@@bs.val] (** ES2015 *)

```

 `fromCharCodeMany \[|n1;n2;n3|\`] creates a string from the characters corresponding to the given code point numbers, using the same rules as `fromCodePoint`.


Examples:
```ocaml

  fromCodePointMany([|0xd55c; 0xae00; 0x1f63a|]) = {js|한글😺|js}

```

```reason

  fromCodePointMany([|54620, 44544, 128570|]) == {js|한글😺|js};
  
```


### Js.String.fromCodePointMany
```reason
[@bs.val] [@bs.splice] /** ES2015 */
external fromCodePointMany : array(int) => t = "String.fromCodePoint";
/* String.raw: ES2015, meant to be used with template strings, not directly */
```

```ocaml
external fromCodePointMany : int array -> t = "String.fromCodePoint" [@@bs.val] [@@bs.splice] (** ES2015 *)


(* String.raw: ES2015, meant to be used with template strings, not directly *)

```

 `length s` returns the length of the given string.


Examples:
```ocaml

  length "abcd" = 4;;

```

```reason

  length("abcd") == 4;
  
```



### Js.String.length
```reason
[@bs.get] external length : t => int = "";
```

```ocaml
external length : t -> int = "" [@@bs.get]

```

 `get s n` returns as a string the character at the given index number. If `n` is out of range, this function returns `undefined`, so at some point this function may be modified to return `t option`.


Examples:
```ocaml

  get "Reason" 0 = "R";;
  get "Reason" 4 = "o";;
  get {js|Rẽasöń|js} 5 = {js|ń|js};;

```

```reason

  get("Reason", 0) == "R";
  get("Reason", 4) == "o";
  get({js|Rẽasöń|js}, 5) == {js|ń|js};
  
```


### Js.String.get
```reason
[@bs.get_index] external get : (t, int) => t = "";
```

```ocaml
external get : t -> int -> t = "" [@@bs.get_index]

```

 `charAt n s` gets the character at index `n` within string `s`. If `n` is negative or greater than the length of `s`, returns the empty string. If the string contains characters outside the range `\u0000-\uffff`, it will return the first 16-bit value at that position in the string.


Examples:
```ocaml

  charAt 0, "Reason" = "R"
  charAt( 12, "Reason") = "";
  charAt( 5, {js|Rẽasöń|js} = {js|ń|js}

```

```reason
!!!
  charAt 0, "Reason" = "R"
  charAt( 12, "Reason") = "";
  charAt( 5, {js|Rẽasöń|js} = {js|ń|js}
!!!
```


### Js.String.charAt
```reason
[@bs.send.pipe: t] external charAt : int => t = "";
```

```ocaml
external charAt : int ->  t = "" [@@bs.send.pipe: t]

```

 `charCodeAt n s` returns the character code at position `n` in string `s`; the result is in the range 0-65535, unlke `codePointAt`, so it will not work correctly for characters with code points greater than or equal to `0x10000`.
The return type is `float` because this function returns `NaN` if `n` is less than zero or greater than the length of the string.


Examples:
```ocaml

  charCodeAt 0 {js|😺|js} returns 0xd83d
  codePointAt 0 {js|😺|js} returns Some 0x1f63a

```

```reason

  charCodeAt(
    0,
    {js|😺|js},
    returns,
    55357,
    codePointAt,
    0,
    {js|😺|js},
    returns,
    Some,
    128570,
  );
  
```



### Js.String.charCodeAt
```reason
[@bs.send.pipe: t] external charCodeAt : int => float = "";
```

```ocaml
external charCodeAt : int -> float  = "" [@@bs.send.pipe: t]

```

 `codePointAt n s` returns the code point at position `n` within string `s` as a `Some` value. The return value handles code points greater than or equal to `0x10000`. If there is no code point at the given position, the function returns `None`.


Examples:
```ocaml

  codePointAt 1 {js|¿😺?|js} = Some 0x1f63a
  codePointAt 5 "abc" = None

```

```reason
!!!
  codePointAt 1 {js|¿😺?|js} = Some 0x1f63a
  codePointAt 5 "abc" = None
!!!
```


### Js.String.codePointAt
```reason
[@bs.send.pipe: t]
[@bs.return {undefined_to_opt: undefined_to_opt}]
/** ES2015 */
external codePointAt : int => option(int) = "";
```

```ocaml
external codePointAt : int -> int option = "" [@@bs.send.pipe: t] [@@bs.return {undefined_to_opt}] (** ES2015 *)

```

 `concat append original` returns a new string with `append` added after `original`.


Examples:
```ocaml

  concat "bell" "cow" = "cowbell";;

```

```reason

  concat("bell", "cow") == "cowbell";
  
```


### Js.String.concat
```reason
[@bs.send.pipe: t] external concat : t => t = "";
```

```ocaml
external concat : t -> t = "" [@@bs.send.pipe: t]

```

 `concat arr original` returns a new string consisting of each item of an array of strings added to the `original` string.


Examples:
```ocaml

  concatMany [|"2nd"; "3rd"; "4th"|] "1st" = "1st2nd3rd4th";;

```

```reason

  concatMany([|"2nd", "3rd", "4th"|], "1st") == "1st2nd3rd4th";
  
```


### Js.String.concatMany
```reason
[@bs.send.pipe: t] [@bs.splice]
external concatMany : array(t) => t = "concat";
```

```ocaml
external concatMany : t array -> t = "concat" [@@bs.send.pipe: t] [@@bs.splice]

```

 ES2015:
    `endsWith substr str` returns `true` if the `str` ends with `substr`, `false` otherwise.
    

Examples:
```ocaml

  endsWith "Script" "BuckleScript" = true;;
  endsWith "Script" "BuckleShoes" = false;;

```

```reason

  endsWith("Script", "BuckleScript") == true;
  endsWith("Script", "BuckleShoes") == false;
  
```
 

### Js.String.endsWith
```reason
[@bs.send.pipe: t] external endsWith : t => bool = "";
```

```ocaml
external endsWith : t -> bool = "" [@@bs.send.pipe: t] 

```

 `endsWithFrom ending len str` returns `true` if the first `len` characters of `str` end with `ending`, `false` otherwise. If `n` is greater than or equal to the length of `str`, then it works like `endsWith`. (Honestly, this should have been named `endsWithAt`, but oh well.)


Examples:
```ocaml

  endsWithFrom "cd" 4 "abcd" = true;;
  endsWithFrom "cd" 3 "abcde" = false;;
  endsWithFrom "cde" 99 "abcde" = true;;
  endsWithFrom "ple" 7 "example.dat" = true;;

```

```reason

  endsWithFrom("cd", 4, "abcd") == true;
  endsWithFrom("cd", 3, "abcde") == false;
  endsWithFrom("cde", 99, "abcde") == true;
  endsWithFrom("ple", 7, "example.dat") == true;
  
```


### Js.String.endsWithFrom
```reason
[@bs.send.pipe: t] /** ES2015 */
external endsWithFrom : (t, int) => bool = "endsWith";
```

```ocaml
external endsWithFrom : t -> int -> bool = "endsWith" [@@bs.send.pipe: t] (** ES2015 *)

```


  `includes searchValue s` returns `true` if `searchValue` is found anywhere within `s`, `false` otherwise.
  

Examples:
```ocaml

  includes "gram" "programmer" = true;;
  includes "er" "programmer" = true;;
  includes "pro" "programmer" = true;;
  includes "xyz" "programmer" = false;;

```

```reason

  includes("gram", "programmer") == true;
  includes("er", "programmer") == true;
  includes("pro", "programmer") == true;
  includes("xyz", "programmer") == false;
  
```


### Js.String.includes
```reason
[@bs.send.pipe: t] /** ES2015 */ external includes : t => bool = "";
```

```ocaml
external includes : t -> bool = "" [@@bs.send.pipe: t] (** ES2015 *)

```


  `includes searchValue start s` returns `true` if `searchValue` is found anywhere within `s` starting at character number `start` (where 0 is the first character), `false` otherwise.
  

Examples:
```ocaml

  includesFrom "gram" 1 "programmer" = true;;
  includesFrom "gram" 4 "programmer" = false;;
  includesFrom {js|한|js} 1 {js|대한민국|js} = true;;

```

```reason

  includesFrom("gram", 1, "programmer") == true;
  includesFrom("gram", 4, "programmer") == false;
  includesFrom({js|한|js}, 1, {js|대한민국|js}) == true;
  
```


### Js.String.includesFrom
```reason
[@bs.send.pipe: t] /** ES2015 */
external includesFrom : (t, int) => bool = "includes";
```

```ocaml
external includesFrom : t -> int -> bool = "includes" [@@bs.send.pipe: t] (** ES2015 *)

```


  `indexOf searchValue s` returns the position at which `searchValue` was first found within `s`, or `-1` if `searchValue` is not in `s`.
  

Examples:
```ocaml

  indexOf "ok" "bookseller" = 2;;
  indexOf "sell" "bookseller" = 4;;
  indexOf "ee" "beekeeper" = 1;;
  indexOf "xyz" "bookseller" = -1;;

```

```reason

  indexOf("ok", "bookseller") == 2;
  indexOf("sell", "bookseller") == 4;
  indexOf("ee", "beekeeper") == 1;
  indexOf("xyz", "bookseller") == (-1);
  
```


### Js.String.indexOf
```reason
[@bs.send.pipe: t] external indexOf : t => int = "";
```

```ocaml
external indexOf : t -> int = "" [@@bs.send.pipe: t]

```


  `indexOfFrom searchValue start s` returns the position at which `searchValue` was found within `s` starting at character position `start`, or `-1` if `searchValue` is not found in that portion of `s`. The return value is relative to the beginning of the string, no matter where the search started from.
  

Examples:
```ocaml

  indexOfFrom "ok" 1 "bookseller" = 2;;
  indexOfFrom "sell" 2 "bookseller" = 4;;
  indexOfFrom "sell" 5 "bookseller" = -1;;
  indexOf "xyz" "bookseller" = -1;;

```

```reason

  indexOfFrom("ok", 1, "bookseller") == 2;
  indexOfFrom("sell", 2, "bookseller") == 4;
  indexOfFrom("sell", 5, "bookseller") == (-1);
  indexOf("xyz", "bookseller") == (-1);
  
```


### Js.String.indexOfFrom
```reason
[@bs.send.pipe: t] external indexOfFrom : (t, int) => int = "indexOf";
```

```ocaml
external indexOfFrom : t -> int -> int = "indexOf" [@@bs.send.pipe: t]

```


  `lastIndexOf searchValue s` returns the position of the {i last} occurrence of `searchValue` within `s`, searching backwards from the end of the string. Returns `-1` if `searchValue` is not in `s`. The return value is always relative to the beginning of the string.
  

Examples:
```ocaml

  lastIndexOf "ok" "bookseller" = 2;;
  lastIndexOf "ee" "beekeeper" = 4;;
  lastIndexOf "xyz" "abcdefg" = -1;;

```

```reason

  lastIndexOf("ok", "bookseller") == 2;
  lastIndexOf("ee", "beekeeper") == 4;
  lastIndexOf("xyz", "abcdefg") == (-1);
  
```


### Js.String.lastIndexOf
```reason
[@bs.send.pipe: t] external lastIndexOf : t => int = "";
```

```ocaml
external lastIndexOf : t -> int = "" [@@bs.send.pipe: t]

```


  `lastIndexOfFrom searchValue start s` returns the position of the {i last} occurrence of `searchValue` within `s`, searching backwards from the given `start` position. Returns `-1` if `searchValue` is not in `s`. The return value is always relative to the beginning of the string.
  

Examples:
```ocaml

  lastIndexOfFrom "ok" 6 "bookseller" = 2;;
  lastIndexOfFrom "ee" 8 "beekeeper" = 4;;
  lastIndexOfFrom "ee" 3 "beekeeper" = 1;;
  lastIndexOfFrom "xyz" 4 "abcdefg" = -1;;

```

```reason

  lastIndexOfFrom("ok", 6, "bookseller") == 2;
  lastIndexOfFrom("ee", 8, "beekeeper") == 4;
  lastIndexOfFrom("ee", 3, "beekeeper") == 1;
  lastIndexOfFrom("xyz", 4, "abcdefg") == (-1);
  
```


### Js.String.lastIndexOfFrom
```reason
[@bs.send.pipe: t] external lastIndexOfFrom : (t, int) => int = "lastIndexOf";
/* extended by ECMA-402 */
```

```ocaml
external lastIndexOfFrom : t -> int -> int = "lastIndexOf" [@@bs.send.pipe: t]


(* extended by ECMA-402 *)
```


  `localeCompare comparison reference` returns
  
{ul
  {- a negative value if `reference` comes before `comparison` in sort order}
  {- zero if `reference` and `comparison` have the same sort order}
  {- a positive value if `reference` comes after `comparison` in sort order}}
  

Examples:
```ocaml

  (localeCompare "ant" "zebra") > 0.0;;
  (localeCompare "zebra" "ant") < 0.0;;
  (localeCompare "cat" "cat") = 0.0;;
  (localeCompare "cat" "CAT") > 0.0;; 

```

```reason

  localeCompare("ant", "zebra") > 0.0;
  localeCompare("zebra", "ant") < 0.0;
  localeCompare("cat", "cat") == 0.0;
  localeCompare("cat", "CAT") > 0.0;
  
```


### Js.String.localeCompare
```reason
[@bs.send.pipe: t] external localeCompare : t => float = "";
```

```ocaml
external localeCompare : t -> float = "" [@@bs.send.pipe: t]

```


  `match regexp str` matches a string against the given `regexp`. If there is no match, it returns `None`.
  For regular expressions without the `g` modifier, if there is a match, the return value is `Some array` where the array contains:
  
  {ul
    {- The entire matched string}
    {- Any capture groups if the `regexp` had parentheses}
  }
  
  For regular expressions with the `g` modifier, a matched expression returns `Some array` with all the matched substrings and no capture groups.
  

Examples:
```ocaml

  match [%re "/b[aeiou]t/"] "The better bats" = Some [|"bet"|]
  match [%re "/b[aeiou]t/g"] "The better bats" = Some [|"bet";"bat"|]
  match [%re "/(\\d+)-(\\d+)-(\\d+)/"] "Today is 2018-04-05." =
    Some [|"2018-04-05"; "2018"; "04"; "05"|]
  match [%re "/b[aeiou]g/"] "The large container." = None

```

```reason
!!!
  match [%re "/b[aeiou]t/"] "The better bats" = Some [|"bet"|]
  match [%re "/b[aeiou]t/g"] "The better bats" = Some [|"bet";"bat"|]
  match [%re "/(\\d+)-(\\d+)-(\\d+)/"] "Today is 2018-04-05." =
    Some [|"2018-04-05"; "2018"; "04"; "05"|]
  match [%re "/b[aeiou]g/"] "The large container." = None
!!!
```



### Js.String.match_
```reason
[@bs.send.pipe: t] [@bs.return {null_to_opt: null_to_opt}]
external match : Js_re.t => option(array(t)) = "match";
```

```ocaml
external match_ : Js_re.t -> t array option = "match" [@@bs.send.pipe: t] [@@bs.return {null_to_opt}]

```


 `normalize str` returns the normalized Unicode string using Normalization Form Canonical (NFC) Composition.

Consider the character `ã`, which can be represented as the single codepoint `\u00e3` or the combination of a lower case letter A `\u0061` and a combining tilde `\u0303`. Normalization ensures that both can be stored in an equivalent binary representation.
  
@see <https://www.unicode.org/reports/tr15/tr15-45.html> Unicode technical report for details

### Js.String.normalize
```reason
[@bs.send.pipe: t] /** ES2015 */ external normalize : t = "";
```

```ocaml
external normalize : t = "" [@@bs.send.pipe: t] (** ES2015 *)

```



  `normalize str form` (ES2015) returns the normalized Unicode string using the specified form of normalization, which may be one of:
  
  {ul
    {- "NFC" — Normalization Form Canonical Composition.}
    {- "NFD" — Normalization Form Canonical Decomposition.}
    {- "NFKC" — Normalization Form Compatibility Composition.}
    {- "NFKD" — Normalization Form Compatibility Decomposition.}
  }
  
  @see <https://www.unicode.org/reports/tr15/tr15-45.html> Unicode technical report for details

### Js.String.normalizeByForm
```reason
[@bs.send.pipe: t] external normalizeByForm : t => t = "normalize";
```

```ocaml
external normalizeByForm : t -> t = "normalize" [@@bs.send.pipe: t]

```


  `repeat n s` returns a string that consists of `n` repetitions of `s`. Raises `RangeError` if `n` is negative.
  

Examples:
```ocaml

  repeat 3 "ha" = "hahaha"
  repeat 0 "empty" = ""

```

```reason

  repeat(3, "ha") == "hahaha"(repeat, 0, "empty") == "";
  
```


### Js.String.repeat
```reason
[@bs.send.pipe: t] /** ES2015 */ external repeat : int => t = "";
```

```ocaml
external repeat : int -> t = "" [@@bs.send.pipe: t] (** ES2015 *)

```

 `replace substr newSubstr string` returns a new string which is
identical to `string` except with the first matching instance of `substr`
replaced by `newSubstr`.

`substr` is treated as a verbatim string to match, not a regular
expression.


Examples:
```ocaml

  replace "old" "new" "old string" = "new string"
  replace "the" "this" "the cat and the dog" = "this cat and the dog"

```

```reason

  replace("old", "new", "old string")
  == "new string"(replace, "the", "this", "the cat and the dog") == "this cat and the dog";
  
```


### Js.String.replace
```reason
[@bs.send.pipe: t] external replace : (t, t) => t = "";
```

```ocaml
external replace : t ->  t ->  t = "" [@@bs.send.pipe: t]

```

 `replaceByRe regex replacement string` returns a new string where occurrences matching `regex`
have been replaced by `replacement`.


Examples:
```ocaml

  replaceByRe [%re "/[aeiou]/g"] "x" "vowels be gone" = "vxwxls bx gxnx"
  replaceByRe [%re "/(\\w+) (\\w+)/"] "$2, $1" "Juan Fulano" = "Fulano, Juan"

```

```reason

  replaceByRe([%re "/[aeiou]/g"], "x", "vowels be gone")
  == "vxwxls bx gxnx"(
       replaceByRe,
       [%re "/(\\w+) (\\w+)/"],
       "$2, $1",
       "Juan Fulano",
     ) == "Fulano, Juan";
  
```


### Js.String.replaceByRe
```reason
[@bs.send.pipe: t] external replaceByRe : (Js_re.t, t) => t = "replace";
```

```ocaml
external replaceByRe : Js_re.t ->  t ->  t = "replace" [@@bs.send.pipe: t]

```

 returns a new string with some or all matches of a pattern with no capturing
parentheses replaced by the value returned from the given function.
The function receives as its parameters the matched string, the offset at which the
match begins, and the whole string being matched


Examples:
```ocaml

let str = "beautiful vowels"
let re = [%re "/[aeiou]/g"]
let matchFn matchPart offset wholeString =
  Js.String.toUpperCase matchPart
  
let replaced = Js.String.unsafeReplaceBy0 re matchFn str

let () = Js.log replaced (* prints "bEAUtifUl vOwEls" *)

```

```reason

let str = "beautiful vowels";
let re = [%re "/[aeiou]/g"];
let matchFn = (matchPart, offset, wholeString) =>
  Js.String.toUpperCase(matchPart);
let replaced = Js.String.unsafeReplaceBy0(re, matchFn, str);
let () = Js.log(replaced); /* prints "bEAUtifUl vOwEls" */

```


@see <https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace#Specifying_a_function_as_a_parameter> MDN

### Js.String.unsafeReplaceBy0
```reason
[@bs.send.pipe: t]
external unsafeReplaceBy0 : (Js_re.t, [@bs.uncurry] ((t, int, t) => t)) => t =
  "replace";
```

```ocaml
external unsafeReplaceBy0 : Js_re.t -> (t -> int -> t -> t [@bs.uncurry]) -> t = "replace" [@@bs.send.pipe: t]

```

 returns a new string with some or all matches of a pattern with one set of capturing
parentheses replaced by the value returned from the given function.
The function receives as its parameters the matched string, the captured string,
the offset at which the match begins, and the whole string being matched.


Examples:
```ocaml

let str = "increment 23"
let re = [%re "/increment (\\d+)/g"]
let matchFn matchPart p1 offset wholeString =
  wholeString ^ " is " ^ (string_of_int ((int_of_string p1) + 1))
  
let replaced = Js.String.unsafeReplaceBy1 re matchFn str

let () = Js.log replaced (* prints "increment 23 is 24" *)

```

```reason

let str = "increment 23";
let re = [%re "/increment (\\d+)/g"];
let matchFn = (matchPart, p1, offset, wholeString) =>
  wholeString ++ " is " ++ string_of_int(int_of_string(p1) + 1);
let replaced = Js.String.unsafeReplaceBy1(re, matchFn, str);
let () = Js.log(replaced); /* prints "increment 23 is 24" */

```


@see <https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace#Specifying_a_function_as_a_parameter> MDN

### Js.String.unsafeReplaceBy1
```reason
[@bs.send.pipe: t]
external unsafeReplaceBy1 : (Js_re.t, [@bs.uncurry] ((t, t, int, t) => t)) => t =
  "replace";
```

```ocaml
external unsafeReplaceBy1 : Js_re.t -> (t -> t -> int -> t -> t [@bs.uncurry]) -> t = "replace" [@@bs.send.pipe: t]

```

 returns a new string with some or all matches of a pattern with two sets of capturing
parentheses replaced by the value returned from the given function.
The function receives as its parameters the matched string, the captured strings,
the offset at which the match begins, and the whole string being matched.


Examples:
```ocaml

let str = "7 times 6"
let re = [%re "/(\\d+) times (\\d+)/"]
let matchFn matchPart p1 p2 offset wholeString =
  string_of_int ((int_of_string p1) * (int_of_string p2))
  
let replaced = Js.String.unsafeReplaceBy2 re matchFn str

let () = Js.log replaced (* prints "42" *)

```

```reason

let str = "7 times 6";
let re = [%re "/(\\d+) times (\\d+)/"];
let matchFn = (matchPart, p1, p2, offset, wholeString) =>
  string_of_int(int_of_string(p1) * int_of_string(p2));
let replaced = Js.String.unsafeReplaceBy2(re, matchFn, str);
let () = Js.log(replaced); /* prints "42" */

```


@see <https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace#Specifying_a_function_as_a_parameter> MDN

### Js.String.unsafeReplaceBy2
```reason
[@bs.send.pipe: t]
external unsafeReplaceBy2 :
  (Js_re.t, [@bs.uncurry] ((t, t, t, int, t) => t)) => t =
  "replace";
```

```ocaml
external unsafeReplaceBy2 : Js_re.t -> (t -> t -> t -> int -> t -> t [@bs.uncurry]) -> t = "replace" [@@bs.send.pipe: t]

```


 returns a new string with some or all matches of a pattern with three sets of capturing
parentheses replaced by the value returned from the given function.
The function receives as its parameters the matched string, the captured strings,
the offset at which the match begins, and the whole string being matched.

@see <https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace#Specifying_a_function_as_a_parameter> MDN

### Js.String.unsafeReplaceBy3
```reason
[@bs.send.pipe: t]
external unsafeReplaceBy3 :
  (Js_re.t, [@bs.uncurry] ((t, t, t, t, int, t) => t)) => t =
  "replace";
```

```ocaml
external unsafeReplaceBy3 : Js_re.t -> (t -> t -> t -> t -> int -> t -> t [@bs.uncurry]) -> t = "replace" [@@bs.send.pipe: t]

```

 `search regexp str` returns the starting position of the first match of `regexp` in the given `str`, or -1 if there is no match.


Examples:
```ocaml

search [%re "/\\d+/"] "testing 1 2 3" = 8;;
search [%re "/\\d+/"] "no numbers" = -1;;

```

```reason

search([%re "/\\d+/"], "testing 1 2 3") == 8;
search([%re "/\\d+/"], "no numbers") == (-1);

```


### Js.String.search
```reason
[@bs.send.pipe: t] external search : Js_re.t => int = "";
```

```ocaml
external search : Js_re.t -> int = "" [@@bs.send.pipe: t]

```

 `slice from:n1 to_:n2 str` returns the substring of `str` starting at character `n1` up to but not including `n2`

If either `n1` or `n2` is negative, then it is evaluated as `length str - n1` (or `length str - n2`.

If `n2` is greater than the length of `str`, then it is treated as `length str`.

If `n1` is greater than `n2`, `slice` returns the empty string.


Examples:
```ocaml

  slice ~from:2 ~to_:5 "abcdefg" == "cde";;
  slice ~from:2 ~to_:9 "abcdefg" == "cdefg";;
  slice ~from:(-4) ~to_:(-2) "abcdefg" == "de";; 
  slice ~from:5 ~to_:1 "abcdefg" == "";;

```

```reason

  slice(~from=2, ~to_=5, "abcdefg") === "cde";
  slice(~from=2, ~to_=9, "abcdefg") === "cdefg";
  slice(~from=-4, ~to_=-2, "abcdefg") === "de";
  slice(~from=5, ~to_=1, "abcdefg") === "";
  
```


### Js.String.slice
```reason
[@bs.send.pipe: t] external slice : (~from: int, ~to_: int) => t = "";
```

```ocaml
external slice : from:int -> to_:int ->  t = "" [@@bs.send.pipe: t]

```

 `sliceToEnd from: n str` returns the substring of `str` starting at character `n` to the end of the string

If `n` is negative, then it is evaluated as `length str - n`.

If `n` is greater than the length of `str`, then `sliceToEnd` returns the empty string.


Examples:
```ocaml

  sliceToEnd ~from: 4 "abcdefg" == "efg";;
  sliceToEnd ~from: (-2) "abcdefg" == "fg";; 
  sliceToEnd ~from: 7 "abcdefg" == "";;

```

```reason

  sliceToEnd(~from=4, "abcdefg") === "efg";
  sliceToEnd(~from=-2, "abcdefg") === "fg";
  sliceToEnd(~from=7, "abcdefg") === "";
  
```


### Js.String.sliceToEnd
```reason
[@bs.send.pipe: t] external sliceToEnd : (~from: int) => t = "slice";
```

```ocaml
external sliceToEnd : from:int ->  t = "slice" [@@bs.send.pipe: t]

```


  `split delimiter str` splits the given `str` at every occurrence of `delimiter` and returns an
  array of the resulting substrings.
  

Examples:
```ocaml

  split "-" "2018-01-02" = [|"2018"; "01"; "02"|];;
  split "," "a,b,,c" = [|"a"; "b"; ""; "c"|];;
  split "::" "good::bad as great::awful" = [|"good"; "bad as great"; "awful"|];;
  split ";" "has-no-delimiter" = [|"has-no-delimiter"|];;

```

```reason

  split("-", "2018-01-02") == [|"2018", "01", "02"|];
  split(",", "a,b,,c") == [|"a", "b", "", "c"|];
  split("::", "good::bad as great::awful")
  == [|"good", "bad as great", "awful"|];
  split(";", "has-no-delimiter") == [|"has-no-delimiter"|];
  
```
;

### Js.String.split
```reason
[@bs.send.pipe: t] external split : t => array(t) = "";
```

```ocaml
external split : t -> t array  = "" [@@bs.send.pipe: t]

```


  `splitAtMost delimiter ~limit: n str` splits the given `str` at every occurrence of `delimiter` and returns an array of the first `n` resulting substrings. If `n` is negative or greater than the number of substrings, the array will contain all the substrings.
  

Examples:
```ocaml

  splitAtMost "/" ~limit: 3 "ant/bee/cat/dog/elk" = [|"ant"; "bee"; "cat"|];;
  splitAtMost "/" ~limit: 0 "ant/bee/cat/dog/elk" = [| |];;
  splitAtMost "/" ~limit: 9 "ant/bee/cat/dog/elk" = [|"ant"; "bee"; "cat"; "dog"; "elk"|];;

```

```reason

  splitAtMost("/", ~limit=3, "ant/bee/cat/dog/elk") == [|"ant", "bee", "cat"|];
  splitAtMost("/", ~limit=0, "ant/bee/cat/dog/elk") == [||];
  splitAtMost("/", ~limit=9, "ant/bee/cat/dog/elk")
  == [|"ant", "bee", "cat", "dog", "elk"|];
  
```


### Js.String.splitAtMost
```reason
[@bs.send.pipe: t]
external splitAtMost : (t, ~limit: int) => array(t) = "split";
```

```ocaml
external splitAtMost: t -> limit:int -> t array = "split" [@@bs.send.pipe: t]

```



  Deprecated - Please use `splitAtMost`

### Js.String.splitLimited
```reason
[@bs.send.pipe: t] [@ocaml.deprecated "Please use splitAtMost"]
external splitLimited : (t, int) => array(t) = "split";
```

```ocaml
external splitLimited : t -> int -> t array = "split" [@@bs.send.pipe: t]
[@@ocaml.deprecated "Please use splitAtMost"]

```


  `splitByRe regex str` splits the given `str` at every occurrence of `regex` and returns an
  array of the resulting substrings.
  

Examples:
```ocaml

  splitByRe [%re "/\\s*[,;]\\s*/"] "art; bed , cog ;dad" = [|"art"; "bed"; "cog"; "dad"|];;
  splitByRe [%re "/[,;]/"] "has:no:match" = [|"has:no:match"|];;

```

```reason

  splitByRe([%re "/\\s*[,;]\\s*/"], "art; bed , cog ;dad")
  == [|"art", "bed", "cog", "dad"|];
  splitByRe([%re "/[,;]/"], "has:no:match") == [|"has:no:match"|];
  
```
;

### Js.String.splitByRe
```reason
[@bs.send.pipe: t] external splitByRe : Js_re.t => array(t) = "split";
```

```ocaml
external splitByRe : Js_re.t ->  t array = "split" [@@bs.send.pipe: t]

```


  `splitByReAtMost regex ~limit: n str` splits the given `str` at every occurrence of `regex` and returns an
  array of the first `n` resulting substrings. If `n` is negative or greater than the number of substrings, the array will contain all the substrings.
  

Examples:
```ocaml

  splitByReAtMost [%re "/\\s*:\\s*/"] ~limit: 3 "one: two: three: four" = [|"one"; "two"; "three"|];;
  splitByReAtMost [%re "/\\s*:\\s*/"] ~limit: 0 "one: two: three: four" = [| |];;
  splitByReAtMost [%re "/\\s*:\\s*/"] ~limit: 8 "one: two: three: four" = [|"one"; "two"; "three"; "four"|];;

```

```reason

  splitByReAtMost([%re "/\\s*:\\s*/"], ~limit=3, "one: two: three: four")
  == [|"one", "two", "three"|];
  splitByReAtMost([%re "/\\s*:\\s*/"], ~limit=0, "one: two: three: four")
  == [||];
  splitByReAtMost([%re "/\\s*:\\s*/"], ~limit=8, "one: two: three: four")
  == [|"one", "two", "three", "four"|];
  
```
;

### Js.String.splitByReAtMost
```reason
[@bs.send.pipe: t]
external splitByReAtMost : (Js_re.t, ~limit: int) => array(t) = "split";
```

```ocaml
external splitByReAtMost : Js_re.t -> limit:int ->  t array = "split" [@@bs.send.pipe: t]

```



  Deprecated - Please use `splitByReAtMost`

### Js.String.splitRegexpLimited
```reason
[@bs.send.pipe: t] [@ocaml.deprecated "Please use splitByReAtMost"]
external splitRegexpLimited : (Js_re.t, int) => array(t) = "";
```

```ocaml
external splitRegexpLimited : Js_re.t -> int ->  t array = "" [@@bs.send.pipe: t]
[@@ocaml.deprecated "Please use splitByReAtMost"]

```

 ES2015:
    `startsWith substr str` returns `true` if the `str` starts with `substr`, `false` otherwise.
    

Examples:
```ocaml

  startsWith "Buckle" "BuckleScript" = true;;
  startsWith "" "BuckleScript" = true;;
  startsWith "Buckle" "JavaScript" = false;;

```

```reason

  startsWith("Buckle", "BuckleScript") == true;
  startsWith("", "BuckleScript") == true;
  startsWith("Buckle", "JavaScript") == false;
  
```
 

### Js.String.startsWith
```reason
[@bs.send.pipe: t] external startsWith : t => bool = "";
```

```ocaml
external startsWith : t -> bool = "" [@@bs.send.pipe: t]

```

 ES2015:
    `startsWithFrom substr n str` returns `true` if the `str` starts with `substr` starting at position `n`, `false` otherwise. If `n` is negative, the search starts at the beginning of `str`.
    

Examples:
```ocaml

  startsWithFrom "kle" 3 "BuckleScript" = true;;
  startsWithFrom "" 3 "BuckleScript" = true;;
  startsWithFrom "Buckle" 2 "JavaScript" = false;;

```

```reason

  startsWithFrom("kle", 3, "BuckleScript") == true;
  startsWithFrom("", 3, "BuckleScript") == true;
  startsWithFrom("Buckle", 2, "JavaScript") == false;
  
```
 

### Js.String.startsWithFrom
```reason
[@bs.send.pipe: t] external startsWithFrom : (t, int) => bool = "startsWith";
```

```ocaml
external startsWithFrom : t -> int -> bool = "startsWith" [@@bs.send.pipe: t]

```


  `substr ~from: n str` returns the substring of `str` from position `n` to the end of the string.
  
  If `n` is less than zero, the starting position is the length of `str` - `n`.
  
  If `n` is greater than or equal to the length of `str`, returns the empty string.
  

Examples:
```ocaml

  substr ~from: 3 "abcdefghij" = "defghij"
  substr ~from: (-3) "abcdefghij" = "hij"
  substr ~from: 12 "abcdefghij" = ""

```

```reason

  substr(~from=3, "abcdefghij")
  == "defghij"(substr, ~from=-3, "abcdefghij") == "hij"(
                                                     substr,
                                                     ~from=12,
                                                     "abcdefghij",
                                                   ) == "";
  
```


### Js.String.substr
```reason
[@bs.send.pipe: t] external substr : (~from: int) => t = "";
```

```ocaml
external substr : from:int -> t = "" [@@bs.send.pipe: t]

```


  `substrAtMost ~from: pos ~length: n str` returns the substring of `str` of length `n` starting at position `pos`.
  
  If `pos` is less than zero, the starting position is the length of `str` - `pos`.
  
  If `pos` is greater than or equal to the length of `str`, returns the empty string.
  
  If `n` is less than or equal to zero, returns the empty string.
  

Examples:
```ocaml

  substrAtMost ~from: 3 ~length: 4 "abcdefghij" = "defghij"
  substrAtMost ~from: (-3) ~length: 4 "abcdefghij" = "hij"
  substrAtMost ~from: 12 ~ length: 2 "abcdefghij" = ""

```

```reason
!!!
  substrAtMost ~from: 3 ~length: 4 "abcdefghij" = "defghij"
  substrAtMost ~from: (-3) ~length: 4 "abcdefghij" = "hij"
  substrAtMost ~from: 12 ~ length: 2 "abcdefghij" = ""
!!!
```


### Js.String.substrAtMost
```reason
[@bs.send.pipe: t]
external substrAtMost : (~from: int, ~length: int) => t = "substr";
```

```ocaml
external substrAtMost : from:int -> length:int -> t = "substr" [@@bs.send.pipe: t]

```


  `substring ~from: start ~to_: finish str` returns characters `start` up to but not including `finish` from `str`.
  
  If `start` is less than zero, it is treated as zero.
  
  If `finish` is zero or negative, the empty string is returned.
  
  If `start` is greater than `finish`, the start and finish points are swapped.
  

Examples:
```ocaml

  substring ~from: 3 ~to_: 6 "playground" = "ygr";;
  substring ~from: 6 ~to_: 3 "playground" = "ygr";;
  substring ~from: 4 ~to_: 12 "playground" = "ground";;

```

```reason

  substring(~from=3, ~to_=6, "playground") == "ygr";
  substring(~from=6, ~to_=3, "playground") == "ygr";
  substring(~from=4, ~to_=12, "playground") == "ground";
  
```


### Js.String.substring
```reason
[@bs.send.pipe: t] external substring : (~from: int, ~to_: int) => t = "";
```

```ocaml
external substring : from:int -> to_:int ->  t = "" [@@bs.send.pipe: t]

```


  `substringToEnd ~from: start str` returns the substring of `str` from position `start` to the end.
  
  If `start` is less than or equal to zero, the entire string is returned.
  
  If `start` is greater than or equal to the length of `str`, the empty string is returned.
  

Examples:
```ocaml

  substringToEnd ~from: 4 "playground" = "ground";;
  substringToEnd ~from: (-3) "playground" = "playground";;
  substringToEnd ~from: 12 "playground" = "";

```

```reason

  substringToEnd(~from=4, "playground") == "ground";
  substringToEnd(~from=-3, "playground") == "playground";
  substringToEnd(~from=12, "playground") == "";
  
```


### Js.String.substringToEnd
```reason
[@bs.send.pipe: t] external substringToEnd : (~from: int) => t = "substring";
```

```ocaml
external substringToEnd : from:int ->  t = "substring" [@@bs.send.pipe: t]

```


  `toLowerCase str` converts `str` to lower case using the locale-insensitive case mappings in the Unicode Character Database. Notice that the conversion can give different results depending upon context, for example with the Greek letter sigma, which has two different lower case forms when it is the last character in a string or not.
  

Examples:
```ocaml

  toLowerCase "ABC" = "abc";;
  toLowerCase {js|ΣΠ|js} = {js|σπ|js};;
  toLowerCase {js|ΠΣ|js} = {js|πς|js};;

```

```reason

  toLowerCase("ABC") == "abc";
  toLowerCase({js|ΣΠ|js}) == {js|σπ|js};
  toLowerCase({js|ΠΣ|js}) == {js|πς|js};
  
```


### Js.String.toLowerCase
```reason
[@bs.send.pipe: t] external toLowerCase : t = "";
```

```ocaml
external toLowerCase : t = "" [@@bs.send.pipe: t]

```



  `toLocaleLowerCase str` converts `str` to lower case using the current locale

### Js.String.toLocaleLowerCase
```reason
[@bs.send.pipe: t] external toLocaleLowerCase : t = "";
```

```ocaml
external toLocaleLowerCase : t = "" [@@bs.send.pipe: t]

```


  `toUpperCase str` converts `str` to upper case using the locale-insensitive case mappings in the Unicode Character Database. Notice that the conversion can expand the number of letters in the result; for example the German `ß` capitalizes to two `S`es in a row.
  

Examples:
```ocaml

  toUpperCase "abc" = "ABC";;
  toUpperCase {js|Straße|js} = {js|STRASSE|js};;
  toLowerCase {js|πς|js} = {js|ΠΣ|js};;

```

```reason

  toUpperCase("abc") == "ABC";
  toUpperCase({js|Straße|js}) == {js|STRASSE|js};
  toLowerCase({js|πς|js}) == {js|ΠΣ|js};
  
```


### Js.String.toUpperCase
```reason
[@bs.send.pipe: t] external toUpperCase : t = "";
```

```ocaml
external toUpperCase : t = "" [@@bs.send.pipe: t]

```



  `toLocaleUpperCase str` converts `str` to upper case using the current locale

### Js.String.toLocaleUpperCase
```reason
[@bs.send.pipe: t] external toLocaleUpperCase : t = "";
```

```ocaml
external toLocaleUpperCase : t = "" [@@bs.send.pipe: t]

```


  `trim str` returns a string that is `str` with whitespace stripped from both ends. Internal whitespace is not removed.


Examples:
```ocaml

  trim "   abc def   " = "abc def"
  trim "\n\r\t abc def \n\n\t\r " = "abc def"

```

```reason

  trim("   abc def   ")
  == "abc def"(trim, "\n\r\t abc def \n\n\t\r ") == "abc def";
  
```


### Js.String.trim
```reason
[@bs.send.pipe: t] external trim : t = "";
/* HTML wrappers */
```

```ocaml
external trim : t = "" [@@bs.send.pipe: t]

(* HTML wrappers *)

```


  `anchor anchorName anchorText` creates a string with an HTML `<a>` element with `name` attribute of `anchorName` and `anchorText` as its content.
  

Examples:
```ocaml

  anchor "page1" "Page One" = "<a name=\"page1\">Page One</a>"

```

```reason

  anchor("page1", "Page One") == "<a name=\"page1\">Page One</a>";
  
```


### Js.String.anchor
```reason
[@bs.send.pipe: t] /** ES2015 */ external anchor : t => t = "";
```

```ocaml
external anchor : t -> t = "" [@@bs.send.pipe: t] (** ES2015 *)

```


  `link urlText linkText` creates a string withan HTML `<a>` element with `href` attribute of `urlText` and `linkText` as its content.
  

Examples:
```ocaml

  link "page2.html" "Go to page two" = "<a href=\"page2.html\">Go to page two</a>"

```

```reason

  link("page2.html", "Go to page two")
  == "<a href=\"page2.html\">Go to page two</a>";
  
```


### Js.String.link
```reason
[@bs.send.pipe: t] /** ES2015 */ external link : t => t = "";
```

```ocaml
external link : t -> t = "" [@@bs.send.pipe: t] (** ES2015 *)

```

### Js.String.castToArrayLike
```reason
external castToArrayLike : t => Js_array.array_like(t) = "%identity";
/* FIXME: we should not encourage people to use [%identity], better
       to provide something using [@@bs.val] so that we can track such
       casting
   */
```

```ocaml
external castToArrayLike : t -> t Js_array.array_like = "%identity" 
(* FIXME: we should not encourage people to use [%identity], better
    to provide something using [@@bs.val] so that we can track such 
    casting
*)

```


