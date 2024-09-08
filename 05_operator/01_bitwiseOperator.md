## bitwise operator



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
