/*
 * Should we use parseML/printRE or parseMLI/printREI?
 */
type conversionType =
  | Implementation
  | Interface;

/*
 * Utility functions for conversion of ML to RE
 */
let toReason = (s: string, implOrInterface: conversionType) : string => {
  Js.String.replaceByRe([%re "/\\\\@/g"], "@", s) |> switch (implOrInterface) {
        | Implementation => Refmt.parseML
        | Interface => Refmt.parseMLI
      }
    |> fun
        | Ok(ast) => ast |> 
          switch(implOrInterface) {
            | Implementation => Refmt.printRE
            | Interface => Refmt.printREI
          }
        | Error(`RefmtParseError({message})) => "Error: " ++ message
};

/*  The following two functions are needed when processing multi-line examples */
/*
 * Return count of leading newlines, leading spaces (after newlines),
 * and string without leading newlines and spaces.
 */
let countLeadingWhitespace = (s: string) : (int, int, string) => {
  let sansNewlines = Js.String.replaceByRe([%re "/^\\n+/g"], "", s);
  let sansLeading = Js.String.replaceByRe([%re "/^\\s+/"], "", sansNewlines);
  (Js.String.length(s) - Js.String.length(sansNewlines),
    Js.String.length(sansNewlines) - Js.String.length(sansLeading), sansLeading)
};

/*
 * Add the given number of spaces to each line in the given string
 */
let addSpaces = (n: int, str: string) => {
  let spaces = String.make(n, ' ');
  Js.String.split("\n", str) |>
    Array.map((item: string) : string => { spaces ++ item }) |>
    Js.Array.joinWith("\n");
};

/*
 * Convert multi-line OCaml to Reason. If the result begins with Error,
 * return original string. Because refmt adds an extra newline at the
 * end of its conversion and trims leading space, we have to save
 * spacing and re-install it.
 */
let multiLineToRE = (implOrInterface: conversionType, s: string) : string => {
  let (nNewlines, nSpaces, inputString) = countLeadingWhitespace(s);
  let result = (toReason(inputString, implOrInterface) |>
    Js.String.replaceByRe([%re "/\\n\\n/g"], "\n") |>
    Js.String.trim) ++ "\n";
  /* Js.log("multiLineToRE |" ++ inputString ++ "| -> |" ++ result ++ "|"); */
  
  if (Js.String.startsWith("Error:", result)) {
    "!!!" ++ s ++ "!!!"
  } else {
    String.make(nNewlines, '\n') ++ addSpaces(nSpaces, result);
  }
};

/*
 * Convert single line of OCaml to Reason. If the result begins with Error,
 * return original string. Get rid of any trailing \n and semicolons.
 */
let singleLineToRE = (implOrInterface: conversionType, s: string) : string => {
  let result = toReason(s, implOrInterface) |>
    Js.String.trim |>
    Js.String.replaceByRe([%re "/;$/"], "");
  /* Js.log("singleLineToRE |" ++ s ++ "| -> |" ++ result ++ "|"); */
  if (Js.String.startsWith("Error:", result)) {
    "!!!" ++ s ++ "!!!"
  } else {
    result;
  }
};
