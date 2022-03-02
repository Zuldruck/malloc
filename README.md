# malloc

This is my own implementation of the low-level standard library `malloc` function.
To do so it uses an even more low-level function which is `sbrk/brk` which permits to change the memory break's address.

## Implementation

The implementation is done using blocks.
A block is filled with metadata (9 bytes) and then the memory used by the user.

The memory could look like that :

```
+----------------------------+        +-------------------------------------------+
|           |                |        |           |                               | 
| metadata  | memory         |        | metadata  | memory                        |
|           |                | -----> |           |                               | -----> ...
| (9 bytes) | (34 bytes)     |        | (9 bytes) | (108 bytes)                   |
|           |                |        |           |                               |
+----------------------------+        +-------------------------------------------+
```

## Features

- Page per page allocation
- Align pointers on even addresses in hexa
