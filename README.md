# mli\_to\_markdown

As of this writing, an effort is under way to update documentation for [Belt](https://bucklescript.github.io/bucklescript/api/Belt.html), a standard library shipped with BuckleScript.

Part of this effort is conversion of the `.mli` interface files to Markdown format. This program is a possible ocntribution to make that process easier.

This is more of a proof-of-concept and a way for me to learn Reason than production code. When you run the code, you provide the name of a file ending in `.mli`; the output file will be the same name except ending in `.rei`.

The definitions (`val` and `external`) are kept in their original OCaml and converted to ReasonML.

For the documentation strings in the file, the algorithm, in general, is that anything in `[...]` is a single line of Bucklescript code, and anything enclosed in `{[...]}` is a multi-line sequence of code. The code examples are presumed to be code rather than interface. If conversion to Reason fails, the original string is kept, surrounded by `!!!`.

The `mli_test_files` folder in this repository contains some of the `.mli` files for Belt, which you may use as input to the program.

# Warning

Do not use this code as an example of what “good“ ReasonML should look like. It was written with some preliminary design, but it was also written in a burning hurry and in a very ad-hoc fashion. YMMV.

# Dependencies

Uses [`glennsl/bs-refmt`](https://github.com/glennsl/bs-refmt)

# Build
```
bsb -make-world
```

# Run

```
node src/MLI_REI_convert.bs.js inputfile.mli ModuleName > outputfile.md
```
