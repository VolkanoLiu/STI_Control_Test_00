# 正则表达式习题

## Building

在终端中直接编译 [task.c](https://github.com/VolkanoLiu/STI_Control_Test_00/blob/master/task.c) 即可
```bash
gcc task.c -o task
```

## Usage

有一个字符串 s 和一个字符规律 p，此代码可以实现 '.' 和 '\*' 的正则表达式匹配。

'.' 匹配任意单个字符 '\*' 匹配零个或多个前面的那一个元素。

匹配可以涵盖整个字符串 s。
* 说明: 

    s 可能为空，且只包含从 a-z 的小写字母。

    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
    
依次输入字符串 s 和字符串 p ，只能用回车分隔。

## Example

* 示例 1: 
 
    输入: 
    ```
    aa
    a
    ```

    输出: `false`
 
* 示例 2: 
 
    输入:
    ``` 
    aa
    a*
    ```

    输出: `true`

* 示例 3: 
 
    输入: 
    ```
    ab
    .*
    ```

    输出: `true`
 
* 示例 4: 
 
    输入: 
    ``` 
    aab
    c*a*b
    ```

    输出: `true`
 
*  示例 5: 
 
    输入: 
    ```
    mississippi
    mis*is*p*.
    ```

    输出: `false `

## License

[GNU General Public License v3.0](https://github.com/VolkanoLiu/STI_Control_Test_00/blob/master/LICENSE)