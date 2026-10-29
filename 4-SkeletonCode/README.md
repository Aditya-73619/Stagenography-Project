# 🖼️ Steganography in C

## 📌 Overview

This project implements **Image Steganography** using the C programming language.

Steganography is the technique of hiding secret information inside another file, such as an image, so that the presence of the hidden data is not easily noticeable.

This project hides a text file inside a BMP image and allows the hidden message to be extracted later using a decoding process.

In simple terms, an image acts as a container for secret information, allowing data to be shared without displaying the message directly.

---

## 🚀 Features

- Encoding: Hide a secret text file inside a BMP image.
- Decoding: Extract the hidden information from an encoded image.
- Supports BMP image files.
- Uses a magic string (`#*`) to identify encoded data.
- Validates input files before processing.
- Generates an output image containing the hidden message.
- Supports decoding the hidden message into a text file.

---

## 🛠️ Technologies Used

- C Programming
- Linked Concepts of File Handling
- Bitwise Operations
- File I/O (`fopen`, `fread`, `fwrite`, `fseek`, `rewind`)
- Bit Manipulation
- Command-Line Argument Handling (`argc` and `argv`)
- Modular Programming
- Error Handling

---

## ⚙️ How to Run

### Compile

Compile the source files using GCC:

```bash
gcc *.c -o a.out
```

### Encode a Secret Message

Use the following command to hide a text file inside a BMP image:

```bash
./a.out -e beautiful.bmp file.txt output.bmp
```

**Arguments:**

- `-e` — Selects encoding mode.
- `beautiful.bmp` — The original BMP image.
- `file.txt` — The text file containing the secret message.
- `output.bmp` — The generated image containing the hidden data.

### Decode the Secret Message

Extract the hidden message from the encoded image:

```bash
./a.out -d output.bmp
```

By default, the decoded message is saved to `decode.txt` if the program uses that default filename.

---

## 🔄 How It Works

### Encoding Process

1. Read and validate the input image and secret text file.
2. Check whether the input files are suitable for encoding.
3. Embed the secret data into the BMP image using bit manipulation.
4. Include the magic string (`#*`) to identify the hidden information.
5. Write the encoded data into a new BMP image.

### Decoding Process

1. Read and validate the encoded BMP image.
2. Extract the hidden information from the image.
3. Verify the magic string to identify the encoded content.
4. Recover the original secret message.
5. Write the extracted message into a text file.

---

## 🎯 Concepts Practiced

- File Handling in C
- Bitwise Operators and Bit Manipulation
- Command-Line Arguments
- Structures and Modular Programming
- File Validation and Error Handling
- Encoding and Decoding Algorithms
- Binary File Processing
- Memory Management

---

## 👨‍💻 Author

Aditya Gupta
