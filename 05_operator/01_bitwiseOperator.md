## bitwise operator

![cpp-bitwise-operators](https://github.com/user-attachments/assets/7206567b-3b58-4fee-b015-f6151a51040a)


![bitwise-operations](https://github.com/user-attachments/assets/731eba58-22ad-44ab-838b-9f47f7b19cea)




```

    bool a = false; 

    cout << (~a) ; // -1 

    // how ?
    // 00000000 
    // 11111111      --> making NOT
    // first bit is 1 so (-) minus
    // then 1111111 's 2's compliment
    //      0000000
    //     +      1
    //     --------
    //      0000001

    // so 1
    // minus 1

```
