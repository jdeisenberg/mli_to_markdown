// Generated by BUCKLESCRIPT VERSION 5.0.0-dev.4, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var Process = require("process");
var Js_types = require("bs-platform/lib/js/js_types.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Utils$Docconvert = require("./Utils.bs.js");

var defnPattern = (/^(val|external)/);

var startDocCommentPattern = (/^\s*\(\*\*/);

var startCommentPattern = (/\(\*/);

var endCommentPattern = (/\*\)/);

function isCommentStart(s) {
  if (startDocCommentPattern.test(s)) {
    return !endCommentPattern.test(s);
  } else {
    return false;
  }
}

function processLines(moduleName, _result, lines, _index) {
  while(true) {
    var index = _index;
    var result = _result;
    var collectDefinition = function (_acc, _index) {
      while(true) {
        var index = _index;
        var acc = _acc;
        if (index >= lines.length) {
          return /* tuple */[
                  acc,
                  index
                ];
        } else {
          var line = Caml_array.caml_array_get(lines, index);
          if (defnPattern.test(line) || isCommentStart(line)) {
            return /* tuple */[
                    acc,
                    index
                  ];
          } else {
            _index = index + 1 | 0;
            _acc = acc + ("\n" + line);
            continue ;
          }
        }
      };
    };
    var getCommentIncr = function (s) {
      var match = startCommentPattern.test(s);
      var nStart = match ? 1 : 0;
      var match$1 = endCommentPattern.test(s);
      var nEnd = match$1 ? 1 : 0;
      return nStart - nEnd | 0;
    };
    var collectComment = function (_acc, _index, _nesting) {
      while(true) {
        var nesting = _nesting;
        var index = _index;
        var acc = _acc;
        if (index >= lines.length) {
          return /* tuple */[
                  acc,
                  index
                ];
        } else {
          var line = Caml_array.caml_array_get(lines, index);
          var newNesting = nesting + getCommentIncr(line) | 0;
          if (endCommentPattern.test(line) && newNesting === 0) {
            return /* tuple */[
                    acc + ("\n" + line),
                    index
                  ];
          } else {
            _nesting = newNesting;
            _index = index + 1 | 0;
            _acc = acc + ("\n" + line);
            continue ;
          }
        }
      };
    };
    var processDefn = function (defn) {
      var matchResult = defn.match((/^(val|external)\s*([A-Za-z0-9_.]+)/));
      var identifier = matchResult !== null ? Caml_array.caml_array_get(matchResult, 2) : "*unknown name*";
      return "### " + (moduleName + ("." + (identifier + ("\n```reason\n" + (Utils$Docconvert.multiLineToRE(/* Interface */1, defn) + ("```\n\n```ocaml\n" + (defn + "\n```\n\n")))))));
    };
    var convertBracketsBraces = function (s) {
      var __x = s.replace((/\[([^\]]+)\]/g), "`$1`");
      var __x$1 = __x.replace((/\{b ([^\}]+)\}/g), "**$1**");
      return __x$1.replace((/\{[ie] ([^\}]+)\}/g), "*$1*");
    };
    var examplePattern = (/\(\*\*((?:.|\n)+)?@example \{\[((?:.|\n)+)\]\}((?:.|\n)*)\*\)/);
    var noExamplePattern = (/\(\*\*((?:.|\n)*)\*\)/);
    var processComment = (function(examplePattern,noExamplePattern){
    return function processComment(comment) {
      var result = comment.match(examplePattern);
      if (result !== null) {
        var items = result;
        var match = Js_types.test(Caml_array.caml_array_get(items, 1), /* String */4);
        var preExample = match ? convertBracketsBraces(Caml_array.caml_array_get(items, 1)) : "";
        var match$1 = Js_types.test(Caml_array.caml_array_get(items, 3), /* String */4);
        var postExample = match$1 ? convertBracketsBraces(Caml_array.caml_array_get(items, 3)) : "";
        var reasonExample = Utils$Docconvert.multiLineToRE(/* Implementation */0, Caml_array.caml_array_get(items, 2));
        return preExample + ("\nExamples:\n```ocaml\n" + (Caml_array.caml_array_get(items, 2) + ("\n```\n\n```reason\n" + (reasonExample + ("\n```\n" + (postExample + "\n"))))));
      } else {
        var result2 = comment.match(noExamplePattern);
        if (result2 !== null) {
          return "\n" + (convertBracketsBraces(Caml_array.caml_array_get(result2, 1)) + "\n");
        } else {
          return "";
        }
      }
    }
    }(examplePattern,noExamplePattern));
    if (index >= lines.length) {
      return result;
    } else {
      var line = Caml_array.caml_array_get(lines, index);
      if (defnPattern.test(line)) {
        var match = collectDefinition(line, index + 1 | 0);
        _index = match[1];
        _result = result + processDefn(match[0]);
        continue ;
      } else if (isCommentStart(line)) {
        var match$1 = collectComment(line, index + 1 | 0, 1);
        _index = match$1[1];
        _result = result + processComment(match$1[0]);
        continue ;
      } else {
        _index = index + 1 | 0;
        continue ;
      }
    }
  };
}

function processFile(fileName, moduleName) {
  console.log("Reading", fileName);
  var inStr = Fs.readFileSync(fileName, "utf8");
  var lines = inStr.split("\n");
  console.log(processLines(moduleName, "---\ntitle: " + (moduleName + "\n---\n"), lines, 0));
  return /* () */0;
}

var match = Belt_Array.get(Process.argv, 0);

var match$1 = Belt_Array.get(Process.argv, 1);

var match$2 = Belt_Array.get(Process.argv, 2);

var match$3 = Belt_Array.get(Process.argv, 3);

var exit = 0;

if (match$2 !== undefined && match$3 !== undefined) {
  processFile(match$2, match$3);
} else {
  exit = 1;
}

if (exit === 1) {
  if (match !== undefined) {
    if (match$1 !== undefined) {
      console.log("Usage: " + (match + (" " + (match$1 + " inputfile.mli ModuleName"))));
    } else {
      console.log("How did you get here without NodeJS or a program to run?");
    }
  } else {
    console.log("How did you get here without NodeJS or a program to run?");
  }
}

var Ba = 0;

exports.Ba = Ba;
exports.defnPattern = defnPattern;
exports.startDocCommentPattern = startDocCommentPattern;
exports.startCommentPattern = startCommentPattern;
exports.endCommentPattern = endCommentPattern;
exports.isCommentStart = isCommentStart;
exports.processLines = processLines;
exports.processFile = processFile;
/* defnPattern Not a pure module */
