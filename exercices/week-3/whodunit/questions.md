# Questions

## What's `stdint.h`?

A Header file with C/C++ data types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

More abstraction when dealing with bits

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2,

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

`0x424d` as it is the hexadecimal of `BM`

## What's the difference between `bfSize` and `biSize`?

biSize is the size of a whole bmp file, including header files.

bfSize is the size of the BITMAPINFOHEADER header file. const 40 bytes.

## What does it mean if `biHeight` is negative?

if biHeight is negative, the bitmap is a top-down DIB

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBitCount field.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Missing of permissions, file doesn't exists, wrong path...

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

Because we are reading just `1` chuck of data into our buffer.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Sets the file position to a given offset.
Like:
```C
	fseak(fp, 7, SEEK_SET )
	// Where fp is a pointer to a FILE
	// It would set the start of the file in the 7th position.
	fputs(" C Programming Language", fp);
	// It writes the ` C Programming Language` in the 7 position after the constant `SEEK_SET`.
```

## What is `SEEK_CUR`?

A constant for the current position of the file.
