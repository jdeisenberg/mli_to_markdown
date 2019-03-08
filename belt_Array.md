Reading mli_files/belt_Array.mli
---
title: Array
---

 {!Belt.Array}    
    Utililites for Array functions 

### Array.length
```reason
/** [length xs] return the size of the array */
external length : array('a) => int = "%array_length";
```

```ocaml
external length: 'a array -> int = "%array_length"
(** [length xs] return the size of the array *)
  
```

### Array.size
```reason
/** {b See} {!length} */ external size : array('a) => int = "%array_length";
```

```ocaml
external size: 'a array -> int = "%array_length"
(** {b See} {!length} *)

```

### Array.get
```reason
let get: (array('a), int) => option('a);
```

```ocaml
val get: 'a array -> int -> 'a option

```

### Array.getExn
```reason
let getExn: (array('a), int) => 'a;
```

```ocaml
val getExn: 'a array -> int -> 'a  
```


 `getExn arr i`

    {b raise} an exception if `i` is out of range

### Array.getUnsafe
```reason
external getUnsafe : (array('a), int) => 'a = "%array_unsafe_get";
```

```ocaml
external getUnsafe: 'a array -> int -> 'a = "%array_unsafe_get"
```


 `getUnasfe arr i`

    {b Unsafe}

    no  bounds checking, this would cause type error
    if `i` does not stay within range

### Array.getUndefined
```reason
external getUndefined : (array('a), int) => Js.undefined('a) =
  "%array_unsafe_get";
```

```ocaml
external getUndefined: 'a array -> int -> 'a Js.undefined = "%array_unsafe_get"
```


 `getUndefined arr i`

    It does the samething in the runtime as {!getUnsafe}, 
    it is {i type safe} since the return type still track whether it is 
    in range or not

### Array.set
```reason
let set: (array('a), int, 'a) => bool;
```

```ocaml
val set: 'a array -> int -> 'a -> bool
```


 `set arr n x` modifies `arr` in place, 
    it replaces the nth element of `arr` with `x` 
    @return false means not updated due to out of range

### Array.setExn
```reason
let setExn: (array('a), int, 'a) => unit;
```

```ocaml
val setExn: 'a array -> int -> 'a -> unit 
```


 `setExn arr i x`
    {b raise} an exception if `i` is out of range

### Array.setUnsafe
```reason
external setUnsafe : (array('a), int, 'a) => unit = "%array_unsafe_set";
```

```ocaml
external setUnsafe: 'a array -> int -> 'a -> unit = "%array_unsafe_set"

```

### Array.shuffleInPlace
```reason
let shuffleInPlace: array('a) => unit;
```

```ocaml
val shuffleInPlace: 'a array -> unit

```

### Array.shuffle
```reason
let shuffle: array('a) => array('a);
```

```ocaml
val shuffle: 'a array -> 'a array  
```


 `shuffle xs`
    @return a fresh array 
### Array.reverseInPlace
```reason
let reverseInPlace: array('a) => unit;
```

```ocaml
val reverseInPlace: 'a array -> unit

```

### Array.reverse
```reason
let reverse: array('a) => array('a);
```

```ocaml
val reverse: 'a array -> 'a array
```


 `reverse x`
    @return a fresh array 
### Array.makeUninitialized
```reason
[@bs.new]
external makeUninitialized : int => array(Js.undefined('a)) = "Array";
```

```ocaml
external makeUninitialized: int -> 'a Js.undefined array = "Array" [@@bs.new]

```

### Array.makeUninitializedUnsafe
```reason
[@bs.new] external makeUninitializedUnsafe : int => array('a) = "Array";
```

```ocaml
external makeUninitializedUnsafe: int -> 'a array = "Array" [@@bs.new]
```


 `makeUninitializedUnsafe n`

    {b Unsafe}   

### Array.make
```reason
let make: (int, 'a) => array('a);
```

```ocaml
val make: int -> 'a  -> 'a array
```


 `make n e` 
    return an array of size `n` filled  with value `e`    
    @return an empty array when `n` is negative.

### Array.range
```reason
let range: (int, int) => array(int);
```

```ocaml
val range: int -> int -> int array
```

 `range start finish` create an inclusive array
    
Examples:
```ocaml

      range 0 3 =  [|0;1;2;3|];;
      range 3 0 =  [||] ;;
      range 3 3 = [|3|];;
    
```

