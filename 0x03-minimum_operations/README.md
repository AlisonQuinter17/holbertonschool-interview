# Minimum Operations
In a text file, there is a single character **H**. Your text editor can execute only two operations in this file: **Copy All** and **Paste**. Given a number **n**, write a method that **calculates the fewest number of operations needed to result in exactly n H characters in the file.**

#### Examples:

**n** = 9

H => **Copy All** => **Paste** => HH => **Paste** =>HHH => **Copy All** => **Paste** => HHHHHH => **Paste** => HHHHHHHHH

Number of operations: **6**
<hr>

**n** = 4

H => **Copy All** => **Paste** => HH => **Copy All** => **Paste** => HHHH

Number of operations: **4**
<hr>

**n** = 12

H => **Copy All** => **Paste** => HH => **Paste** =>HHH => **Copy All** => **Paste** => HHHHHH => **Copy All** => **Paste** => HHHHHHHHHHHH

Number of operations: **7**
<hr>

**n** = 0

Number of operations: **0**
<hr>

**n** = -3

Number of operations: **0**
<hr>

**n** = "Holacarebola"

Number of operations: **0**
