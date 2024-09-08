
# formulas

```

 // int n = 5;

 // 0->7
 // 1->5
 // 2->3
 // 3->1

 // formula = 2*n - 2*N - 1 where ( N = row+1 ) if row starts from 0 then

```

<br/>


```
 
int n = 5;

0->4
1->3
2->2
3->1

formula = n - (row+1)
        = n - row - 1

```

<br/>

```

n = 5 ;

0->1
1->3
2->5
3->7

formula = 2n + 1

```


<br/>


```
//  1
//  1 1
//  1 2 1
//  1 3 3 1
//  1 4 6 4 1
//  1 5 10 10 5 1
//  1 6 15 20 15 6 1

// pascal triangle make with BIONOMIAL COEEFICIENT

// FORMULA

// c = c * (i-j) / j 
// where i = [1, N]
//       j = [1, N]

// formula saying start from 1 th index ( not 0 )
```

<br/>

```

// =========================

//         1 | 
//       2 3 |2
//     3 4 5 |4 3
//   4 5 6 7 |6 5 4
// 5 6 7 8 9 |8 7 6 5

// for pyramid after | line
// u can also make logic like
// loop run til noOfRow
// print start from 2*row and then do decrement

```