```reason

      range(0, 3) == [|0, 1, 2, 3|];
      range(3, 0) == [||];
      range(3, 3) == [|3|];
      
```


### Array.rangeBy
```reason
/** {b See} {!length} */
let rangeBy: (int, int, ~step: int) => array(int);
```

```ocaml
val rangeBy: int -> int -> step:int -> int array
```

 `rangeBy start finish ~step`

    @return empty array when step is 0 or negative
    it also return empty array when `start > finish`
    
    
Examples:
```ocaml

     rangeBy 0 10 ~step:3 = [|0;3;6;9|];;
     rangeBy 0 12 ~step:3 = [|0;3;6;9;12|];;
     rangeBy 33 0 ~step:1 =  [||];;
     rangeBy 33 0 ~step:(-1) = [||];;
     rangeBy 3 12 ~step:(-1) = [||];;
     rangeBy 3 3 ~step:0 = [||] ;;     
     rangeBy 3 3 ~step:(1) = [|3|] ;;
   
```

```reason

     rangeBy(0, 10, ~step=3) == [|0, 3, 6, 9|];
     rangeBy(0, 12, ~step=3) == [|0, 3, 6, 9, 12|];
     rangeBy(33, 0, ~step=1) == [||];
     rangeBy(33, 0, ~step=-1) == [||];
     rangeBy(3, 12, ~step=-1) == [||];
     rangeBy(3, 3, ~step=0) == [||];
     rangeBy(3, 3, ~step=1) == [|3|];
     
```


### Array.makeByU
```reason
let makeByU: (int, (. int) => 'a) => array('a);
```

```ocaml
val makeByU: int -> (int -> 'a [@bs]) -> 'a array
```

### Array.makeBy
```reason
let makeBy: (int, int => 'a) => array('a);
```

```ocaml
val makeBy: int -> (int -> 'a ) -> 'a array
```

 `makeBy n f` 
    
    return an empty array when `n` is negative 
    return an array of size `n` populated by `f i` start from `0` to `n - 1`

    
Examples:
```ocaml

      makeBy 5 (fun i -> i) = [|0;1;2;3;4|]
    
```

```reason

      makeBy(5, i => i) == [|0, 1, 2, 3, 4|];
      
```


### Array.makeByAndShuffleU
```reason
let makeByAndShuffleU: (int, (. int) => 'a) => array('a);
```

```ocaml
val makeByAndShuffleU: int -> (int -> 'a [@bs]) -> 'a array
```

### Array.makeByAndShuffle
```reason
let makeByAndShuffle: (int, int => 'a) => array('a);
```

```ocaml
val makeByAndShuffle: int -> (int -> 'a ) -> 'a array    
```


 `makeByAndShuffle n f`

    Equivalent to `shuffle (makeBy n f)`

### Array.zip
```reason
/** {b See} {!length} */
let zip: (array('a), array('b)) => array(('a, 'b));
```

```ocaml
val zip: 'a array -> 'b array -> ('a * 'b) array
```

 `zip a b` 
    
    Stop with the shorter array

    
Examples:
```ocaml

      zip [|1;2] [|1;2;3|] = [| (1,2); (2;2)|]
    
```

```reason
!!!
      zip [|1;2] [|1;2;3|] = [| (1,2); (2;2)|]
    !!!
```

 


    `zipBy xs ys f`
   
    Stops with shorter array

    Equivalent to `map (zip xs ys) (fun (a,b) -> f a b) `
 
### Array.concat
```reason
let concat: (array('a), array('a)) => array('a);
```

```ocaml
val concat: 'a array -> 'a array -> 'a array
```


 `concat xs ys`

    @return a fresh array containing the
    concatenation of the arrays `v1` and `v2`, so even if `v1` or `v2`
    is empty, it can not be shared 

### Array.concatMany
```reason
let concatMany: array(array('a)) => array('a);
```

```ocaml
val concatMany: 'a array array -> 'a array
```



    `concatMany xss`

    @return a fresh array as the concatenation of `xss`

### Array.slice
```reason
let slice: (array('a), ~offset: int, ~len: int) => array('a);
```

```ocaml
val slice: 'a array -> offset:int -> len:int -> 'a array
```


 `slice arr offset len`
    
    `offset` can be negative,
    `slice arr -1 1` means get the last element as a singleton array

    `slice arr -(very_large_index) len` will do a copy of the array
    
    if the array does not have enough data, `slice` extracts through
    the end of sequence

