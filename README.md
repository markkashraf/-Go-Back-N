# Go-Back-N Protocol Simulation in C++

## Overview

This C++ project implements the Go-Back-N protocol, a sliding window protocol for reliable communication over a network. The program allows the user to simulate the transmission and reception of frames, as well as simulate timeout scenarios where frames are resent.

## Usage

### Prerequisites

- C++ compiler (e.g., g++)
- Git (optional)

### Compile

```bash
g++ -o go-back-n-simulation main.cpp
```

### Run

```bash
./go-back-n-simulation
```

## Program Features

1. **Input Parameters:**
   - Number of frames to be transmitted.
   - Sequence number for each frame.

2. **Frame Transmission:**
   - Simulates the transmission of frames.

3. **Frame Reception:**
   - Simulates the reception of frames.

4. **Timeout Simulation:**
   - Simulates a timeout scenario, triggering the retransmission of frames.

## Example

```plaintext

Number of frames:10

Sequence number:4

Enter frame number 1 :
ABCDEFGHI
Enter frame number 2 :
BCDEFGHIJ
Enter frame number 3 :
CDEFGHIJK
Enter frame number 4 :
DEFGHIJKL
Enter frame number 5 :
EFGHIJKLM
Enter frame number 6 :
FGHIJKLMN
Enter frame number 7 :
GHIJKLMNO
Enter frame number 8 :
HIJKLMNOP
Enter frame number 9 :
IJKLMNOPQ
Enter frame number 10 :
JKLMNOPQR

--- Transmission Simulation ---


 Frames Sent : 8 | A B C D E F G H I
                   B C D E F G H I J
                   C D E F G H I J K
                   D E F G H I J K L
                   E F G H I J K L M
                   F G H I J K L M N
                   G H I J K L M N O
                   H I J K L M N O P

 Frames received| A B C D E F G H I


 Frames Sent : 8 | B C D E F G H I J
                   C D E F G H I J K
                   D E F G H I J K L
                   E F G H I J K L M
                   F G H I J K L M N
                   G H I J K L M N O
                   H I J K L M N O P
                   I J K L M N O P Q

 Frames received| B C D E F G H I J
                  C D E F G H I J K
                  D E F G H I J K L
                  E F G H I J K L M
                  F G H I J K L M N


 Frames Sent : 4 | G H I J K L M N O
                   H I J K L M N O P
                   I J K L M N O P Q
                   J K L M N O P Q R

 Frames received|

 Timed out, resending frame....
 Frames Sent : 4 | G H I J K L M N O
                   H I J K L M N O P
                   I J K L M N O P Q
                   J K L M N O P Q R

 Frames received|

 Timed out, resending frame....
 Frames Sent : 4 | G H I J K L M N O
                   H I J K L M N O P
                   I J K L M N O P Q
                   J K L M N O P Q R

 Frames received| G H I J K L M N O
                  H I J K L M N O P
                  I J K L M N O P Q
                  J K L M N O P Q R


Process finished with exit code 0


--- Simulation Complete ---
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This was a group project for the Computer Networks course for ENG ASU.

Feel free to contribute and provide feedback to improve this simulation!
