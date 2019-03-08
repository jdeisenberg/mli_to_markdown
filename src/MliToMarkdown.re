module Ba = Belt.Array;

let defnPattern = [%re "/^(val|external)/"];
let startDocCommentPattern = [%re "/^\\s*\\(\\*\\*/"];
let startCommentPattern = [%re "/\\(\\*/"];
let endCommentPattern = [%re "/\\*\\)/"];

let isCommentStart(s: string): bool {
  Js.Re.test(s, startDocCommentPattern) && (! Js.Re.test(s, endCommentPattern))
};
 
let rec processLines = (moduleName: string, result: string, lines: array(string), index: int): string => {

  let rec collectDefinition = (acc: string, index: int): (string, int) => {
    if (index >= Ba.length(lines)) {
      (acc, index)
    } else {
      let line = lines[index];
      if (Js.Re.test(line, defnPattern) || isCommentStart(line)) {
        (acc, index)
      } else {
        collectDefinition(acc ++ "\n" ++ line, index + 1)
      }
    }
  };

  /*
    Determine how much to increment or decrement comment nesting level
  */
  let getCommentIncr = (s: string): int => {
    let nStart = Js.Re.test(s, startCommentPattern) ? 1 : 0;
    let nEnd = Js.Re.test(s, endCommentPattern) ? 1 : 0;
    nStart - nEnd;
  }
  
  let rec collectComment = (acc: string, index: int, nesting: int): (string, int) => {
    if (index >= Ba.length(lines)) {
      (acc, index)
    } else {
      let line = lines[index];
      let newNesting = nesting + getCommentIncr(line)
      if (Js.Re.test(line, endCommentPattern) && newNesting == 0) {
        (acc ++ "\n" ++ line, index)
      } else {
        collectComment(acc ++ "\n" ++ line, index + 1, newNesting)
      }
    }
  };

  let processDefn = (defn: string): string => {
    let matchResult = Js.String.match([%re "/^(val|external)\\s*([A-Za-z0-9_.]+)/"], defn);
    let identifier = switch (matchResult) {
      | Some(matches) => matches[2] /* 0 = whole matched string, 1 = val/external 2 = id */
      | None => "*unknown name*"
    };
    "### " ++ moduleName ++ "." ++ identifier ++ "\n" ++
    "```reason\n" ++
    Utils.multiLineToRE(Utils.Interface, defn) ++
    "```\n\n" ++
    "```ocaml\n" ++
    defn ++
    "\n```\n\n";
  };

  let convertBracketsBraces = (s: string): string => {
    Js.String.replaceByRe([%re {|/\[([^\]]+)\]/g|}], "`$1`", s) ->
    Js.String.replaceByRe([%re {|/\{b ([^\}]+)\}/g|}], "**$1**", _) -> 
    Js.String.replaceByRe([%re {|/\{(?:i|em) ([^\}]+)\}/g|}], "*$1*", _); 
  };  

  let convertExample = (items: array(string)): string => {
    let preExample = Js.Types.test(items[1], Js.Types.String) ? convertBracketsBraces(items[1]) : "";
    let postExample = Js.Types.test(items[3], Js.Types.String) ? convertBracketsBraces(items[3]) : "";
    let reasonExample = Utils.multiLineToRE(Utils.Implementation, items[2]);
    preExample ++ "\nExamples:\n" ++
      "```ocaml\n" ++
      items[2] ++
      "\n```\n\n```reason\n" ++
      reasonExample ++
      "\n```\n" ++ postExample ++ "\n";
  };
  
  let examplePattern = [%re {|/\(\*\*((?:.|\n)+)?@example \{\[((?:.|\n)+)\]\}((?:.|\n)*)\*\)/|}];
  let noExamplePattern = [%re {|/\(\*\*((?:.|\n)*)\*\)/|}]
  
  let processComment = (comment: string): string => {
    let result = Js.String.match(examplePattern, comment);
    let modified = switch (result) {
      | Some(items) => convertExample(items)
      | None => {
          let result2 = Js.String.match(noExamplePattern, comment);
          switch (result2) {
            | Some(items) => "\n" ++ convertBracketsBraces(items[1]) ++ "\n"
            | None => ""
          }
      }
    };

    modified;
  };

  if (index >= Ba.length(lines)) {
    result
  } else {
    let line = lines[index];
    if (Js.Re.test(line, defnPattern)) {
      let (defn, n) = collectDefinition(line, index + 1);
      processLines(moduleName, result ++ processDefn(defn), lines, n);
    } else if (isCommentStart(line)) {
      /* Nesting starts at 1 because we have a comment start on this line */
      let (comment, n) = collectComment(line, index + 1, 1);
      processLines(moduleName, result ++ processComment(comment), lines, n);
    } else {
      processLines(moduleName, result, lines, index + 1)
    }
  }
};

let processFile = (fileName: string, moduleName: string) : unit => {
  Js.log2("Reading", fileName);
  let inStr = Node.Fs.readFileAsUtf8Sync(fileName);
  let lines = Js.String.split("\n", inStr);

  processLines(moduleName, "---\ntitle: " ++ moduleName ++ "\n---\n", lines, 0) -> Js.log;

};

/* --- Main --- */
switch ((Ba.get(Node.Process.argv, 0), Ba.get(Node.Process.argv, 1), Ba.get(Node.Process.argv, 2),
  Ba.get(Node.Process.argv, 3))) {
  | (_, _, Some(inFileName), Some(moduleName)) => processFile(inFileName, moduleName)
  | (Some(node), Some(prog), _, _) =>
    Js.log("Usage: " ++ node ++ " " ++ prog ++ " inputfile.mli ModuleName")
  | (_, _, _, _) =>
    Js.log("How did you get here without NodeJS or a program to run?")
};