### Array.copy
```reason
let copy: array('a) => array('a);
```

```ocaml
val copy: 'a array -> 'a array
```


 `copy a` 

    @return a copy of `a`, that is, a fresh array
   containing the same elements as `a`. 
### Array.fill
```reason
let fill: (array('a), ~offset: int, ~len: int, 'a) => unit;
```

```ocaml
val fill: 'a array -> offset:int -> len:int -> 'a -> unit
```

 `fill arr ~offset ~len x` 

    Modifies `arr` in place,
    storing `x` in elements number `offset` to `offset + len - 1`.

    `offset` can be negative

    `fill arr offset:(-1) len:1 ` means fill the last element,
    if the array does not have enough data, `fill` will ignore it

    
Examples:
```ocaml


      let arr = makeBy 5 (fun i -> i) ;;
      fill arr ~offset:2 ~len:2 0 ;;
      arr = [|0;1;0;0;4|];;
    
```

```reason


      let arr = makeBy(5, i => i);
      fill(arr, ~offset=2, ~len=2, 0);
      arr == [|0, 1, 0, 0, 4|];
      
```

 
### Array.blit
```reason
let blit:
  (
    ~src: array('a),
    ~srcOffset: int,
    ~dst: array('a),
    ~dstOffset: int,
    ~len: int
  ) =>
  unit;
```

```ocaml
val blit: 
    src:'a array -> srcOffset:int -> dst:'a array -> dstOffset:int -> len:int -> unit
```


 `blit ~src:v1 ~srcOffset:o1 ~dst:v2 ~dstOffset:o2 ~len` 

    copies `len` elements
   from array `v1`, starting at element number `o1`, to array `v2`,
   starting at element number `o2`. 
   
    It works correctly even if
    `v1` and `v2` are the same array, and the source and
    destination chunks overlap.

    `offset` can be negative, `-1` means `len - 1`, if `len + offset`  is still 
    negative, it will be set as 0   

### Array.blitUnsafe
```reason
let blitUnsafe:
  (
    ~src: array('a),
    ~srcOffset: int,
    ~dst: array('a),
    ~dstOffset: int,
    ~len: int
  ) =>
  unit;
```

```ocaml
val blitUnsafe:
  src:'a array -> srcOffset:int -> dst:'a array -> dstOffset:int -> len:int -> unit 
```



   {b Unsafe} blit without bounds checking

### Array.forEachU
```reason
let forEachU: (array('a), (. 'a) => unit) => unit;
```

```ocaml
val forEachU: 'a array ->  ('a -> unit [@bs]) -> unit
```

### Array.forEach
```reason
let forEach: (array('a), 'a => unit) => unit;
```

```ocaml
val forEach: 'a array ->  ('a -> unit ) -> unit
```


 `forEach xs f`

    Call f on each element of `xs` from the beginning to end

### Array.mapU
```reason
let mapU: (array('a), (. 'a) => 'b) => array('b);
```

```ocaml
val mapU: 'a array ->  ('a -> 'b [@bs]) -> 'b array
```

### Array.map
```reason
let map: (array('a), 'a => 'b) => array('b);
```

```ocaml
val map: 'a array ->  ('a -> 'b ) -> 'b array
```


 `map xs f `

    @return a new array by calling `f` to element of `xs` from
    the beginning to end

### Array.keepU
```reason
let keepU: (array('a), (. 'a) => bool) => array('a);
```

```ocaml
val keepU: 'a array -> ('a -> bool [@bs]) -> 'a array
```

### Array.keep
```reason
let keep: (array('a), 'a => bool) => array('a);
```

```ocaml
val keep: 'a array -> ('a -> bool ) -> 'a array
```

 `keep xs p `
    @return a new array that keep all elements satisfy `p`

    
Examples:
```ocaml

      keep [|1;2;3|] (fun x -> x mod  2 = 0) = [|2|]
    
```

```reason

      keep([|1, 2, 3|], x => x mod 2 == 0) == [|2|];
      
```


### Array.keepMapU
```reason
let keepMapU: (array('a), (. 'a) => option('b)) => array('b);
```

```ocaml
val keepMapU: 'a array -> ('a -> 'b option [@bs]) -> 'b array
```

