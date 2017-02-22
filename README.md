# C-encryption-
Using XOR operation to encrypt and decrypt text or Hex code transferred from ASCII — 

原理很简单，就是用位操作**异或** `x^y^y = x`的原理来进行加密解密，所以如果解密的时候没有密钥，也可以穷举出结果，然后再从结果里挑看似是正确的原文。

## en.c && de.c
en是加密，de是解密。

加密和解密都是针对**字符串**或**文本文件的**，输出也是文本。

具体怎样用一用就知道了。

## hex_de_en.c	

- **加密**==>输入字符串，输入密钥，输出原字符串十六进制结果与加密后的结果
- **解密**==>输入字符串，输入密钥(没有则穷举)，输出解密后的结果。
