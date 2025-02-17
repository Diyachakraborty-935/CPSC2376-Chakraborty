Off-by-One error In for Loop
The for loop is providing out-of-bounds access to values outside the loop. The loop must be restricted to where the most times it can iterate is one less than the size of the vector.
C-style Arrays (Square Bracket Notation) Used In Vector
The vector is using square bracket notation, which is out-of-date. To point to particular spots in the vector, use vectorName.at(slot).