### Array.keepMap
```reason
let keepMap: (array('a), 'a => option('b)) => array('b);
```

```ocaml
val keepMap: 'a array -> ('a -> 'b option) -> 'b array 
```

 `keepMap xs p`
    @return a new array that keep all elements that return a non-None applied `p`

    
Examples:
```ocaml

      keepMap [|1;2;3|] (fun x -> if x mod 2 then Some x else None)
      = [| 2 |]
    
```

```reason

      keepMap([|1, 2, 3|], x =>
        if (x mod 2) {
          Some(x);
        } else {
          None;
        }
      )
      == [|2|];
      
```


### Array.forEachWithIndexU
```reason
let forEachWithIndexU: (array('a), (. int, 'a) => unit) => unit;
```

```ocaml
val forEachWithIndexU: 'a array ->  (int -> 'a -> unit [@bs]) -> unit
```

### Array.forEachWithIndex
```reason
let forEachWithIndex: (array('a), (int, 'a) => unit) => unit;
```

```ocaml
val forEachWithIndex: 'a array ->  (int -> 'a -> unit ) -> unit
```


 `forEachWithIndex xs f`

    The same with {!forEach}, except that `f` is supplied with one
    more argument: the index starting from 0

### Array.mapWithIndexU
```reason
let mapWithIndexU: (array('a), (. int, 'a) => 'b) => array('b);
```

```ocaml
val mapWithIndexU: 'a array ->  (int -> 'a -> 'b [@bs]) -> 'b array
```

### Array.mapWithIndex
```reason
let mapWithIndex: (array('a), (int, 'a) => 'b) => array('b);
```

```ocaml
val mapWithIndex: 'a array ->  (int -> 'a -> 'b ) -> 'b array    
```


 `mapWithIndex xs f `

    The same with {!map} except that `f` is supplied with one
    more argument: the index starting from 0

### Array.reduceU
```reason
let reduceU: (array('b), 'a, (. 'a, 'b) => 'a) => 'a;
```

```ocaml
val reduceU:  'b array -> 'a -> ('a -> 'b -> 'a [@bs]) ->'a
```

### Array.reduce
```reason
let reduce: (array('b), 'a, ('a, 'b) => 'a) => 'a;
```

```ocaml
val reduce:  'b array -> 'a -> ('a -> 'b -> 'a ) ->'a
```

 `reduce xs init f`

    
Examples:
```ocaml

      reduce [|2;3;4|] 1 (+) = 10
    
```

```reason

      reduce([|2, 3, 4|], 1, (+)) == 10;
      
```

   

### Array.reduceReverseU
```reason
let reduceReverseU: (array('b), 'a, (. 'a, 'b) => 'a) => 'a;
```

```ocaml
val reduceReverseU: 'b array -> 'a -> ('a -> 'b ->  'a [@bs]) ->  'a
```

### Array.reduceReverse
```reason
let reduceReverse: (array('b), 'a, ('a, 'b) => 'a) => 'a;
```

```ocaml
val reduceReverse: 'b array -> 'a -> ('a -> 'b ->  'a ) ->  'a
```

 `reduceReverse xs init f`
    
Examples:
```ocaml

      reduceReverse [|1;2;3;4|] 100 (-) = 90 
    
```

```reason

      reduceReverse([|1, 2, 3, 4|], 100, (-)) == 90;
      
```


### Array.reduceReverse2U
```reason
let reduceReverse2U: (array('a), array('b), 'c, (. 'c, 'a, 'b) => 'c) => 'c;
```

```ocaml
val reduceReverse2U:
  'a array -> 'b array -> 'c  -> ('c -> 'a -> 'b ->  'c [@bs]) ->  'c
```

### Array.reduceReverse2
```reason
let reduceReverse2: (array('a), array('b), 'c, ('c, 'a, 'b) => 'c) => 'c;
```

```ocaml
val reduceReverse2:  
  'a array -> 'b array -> 'c  -> ('c -> 'a -> 'b ->  'c) ->  'c
```


   
Examples:
```ocaml

     reduceReverse2 [|1;2;3|] [|1;2|] 0 (fun acc x y -> acc + x + y) = 6
   
```

```reason

     reduceReverse2([|1, 2, 3|], [|1, 2|], 0, (acc, x, y) => acc + x + y) == 6;
     
```


