# IPD Homework 7: Hexapawn


## Summary

For this homework, you will write an interactive program implementing
the two-player abstract strategy game
[Hexapawn].


## Goals

To design a whole program from scratch, while maintaining good style and
logical factoring.


## Design overview

Your Hexapawn game will be split into two components: the model and the
user interface.

The model should contain the state of the abstract
Hexapawn game and enforce the rules of Hexapawn, independently of the user
interface. This means, for example, that the same model class could be
used with your text-based interface and my graphical user interface.

Your model will have two clients: the user interface (which is part of
the main program that a user would run) and the model tests. Clients
must use the public member functions of your model class to find out
about the state of the game and perform moves. That means that the public
member functions of your model class need to provide the right access so
that it’s possible for the UI to “play” the game on behalf of the users.
However, it’s also responsible to enforce the rules of Hexapawn, which means
that client code should not be able to modify the model in ways that
violate the rules of the game.


## Specification

The rules of Hexapawn are available in [the Hexapawn Wikipedia
article][Hexapawn], and your program should implement these rules.

Unlike traditional 3×3 Hexapawn, your game should support board
dimensions from 3×3 to 8×8. Changing a dimension should be as easy as
changing a constant (or you can integrate dimension selection into your
UI).

At each turn, your game should display the state of the board and which
player’s turn it is. It should then allow the player to select a move.
Here is an example of what that display might look like for a 5×3 game:

````
   | a | b | c | d | e |
---+---+---+---+---+---+---
 3 | B | B | B | B | B | 3
---+---+---+---+---+---+---
 2 |   | W |   |   |   | 2
---+---+---+---+---+---+---
 1 | W |   | W | W | W | 1
---+---+---+---+---+---+---
   | a | b | c | d | e |

Player B’s move:
  0: a3–a2
  1: a3–b2
  2: c3–c2
  3: c3–b2
  4: d3–d2
  5: e3–e2
>
````

If you wish, you may improve upon the display. For example, you could
rotate the display of the board so that each player moves up the board,
rather than player B moving down.

When a player wins, either by reaching the other side or leaving the
other player with no available moves, a messages to this effect should
be displayed and the program should terminate.


## Deliverables

For this homework you must:

  - Implement a model of the Hexapawn game in [`src/Model.hxx`] and
    [`src/Model.cxx`].
    
  - Write sufficient tests in [`test/model_test.cxx`] to demonstrate
    your model’s correctness.
    
  - Implement the interactive `hexapawn` game as described above
    in [`src/model_test.cxx`].
    
  - Adhere to the [IPD Style Manual for C and C++][style].


[Hexapawn]: https://en.wikipedia.org/wiki/Hexapawn
[`src/hexapawn.cxx`]: src/hexapawn.cxx
[`src/Model.hxx`]: src/Model.hxx
[`src/Model.cxx`]: src/Model.cxx
[`test/model_test.cxx`]: test/model_test.cxx