### Array.someU
```reason
let someU: (array('a), (. 'a) => bool) => bool;
```

```ocaml
val someU: 'a array -> ('a -> bool [@bs]) -> bool
```

### Array.some
```reason
let some: (array('a), 'a => bool) => bool;
```

```ocaml
val some: 'a array -> ('a -> bool) -> bool
```


 `some xs p`
    @return true if one of element satifies `p`

### Array.everyU
```reason
/** [length xs] return the size of the array */
let everyU: (array('a), (. 'a) => bool) => bool;
```

```ocaml
val everyU: 'a array -> ('a -> bool [@bs]) -> bool
```

### Array.every
```reason
let every: (array('a), (. 'a) => bool) => bool;
```

```ocaml
val every: 'a array -> ('a -> bool ) -> bool
```


 `every xs p`
    @return true if all elements satisfy `p`

### Array.every2U
```reason
let every2U: (array('a), array('b), (. 'a, 'b) => bool) => bool;
```

```ocaml
val every2U: 'a array -> 'b array -> ('a -> 'b -> bool [@bs]) -> bool
```

### Array.every2
```reason
let every2: (array('a), array('b), ('a, 'b) => bool) => bool;
```

```ocaml
val every2: 'a array -> 'b array -> ('a -> 'b -> bool ) -> bool
```

 `every2 xs ys p` only tests the length of shorter

    
Examples:
```ocaml

      every2 [|1;2;3|] [|0;1|] (>) = true;;
      (every2 [||] [|1|] (fun   x y -> x > y)) = true;;
      (every2 [|2;3|] [|1|] (fun   x y -> x > y)) = true;; 
    
```

```reason

      every2([|1, 2, 3|], [|0, 1|], (>)) == true;
      every2([||], [|1|], (x, y) => x > y) == true;
      every2([|2, 3|], [|1|], (x, y) => x > y) == true;
      
```


### Array.some2U
```reason
let some2U: (array('a), array('b), (. 'a, 'b) => bool) => bool;
```

```ocaml
val some2U: 'a array -> 'b array -> ('a -> 'b -> bool [@bs]) -> bool
```

### Array.some2
```reason
let some2: (array('a), array('b), ('a, 'b) => bool) => bool;
```

```ocaml
val some2: 'a array -> 'b array -> ('a -> 'b -> bool ) -> bool
```

 `some2 xs ys p` only tests the length of shorter

    
Examples:
```ocaml

      some2 [|0;2|] [|1;0;3|] (>) = true ;;
      (some2 [||] [|1|] (fun   x y -> x > y)) =  false;;
      (some2 [|2;3|] [|1;4|] (fun   x y -> x > y)) = true;;
    
```

```reason

      some2([|0, 2|], [|1, 0, 3|], (>)) == true;
      some2([||], [|1|], (x, y) => x > y) == false;
      some2([|2, 3|], [|1, 4|], (x, y) => x > y) == true;
      
```


### Array.cmpU
```reason
let cmpU: (array('a), array('a), (. 'a, 'a) => int) => int;
```

```ocaml
val cmpU: 'a array -> 'a array -> ('a -> 'a -> int [@bs]) -> int
```

### Array.cmp
```reason
let cmp: (array('a), array('a), ('a, 'a) => int) => int;
```

```ocaml
val cmp: 'a array -> 'a array -> ('a -> 'a -> int ) -> int
```


 `cmp a b`
    
    - Compared by length if `length a <> length b` 
    - Otherwise compare one by one `f ai bi`

### Array.eqU
```reason
let eqU: (array('a), array('a), (. 'a, 'a) => bool) => bool;
```

```ocaml
val eqU:  'a array -> 'a array -> ('a -> 'a -> bool [@bs]) -> bool
```

### Array.eq
```reason
let eq: (array('a), array('a), ('a, 'a) => bool) => bool;
```

```ocaml
val eq:  'a array -> 'a array -> ('a -> 'a -> bool ) -> bool
```


 `eq a b`
    
    - return false if length is not the same
    - equal one by one using `f ai bi`

### Array.truncateToLengthUnsafe
```reason
[@bs.set] /** {b Unsafe}  */
external truncateToLengthUnsafe : (array('a), int) => unit = "length";
```

```ocaml
external truncateToLengthUnsafe: 'a array -> int ->  unit = "length" [@@bs.set]
(** {b Unsafe}  *)

```


